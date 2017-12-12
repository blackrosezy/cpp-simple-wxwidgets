#include <wx/wx.h>

class SimpleDialog : public wxDialog {
public:
    SimpleDialog(const wxString &title);

private:
    void OnQuit(wxCloseEvent &event);
};