#include "frame.h"

SimpleFrame::SimpleFrame(const wxString& title):
	wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 350)) {
	Centre();
}