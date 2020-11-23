#include "wx_defines.h"
#include <wx/defs.h>

#include <wx/button.h>
#include <wx/listbox.h>
#include <wx/sizer.h>

#include "colores.h"

const int ID_LISTBOX = 102;

BEGIN_EVENT_TABLE(ColoresDialog, wxDialog)
    EVT_SIZE(ColoresDialog::OnSize)
    EVT_BUTTON(wxID_OK, ColoresDialog::CloseWindow)
    EVT_BUTTON(wxID_CANCEL, ColoresDialog::abandonar)
    EVT_CLOSE(ColoresDialog::OnCloseWindow)
    EVT_LISTBOX(ID_LISTBOX, ColoresDialog::SetColor)
    EVT_LISTBOX_DCLICK(ID_LISTBOX, ColoresDialog::SetColor)
END_EVENT_TABLE()

ColoresDialog::ColoresDialog(wxWindow* parent) :
    wxDialog(parent, wxID_ANY, _T("Background color"), wxDefaultPosition)
{
	wxSize sz = wxSize(200, 100);
	wxPoint p= wxPoint(-1,-1);
    wxListBox* list = new wxListBox(this, ID_LISTBOX,p, sz, 0, 0, wxLB_SINGLE);
	list->Append(_T("Cyan"));
	list->Append(_T("Green"));
	list->Append(_T("Magenta"));
	list->Append(_T("Yellow"));

    m_OK = new wxButton(this, wxID_OK);
    m_cancel = new wxButton(this, wxID_CANCEL);

    wxBoxSizer *button_sizer = new wxBoxSizer( wxHORIZONTAL );
    button_sizer->Add( m_cancel, 0, wxALL, 10 );
    button_sizer->Add( m_OK, 0, wxALL, 10 );

    wxBoxSizer *topsizer = new wxBoxSizer( wxVERTICAL );
    topsizer->Add( list, 1, wxEXPAND | wxLEFT | wxRIGHT, 10 );
    topsizer->Add( button_sizer, 0, wxALIGN_LEFT );

    SetSizer( topsizer );
    topsizer->SetSizeHints( this );
    CentreOnParent();
}

void ColoresDialog::OnSize(wxSizeEvent& WXUNUSED(event)){
    Layout();
}

void ColoresDialog::SetColor(wxCommandEvent& event){
	if (event.GetEventType() == wxEVT_COMMAND_LISTBOX_SELECTED){
        m_color=event.GetString();
    }else if(event.GetEventType() == wxEVT_COMMAND_LISTBOX_DOUBLECLICKED){
        m_color=event.GetString();
    	EndModal(wxID_OK);
	}
}

void ColoresDialog::CloseWindow(wxCommandEvent& event){
	if (event.GetEventType() == wxEVT_COMMAND_LISTBOX_SELECTED){
        m_color=event.GetString();
    }
    EndModal(wxID_OK);
}

void ColoresDialog::abandonar(wxCommandEvent& WXUNUSED(event)){
	    EndModal(wxID_CANCEL);
}

void ColoresDialog::OnCloseWindow(wxCloseEvent& WXUNUSED(event)){
    EndModal(wxID_CANCEL);
}
