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
// golf_ak.h: interface for the golf_ak class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_GOLF_AK_H__)
#define _GOLF_AK_H__

#include "golf.h"

class golf_ak : public golf  
{
public:
	bool colocar_carta(int n,int ini);
	golf_ak();
	virtual ~golf_ak();

};

#endif
