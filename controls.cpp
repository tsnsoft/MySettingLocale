#include "main.h"

#include <wx/msgdlg.h>
/*
 В ЭТОТ ФАЙЛ МОЖНО ПОМЕЩАТЬ ВСЕ ОБРАБОТЧИКИ СОБЫТИЙ ПРОГРАММЫ
 */

// ЭТО РЕАЛИЗАЦИЯ НАШЕГО МЕТОДА ОБРАБОТЧИКА СОБЫТИЯ НАЖАТИЯ НА КНОПКУ!
void MainFrame::OnClick(wxCommandEvent& event) {
	wxMessageBox(_(L"Здравствуйте"), _(L"Сообщение"), wxOK | wxICON_INFORMATION);
}
