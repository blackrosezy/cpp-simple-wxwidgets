//
// Created by blackrosezy on 12-Dec-17.
//

#ifndef ALL_WXCLOCKDC_H
#define ALL_WXCLOCKDC_H

#include <wx/wx.h>

class wxClockDC : public wxPanel {
public:
    wxClockDC(wxWindow *parent);

    void paintEvent(wxPaintEvent &event);

    void OnSize(wxSizeEvent &event);

private:

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


#endif //ALL_WXCLOCKDC_H
