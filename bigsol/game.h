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
// game.h: interface for the game class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_GAME_H__)
#define _GAME_H__

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

#include "wx/sound.h"
#include "Crender.h"
#include "Ccolumna.h"
#include "cards.h"
#include "undos.h"

extern Crender	crender;
extern void		movimiento_ini(float,float,float,int);
extern void		renderiza_ini(void);
extern void		movimiento(float,float,float,int);
extern bool		mov_pendiente;
extern bool		JUEGO_FINALIZADO;
extern bool		doble_click;
extern bool		retroceso;
extern bool		mov_pendiente;
extern bool		activar_sonido;
extern int		cuantas_serp;

class game{
public:
	// Sonidos
	wxSound*    	sonido_colocar;
    wxString    	colocarFile;
	Ccolumna		*golum[37];			// Las columnas que tiene el juego
	int				num_golum;			// Las "colum" que tiene el juego
	bool			cambio_de_juego;	// True si va a haber cambio de juego
	int				mazo_juego;			// El numero de cartas que tiene el mazo inicial
	int				cartas_colocadas;	// Las cartas colocadas
	int				num_mov;			// Numero de movimientos realizados
	cards			*carta[209];		// Las cartas (4 barajas)
	int				orden[209];			// El orden de salida tras barajar. PONGO UNO MAS PARA AHORRARME UN PEQUE�O CODIGO
	bool			FASE_PRESENTACION;	// Es true si estamos en la presentacion inicial
	int				numero_cartas;		// Para animar el reparto de cartas
	bool			juego_automatico;	// Es true si esta activado
	bool			esperar;			// Variable auxiliar para deshacer que de momento esta aqui
	int				carta_seleccionada; // Es la carta seleccionada
	int				carta_iluminada;	// Es la carta como que cabe en la columna
	bool			hemos_acabado;		// Juego terminado?
	int				numero_juego;		// El numero que se juega
	int 			columna_inicio;		// La columna inicial del movimiento de la carta
	int 			columna_final;		// La columna final   del movimiento de la carta
	bool			afin;				// Si se mueve a casilla final es true
	int 			pases;				// En algunos juegos, cuantas veces se puede pinint en un MAZO reciclable
	int 			ultima_columna;		// Que ultima columna es?? Para los fors. MUY importante!!
	int				tipo_juego;			// Realmente el nombre del juego (en define)
	bool			undo;				// Para controlar la velocidad con deshacer
	bool			redo;				// Para controlar la velocidad con rehacer
	bool			descubierta;		// Si se ha descubierto o no una carta para el undo/redo
	bool			mover_permitido;	// Si esta permitido o no mover la carta de su lugar
	bool			automatico_permitido;// Si esta permitido o no activar/desactivar el automatico
	// Para mover la/s carta/s con el cursor
	// (desplazamiento del cursor con respecto al centro de la carta)
	double			x_ori;
	double			y_ori;
	double			z_ori;

	// Para deshacer/rehacer
	undos *primer_mov;	// Primer movimiento de la lista
	undos *ultimo_mov;	// Ultimo movimiento de la lista
	undos *actual_mov;	// Donde estoy posicionado dentro de la lista

	// Camara.  Posiciones distintas para cada juego
	float posX;
	float posY;
	float posZ;
	float viewX;
	float viewY;
	float viewZ;
	float posX0;
	float posY0;
	float posZ0;
	float viewX0;
	float viewY0;
	float viewZ0;
	float vectorX;
	float vectorY;
	float vectorZ;

	// Funciones	
	game();
	void		 barajar(int a);
	bool		 repartir(void);				// Reparto inicial de cartas. Todas al mazo
	virtual void fase_presentacion(void);
	virtual void repetir_juego(void);
	virtual void inicio_especial(void);			// A efectos de probar el juego. Ordenacion mas adecuada
	virtual void mueve_colum_reparto(int ini,int fin,bool mostrada);// Valido para la animacion inicial
	virtual void mueve_golum(int ini,int fin);// Mueve UNA carta de una columna a otra con reglas
	virtual void mueve_multigolum(int ini, int fin);// Mueve VARIAS cartas de una columna a otra con reglas
	virtual	void ondobleclick(int);				// Procesa dobleclick izquierdo del raton
	virtual	int  que_carta_es(int cc);
	virtual void mover_a_columna(int cc);		// Mueve a una columna determinada,si se puede, una carta/s previamente seleccionadas
	virtual bool es_seleccionable(int,int);	// Para cada juego sera o no seleccionable
	virtual	bool colocar_carta(int n,int ini);	// La carta y la columna de inicio. Colocacion a casillas finales
	virtual bool mover(int,int);	// Mueve carta/s de ua golum a otra
	virtual	bool automatico(void);	// Coloca automaticamente en casillas finales
	virtual	void recolocar(void);	// Recoloca las cartas para que quepan en la golum
	virtual	void busca_sitio(void);	// Busca automaticamente un sitio para la carta que tenemos agarrada
	virtual void busca_sitio_boton_derecho(void);
	virtual bool rehacer(void);
	virtual bool deshacer(void);
	// Sonido
    bool CreateSoundColocar(wxSound& snd) const;
	//virtual void ilumina_sitio(void);
	virtual ~game();
};

#endif
