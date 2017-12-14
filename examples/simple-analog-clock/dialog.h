#include <wx/wx.h>
#include "clockdc.h"
#include "clockgc.h"

class SimpleDialog : public wxDialog {
public:
    SimpleDialog(const wxString &title);

private:
    void OnQuit(wxCloseEvent &event);
    void OnTimer(wxTimerEvent &event);

    wxClockGC *clockGC;
    wxClockDC *clockDC;
    wxTimer *timer;
};