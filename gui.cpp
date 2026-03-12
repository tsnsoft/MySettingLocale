///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.736-v4.2.1-115-g11c2dec8-dirty)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

MainFrameBase::MainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 300,150 ), wxSize( 300,150 ) );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_staticText3 = new wxStaticText( m_panel1, wxID_ANY, _(L"Привет !"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer3->Add( m_staticText3, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_staticText4 = new wxStaticText( m_panel1, wxID_ANY, _(L"Я программа на русском языке"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer3->Add( m_staticText4, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	m_button2 = new wxButton( m_panel1, wxID_ANY, _(L"Нажми на меня"), wxDefaultPosition, wxSize( 110,30 ), 0 );
	m_button2->SetMinSize( wxSize( 110,30 ) );

	bSizer3->Add( m_button2, 0, wxALIGN_CENTER_HORIZONTAL|wxALL|wxFIXED_MINSIZE, 5 );


	m_panel1->SetSizer( bSizer3 );
	m_panel1->Layout();
	bSizer3->Fit( m_panel1 );
	bSizer2->Add( m_panel1, 1, wxEXPAND | wxALL, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnClick ), NULL, this );
}

MainFrameBase::~MainFrameBase()
{
	// Disconnect Events
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainFrameBase::OnClick ), NULL, this );

}
