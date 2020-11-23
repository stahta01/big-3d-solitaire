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
// scorpion.cpp: implementation of the scorpion class.
//
//////////////////////////////////////////////////////////////////////

#include "wx_defines.h"
#include <wx/defs.h>

#include <wx/sound.h>
#include <wx/string.h>

#include "scorpion.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

scorpion::scorpion()
{
golum[ 0]->selec=true;
golum[ 9]->textura=FINAL_AK;
golum[10]->textura=FINAL_AK;
golum[11]->textura=FINAL_AK;
golum[12]->textura=FINAL_AK;

tipo_juego=SCORPION;
juego_automatico=true;
mover_permitido=true;
automatico_permitido=false;
posX=0.0593f;
posY=-0.422f;
posZ=-0.247f;
viewX=0.0593f;
viewY=0.004f;
viewZ=-1.387f;
vectorX=0.f;
vectorY=1.f;
vectorZ=0.f;
}

scorpion::~scorpion()
{

}

void scorpion::fase_presentacion()
{
mueve_colum_reparto(0,2,false);mueve_colum_reparto(0,3,false);
mueve_colum_reparto(0,4,false);mueve_colum_reparto(0,5,false);
mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);

mueve_colum_reparto(0,2,false);mueve_colum_reparto(0,3,false);
mueve_colum_reparto(0,4,false);mueve_colum_reparto(0,5,false);
mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);

mueve_colum_reparto(0,2,false);mueve_colum_reparto(0,3,false);
mueve_colum_reparto(0,4,false);mueve_colum_reparto(0,5,false);
mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);

mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);
mueve_colum_reparto(0,4,true);mueve_colum_reparto(0,5,true);
mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);

mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);
mueve_colum_reparto(0,4,true);mueve_colum_reparto(0,5,true);
mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);

mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);
mueve_colum_reparto(0,4,true);mueve_colum_reparto(0,5,true);
mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);

mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);
mueve_colum_reparto(0,4,true);mueve_colum_reparto(0,5,true);
mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);

FASE_PRESENTACION=false;
}

//**********************************************
// Coloca cartas automaticamente de las columnas
	bool scorpion::automatico(void)
//**********************************************
{
// FUNCION RECURSIVA. DEVUELVE VERDAD SI HA HABIDO COLOCACION DE CARTA
// EN PILA INFERIOR Y NO SE CANCELA HASTA QUE SE REVISE TODO Y DEVUELVA FALSO
// Bueno, no se ha hecho tan elegante...
if(mov_pendiente) return false;
bool mv=mov_pendiente;
int ci=columna_inicio;
int cs=carta_seleccionada;
mov_pendiente=true;
lista *alfa=NULL;
int valor=1;
int tipo=0;
bool colocar=false;
bool devolver=false;

for(int k=2;k<ultima_columna;k++)
	{
	// Primero miramos si hay toda una columna para colocar
	valor=1;tipo=0;colocar=false;	
	alfa=golum[k]->ultimo_valor;
	if (golum[k]->num_cartas >12 && carta[alfa->carta]->valor==valor)
		{
		tipo=carta[alfa->carta]->tipo;
		//alfa=alfa->ant;
		for(int i=0;i<12;i++)
			{
			alfa=alfa->ant; valor++;
			if(carta[alfa->carta]->mostrada && carta[alfa->carta]->tipo==tipo && carta[alfa->carta]->valor==valor)
				{
				colocar=true;
				}
			else 
				{
				colocar=false;
				break;
				}
			}
		if(colocar)
			{
			carta_seleccionada=alfa->carta;columna_inicio=k;
			golum[k]->num_sel=13;
			carta[alfa->carta]->seleccionada=true;
			for(int i=0;i<12;i++)
				{
				alfa=alfa->sig;
				carta[alfa->carta]->seleccionada=true;
				}
			if(colocar_carta(carta_seleccionada,columna_inicio)) devolver=true;
			}
		}
	recolocar();
	}
carta_seleccionada=cs;columna_inicio=ci;mov_pendiente=mv;
return devolver;
}

//*********************************************************
// Mira si la carta en cuestion cabe en alguna pila final	
	bool scorpion::colocar_carta(int n,int ini)
//*********************************************************
{
bool devolver=false;
int b=0;
lista *alfa=NULL;
int karta_anterior=n;

// Vamos al principio de la golum
alfa=golum[ini]->primer_valor->sig;
// Vemos donde hemos pinchado
for(int k=0;k<golum[ini]->num_cartas;k++)
	{
	if(alfa->carta!=n) alfa=alfa->sig;
	else {b=k;break;}
	}

// Son todas las cartas del mismo palo en orden decreciente??
// La primera carta ya esta comprobada (de ahi el +1)
for(int k=b+1;k<golum[ini]->num_cartas;k++)
	{	
	alfa=alfa->sig;
	if(!(carta[alfa->carta]->tipo==carta[karta_anterior]->tipo &&
		 carta[alfa->carta]->valor==carta[karta_anterior]->valor-1))
		return false;
	else karta_anterior=alfa->carta;
	}

// Hemos pasado el chequeo
for(int g=ultima_columna;g<num_golum;g++)
	{
	if (!golum[g]->num_cartas)
		{
		// CON ESTE METODO SOLO SIN FORS NI DESELECCIONAR
		// VAN TODAS A LA VEZ Y SE OBTIENE OTRO EFECTO
		// Y ES MAS GUAPO
		afin=true;
		carta[n]->seleccionada=true;
		mueve_multigolum(ini,g);
		carta[n]->seleccionada=false;
		golum[ini]->num_sel=0;
		if(ultimo_mov!=actual_mov){
			while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
				ultimo_mov=ultimo_mov->ant_mov;
				delete(ultimo_mov->sig_mov);
				ultimo_mov->sig_mov=NULL;
				}
			}
		ultimo_mov->sig_mov=new undos(ini,g,1,13,ultimo_mov,NULL,descubierta);
		ultimo_mov=ultimo_mov->sig_mov;
		actual_mov=ultimo_mov;
		if (activar_sonido && sonido_colocar->IsOk())	sonido_colocar->Play(wxSOUND_ASYNC);
		devolver=true;cartas_colocadas+=13;
		num_mov++;if(esperar) {esperar=false;juego_automatico=true;}
		columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
		descubierta=false;
		break;
		}
	}
return devolver;
}

//************************************//
// Mueve de una columna a otra efectivamente
// si se verifican las reglas del juego
bool scorpion::mover(int ini, int fin)
//***********************************//
{
//lista *alfa=NULL;
//int karta=NOCARTA;

// Del MAZO a las COLUMNAS
if(ini==0 && fin==1)
	{
	// Metemos una carta en cada una de las TRES PRIMERAS columnas
	for(int k=2;k<5;k++)
		{
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
	num_mov++;descubierta=false;
	return true;
	}	
// Se puede colocar de una COLUMNA/PILA a COLUMNA NO VACIAS
// Para Yukon podria pasar que se colocara en su misma columna
// y por eso se evita sobreescribiendo el metodo
else if (golum[fin]->num_cartas && fin!=ini &&
	carta[carta_seleccionada]->tipo==carta[golum[fin]->ultimo_valor->carta]->tipo &&
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
// Se puede colocar en una COLUMNA VACIA. Solo se puede mover un REY y todo lo detras claro
else if (!golum[fin]->num_cartas && carta[carta_seleccionada]->valor==13)
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

//*********************************************************************//
// Busca automaticamente un sitio para la carta seleccionada o agarrada
	void scorpion::busca_sitio(void)
//*********************************************************************//
{
lista *alfa;
bool colocada=false;
int cs=carta_seleccionada;
int ci=columna_inicio;
int cf=NOCOL;
bool mv=mov_pendiente;
mov_pendiente=true;
float xf,yf,zf;
// Miramos si el JUGADOR intenta COLOCAR la carta
// en una columna determinada

// TODO ESTE PROCESO COMENTADO SE REFIERE A QUE LE JUGADOR INTENTA COLOCAR
// EN UN SITIO DETERMINADO Y HAY QUE RECODIFICARLO TODO SIN FILAS[] NI COLUMNAS[]
if(mov_pendiente)
	{	// JUGADOR INTENTA COLOCAR EN LA MISMA columna de inicio
	if(carta[cs]->x>golum[ci]->x-0.04f &&	// La PILA NO se permite
	   carta[cs]->x<golum[ci]->x+0.04f &&
	   carta[cs]->y>(golum[ci]->y+golum[ci]->desp_y*(golum[ci]->num_cartas-golum[ci]->num_sel))-0.12f &&	// Si se pone a 0.035f
	   carta[cs]->y<(golum[ci]->y+golum[ci]->desp_y*(golum[ci]->num_cartas-golum[ci]->num_sel))+0.12f &&	// no funciona el doble click
	   ci>1 && !doble_click)  // pero lo arreglaremos con un bool de dobleclick
		{
		afin=false;
		xf=golum[ci]->x+golum[ci]->desp_x*(golum[ci]->num_cartas-golum[ci]->num_sel);
		yf=golum[ci]->y+golum[ci]->desp_y*(golum[ci]->num_cartas-golum[ci]->num_sel);
		zf=golum[ci]->z+golum[ci]->desp_z*(golum[ci]->num_cartas-golum[ci]->num_sel);
		movimiento(xf,yf,zf,cs);
		cf=ci;
		colocada=true;
		}
	else // EL JUGADOR INTENTA COLOCAR EN UNA COLUMNA DETERMINADA
		{	// LA PILA NO ESTA PERMITIDA
		for(int k=2;k<ultima_columna;k++) 
			{			// El ANCHO de carta y el ALTO de carta
			if(carta[cs]->x>golum[k]->x-0.04f &&
			   carta[cs]->x<golum[k]->x+0.04f &&
		       carta[cs]->y>(golum[k]->y+golum[k]->desp_y*(golum[k]->num_cartas-golum[k]->num_sel))-0.12f &&
		       carta[cs]->y<(golum[k]->y+golum[k]->desp_y*(golum[k]->num_cartas-golum[k]->num_sel))+0.12f)
				{
				if(k==ci && !doble_click)	// Es la misma columna; la dejamos donde esta
					{
					afin=false;
					xf=golum[ci]->x+golum[ci]->desp_x*(golum[ci]->num_cartas-golum[ci]->num_sel);
					yf=golum[ci]->y+golum[ci]->desp_y*(golum[ci]->num_cartas-golum[ci]->num_sel);
					zf=golum[ci]->z+golum[ci]->desp_z*(golum[ci]->num_cartas-golum[ci]->num_sel);
					movimiento(xf,yf,zf,cs);
					colocada=true;
					break;
					}
				else if(mover(ci,k))
					{
					cf=k;
					colocada=true;
					break;
					}
				else
					{
					carta_seleccionada=cs;
					columna_inicio=ci;
					cf=ci;
					}
				}
			}	// Fin del for
		}
	}
// Si el juego automatico esta desactivado
// mira si se puede colocar en columnas finales
// Solo lo miraremos si hemos pinchado una K con 13 cartas en total de seleccion
if(!juego_automatico && !colocada &&
    golum[columna_inicio]->num_sel==13 && carta[carta_seleccionada]->valor==13)
	if(colocar_carta(carta_seleccionada,columna_inicio) && !colocada)	// Si se ha colocado la carta volvemos
		{
		colocada=true;
		}
// Buscamos sitio en columnas ocupadas del mismo palo
if(!colocada)
	{
	for(int k=2;k<ultima_columna;k++)
		{
		if(golum[k]->num_cartas && k!=ci)	// Evitamos la misma columna
			{
			if(mover_a_palo(columna_inicio,k)) {
				cf=k;colocada=true;break;
			}
			else {carta_seleccionada=cs;cf=columna_inicio=ci;}
			}
		}
	}
// Buscamos sitio en columnas ocupadas de distinto palo
if(!colocada)
	{
	for(int k=2;k<ultima_columna;k++)
		{
		if(golum[k]->num_cartas)
			{
			if(mover(columna_inicio,k)) {
				cf=k;colocada=true;break;
			}
			else {carta_seleccionada=cs;cf=columna_inicio=ci;}
			}
		}
	}
// Ahora buscamos sitio en huecos libres ya que no esta colocada
if(!colocada)
{
	for(int k=2;k<ultima_columna;k++)
		{
		if(!golum[k]->num_cartas)
			{
				if(mover(columna_inicio,k))
					{
					colocada=true;
					break;
					}
			}
		}
}
if(mov_pendiente && !colocada)	// Es una carta que debe volver a su sitio
	{
	columna_inicio=ci;afin=false;
	carta_seleccionada=cs;
	xf=golum[ci]->x+golum[ci]->desp_x*(golum[ci]->num_cartas-golum[ci]->num_sel);
	yf=golum[ci]->y+golum[ci]->desp_y*(golum[ci]->num_cartas-golum[ci]->num_sel);
	zf=golum[ci]->z+golum[ci]->desp_z*(golum[ci]->num_cartas-golum[ci]->num_sel);
	if(ci==1 && golum[1]->num_cartas>54){
		xf=golum[1]->x+(golum[1]->desp_x*(golum[1]->num_cartas-56));
		yf=golum[1]->y-0.05f;
		}
	movimiento(xf,yf,zf,cs);	// Se pierde el valor de carta_seleccionada al llamar a movimiento
	}
// Ponemos todas las cartas de la columna no seleccionadas
alfa=golum[ci]->primer_valor->sig;
for(int k=0;k<golum[ci]->num_cartas;k++){
	carta[alfa->carta]->seleccionada=false;
	alfa=alfa->sig;
	}
golum[ci]->num_sel=0;
carta_seleccionada=NOCARTA;columna_inicio=NOCOL;mov_pendiente=mv;
}

//************************************//
// Mueve de una columna a otra efectivamente
// si son del mismo palo
bool scorpion::mover_a_palo(int ini, int fin)
//***********************************//
{
// Del MAZO a las COLUMNAS
if(ini==0 && fin==1) return false;
// De COLUMNA/PILA a COLUMNA CON MISMO PALO
else if(golum[fin]->num_cartas && ini!=fin &&

		carta[carta_seleccionada]->tipo==carta[golum[fin]->ultimo_valor->carta]->tipo &&
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
	num_mov++;if(esperar) {esperar=false;juego_automatico=true;}
	descubierta=false;
	return true;
	}
else return false;
}

