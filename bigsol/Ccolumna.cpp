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
// Ccolumna.cpp: implementation of the Ccolumna class.
//
//////////////////////////////////////////////////////////////////////

#include "Ccolumna.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Ccolumna::Ccolumna()
{

}

Ccolumna::~Ccolumna()
{

}

Ccolumna::Ccolumna(float X, float Y, float Z, int TIPO, bool SELEC, int NUM_CARTAS, float DESP_X, float DESP_Y, float DESP_Z,int textur,int sel)
{
x=X;y=Y;z=Z;tipo=TIPO;selec=SELEC;num_cartas=NUM_CARTAS;desp_x=DESP_X;desp_y=DESP_Y;desp_z=DESP_Z;
primer_valor=NULL;ultimo_valor=NULL;textura=textur;num_sel=sel;
}
