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
// indian.cpp: implementation of the indian class.
//
//////////////////////////////////////////////////////////////////////

#include "indian.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

indian::indian()
{
tipo_juego=INDIAN;
}

indian::~indian()
{

}

void indian::fase_presentacion()
{
// PRIMERA FILA
mueve_colum_reparto(0,2,false);mueve_colum_reparto(0,3,false);mueve_colum_reparto(0,4,false);
mueve_colum_reparto(0,5,false);mueve_colum_reparto(0,6,false);mueve_colum_reparto(0,7,false);
mueve_colum_reparto(0,8,false);mueve_colum_reparto(0,9,false);mueve_colum_reparto(0,10,false);
mueve_colum_reparto(0,11,false);
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
FASE_PRESENTACION=false;
}

//************************************//
// Mueve de una columna a otra efectivamente
// si se verifican las reglas del juego
bool indian::mover(int ini, int fin)
//***********************************//
{
int karta=NOCARTA;
// Del MAZO a la PILA
if(ini==0 && fin==1){
	afin=false;
	karta=golum[0]->ultimo_valor->carta;
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
	carta[carta_seleccionada]->tipo !=carta[golum[fin]->ultimo_valor->carta]->tipo &&
	carta[carta_seleccionada]->valor==carta[golum[fin]->ultimo_valor->carta]->valor-1)
	{
	afin=false;
	mueve_multigolum(ini,fin);
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

	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	descubierta=false;
	return true;
	}
// Se puede colocar en una COLUMNA VACIA
else if (!golum[fin]->num_cartas)
	{
	afin=false;
	mueve_multigolum(ini,fin);
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

	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	descubierta=false;
	return true;
	}
else return false;
}

//*****************************************************//
// Devuelve TRUE si la carta es seleccionable
// segun las reglas del juego
bool indian::es_seleccionable(int cc,int c)
//****************************************************//
{
if(!carta[cc]->mostrada) {carta[cc]->seleccionada=false;golum[c]->num_sel=0;return false;}
if (cc==golum[c]->ultimo_valor->carta)
	{
	carta[cc]->seleccionada=true;
	golum[c]->num_sel=1;
	return true;
	}
else return false;
}
