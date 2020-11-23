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
// easthaven.cpp: implementation of the easthaven class.
//
//////////////////////////////////////////////////////////////////////

#include "wx_defines.h"
#include <wx/defs.h>

#include <wx/string.h>

#include "easthaven.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

easthaven::easthaven()
{
tipo_juego=EASTHAVEN;
golum[0]->textura=MAZO_NO;
golum[2]->textura=HUECO;
golum[3]->textura=HUECO;
golum[4]->textura=HUECO;
golum[5]->textura=HUECO;
golum[6]->textura=HUECO;
golum[7]->textura=HUECO;
golum[8]->textura=HUECO;
golum[1]->selec=false;
golum[1]->tipo=4;
}

easthaven::~easthaven()
{

}

void easthaven::fase_presentacion()
{
mueve_colum_reparto(0,2,false);mueve_colum_reparto(0,3,false);
mueve_colum_reparto(0,4,false);mueve_colum_reparto(0,5,false);
mueve_colum_reparto(0,6,false);mueve_colum_reparto(0,7,false);
mueve_colum_reparto(0,8,false);

mueve_colum_reparto(0,2,false);mueve_colum_reparto(0,3,false);
mueve_colum_reparto(0,4,false);mueve_colum_reparto(0,5,false);
mueve_colum_reparto(0,6,false);mueve_colum_reparto(0,7,false);
mueve_colum_reparto(0,8,false);

mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);
mueve_colum_reparto(0,4,true);mueve_colum_reparto(0,5,true);
mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);

FASE_PRESENTACION=false;
}

//************************************//
// Mueve de una columna a otra efectivamente
// si se verifican las reglas del juego
bool easthaven::mover(int ini, int fin)
//***********************************//
{
//lista *alfa=NULL;
//int karta=NOCARTA;
// Del MAZO a las COLUMNAS
if(ini==0 && fin==1)
	{
	// Metemos una carta en cada una de las columnas si hay cartas en el mazo
	for(int k=2;k<ultima_columna;k++)
		{
		if(golum[0]->num_cartas){
			mueve_golum(0,k);
			if(ultimo_mov!=actual_mov){
				while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
					ultimo_mov=ultimo_mov->ant_mov;
					delete(ultimo_mov->sig_mov);
					ultimo_mov->sig_mov=NULL;
					}
				}		// Esto de k-1 es para ahorrarme una variable: es lo de cuantos mov
			ultimo_mov->sig_mov=new undos(0,k,k-1,1,ultimo_mov,NULL,descubierta);
			ultimo_mov=ultimo_mov->sig_mov;
			actual_mov=ultimo_mov;
			}
		}
	num_mov++;descubierta=false;
	return true;
	}
// Se puede colocar de una COLUMNA/PILA a COLUMNA NO VACIAS
else if (golum[fin]->num_cartas && 
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

//**************************************//
// Busca automaticamente un sitio para la carta de la pila
void easthaven::busca_sitio_boton_derecho()
//**************************************//
{
// Nada que hacer
}

//*****************************************************//
// Devuelve TRUE si la carta es seleccionable
// segun las reglas del juego
bool easthaven::es_seleccionable(int cc,int c)
//****************************************************//
{
lista *alfa=NULL;
int b=0;
int karta_anterior=cc;
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
