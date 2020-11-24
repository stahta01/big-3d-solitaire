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
// freecell2.h: interface for the freecell2 class.
//
//////////////////////////////////////////////////////////////////////

#ifndef FREECELL2_H_INCLUDED
#define FREECELL2_H_INCLUDED

#include "klondike.h"

class freecell2 : public klondike  
{
public:
	virtual void fase_presentacion();
	virtual void repetir_juego();
	virtual bool es_seleccionable(int cc,int c);
	virtual bool mover(int ini, int fin);
	void busca_sitio_boton_derecho();
	freecell2();
	virtual ~freecell2();

};

#endif
