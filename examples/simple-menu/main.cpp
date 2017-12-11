#include "main.h"
#include "menu.h"

IMPLEMENT_APP(SimpleApp)

bool SimpleApp::OnInit() {
	SimpleMenu *simple = new SimpleMenu(wxT("My SimpleMenu App"));
	simple->SetIcon(wxICON(APP_ICON));
	simple->Show(true);
	return true;
}