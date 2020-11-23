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
// canfield.cpp: implementation of the canfield class.
//
//////////////////////////////////////////////////////////////////////

#include "wx_defines.h"
#include <wx/defs.h>

#include <wx/sound.h>
#include <wx/string.h>

#include "canfield.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

canfield::canfield()
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
golum[ 0]=new Ccolumna(-0.12f,0.4f,-1.2f,0,true,0,0.0000015f,0.0000015f,0.00015f,MAZO_SI,0);
// LA "COLUMNA" PILA
golum[ 1]=new Ccolumna(-0.f,0.4f,-1.2f,1,true,0,0.0000015f,0.0000015f,0.00015f,MAZO_NO,0);
// LA COLUMNA RESERVA (Tiene 13 cartas)
golum[ 2]=new Ccolumna(-0.30f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,MAZO_NO,0);
// LAS COLUMNAS (4)
golum[ 3]=new Ccolumna(-0.12f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 4]=new Ccolumna( 0.f,  0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 5]=new Ccolumna( 0.12f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 6]=new Ccolumna( 0.24f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
// LAS FINALES (4)
golum[ 7]=new Ccolumna( 0.27f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_G,0);
golum[ 8]=new Ccolumna( 0.36f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_G,0);
golum[ 9]=new Ccolumna( 0.45f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_G,0);
golum[10]=new Ccolumna( 0.54f, 0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_G,0);
// LAS NO UTILIZABLES
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

num_golum=11;	// Siempre es una mas
mazo_juego=52;
ultima_columna=7;	// Una mas. Son las columnas seleccionables
juego_automatico=false;
tipo_juego=CANFIELD;
mover_permitido=true;
automatico_permitido=true;
valor_base=0;
posX=0.041f;
posY=-0.306f;
posZ=-0.261f;
viewX=0.041f;
viewY=0.12f;
viewZ=-1.4f;
vectorX=0.f;
vectorY=1.f;
vectorZ=0.f;
}

canfield::~canfield()
{

}

void canfield::repetir_juego()
{
game::repetir_juego();
mazo_juego=52;juego_automatico=false;
golum[7]->textura=FINAL_G;golum[8]->textura=FINAL_G;
golum[9]->textura=FINAL_G;golum[10]->textura=FINAL_G;
valor_base=0;
}

void canfield::fase_presentacion()
{
mueve_colum_reparto(0,7,true);valor_base=carta[golum[7]->ultimo_valor->carta]->valor;
cartas_colocadas++;
switch(valor_base)
	{
	case 1:
	golum[7]->textura=FINAL;golum[8]->textura=FINAL;
	golum[9]->textura=FINAL;golum[10]->textura=FINAL;
	break;
	case 2:
	golum[7]->textura=FINAL_2;golum[8]->textura=FINAL_2;
	golum[9]->textura=FINAL_2;golum[10]->textura=FINAL_2;
	break;
	case 3:
	golum[7]->textura=FINAL_3;golum[8]->textura=FINAL_3;
	golum[9]->textura=FINAL_3;golum[10]->textura=FINAL_3;
	break;
	case 4:
	golum[7]->textura=FINAL_4;golum[8]->textura=FINAL_4;
	golum[9]->textura=FINAL_4;golum[10]->textura=FINAL_4;
	break;
	case 5:
	golum[7]->textura=FINAL_5;golum[8]->textura=FINAL_5;
	golum[9]->textura=FINAL_5;golum[10]->textura=FINAL_5;
	break;
	case 6:
	golum[7]->textura=FINAL_6;golum[8]->textura=FINAL_6;
	golum[9]->textura=FINAL_6;golum[10]->textura=FINAL_6;
	break;
	case 7:
	golum[7]->textura=FINAL_7;golum[8]->textura=FINAL_7;
	golum[9]->textura=FINAL_7;golum[10]->textura=FINAL_7;
	break;
	case 8:
	golum[7]->textura=FINAL_8;golum[8]->textura=FINAL_8;
	golum[9]->textura=FINAL_8;golum[10]->textura=FINAL_8;
	break;
	case 9:
	golum[7]->textura=FINAL_9;golum[8]->textura=FINAL_9;
	golum[9]->textura=FINAL_9;golum[10]->textura=FINAL_9;
	break;
	case 10:
	golum[7]->textura=FINAL_10;golum[8]->textura=FINAL_10;
	golum[9]->textura=FINAL_10;golum[10]->textura=FINAL_10;
	break;
	case 11:
	golum[7]->textura=FINAL_J;golum[8]->textura=FINAL_J;
	golum[9]->textura=FINAL_J;golum[10]->textura=FINAL_J;
	break;
	case 12:
	golum[7]->textura=FINAL_Q;golum[8]->textura=FINAL_Q;
	golum[9]->textura=FINAL_Q;golum[10]->textura=FINAL_Q;
	break;
	case 13:
	golum[7]->textura=FINAL_K;golum[8]->textura=FINAL_K;
	golum[9]->textura=FINAL_K;golum[10]->textura=FINAL_K;
	break;
	}
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);
mueve_colum_reparto(0,2,true);
mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);
FASE_PRESENTACION=false;
}

//*****************************************************//
// Devuelve TRUE si la carta es seleccionable
// segun las reglas del juego
bool canfield::es_seleccionable(int cc,int c)
//****************************************************//
{
lista *alfa=NULL;
int b=0;
int karta_anterior=cc;
golum[c]->num_sel=0;
carta[cc]->seleccionada=true;
// LA PILA DE RESERVA, SI HAY CARTAS
if(c==2 && golum[2]->num_cartas)
	{
	if(cc==golum[2]->ultimo_valor->carta)
		{
		carta[cc]->seleccionada=true;
		golum[c]->num_sel=1;
		return true;
		}
	else{
		carta[cc]->seleccionada=false;
		golum[c]->num_sel=0;
		return false;
		}
	}
// Vamos al principio de la golum
alfa=golum[c]->primer_valor->sig;
// Vemos donde hemos pinchado
// SOLO SE ADMITE PASAR COLUMNAS ENTERAS !!!
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
		if(carta[alfa->carta]->color==carta[karta_anterior]->color &&
		   carta[alfa->carta]->valor!=carta[karta_anterior]->valor-1)
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
		else
			{
			carta[alfa->carta]->seleccionada=true;golum[c]->num_sel++;
			karta_anterior=alfa->carta;
			}
		}
	}
return true;	// Realmente aqui nunca llega
}


//******************************************//
// Identifica la carta que se ha pinchado
int canfield::que_carta_es(int cc)
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
//if(cc==1 && !golum[0]->num_cartas && !golum[1]->num_cartas)
//	golum[0]->textura=MAZO_NO;	// No hay cartas en la pila que pasar

if(cc==1 && !golum[0]->num_cartas)	// MAZO RECICLABLE
	{
	int n=golum[1]->num_cartas;
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
else if(cc==1 && !golum[0]->num_cartas)	// Es la ultima carta de la pila que ahora
	{									// tiene seleccion 1!!!
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

if(cc>199 && cc<ultima_columna*100)	// COLUMNAS DESDE LA 2
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


//*********************************************************
// Mira si la carta en cuestion cabe en alguna pila final	
	bool canfield::colocar_carta(int n,int ini)
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
// Colocamos cartas de la reserva, si hay
if (golum[2]->num_cartas && carta_seleccionada==NOCARTA)
	{
	for(int k=3;k<ultima_columna;k++)
		{
		if(!golum[k]->num_cartas)
			{
			carta_seleccionada=golum[2]->ultimo_valor->carta;
			golum[2]->num_sel=1;
			mover(2,k);
			golum[2]->num_sel=0;
			carta_seleccionada=NOCARTA;columna_inicio=NOCOL;
			devolver=true;
			break;
			}
		}
	}
return devolver;
}

//************************************//
// Mueve de una columna a otra efectivamente
// si se verifican las reglas del juego
bool canfield::mover(int ini, int fin)
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
else if (!golum[fin]->num_cartas && ((!golum[2]->num_cartas && ini==1) || ini==2))
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
	void canfield::busca_sitio(void)
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
// Colocamos cartas de la reserva, si hay y se puede
if (golum[2]->num_cartas && carta_seleccionada==NOCARTA)
	{
	for(int k=3;k<ultima_columna;k++)
		{
		if(!golum[k]->num_cartas)
			{
			carta_seleccionada=golum[2]->ultimo_valor->carta;
			golum[2]->num_sel=1;
			mover(2,k);
			golum[2]->num_sel=0;
			carta_seleccionada=NOCARTA;columna_inicio=NOCOL;
			break;
			}
		}
	}
}

//**************************************//
// Busca automaticamente un sitio para la carta de la pila
void canfield::busca_sitio_boton_derecho()
//**************************************//
{
bool colocada=false;
int cs=NOCARTA;
mov_pendiente=true;
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
		for(int k=3;k<ultima_columna;k++)
			{
			if(golum[k]->num_cartas && mover(1,k)) {
				colocada=true;break;
				}
			}
		}
	if(juego_automatico && mov_pendiente && !colocada)	// Es una carta que debe volver a su sitio
		{
		columna_inicio=1;afin=false;
		float x=golum[1]->x+golum[1]->desp_x*(golum[1]->num_cartas-1);
		float y=golum[1]->y+golum[1]->desp_y*(golum[1]->num_cartas-1);
		float z=golum[1]->z+golum[1]->desp_z*(golum[1]->num_cartas-1);
		movimiento(x,y,z,carta_seleccionada);
		}
	}
golum[1]->num_sel=0;
carta[cs]->seleccionada=false;
carta_seleccionada=NOCARTA;columna_inicio=NOCOL;mov_pendiente=false;
}

//**********************************************
// Coloca cartas automaticamente de las columnas
	bool canfield::automatico(void)
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
