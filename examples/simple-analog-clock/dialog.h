#include <wx/wx.h>
#include "clockPanel.h"

class SimpleDialog : public wxDialog {
public:
    SimpleDialog(const wxString &title);

private:
    void OnQuit(wxCloseEvent &event);
    void OnTimer(wxTimerEvent &event);

    ClockPanel *imagePanel;
    wxTimer *timer;
};