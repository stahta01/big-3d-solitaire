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
#ifndef _40_LADRONES_H_
#define _40_LADRONES_H_

#ifdef __WXGTK__
    #define USE_WXGTK 1
#else
    #define USE_WXGTK 0
#endif

#include <wx/frame.h>
//#include <wx/glcanvas.h>
#include "openglcanvas.h"

enum Posicionestoolbar {
    TOOLBAR_LEFT,
    TOOLBAR_TOP,
    TOOLBAR_RIGHT,
    TOOLBAR_BOTTOM
};

// Define a new application type
class BigSol: public wxApp {
public:
    bool OnInit();
protected:
    void InitExceptionHandler();
};

// Define a new frame type
class OpenGLCanvas;
class ScoreFile;
class PlayerSelectionDialog;
class ScoreDialog;
class MyFrame: public wxFrame {
public:
	OpenGLCanvas *m_canvas;
	ScoreFile* m_scoreFile;
	wxString jugador;
	PlayerSelectionDialog* m_playerDialog;
	ScoreDialog *m_estadisticas;
	wxStopWatch swJuego;
	wxStopWatch swGeneral;
	wxString TiposAlArrancar;
	wxString ColorPorDefecto;
	wxConfig *config;
	wxString *BestTime   [40];
	wxString *BestJugador[40];
	wxString *BestNumber [40];
    
    static MyFrame *Create(MyFrame *parentFrame, bool isCloneWindow = false);
    void OnExit(wxCommandEvent& event);
    void OnNewWindow(wxCommandEvent& event);
    // PARA LA TOOLBAR
    void RecreateToolbar();
    //void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnAboutHTML(wxCommandEvent& event);
    void ShowTip(wxCommandEvent& event);
    void ShowLicense(wxCommandEvent& event);
    void NumericEntry(wxCommandEvent& event);
    void FrameRateNumericEntry(wxCommandEvent& event);
    //void SelectGame(wxCommandEvent& event);
    void SelectBackgroundColor(wxCommandEvent& event);
    void CamaraStandard(wxCommandEvent& event);
    void CamaraMain(wxCommandEvent& event);
    void OnNewGame(wxCommandEvent& event);
    void Automaticos(wxCommandEvent& event);
    void OnRestartGame(wxCommandEvent& event);
	// MENU JUEGOS
    void OnCanfield(wxCommandEvent& event);
    void OnDoubles(wxCommandEvent& event);
    void OnFortyThieves(wxCommandEvent& event);
    void OnFreecell(wxCommandEvent& event);
    void OnGolf(wxCommandEvent& event);
    void OnKlondike(wxCommandEvent& event);
    void OnSpider(wxCommandEvent& event);
    void OnUndo(wxCommandEvent& event);
    void OnRedo(wxCommandEvent& event);
    void OnUndoAll(wxCommandEvent& event);
    void OnRedoAll(wxCommandEvent& event);
    void OnActivarSonido(wxCommandEvent& event);
    void MostrarJugadores();
    //void SelectJuego();
    void OnNewDeck(wxCommandEvent& event);
    void OnOldDeck(wxCommandEvent& event);
    void OnFunDeck(wxCommandEvent& event);
    void OnRetroDeck(wxCommandEvent& event);
    
    void OnImageBlue(wxCommandEvent& event);
    void OnImageGreen(wxCommandEvent& event);
    void OnImageYellow(wxCommandEvent& event);
    void OnImageClassic(wxCommandEvent& event);
    
    void OnImageOpen(wxCommandEvent& event);
    
    void EstableceJuego(bool);
    void MuestraArbolJuegos(wxCommandEvent& event);
    void MuestraJuegos();
    void MostrarTip();
    void Estadisticas(wxCommandEvent& event);
    void MejoresTiempos(wxCommandEvent& event);
    void OnHelpGameHTML(wxCommandEvent& event);
    void AyudaGameHTML();
    void Zoomin(wxCommandEvent& event);
    void Zoomout(wxCommandEvent& event);
    
    //void OnSize(wxSizeEvent& event);
    //event.Enable( m_tbar != NULL );
    //}
private:
    MyFrame(wxWindow *parent, const wxString& title, const wxPoint& pos,
            const wxSize& size, long style = wxDEFAULT_FRAME_STYLE | wxMAXIMIZE);
            	wxFont* m_font;
    //wxMINIMIZE_BOX | wxMAXIMIZE_BOX | wxRESIZE_BORDER | wxSYSTEM_MENU | wxCAPTION | wxCLOSE_BOX | wxCLIP_CHILDREN
	//wxDEFAULT_FRAME_STYLE
    // ***************
	// PARA LA TOOLBAR
	// ***************
    bool	m_smallToolbar;
    bool	m_horzText;
    bool	m_useCustomDisabled;
    bool	m_showTooltips;
    size_t  m_rows;             // 1 or 2 only
    // the number of print buttons we have (they're added/removed dynamically)
    //size_t              m_nPrint;
    // store toolbar position for future use
    Posicionestoolbar   m_toolbarPosition;
    wxTextCtrl         *m_textWindow;
    wxToolBar          *m_tbar;
    // the path to the custom bitmap for the test toolbar tool
    wxString            m_pathBmp;
    DECLARE_EVENT_TABLE()
};

#endif // #ifndef _40_LADRONES_H_

