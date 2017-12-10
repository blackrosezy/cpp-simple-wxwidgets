#include "main.h"
#include "simple.h"

IMPLEMENT_APP(SimpleApp)

bool SimpleApp::OnInit() {
	Simple *simple = new Simple(wxT("My Simple App"));
	simple->Show(true);
	return true;
}