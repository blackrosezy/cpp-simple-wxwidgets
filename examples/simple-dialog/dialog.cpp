#include "dialog.h"

SimpleDialog::SimpleDialog(const wxString &title) :
        wxDialog(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150),wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER) {
    Centre();
    ShowModal();
    Destroy();
}