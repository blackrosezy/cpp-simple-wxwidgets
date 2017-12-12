#include "main.h"
#include "frame.h"

IMPLEMENT_APP(SimpleApp)

bool SimpleApp::OnInit() {
	SimpleFrame *simple = new SimpleFrame(wxT("My SimpleFrame App"));
	simple->SetIcon(wxICON(APP_ICON));
	simple->Show(true);
	return true;
}