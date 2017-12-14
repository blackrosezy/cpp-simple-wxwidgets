#include "dialog.h"

SimpleDialog::SimpleDialog(const wxString &title) :
        wxDialog(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 350),
                 wxDEFAULT_DIALOG_STYLE | wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxRESIZE_BORDER) {
    wxImage::AddHandler(new wxJPEGHandler);

    wxBoxSizer *sizer = new wxBoxSizer(wxHORIZONTAL);
    imagePanel = new ClockPanel(this, wxT("images/soup.jpg"));
    sizer->Add(imagePanel, 1, wxEXPAND);
    SetSizer(sizer);

    timer = new wxTimer(this);
    timer->Start(100);

    Centre();

    Bind(wxEVT_CLOSE_WINDOW, &SimpleDialog::OnQuit, this);
    Bind(wxEVT_TIMER, &SimpleDialog::OnTimer, this);
}


void SimpleDialog::OnQuit(wxCloseEvent &event) {
    timer->Stop();
    Destroy();
}

void SimpleDialog::OnTimer(wxTimerEvent &event){
    imagePanel->Refresh();
}