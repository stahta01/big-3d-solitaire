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
// towers.cpp: implementation of the towers class.
//
//////////////////////////////////////////////////////////////////////

#include "wx_defines.h"
#include <wx/defs.h>

#include <wx/sound.h>
#include <wx/string.h>

#include "towers.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

towers::towers()
{
//game();
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
golum[0]=new Ccolumna(-0.42f,0.4f,-1.2f,0,false,0,0.0000015f,0.0000015f,0.00015f,MAZO_NO,0);
// LA "COLUMNA" PILA
golum[1]=new Ccolumna(-0.30f,0.4f,-1.2f,4,false,0,0.0170f,0.f,0.f,MAZO_NO,0);
// LAS DE APOYO (4)
golum[ 2]=new Ccolumna(-0.30f,0.4f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,APOYO,0);
golum[ 3]=new Ccolumna(-0.18f,0.4f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,APOYO,0);
golum[ 4]=new Ccolumna(-0.06f,0.4f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,APOYO,0);
golum[ 5]=new Ccolumna( 0.06f,0.4f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,APOYO,0);
// LAS COLUMNAS (10)
golum[ 6]=new Ccolumna(-0.54f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO_K,0);
golum[ 7]=new Ccolumna(-0.42f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO_K,0);
golum[ 8]=new Ccolumna(-0.30f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO_K,0);
golum[ 9]=new Ccolumna(-0.18f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO_K,0);
golum[10]=new Ccolumna(-0.06f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO_K,0);
golum[11]=new Ccolumna( 0.06f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO_K,0);
golum[12]=new Ccolumna( 0.18f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO_K,0);
golum[13]=new Ccolumna( 0.30f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO_K,0);
golum[14]=new Ccolumna( 0.42f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO_K,0);
golum[15]=new Ccolumna( 0.54f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO_K,0);
// LAS FINALES (4)
golum[16]=new Ccolumna(0.27f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
golum[17]=new Ccolumna(0.36f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
golum[18]=new Ccolumna(0.45f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
golum[19]=new Ccolumna(0.54f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
// LAS NO UTILIZABLES
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

num_golum=20;	// Siempre es una mas: de la 0 a la 12 => 13
ultima_columna=16;	// Una mas. Son las columnas seleccionables
tipo_juego=TOWERS;
juego_automatico=true;
mover_permitido=true;
automatico_permitido=true;
mazo_juego=52;
}

towers::~towers()
{

}

void towers::fase_presentacion()
{
mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);
mueve_colum_reparto(0,10,true);mueve_colum_reparto(0,11,true);
mueve_colum_reparto(0,12,true);mueve_colum_reparto(0,13,true);
mueve_colum_reparto(0,14,true);mueve_colum_reparto(0,15,true);

mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);
mueve_colum_reparto(0,10,true);mueve_colum_reparto(0,11,true);
mueve_colum_reparto(0,12,true);mueve_colum_reparto(0,13,true);
mueve_colum_reparto(0,14,true);mueve_colum_reparto(0,15,true);

mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);
mueve_colum_reparto(0,10,true);mueve_colum_reparto(0,11,true);
mueve_colum_reparto(0,12,true);mueve_colum_reparto(0,13,true);
mueve_colum_reparto(0,14,true);mueve_colum_reparto(0,15,true);

mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);
mueve_colum_reparto(0,10,true);mueve_colum_reparto(0,11,true);
mueve_colum_reparto(0,12,true);mueve_colum_reparto(0,13,true);
mueve_colum_reparto(0,14,true);mueve_colum_reparto(0,15,true);

mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);
mueve_colum_reparto(0,10,true);mueve_colum_reparto(0,11,true);
mueve_colum_reparto(0,12,true);mueve_colum_reparto(0,13,true);
mueve_colum_reparto(0,14,true);mueve_colum_reparto(0,15,true);

mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
FASE_PRESENTACION=false;
}


//*****************************************************//
// Devuelve TRUE si la carta es seleccionable
// segun las reglas del juego
bool towers::es_seleccionable(int cc,int c)
//****************************************************//
{
lista *alfa=NULL;
int b=0;
int karta_anterior=cc;
int huecos_libres=0;
golum[c]->num_sel=0;
carta[cc]->seleccionada=true;

// Contamos los huecos libres que hay (solo las free!!!)
for(int k=2;k<6;k++)
	if(!golum[k]->num_cartas)
		huecos_libres++;

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
		if (carta[alfa->carta]->tipo==carta[karta_anterior]->tipo &&
		    carta[alfa->carta]->valor==carta[karta_anterior]->valor-1 &&
			golum[c]->num_sel<huecos_libres)
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

//************************************//
// Mueve de una columna a otra efectivamente
// si se verifican las reglas del juego
bool towers::mover(int ini, int fin)
//***********************************//
{
//lista *alfa=NULL;
//int karta=NOCARTA;
int huecos_libres=0;
// Contamos los huecos libres que hay (solo los free!!!)
for(int k=2;k<6;k++)
	if(!golum[k]->num_cartas)
		huecos_libres++;
// Se puede colocar de una COLUMNA/PILA a COLUMNA NO VACIAS
if (golum[fin]->num_cartas && 
	carta[carta_seleccionada]->tipo==carta[golum[fin]->ultimo_valor->carta]->tipo &&
	carta[carta_seleccionada]->valor==carta[golum[fin]->ultimo_valor->carta]->valor-1 &&
	fin>5 && golum[ini]->num_sel<=huecos_libres+1)
	{
	afin=false;
	int s=golum[ini]->num_sel;
	mueve_multigolum(ini,fin);
	if(ultimo_mov!=actual_mov){
		while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
			ultimo_mov=ultimo_mov->ant_mov;
			delete(ultimo_mov->sig_mov);
			ultimo_mov->sig_mov=NULL;
			}
		}
	ultimo_mov->sig_mov=new undos(ini,fin,1,s,ultimo_mov,NULL,false);
	ultimo_mov=ultimo_mov->sig_mov;
	actual_mov=ultimo_mov;
	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	return true;
	}
// Se puede colocar en una COLUMNA VACIA solo REY
// Las columnas de apoyo solo pueden recibir una carta
else if (!golum[fin]->num_cartas &&
		 ((fin>5 && golum[ini]->num_sel<=huecos_libres+1 && carta[carta_seleccionada]->valor==13) || 
		  (golum[ini]->num_sel==1 && fin<6) ||
		  (golum[ini]->num_sel==1 && carta[carta_seleccionada]->valor==13)))
	{
	afin=false;
	int s=golum[ini]->num_sel;
	mueve_multigolum(ini,fin);
	if(ultimo_mov!=actual_mov){
		while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
			ultimo_mov=ultimo_mov->ant_mov;
			delete(ultimo_mov->sig_mov);
			ultimo_mov->sig_mov=NULL;
			}
		}
	ultimo_mov->sig_mov=new undos(ini,fin,1,s,ultimo_mov,NULL,false);
	ultimo_mov=ultimo_mov->sig_mov;
	actual_mov=ultimo_mov;
	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	return true;
	}
else return false;
}

void towers::busca_sitio_boton_derecho()
{
    // Nada que hacer
}
