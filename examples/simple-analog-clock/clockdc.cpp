//
// Created by blackrosezy on 12-Dec-17.
//

#include "clockdc.h"

const double PI = acos(-1);
const double RATIO = 0.05;

wxClockDC::wxClockDC(wxWindow *parent) : wxPanel(parent) {
    SetDoubleBuffered(true);
    Bind(wxEVT_PAINT, &wxClockDC::paintEvent, this);
    Bind(wxEVT_SIZE, &wxClockDC::OnSize, this);
}

void wxClockDC::paintEvent(wxPaintEvent &event) {
    wxPaintDC dc(this);
    drawClock(dc);
}

void wxClockDC::OnSize(wxSizeEvent &event) {
    Refresh();
    //skip the event.
    event.Skip();
}

void wxClockDC::drawClock(wxDC &dc) {
    wxSize panel_size = dc.GetSize();
    (panel_size.x > panel_size.y) ? radius = panel_size.y / 2 : radius = panel_size.x / 2;
    radius -= radius * RATIO; // fix too near to border
    origin_point = wxPoint(panel_size.x / 2, panel_size.y / 2);
    drawBaseClock(dc);
    drawHands(dc);
    drawCenterScrewCircle(dc);
}

void wxClockDC::drawBaseClock(wxDC &dc) {
    drawClockCircle(dc);
    drawMinuteLines(dc, 5);
    drawHourLines(dc, 10);
    drawNumbers(dc, 25);
}

void wxClockDC::drawHands(wxDC &dc) {
    time_t currentTime;
    struct tm *localTime;

    time(&currentTime);
    localTime = localtime(&currentTime);

    drawSecondHand(dc, 80, localTime->tm_sec);
    drawMinuteHand(dc, 70, localTime->tm_min);
    drawHourHand(dc, 50, localTime->tm_hour, localTime->tm_min);
}

void wxClockDC::drawClockCircle(wxDC &dc) {
    wxPen pen = wxPen(wxColour(189, 199, 208), radius * RATIO);
    dc.SetPen(pen);
    wxBrush brush = wxBrush(wxColour(60, 75, 82));
    dc.SetBrush(brush);
    dc.DrawCircle(origin_point, radius);
}

void wxClockDC::drawCenterScrewCircle(wxDC &dc) {
    wxPen pen = wxPen(wxColour(189, 199, 208), 0);
    dc.SetPen(pen);
    wxBrush brush = wxBrush(wxColour(189, 199, 208));
    dc.SetBrush(brush);
    dc.DrawCircle(origin_point, radius * (RATIO / 0.5));


    wxPen pen2 = wxPen(wxColour(106, 129, 138), radius * (RATIO / 10));
    dc.SetPen(pen2);
    wxBrush brush2 = wxBrush(wxColour(189, 199, 208));
    dc.SetBrush(brush2);
    dc.DrawCircle(origin_point, radius * (RATIO / 0.9));
}

void wxClockDC::drawMinuteLines(wxDC &dc, int percentage_length) {
    wxPen pen = wxPen(wxColour(106, 129, 138), radius * (RATIO / 3));
    pen.SetCap(wxCAP_ROUND);
    dc.SetPen(pen);
    int _percentage_length = 100 - percentage_length;
    for (int i = 1; i < 61; i++) {
        int angle = i * 6;
        double _radius = radius - (radius * RATIO);
        drawLineFromCenter(dc, (_percentage_length * _radius) / 100, _radius, angle);
    }
}

void wxClockDC::drawHourLines(wxDC &dc, int percentage_length) {
    wxPen pen = wxPen(wxColour(255, 255, 255), radius * (RATIO / 2.2));
    pen.SetCap(wxCAP_ROUND);
    dc.SetPen(pen);
    int _percentage_length = 100 - percentage_length;
    for (int i = 1; i < 13; i++) {
        int angle = i * 30;
        double _radius = radius - (radius * RATIO);
        drawLineFromCenter(dc, (_percentage_length * _radius) / 100, _radius, angle);
    }
}

void wxClockDC::drawNumbers(wxDC &dc, int pos_from_center) {
    int _percentage_pos = 100 - pos_from_center;

    wxFont font(wxFontInfo(12));
    font.Scale(0.01 * radius);
    dc.SetFont(font);
    dc.SetTextForeground(wxColour(106, 129, 138));
    for (int i = 1; i < 13; i++) {
        int angle = i * 30;
        wxString str_num;
        str_num << i;
        drawTextFromCenter(dc, (_percentage_pos * radius) / 100, angle, str_num);
    }
}

void wxClockDC::drawSecondHand(wxDC &dc, int percentage_length, int second) {
    wxPen pen = wxPen(wxColour(189, 199, 208), radius * (RATIO / 2));
    pen.SetCap(wxCAP_BUTT);
    dc.SetPen(pen);
    int angle = second * 6;
    drawLineFromCenter(dc, 0, (percentage_length * radius) / 100, angle);
}

void wxClockDC::drawMinuteHand(wxDC &dc, int percentage_length, int minute) {
    wxPen pen = wxPen(wxColour(189, 199, 208), radius * (RATIO / 1.2));
    pen.SetCap(wxCAP_BUTT);
    dc.SetPen(pen);
    int angle = minute * 6;
    drawLineFromCenter(dc, 0, (percentage_length * radius) / 100, angle);
}

void wxClockDC::drawHourHand(wxDC &dc, int percentage_length, int hour, int minute) {
    wxPen pen = wxPen(wxColour(189, 199, 208), radius * (RATIO / 0.7));
    pen.SetCap(wxCAP_BUTT);
    dc.SetPen(pen);
    int angle = hour * 30 + (0.5 * minute);
    drawLineFromCenter(dc, 0, (percentage_length * radius) / 100, angle);
}

void wxClockDC::drawLineFromCenter(wxDC &dc, int start_at_radius, int end_at_radius, int angle) {
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

    dc.DrawLine(start_point, end_point);
}

void wxClockDC::drawTextFromCenter(wxDC &dc, int pos_at_radius, int angle, wxString text) {
    int _angle = angle - 90;
    double rad_angle = radian(_angle);
    double start_x = pos_at_radius * cos(rad_angle);
    double start_y = pos_at_radius * sin(rad_angle);
    wxPoint start_point(start_x, start_y);
    start_point += origin_point;

    wxSize text_size = dc.GetTextExtent(text);
    start_point.x -= text_size.x / 2;
    start_point.y -= text_size.y / 2;
    dc.DrawText(text, start_point);
}

double wxClockDC::radian(int angle) {
    return (PI / 180) * angle;
}



