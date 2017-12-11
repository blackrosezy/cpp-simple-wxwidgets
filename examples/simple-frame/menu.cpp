#include "frame.h"

SimpleFrame::SimpleFrame(const wxString& title):
	wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 150)) {
	Centre();
}