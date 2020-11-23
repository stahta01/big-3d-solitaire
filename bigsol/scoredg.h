/////////////////////////////////////////////////////////////////////////////
// Name:        scoredg.h
// Purpose:     Forty Thieves patience game
// Author:      Chris Breeze
// Modified by:
// Created:     21/07/97
// RCS-ID:      $Id: scoredg.h,v 1.4 2004/10/05 15:38:09 ABX Exp $
// Copyright:   (c) 1993-1998 Chris Breeze
// Licence:     wxWindows licence
//---------------------------------------------------------------------------
// Last modified: 22nd July 1998 - ported to wxWidgets 2.0
/////////////////////////////////////////////////////////////////////////////
#ifndef _SCOREDG_H_
#define _SCOREDG_H_

class ScoreDialog : public wxDialog
{
public:
    ScoreDialog(wxWindow* parent, int total[], int ganados[],wxString jugador);
    virtual ~ScoreDialog(){};

    void Display();

protected:
    void OnCloseWindow(wxCloseEvent& event);

private:
    //ScoreFile* m_scoreFile;
    wxButton* m_OK;
    wxFont*   font1;

DECLARE_EVENT_TABLE()
};

#endif
