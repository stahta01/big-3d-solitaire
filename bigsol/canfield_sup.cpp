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
// canfield_sup.cpp: implementation of the canfield_sup class.
//
//////////////////////////////////////////////////////////////////////

#include "canfield_sup.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

canfield_sup::canfield_sup()
{
tipo_juego=CANFIELD_SUP;

}

canfield_sup::~canfield_sup()
{

}

//************************************//
// Mueve de una columna a otra efectivamente
// si se verifican las reglas del juego
bool canfield_sup::mover(int ini, int fin)
//***********************************//
{
int num_movi=0;
lista *alfa=NULL;
int karta=NOCARTA;
// Del MAZO a la PILA
if(ini==0 && fin==1){
	// Movemos primera carta
	afin=false;
	alfa=golum[0]->ultimo_valor;
	karta=alfa->carta;
	carta[karta]->seleccionada=true;
	columna_inicio=0;
	golum[0]->num_sel=1;
	mueve_multigolum(0,1);
	num_movi++;
	if(ultimo_mov!=actual_mov){
		while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
			ultimo_mov=ultimo_mov->ant_mov;
			delete(ultimo_mov->sig_mov);
			ultimo_mov->sig_mov=NULL;
			}
		}
	ultimo_mov->sig_mov=new undos(ini,fin,num_movi,1,ultimo_mov,NULL,descubierta);
	ultimo_mov=ultimo_mov->sig_mov;
	actual_mov=ultimo_mov;
	carta[karta]->seleccionada=false;

	// Movemos segunda carta
	if(golum[0]->num_cartas) {
		afin=false;
		alfa=golum[0]->ultimo_valor;
		karta=alfa->carta;
		carta[karta]->seleccionada=true;
		columna_inicio=0;
		golum[0]->num_sel=1;
		mueve_multigolum(0,1);
		num_movi++;
		if(ultimo_mov!=actual_mov){
			while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
				ultimo_mov=ultimo_mov->ant_mov;
				delete(ultimo_mov->sig_mov);
				ultimo_mov->sig_mov=NULL;
				}
			}
		ultimo_mov->sig_mov=new undos(ini,fin,num_movi,1,ultimo_mov,NULL,descubierta);
		ultimo_mov=ultimo_mov->sig_mov;
		actual_mov=ultimo_mov;
		carta[karta]->seleccionada=false;
		}
	// Movemos tercera carta
	if(golum[0]->num_cartas) {
		afin=false;
		alfa=golum[0]->ultimo_valor;
		karta=alfa->carta;
		carta[karta]->seleccionada=true;
		columna_inicio=0;
		golum[0]->num_sel=1;
		mueve_multigolum(0,1);
		num_movi++;
		if(ultimo_mov!=actual_mov){
			while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
				ultimo_mov=ultimo_mov->ant_mov;
				delete(ultimo_mov->sig_mov);
				ultimo_mov->sig_mov=NULL;
				}
			}
		ultimo_mov->sig_mov=new undos(ini,fin,num_movi,1,ultimo_mov,NULL,descubierta);
		ultimo_mov=ultimo_mov->sig_mov;
		actual_mov=ultimo_mov;
		carta[karta]->seleccionada=false;
		}

	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	descubierta=false;
	return true;
	}
// Se puede colocar de una COLUMNA/PILA a COLUMNA NO VACIAS PERO TODA LA COLUMNA
else if(golum[fin]->num_cartas && 
		(ini==1 || ini==2 || golum[ini]->num_sel==golum[ini]->num_cartas) && 
	carta[carta_seleccionada]->color!=carta[golum[fin]->ultimo_valor->carta]->color &&
	(carta[carta_seleccionada]->valor==carta[golum[fin]->ultimo_valor->carta]->valor-1 ||
	(carta[carta_seleccionada]->valor==13 && carta[golum[fin]->ultimo_valor->carta]->valor==1)))
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
// Si las cartas de reserva ya estan agotadas y SOLO LA PILA!!!
// o es la carta de reserva
// NO SE ADMITEN CARTAS DE LAS COLUMNAS
else if (!golum[fin]->num_cartas && (ini==1 || ini==2))
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

//**********************************************
// Coloca cartas automaticamente de las columnas
bool canfield_sup::automatico(void)
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
	// Colocamos cartas de las columnas
	for (l=2;l<ultima_columna;l++)
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
	// Colocamos cartas de la reserva, si hay
	/*
	if (golum[2]->num_cartas)
		{
		for(int k=3;k<ultima_columna;k++)
			{
			if(!golum[k]->num_cartas)
				{
				carta_seleccionada=golum[2]->ultimo_valor->carta;
				golum[2]->num_sel=1;
				mover(2,k);
				vuelta=false;
				break;
				}
			}
		}
	*/
	// Colocamos cartas de la pila si hay
	if(!golum[1]->num_cartas)
		{
		vuelta=false;
		}
	else if(golum[1]->num_cartas && !salir)
		{
		for(r=golum[1]->num_cartas;r;r--)
			{
			alfa=golum[1]->ultimo_valor;
			columna_inicio=1;
			carta_seleccionada=alfa->carta;
			if (!colocar_carta(carta_seleccionada,1)) vuelta=false;
			else vuelta=true;
			}	
		}
	}	// Fin del while
columna_inicio=ci;
carta_seleccionada=cs;
mov_pendiente=mv;
return vuelta;
}

//*********************************************************
// Mira si la carta en cuestion cabe en alguna pila final	
	bool canfield_sup::colocar_carta(int n,int ini)
//*********************************************************
{
bool devolver=false;
int cs=carta_seleccionada;
int ci=ini;
if(carta[n]->valor==valor_base)	//COLOCACION DE VALOR BASE
	{
	for(int g=ultima_columna;g<num_golum;g++)
		{
		if (!golum[g]->num_cartas)
			{
			afin=true;
			carta[n]->seleccionada=true;
			golum[ini]->num_sel=1;
			mueve_multigolum(ini,g);
			carta[n]->seleccionada=false;
			golum[ini]->num_sel=0;
			if(!carta[golum[ini]->ultimo_valor->carta]->mostrada)
				carta[golum[ini]->ultimo_valor->carta]->mostrada=true;
			if(ultimo_mov!=actual_mov){
				while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
					ultimo_mov=ultimo_mov->ant_mov;
					delete(ultimo_mov->sig_mov);
					ultimo_mov->sig_mov=NULL;
					}
				}
			ultimo_mov->sig_mov=new undos(ini,g,1,1,ultimo_mov,NULL,descubierta);
			if(descubierta)
				carta_seleccionada=NOCARTA;
			ultimo_mov=ultimo_mov->sig_mov;
			actual_mov=ultimo_mov;
			if (activar_sonido && sonido_colocar->IsOk())	sonido_colocar->Play(wxSOUND_ASYNC);
			devolver=true;cartas_colocadas++;
			num_mov++;descubierta=false;if(esperar) {esperar=false;}//juego_automatico=true;}
			ci=columna_inicio=columna_final=NOCOL;cs=carta_seleccionada=NOCARTA;
			break;
			}
		}
	}
else
	{
	for(int g=ultima_columna;g<num_golum;g++)	//COLOCACION DE LAS OTRAS CARTAS
		{
		if (golum[g]->num_cartas && carta[n]->tipo==carta[golum[g]->ultimo_valor->carta]->tipo &&
			(carta[n]->valor==carta[golum[g]->ultimo_valor->carta]->valor+1 ||
			 (carta[n]->valor==1 && carta[golum[g]->ultimo_valor->carta]->valor==13)))
			{
			afin=true;
			carta[n]->seleccionada=true;
			golum[ini]->num_sel=1;
			mueve_multigolum(ini,g);
			carta[n]->seleccionada=false;
			golum[ini]->num_sel=0;
			if(!carta[golum[ini]->ultimo_valor->carta]->mostrada)
				carta[golum[ini]->ultimo_valor->carta]->mostrada=true;
			if(ultimo_mov!=actual_mov){
				while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
					ultimo_mov=ultimo_mov->ant_mov;
					delete(ultimo_mov->sig_mov);
					ultimo_mov->sig_mov=NULL;
					}
				}
			ultimo_mov->sig_mov=new undos(ini,g,1,1,ultimo_mov,NULL,descubierta);
			ultimo_mov=ultimo_mov->sig_mov;
			actual_mov=ultimo_mov;
			devolver=true;cartas_colocadas++;descubierta=false;
			if (activar_sonido && sonido_colocar->IsOk())	sonido_colocar->Play(wxSOUND_ASYNC);
			num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
			ci=columna_inicio=columna_final=NOCOL;cs=carta_seleccionada=NOCARTA;
			break;
			}
		}
	}
return devolver;
}

//*********************************************************************//
// Busca automaticamente un sitio para la carta seleccionada o agarrada
	void canfield_sup::busca_sitio(void)
//*********************************************************************//
{
lista *alfa;
bool colocada=false;
int cs=carta_seleccionada;
int ci=columna_inicio;
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
		colocada=true;
		}
	else // EL JUGADOR INTENTA COLOCAR EN UNA COLUMNA DETERMINADA
		{	// LA PILA NO ESTA PERMITIDA NI LA COLUMNA DE RESERVA
		for(int k=3;k<ultima_columna;k++) 
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
					colocada=true;
					break;
					}
				else
					{
					carta_seleccionada=cs;
					columna_inicio=ci;
					}
				}
			}	// Fin del for
		}
	}
// Si el juego automatico esta activado
// mira si se puede colocar en columnas finales
if(!juego_automatico && !colocada &&
    golum[columna_inicio]->ultimo_valor->carta==carta_seleccionada)
	if(colocar_carta(carta_seleccionada,columna_inicio) && !colocada)	// Si se ha colocado la carta volvemos
		{
		colocada=true;
		}
// Buscamos sitio en columnas ocupadas
if(!colocada)
	{
	for(int k=3;k<ultima_columna;k++)
		{
		if(golum[k]->num_cartas)
			{
			if(mover(columna_inicio,k)) {
				colocada=true;break;
			}
			else {carta_seleccionada=cs;columna_inicio=ci;}
			}
		}
	}
// Ahora buscamos sitio en huecos libres ya que no esta colocada
if(!colocada)
{
	for(int k=3;k<ultima_columna;k++)
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
	// Este no es su sitio. Hay que hacerlo para multiples cartas
	xf=golum[ci]->x+golum[ci]->desp_x*(golum[ci]->num_cartas-golum[ci]->num_sel);
	yf=golum[ci]->y+golum[ci]->desp_y*(golum[ci]->num_cartas-golum[ci]->num_sel);
	zf=golum[ci]->z+golum[ci]->desp_z*(golum[ci]->num_cartas-golum[ci]->num_sel);
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
recolocar();
}
