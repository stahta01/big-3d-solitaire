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
// casillas.h: interface for the casillas class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_CASILLAS_H__4AAE92A2_C19D_11D7_97D8_AED3ECEFB34D__INCLUDED_)
#define _CASILLAS_H__4AAE92A2_C19D_11D7_97D8_AED3ECEFB34D__INCLUDED_

#include "cards.h"

class casillas  
{
public:
	int n[13];	// Para undos.Son las trece cartas colocadas en
							// la casilla; para ver cuales son en verdad
	cards c;				// La carta que esta colocada en la casilla
	// Las casillas finales de colocacion
	casillas();
	virtual ~casillas();

};

#endif // !defined(_CASILLAS_H__4AAE92A2_C19D_11D7_97D8_AED3ECEFB34D__INCLUDED_)
