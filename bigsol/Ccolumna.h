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
// Ccolumna.h: interface for the columna class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_CCOLUMNA_H__)
#define _CCOLUMNA_H__

//#include <stdio.h>
#include "lista.h"
#define NULL	__null
class Ccolumna  
{
public:
	float		x;				// Posicion horizontal
	float		y;				// Posicion vertical
	float		z;				// Posicion en eje Z
	int			tipo;			// 0:MAZO 1:PILA 2:COLUMNA 3:FINAL 4:NO UTILIZABLE
	bool		selec;			// Si es seleccionable para pinint
	int			num_cartas;		// Numero de cartas que contiene. Puede haber mas de 127
	int			num_sel;		// Numero de cartas que se han seleccionado
	lista		*primer_valor;
	lista		*ultimo_valor;	// Lista doblemente enlazada con los valores que contiene
	float		desp_x;			// El desplazamiento en X que tiene la columna para cada carta
	float		desp_y;			// El desplazamiento en Y que tiene la columna para cada carta
	float		desp_z;			// El desplazamiento en Z que tiene la columna para cada carta
	int	textura;		// El dibujo que tienen cuando estan vacias
	Ccolumna(float X,float Y,float Z, int TIPO, bool SELEC, int NUM_CARTAS,
			 float DESP_X,float DESP_Y,float DESP_Z,int textur,int sel);
	Ccolumna();
	virtual ~Ccolumna();
};

#endif
