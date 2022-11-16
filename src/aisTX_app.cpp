#include <wx/wx.h>
#include <wx/image.h>

#include "aisTX_appFrameMain.h"
#include "aisTX_appPanelMain.h"

#include "../data/folder.xpm"
wxIcon icon(play);


class wxHelloApp : public wxApp {

public:
	wxHelloApp() = default;
	virtual ~wxHelloApp() = default;
	bool OnInit() override;
	int OnExit() override { return 0; }

};

IMPLEMENT_APP(wxHelloApp);

inline bool wxHelloApp::OnInit() {

	auto *mainFrame = new aisTX_appFrameMain(nullptr);
	new aisTX_appPanelMain(mainFrame);
	mainFrame->SetIcon(icon);
	mainFrame->Show(true);
	SetTopWindow(mainFrame);
	mainFrame->Refresh();
	return true;
}