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
// corona.h: interface for the corona class.
//
//////////////////////////////////////////////////////////////////////

#ifndef CORONA_H_INCLUDED
#define CORONA_H_INCLUDED

#include "game.h"

class corona : public game
{
public:
	corona();
	virtual ~corona();
	bool	automatico();
	void	fase_presentacion(void);
	void	repetir_juego(void);
	bool	mover(int,int);	// Mueve carta/s de ua golum a otra
	void	busca_sitio_boton_derecho();
	int		que_carta_es(int cc);
	void	mover_a_columna(int cc);
};

#endif
