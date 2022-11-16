///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/frame.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/combobox.h>
#include <wx/timer.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class FrameMain
///////////////////////////////////////////////////////////////////////////////
class FrameMain : public wxFrame
{
	private:

	protected:

	public:

		FrameMain( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("aisTX_app"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 322,644 ), long style = wxDEFAULT_FRAME_STYLE|wxRESIZE_BORDER|wxTAB_TRAVERSAL );

		~FrameMain();

};

///////////////////////////////////////////////////////////////////////////////
/// Class PanelMain
///////////////////////////////////////////////////////////////////////////////
class PanelMain : public wxPanel
{
	private:

	protected:
		wxStaticText* m_staticText37;
		wxButton* m_buttonTexts;
		wxButton* m_buttonWaterLevels;
		wxStaticText* m_staticText82;
		wxPanel* m_panel3;
		wxStaticText* m_staticText12;
		wxStaticText* m_staticText13;
		wxStaticText* m_staticText14;
		wxStaticText* m_staticText15;
		wxStaticText* m_staticText16;
		wxStaticText* m_staticText17;
		wxPanel* m_panel5;
		wxStaticText* m_staticText31;
		wxTextCtrl* m_textMMSI3;
		wxStaticText* m_staticText21;
		wxTextCtrl* m_textCountry3;
		wxStaticText* m_staticText41;
		wxTextCtrl* m_textGauge1;
		wxStaticText* m_staticText51;
		wxTextCtrl* m_textWaterRef1;
		wxStaticText* m_staticText61;
		wxTextCtrl* m_textValue1;
		wxStaticText* m_staticText71;
		wxTextCtrl* m_textGauge2;
		wxStaticText* m_staticText81;
		wxTextCtrl* m_textWaterRef2;
		wxStaticText* m_staticText91;
		wxTextCtrl* m_textValue2;
		wxStaticText* m_staticText101;
		wxTextCtrl* m_textGauge3;
		wxStaticText* m_staticText111;
		wxTextCtrl* m_textWaterRef3;
		wxStaticText* m_staticText511;
		wxTextCtrl* m_textValue3;
		wxButton* m_buttonSave;
		wxButton* m_buttonDelete;
		wxButton* m_bpPlay;
		wxButton* m_bpStop;
		wxComboBox* comSel;
		wxComboBox* rateSel;

		// Virtual event handlers, override them in your derived class
		virtual void OnTexts( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnWaterLevels( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMessageSave( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMessageDelete( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStart( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnStop( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTimer( wxTimerEvent& event ) { event.Skip(); }


	public:
		wxNotebook* m_notebookMessage
		;
		wxTextCtrl* m_textMMSI1;
		wxTextCtrl* m_textCountry1;
		wxTextCtrl* m_textFairwaySection1;
		wxTextCtrl* m_textObjectCode1;
		wxTextCtrl* m_textHectometre1;
		wxTextCtrl* m_textText1;
		wxStaticText* m_staticText20;
		wxStaticText* m_staticText201;
		wxTimer m_timer1;

		PanelMain( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 270,705 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

		~PanelMain();

};

