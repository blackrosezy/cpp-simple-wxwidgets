#include "main.h"
#include "frame.h"

IMPLEMENT_APP(SimpleApp)

bool SimpleApp::OnInit() {
	SimpleDialog *simple = new SimpleDialog(wxT("My SimpleDialog App"));
	simple->SetIcon(wxICON(APP_ICON));
	simple->Show(true);
	return true;
}