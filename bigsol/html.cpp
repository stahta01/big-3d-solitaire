/*
Big Solitaries 3D
Copyright (C) 2006  F�lix Jos� Cladellas

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
// html.cpp: implementation of the game class->
//
//////////////////////////////////////////////////////////////////////

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

// HTML
#include "wx/textfile.h"
#include "wx/html/htmlwin.h"

#include "resource.h"
#include "html.h"

extern int		tipo_juego;

// ************** //
// HELP GAME HTML //
// ************** //
HelpGameHTML::HelpGameHTML( wxWindow *parent, wxWindowID id, const wxString &title,
    const wxPoint &position, const wxSize& size, long style ) :
    wxDialog( parent, id, title, position, size, style ){
    AddControls(this);
    Centre(wxBOTH);
}
bool HelpGameHTML::AddControls(wxWindow* parent){
    wxString htmlText;
   	//sprintf(buffer2,"help/%s",jocs[tipo_juego-7000].ayuda);
    wxString htmlFile = wxGetCwd() + wxFILE_SEP_PATH + jocs[tipo_juego-7000].ayuda;
    wxTextFile file(htmlFile);
    if (file.Exists()){
    	file.Open();
        for ( htmlText = file.GetFirstLine();
      	!file.Eof();
        htmlText << file.GetNextLine() << _T("\n") ) ;
    }
    if (htmlText.empty()){
        htmlText.Printf(wxT("<html><head><title>Warning</title></head><body><P>Sorry, could not find resource for Help Game<P></body></html>"));
    }
    // Customize the HTML
    //htmlText.Replace(wxT("$DATE$"), _T(__DATE__));
    wxSize htmlSize(650, 370);
#ifdef __WXMSW__
    long borderStyle = wxDOUBLE_BORDER;
#else
    long borderStyle = wxRAISED_BORDER;
#endif
    wxHtmlWindow* html = new wxHtmlWindow(this, ID_ABOUT_HTML_WINDOW, wxDefaultPosition, htmlSize, borderStyle);
    html -> SetBorders(5);
    html -> SetPage(htmlText);
    //// Start of sizer-based control creation
    wxSizer *item0 = new wxBoxSizer( wxVERTICAL );
    wxWindow *item1 = parent->FindWindow( ID_ABOUT_HTML_WINDOW );
    wxASSERT( item1 );
    item0->Add( item1, 0, wxALIGN_CENTRE|wxALL, 5 );
    wxButton *item2 = new wxButton( parent, wxID_CLOSE );
    item2->SetDefault();
    item2->SetFocus();
    SetAffirmativeId(wxID_CLOSE);
    item0->Add( item2, 0, wxALIGN_RIGHT|wxALL, 5 );
    parent->SetSizer( item0 );
    parent->Layout();
    item0->Fit( parent );
    item0->SetSizeHints( parent );
    return true;
}
// ************************ //
// LICENCIA EN FORMATO HTML //
// ************************ //
LicenseHTML::LicenseHTML( wxWindow *parent, wxWindowID id, const wxString &title,
    const wxPoint &position, const wxSize& size, long style ) :
    wxDialog( parent, id, title, position, size, style ){
    AddControls(this);
    Centre(wxBOTH);
}
bool LicenseHTML::AddControls(wxWindow* parent){
    wxString htmlText;
    wxString htmlFile = wxGetCwd() + wxFILE_SEP_PATH + wxT("license.html");
    wxTextFile file(htmlFile);
    if (file.Exists()){
    	file.Open();
        for ( htmlText = file.GetFirstLine();
      	!file.Eof();
        htmlText << file.GetNextLine() << _T("\n") ) ;
    }
    if (htmlText.empty()){
        htmlText.Printf(wxT("<html><head><title>Warning</title></head><body><P>Sorry, could not find resource for License dialog<P></body></html>"));
    }
    // Customize the HTML
    //htmlText.Replace(wxT("$DATE$"), _T(__DATE__));
    wxSize htmlSize(600, 400);
#ifdef __WXMSW__
    long borderStyle = wxDOUBLE_BORDER;
#else
    long borderStyle = wxRAISED_BORDER;
#endif
    wxHtmlWindow* html = new wxHtmlWindow(this, ID_ABOUT_HTML_WINDOW, wxDefaultPosition, htmlSize, borderStyle);
    html -> SetBorders(5);
    html -> SetPage(htmlText);
    //// Start of sizer-based control creation
    wxSizer *item0 = new wxBoxSizer( wxVERTICAL );
    wxWindow *item1 = parent->FindWindow( ID_ABOUT_HTML_WINDOW );
    wxASSERT( item1 );
    item0->Add( item1, 0, wxALIGN_CENTRE|wxALL, 5 );
    wxButton *item2 = new wxButton( parent, wxID_CLOSE );
    item2->SetDefault();
    item2->SetFocus();
    SetAffirmativeId(wxID_CLOSE);
    item0->Add( item2, 0, wxALIGN_RIGHT|wxALL, 5 );
    parent->SetSizer( item0 );
    parent->Layout();
    item0->Fit( parent );
    item0->SetSizeHints( parent );
    return true;
}
// ********************* //
// ABOUT EN FORMATO HTML //
// ********************* //
BigAbouHTML::BigAbouHTML( wxWindow *parent, wxWindowID id, const wxString &title,
    const wxPoint &position, const wxSize& size, long style ) :
    wxDialog( parent, id, title, position, size, style ){
    AddControls(this);
    Centre(wxBOTH);
}
bool BigAbouHTML::AddControls(wxWindow* parent){
    wxString htmlText;
    wxString htmlFile = wxGetCwd() + wxFILE_SEP_PATH + wxT("Data/help/about.html");
    wxTextFile file(htmlFile);
    if (file.Exists()){
    	file.Open();
        for ( htmlText = file.GetFirstLine();
        !file.Eof();
        htmlText << file.GetNextLine() << _T("\n") ) ;
    }
    if (htmlText.empty()){
        htmlText.Printf(wxT("<html><head><title>Warning</title></head><body><P>Sorry, could not find resource for About dialog<P></body></html>"));
    }
    // Customize the HTML
    //htmlText.Replace(wxT("$DATE$"), _T(__DATE__));
    wxSize htmlSize(440, 320);
    // Note: in later versions of wxWin this will be fixed so wxRAISED_BORDER
    // does the right thing. Meanwhile, this is a workaround.
#ifdef __WXMSW__
    long borderStyle = wxDOUBLE_BORDER;
#else
    long borderStyle = wxRAISED_BORDER;
#endif
    wxHtmlWindow* html = new wxHtmlWindow(this, ID_ABOUT_HTML_WINDOW, wxDefaultPosition, htmlSize, borderStyle);
    html -> SetBorders(10);
    html -> SetPage(htmlText);
    //// Start of sizer-based control creation
    wxSizer *item0 = new wxBoxSizer( wxVERTICAL );
    wxWindow *item1 = parent->FindWindow( ID_ABOUT_HTML_WINDOW );
    wxASSERT( item1 );
    item0->Add( item1, 0, wxALIGN_CENTRE|wxALL, 5 );
    wxButton *item2 = new wxButton( parent, wxID_CLOSE );
    item2->SetDefault();
    item2->SetFocus();
    SetAffirmativeId(wxID_CLOSE);
    item0->Add( item2, 0, wxALIGN_RIGHT|wxALL, 5 );
    parent->SetSizer( item0 );
    parent->Layout();
    item0->Fit( parent );
    item0->SetSizeHints( parent );
    return true;
}
