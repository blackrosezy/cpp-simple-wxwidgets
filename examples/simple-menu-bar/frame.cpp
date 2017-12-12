#include "frame.h"

SimpleDialog::SimpleDialog(const wxString &title) :
        wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 350)) {
    wxImage::AddHandler(new wxPNGHandler);
    menuBar = new wxMenuBar;

    menuFile = new wxMenu;

    wxMenuItem *menuItemNothing = new wxMenuItem(menuFile, wxID_ANY, wxT("Do nothing"));
    wxBitmap bmpNothings(wxBITMAP_PNG(PNG_NOTHING));
    menuItemNothing->SetBitmap(bmpNothings);
    menuFile->Append(menuItemNothing);
    menuFile->Append(wxID_SEPARATOR);
    menuFile->Append(wxID_EXIT, wxT("&Quit"));

    menuBar->Append(menuFile, wxT("&File"));
    SetMenuBar(menuBar);
    Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(SimpleDialog::OnQuit));

    Centre();
}

void SimpleDialog::OnQuit(wxCommandEvent &event) {
    Close(true);
}