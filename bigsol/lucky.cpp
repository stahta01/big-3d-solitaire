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
// lucky.cpp: implementation of the lucky class.
//
//////////////////////////////////////////////////////////////////////

#include "wx_defines.h"
#include <wx/defs.h>

#include <wx/sound.h>
#include <wx/string.h>

#include "lucky.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

lucky::lucky()
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
golum[0]=new Ccolumna(-0.36f,0.45f,-1.2f,0,false,0,0.0000015f,0.0000015f,0.00015f,MAZO_NO,0);
// LA "COLUMNA" PILA (INEXISTENTE)
golum[1]=new Ccolumna(-0.24f,0.45f,-1.2f,4,false,0,0.0170f,0.f,0.00005f,MAZO_NO,0);
// LAS COLUMNAS (13)
golum[ 2]=new Ccolumna(-0.5f, 0.25f,-1.2f,2,true,0,0.025f,0.f,0.0001f,HUECO_K,0);
golum[ 3]=new Ccolumna( 0.0f, 0.25f,-1.2f,2,true,0,0.025f,0.f,0.0001f,HUECO_K,0);
golum[ 4]=new Ccolumna( 0.5f, 0.25f,-1.2f,2,true,0,0.025f,0.f,0.0001f,HUECO_K,0);
golum[ 5]=new Ccolumna(-0.25f,0.10f,-1.2f,2,true,0,0.025f,0.f,0.0001f,HUECO_K,0);
golum[ 6]=new Ccolumna( 0.25f,0.10f,-1.2f,2,true,0,0.025f,0.f,0.0001f,HUECO_K,0);
golum[ 7]=new Ccolumna(-0.5f,-0.05f,-1.2f,2,true,0,0.025f,0.f,0.0001f,HUECO_K,0);
golum[ 8]=new Ccolumna( 0.0f,-0.05f,-1.2f,2,true,0,0.025f,0.f,0.0001f,HUECO_K,0);
golum[ 9]=new Ccolumna( 0.5f,-0.05f,-1.2f,2,true,0,0.025f,0.f,0.0001f,HUECO_K,0);
golum[10]=new Ccolumna(-0.25f,-0.2f,-1.2f,2,true,0,0.025f,0.f,0.0001f,HUECO_K,0);
golum[11]=new Ccolumna( 0.25f,-0.2f,-1.2f,2,true,0,0.025f,0.f,0.0001f,HUECO_K,0);
golum[12]=new Ccolumna(-0.5f,-0.35f,-1.2f,2,true,0,0.025f,0.f,0.0001f,HUECO_K,0);
golum[13]=new Ccolumna( 0.0f,-0.35f,-1.2f,2,true,0,0.025f,0.f,0.0001f,HUECO_K,0);
golum[14]=new Ccolumna( 0.5f,-0.35f,-1.2f,2,true,0,0.025f,0.f,0.0001f,HUECO_K,0);
// LAS FINALES (4)
golum[15]=new Ccolumna(0.27f, 0.45f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
golum[16]=new Ccolumna(0.36f, 0.45f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
golum[17]=new Ccolumna(0.45f, 0.45f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
golum[18]=new Ccolumna(0.54f, 0.45f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
// LAS NO UTILIZABLES
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

num_golum=19;	// Siempre es una mas
mazo_juego=52;
ultima_columna=15;	// Una mas. Son las columnas seleccionables
juego_automatico=true;
tipo_juego=LUCKY;
mover_permitido=true;
automatico_permitido=true;
}

lucky::~lucky()
{

}

void lucky::fase_presentacion()
{
int i=0;
for(i=2;i<15;i++) mueve_colum_reparto(0,i,true);
for(i=2;i<15;i++) mueve_colum_reparto(0,i,true);
for(i=2;i<15;i++) mueve_colum_reparto(0,i,true);
for(i=2;i<15;i++) mueve_colum_reparto(0,i,true);
FASE_PRESENTACION=false;
}

//*****************************************************//
// Devuelve TRUE si la carta es seleccionable
// segun las reglas del juego
bool lucky::es_seleccionable(int cc,int c)
//****************************************************//
{
lista *alfa=NULL;
int b=0;
int karta_anterior=cc;
//int huecos_libres=0;
golum[c]->num_sel=0;
carta[cc]->seleccionada=true;

// Vamos al principio de la golum
alfa=golum[c]->primer_valor->sig;
// Vemos donde hemos pinchado
for(int k=0;k<golum[c]->num_cartas;k++)
	{
	if(alfa->carta!=cc) alfa=alfa->sig;
	else {b=k;break;}
	}
for(int k=b;k<golum[c]->num_cartas;k++)
	{	
	if(alfa->sig==NULL)	// Es la ultima carta siempre seleccionable
		{
		carta[alfa->carta]->seleccionada=true;
		golum[c]->num_sel++;
		return true;
		}
	else
		{
		alfa=alfa->sig;
		if (carta[alfa->carta]->color!=carta[karta_anterior]->color &&
		    carta[alfa->carta]->valor==carta[karta_anterior]->valor-1)
				{
				carta[alfa->carta]->seleccionada=true;
				golum[c]->num_sel++;
				karta_anterior=alfa->carta;
				}
		else
			{
			alfa=golum[c]->primer_valor->sig;
			for(int kk=0;kk<golum[c]->num_cartas;kk++)
				{
				carta[alfa->carta]->seleccionada=false;
				alfa=alfa->sig;
				}
			golum[c]->num_sel=0;
			return false;
			}
		}
	}
return true;	// Realmente aqui nunca llega
}
