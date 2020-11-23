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
// spider3.cpp: implementation of the spider3 class.
//
//////////////////////////////////////////////////////////////////////

#include "spider3.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

spider3::spider3()
{
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
// LA COLUMNA MAZO la columna[0],fila[0]
golum[0]=new Ccolumna(-0.605f,0.4f,-1.2f,0,true,156,0.0000012f,0.0000012f,0.00008f,MAZO_NO,0);
// LA "COLUMNA" PILA
golum[1]=new Ccolumna(-0.495f,0.4f,-1.2f,4,false,0,0.0170f,0.f,0.00005f,MAZO_NO,0);
// LAS COLUMNAS (12)
golum[ 2]=new Ccolumna(-0.605f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 3]=new Ccolumna(-0.495f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 4]=new Ccolumna(-0.385f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 5]=new Ccolumna(-0.275f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 6]=new Ccolumna(-0.165f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 7]=new Ccolumna(-0.055f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 8]=new Ccolumna( 0.055f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 9]=new Ccolumna( 0.165f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[10]=new Ccolumna( 0.275f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[11]=new Ccolumna( 0.385f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[12]=new Ccolumna( 0.495f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[13]=new Ccolumna( 0.605f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
// LAS CASILLA FINALES (12)
golum[14]=new Ccolumna(-0.38f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
golum[15]=new Ccolumna(-0.29f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
golum[16]=new Ccolumna(-0.20f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
golum[17]=new Ccolumna(-0.11f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
golum[18]=new Ccolumna(-0.02f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
golum[19]=new Ccolumna( 0.07f  ,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
golum[20]=new Ccolumna( 0.16f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
golum[21]=new Ccolumna( 0.25f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
golum[22]=new Ccolumna( 0.34f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
golum[23]=new Ccolumna( 0.43f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
golum[24]=new Ccolumna( 0.52f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
golum[25]=new Ccolumna( 0.61f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
// LAS NO UTILIZABLES
golum[26]=new Ccolumna( 0.315f,-0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
golum[27]=new Ccolumna( 0.315f,-0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
golum[28]=new Ccolumna( 0.315f,-0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
golum[29]=new Ccolumna( 0.385f,-0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
golum[30]=new Ccolumna( 0.455f,-0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
golum[31]=new Ccolumna( 0.525f,-0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
golum[32]=new Ccolumna( 0.605f,-0.55f,-1.2f,4,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[33]=new Ccolumna( 0.605f,-0.55f,-1.2f,4,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[34]=new Ccolumna( 0.605f,-0.55f,-1.2f,4,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[35]=new Ccolumna( 0.605f,-0.55f,-1.2f,4,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[36]=new Ccolumna( 0.605f,-0.55f,-1.2f,4,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);

num_golum=26;
mazo_juego=156;
ultima_columna=14;
tipo_juego=SPIDER3;
}

spider3::~spider3()
{

}

void spider3::repetir_juego()
{
game::repetir_juego();
mazo_juego=156;juego_automatico=true;
for(int k=2;k<ultima_columna;k++) golum[k]->desp_y=-0.03f;
}

void spider3::fase_presentacion()
{
mueve_colum_reparto(0,2,false);mueve_colum_reparto(0,2,false);
mueve_colum_reparto(0,2,false);mueve_colum_reparto(0,2,false);
mueve_colum_reparto(0,2,true);
mueve_colum_reparto(0,3,false);mueve_colum_reparto(0,3,false);
mueve_colum_reparto(0,3,false);mueve_colum_reparto(0,3,false);
mueve_colum_reparto(0,3,true);
mueve_colum_reparto(0,4,false);mueve_colum_reparto(0,4,false);
mueve_colum_reparto(0,4,false);mueve_colum_reparto(0,4,false);
mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,false);mueve_colum_reparto(0,5,false);
mueve_colum_reparto(0,5,false);mueve_colum_reparto(0,5,false);
mueve_colum_reparto(0,5,true);
mueve_colum_reparto(0,6,false);mueve_colum_reparto(0,6,false);
mueve_colum_reparto(0,6,false);mueve_colum_reparto(0,6,false);
mueve_colum_reparto(0,6,true);
mueve_colum_reparto(0,7,false);mueve_colum_reparto(0,7,false);
mueve_colum_reparto(0,7,false);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,false);mueve_colum_reparto(0,8,false);
mueve_colum_reparto(0,8,false);mueve_colum_reparto(0,8,true);
mueve_colum_reparto(0,9,false);mueve_colum_reparto(0,9,false);
mueve_colum_reparto(0,9,false);mueve_colum_reparto(0,9,true);
mueve_colum_reparto(0,10,false);mueve_colum_reparto(0,10,false);
mueve_colum_reparto(0,10,false);mueve_colum_reparto(0,10,true);
mueve_colum_reparto(0,11,false);mueve_colum_reparto(0,11,false);
mueve_colum_reparto(0,11,false);mueve_colum_reparto(0,11,true);
mueve_colum_reparto(0,12,false);mueve_colum_reparto(0,12,false);
mueve_colum_reparto(0,12,false);mueve_colum_reparto(0,12,true);
mueve_colum_reparto(0,13,false);mueve_colum_reparto(0,13,false);
mueve_colum_reparto(0,13,false);mueve_colum_reparto(0,13,true);

FASE_PRESENTACION=false;
}
