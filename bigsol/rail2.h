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
// rail2.h: interface for the rail2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_RAIL2_H__)
#define _RAIL2_H__

#include "klondike.h"

class rail2 : public klondike  
{
public:
	rail2();
	virtual ~rail2();
	bool mover(int ini, int fin);
	void fase_presentacion(void);
	void repetir_juego(void);
};

#endif

