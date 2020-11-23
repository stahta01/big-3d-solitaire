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
// rail1.cpp: implementation of the rail1 class.
//
//////////////////////////////////////////////////////////////////////

#include "rail1.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

rail1::rail1()
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
golum[ 0]=new Ccolumna(-0.18f,0.4f,-1.2f,0,true,0,0.0000015f,0.0000015f,0.00015f,MAZO_NO,0);
// LA "COLUMNA" PILA
golum[ 1]=new Ccolumna(-0.06f,0.4f,-1.2f,1,true,0,0.0000015f,0.0000015f,0.00015f,MAZO_NO,0);
// LAS COLUMNAS (4)
golum[ 2]=new Ccolumna(-0.18f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 3]=new Ccolumna(-0.06f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 4]=new Ccolumna( 0.06f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 5]=new Ccolumna( 0.18f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
// LAS FINALES (4)
golum[ 6]=new Ccolumna( 0.27f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_G,0);
golum[ 7]=new Ccolumna( 0.36f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_G,0);
golum[ 8]=new Ccolumna( 0.45f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_G,0);
golum[ 9]=new Ccolumna( 0.54f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_G,0);
// LAS NO UTILIZABLES
golum[10]=new Ccolumna(-0.12f,0.0f,-1.2f,4,false,0,0.f,0.f,0.0f,HUECO,0);
golum[11]=new Ccolumna(-0.12f,0.0f,-1.2f,4,false,0,0.f,0.f,0.0f,HUECO,0);
golum[12]=new Ccolumna( 0.00f,0.0f,-1.2f,4,false,0,0.f,0.f,0.0f,HUECO,0);
golum[13]=new Ccolumna(-0.12f,0.0f,-1.2f,4,false,0,0.f,0.f,0.0f,HUECO,0);
golum[14]=new Ccolumna( 0.00f,0.0f,-1.2f,4,false,0,0.f,0.f,0.0f,HUECO,0);
golum[15]=new Ccolumna( 0.12f,0.0f,-1.2f,4,false,0,0.f,0.f,0.0f,HUECO,0);
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

num_golum=10;	// Siempre es una mas
mazo_juego=52;
ultima_columna=6;	// Una mas. Son las columnas seleccionables
juego_automatico=true;
tipo_juego=RAIL1;
mover_permitido=true;
automatico_permitido=true;
posX=0.0638f;
posY=-0.278f;
posZ=-0.261f;
viewX=0.0638f;
viewY=0.148f;
viewZ=-1.4f;
vectorX=0.f;
vectorY=1.f;
vectorZ=0.f;
}

rail1::~rail1()
{

}

void rail1::fase_presentacion()
{
mueve_colum_reparto(0,2,true);
mueve_colum_reparto(0,3,true);
mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);
FASE_PRESENTACION=false;
}

//************************************//
// Mueve de una columna a otra efectivamente
// si se verifican las reglas del juego
bool rail1::mover(int ini, int fin)
//***********************************//
{
lista *alfa=NULL;
int karta=NOCARTA;
// Del MAZO a la PILA
if(ini==0 && fin==1){
	afin=false;
	alfa=golum[0]->ultimo_valor;
	karta=alfa->carta;
	carta[karta]->seleccionada=true;
	columna_inicio=0;
	golum[0]->num_sel=1;
	mueve_multigolum(0,1);
	if(ultimo_mov!=actual_mov){
		while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
			ultimo_mov=ultimo_mov->ant_mov;
			delete(ultimo_mov->sig_mov);
			ultimo_mov->sig_mov=NULL;
			}
		}
	ultimo_mov->sig_mov=new undos(ini,fin,1,1,ultimo_mov,NULL,descubierta);
	ultimo_mov=ultimo_mov->sig_mov;
	actual_mov=ultimo_mov;
	carta[karta]->seleccionada=false;
	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	descubierta=false;
	return true;
	}
// Se puede colocar de una COLUMNA/PILA a COLUMNA NO VACIAS
else if (golum[fin]->num_cartas && 
		carta[carta_seleccionada]->valor==carta[golum[fin]->ultimo_valor->carta]->valor-1)
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
	ultimo_mov->sig_mov=new undos(ini,fin,1,s,ultimo_mov,NULL,descubierta);
	ultimo_mov=ultimo_mov->sig_mov;
	actual_mov=ultimo_mov;
	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	descubierta=false;
	return true;
	}
// Se puede colocar en una COLUMNA VACIA
else if (!golum[fin]->num_cartas)
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
	ultimo_mov->sig_mov=new undos(ini,fin,1,s,ultimo_mov,NULL,descubierta);
	ultimo_mov=ultimo_mov->sig_mov;
	actual_mov=ultimo_mov;

	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	descubierta=false;
	return true;
	}
else return false;
}
