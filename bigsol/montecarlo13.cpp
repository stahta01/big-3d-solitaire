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
// montecarlo13.cpp: implementation of the montecarlo13 class.
//
//////////////////////////////////////////////////////////////////////

#include "montecarlo13.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

montecarlo13::montecarlo13()
{
//montecarlo();
tipo_juego=DOUBLES13;
}

montecarlo13::~montecarlo13()
{

}

//*********************************************************
// Mira si la carta en cuestion cabe en alguna pila final	
	bool montecarlo13::colocar_carta(int n,int ini)
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
		if(carta[carta_seleccionada]->valor+carta[n]->valor==13)
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

//******************************************//
// Identifica la carta que se ha pinchado
int montecarlo13::que_carta_es(int cc)
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
		if(carta[karta]->valor==13)
			{
			afin=true;
			carta_seleccionada=karta;
			carta[karta]->seleccionada=true;
			golum[c]->num_sel=1;
			mueve_multigolum(c,1);
			if(ultimo_mov!=actual_mov){
				while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
					ultimo_mov=ultimo_mov->ant_mov;
					delete(ultimo_mov->sig_mov);
					ultimo_mov->sig_mov=NULL;
					}
				}
			ultimo_mov->sig_mov=new undos(c,1,1,1,ultimo_mov,NULL,false);
			ultimo_mov=ultimo_mov->sig_mov;
			actual_mov=ultimo_mov;
			cartas_colocadas++;
			if (activar_sonido && sonido_colocar->IsOk())	sonido_colocar->Play(wxSOUND_ASYNC);
			num_mov++;
			if(esperar) {esperar=false;}//juego_automatico=true;}
			columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
			karta=NOCARTA;
			}
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
