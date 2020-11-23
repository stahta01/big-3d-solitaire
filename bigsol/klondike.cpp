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
// klondike.cpp: implementation of the klondike class.
//
//////////////////////////////////////////////////////////////////////

#include "klondike.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

klondike::klondike()
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
golum[0]=new Ccolumna(-0.36f,0.4f,-1.2f,0,true,0,0.0000015f,0.0000015f,0.00015f,MAZO_SI,0);
// LA "COLUMNA" PILA
golum[1]=new Ccolumna(-0.24f,0.4f,-1.2f,1,true,0,0.0170f,0.f,0.00005f,MAZO_NO,0);
// LAS COLUMNAS (7)
golum[ 2]=new Ccolumna(-0.36f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO_K,0);
golum[ 3]=new Ccolumna(-0.24f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO_K,0);
golum[ 4]=new Ccolumna(-0.12f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO_K,0);
golum[ 5]=new Ccolumna( 0.00f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO_K,0);
golum[ 6]=new Ccolumna( 0.12f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO_K,0);
golum[ 7]=new Ccolumna( 0.24f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO_K,0);
golum[ 8]=new Ccolumna( 0.36f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO_K,0);
// LAS FINALES (4)
golum[ 9]=new Ccolumna(0.55f, 0.08f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
golum[10]=new Ccolumna(0.55f,-0.06f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
golum[11]=new Ccolumna(0.55f,-0.20f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
golum[12]=new Ccolumna(0.55f,-0.34f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
// LAS NO UTILIZABLES
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
golum[36]=new Ccolumna( 0.605f,-0.55f,-1.2f,4,false,0,0.0008f,-0.03f,0.0008f,FINAL,0);

num_golum=13;	// Siempre es una mas: de la 0 a la 12 => 13
mazo_juego=52;
ultima_columna=9;	// Una mas. Son las columnas seleccionables
juego_automatico=true;
tipo_juego=KLONDIKE;
mover_permitido=true;
automatico_permitido=true;
posX=0.f;
posY=-0.442f;
posZ=-0.133f;
viewX=0.f;
viewY=-0.016f;
viewZ=-1.273f;
vectorX=0.f;
vectorY=1.f;
vectorZ=0.f;
}

klondike::~klondike()
{

}

void klondike::fase_presentacion()
{
mueve_colum_reparto(0,2,true);
mueve_colum_reparto(0,3,false);mueve_colum_reparto(0,3,true);
mueve_colum_reparto(0,4,false);mueve_colum_reparto(0,4,false);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,false);mueve_colum_reparto(0,5,false);
mueve_colum_reparto(0,5,false);mueve_colum_reparto(0,5,true);
mueve_colum_reparto(0,6,false);mueve_colum_reparto(0,6,false);
mueve_colum_reparto(0,6,false);mueve_colum_reparto(0,6,false);mueve_colum_reparto(0,6,true);
mueve_colum_reparto(0,7,false);mueve_colum_reparto(0,7,false);
mueve_colum_reparto(0,7,false);mueve_colum_reparto(0,7,false);
mueve_colum_reparto(0,7,false);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,false);mueve_colum_reparto(0,8,false);
mueve_colum_reparto(0,8,false);mueve_colum_reparto(0,8,false);
mueve_colum_reparto(0,8,false);mueve_colum_reparto(0,8,false);mueve_colum_reparto(0,8,true);
FASE_PRESENTACION=false;
}

void klondike::repetir_juego()
{
game::repetir_juego();
mazo_juego=52;juego_automatico=true;
}

//*****************************************************//
// Devuelve TRUE si la carta es seleccionable
// segun las reglas del juego
bool klondike::es_seleccionable(int cc,int c)
//****************************************************//
{
lista *alfa=NULL;
int b=0;
int karta_anterior=cc;
golum[c]->num_sel=0;
carta[cc]->seleccionada=true;
// Si esta ocultada pero hemos pinchado la ultima la descubrimos
// No es necesario: ya automaticamente se pone mostrada al quedar liberada la columna
//if(!carta[cc]->mostrada && c>1 && golum[c]->ultimo_valor->carta==cc)
//	{
//	carta[cc]->mostrada=true;golum[c]->num_sel++;return true;
//	}
// Si esta ocultada devolvemos false
if(!carta[cc]->mostrada) {carta[cc]->seleccionada=false;golum[c]->num_sel=0;return false;}

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

//************************************//
// Mueve de una columna a otra efectivamente
// si se verifican las reglas del juego
bool klondike::mover(int ini, int fin)
//***********************************//
{
int num_movi=0;
lista *alfa=NULL;
int karta=NOCARTA;
// Del MAZO a la PILA
if(ini==0 && fin==1){
	if(tipo_juego==KLONDIKE3){
		// DAMOS TRES CARTAS
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
	}else{	
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
	}
	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	descubierta=false;
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

//*********************************************************
// Mira si la carta en cuestion cabe en alguna pila final	
	bool klondike::colocar_carta(int n,int ini)
//*********************************************************
{
bool devolver=false;
if(carta[n]->valor==1)	//COLOCACION DE ASES
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
			columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
			break;
			}
		}
	}
else
	{
	for(int g=ultima_columna;g<num_golum;g++)	//COLOCACION DE LAS OTRAS CARTAS
		{
		if (carta[n]->valor==carta[golum[g]->ultimo_valor->carta]->valor+1 &&
			carta[n]->tipo==carta[golum[g]->ultimo_valor->carta]->tipo &&
			golum[g]->num_cartas)
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
			columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
			break;
			}
		}
	}
return devolver;
}

//******************************************//
// Identifica la carta que se ha pinchado
int klondike::que_carta_es(int cc)
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
//if(cc==1 && !golum[0]->num_cartas && golum[0]->textura==MAZO_SI && !golum[1]->num_cartas)
//	golum[0]->textura=MAZO_NO;	// No hay cartas en la pila que pasar

if(cc==1 && !golum[0]->num_cartas && golum[0]->textura==MAZO_SI)	// MAZO RECICLABLE UN SOLO PASO
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

//**********************************************
// Recoloca cartas de las columnas
	void klondike::recolocar(void)
//**********************************************
{
// Recoloca las cartas de las golums para que quepan
// AL LORO PORQUE SI EL AUTOMATICO NO ESTA ACTIVADO NO SE RECOLOCAN CARTAS !!
if(tipo_juego==LUCKY) return;
lista *alfa=NULL;
for(int k=2;k<ultima_columna;k++)
	{
	// Recolocamos golums en y
	if(golum[k]->num_cartas && golum[k]->num_cartas<17 && golum[k]->desp_y!=-0.03f)
		{
		golum[k]->desp_y=golum[36]->desp_y;
		alfa=golum[k]->primer_valor->sig;
		for(int m=0;m<golum[k]->num_cartas;m++)
			{
			carta[alfa->carta]->y=golum[k]->y+golum[k]->desp_y*m;
			alfa=alfa->sig;
			}
		}
	else if(golum[k]->num_cartas>16)
		{
		golum[k]->desp_y=-0.60f/(float)(golum[k]->num_cartas-1);
		alfa=golum[k]->primer_valor->sig;
		for(int m=0;m<golum[k]->num_cartas;m++)
			{
			carta[alfa->carta]->y=golum[k]->y+golum[k]->desp_y*m;
			alfa=alfa->sig;
			}
		}
	}
}
