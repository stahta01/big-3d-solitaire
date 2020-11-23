/*
Big Solitaries 3D
Copyright (C) 2006  Félix José Cladellas

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
// golf_ak2.cpp: implementation of the gol_ak2 class.
//
//////////////////////////////////////////////////////////////////////

#include "wx_defines.h"
#include <wx/defs.h>

#include <wx/sound.h>
#include <wx/string.h>

#include "golf_ak2.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

golf_ak2::golf_ak2()
{
tipo_juego=GOLF_AK2;
// LA "COLUMNA" PILA AHORA ES FINAL
// golum[1]=new Ccolumna(0.f,-0.3f,-1.2f,1,true,0,0.00025f,0.00025f,0.0002f,FINAL_G,0);
// LAS COLUMNAS
golum[ 0]->x=-0.12f;golum[ 1]->x=0.12f;golum[ 1]->y=0.4f;golum[ 1]->desp_z=0.00005f;
golum[ 1]->desp_x=0.0001f;golum[ 1]->desp_y=0.0001f;
golum[ 2]->x=-0.48f;
golum[ 3]->x=-0.36f;
golum[ 4]->x=-0.24f;
golum[ 5]->x=-0.12f;
golum[ 6]->x=0.f;
golum[ 7]->x=0.12f;
golum[ 8]->x=0.24f;
golum[ 9]->x=0.36f;golum[ 9]->y=0.2f;golum[ 9]->tipo=2;golum[ 9]->selec=true;
golum[ 9]->desp_x=0.f;golum[ 9]->desp_y=-0.05f;golum[ 9]->desp_z=0.0001f;
golum[ 9]->textura=MAZO_NO;
golum[10]->x=0.48f;golum[10]->y=0.2f;golum[10]->tipo=2;golum[10]->selec=true;
golum[10]->desp_x=0.f;golum[10]->desp_y=-0.05f;golum[10]->desp_z=0.0001f;
golum[10]->textura=MAZO_NO;
num_golum=11;
mazo_juego=104;
ultima_columna=11;
}

golf_ak2::~golf_ak2()
{

}


void golf_ak2::fase_presentacion()
{
// PRIMERA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,10,true);
// SEGUNDA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,10,true);
// TERCERA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,10,true);
// CUARTA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,10,true);
// QUINTA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,10,true);
// SEXTA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,10,true);
// SEPTIMA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,10,true);
// LA PRIMERA DE LA PILA
mueve_colum_reparto(0,1,true);cartas_colocadas=1;
FASE_PRESENTACION=false;
}

void golf_ak2::repetir_juego()
{
game::repetir_juego();
mazo_juego=104;juego_automatico=false;
}
