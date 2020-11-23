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
// corona.cpp: implementation of the corona class.
//
//////////////////////////////////////////////////////////////////////

#include "wx_defines.h"
#include <wx/defs.h>

#include <wx/string.h>

#include "corona.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

corona::corona()
{
golum[14]->x=-0.315f;
golum[14]->y=-0.39f;
golum[14]->z=-1.2f;
golum[14]->tipo=3;
golum[14]->selec=false;
golum[14]->textura=FINAL;
golum[14]->desp_z=0.0008f;
golum[14]->desp_x=0.0008f;
golum[14]->desp_y=0.00025f;

golum[15]->x=-0.225f;
golum[15]->y=-0.39f;
golum[15]->z=-1.2f;
golum[15]->tipo=3;
golum[15]->selec=false;
golum[15]->textura=FINAL;
golum[15]->desp_z=0.0008f;
golum[15]->desp_x=0.0008f;
golum[15]->desp_y=0.00025f;
golum[16]->x=-0.135f;
golum[17]->x=-0.045f;
golum[18]->x= 0.045f;
golum[19]->x= 0.135f;
golum[20]->x= 0.225f;
golum[21]->x= 0.315f;

golum[22]->tipo=4;
golum[23]->tipo=4;
golum[24]->tipo=4;
golum[25]->tipo=4;

num_golum=22;
mazo_juego=104;
ultima_columna=14;
tipo_juego=CORONA;
}

corona::~corona()
{

}

void corona::fase_presentacion()
{
// PRIMERA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,10,true);
mueve_colum_reparto(0,11,true);mueve_colum_reparto(0,12,true);mueve_colum_reparto(0,13,true);
// SEGUNDA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,10,true);
mueve_colum_reparto(0,11,true);mueve_colum_reparto(0,12,true);mueve_colum_reparto(0,13,true);
// TERCERA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,10,true);
mueve_colum_reparto(0,11,true);mueve_colum_reparto(0,12,true);mueve_colum_reparto(0,13,true);
FASE_PRESENTACION=false;
}


//**********************************************
// Coloca cartas automaticamente de las columnas
	bool corona::automatico(void)
//**********************************************
{
// FUNCION RECURSIVA. DEVUELVE VERDAD SI HA HABIDO COLOCACION DE CARTA
// EN PILA INFERIOR Y NO SE CANCELA HASTA QUE SE REVISE TODO Y DEVUELVA FALSO
// Bueno, no se ha hecho tan elegante...
int r,l;
bool vuelta=true;
bool mv=mov_pendiente;
bool salir;
int ci=columna_inicio;
int cs=carta_seleccionada;
mov_pendiente=true;
lista *alfa=NULL;
while(vuelta)
	{
	if(cartas_colocadas==mazo_juego){
		vuelta=false;
		JUEGO_FINALIZADO=true;
		break;
	}
	salir=false;

	for (l=2;l<ultima_columna;l++)	// Colocamos cartas de las columnas
		{
		if(golum[l]->num_cartas)
			{
			for(r=golum[l]->num_cartas;r;r--)
				{
				alfa=golum[l]->ultimo_valor;
				columna_inicio=l;
				carta_seleccionada=alfa->carta;
				if (!colocar_carta(carta_seleccionada,l)) {vuelta=false;break;}
				else {vuelta=true;salir=true;break;}
				}
			}
		if (salir) break;
		}
	
	// Si no hay cartas en la pila pero si en el mazo,
	// se mueve una carta del mazo a la pila
	if (golum[0]->num_cartas && !golum[1]->num_cartas)
		{
		carta_seleccionada=golum[0]->ultimo_valor->carta;
		golum[0]->num_sel=1;
		mover(0,1);
		vuelta=false;
		}

	// Colocamos cartas de la reserva, si hay
	if (golum[1]->num_cartas)
		{
		for(int k=2;k<ultima_columna;k++)
			{
			if(!golum[k]->num_cartas)
				{
				carta_seleccionada=golum[1]->ultimo_valor->carta;
				golum[1]->num_sel=1;
				mover(1,k);
				vuelta=false;
				break;
				}
			}
		}

	if(!golum[1]->num_cartas)	// No hay cartas en la pila
		{
		vuelta=false;break;
		}
	else if(golum[1]->num_cartas && !salir)	// Colocamos cartas de la pila
		{
		for(r=golum[1]->num_cartas;r;r--)
			{
			alfa=golum[1]->ultimo_valor;
			columna_inicio=1;
			carta_seleccionada=alfa->carta;
			if (!colocar_carta(carta_seleccionada,1)) {vuelta=false;break;}
			else {vuelta=true;break;}
			}	
		}	// Fin de los ifs
	}	// Fin del while
if (cs==NOCARTA) recolocar();
columna_inicio=ci;
carta_seleccionada=cs;
mov_pendiente=mv;
return vuelta;
}

//***************************************//
// Repite el ultimo juego
void corona::repetir_juego()
//***************************************//
{
game::repetir_juego();
mazo_juego=104;
}

//************************************//
// Mueve de una columna a otra efectivamente
// si se verifican las reglas del juego
bool corona::mover(int ini, int fin)
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
	ultimo_mov->sig_mov=new undos(ini,fin,1,1,ultimo_mov,NULL,false);
	ultimo_mov=ultimo_mov->sig_mov;
	actual_mov=ultimo_mov;
	carta[karta]->seleccionada=false;
	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	return true;
	}	
// Se puede colocar de una COLUMNA/PILA a COLUMNA NO VACIAS
else if (golum[fin]->num_cartas && 
	carta[carta_seleccionada]->tipo ==carta[golum[fin]->ultimo_valor->carta]->tipo &&
	carta[carta_seleccionada]->valor==carta[golum[fin]->ultimo_valor->carta]->valor-1)
	{
	afin=false;
	mueve_golum(ini,fin);
	if(ultimo_mov!=actual_mov){
		while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
			ultimo_mov=ultimo_mov->ant_mov;
			delete(ultimo_mov->sig_mov);
			ultimo_mov->sig_mov=NULL;
			}
		}
	ultimo_mov->sig_mov=new undos(ini,fin,1,1,ultimo_mov,NULL,false);
	ultimo_mov=ultimo_mov->sig_mov;
	actual_mov=ultimo_mov;

	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	return true;
	}
// Se puede colocar en una COLUMNA VACIA
// Si las cartas de la pila ya estan agotadas
// NO SE ADMITEN CARTAS DE LAS COLUMNAS
else if (!golum[fin]->num_cartas && (!golum[1]->num_cartas || ini==1))
	{
	afin=false;
	mueve_golum(ini,fin);
	if(ultimo_mov!=actual_mov){
		while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
			ultimo_mov=ultimo_mov->ant_mov;
			delete(ultimo_mov->sig_mov);
			ultimo_mov->sig_mov=NULL;
			}
		}
	ultimo_mov->sig_mov=new undos(ini,fin,1,1,ultimo_mov,NULL,false);
	ultimo_mov=ultimo_mov->sig_mov;
	actual_mov=ultimo_mov;

	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	return true;
	}
else return false;
}

//**************************************//
// Busca automaticamente un sitio para la carta de la pila
void corona::busca_sitio_boton_derecho()
//**************************************//
{
bool colocada=false;
int cs=NOCARTA;
mov_pendiente=true;
// Si hay cartas en la pila primero debemos colocarla en hueco libre si
// existe para evitar trampas con el deshacer/rehacer
if (golum[1]->num_cartas && carta_seleccionada==NOCARTA)
	{
	for(int k=2;k<ultima_columna;k++)
		{
		if(!golum[k]->num_cartas)
			{
			carta_seleccionada=golum[1]->ultimo_valor->carta;
			golum[1]->num_sel=1;
			mover(1,k);
			golum[1]->num_sel=0;
			carta_seleccionada=NOCARTA;columna_inicio=NOCOL;
			//devolver=true;
			break;
			}
		}
	}
// Sacamos carta del MAZO si hay claro
if(golum[0]->num_cartas && mover(0,1))
	{
	columna_inicio=1;
	carta_seleccionada=golum[1]->ultimo_valor->carta;
	cs=carta_seleccionada;
	carta[golum[1]->ultimo_valor->carta]->seleccionada=true;
	golum[1]->num_sel=1;
// Si el juego automatico esta activado
// mira si se puede colocar en columnas finales
	if(juego_automatico && !colocada)
		if(colocar_carta(carta_seleccionada,1) && !colocada)	// Si se ha colocado la carta volvemos
			{
			colocada=true;
			}
// Buscamos sitio en columnas ocupadas si esta puesto el automatico
	if(juego_automatico && !colocada)
		{
		for(int k=2;k<ultima_columna;k++)
			{
			if(golum[k]->num_cartas && mover(1,k)) colocada=true;
			}
		}
	if(juego_automatico && mov_pendiente && !colocada)	// Es una carta que debe volver a su sitio
		{
		columna_inicio=1;afin=false;
		float x=golum[1]->x+golum[1]->desp_x*(golum[1]->num_cartas-1);
		float y=golum[1]->y+golum[1]->desp_y*(golum[1]->num_cartas-1);
		float z=golum[1]->z+golum[1]->desp_z*(golum[1]->num_cartas-1);
		if(golum[1]->num_cartas>54 && tipo_juego!=GOLF_AK2 && tipo_juego!=CANFIELD2){
			x=golum[1]->x+(golum[1]->desp_x*(golum[1]->num_cartas-56));
			y=golum[1]->y-0.05f;
			}
		movimiento(x,y,z,carta_seleccionada);
		}
	}
golum[1]->num_sel=0;
carta[cs]->seleccionada=false;
carta_seleccionada=NOCARTA;columna_inicio=NOCOL;mov_pendiente=false;
}

//******************************************//
// Identifica la carta que se ha pinchado
int corona::que_carta_es(int cc)
//******************************************//
{
lista *alfa=NULL;
int c,b;
int karta=NOCARTA;
if(cc==1 && golum[0]->num_cartas)	// MAZO
	{
// Si hay cartas en la pila primero debemos colocarla en hueco libre si
// existe para evitar trampas con el deshacer/rehacer
	if(golum[1]->num_cartas)
		{
		for(int k=2;k<ultima_columna;k++)
			{
			if(!golum[k]->num_cartas)
				{
				carta_seleccionada=golum[1]->ultimo_valor->carta;
				golum[1]->num_sel=1;
				mover(1,k);
				golum[1]->num_sel=0;
				carta_seleccionada=NOCARTA;columna_inicio=NOCOL;
				//return NOCARTA;
				break;
				}
			}
		if(golum[0]->num_cartas) mover(0,1);
		return NOCARTA;
		}
	else if(golum[0]->num_cartas && mover(0,1))
		{
		return NOCARTA;
		}
	else return NOCARTA;
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

//**************************************//
	void corona::mover_a_columna(int cc)
//**************************************//
{
lista *alfa;
int c;
//int karta=NOCARTA;
int ci=columna_inicio;

// MAZO. SOLO PERMITIDO SI NO HAY CARTA SELECCIONADA
if(cc==1 && golum[0]->num_cartas && carta_seleccionada==NOCARTA)
	{
	// Primero nos cepillamos las posibles cartas seleccionadas
	alfa=golum[ci]->primer_valor->sig;
	for(int k=0;k<golum[ci]->num_cartas;k++){
		carta[alfa->carta]->seleccionada=false;
		alfa=alfa->sig;
		}
	golum[ci]->num_sel=0;
	mover(0,1);
	}
else if(cc==1 && !golum[0]->num_cartas)	// Es la ultima carta de la pila
	{									// que ahora tiene seleccion 1!!!
	if(golum[1]->num_cartas)
		{
		columna_final=NOCOL;		// No se permite mover cartas a la pila
		}
	else if(!golum[1]->num_cartas)	// Hemos pinchado una PILA sin cartas
		{
		columna_final=NOCOL;		// No se permite mover cartas a la pila
		}
	}
if(cc==2)	// PILA
	{
	if(golum[1]->num_cartas)
		{
		columna_final=NOCOL;		// No se permite mover cartas a la pila
		}
	else if(!golum[1]->num_cartas)	// Hemos pinchado una PILA sin cartas
		{
		columna_final=NOCOL;
		}
	}
if(cc>199 && cc<ultima_columna*100)	// COLUMNAS DE LA 2 A LA 13 (LAS 12 DEL JUEGO)
	{
	c=cc/100;
	columna_final=c;
	}
// Y ahora intentamos mover la carta
if(columna_inicio!=columna_final && columna_final!=NOCOL)
	mover(columna_inicio,columna_final);

alfa=golum[ci]->primer_valor->sig;
for(int k=0;k<golum[ci]->num_cartas;k++){
	carta[alfa->carta]->seleccionada=false;
	alfa=alfa->sig;
	}
golum[ci]->num_sel=0;

carta_seleccionada=NOCARTA;columna_inicio=columna_final=NOCOL;
}
