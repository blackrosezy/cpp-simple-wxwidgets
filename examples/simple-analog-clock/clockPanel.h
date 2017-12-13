//
// Created by blackrosezy on 12-Dec-17.
//

#ifndef ALL_IMAGEPANEL_H
#define ALL_IMAGEPANEL_H

#include <wx/wx.h>

class ClockPanel : public wxPanel {
public:
    ClockPanel(wxWindow *parent, wxString fileName);

    void paintEvent(wxPaintEvent &event);

    void OnSize(wxSizeEvent &event);

private:
//    void drawSecondHand(wxDC &dc, int radius, int cx, int cy, int second);
//
//    void drawMinuteHand(wxDC &dc, int radius, int cx, int cy, int minute);
//
//    void drawHourHand(wxDC &dc, int radius, int cx, int cy, int hour);

    void drawClock(wxDC &dc);

    void drawBaseClock(wxDC &dc);

    void drawHands(wxDC &dc);

    void drawClockCircle(wxDC &dc);

    void drawCenterScrewCircle(wxDC &dc);

    void drawMinuteLines(wxDC &dc, int percentage_length);

    void drawHourLines(wxDC &dc, int percentage_length);

    void drawNumbers(wxDC &dc, int pos_from_center);

    void drawSecondHand(wxDC &dc, int percentage_length, int second);

    void drawMinuteHand(wxDC &dc, int percentage_length, int minute);

    void drawHourHand(wxDC &dc, int percentage_length, int hour, int minute);

    void drawLineFromCenter(wxDC &dc, int start_at_radius, int end_at_radius, int angle);

    void drawTextFromCenter(wxDC &dc, int pos_at_radius, int angle, wxString text);

    double radian(int angle);

    int radius;
    wxPoint origin_point;
};


#endif //ALL_IMAGEPANEL_H
