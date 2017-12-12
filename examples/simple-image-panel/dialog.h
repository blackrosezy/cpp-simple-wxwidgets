#include <wx/wx.h>
#include "imagePanel.h"

class SimpleDialog : public wxDialog {
public:
    SimpleDialog(const wxString &title);

private:
    void OnQuit(wxCloseEvent &event);

    ImagePanel *imagePanel;
};