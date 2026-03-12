#include <wx/fileconf.h>
#include <wx/dir.h>
#include <wx/filename.h>
#include <wx/log.h>
#include <wx/filefn.h> 

// ЛОКАЛИЗАЦИЯ НА НУЖНЫЙ ЯЗЫК
bool InitializeLocalization()
{
	// Определение каталога с переводами и файла настроек
	wxString configFile = wxGetCwd() + wxFILE_SEP_PATH + "settings.ini";
	wxString langDirPath = wxGetCwd() + wxFILE_SEP_PATH + "lang";
	
	// Создание файла настроек, если его нет
	if (!wxFileExists(configFile)) {
		wxFileConfig createConfig("MyApp", wxEmptyString, configFile, wxEmptyString, 
								  wxCONFIG_USE_LOCAL_FILE);
		createConfig.Write("General/language", "ru");
		createConfig.Flush(); 
	}
	
	// Создание папки lang, если она отсутствует
	if (!wxDirExists(langDirPath)) {
		wxMkdir(langDirPath); 
	}
	
	// Читаем выбранный язык из конфига
	wxFileConfig config("MyApp", wxEmptyString, configFile, wxEmptyString, wxCONFIG_USE_LOCAL_FILE);
	wxString langStr;
	config.Read("General/language", &langStr, "ru");
	
	// Определяем код языка
	const wxLanguageInfo* langInfo = wxLocale::FindLanguageInfo(langStr);
	int languageCode = langInfo ? langInfo->Language : wxLANGUAGE_RUSSIAN;
	
	// Создаём и инициализируем локаль
	wxLocale* locale = new wxLocale;
	if (!locale->Init(languageCode)) {
		if (!locale->Init(wxLANGUAGE_ENGLISH)) {
			delete locale;
			return false;
		}
	}
	
	// Сканирование папки с локализациями
	wxLocale::AddCatalogLookupPathPrefix(langDirPath);
	wxDir dir(langDirPath);
	
	if (dir.IsOpened())	{
		wxString fileName;
		
		// Ищем подкаталоги
		bool cont = dir.GetFirst(&fileName, wxEmptyString, wxDIR_DIRS);
		while (cont) {
			locale->AddCatalog(fileName);
			cont = dir.GetNext(&fileName);
		}
		
		// Ищем .mo файлы
		cont = dir.GetFirst(&fileName, "*.mo", wxDIR_FILES);
		while (cont) {
			wxFileName fn(fileName);
			locale->AddCatalog(fn.GetName());
			cont = dir.GetNext(&fileName);
		}
	}
	
	return true;
}
