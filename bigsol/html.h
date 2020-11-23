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

#ifndef HTML_H_
#define HTML_H_

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

// ****************************** //
// LA CLASE ABOUT EN FORMATO HTML //
// ****************************** //
class BigAbouHTML: public wxDialog{
public:
    // constructors and destructors
    BigAbouHTML( wxWindow *parent, wxWindowID id, const wxString &title,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE );
    bool AddControls(wxWindow* parent);
};

// *************************** //
// LA LICENCIA EN FORMATO HTML //
// *************************** //
class LicenseHTML: public wxDialog{
public:
    // constructors and destructors
    LicenseHTML( wxWindow *parent, wxWindowID id, const wxString &title,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE );
    bool AddControls(wxWindow* parent);
};
// ************** //
// HELP GAME HTML //
// ************** //
class HelpGameHTML: public wxDialog{
public:
    // constructors and destructors
    HelpGameHTML( wxWindow *parent, wxWindowID id, const wxString &title,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = wxDEFAULT_DIALOG_STYLE );
    bool AddControls(wxWindow* parent);
};

#endif /*HTML_H_*/
