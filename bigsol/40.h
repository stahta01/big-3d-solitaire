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
#ifndef _40_H__
#define _40_H__

//#include <windows.h>		// Archivo de cabecera para Windows
#include <stdio.h>			// Include para manejar ficheros
//#include <gl\glew.h>
//#include <GL/glut.h>    // Header File For The GLUT Library 
//#include <GL/gl.h>	// Header File For The OpenGL32 Library
//#include <GL/glu.h>	// Header File For The GLu32 Library
//#include <gl\gl.h>			// Archivo de cabecera para la libreria OpenGL32
//#include <gl\glu.h>			// Archivo de cabecera para la libreria GLu32
//#include <gl\glaux.h>		// Archivo de cabecera para la libreria Glaux
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#include <stdarg.h>
#include <math.h> 
#include <time.h>
//#include <new.h>
//#include <commctrl.h>


// Activar esta linea para chequear memory leaks
// #include "mmgr.h"

#include "text_tex.h"
#include "resource.h"
//#include "camara.h"

//#define WM_MOUSEWHEEL	0x020A
#define NADA		 0
#define MAZO		 1	// Para pinint en el mazo
#define PILA		 2	// Para pinint en la pila
#define NOCARTA	   208
#define NOCOL	    -1

// Para texturas
#define FINAL		53	// La textura para FINALES en A
#define	HUECO		54	// La textura para HUECOS genericos
#define FUENTE		55	// La textura para la fuente
#define	HUECO_K		56	// La textura para HUECOS en K
#define FINAL_AK	57	// La textura para FINALES EN A-K
#define FINAL_G		58	// La textura para FINALES genericas
//#define APOYO		59	// La textura para casillas de APOYO
#define BACK		60	// El ejemplo de cada juego
#define T_ATRAS		61	// Atras
#define T_ADELANTE	62	// Avanti
#define	HUECO_2		63	// La textura para HUECOS en 2
#define	FINAL_2		64	// La textura para HUECOS en 2
#define	FINAL_3		65	// La textura para HUECOS en 2
#define	FINAL_4		66	// La textura para HUECOS en 2
#define	FINAL_5		67	// La textura para HUECOS en 2
#define	FINAL_6		68	// La textura para HUECOS en 2
#define	FINAL_7		69	// La textura para HUECOS en 2
#define	FINAL_8		70	// La textura para HUECOS en 2
#define	FINAL_9		71	// La textura para HUECOS en 2
#define	FINAL_10	72	// La textura para HUECOS en 2
#define	FINAL_J		73	// La textura para HUECOS en 2
#define	FINAL_Q		74	// La textura para HUECOS en 2
#define	FINAL_K		75	// La textura para HUECOS en 2
#define PANEL		76	// La textura para los botones
#define LOGO		77	// La textura para el logo
#define MAZO_SI		78	// La textura para el MAZO RECICLABLE
#define MAZO_NO		79	// La textura para el MAZO NO RECICLABLE
#define MENU		80	// La textura para el MENU
#define MAZO_SI2	81	// La textura para el TEXTO GIRATORIO
#define FONDO		82	// La imagen de fondo, si finalmente se pone
#define APOYO		83	// La textura para casillas de APOYO

// Para pinint en MENUS
#define MENU_JUEGOS	6000	// Para el menu principal
#define MENU_JUEGO	6001	// Para el menu principal
#define NEW			6002
#define QUIT		6003
#define RESTART		6004
#define SELECT		6005
#define CONTINUE	6006
#define AUTO		6007
#define YES			6008
#define NOT			6009
#define STADIS		6010
#define RESET		6011
#define ATRAS		6012
#define ADELANTE	6013

#define CANFIELD	7000
#define CANFIELD2	7001
#define CANFIELD_SUP 7002
#define CORONA		7003
#define DOUBLES		7004
#define DOUBLES13	7005
#define EASTHAVEN	7006
#define EMPEROR		7007
#define G2			7008	// Forty Thieves
#define G40Y8		7009	// Forty and Eight
#define G3			7010	// Forty Thieves Three Decks
#define G4			7011	// Forty Thieves Four Decks
#define FREECELL	7012
#define FREECELL2	7013
#define GOLF		7014
#define GOLF_AK		7015
#define GOLF_AK2	7016
#define INDIAN		7017
#define KLONDIKE	7018
#define KLONDIKE2	7019
#define LUCKY		7020
#define MONTANA		7021
#define OCEANS		7022
#define RAIL1		7023
#define RAIL2		7024
#define RUSSIAN		7025
#define RUSSIAN_NK	7026
#define SCARAB		7027
#define SCORPION	7028
#define SIMPLESIMON	7029
#define SPIDER		7030
#define SPIDER1		7031
#define SPIDER2		7032
#define SPIDER3		7033
#define SPIDERETTE	7034
#define SPIDERETTER	7035
#define TOWERS		7036
#define YUKON		7037
#define YUKON_NK	7038
#define IX			7039

#define KLONDIKE3	7040

#define START		8000
#define ANTERIOR	8001
#define SIGUIENTE	8002

#define MOUSE_IN_BOX	1
#define SPEED	0.005f

#endif
