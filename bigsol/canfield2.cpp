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
// canfield2.cpp: implementation of the canfield2 class.
//
//////////////////////////////////////////////////////////////////////

#include "wx_defines.h"
#include <wx/defs.h>

#include <wx/sound.h>

#include "canfield2.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

canfield2::canfield2()
{
// Vaciar las golums de cartas y eliminarlas
for(int i=0;i<37 ;i++)	{	
	if(golum[i]->ultimo_valor!=NULL) {
		while(golum[i]->ultimo_valor->ant!=NULL) {
			golum[i]->ultimo_valor=golum[i]->ultimo_valor->ant;
			delete(golum[i]->ultimo_valor->sig); // Liberamos puntero
			golum[i]->ultimo_valor->sig=NULL;
			}
		}
	if(golum[i]!=NULL) delete golum[i];
	}
// Recrear las golums
// LA COLUMNA MAZO
golum[ 0]=new Ccolumna(-0.45f,0.4f,-1.2f,0,true,0,0.0000015f,0.0000015f,0.00012f,MAZO_SI,0);
// LA "COLUMNA" PILA
golum[ 1]=new Ccolumna(-0.3f,0.4f,-1.2f,1,true,0,0.0000015f,0.0000015f,0.00012f,MAZO_NO,0);
// LA COLUMNA RESERVA (Tiene 13 cartas)
golum[ 2]=new Ccolumna(-0.30f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,MAZO_NO,0);
// LAS COLUMNAS (5)
golum[ 3]=new Ccolumna(-0.12f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 4]=new Ccolumna( 0.f,  0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 5]=new Ccolumna( 0.12f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 6]=new Ccolumna( 0.24f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 7]=new Ccolumna( 0.36f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
// LAS FINALES (8)
golum[ 8]=new Ccolumna(-0.09f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_G,0);
golum[ 9]=new Ccolumna( 0.f  , 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_G,0);
golum[10]=new Ccolumna( 0.09f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_G,0);
golum[11]=new Ccolumna( 0.18f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_G,0);
golum[12]=new Ccolumna( 0.27f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_G,0);
golum[13]=new Ccolumna( 0.36f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_G,0);
golum[14]=new Ccolumna( 0.45f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_G,0);
golum[15]=new Ccolumna( 0.54f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_G,0);
// LAS NO UTILIZABLES
golum[16]=new Ccolumna( 0.24f,0.0f,-1.2f,4,false,0,0.f,0.f,0.0f,HUECO,0);
golum[17]=new Ccolumna(-0.24f,-0.17f,-1.2f,4,false,0,0.f,0.f,0.0f,HUECO,0);
golum[18]=new Ccolumna(-0.12f,-0.17f,-1.2f,4,false,0,0.f,0.f,0.0f,HUECO,0);
golum[19]=new Ccolumna( 0.00f,-0.17f,-1.2f,4,false,0,0.f,0.f,0.0f,HUECO,0);
golum[20]=new Ccolumna( 0.12f,-0.17f,-1.2f,4,false,0,0.f,0.f,0.0f,HUECO,0);
golum[21]=new Ccolumna( 0.24f,-0.17f,-1.2f,4,false,0,0.f,0.f,0.0f,HUECO,0);
golum[22]=new Ccolumna(-0.24f,-0.34f,-1.2f,4,false,0,0.f,0.f,0.0f,HUECO,0);
golum[23]=new Ccolumna(-0.12f,-0.34f,-1.2f,4,false,0,0.f,0.f,0.0f,HUECO,0);
golum[24]=new Ccolumna( 0.00f,-0.34f,-1.2f,4,false,0,0.f,0.f,0.0f,HUECO,0);
golum[25]=new Ccolumna( 0.12f,-0.34f,-1.2f,4,false,0,0.f,0.f,0.0f,HUECO,0);
golum[26]=new Ccolumna( 0.24f,-0.34f,-1.2f,4,false,0,0.f,0.f,0.0f,HUECO,0);
golum[27]=new Ccolumna( 0.605f,-0.55f,-1.2f,4,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[28]=new Ccolumna( 0.605f,-0.55f,-1.2f,4,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[29]=new Ccolumna( 0.605f,-0.55f,-1.2f,4,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[30]=new Ccolumna( 0.605f,-0.55f,-1.2f,4,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[31]=new Ccolumna( 0.605f,-0.55f,-1.2f,4,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[32]=new Ccolumna( 0.605f,-0.55f,-1.2f,4,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[33]=new Ccolumna( 0.605f,-0.55f,-1.2f,4,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[34]=new Ccolumna( 0.605f,-0.55f,-1.2f,4,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[35]=new Ccolumna( 0.605f,-0.55f,-1.2f,4,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[36]=new Ccolumna( 0.605f,-0.55f,-1.2f,4,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);

num_golum=16;	// Siempre es una mas
mazo_juego=104;
ultima_columna=8;	// Una mas. Son las columnas seleccionables
juego_automatico=false;
tipo_juego=CANFIELD2;
mover_permitido=true;
automatico_permitido=true;
valor_base=0;
}

canfield2::~canfield2()
{

}

void canfield2::repetir_juego()
{
game::repetir_juego();
mazo_juego=104;juego_automatico=false;
golum[8]->textura=FINAL_G;golum[9]->textura=FINAL_G;
golum[10]->textura=FINAL_G;golum[11]->textura=FINAL_G;
golum[12]->textura=FINAL_G;golum[13]->textura=FINAL_G;
golum[14]->textura=FINAL_G;golum[15]->textura=FINAL_G;
valor_base=0;
}

void canfield2::fase_presentacion()
{
mueve_colum_reparto(0,8,true);valor_base=carta[golum[8]->ultimo_valor->carta]->valor;
cartas_colocadas++;
switch(valor_base)
	{
	case 1:
	golum[8]->textura=FINAL;golum[9]->textura=FINAL;
	golum[10]->textura=FINAL;golum[11]->textura=FINAL;
	golum[12]->textura=FINAL;golum[13]->textura=FINAL;
	golum[14]->textura=FINAL;golum[15]->textura=FINAL;
	break;
	case 2:
	golum[8]->textura=FINAL_2;golum[9]->textura=FINAL_2;
	golum[10]->textura=FINAL_2;golum[11]->textura=FINAL_2;
	golum[12]->textura=FINAL_2;golum[13]->textura=FINAL_2;
	golum[14]->textura=FINAL_2;golum[15]->textura=FINAL_2;
	break;
	case 3:
	golum[8]->textura=FINAL_3;golum[9]->textura=FINAL_3;
	golum[10]->textura=FINAL_3;golum[11]->textura=FINAL_3;
	golum[12]->textura=FINAL_3;golum[13]->textura=FINAL_3;
	golum[14]->textura=FINAL_3;golum[15]->textura=FINAL_3;
	break;
	case 4:
	golum[8]->textura=FINAL_4;golum[9]->textura=FINAL_4;
	golum[10]->textura=FINAL_4;golum[11]->textura=FINAL_4;
	golum[12]->textura=FINAL_4;golum[13]->textura=FINAL_4;
	golum[14]->textura=FINAL_4;golum[15]->textura=FINAL_4;
	break;
	case 5:
	golum[8]->textura=FINAL_5;golum[9]->textura=FINAL_5;
	golum[10]->textura=FINAL_5;golum[11]->textura=FINAL_5;
	golum[12]->textura=FINAL_5;golum[13]->textura=FINAL_5;
	golum[14]->textura=FINAL_5;golum[15]->textura=FINAL_5;
	break;
	case 6:
	golum[8]->textura=FINAL_6;golum[9]->textura=FINAL_6;
	golum[10]->textura=FINAL_6;golum[11]->textura=FINAL_6;
	golum[12]->textura=FINAL_6;golum[13]->textura=FINAL_6;
	golum[14]->textura=FINAL_6;golum[15]->textura=FINAL_6;
	break;
	case 7:
	golum[8]->textura=FINAL_7;golum[9]->textura=FINAL_7;
	golum[10]->textura=FINAL_7;golum[11]->textura=FINAL_7;
	golum[12]->textura=FINAL_7;golum[13]->textura=FINAL_7;
	golum[14]->textura=FINAL_7;golum[15]->textura=FINAL_7;
	break;
	case 8:
	golum[8]->textura=FINAL_8;golum[9]->textura=FINAL_8;
	golum[10]->textura=FINAL_8;golum[11]->textura=FINAL_8;
	golum[12]->textura=FINAL_8;golum[13]->textura=FINAL_8;
	golum[14]->textura=FINAL_8;golum[15]->textura=FINAL_8;
	break;
	case 9:
	golum[8]->textura=FINAL_9;golum[9]->textura=FINAL_9;
	golum[10]->textura=FINAL_9;golum[11]->textura=FINAL_9;
	golum[12]->textura=FINAL_9;golum[13]->textura=FINAL_9;
	golum[14]->textura=FINAL_9;golum[15]->textura=FINAL_9;
	break;
	case 10:
	golum[8]->textura=FINAL_10;golum[9]->textura=FINAL_10;
	golum[10]->textura=FINAL_10;golum[11]->textura=FINAL_10;
	golum[12]->textura=FINAL_10;golum[13]->textura=FINAL_10;
	golum[14]->textura=FINAL_10;golum[15]->textura=FINAL_10;
	break;
	case 11:
	golum[8]->textura=FINAL_J;golum[9]->textura=FINAL_J;
	golum[10]->textura=FINAL_J;golum[11]->textura=FINAL_J;
	golum[12]->textura=FINAL_J;golum[13]->textura=FINAL_J;
	golum[14]->textura=FINAL_J;golum[15]->textura=FINAL_J;
	break;
	case 12:
	golum[8]->textura=FINAL_Q;golum[9]->textura=FINAL_Q;
	golum[10]->textura=FINAL_Q;golum[11]->textura=FINAL_Q;
	golum[12]->textura=FINAL_Q;golum[13]->textura=FINAL_Q;
	golum[14]->textura=FINAL_Q;golum[15]->textura=FINAL_Q;
	break;
	case 13:
	golum[8]->textura=FINAL_K;golum[9]->textura=FINAL_K;
	golum[10]->textura=FINAL_K;golum[11]->textura=FINAL_K;
	golum[12]->textura=FINAL_K;golum[13]->textura=FINAL_K;
	golum[14]->textura=FINAL_K;golum[15]->textura=FINAL_K;
	break;
	}
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);
mueve_colum_reparto(0,2,true);

mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);
mueve_colum_reparto(0,7,true);
FASE_PRESENTACION=false;
}
