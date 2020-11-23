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

// ladrones40y8.cpp: implementation of the ladrones40y8 class.
//
//////////////////////////////////////////////////////////////////////

#include "ladrones40y8.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
ladrones40y8::ladrones40y8()
{
// ESTAMOS PARA 40 LADRONES 2 MAZOS y 8 COLUMNAS CON UN REDEAL
// SOLO SE HAN CAMBIADO LAS DIFERENCIAS FUNDAMENTALES ENTRE LAS COLUM
// LA COLUMNA MAZO   es la misma que la de la clase base
// LA "COLUMNA" PILA es la misma que la de la clase base
// LAS COLUMNAS
golum[ 0]->desp_z=0.00015f;golum[0]->textura=MAZO_SI;
golum[ 2]->x=-0.42f;
golum[ 3]->x=-0.30f;
golum[ 4]->x=-0.18f;
golum[ 5]->x=-0.06f;
golum[ 6]->x= 0.06f;
golum[ 7]->x= 0.18f;
golum[ 8]->x= 0.30f;
golum[ 9]->x= 0.42f;
// LAS CASILLA FINALES
golum[10]->x=-0.315f;golum[10]->y=-0.39f;golum[10]->z=-1.2f;golum[10]->tipo=3;
golum[10]->selec=false;golum[10]->textura=FINAL;golum[10]->desp_z=0.0008f;
golum[10]->desp_x=0.0008f;golum[10]->desp_y=0.00025f;

golum[11]->x=-0.225f;golum[11]->y=-0.39f;golum[11]->z=-1.2f;golum[11]->tipo=3;
golum[11]->selec=false;golum[11]->textura=FINAL;golum[11]->desp_z=0.0008f;
golum[11]->desp_x=0.0008f;golum[11]->desp_y=0.00025f;

golum[12]->x=-0.135f;golum[12]->textura=FINAL;golum[12]->y=-0.39f;
golum[12]->z=-1.2f;golum[12]->tipo=3;golum[12]->selec=false;
golum[12]->desp_z=0.0008f;golum[12]->desp_x=0.0008f;golum[12]->desp_y=0.00025f;
golum[13]->x=-0.045f;golum[13]->textura=FINAL;golum[13]->y=-0.39f;
golum[13]->z=-1.2f;golum[13]->tipo=3;golum[13]->selec=false;
golum[13]->desp_z=0.0008f;golum[13]->desp_x=0.0008f;golum[13]->desp_y=0.00025f;

golum[14]->x= 0.045f;
golum[15]->x= 0.135f;
golum[16]->x= 0.225f;
golum[17]->x= 0.315f;
// LAS NO UTILIZABLES
golum[18]->x= 0.f;golum[18]->y=0.f;golum[18]->z=-1.f;golum[18]->tipo=4;
golum[19]->x= 0.f;golum[19]->y=0.f;golum[19]->z=-1.f;golum[19]->tipo=4;
golum[20]->x= 0.f;golum[20]->y=0.f;golum[20]->z=-1.f;golum[20]->tipo=4;
golum[21]->x= 0.f;golum[21]->y=0.f;golum[21]->z=-1.f;golum[21]->tipo=4;
golum[22]->x= 0.f;golum[22]->y=0.f;golum[22]->z=-1.f;golum[22]->tipo=4;
golum[23]->x= 0.f;golum[23]->y=0.f;golum[23]->z=-1.f;golum[23]->tipo=4;
golum[24]->x= 0.f;golum[24]->y=0.f;golum[24]->z=-1.f;golum[24]->tipo=4;
golum[25]->x= 0.f;golum[25]->y=0.f;golum[25]->z=-1.f;golum[25]->tipo=4;
num_golum=18;
mazo_juego=104;
ultima_columna=10;
tipo_juego=G40Y8;
}

ladrones40y8::~ladrones40y8()
{

}

void ladrones40y8::fase_presentacion()
{
// PRIMERA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);
// SEGUNDA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);
// TERCERA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);
// CUARTA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);
FASE_PRESENTACION=false;
}

//***************************************//
// Repite el ultimo juego
void ladrones40y8::repetir_juego()
//***************************************//
{
game::repetir_juego();
mazo_juego=104;
pases=0;
golum[0]->textura=MAZO_SI;juego_automatico=true;
for(int k=2;k<10;k++) golum[k]->desp_y=-0.03f;
}

//******************************************//
// Identifica la carta que se ha pinchado
int ladrones40y8::que_carta_es(int cc)
//******************************************//
{
lista *alfa=NULL;
int c,b;
int karta=NOCARTA;
if(cc==1 && golum[0]->num_cartas)	// MAZO
	{
	if(golum[0]->num_cartas && mover(0,1))
		{
		return NOCARTA;
		}
	else return NOCARTA;
	}
if(cc==1 && !golum[0]->num_cartas && !pases && !golum[1]->num_cartas)
	golum[0]->textura=MAZO_NO;	// No hay cartas en la pila que pasar

if(cc==1 && !golum[0]->num_cartas && !pases)	// MAZO RECICLABLE UN SOLO PASO
	{
	golum[0]->textura=MAZO_NO;int n=golum[1]->num_cartas;
	pases++;
	for(int k=1;k<n+1;k++)
		{
		afin=false;
		alfa=golum[1]->ultimo_valor;
		karta=alfa->carta;
		carta_seleccionada=karta;
		carta[karta]->seleccionada=true;
		columna_inicio=1;
		golum[1]->num_sel=1;
		mueve_multigolum(1,0);
		if(ultimo_mov!=actual_mov)
			{
			while(ultimo_mov->ant_mov!=actual_mov->ant_mov)
				{
				ultimo_mov=ultimo_mov->ant_mov;
				delete(ultimo_mov->sig_mov);
				ultimo_mov->sig_mov=NULL;
				}
			}
		ultimo_mov->sig_mov=new undos(1,0,k,1,ultimo_mov,NULL,descubierta);
		ultimo_mov=ultimo_mov->sig_mov;
		actual_mov=ultimo_mov;
		carta[karta]->seleccionada=false;
		}
	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	num_mov++;descubierta=false;if(esperar) {esperar=false;}//juego_automatico=true;}
	return NOCARTA;
	}
else if(cc==1 && !golum[0]->num_cartas)	// Es la ultima carta de la pila que ahora tiene
	{							// seleccion 1!!!
	if(golum[1]->num_cartas)
		{
		alfa=golum[1]->ultimo_valor;
		karta=alfa->carta;
		columna_inicio=1;
		carta[karta]->seleccionada=true;
		golum[1]->num_sel=1;
		return karta;
		}
	else if(!golum[1]->num_cartas)	// Hemos pinchado una PILA sin cartas
		{
		karta=NOCARTA;
		columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
		return NOCARTA;
		}
	}

if(cc==2)	// PILA
	{
	if(golum[1]->num_cartas)
		{
		alfa=golum[1]->ultimo_valor;
		karta=alfa->carta;
		columna_inicio=1;
		carta[karta]->seleccionada=true;
		golum[1]->num_sel=1;
		return karta;
		}
	else if(!golum[1]->num_cartas)	// Hemos pinchado una PILA sin cartas
		{
		karta=NOCARTA;
		columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
		return NOCARTA;
		}
	}

if(cc>199 && cc<ultima_columna*100)	// COLUMNAS DE LA 2 A LA 13 (LAS 12 DEL JUEGO)
	{
	c=cc/100;
	b=cc-c*100;
	if (golum[c]->num_cartas)	// HAY CARTAS EN LA GOLUM
		{
		alfa=golum[c]->primer_valor->sig;
		// Contamos las cartas que hay desde el principio a donde hemos pinchado
		for(int k=0;k<b;k++) {if(alfa->sig!=NULL) alfa=alfa->sig;}
		karta=alfa->carta;
		if (es_seleccionable(karta,c))	// Cumple reglas de seleccion??
			{
			if(columna_inicio==NOCOL) columna_inicio=c;
			else columna_final=c;
			return karta;
			}
		else		// HEMOS PINCHADO UNA CARTA FUERA DE LAS REGLAS DE SELECCION
			{
			karta=NOCARTA;
			columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
			return NOCARTA;
			}
		}
	else if(!golum[c]->num_cartas && carta_seleccionada!=NOCARTA && columna_inicio!=NOCOL)
		{
		columna_final=c;
		return carta_seleccionada;
		}
	}
return NOCARTA;
}
