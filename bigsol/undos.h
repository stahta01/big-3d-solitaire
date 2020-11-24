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
// undos.h: interface for the undos class.
//
//////////////////////////////////////////////////////////////////////

#ifndef UNDOS_H_INCLUDED
#define UNDOS_H_INCLUDED

class undos  
{
public:
	int ini;		// Columna de donde se inicia el movimiento
	int fin;		// Columna a  donde finaliza  el movimiento
	int cuantas;	// Cuantos movimientos hay que considerar en esta ultima "jugada"
	int selec;		// Cuantas cartas seleccionadas se han movido en esta jugada
	bool oculta;	// Si con el movimiento ha habido o no descubrimiento de carta
	undos *sig_mov;	// Puntero al movimiento siguiente 
	undos *ant_mov;	// Puntero al movimiento anterior
	undos();		// Constructor por defecto
	undos(int i,int f,int cuant,int sel,undos *a,undos *s,bool ocu); // Otro constructor
	virtual ~undos();

};

#endif
