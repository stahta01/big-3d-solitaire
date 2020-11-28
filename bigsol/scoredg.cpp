/////////////////////////////////////////////////////////////////////////////
// Name:        scoredg.cpp
// Purpose:     Forty Thieves patience game
// Author:      Chris Breeze
// Modified by:
// Created:     21/07/97
// RCS-ID:      $Id: scoredg.cpp,v 1.16 2006/10/31 08:50:13 RD Exp $
// Copyright:   (c) 1993-1998 Chris Breeze
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "wx_defines.h"
#include <wx/defs.h>

#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/grid.h>

#include "resource.h"
#include "scoredg.h"
#define USE_GRID_FOR_SCORE     wxUSE_GRID


BEGIN_EVENT_TABLE(ScoreDialog, wxDialog)
    EVT_CLOSE(ScoreDialog::OnCloseWindow)
END_EVENT_TABLE()

ScoreDialog::ScoreDialog(wxWindow* parent, int total[], int ganados[], wxString jugador) :
    wxDialog(parent, wxID_ANY, _("Statistics ")+jugador, wxDefaultPosition, wxSize(500, 400))
{
    wxSize sz = wxSize(500, 400);
#if USE_GRID_FOR_SCORE
    wxGrid* list = new wxGrid(this, wxID_ANY, wxDefaultPosition, sz, 0);
    list->CreateGrid(41, 4);
    int total_general=0;
    int ganados_general=0;
    float f=0.00f;
    for (unsigned int i = 0; i < 40; i++){
        wxString string_value;
        //list->SetCellValue(i,0,juegos[i]);
        list->SetCellValue(i,0,jocs[i].nombre);
        string_value.Printf( _T("%u"), total[i] );
        list->SetCellValue(i,1,string_value);
        string_value.Printf( _T("%u"), ganados[i] );
        list->SetCellValue(i,2,string_value);
        if(total[i]==0){
        	string_value.Printf( _T("%3.2f %%"),f);
        }else{
        	string_value.Printf( _T("%3.2f %%"),(float)(((float)ganados[i]/(float)total[i])*100));
        }
        list->SetCellValue(i,3,string_value);
        total_general+=total[i];
        ganados_general+=ganados[i];
    }
    wxString string_value;
    list->SetCellValue(40,0,wxEmptyString);
    string_value.Printf( _T("%u"), total_general);
    list->SetCellValue(40,1,string_value);
    string_value.Printf( _T("%u"), ganados_general);
    list->SetCellValue(40,2,string_value);
    if(total_general==0){
    	string_value.Printf( _T("%3.2f %%"),f);
    }else{
    	string_value.Printf( _T("%3.2f %%"),(float)(((float)ganados_general/(float)total_general)*100));
    }
    list->SetCellValue(40,3,string_value);
    
    list->SetColLabelValue(0, _T("Game"));
    list->SetColLabelValue(1, _T(" Total"));
    list->SetColLabelValue(2, _T("  Wins"));
    list->SetColLabelValue(3, _T("     %"));
    list->EnableEditing(false);
    //list->AutoSizeColumns();
    list->SetColSize(0,170);
    list->SetColSize(1,50);
    list->SetColSize(2,50);
    list->SetColSize(3,10);

    list->SetColLabelAlignment(wxALIGN_LEFT,wxALIGN_CENTRE);
    list->SetDefaultCellAlignment(wxALIGN_CENTRE, wxALIGN_CENTRE);
    list->SetRowLabelSize(0);
 //   list->SetRowLabelAlignment(wxALIGN_LEFT, wxALIGN_CENTRE);

    list->SetCellTextColour(40, 0, *wxBLACK);
    list->SetCellTextColour(40, 1, *wxBLACK);
    list->SetCellTextColour(40, 2, *wxBLACK);
    list->SetCellTextColour(40, 3, *wxBLACK);
    list->SetCellBackgroundColour(40, 0, *wxLIGHT_GREY);
    list->SetCellBackgroundColour(40, 1, *wxLIGHT_GREY);
    list->SetCellBackgroundColour(40, 2, *wxLIGHT_GREY);
    list->SetCellBackgroundColour(40, 3, *wxLIGHT_GREY);
    
    font1=new wxFont();
    font1 = wxTheFontList->FindOrCreateFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    list->SetCellFont(40, 1, *font1);
    list->SetCellFont(40, 2, *font1);
    list->SetCellFont(40, 3, *font1);
    
    //list->SetLabelTextColour(*wxWHITE);
    //list->SetLabelBackgroundColour(*wxBLUE);
    list->AutoSizeRows();
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

void ScoreDialog::Display(){
    ShowModal();
}

void ScoreDialog::OnCloseWindow(wxCloseEvent& WXUNUSED(event)){
    EndModal(wxID_OK);
}
