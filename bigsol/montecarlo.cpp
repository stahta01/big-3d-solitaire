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
// montecarlo.cpp: implementation of the montecarlo class.
//
//////////////////////////////////////////////////////////////////////

#include "wx_defines.h"
#include <wx/defs.h>

#include <wx/sound.h>
#include <wx/string.h>

#include "montecarlo.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

montecarlo::montecarlo()
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
// ESTAMOS PARA 40 LADRONES 3 MAZOS
// LA COLUMNA MAZO la columna[0],fila[0]
golum[0]=new Ccolumna(-0.42f,0.f,-1.2f,0,true,0,0.0000015f,0.0000015f,0.00015f,MAZO_SI,0);
// LA "COLUMNA" PILA AHORA ES FINAL
golum[1]=new Ccolumna(0.42f,0.f,-1.2f,1,true,0,0.00025f,0.00025f,0.0002f,FINAL_G,0);
// LAS COLUMNAS. CONTIENEN UNA CARTA CADA UNA Y SOLO UNA CARTA
golum[ 2]=new Ccolumna(-0.24f,0.34f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[ 3]=new Ccolumna(-0.12f,0.34f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[ 4]=new Ccolumna( 0.00f,0.34f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[ 5]=new Ccolumna( 0.12f,0.34f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[ 6]=new Ccolumna( 0.24f,0.34f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);

golum[ 7]=new Ccolumna(-0.24f,0.17f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[ 8]=new Ccolumna(-0.12f,0.17f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[ 9]=new Ccolumna( 0.00f,0.17f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[10]=new Ccolumna( 0.12f,0.17f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[11]=new Ccolumna( 0.24f,0.17f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);

golum[12]=new Ccolumna(-0.24f,0.0f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[13]=new Ccolumna(-0.12f,0.0f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[14]=new Ccolumna( 0.00f,0.0f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[15]=new Ccolumna( 0.12f,0.0f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[16]=new Ccolumna( 0.24f,0.0f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);

golum[17]=new Ccolumna(-0.24f,-0.17f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[18]=new Ccolumna(-0.12f,-0.17f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[19]=new Ccolumna( 0.00f,-0.17f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[20]=new Ccolumna( 0.12f,-0.17f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[21]=new Ccolumna( 0.24f,-0.17f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);

golum[22]=new Ccolumna(-0.24f,-0.34f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[23]=new Ccolumna(-0.12f,-0.34f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[24]=new Ccolumna( 0.00f,-0.34f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[25]=new Ccolumna( 0.12f,-0.34f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);
golum[26]=new Ccolumna( 0.24f,-0.34f,-1.2f,2,true,0,0.f,0.f,0.0f,HUECO,0);

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

num_golum=27;
mazo_juego=52;
ultima_columna=27;
juego_automatico=false;
tipo_juego=DOUBLES;
mover_permitido=false;
automatico_permitido=false;
}

montecarlo::~montecarlo()
{

}

void montecarlo::fase_presentacion()
{
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);
mueve_colum_reparto(0,7,true);mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);
mueve_colum_reparto(0,10,true);mueve_colum_reparto(0,11,true);
mueve_colum_reparto(0,12,true);mueve_colum_reparto(0,13,true);mueve_colum_reparto(0,14,true);
mueve_colum_reparto(0,15,true);mueve_colum_reparto(0,16,true);
mueve_colum_reparto(0,17,true);mueve_colum_reparto(0,18,true);mueve_colum_reparto(0,19,true);
mueve_colum_reparto(0,20,true);mueve_colum_reparto(0,21,true);
mueve_colum_reparto(0,22,true);mueve_colum_reparto(0,23,true);mueve_colum_reparto(0,24,true);
mueve_colum_reparto(0,25,true);mueve_colum_reparto(0,26,true);

FASE_PRESENTACION=false;
}

void montecarlo::repetir_juego()
{
game::repetir_juego();
mazo_juego=52;
juego_automatico=false;
mover_permitido=false;
automatico_permitido=false;
}

//*******************************************//
// Mueve de una columna a otra efectivamente
// si se verifican las reglas del juego
bool montecarlo::mover(int ini, int fin)
//*******************************************//
{
// Reordenar COLUMNAS y del MAZO a las COLUMNAS LIBRES INFERIORES
// Reordenacion
// Buscamos primer golum libre y luego la primera carta tras el hueco
// Repetimos iteracion
bool hay=true;
int cuantas=1;
bool hubo_mov=false;
while(hay)
	{
	for(int k=2;k<num_golum;k++) {
		if(!golum[k]->num_cartas) {
			columna_final=k;
			hay=true;
			break;
			}
		else hay=false;
		}
		if (hay) {
			hay=false;
			for(int k=columna_final;k<num_golum;k++) {// Buscamos la primera carta tras el hueco
				if(golum[k]->num_cartas) {
					columna_inicio=k;
					hay=true;
					break;
					}
				else {
					hay=false;
					columna_inicio=NOCOL;
					}
				}
			}
		if(hay) {
			golum[columna_inicio]->num_sel=1;
			carta[golum[columna_inicio]->ultimo_valor->carta]->seleccionada=true;
			carta_seleccionada=golum[columna_inicio]->ultimo_valor->carta;
			mueve_golum(columna_inicio,columna_final);
			golum[columna_inicio]->num_sel=0;
			carta[golum[columna_inicio]->ultimo_valor->carta]->seleccionada=false;
			if(ultimo_mov!=actual_mov){
				while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
					ultimo_mov=ultimo_mov->ant_mov;
					delete(ultimo_mov->sig_mov);
					ultimo_mov->sig_mov=NULL;
					}
				}
			ultimo_mov->sig_mov=new undos(columna_inicio,columna_final,cuantas,1,ultimo_mov,NULL,false);
			ultimo_mov=ultimo_mov->sig_mov;
			actual_mov=ultimo_mov;cuantas++;hubo_mov=true;
			}
	}	// Fin del WHILE
// Rellenamos espacios vacios con cartas del mazo
for(int k=2;k<27;k++) {
	if(!golum[k]->num_cartas && golum[0]->num_cartas) {
		mueve_golum(0,k);
		if(ultimo_mov!=actual_mov){
			while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
				ultimo_mov=ultimo_mov->ant_mov;
				delete(ultimo_mov->sig_mov);
				ultimo_mov->sig_mov=NULL;
				}
			}
		ultimo_mov->sig_mov=new undos(0,k,cuantas,1,ultimo_mov,NULL,false);
		ultimo_mov=ultimo_mov->sig_mov;
		actual_mov=ultimo_mov;cuantas++;hubo_mov=true;
		}
	}
if(hubo_mov) num_mov++;
return false;
}

//*********************************************************
// Mira si la carta en cuestion cabe en alguna pila final	
	bool montecarlo::colocar_carta(int n,int ini)
//*********************************************************
{
int fin=columna_final;
int cs=carta_seleccionada;
bool devolver=false;
if ((ini==2  && (fin==3  || fin==7  || fin==8															)) ||
	(ini==6  && (fin==5  || fin==10 || fin==11															)) ||
	(ini==22 && (fin==17 || fin==18 || fin==23															)) ||
	(ini==26 && (fin==21 || fin==20 || fin==25															)) || 
	(ini==3  && (fin==2  || fin==4  || fin==7  || fin==8  || fin==9										)) ||
	(ini==4  && (fin==3  || fin==5  || fin==8  || fin==9  || fin==10									)) ||
	(ini==5  && (fin==4  || fin==6  || fin==9  || fin==10 || fin==11									)) ||
	(ini==7  && (fin==2  || fin==3  || fin==8  || fin==12 || fin==13									)) ||
	(ini==12 && (fin==7  || fin==8  || fin==13 || fin==17 || fin==18									)) ||
	(ini==17 && (fin==12 || fin==13 || fin==18 || fin==22 || fin==23									)) ||
	(ini==11 && (fin==5  || fin==6  || fin==10 || fin==15 || fin==16									)) ||
	(ini==16 && (fin==11 || fin==21 || fin==10 || fin==15 || fin==20									)) ||
	(ini==21 && (fin==16 || fin==26 || fin==15 || fin==20 || fin==25									)) ||
	(ini==23 && (fin==22 || fin==24 || fin==17 || fin==18 || fin==19									)) ||
	(ini==24 && (fin==23 || fin==25 || fin==18 || fin==19 || fin==20									)) ||
	(ini==25 && (fin==24 || fin==26 || fin==19 || fin==20 || fin==21									)) ||
	(ini==8  && (fin==2  || fin==3  || fin==4  || fin==7  || fin==9  || fin==12  || fin==13  || fin==14	)) ||
	(ini==9  && (fin==3  || fin==4  || fin==5  || fin==8  || fin==10 || fin==13  || fin==14  || fin==15	)) ||
	(ini==10 && (fin==4  || fin==5  || fin==6  || fin==9  || fin==11 || fin==14  || fin==15  || fin==16	)) ||
	(ini==13 && (fin==7  || fin==8  || fin==9  || fin==12 || fin==14 || fin==17  || fin==18  || fin==19	)) ||
	(ini==14 && (fin==8  || fin==9  || fin==10 || fin==13 || fin==15 || fin==18  || fin==19  || fin==20	)) ||
	(ini==15 && (fin==9  || fin==10 || fin==11 || fin==14 || fin==16 || fin==19  || fin==20  || fin==21	)) ||
	(ini==18 && (fin==12 || fin==13 || fin==14 || fin==17 || fin==19 || fin==22  || fin==23  || fin==24	)) ||
	(ini==19 && (fin==13 || fin==14 || fin==15 || fin==18 || fin==20 || fin==23  || fin==24  || fin==25	)) ||
	(ini==20 && (fin==14 || fin==15 || fin==16 || fin==19 || fin==21 || fin==24  || fin==25  || fin==26	)) )
	{
		if(carta[carta_seleccionada]->valor==carta[n]->valor)
		{
		// Primero muevo la ultima carta pinchada
		afin=true;
		carta[n]->seleccionada=true;
		carta[carta_seleccionada]->seleccionada=false;
		golum[fin]->num_sel=1;
		carta_seleccionada=n;
		columna_inicio=fin;
		mueve_multigolum(fin,1);
				
		if(ultimo_mov!=actual_mov){
			while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
				ultimo_mov=ultimo_mov->ant_mov;
				delete(ultimo_mov->sig_mov);
				ultimo_mov->sig_mov=NULL;
				}
			}
		ultimo_mov->sig_mov=new undos(fin,1,1,1,ultimo_mov,NULL,false);
		ultimo_mov=ultimo_mov->sig_mov;
		actual_mov=ultimo_mov;
		cartas_colocadas++;
		if (activar_sonido && sonido_colocar->IsOk())	sonido_colocar->Play(wxSOUND_ASYNC);
		// Ahora muevo la primera carta seleccionada
		afin=true;
		carta_seleccionada=cs;
		columna_inicio=ini;
		carta[carta_seleccionada]->seleccionada=true;
		golum[ini]->num_sel=1;
		mueve_multigolum(ini,1);
		
		if(ultimo_mov!=actual_mov){
			while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
				ultimo_mov=ultimo_mov->ant_mov;
				delete(ultimo_mov->sig_mov);
				ultimo_mov->sig_mov=NULL;
				}
			}
		ultimo_mov->sig_mov=new undos(ini,1,2,1,ultimo_mov,NULL,false);
		ultimo_mov=ultimo_mov->sig_mov;
		actual_mov=ultimo_mov;
		cartas_colocadas++;
		if (activar_sonido && sonido_colocar->IsOk())	sonido_colocar->Play(wxSOUND_ASYNC);

		num_mov++;
		if(esperar) {esperar=false;}//juego_automatico=true;}
		columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
		}
	}
return devolver;
}

//*********************************************************************//
// Busca automaticamente un sitio para la carta seleccionada o agarrada
	void montecarlo::busca_sitio(void)
//*********************************************************************//
{
// Nada que hacer
}

//**************************************//
// Busca automaticamente un sitio para la carta de la pila
	void montecarlo::busca_sitio_boton_derecho()
//**************************************//
{
// Nada que hacer
}

//***********************************//
void montecarlo::mover_a_columna(int cc)
//***********************************//
{
int c;
int karta=NOCARTA;
if(cc==1 && golum[0]->num_cartas)	// MAZO
	{
	carta[golum[columna_inicio]->ultimo_valor->carta]->seleccionada=false;
	golum[columna_inicio]->num_sel=0;
	columna_inicio=columna_final=NOCOL;
	carta_seleccionada=NOCARTA;
	}
else if(cc==1 && !golum[0]->num_cartas)	// Es la ultima carta de la pila que ahora
	{									// tiene seleccion 1!!!
	carta[golum[columna_inicio]->ultimo_valor->carta]->seleccionada=false;
	golum[columna_inicio]->num_sel=0;
	columna_inicio=columna_final=NOCOL;
	carta_seleccionada=NOCARTA;
	}
if(cc==2)	// PILA
	{
	carta[golum[columna_inicio]->ultimo_valor->carta]->seleccionada=false;
	golum[columna_inicio]->num_sel=0;
	columna_inicio=columna_final=NOCOL;
	carta_seleccionada=NOCARTA;
	}
if(cc>199 && cc<ultima_columna*100)	// COLUMNAS DE LA 2 A LA 26 (LAS 25 DEL JUEGO)
	{
	c=cc/100;
	if (golum[c]->num_cartas)	// HAY CARTA EN LA GOLUM
		{
		karta=golum[c]->ultimo_valor->carta;
		columna_final=c;
		colocar_carta(karta,columna_inicio);
		}
	else if(!golum[c]->num_cartas && carta_seleccionada!=NOCARTA && columna_inicio!=NOCOL)
		{
		carta[golum[columna_inicio]->ultimo_valor->carta]->seleccionada=false;
		golum[columna_inicio]->num_sel=0;
		columna_inicio=columna_final=NOCOL;
		carta_seleccionada=NOCARTA;
		}
	}
if(columna_inicio!=NOCOL){
	carta[golum[columna_inicio]->ultimo_valor->carta]->seleccionada=false;
	golum[columna_inicio]->num_sel=0;
	}
carta_seleccionada=NOCARTA;columna_inicio=columna_final=NOCOL;
}

//******************************************//
// Identifica la carta que se ha pinchado
int montecarlo::que_carta_es(int cc)
//******************************************//
{
int c;
int karta=NOCARTA;
if(cc==1)	// MAZO
	{
	mover(0,1);
	return NOCARTA;
	}
if(cc>199 && cc<ultima_columna*100)	// COLUMNAS DE LA 2 A LA 13 (LAS 12 DEL JUEGO)
	{
	c=cc/100;
	if (golum[c]->num_cartas)	// HAY CARTA EN LA GOLUM
		{
		karta=golum[c]->ultimo_valor->carta;
		carta[karta]->seleccionada=true;
		columna_inicio=c;
		return karta;
		}
	else if(!golum[c]->num_cartas)
		{
		columna_inicio=columna_final=NOCOL;
		carta_seleccionada=NOCARTA;
		return NOCARTA;
		}
	}
return NOCARTA;
}
