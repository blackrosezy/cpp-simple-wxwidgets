#include <wx/wx.h>

class SimpleDialog : public wxDialog {
public:
    SimpleDialog(const wxString &title);

private:
    void OnQuit(wxCloseEvent &event);
    void OnContextMenu(wxContextMenuEvent &event);
    void OnContextMenuClick(wxCommandEvent &event);

    wxMenuBar *menuBar;
    wxMenu *menuFile;
};