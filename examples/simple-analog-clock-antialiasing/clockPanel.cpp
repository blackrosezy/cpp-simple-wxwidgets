//
// Created by blackrosezy on 12-Dec-17.
//
#include <wx/graphics.h>
#include "clockPanel.h"

const double PI = acos(-1);
const double RATIO = 0.05;

ClockPanel::ClockPanel(wxWindow *parent, wxString fileName) : wxPanel(parent) {
    SetDoubleBuffered(true);
    Bind(wxEVT_PAINT, &ClockPanel::paintEvent, this);
    Bind(wxEVT_SIZE, &ClockPanel::OnSize, this);
}

void ClockPanel::paintEvent(wxPaintEvent &event) {
    wxPaintDC dc(this);
    wxGraphicsContext *gc = wxGraphicsContext::Create(dc);
    if (gc) {
        drawClock(gc);
        delete gc;
    }
}

void ClockPanel::OnSize(wxSizeEvent &event) {
    Refresh();
    //skip the event.
    event.Skip();
}

void ClockPanel::drawClock(wxGraphicsContext *gc) {
    wxDouble x, y;
    gc->GetSize(&x, &y);
    (x > y) ? radius = y / 2 : radius = x / 2;
    radius -= radius * RATIO; // fix too near to border
    origin_point = wxPoint(x / 2, y / 2);
    drawBaseClock(gc);
    drawHands(gc);
    drawCenterScrewCircle(gc);
}

void ClockPanel::drawBaseClock(wxGraphicsContext *gc) {
    drawClockCircle(gc);
    drawMinuteLines(gc, 5);
    drawHourLines(gc, 10);
    drawNumbers(gc, 25);
}

void ClockPanel::drawHands(wxGraphicsContext *gc) {
    time_t currentTime;
    struct tm *localTime;

    time(&currentTime);
    localTime = localtime(&currentTime);

    drawSecondHand(gc, 80, localTime->tm_sec);
    drawMinuteHand(gc, 70, localTime->tm_min);
    drawHourHand(gc, 50, localTime->tm_hour, localTime->tm_min);
}

void ClockPanel::drawClockCircle(wxGraphicsContext *gc) {
    const wxPen pen = wxPen(wxColour(189, 199, 208), radius * RATIO);
    gc->SetPen(pen);
    wxBrush brush = wxBrush(wxColour(60, 75, 82));
    gc->SetBrush(brush);
    wxDouble _radius = radius;
    gc->DrawEllipse(origin_point.x - _radius, origin_point.y - _radius, _radius * 2, _radius * 2);
}

void ClockPanel::drawCenterScrewCircle(wxGraphicsContext *gc) {
    wxPen pen = wxPen(wxColour(189, 199, 208), 0);
    gc->SetPen(pen);
    wxBrush brush = wxBrush(wxColour(189, 199, 208));
    gc->SetBrush(brush);
    wxDouble _radius = radius * (RATIO / 0.5);
    gc->DrawEllipse(origin_point.x - _radius, origin_point.y - _radius, _radius * 2, _radius * 2);


    wxPen pen2 = wxPen(wxColour(106, 129, 138), radius * (RATIO / 10));
    gc->SetPen(pen2);
    wxBrush brush2 = wxBrush(wxColour(189, 199, 208));
    gc->SetBrush(brush2);
    _radius = radius * (RATIO / 0.9);
    gc->DrawEllipse(origin_point.x - _radius, origin_point.y - _radius, _radius * 2, _radius * 2);
}

void ClockPanel::drawMinuteLines(wxGraphicsContext *gc, int percentage_length) {
    wxPen pen = wxPen(wxColour(106, 129, 138), radius * (RATIO / 3));
    pen.SetCap(wxCAP_ROUND);
    gc->SetPen(pen);
    int _percentage_length = 100 - percentage_length;
    for (int i = 1; i < 61; i++) {
        int angle = i * 6;
        if (angle % 30 == 0) continue;
        double _radius = radius - (radius * RATIO);
        drawLineFromCenter(gc, (_percentage_length * _radius) / 100, _radius, angle);
    }
}

void ClockPanel::drawHourLines(wxGraphicsContext *gc, int percentage_length) {
    wxPen pen = wxPen(wxColour(255, 255, 255), radius * (RATIO / 2.2));
    pen.SetCap(wxCAP_ROUND);
    gc->SetPen(pen);
    int _percentage_length = 100 - percentage_length;
    for (int i = 1; i < 13; i++) {
        int angle = i * 30;
        double _radius = radius - (radius * RATIO);
        drawLineFromCenter(gc, (_percentage_length * _radius) / 100, _radius, angle);
    }
}

void ClockPanel::drawNumbers(wxGraphicsContext *gc, int pos_from_center) {
    int _percentage_pos = 100 - pos_from_center;

    wxFont font(wxFontInfo(12));
    font.Scale(0.01 * radius);
    gc->SetFont(font, wxColour(106, 129, 138));
    for (int i = 1; i < 13; i++) {
        int angle = i * 30;
        wxString str_num;
        str_num << i;
        drawTextFromCenter(gc, (_percentage_pos * radius) / 100, angle, str_num);
    }
}

void ClockPanel::drawSecondHand(wxGraphicsContext *gc, int percentage_length, int second) {
    wxPen pen = wxPen(wxColour(189, 199, 208), radius * (RATIO / 2));
    pen.SetCap(wxCAP_BUTT);
    gc->SetPen(pen);
    int angle = second * 6;
    drawLineFromCenter(gc, 0, (percentage_length * radius) / 100, angle);
}

void ClockPanel::drawMinuteHand(wxGraphicsContext *gc, int percentage_length, int minute) {
    wxPen pen = wxPen(wxColour(189, 199, 208), radius * (RATIO / 1.2));
    pen.SetCap(wxCAP_BUTT);
    gc->SetPen(pen);
    int angle = minute * 6;
    drawLineFromCenter(gc, 0, (percentage_length * radius) / 100, angle);
}

void ClockPanel::drawHourHand(wxGraphicsContext *gc, int percentage_length, int hour, int minute) {
    wxPen pen = wxPen(wxColour(189, 199, 208), radius * (RATIO / 0.7));
    pen.SetCap(wxCAP_BUTT);
    gc->SetPen(pen);
    int angle = hour * 30 + (0.5 * minute);
    drawLineFromCenter(gc, 0, (percentage_length * radius) / 100, angle);
}

void ClockPanel::drawLineFromCenter(wxGraphicsContext *gc, int start_at_radius, int end_at_radius, int angle) {
    int _angle = angle - 90;
    double rad_angle = radian(_angle);

    double start_x = start_at_radius * cos(rad_angle);
    double start_y = start_at_radius * sin(rad_angle);
    wxPoint start_point(start_x, start_y);
    start_point += origin_point;

    double end_x = end_at_radius * cos(rad_angle);
    double end_y = end_at_radius * sin(rad_angle);
    wxPoint end_point(end_x, end_y);
    end_point += origin_point;

    gc->StrokeLine(start_point.x, start_point.y, end_point.x, end_point.y);
}

void ClockPanel::drawTextFromCenter(wxGraphicsContext *gc, int pos_at_radius, int angle, wxString text) {
    int _angle = angle - 90;
    double rad_angle = radian(_angle);
    double start_x = pos_at_radius * cos(rad_angle);
    double start_y = pos_at_radius * sin(rad_angle);
    wxPoint start_point(start_x, start_y);
    start_point += origin_point;
    wxDouble text_width, text_height;
    gc->GetTextExtent(text, &text_width, &text_height);
    start_point.x -= text_width / 2;
    start_point.y -= text_height / 2;
    gc->DrawText(text, start_point.x, start_point.y);
}

double ClockPanel::radian(int angle) {
    return (PI / 180) * angle;
}



