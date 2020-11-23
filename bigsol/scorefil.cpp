/////////////////////////////////////////////////////////////////////////////
// Name:        scorefil.cpp
// Purpose:     Forty Thieves patience game
// Author:      Chris Breeze
// Modified by:
// Created:     21/07/97
// RCS-ID:      $Id: scorefil.cpp,v 1.8 2005/09/23 12:48:19 MR Exp $
// Copyright:   (c) 1993-1998 Chris Breeze
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#include "wx_defines.h"
#include <wx/defs.h>

#ifdef __WXGTK__
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#endif

#include <wx/msgdlg.h>
#include <wx/textfile.h>
#include <wx/config.h>
#include <wx/fileconf.h>

#include "scorefil.h"

ScoreFile::ScoreFile(const wxString& appName){
    m_config = new wxConfig(_T("bigsol.nfo"), _T("wxWidgets"),_T("bigsol.nfo"), wxEmptyString, wxCONFIG_USE_LOCAL_FILE);  // only local
    for(int k=0;k<40;k++){
    	myGames[k]=0;
        myWins[k]=0;
    }
}

ScoreFile::~ScoreFile()
{
    delete m_config;
#ifdef __WXGTK__
    // ensure score file has rw-rw-rw permissions
    // (wxFileConfig sets them to rw-------)
    chmod(m_configFilename, 0666);
#endif
}


void ScoreFile::GetPlayerList( wxArrayString &list ){
    m_config->SetPath(_T("/Players"));
    int length = m_config->GetNumberOfGroups();
    if (length <= 0) return;
    wxString player;
    long index;
    if (m_config->GetFirstGroup(player, index)){
         list.Add( player );
        while (m_config->GetNextGroup(player, index)){
              list.Add( player );
        }
    }
}

// Calculate an encrypted check number to prevent tampering with score file
long ScoreFile::CalcCheck(const wxString& name, int p1, int p2){
    long check = 0;
    size_t i, max = name.length();
    for(i = 0; i < max; ++i ){
        check = (check << 1) ^ (long)name[i];
        check = ((check >> 23) ^ check) & 0xFFFFFF;
    }
    check = (check << 1) ^ (long)p1;
    check = ((check >> 23) ^ check) & 0xFFFFFF;
    check = (check << 1) ^ (long)p2;
    check = ((check >> 23) ^ check) & 0xFFFFFF;
    return check;
}

wxString ScoreFile::GetPreviousPlayer() const{
    wxString result;
    m_config->SetPath(_T("/General"));
    m_config->Read(_T("LastPlayer"), &result);
    return result;
}

void ScoreFile::Lee(const wxString& player){
	long check = 0;
    int total[40];
    int ganados[40];
    for(int k=0;k<40;k++){
   		total[k]   = 0;
   		ganados[k] = 0;
   	}
    m_config->SetPath(_T("/Players"));
    m_config->SetPath(player);
    if( m_config->Read(_T("Canfield_Games"), &myGames[0], 0L) &&
        m_config->Read(_T("Canfield_Wins"),  &myWins[0], 0L) &&
        
		m_config->Read(_T("Canfield Two Decks_Games"), &myGames[1], 0L) &&
		m_config->Read(_T("Canfield Two Decks_Wins"),  &myWins[1], 0L) &&
		
		m_config->Read(_T("Canfield Superior_Games"), &myGames[2], 0L) &&
		m_config->Read(_T("Canfield Superior_Wins"),  &myWins[2], 0L) &&
		
		m_config->Read(_T("Corona_Games"), &myGames[3], 0L) &&
		m_config->Read(_T("Corona_Wins"),  &myWins[3], 0L) &&
		
		m_config->Read(_T("Doubles_Games"), &myGames[4], 0L) &&
		m_config->Read(_T("Doubles_Wins"),  &myWins[4], 0L) &&
		
		m_config->Read(_T("Doubles 13_Games"), &myGames[5], 0L) &&
		m_config->Read(_T("Doubles 13_Wins"),  &myWins[5], 0L) &&
		
		m_config->Read(_T("Easthaven_Games"), &myGames[6], 0L) &&
		m_config->Read(_T("Easthaven_Wins"),  &myWins[6], 0L) &&
		
		m_config->Read(_T("Emperor_Games"), &myGames[7], 0L) &&
		m_config->Read(_T("Emperor_Wins"),  &myWins[7], 0L) &&
		
		m_config->Read(_T("Forty Thieves_Games"), &myGames[8], 0L) &&
		m_config->Read(_T("Forty Thieves_Wins"),  &myWins[8], 0L) &&
		
		m_config->Read(_T("Forty Thieves and Eight_Games"), &myGames[9], 0L) &&
		m_config->Read(_T("Forty Thieves and Eight_Wins"),  &myWins[9], 0L) &&
		
		m_config->Read(_T("Forty Thieves Three Decks_Games"), &myGames[10], 0L) &&
		m_config->Read(_T("Forty Thieves Three Decks_Wins"),  &myWins[10], 0L) &&
		
		m_config->Read(_T("Forty Thieves Four Decks_Games"), &myGames[11], 0L) &&
		m_config->Read(_T("Forty Thieves Four Decks_Wins"),  &myWins[11], 0L) &&
		
		m_config->Read(_T("FreeCell_Games"), &myGames[12], 0L) &&
		m_config->Read(_T("FreeCell_Wins"),  &myWins[12], 0L) &&
		
		m_config->Read(_T("FreeCell Two Decks_Games"), &myGames[13], 0L) &&
		m_config->Read(_T("FreeCell Two Decks_Wins"),  &myWins[13], 0L) &&
		
		m_config->Read(_T("Golf_Games"), &myGames[14], 0L) &&
		m_config->Read(_T("Golf_Wins"),  &myWins[14], 0L) &&
		
		m_config->Read(_T("Golf A-K_Games"), &myGames[15], 0L) &&
		m_config->Read(_T("Golf A-K_Wins"),  &myWins[15], 0L) &&
		
		m_config->Read(_T("Golf A-K Two Decks_Games"), &myGames[16], 0L) &&
		m_config->Read(_T("Golf A-K Two Decks_Wins"),  &myWins[16], 0L) &&
		
		m_config->Read(_T("Indian_Games"), &myGames[17], 0L) &&
		m_config->Read(_T("Indian_Wins"),  &myWins[17], 0L) &&
		
		m_config->Read(_T("Klondike_Games"), &myGames[18], 0L) &&
		m_config->Read(_T("Klondike_Wins"),  &myWins[18], 0L) &&
		
		m_config->Read(_T("Klondike Two Decks_Games"), &myGames[19], 0L) &&
		m_config->Read(_T("Klondike Two Decks_Wins"),  &myWins[19], 0L) &&
		
		m_config->Read(_T("Lucky Fans_Games"), &myGames[20], 0L) &&
		m_config->Read(_T("Lucky Fans_Wins"),  &myWins[20], 0L) &&
		
		m_config->Read(_T("Montana Three Redeals_Games"), &myGames[21], 0L) &&
		m_config->Read(_T("Montana Three Redeals_Wins"),  &myWins[21], 0L) &&
		
		m_config->Read(_T("Ocean's Eleven_Games"), &myGames[22], 0L) &&
		m_config->Read(_T("Ocean's Eleven_Wins"),  &myWins[22], 0L) &&
		
		m_config->Read(_T("Rail One Deck_Games"), &myGames[23], 0L) &&
		m_config->Read(_T("Rail One Deck_Wins"),  &myWins[23], 0L) &&
		
		m_config->Read(_T("Rail Two Decks_Games"), &myGames[24], 0L) &&
		m_config->Read(_T("Rail Two Decks_Wins"),  &myWins[24], 0L) &&
		
		m_config->Read(_T("Russian_Games"), &myGames[25], 0L) &&
		m_config->Read(_T("Russian_Wins"),  &myWins[25], 0L) &&
		
		m_config->Read(_T("Russian Relaxed_Games"), &myGames[26], 0L) &&
		m_config->Read(_T("Russian Relaxed_Wins"),  &myWins[26], 0L) &&
		
		m_config->Read(_T("Scarab_Games"), &myGames[27], 0L) &&
		m_config->Read(_T("Scarab_Wins"),  &myWins[27], 0L) &&
		
		m_config->Read(_T("Scorpion_Games"), &myGames[28], 0L) &&
		m_config->Read(_T("Scorpion_Wins"),  &myWins[28], 0L) &&
		
		m_config->Read(_T("Simple Simon_Games"), &myGames[29], 0L) &&
		m_config->Read(_T("Simple Simon_Wins"),  &myWins[29], 0L) &&
		
		m_config->Read(_T("Spider_Games"), &myGames[30], 0L) &&
		m_config->Read(_T("Spider_Wins"),  &myWins[30], 0L) &&
		
		m_config->Read(_T("Spider One Suite_Games"), &myGames[31], 0L) &&
		m_config->Read(_T("Spider One Suite_Wins"),  &myWins[31], 0L) &&
		
		m_config->Read(_T("Spider Two Suites_Games"), &myGames[32], 0L) &&
		m_config->Read(_T("Spider Two Suites_Wins"),  &myWins[32], 0L) &&
		
		m_config->Read(_T("Spider Three Decks_Games"), &myGames[33], 0L) &&
		m_config->Read(_T("Spider Three Decks_Wins"),  &myWins[33], 0L) &&
		
		m_config->Read(_T("Spiderette_Games"), &myGames[34], 0L) &&
		m_config->Read(_T("Spiderette_Wins"),  &myWins[34], 0L) &&
		
		m_config->Read(_T("Spiderette Relaxed_Games"), &myGames[35], 0L) &&
		m_config->Read(_T("Spiderette Relaxed_Wins"),  &myWins[35], 0L) &&
		
		m_config->Read(_T("Towers_Games"), &myGames[36], 0L) &&
		m_config->Read(_T("Towers_Wins"),  &myWins[36], 0L) &&
		
		m_config->Read(_T("Yukon_Games"), &myGames[37], 0L) &&
		m_config->Read(_T("Yukon_Wins"),  &myWins[37], 0L) &&
		
		m_config->Read(_T("Yukon Relaxed_Games"), &myGames[38], 0L) &&
		m_config->Read(_T("Yukon Relaxed_Wins"),  &myWins[38], 0L) &&
		
		m_config->Read(_T("Z-Four_Games"), &myGames[39], 0L) &&
		m_config->Read(_T("Z-Four_Wins"),  &myWins[39], 0L) &&
         
        m_config->Read(_T("Check"), &check, 0L)){
        int total_general=0;
        int total_ganados=0;
        for(int j=0;j<40;j++){
        	total_general+=myGames[j];
        	total_ganados+=myWins[j];
        }
        if (check != CalcCheck(player, total_general, total_ganados)){
           	wxMessageBox(_T("Statistics file corrupted"), _T("Warning"), wxOK | wxICON_EXCLAMATION);
        }else{
        	for(int k=0;k<40;k++){
           		total[k]   = (int)myGames[k];
           		ganados[k] = (int)myWins[k];
           		//printf("total[%d] vale %d\n",k,total[k]);
        	}
        }
    }
    Escribe(player,total,ganados);
}

void ScoreFile::Escribe(const wxString& player,int total[], int ganados[]){
	int j=0;
    if (!player.IsEmpty()){
        m_config->SetPath(_T("/General"));
        m_config->Write(_T("LastPlayer"), wxString(player));
        m_config->SetPath(_T("/Players"));
        m_config->SetPath(player);
        
        m_config->Write(_T("Canfield_Games"), (long)total[j]);
        m_config->Write(_T("Canfield_Wins"), (long)ganados[j]);j++;
        
		m_config->Write(_T("Canfield Two Decks_Games"), (long)total[j]);
		m_config->Write(_T("Canfield Two Decks_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Canfield Superior_Games"), (long)total[j]);
		m_config->Write(_T("Canfield Superior_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Corona_Games"), (long)total[j]);
		m_config->Write(_T("Corona_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Doubles_Games"), (long)total[j]);
		m_config->Write(_T("Doubles_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Doubles 13_Games"), (long)total[j]);
		m_config->Write(_T("Doubles 13_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Easthaven_Games"), (long)total[j]);
		m_config->Write(_T("Easthaven_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Emperor_Games"), (long)total[j]);
		m_config->Write(_T("Emperor_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Forty Thieves_Games"), (long)total[j]);
		m_config->Write(_T("Forty Thieves_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Forty Thieves and Eight_Games"), (long)total[j]);
		m_config->Write(_T("Forty Thieves and Eight_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Forty Thieves Three Decks_Games"), (long)total[j]);
		m_config->Write(_T("Forty Thieves Three Decks_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Forty Thieves Four Decks_Games"), (long)total[j]);
		m_config->Write(_T("Forty Thieves Four Decks_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("FreeCell_Games"), (long)total[j]);
		m_config->Write(_T("FreeCell_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("FreeCell Two Decks_Games"), (long)total[j]);
		m_config->Write(_T("FreeCell Two Decks_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Golf_Games"), (long)total[j]);
		m_config->Write(_T("Golf_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Golf A-K_Games"), (long)total[j]);
		m_config->Write(_T("Golf A-K_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Golf A-K Two Decks_Games"), (long)total[j]);
		m_config->Write(_T("Golf A-K Two Decks_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Indian_Games"), (long)total[j]);
		m_config->Write(_T("Indian_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Klondike_Games"), (long)total[j]);
		m_config->Write(_T("Klondike_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Klondike Two Decks_Games"), (long)total[j]);
		m_config->Write(_T("Klondike Two Decks_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Lucky Fans_Games"), (long)total[j]);
		m_config->Write(_T("Lucky Fans_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Montana Three Redeals_Games"), (long)total[j]);
		m_config->Write(_T("Montana Three Redeals_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Ocean's Eleven_Games"), (long)total[j]);
		m_config->Write(_T("Ocean's Eleven_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Rail One Deck_Games"), (long)total[j]);
		m_config->Write(_T("Rail One Deck_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Rail Two Decks_Games"), (long)total[j]);
		m_config->Write(_T("Rail Two Decks_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Russian_Games"), (long)total[j]);
		m_config->Write(_T("Russian_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Russian Relaxed_Games"), (long)total[j]);
		m_config->Write(_T("Russian Relaxed_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Scarab_Games"), (long)total[j]);
		m_config->Write(_T("Scarab_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Scorpion_Games"), (long)total[j]);
		m_config->Write(_T("Scorpion_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Simple Simon_Games"), (long)total[j]);
		m_config->Write(_T("Simple Simon_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Spider_Games"), (long)total[j]);
		m_config->Write(_T("Spider_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Spider One Suite_Games"), (long)total[j]);
		m_config->Write(_T("Spider One Suite_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Spider Two Suites_Games"), (long)total[j]);
		m_config->Write(_T("Spider Two Suites_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Spider Three Decks_Games"), (long)total[j]);
		m_config->Write(_T("Spider Three Decks_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Spiderette_Games"), (long)total[j]);
		m_config->Write(_T("Spiderette_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Spiderette Relaxed_Games"), (long)total[j]);
		m_config->Write(_T("Spiderette Relaxed_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Towers_Games"), (long)total[j]);
		m_config->Write(_T("Towers_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Yukon_Games"), (long)total[j]);
		m_config->Write(_T("Yukon_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Yukon Relaxed_Games"), (long)total[j]);
		m_config->Write(_T("Yukon Relaxed_Wins"), (long)ganados[j]);j++;
		
		m_config->Write(_T("Z-Four_Games"), (long)total[j]);
		m_config->Write(_T("Z-Four_Wins"), (long)ganados[j]);
        
        int total_general=0;
        int total_ganados=0;
        for(j=0;j<40;j++){
        	total_general+=total[j];
        	total_ganados+=ganados[j];
        }
        m_config->Write(_T("Check"), CalcCheck(player, total_general, total_ganados));        
        
    }
}
