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
    void drawClock(wxGraphicsContext *gc);

    void drawBaseClock(wxGraphicsContext *gc);

    void drawHands(wxGraphicsContext *gc);

    void drawClockCircle(wxGraphicsContext *gc);

    void drawCenterScrewCircle(wxGraphicsContext *gc);

    void drawMinuteLines(wxGraphicsContext *gc, int percentage_length);

    void drawHourLines(wxGraphicsContext *gc, int percentage_length);

    void drawNumbers(wxGraphicsContext *gc, int pos_from_center);

    void drawSecondHand(wxGraphicsContext *gc, int percentage_length, int second);

    void drawMinuteHand(wxGraphicsContext *gc, int percentage_length, int minute);

    void drawHourHand(wxGraphicsContext *gc, int percentage_length, int hour, int minute);

    void drawLineFromCenter(wxGraphicsContext *gc, int start_at_radius, int end_at_radius, int angle);

    void drawTextFromCenter(wxGraphicsContext *gc, int pos_at_radius, int angle, wxString text);

    double radian(int angle);

    int radius;
    wxPoint origin_point;
};


#endif //ALL_IMAGEPANEL_H
