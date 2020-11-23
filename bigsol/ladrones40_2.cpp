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

#include "wx_defines.h"
#include <wx/defs.h>

#include <wx/sound.h>
#include <wx/string.h>

#include "ladrones40_2.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ladrones40_2::ladrones40_2()
{
//game(); // No es neseario
// ESTAMOS PARA 40 LADRONES 2 MAZOS
// SOLO SE HAN CAMBIADO LAS DIFERENCIAS FUNDAMENTALES ENTRE LAS COLUM
// LA COLUMNA MAZO   es la misma que la de la clase base
// LA "COLUMNA" PILA es la misma que la de la clase base
// LAS COLUMNAS
golum[ 0]->desp_z=0.00015f;
golum[ 2]->x=-0.54f;
golum[ 3]->x=-0.42f;
golum[ 4]->x=-0.30f;
golum[ 5]->x=-0.18f;
golum[ 6]->x=-0.06f;
golum[ 7]->x= 0.06f;
golum[ 8]->x= 0.18f;
golum[ 9]->x= 0.30f;
golum[10]->x= 0.42f;
golum[11]->x= 0.54f;
// LAS CASILLA FINALES
golum[12]->x=-0.315f;
golum[12]->y=-0.39f;
golum[12]->z=-1.2f;
golum[12]->tipo=3;
golum[12]->selec=false;
golum[12]->textura=FINAL;
golum[12]->desp_z=0.0008f;
golum[12]->desp_x=0.0008f;
golum[12]->desp_y=0.00025f;

golum[13]->x=-0.225f;
golum[13]->y=-0.39f;
golum[13]->z=-1.2f;
golum[13]->tipo=3;
golum[13]->selec=false;
golum[13]->textura=FINAL;
golum[13]->desp_z=0.0008f;
golum[13]->desp_x=0.0008f;
golum[13]->desp_y=0.00025f;
golum[14]->x=-0.135f;
golum[15]->x=-0.045f;
golum[16]->x= 0.045f;
golum[17]->x= 0.135f;
golum[18]->x= 0.225f;
golum[19]->x= 0.315f;
// LAS NO UTILIZABLES
golum[20]->x= 0.f;golum[20]->y=0.f;golum[20]->z=-1.f;golum[20]->tipo=4;
golum[21]->x= 0.f;golum[21]->y=0.f;golum[21]->z=-1.f;golum[21]->tipo=4;
golum[22]->x= 0.f;golum[22]->y=0.f;golum[22]->z=-1.f;golum[22]->tipo=4;
golum[23]->x= 0.f;golum[23]->y=0.f;golum[23]->z=-1.f;golum[23]->tipo=4;
golum[24]->x= 0.f;golum[24]->y=0.f;golum[24]->z=-1.f;golum[24]->tipo=4;
golum[25]->x= 0.f;golum[25]->y=0.f;golum[25]->z=-1.f;golum[25]->tipo=4;
num_golum=20;
mazo_juego=104;
ultima_columna=12;
tipo_juego=G2;
}

ladrones40_2::~ladrones40_2()
{

}

void ladrones40_2::fase_presentacion()
{
// PRIMERA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,10,true);
mueve_colum_reparto(0,11,true);
// SEGUNDA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,10,true);
mueve_colum_reparto(0,11,true);
// TERCERA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,10,true);
mueve_colum_reparto(0,11,true);
// CUARTA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,10,true);
mueve_colum_reparto(0,11,true);
FASE_PRESENTACION=false;
}

//***************************************//
// Repite el ultimo juego
void ladrones40_2::repetir_juego()
//***************************************//
{
game::repetir_juego();
mazo_juego=104;
}

