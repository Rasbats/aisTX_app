#include "aisTX_appPanelMain.h"

class aisEncoder;


// ----------------------------------------------------------------------------
// wxProcess-derived classes
// ----------------------------------------------------------------------------

// This is the handler for process termination events
class MyProcess : public wxProcess
{
public:
	MyProcess(aisTX_appPanelMain *parent, const wxString& cmd)
		: wxProcess(parent), m_cmd(cmd)
	{
		m_parent = parent;
	}

	// instead of overriding this virtual function we might as well process the
	// event from it in the frame class - this might be more convenient in some
	// cases
	virtual void OnTerminate(int pid, int status);

protected:
	aisTX_appPanelMain *m_parent;
	wxString m_cmd;
};

// ----------------------------------------------------------------------------
// MyProcess
// ----------------------------------------------------------------------------

void MyProcess::OnTerminate(int pid, int status)
{
	// we're not needed any more
	delete this;
}


aisTX_appPanelMain::aisTX_appPanelMain( wxWindow* parent )
:
PanelMain( parent )
{   
	int portnum; // Number of available ports

	portnum = Find_Comm(comports); // Call to the ports finder function

	for (int i = 0; i < portnum; i++)
	{
		comSel->Append(comports[i]); // Showing the available ports in the comSel combo box
	}

	comSel->SetSelection(0);
}


void aisTX_appPanelMain::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxMessageBox(wxString::Format(
		_T("Welcome to %s!\n")
		_T("\n")
		_T("This is the aisTX_app template\n")
		_T("running under %s."),
		wxVERSION_STRING,
		wxGetOsDescription().c_str()
	),
		_T("About aisTX_app"),
		wxOK | wxICON_INFORMATION,
		this);
}

void aisTX_appPanelMain::OnStart(wxCommandEvent& event) {

	MSG = "8";
	FI = 44;
	DAC = 200;
	payloadText = "BRUG OPEN";
	AisEncoder E = AisEncoder(MSG, FI, DAC, payloadText);
	serialOut = E.getFullMsg();

	StartDriving();

}

 int aisTX_appPanelMain::StartDriving() {


	wxString wxserialOut = GetMessage();
	char* com_port = "\\\\.\\COM8";
	int rate;
	//DWORD COM_BAUD_RATE = CBR_4800;

	wxString rateSelected = rateSel->GetStringSelection();
	rate = wxAtoi(rateSelected);

	COM_BAUD_RATE = GetBaudRate(rate);

	wxString comSelected = comSel->GetStringSelection();
	int port_aux = 0;

	if (comSelected.size() > 1)
	{
		port_aux = (int)comSelected[3] - 48;
		wxString myPort = wxString::Format("%i", port_aux);

		com_port  = GetComPort(port_aux);		
		mySerial = new SimpleSerial(com_port, COM_BAUD_RATE);
			
	}

	//serialOut = "!AIVDM,1,1,,A,8000000j;02`004<8tS4`eP85D588DU@Dr04r1=A8tlhDUADpLDp,0*2F";

	//
	// GetMessage() creates an AIVDM message, as sent by a transceiver
	// Comment out if you want to send a BBM to the transceiver
	//
	serialOut = GetMessage();
	charArray = new char[serialOut.size() + 1];
	copy(serialOut.begin(), serialOut.end(), charArray);

	m_timer1.Start(500, wxTIMER_CONTINUOUS);
	return 0;
}

void aisTX_appPanelMain::OnTimer(wxTimerEvent& event) { 

	mySerial->WriteSerialPort(charArray);
	mySerial->WriteSerialPort("\r\n");

	Sleep(200);
}

void aisTX_appPanelMain::OnStop(wxCommandEvent& event){
	m_timer1.Stop();
}


wxString aisTX_appPanelMain::GetMessage() {

	long value;

	int pageSelected = 0;

	if (pageSelected == 0) {

		wxString mMMSI = m_textMMSI1->GetValue();
		mMMSI.ToLong(&value);
		int vMMSI = value;

		wxString xcountry = m_textCountry1->GetValue();
		const char* mcountry = xcountry.c_str();
		string country = mcountry;
		std::transform(country.begin(), country.end(), country.begin(), ::toupper);


		wxString mSection = m_textFairwaySection1->GetValue();
		mSection.ToLong(&value);
		int vSection = value;

		wxString xCode = m_textObjectCode1->GetValue();
		const char* mCode = xCode.c_str();
		string Code = mCode;
		std::transform(Code.begin(), Code.end(), Code.begin(), ::toupper);

		wxString mHect = m_textHectometre1->GetValue();
		mHect.ToLong(&value);
		int vHect = value;


		wxString Text = m_textText1->GetValue();
		const char* cText = Text.c_str();
		string mText = cText;
		std::transform(mText.begin(), mText.end(), mText.begin(), ::toupper);

		int vSpare = 0;

		myNMEAais44_8 = myAIS.nmeaEncode44_8(vMMSI, country, vSection, Code, vHect, mText);

		//wxMessageBox(myNMEAais44_8);

		return myNMEAais44_8;
	}
}

DWORD aisTX_appPanelMain::GetBaudRate(int rate) {

	switch (rate)
	{
		case 4800: {
			return CBR_9600;
			break;
		}
		case 9600: {
			return CBR_9600;
			break;
		}
		case 19200: {
			return CBR_9600;
			break;
		}
		case 38400: {
			return CBR_9600;
			break;
		}
	}

	return CBR_9600;
}

char* aisTX_appPanelMain::GetComPort(int port_aux) {
	
	char* com_port = "999";
	
	switch (port_aux)
	{
		case 1: {
			com_port = "\\\\.\\COM1";
			return com_port;
			break;
		}
		case 2: {
			com_port = "\\\\.\\COM2";
			return com_port;
			break;
		}

		case 3: {
			com_port = "\\\\.\\COM3";
			return com_port;
			break;
		}
		case 4: {
			com_port = "\\\\.\\COM4";
			return com_port;
			break;
		}

		case 5: {
			com_port = "\\\\.\\COM5";
			return com_port;
			break;
		}
		case 6: {
			com_port = "\\\\.\\COM6";
			return com_port;
			break;
		}
		case 7: {
			com_port = "\\\\.\\COM7";
			return com_port;
			break;
		}
		case 8: {
			com_port = "\\\\.\\COM8";
			return com_port;
			break;
		}
		case 9: {
			com_port = "\\\\.\\COM9";
			return com_port;
			break;
		}
		case 10: {
			com_port = "\\\\.\\COM10";
			return com_port;
			break;
		}
	}
	com_port = "\\\\.\\COM8";
	return com_port;
}
///////////////////////////////////////////////////////////

//
// This dialog not used. Left as an example.
//
CalendarDialog::CalendarDialog(wxWindow * parent, wxWindowID id, const wxString & title,
	const wxPoint & position, const wxSize & size, long style)
	: wxDialog(parent, id, title, position, size, style)
{

	wxString dimensions = wxT(""), s;
	wxPoint p;
	wxSize  sz;

	sz.SetWidth(220);
	sz.SetHeight(200);

	p.x = 6; p.y = 2;
	s.Printf(_(" x = %d y = %d\n"), p.x, p.y);
	dimensions.append(s);
	s.Printf(_(" width = %d height = %d\n"), sz.GetWidth(), sz.GetHeight());
	dimensions.append(s);
	dimensions.append(wxT("here"));

	dialogCalendar = new wxCalendarCtrl(this, -1, wxDefaultDateTime, p, sz, wxCAL_SHOW_HOLIDAYS, _("Tide Calendar"));

	m_staticText = new wxStaticText(this, wxID_ANY, _("Time:"), wxPoint(15, 200), wxSize(60, 21));

	wxDateTime dt = dt.Now();
	_timeCtrl = new wxTimePickerCtrl(this, wxID_ANY, dt, wxPoint(75, 200), wxSize(80, 21));

	p.y += sz.GetHeight() + 30;
	wxButton * b = new wxButton(this, wxID_OK, _("OK"), p, wxDefaultSize);
	p.x += 110;
	wxButton * c = new wxButton(this, wxID_CANCEL, _("Cancel"), p, wxDefaultSize);

}




