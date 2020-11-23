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
#ifndef OPENGLCANVAS_H_
#define OPENGLCANVAS_H_

#ifdef __WXGTK__
    #define USE_WXGTK 1
#else
    #define USE_WXGTK 0
#endif

#include "wx/glcanvas.h"
#include "wx/sound.h"

#if wxUSE_GLCANVAS

class OpenGLCanvas: public wxGLCanvas {
    friend class MyFrame;
    //friend class game;
public:
    OpenGLCanvas( wxWindow *parent, wxWindowID id = wxID_ANY,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        long style = 0, const wxString& name = _T("OpenGLCanvas") );

    ~OpenGLCanvas();

    void OnPaint(wxPaintEvent& event);
    void OnSize(wxSizeEvent& event);
    void OnEraseBackground(wxEraseEvent& event);
    void OnKeyDown(wxKeyEvent& event);
    void OnKeyUp(wxKeyEvent& event);
    void OnEnterWindow(wxMouseEvent& event);
	void onMouseEvent(wxMouseEvent& e);
	void onMouseWheel(wxMouseEvent& e);
	void idle(wxIdleEvent& e);

	void InitGL();
	void restauraGL();
	void Swap();
	void recorrido();
	void recorrido_out();
	void recorrido_in();
	void mov_camara(float,float,float,float,float,float,float);
	void mov_camara_vacio(float,float,float,float,float,float,float);
    //void Rotate(GLfloat deg);
    bool proceso_de_carga(int a,GLint modo);
    void serp3D(int a);
    //void movimiento(float xfin,float yfin,float zfin,int n);
    //void movimiento_ini(float xfin,float yfin,float zfin,int n);
    //void renderiza_ini(void);
    int renderiza(GLint modo);
    int renderiza_vacio();
    int dame_cartaID(int x, int y);	// Busca carta pinchada
    //void Action( long code, unsigned long lasttime,unsigned long acceltime );
    // Sonido
    bool CreateSoundWin(wxSound& snd) const;
    wxSound*    	sonido_win;
private:
	wxString	swinFile;
    bool   		m_init;
    GLuint 		m_gllist;
    long   m_rleft;
    long   m_rright;
    long   m_up;
	long   m_down;
	long   m_home;
	long   m_end;
	long   m_insert;
	long   m_del;
	long   m_repag;
	long   m_avpag;
	long   m_escape;
    long   m_Key;
    long   m_F1;
    long   m_F2;
    long   m_F3;
    long   m_F5;
    long   m_F6;
    long   m_F7;
    long   m_F8;
    long   m_NUMPAD1;
    long   m_NUMPAD2;
    long   m_NUMPAD3;
    long   m_NUMPAD4;
    long   m_NUMPAD5;
    long   m_NUMPAD7;
    long   m_NUMPAD8;
    long   m_NUMPAD9;

DECLARE_EVENT_TABLE()
};

#endif
#endif /*OPENGLCANVAS_H_*/
