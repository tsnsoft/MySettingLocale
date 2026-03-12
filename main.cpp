#include "main.h"
#include "tsnsoft.xpm"
#include <wx/log.h>

// initialize the application
IMPLEMENT_APP(MainApp);

////////////////////////////////////////////////////////////////////////////////
// application class implementation
////////////////////////////////////////////////////////////////////////////////

extern bool InitializeLocalization(); // НАША ЛОКАЛИЗАЦИЯ

bool MainApp::OnInit()
{
	// АКТИВАЦИЯ ЛОКАЛИЗАЦИИ НА НУЖНЫЙ ЯЗЫК -------------
	if (!InitializeLocalization()) { wxLogError(L"Ошибка инициализации локализации"); }
	// --------------------------------------------------
	
	MainFrame* frame = new MainFrame(NULL);
	SetTopWindow(frame);
	frame->Show();
	
	return true;
}

////////////////////////////////////////////////////////////////////////////////
// main application frame implementation
////////////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame(wxWindow* parent)
: MainFrameBase(parent) {
	this->SetIcon(wxIcon(tsnsoft_xpm));
}

MainFrame::~MainFrame() {         
}

// ЭТО НАША РЕАЛИЗАЦИЯ ОБРАБОТЧИКА ЗАКРЫТИЯ ФОРМЫ!
void MainFrame::OnCloseFrame(wxCloseEvent& event) {  // Обработчик события закрытия окна
	Destroy();
}
