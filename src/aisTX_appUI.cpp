///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "aisTX_appUI.h"

///////////////////////////////////////////////////////////////////////////

FrameMain::FrameMain( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );


	this->Centre( wxBOTH );
}

FrameMain::~FrameMain()
{
}

PanelMain::PanelMain( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );

	m_staticText37 = new wxStaticText( this, wxID_ANY, _("  Saved Messages"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText37->Wrap( -1 );
	m_staticText37->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	bSizer15->Add( m_staticText37, 0, wxALL, 5 );


	bSizer10->Add( bSizer15, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer132;
	bSizer132 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonTexts = new wxButton( this, wxID_ANY, _("Text Messages"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonTexts->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	bSizer132->Add( m_buttonTexts, 0, wxALL, 5 );

	m_buttonWaterLevels = new wxButton( this, wxID_ANY, _("Water Levels"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonWaterLevels->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	bSizer132->Add( m_buttonWaterLevels, 0, wxALL, 5 );


	bSizer12->Add( bSizer132, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxVERTICAL );

	m_staticText82 = new wxStaticText( this, wxID_ANY, _("   AIS Message"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText82->Wrap( -1 );
	m_staticText82->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	bSizer121->Add( m_staticText82, 0, wxALL|wxEXPAND, 5 );

	m_notebookMessage
	= new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel3 = new wxPanel( m_notebookMessage
	, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer131;
	bSizer131 = new wxBoxSizer( wxVERTICAL );

	wxGridSizer* gSizer2;
	gSizer2 = new wxGridSizer( 0, 2, 0, 0 );

	m_staticText12 = new wxStaticText( m_panel3, wxID_ANY, _("MMSI"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	gSizer2->Add( m_staticText12, 0, wxALL, 5 );

	m_textMMSI1 = new wxTextCtrl( m_panel3, wxID_ANY, _("244123459"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_textMMSI1, 0, wxALL, 5 );

	m_staticText13 = new wxStaticText( m_panel3, wxID_ANY, _("Country"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	gSizer2->Add( m_staticText13, 0, wxALL, 5 );

	m_textCountry1 = new wxTextCtrl( m_panel3, wxID_ANY, _("NL"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_textCountry1, 0, wxALL, 5 );

	m_staticText14 = new wxStaticText( m_panel3, wxID_ANY, _("Fairway Section"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	gSizer2->Add( m_staticText14, 0, wxALL, 5 );

	m_textFairwaySection1 = new wxTextCtrl( m_panel3, wxID_ANY, _("201"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_textFairwaySection1, 0, wxALL, 5 );

	m_staticText15 = new wxStaticText( m_panel3, wxID_ANY, _("Object Code"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	gSizer2->Add( m_staticText15, 0, wxALL, 5 );

	m_textObjectCode1 = new wxTextCtrl( m_panel3, wxID_ANY, _("05397"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_textObjectCode1, 0, wxALL, 5 );

	m_staticText16 = new wxStaticText( m_panel3, wxID_ANY, _("Hectometre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	gSizer2->Add( m_staticText16, 0, wxALL, 5 );

	m_textHectometre1 = new wxTextCtrl( m_panel3, wxID_ANY, _("267"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer2->Add( m_textHectometre1, 0, wxALL, 5 );


	bSizer131->Add( gSizer2, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer( wxVERTICAL );

	m_staticText17 = new wxStaticText( m_panel3, wxID_ANY, _("Text"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	m_staticText17->SetFont( wxFont( 9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	bSizer101->Add( m_staticText17, 0, wxALL, 5 );

	m_textText1 = new wxTextCtrl( m_panel3, wxID_ANY, _("BRUG OPEN"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_WORDWRAP );
	bSizer101->Add( m_textText1, 0, wxALL|wxEXPAND, 5 );


	bSizer131->Add( bSizer101, 0, wxEXPAND, 5 );


	m_panel3->SetSizer( bSizer131 );
	m_panel3->Layout();
	bSizer131->Fit( m_panel3 );
	m_notebookMessage
	->AddPage( m_panel3, _("Text"), true );
	m_panel5 = new wxPanel( m_notebookMessage
	, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxGridSizer* gSizer11;
	gSizer11 = new wxGridSizer( 0, 2, 0, 0 );

	m_staticText31 = new wxStaticText( m_panel5, wxID_ANY, _("MMSI"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	gSizer11->Add( m_staticText31, 0, wxALL, 5 );

	m_textMMSI3 = new wxTextCtrl( m_panel5, wxID_ANY, _("00000"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer11->Add( m_textMMSI3, 0, wxALL, 5 );

	m_staticText21 = new wxStaticText( m_panel5, wxID_ANY, _("Country"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	gSizer11->Add( m_staticText21, 0, wxALL, 5 );

	m_textCountry3 = new wxTextCtrl( m_panel5, wxID_ANY, _("ZZ"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer11->Add( m_textCountry3, 0, wxALL, 5 );

	m_staticText41 = new wxStaticText( m_panel5, wxID_ANY, _("Gauge ID 1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText41->Wrap( -1 );
	gSizer11->Add( m_staticText41, 0, wxALL, 5 );

	m_textGauge1 = new wxTextCtrl( m_panel5, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer11->Add( m_textGauge1, 0, wxALL, 5 );

	m_staticText51 = new wxStaticText( m_panel5, wxID_ANY, _("Water level Ref 1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	gSizer11->Add( m_staticText51, 0, wxALL, 5 );

	m_textWaterRef1 = new wxTextCtrl( m_panel5, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer11->Add( m_textWaterRef1, 0, wxALL, 5 );

	m_staticText61 = new wxStaticText( m_panel5, wxID_ANY, _("Water level value 1"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText61->Wrap( -1 );
	gSizer11->Add( m_staticText61, 0, wxALL, 5 );

	m_textValue1 = new wxTextCtrl( m_panel5, wxID_ANY, _("-65536"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer11->Add( m_textValue1, 0, wxALL, 5 );

	m_staticText71 = new wxStaticText( m_panel5, wxID_ANY, _("Gauge ID 2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText71->Wrap( -1 );
	gSizer11->Add( m_staticText71, 0, wxALL, 5 );

	m_textGauge2 = new wxTextCtrl( m_panel5, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer11->Add( m_textGauge2, 0, wxALL, 5 );

	m_staticText81 = new wxStaticText( m_panel5, wxID_ANY, _("Water level Ref 2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText81->Wrap( -1 );
	gSizer11->Add( m_staticText81, 0, wxALL, 5 );

	m_textWaterRef2 = new wxTextCtrl( m_panel5, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer11->Add( m_textWaterRef2, 0, wxALL, 5 );

	m_staticText91 = new wxStaticText( m_panel5, wxID_ANY, _("Water level value 2"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText91->Wrap( -1 );
	gSizer11->Add( m_staticText91, 0, wxALL, 5 );

	m_textValue2 = new wxTextCtrl( m_panel5, wxID_ANY, _("-65536"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer11->Add( m_textValue2, 0, wxALL, 5 );

	m_staticText101 = new wxStaticText( m_panel5, wxID_ANY, _("Gauge ID 3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText101->Wrap( -1 );
	gSizer11->Add( m_staticText101, 0, wxALL, 5 );

	m_textGauge3 = new wxTextCtrl( m_panel5, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer11->Add( m_textGauge3, 0, wxALL, 5 );

	m_staticText111 = new wxStaticText( m_panel5, wxID_ANY, _("Water level Ref 3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText111->Wrap( -1 );
	gSizer11->Add( m_staticText111, 0, wxALL, 5 );

	m_textWaterRef3 = new wxTextCtrl( m_panel5, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer11->Add( m_textWaterRef3, 0, wxALL, 5 );

	m_staticText511 = new wxStaticText( m_panel5, wxID_ANY, _("Water level value 3"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText511->Wrap( -1 );
	gSizer11->Add( m_staticText511, 0, wxALL, 5 );

	m_textValue3 = new wxTextCtrl( m_panel5, wxID_ANY, _("-65536"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer11->Add( m_textValue3, 0, wxALL, 5 );


	m_panel5->SetSizer( gSizer11 );
	m_panel5->Layout();
	gSizer11->Fit( m_panel5 );
	m_notebookMessage
	->AddPage( m_panel5, _("Water_level"), false );

	bSizer121->Add( m_notebookMessage
	, 0, wxEXPAND | wxALL, 5 );


	bSizer12->Add( bSizer121, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer141;
	bSizer141 = new wxBoxSizer( wxHORIZONTAL );

	m_buttonSave = new wxButton( this, wxID_ANY, _("Save"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonSave->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	bSizer141->Add( m_buttonSave, 0, wxALL, 5 );

	m_buttonDelete = new wxButton( this, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonDelete->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );

	bSizer141->Add( m_buttonDelete, 0, wxALL, 5 );


	bSizer6->Add( bSizer141, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );


	bSizer16->Add( 0, 0, 1, wxEXPAND, 5 );

	m_bpPlay = new wxButton( this, wxID_ANY, _("Start Tx"), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_bpPlay->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );
	m_bpPlay->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_bpPlay->SetBackgroundColour( wxColour( 0, 255, 0 ) );

	bSizer16->Add( m_bpPlay, 0, wxALIGN_CENTER_VERTICAL|wxALL, 2 );

	m_bpStop = new wxButton( this, wxID_ANY, _("Stop Tx"), wxDefaultPosition, wxDefaultSize, 0 );
	m_bpStop->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial") ) );
	m_bpStop->SetBackgroundColour( wxColour( 255, 0, 0 ) );

	bSizer16->Add( m_bpStop, 0, wxALIGN_CENTER_VERTICAL|wxALL, 2 );


	bSizer16->Add( 0, 0, 1, wxEXPAND, 5 );


	bSizer6->Add( bSizer16, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer122;
	bSizer122 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText20 = new wxStaticText( this, wxID_ANY, _("Comport            "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	m_staticText20->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer122->Add( m_staticText20, 0, wxALL, 5 );

	comSel = new wxComboBox( this, wxID_ANY, _("Select Comport"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	bSizer122->Add( comSel, 0, wxALL, 5 );


	bSizer6->Add( bSizer122, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer1221;
	bSizer1221 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText201 = new wxStaticText( this, wxID_ANY, _("Baud rate          "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText201->Wrap( -1 );
	m_staticText201->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Arial") ) );

	bSizer1221->Add( m_staticText201, 0, wxALL, 5 );

	rateSel = new wxComboBox( this, wxID_ANY, _("9600"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	rateSel->Append( _("4800") );
	rateSel->Append( _("9600") );
	rateSel->Append( _("19200") );
	rateSel->Append( _("38400") );
	rateSel->SetSelection( 1 );
	bSizer1221->Add( rateSel, 0, wxALL|wxEXPAND, 5 );


	bSizer6->Add( bSizer1221, 0, wxEXPAND, 5 );


	bSizer14->Add( bSizer6, 0, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer12->Add( bSizer14, 0, wxEXPAND, 5 );


	bSizer10->Add( bSizer12, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer10 );
	this->Layout();
	m_timer1.SetOwner( this, wxID_ANY );

	// Connect Events
	m_buttonTexts->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::OnTexts ), NULL, this );
	m_buttonWaterLevels->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::OnWaterLevels ), NULL, this );
	m_buttonSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::OnMessageSave ), NULL, this );
	m_buttonDelete->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::OnMessageDelete ), NULL, this );
	m_bpPlay->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::OnStart ), NULL, this );
	m_bpStop->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::OnStop ), NULL, this );
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( PanelMain::OnTimer ) );
}

PanelMain::~PanelMain()
{
	// Disconnect Events
	m_buttonTexts->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::OnTexts ), NULL, this );
	m_buttonWaterLevels->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::OnWaterLevels ), NULL, this );
	m_buttonSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::OnMessageSave ), NULL, this );
	m_buttonDelete->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::OnMessageDelete ), NULL, this );
	m_bpPlay->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::OnStart ), NULL, this );
	m_bpStop->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelMain::OnStop ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( PanelMain::OnTimer ) );

}
