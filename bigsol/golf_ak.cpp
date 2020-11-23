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
// golf_ak.cpp: implementation of the golf_ak class.
//
//////////////////////////////////////////////////////////////////////

#include "wx_defines.h"
#include <wx/defs.h>

#include <wx/sound.h>
#include <wx/string.h>

#include "golf_ak.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

golf_ak::golf_ak()
{
tipo_juego=GOLF_AK;
}

golf_ak::~golf_ak()
{

}

//*********************************************************
// Mira si la carta en cuestion cabe en alguna pila final	
bool golf_ak::colocar_carta(int n,int ini)
//*********************************************************
{
bool devolver=false;
if (carta[n]->valor!=1 && carta[n]->valor!=13 && 
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
	     (carta[n]->valor==carta[golum[1]->ultimo_valor->carta]->valor-1 ||
		  carta[golum[1]->ultimo_valor->carta]->valor==13))
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
else if (carta[n]->valor==13 &&
	     (carta[n]->valor==carta[golum[1]->ultimo_valor->carta]->valor+1 ||
		  carta[golum[1]->ultimo_valor->carta]->valor==1))
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
