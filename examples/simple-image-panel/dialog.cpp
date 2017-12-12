#include "dialog.h"

SimpleDialog::SimpleDialog(const wxString &title) :
        wxDialog(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 350),
                 wxDEFAULT_DIALOG_STYLE | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxRESIZE_BORDER) {
    wxImage::AddHandler(new wxJPEGHandler);
    wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
    imagePanel = new ImagePanel(this, wxT("images/soup.jpg"));
    sizer->Add(imagePanel, 1, wxEXPAND);
    SetSizer(sizer);

    Centre();

    Bind(wxEVT_CLOSE_WINDOW, &SimpleDialog::OnQuit, this);
}


void SimpleDialog::OnQuit(wxCloseEvent &event) {
    Destroy();
}
