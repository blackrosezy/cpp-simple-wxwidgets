#include "dialog.h"
#include "id.h"

SimpleDialog::SimpleDialog(const wxString &title) :
        wxDialog(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 350),
                 wxDEFAULT_DIALOG_STYLE | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxRESIZE_BORDER) {
    wxImage::AddHandler(new wxPNGHandler);
    Centre();
    Bind(wxEVT_CLOSE_WINDOW, &SimpleDialog::OnQuit, this);
    Bind(wxEVT_CONTEXT_MENU, &SimpleDialog::OnContextMenu, this);

}

void SimpleDialog::OnQuit(wxCloseEvent &event) {
    Destroy();
}

void SimpleDialog::OnContextMenu(wxContextMenuEvent &event) {
    wxMenu *ctxMenu = new wxMenu;

    wxMenuItem *menuItemNothing = new wxMenuItem(ctxMenu, CLICK_ME, wxT("Click Me"));
    wxBitmap bmpNothings(wxBITMAP_PNG(PNG_NOTHING));
    menuItemNothing->SetBitmap(bmpNothings);

    ctxMenu->Append(menuItemNothing);
    ctxMenu->Append(wxID_ANY, wxT("About.."));

    Bind(wxEVT_MENU, &SimpleDialog::OnContextMenuClick, this);

    PopupMenu(ctxMenu);
}

void SimpleDialog::OnContextMenuClick(wxCommandEvent &event) {
    long id = event.GetId();
    switch (id) {
        case CLICK_ME:
            wxMessageBox("I have been clicked!");
            break;
    };

}