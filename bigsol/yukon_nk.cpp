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
// yukon_nk.cpp: implementation of the yukon_nk class.
//
//////////////////////////////////////////////////////////////////////

#include "yukon_nk.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

yukon_nk::yukon_nk()
{
tipo_juego=YUKON_NK;
golum[2]->textura=HUECO;
golum[3]->textura=HUECO;
golum[4]->textura=HUECO;
golum[5]->textura=HUECO;
golum[6]->textura=HUECO;
golum[7]->textura=HUECO;
golum[8]->textura=HUECO;
}

yukon_nk::~yukon_nk()
{

}

//************************************//
// Mueve de una columna a otra efectivamente
// si se verifican las reglas del juego
bool yukon_nk::mover(int ini, int fin)
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
// Para Yukon podria pasar que se colocara en su misma columna
// y por eso se evita sobreescribiendo el metodo
else if (golum[fin]->num_cartas && fin!=ini &&
	carta[carta_seleccionada]->color!=carta[golum[fin]->ultimo_valor->carta]->color &&
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
// Se puede colocar en una COLUMNA VACIA. Aqui se puede mover cualquier carta y todo lo detras claro
else if (!golum[fin]->num_cartas)// && carta[carta_seleccionada]->valor==13)
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
