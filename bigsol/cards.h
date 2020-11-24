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
// cards.h: interface for the cards class.
//
//////////////////////////////////////////////////////////////////////

#ifndef CARDS_H_INCLUDED
#define CARDS_H_INCLUDED

class cards  
{
public:
	int				valor;		// El AS vale 1, K 13, Q 12 etc...
	int				tipo;		// 1=trebol, 2=rombo, 3=corazones, 4=picas
	bool			color;		// 0=negro, 1=rojo
	int	bitmap;		// Que ID de bitmap corresponde
	float			x;			// Posicion X de la carta
	float			y;			// Posicion Y de la carta
	float			z;			// Posicion Z de la carta
	bool			mostrada;	// Si esta boca arriba o boca abajo
	bool			seleccionada;	// Si esta o no seleccionada

	cards();
	virtual ~cards();
};

#endif
