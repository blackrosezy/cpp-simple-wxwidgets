#include <wx/wx.h>

class SimpleApp: public wxApp {
  public:
	virtual bool OnInit();
};

DECLARE_APP(SimpleApp)