/*
Big Solitaries 3D
Copyright (C) 2006  Félix José Cladellas

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
// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include "resource.h"
#include "bestTimesdg.h"
#define USE_GRID_FOR_SCORE     wxUSE_GRID
#include "wx/grid.h"

BEGIN_EVENT_TABLE(BestTimesDialog, wxDialog)
    EVT_CLOSE(BestTimesDialog::OnCloseWindow)
END_EVENT_TABLE()

BestTimesDialog::BestTimesDialog(wxWindow* parent,wxString *Tiempo[],wxString *Jugador[], wxString *NumJuego[]) :
    wxDialog(parent, wxID_ANY, _("Best Times "), wxDefaultPosition, wxSize(600, 440))
{
    wxSize sz = wxSize(600, 440);
#if USE_GRID_FOR_SCORE
    wxGrid* list = new wxGrid(this, wxID_ANY, wxDefaultPosition, sz, 0);
    list->CreateGrid(40, 4);
    for (unsigned int i = 0; i < 40; i++){
        wxString string_value;
        list->SetCellValue(i,0,jocs[i].nombre);
        list->SetCellValue(i,1,*Jugador[i]);
        list->SetCellValue(i,2,*Tiempo[i]);
        list->SetCellValue(i,3,*NumJuego[i]);
    }
    list->SetColLabelValue(0, _T("Game"));
    list->SetColLabelValue(1, _T("     Player"));
    list->SetColLabelValue(2, _T("       Time"));
    list->SetColLabelValue(3, _T("   Number"));
    list->SetEditable(false);
    //list->AutoSizeColumns();
    list->SetColSize(0,170);
    list->SetColSize(1,100);
    list->SetColSize(2,100);
    list->SetColSize(3,-1);

    list->SetColLabelAlignment(wxALIGN_LEFT,wxALIGN_CENTRE);

    wxGridCellAttr *attr=new(wxGridCellAttr);
    wxGridCellAttr *attr2=new(wxGridCellAttr);
    attr->SetAlignment(wxALIGN_LEFT,wxALIGN_CENTRE);
    attr2->SetAlignment(wxALIGN_CENTRE,wxALIGN_CENTRE);
    list->SetColAttr(0,attr);
    list->SetColAttr(1,attr2);
    list->SetColAttr(2,attr2);
    list->SetColAttr(3,attr2);
    
    //list->SetCellAlignment(1, 1, wxALIGN_RIGHT,wxALIGN_CENTRE);
    list->SetCellTextColour(40, 0, *wxBLACK);
    list->SetCellTextColour(40, 1, *wxBLACK);
    list->SetCellTextColour(40, 2, *wxBLACK);
    list->SetCellTextColour(40, 3, *wxBLACK);
    list->SetCellBackgroundColour(40, 0, *wxLIGHT_GREY);
    list->SetCellBackgroundColour(40, 1, *wxLIGHT_GREY);
    list->SetCellBackgroundColour(40, 2, *wxLIGHT_GREY);
    list->SetCellBackgroundColour(40, 3, *wxLIGHT_GREY);
    
    font1=new wxFont();
    font1 = wxTheFontList->FindOrCreateFont(10, wxBOLD, wxNORMAL, wxNORMAL);
    list->SetCellFont(40, 1, *font1);
    list->SetCellFont(40, 2, *font1);
    list->SetCellFont(40, 3, *font1);
    
    //list->SetLabelTextColour(*wxWHITE);
    //list->SetLabelBackgroundColour(*wxBLUE);
    list->AutoSizeRows();
    list->SetRowLabelSize(0);
    list->EnableDragRowSize(false);
    list->EnableDragColSize(false);
    list->EnableDragGridSize(false);
    list->ClearSelection();
    list->EnableEditing(false);
    sz.x = wxDefaultCoord;
#else
   EndModal(wxID_OK);
#endif
    list->SetInitialSize(sz);
    // locate and resize with sizers
    wxBoxSizer *topsizer = new wxBoxSizer( wxHORIZONTAL );
    topsizer->Add( list, 1, wxALL|wxGROW, 10 );
    wxButton *button = new wxButton(this, wxID_OK);
    topsizer->Add( button, 0, wxALIGN_CENTER_HORIZONTAL|wxALL , 10 );
    button->SetFocus();
    SetSizer( topsizer );
    GetSizer()->Fit(this);
    GetSizer()->SetSizeHints(this);
    CentreOnParent();
}

void BestTimesDialog::Display(){
    ShowModal();
}

void BestTimesDialog::OnCloseWindow(wxCloseEvent& WXUNUSED(event)){
    EndModal(wxID_OK);
}
