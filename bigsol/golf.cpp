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
// golf.cpp: implementation of the golf class.
//
//////////////////////////////////////////////////////////////////////

#include "wx_defines.h"
#include <wx/defs.h>

#include <wx/sound.h>
#include <wx/string.h>

#include "golf.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

golf::golf()
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
golum[0]=new Ccolumna(0.0f,0.4f,-1.2f,0,true,0,0.0000015f,0.0000015f,0.00015f,MAZO_NO,0);
// LA "COLUMNA" PILA AHORA ES FINAL
golum[1]=new Ccolumna(0.f,-0.3f,-1.2f,1,true,0,0.00025f,0.00025f,0.0002f,FINAL_G,0);
// LAS COLUMNAS
golum[ 2]=new Ccolumna(-0.36f,0.2f,-1.2f,2,true,0,0.f,-0.05f,0.0001f,MAZO_NO,0);
golum[ 3]=new Ccolumna(-0.24f,0.2f,-1.2f,2,true,0,0.f,-0.05f,0.0001f,MAZO_NO,0);
golum[ 4]=new Ccolumna(-0.12f,0.2f,-1.2f,2,true,0,0.f,-0.05f,0.0001f,MAZO_NO,0);
golum[ 5]=new Ccolumna( 0.00f,0.2f,-1.2f,2,true,0,0.f,-0.05f,0.0001f,MAZO_NO,0);
golum[ 6]=new Ccolumna( 0.12f,0.2f,-1.2f,2,true,0,0.f,-0.05f,0.0001f,MAZO_NO,0);
golum[ 7]=new Ccolumna( 0.24f,0.2f,-1.2f,2,true,0,0.f,-0.05f,0.0001f,MAZO_NO,0);
golum[ 8]=new Ccolumna( 0.36f,0.2f,-1.2f,2,true,0,0.f,-0.05f,0.0001f,MAZO_NO,0);
// LAS NO UTILIZABLES
golum[ 9]=new Ccolumna( 0.f,-0.4f,-1.2f,4,false,0,0.00025f,0.00025f,0.005f,FINAL,0);
golum[10]=new Ccolumna( 0.275f,0.2f,-1.2f,4,false,0,0.f,-0.03f,0.001f,HUECO,0);
golum[11]=new Ccolumna( 0.385f,0.2f,-1.2f,4,false,0,0.f,-0.03f,0.001f,HUECO,0);
golum[12]=new Ccolumna( 0.495f,0.2f,-1.2f,4,false,0,0.f,-0.03f,0.001f,HUECO,0);
golum[13]=new Ccolumna( 0.605f,0.2f,-1.2f,4,false,0,0.f,-0.03f,0.001f,HUECO,0);
golum[14]=new Ccolumna(-0.605f,-0.6f,-1.7f,4,false,0,0.00025f,0.00025f,0.005f,FINAL,0);
golum[15]=new Ccolumna(-0.495f,-0.6f,-1.7f,4,false,0,0.00025f,0.00025f,0.005f,FINAL,0);
golum[16]=new Ccolumna(-0.385f,-0.6f,-1.7f,4,false,0,0.00025f,0.00025f,0.005f,FINAL,0);
golum[17]=new Ccolumna(-0.275f,-0.6f,-1.7f,4,false,0,0.00025f,0.00025f,0.005f,FINAL,0);
golum[18]=new Ccolumna(-0.165f,-0.6f,-1.7f,4,false,0,0.00025f,0.00025f,0.005f,FINAL,0);
golum[19]=new Ccolumna(-0.055f,-0.6f,-1.7f,4,false,0,0.00025f,0.00025f,0.005f,FINAL,0);
golum[20]=new Ccolumna( 0.055f,-0.6f,-1.7f,4,false,0,0.00025f,0.00025f,0.005f,FINAL,0);
golum[21]=new Ccolumna( 0.165f,-0.6f,-1.7f,4,false,0,0.00025f,0.00025f,0.005f,FINAL,0);
golum[22]=new Ccolumna( 0.275f,-0.6f,-1.7f,4,false,0,0.00025f,0.00025f,0.005f,FINAL,0);
golum[23]=new Ccolumna( 0.385f,-0.6f,-1.7f,4,false,0,0.00025f,0.00025f,0.005f,FINAL,0);
golum[24]=new Ccolumna( 0.495f,-0.6f,-1.7f,4,false,0,0.00025f,0.00025f,0.005f,FINAL,0);
golum[25]=new Ccolumna( 0.605f,-0.6f,-1.7f,4,false,0,0.00025f,0.00025f,0.005f,FINAL,0);
golum[26]=new Ccolumna( 0.605f,-0.6f,-1.7f,4,false,0,0.00025f,0.00025f,0.005f,FINAL,0);
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

num_golum=9;
mazo_juego=52;
ultima_columna=9;
juego_automatico=false;
tipo_juego=GOLF;
automatico_permitido=false;
posX  =  0.f;
posY  = -0.37f;
posZ  = -0.2196f;
viewX =  0.f;
viewY =  0.056f;
viewZ = -1.3596f;
}

golf::~golf()
{

}

void golf::fase_presentacion()
{
// PRIMERA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);
// SEGUNDA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);
// TERCERA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);
// CUARTA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);
// QUINTA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);
// LA PRIMERA DE LA PILA
mueve_colum_reparto(0,1,true);cartas_colocadas=1;
FASE_PRESENTACION=false;
}

void golf::repetir_juego()
{
game::repetir_juego();
mazo_juego=52;juego_automatico=false;
}

//*******************************************//
// Mueve de una columna a otra efectivamente
// si se verifican las reglas del juego
bool golf::mover(int ini, int fin)
//*******************************************//
{
// Del MAZO a la PILA
if(ini==0 && fin==1){
	afin=true;
	carta_seleccionada=golum[ini]->ultimo_valor->carta;
	carta[golum[ini]->ultimo_valor->carta]->seleccionada=false;
	golum[ini]->num_sel=1;
	columna_inicio=ini;
	mueve_multigolum(ini,fin);
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
	cartas_colocadas++;
	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	return true;
	}	
return false;
}

//*********************************************************
// Mira si la carta en cuestion cabe en alguna pila final	
	bool golf::colocar_carta(int n,int ini)
//*********************************************************
{
bool devolver=false;
if (carta[n]->valor!=1 &&
	(carta[n]->valor==carta[golum[1]->ultimo_valor->carta]->valor+1
	|| carta[n]->valor==carta[golum[1]->ultimo_valor->carta]->valor-1))
	{
	afin=true;
	columna_inicio=ini;
	carta[n]->seleccionada=true;
	mueve_multigolum(ini,1);
	if(ultimo_mov!=actual_mov){
		while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
			ultimo_mov=ultimo_mov->ant_mov;
			delete(ultimo_mov->sig_mov);
			ultimo_mov->sig_mov=NULL;
			}
		}
	ultimo_mov->sig_mov=new undos(ini,1,1,1,ultimo_mov,NULL,false);
	ultimo_mov=ultimo_mov->sig_mov;
	actual_mov=ultimo_mov;
	devolver=true;cartas_colocadas++;
	if (activar_sonido && sonido_colocar->IsOk())	sonido_colocar->Play(wxSOUND_ASYNC);
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	}
else if (carta[n]->valor==1 &&
	     carta[n]->valor==carta[golum[1]->ultimo_valor->carta]->valor-1)
	{
	afin=true;
	columna_inicio=ini;
	carta[n]->seleccionada=true;
	mueve_multigolum(ini,1);
	if(ultimo_mov!=actual_mov){
		while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
			ultimo_mov=ultimo_mov->ant_mov;
			delete(ultimo_mov->sig_mov);
			ultimo_mov->sig_mov=NULL;
			}
		}
	ultimo_mov->sig_mov=new undos(ini,1,1,1,ultimo_mov,NULL,false);
	ultimo_mov=ultimo_mov->sig_mov;
	actual_mov=ultimo_mov;
	devolver=true;cartas_colocadas++;
	if (activar_sonido && sonido_colocar->IsOk())	sonido_colocar->Play(wxSOUND_ASYNC);
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	}
return devolver;
}

//*********************************************************************//
// Busca automaticamente un sitio para la carta seleccionada o agarrada
	void golf::busca_sitio(void)
//*********************************************************************//
{
bool colocada=false;
int cs=carta_seleccionada;
int ci=columna_inicio;
bool mv=mov_pendiente;
mov_pendiente=true;
// Si el juego automatico esta activado
// mira si se puede colocar en columnas finales
if(!juego_automatico && !colocada)
	if(colocar_carta(carta_seleccionada,columna_inicio) && !colocada)	// Si se ha colocado la carta volvemos
		{
		colocada=true;
		}
// Es una carta que debe volver a su sitio
if(mov_pendiente && !colocada)
	{
	columna_inicio=ci;afin=false;
	carta_seleccionada=cs;
	float x=golum[columna_inicio]->x+golum[columna_inicio]->desp_x*(golum[columna_inicio]->num_cartas-1);
	float y=golum[columna_inicio]->y+golum[columna_inicio]->desp_y*(golum[columna_inicio]->num_cartas-1);
	float z=golum[columna_inicio]->z+golum[columna_inicio]->desp_z*(golum[columna_inicio]->num_cartas-1);
	movimiento(x,y,z,cs);
	}
carta[cs]->seleccionada=false;
carta_seleccionada=NOCARTA;columna_inicio=NOCOL;mov_pendiente=mv;
}

//**************************************//
// Busca automaticamente un sitio para la carta de la pila
	void golf::busca_sitio_boton_derecho()
//**************************************//
{
// Sacamos carta del MAZO si hay claro
if(golum[0]->num_cartas) mover(0,1);
}

//***********************************//
void golf::mover_a_columna(int cc)
//***********************************//
{
//int karta=NOCARTA;
if(cc==1 && golum[0]->num_cartas)	// MAZO
	{
	carta[carta_seleccionada]->seleccionada=false;
	columna_inicio=NOCOL;
	mover(0,1);
	}
else if(cc==1 && !golum[0]->num_cartas)	// Es la ultima carta de la pila que ahora
	{									// tiene seleccion 1!!!
	colocar_carta(carta_seleccionada,columna_inicio);
	}
if(cc==2)	// PILA
	{
	colocar_carta(carta_seleccionada,columna_inicio);
	}
carta[carta_seleccionada]->seleccionada=false;
carta_seleccionada=NOCARTA;columna_inicio=columna_final=NOCOL;
}

//******************************************//
// Identifica la carta que se ha pinchado
int golf::que_carta_es(int cc)
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
		if (es_seleccionable(karta,c)) {// Cumple reglas de seleccion??
			if(columna_inicio==NOCOL) columna_inicio=c;
			else columna_final=c;
			carta[karta]->seleccionada=true;
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
