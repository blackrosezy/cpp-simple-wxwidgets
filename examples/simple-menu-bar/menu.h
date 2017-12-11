#include <wx/wx.h>

class SimpleDialog: public wxFrame {
  public:
	SimpleDialog(const wxString& title);
	void OnQuit(wxCommandEvent& event);
    wxMenuBar *menuBar;
    wxMenu *menuFile;
};