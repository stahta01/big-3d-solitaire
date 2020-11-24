/////////////////////////////////////////////////////////////////////////////
// Name:        scorefil.h
// Purpose:     Forty Thieves patience game
// Author:      Chris Breeze
// Modified by:
// Created:     21/07/97
// RCS-ID:      $Id: scorefil.h,v 1.6 2004/06/02 09:14:59 ABX Exp $
// Copyright:   (c) 1993-1998 Chris Breeze
// Licence:     wxWindows licence
//---------------------------------------------------------------------------
// Last modified: 22nd July 1998 - ported to wxWidgets 2.0
/////////////////////////////////////////////////////////////////////////////
#ifndef SCOREFILE_H_INCLUDED
#define SCOREFILE_H_INCLUDED

#include <wx/config.h>

class ScoreFile {
public:
	int myWins[40];
	int myGames[40];
    ScoreFile(const wxString& appName);
    virtual ~ScoreFile();

    void GetPlayerList( wxArrayString &list );
    wxString GetPreviousPlayer() const;

    //void LeePuntuacionJugador(const wxString& player);
    //int &myWins, int &myGames);
    void Lee    (const wxString& player);
    void Escribe(const wxString& player, int total[], int ganados[]);

private:
    long CalcCheck(const wxString& name, int p1, int p2);
    wxString m_configFilename;
    wxConfig* m_config;
};

#endif
