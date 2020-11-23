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
// simplesimon.cpp: implementation of the simplesimon class.
//
//////////////////////////////////////////////////////////////////////

#include "wx_defines.h"
#include <wx/defs.h>

#include <wx/sound.h>
#include <wx/string.h>

#include "simplesimon.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

simplesimon::simplesimon()
{
golum[0]->selec=false;
golum[16]->tipo=4;golum[17]->tipo=4;golum[18]->tipo=4;golum[19]->tipo=4;
num_golum=16;
ultima_columna=12;
mazo_juego=52;
tipo_juego=SIMPLESIMON;
}

simplesimon::~simplesimon()
{

}

void simplesimon::repetir_juego()
{
game::repetir_juego();
mazo_juego=52;juego_automatico=true;
for(int k=2;k<12;k++) golum[k]->desp_y=-0.03f;
}

void simplesimon::fase_presentacion()
{
mueve_colum_reparto(0,2,true);
mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,3,true);
mueve_colum_reparto(0,4,true);mueve_colum_reparto(0,4,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,5,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,5,true);
mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,6,true);
mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,6,true);
mueve_colum_reparto(0,7,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,7,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,7,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,8,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,8,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,8,true);
mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,9,true);
mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,9,true);
mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,9,true);
mueve_colum_reparto(0,10,true);mueve_colum_reparto(0,10,true);mueve_colum_reparto(0,10,true);
mueve_colum_reparto(0,10,true);mueve_colum_reparto(0,10,true);mueve_colum_reparto(0,10,true);
mueve_colum_reparto(0,10,true);mueve_colum_reparto(0,10,true);
mueve_colum_reparto(0,11,true);mueve_colum_reparto(0,11,true);mueve_colum_reparto(0,11,true);
mueve_colum_reparto(0,11,true);mueve_colum_reparto(0,11,true);mueve_colum_reparto(0,11,true);
mueve_colum_reparto(0,11,true);mueve_colum_reparto(0,11,true);
FASE_PRESENTACION=false;
}
