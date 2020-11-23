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

#include "wx_defines.h"
#include <wx/defs.h>

#include <wx/sound.h>
#include <wx/string.h>

#include "montana.h" // class's header file

// class constructor
montana::montana()
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
golum[ 0]=new Ccolumna( 0.f,0.4f,-1.2f,0,true,0,0.0000015f,0.0000015f,0.00015f,MAZO_SI,0);
// LAS "COLUMNAS"
golum[ 2]=new Ccolumna(-0.6f, 0.2f,-1.2f,2,true,0,0.1f,0.f,0.f,HUECO_2,0);
golum[ 3]=new Ccolumna(-0.6f, 0.04f,-1.2f,2,true,0,0.1f,0.f,0.f,HUECO_2,0);
golum[ 4]=new Ccolumna(-0.6f,-0.12f,-1.2f,2,true,0,0.1f,0.f,0.f,HUECO_2,0);
golum[ 5]=new Ccolumna(-0.6f,-0.28f,-1.2f,2,true,0,0.1f,0.f,0.f,HUECO_2,0);
// LAS NO UTILIZABLES
golum[ 1]=new Ccolumna( 0.00f,0.2f,-1.2f,4,false,0,0.f,-0.03f,0.0f,HUECO_K,0);
golum[ 6]=new Ccolumna( 0.12f,0.2f,-1.2f,4,false,0,0.f,-0.03f,0.0f,HUECO_K,0);
golum[ 7]=new Ccolumna( 0.24f,0.2f,-1.2f,4,false,0,0.f,-0.03f,0.0f,HUECO_K,0);
golum[ 8]=new Ccolumna( 0.36f,0.2f,-1.2f,4,false,0,0.f,-0.03f,0.0f,HUECO_K,0);
golum[ 9]=new Ccolumna( 0.55f, 0.08f,-1.2f,4,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
golum[10]=new Ccolumna( 0.55f,-0.06f,-1.2f,4,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
golum[11]=new Ccolumna( 0.55f,-0.20f,-1.2f,4,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
golum[12]=new Ccolumna( 0.55f,-0.34f,-1.2f,4,false,0,0.0005f,0.00025f,0.0008f,FINAL,0);
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

num_golum=6;	// Siempre es una mas
mazo_juego=52;
ultima_columna=6;	// Una mas. Son las columnas seleccionables
juego_automatico=false;
tipo_juego=MONTANA;
mover_permitido=true;
automatico_permitido=false;
carta[0]->bitmap=HUECO;carta[13]->bitmap=HUECO;
carta[26]->bitmap=HUECO;carta[39]->bitmap=HUECO;
cartas_colocadas=4;
xmon=ymon=zmon=0.f;
lugar_ini=0;
pases=0;
}

// class destructor
montana::~montana()
{

}

void montana::repetir_juego()
{
game::repetir_juego();
num_golum=6;	// Siempre es una mas
mazo_juego=52;
ultima_columna=6;	// Una mas. Son las columnas seleccionables
juego_automatico=false;
tipo_juego=MONTANA;
mover_permitido=true;
automatico_permitido=false;
carta[0]->bitmap=HUECO;carta[13]->bitmap=HUECO;
carta[26]->bitmap=HUECO;carta[39]->bitmap=HUECO;
cartas_colocadas=4;
xmon=ymon=zmon=0.f;
lugar_ini=0;
pases=0;
golum[0]->textura=MAZO_SI;
}


void montana::fase_presentacion()
{
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,2,true);
mueve_colum_reparto(0,2,true);

mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,3,true);
mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,3,true);
mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,3,true);
mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,3,true);
mueve_colum_reparto(0,3,true);

mueve_colum_reparto(0,4,true);mueve_colum_reparto(0,4,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,4,true);mueve_colum_reparto(0,4,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,4,true);mueve_colum_reparto(0,4,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,4,true);mueve_colum_reparto(0,4,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,4,true);

mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,5,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,5,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,5,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,5,true);
mueve_colum_reparto(0,5,true);

recuento();FASE_PRESENTACION=false;
}


bool montana::es_seleccionable(int cc,int c)
{
if (carta[cc]->bitmap!=HUECO)
	{
	carta[cc]->seleccionada=true;
	golum[c]->num_sel=1;
	xmon=carta[cc]->x;
	ymon=carta[cc]->y;
	zmon=carta[cc]->z;
	return true;
	}
else return false;
}


void montana::busca_sitio_boton_derecho()
{
    // Nada que hacer
}


//*********************************************************************//
// Busca automaticamente un sitio para la carta seleccionada o agarrada
	void montana::busca_sitio(void)
//*********************************************************************//
{
bool colocada=false;
int cs=carta_seleccionada;
int ci=columna_inicio;
bool mv=mov_pendiente;
mov_pendiente=true;
// TODO ESTE PROCESO COMENTADO SE REFIERE A QUE LE JUGADOR INTENTA COLOCAR
// EN UN SITIO DETERMINADO Y HAY QUE RECODIFICARLO TODO SIN FILAS[] NI COLUMNAS[]
if(mov_pendiente)
	{	// JUGADOR INTENTA COLOCAR EN LA MISMA columna de inicio
	if (carta[cs]->x>xmon-0.04f && carta[cs]->x<xmon+0.04f &&
	    carta[cs]->y>ymon-0.12f && carta[cs]->y<ymon+0.12f &&
	    ci>1 && !doble_click)  // pero lo arreglaremos con un bool de dobleclick
		{
		afin=false;
		movimiento(xmon,ymon,zmon,cs);
		colocada=true;
		}
	else // EL JUGADOR INTENTA COLOCAR EN UNA COLUMNA DETERMINADA
		{	// LA PILA NO ESTA PERMITIDA
		for(int k=2;k<ultima_columna;k++) 
			{			// El ANCHO de carta y el ALTO de carta
			if (carta[cs]->valor==2 && 
				carta[cs]->x>golum[k]->x-0.04f &&
			    carta[cs]->x<golum[k]->x+0.04f &&
		        carta[cs]->y>golum[k]->y-0.12f &&
		        carta[cs]->y<golum[k]->y+0.12f)
				{
				if(mover(ci,k))
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
	movimiento(xmon,ymon,zmon,cs);
	}
carta[cs]->seleccionada=false;
carta_seleccionada=NOCARTA;columna_inicio=NOCOL;mov_pendiente=mv;
}


//******************************************//
// Identifica la carta que se ha pinchado
int montana::que_carta_es(int cc)
//******************************************//
{
lista *alfa=NULL;
int c,b;
int karta=NOCARTA;
if(cc==1 && pases<3)	// LOS PASES ORIGINALES SON 2!!!
	{
	pases++;
	if(pases==3) golum[0]->textura=MAZO_NO;

	for(int k=2;k<ultima_columna;k++)
		{
		if (carta[golum[k]->primer_valor->sig->carta]->valor==2)
			{
			alfa=golum[k]->primer_valor->sig;
			karta=alfa->carta;
			for(int kk=0;kk<12;kk++)
				{
				alfa=alfa->sig;
				if (carta[alfa->carta]->valor==carta[karta]->valor+1 &&
					carta[alfa->carta]->tipo==carta[karta]->tipo)
					karta=alfa->carta;
				else 
					{
					afin=true;
					columna_inicio=k;
					for(int p=kk;p<12;p++)
						{
						afin=true;
						alfa=golum[k]->ultimo_valor;
						carta_seleccionada=alfa->carta;
						carta[carta_seleccionada]->seleccionada=true;
						golum[k]->num_sel=1;
						mueve_multigolum(k,0);
						carta[carta_seleccionada]->seleccionada=false;
						}
					break;
					}
				}
			}
		else
			{
			columna_inicio=k;
			for(int p=0;p<13;p++)
				{
				afin=true;
				alfa=golum[k]->ultimo_valor;
				carta_seleccionada=alfa->carta;
				carta[carta_seleccionada]->seleccionada=true;
				golum[k]->num_sel=1;
				mueve_multigolum(k,0);
				carta[carta_seleccionada]->seleccionada=false;
				}
			}
		}
	barajar_resto();
	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	recuento();
	// Y NOS CEPILLAMOS TODO EL DESHACER/REHACER
	while(ultimo_mov->ant_mov!=NULL) {
		ultimo_mov=ultimo_mov->ant_mov;
		delete(ultimo_mov->sig_mov); // Liberamos puntero
		ultimo_mov->sig_mov=NULL;
		}
	primer_mov=new undos(NOCOL,NOCOL,1,0,NULL,NULL,false);
	ultimo_mov=primer_mov;
	actual_mov=primer_mov;
	}

if(cc>199 && cc<ultima_columna*100)	// COLUMNAS DE LA 2 A LA 5 (LAS 4 DEL JUEGO)
	{
	c=cc/100;
	b=cc-c*100;
	lugar_ini=b;
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
return NOCARTA;
}

//*********************************************************
//  Mira si la carta en cuestion cabe en alguna pila final	
	bool montana::colocar_carta(int n,int ini)
//*********************************************************
{
bool devolver=false;
bool colocada=false;
int karta;
lista *alfa=NULL;
lista *beta=NULL;
//float xf=0.f;float yf=0.f;float zf=0.f;
if(carta[n]->valor==2)	//COLOCACION DE DOSES
	{
	for(int g=2;g<num_golum;g++)
		{
		if (carta[golum[g]->primer_valor->sig->carta]->valor==1)
  			{
			afin=false;
			carta[n]->seleccionada=true;
			golum[ini]->num_sel=1;
			karta=golum[g]->primer_valor->sig->carta;
			float xf=carta[karta]->x;
			float yf=carta[karta]->y;
			float zf=carta[karta]->z;
			movimiento(xf,yf,zf,n);
			golum[g]->primer_valor->sig->carta=n;
			carta[karta]->x=xmon;
			carta[karta]->y=ymon;
			carta[karta]->z=zmon;
			alfa=golum[ini]->primer_valor->sig;
			// Contamos las cartas que hay desde el principio a donde hemos pinchado
	        for(int k=0;k<lugar_ini;k++) {if(alfa->sig!=NULL) alfa=alfa->sig;}
		    alfa->carta=karta;
			//mueve_multigolum(ini,g);
			carta[n]->seleccionada=false;
			golum[ini]->num_sel=0;
			if(ultimo_mov!=actual_mov){
				while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
					ultimo_mov=ultimo_mov->ant_mov;
					delete(ultimo_mov->sig_mov);
					ultimo_mov->sig_mov=NULL;
					}
				}
			ultimo_mov->sig_mov=new undos(ini,lugar_ini,g,0,ultimo_mov,NULL,false);
			ultimo_mov=ultimo_mov->sig_mov;
			actual_mov=ultimo_mov;
			if (activar_sonido && sonido_colocar->IsOk())	sonido_colocar->Play(wxSOUND_ASYNC);
			devolver=true;recuento();
			num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
			columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
			break;
			}
		}
	}
else
	{
	for(int g=2;g<num_golum;g++)	//COLOCACION DE LAS OTRAS CARTAS
		{
		alfa=golum[g]->primer_valor->sig;
		for(int kk=0;kk<12;kk++)
			{
			alfa=alfa->sig;
			if( carta[alfa->carta]->valor==1					  &&
			    carta[alfa->ant->carta]->valor+1==carta[n]->valor &&
			    carta[alfa->ant->carta]->tipo==carta[n]->tipo)
				{
				afin=false;
				carta[n]->seleccionada=true;
				golum[ini]->num_sel=1;
				karta=alfa->carta;
				float xf=carta[karta]->x;
				float yf=carta[karta]->y;
				float zf=carta[karta]->z;
				movimiento(xf,yf,zf,n);
				alfa->carta=n;
				carta[karta]->x=xmon;
				carta[karta]->y=ymon;
				carta[karta]->z=zmon;
				beta=golum[ini]->primer_valor->sig;
				// Contamos las cartas que hay desde el principio a donde hemos pinchado
				for(int k=0;k<lugar_ini;k++) {if(beta->sig!=NULL) beta=beta->sig;}
				beta->carta=karta;
				carta[n]->seleccionada=false;
				golum[ini]->num_sel=0;
				if(ultimo_mov!=actual_mov){
					while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
						ultimo_mov=ultimo_mov->ant_mov;
						delete(ultimo_mov->sig_mov);
						ultimo_mov->sig_mov=NULL;
						}
					}
				ultimo_mov->sig_mov=new undos(ini,lugar_ini,g,kk+1,ultimo_mov,NULL,false);
				ultimo_mov=ultimo_mov->sig_mov;
				actual_mov=ultimo_mov;
				if (activar_sonido && sonido_colocar->IsOk())	sonido_colocar->Play(wxSOUND_ASYNC);
				devolver=true;recuento();
				num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
				columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
				colocada=true;
				break;
				}
			}
		if(colocada) break;}
	}
return devolver;
}

//-[ Barajar el resto de cartas, las que hay en el mazo ]-
void montana::barajar_resto()
//********************************//
{
int j;
int igual=0;
bool volver=false;
lista *alfa=golum[0]->primer_valor;
//j=rand() % golum[0]->num_cartas;  
// El ASES son colocados a MANO
orden[0]=0;
int h1=13-golum[2]->num_cartas;
int h2=h1+(13-golum[3]->num_cartas);
int h3=h2+(13-golum[4]->num_cartas);

for(int i=1; i<golum[0]->num_cartas; i++)
	{
	if(i==h1)	   j=13;
	else if(i==h2) j=26;
	else if(i==h3) j=39;
	else
		{
		do
			{
			j=rand() % mazo_juego;
			} while(j==13 || j==26 || j==39);
		}
	for(int k=0;k<i;k++)
		{
		if (orden[k]==j)
			{
			igual=1;
			break;
			}
		else igual=0;
		}
	if (!igual)
		{
		volver=true;
		alfa=golum[0]->primer_valor;
		for(int y=0;y<golum[0]->num_cartas;y++)
			{
			alfa=alfa->sig;
			if(alfa->carta==j)
				{
				orden[i]=j;	//printf("Numero extra�do en bola dentro de mazo %d . %d\n",i,resultado[i]);
				volver=false;
				break;
				}
			else
				{
				volver=true;
				}
			}
		}
	else
		{
		i--;
		//printf("Numero repetido: %d\n",j);
		}
	if (!igual && volver) i--;
	}
// Primero hay que meterlas en el mazo (solo virtualmente)
int cc=NOCARTA;
alfa=golum[0]->primer_valor->sig;
for(int k=0;k<golum[0]->num_cartas;k++){
	cc=orden[golum[0]->num_cartas-1-k];
	alfa->carta=cc;
	alfa=alfa->sig;
	carta[cc]->x=golum[0]->x+golum[0]->desp_x*k;
	carta[cc]->y=golum[0]->y+golum[0]->desp_y*k;
	carta[cc]->z=golum[0]->z+golum[0]->desp_z*k;
	carta[cc]->seleccionada=false;
	}

for(int k=2;k<ultima_columna;k++)
	{
	for(int i=golum[k]->num_cartas;i<13;i++)
		mueve_colum_reparto(0,k,true);
	}
}

// Contamos las cartas ya colocadas
//----------------------------------
void montana::recuento()
{
lista *alfa=NULL;
int karta=NOCARTA;
cartas_colocadas=4;
for(int k=2;k<ultima_columna;k++)
	{
	if (carta[golum[k]->primer_valor->sig->carta]->valor==2)
		{
		cartas_colocadas++;
		alfa=golum[k]->primer_valor->sig;
		karta=alfa->carta;
		for(int kk=0;kk<12;kk++)
			{
			alfa=alfa->sig;
			if (carta[alfa->carta]->valor==carta[karta]->valor+1 &&
				carta[alfa->carta]->tipo==carta[karta]->tipo)
				{cartas_colocadas++;karta=alfa->carta;}
			else break;
			}
		}
	}
if(cartas_colocadas==mazo_juego){
	golum[0]->selec=false;golum[0]->textura=MAZO_NO;
	golum[2]->selec=false;
	golum[3]->selec=false;
	golum[4]->selec=false;
	golum[5]->selec=false;
	}
}

// Solo valido para mover los DOSES A MANO
//-----------------------------------------
bool montana::mover(int ini,int k)
{
int karta=NOCARTA;
int cs=carta_seleccionada;
lista *alfa;
if (carta[golum[k]->primer_valor->sig->carta]->valor==1)
	{
	afin=false;
	carta[cs]->seleccionada=true;
	golum[ini]->num_sel=1;
	karta=golum[k]->primer_valor->sig->carta;
	float xf=carta[karta]->x;
	float yf=carta[karta]->y;
	float zf=carta[karta]->z;
	movimiento(xf,yf,zf,carta_seleccionada);
	golum[k]->primer_valor->sig->carta=cs;
	carta[karta]->x=xmon;
	carta[karta]->y=ymon;
	carta[karta]->z=zmon;
	alfa=golum[ini]->primer_valor->sig;
	// Contamos las cartas que hay desde el principio a donde hemos pinchado
	for(int kk=0;kk<lugar_ini;kk++) {if(alfa->sig!=NULL) alfa=alfa->sig;}
	alfa->carta=karta;
	carta[cs]->seleccionada=false;
	golum[ini]->num_sel=0;
	if(ultimo_mov!=actual_mov){
		while(ultimo_mov->ant_mov!=actual_mov->ant_mov) {
			ultimo_mov=ultimo_mov->ant_mov;
			delete(ultimo_mov->sig_mov);
			ultimo_mov->sig_mov=NULL;
			}
		}
	ultimo_mov->sig_mov=new undos(ini,lugar_ini,k,0,ultimo_mov,NULL,false);
	ultimo_mov=ultimo_mov->sig_mov;
	actual_mov=ultimo_mov;
	recuento();
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	return true;
	}
return false;
}

//*************************************************************//
//	Atras                                
	bool montana::deshacer(void)
// Devuelve true si ha habido retroceso y false si no
// En MONTANA la utilizacion de la lista UNDOS es DIFERENTE
// INI: LA COLUMNA DE INICIO **********************************
// FIN: EL LUGAR QUE OCUPABA EN LA COLUMNA DE INICIO **********
// CUANTAS: LA COLUMNA FINAL **********************************
// SEL: EL LUGAR QUE OCUPABA EN LA COLUMNA FINAL **************
//*************************************************************//
{
int ini,fin,lugar_fin;
bool desh=true;
int karta,cs;
lista *alfa,*beta;
ini      =actual_mov->ini;
lugar_ini=actual_mov->fin;
fin      =actual_mov->cuantas;
lugar_fin=actual_mov->selec;

if (actual_mov->ant_mov!=NULL)	// No estamos en primer elemento de la lista
	{
	mov_pendiente=true;afin=false;retroceso=true;

	alfa=golum[ini]->primer_valor->sig;
	// Contamos las cartas que hay desde el principio a donde hemos pinchado
	for(int k=0;k<lugar_ini;k++) {if(alfa->sig!=NULL) alfa=alfa->sig;}
	karta=alfa->carta;  // ES UN PUTO AS, SEGURO
	float xf=carta[karta]->x;float yf=carta[karta]->y;float zf=carta[karta]->z;

	beta=golum[fin]->primer_valor->sig;
	// Contamos las cartas que hay desde el principio a donde hemos pinchado
	for(int k=0;k<lugar_fin;k++) {if(beta->sig!=NULL) beta=beta->sig;}
	cs=beta->carta;
	xmon=carta[cs]->x;ymon=carta[cs]->y;zmon=carta[cs]->z;

	carta[cs]->seleccionada=true;
	carta_seleccionada=cs;
	columna_inicio=fin;
	golum[fin]->num_sel=1;
	movimiento(xf,yf,zf,cs);
	alfa->carta=cs;
	beta->carta=karta;
	carta[karta]->x=xmon;
	carta[karta]->y=ymon;
	carta[karta]->z=zmon;
	alfa=golum[fin]->primer_valor->sig;
	
	carta[cs]->seleccionada=false;
	golum[fin]->num_sel=0;
	actual_mov=actual_mov->ant_mov;
	columna_inicio=NOCOL;carta_seleccionada=NOCARTA;
	desh=true;
	}
else desh=false; // ESTAMOS EN PRIMER MOVIMIENTO, SE PODRIA DAR UN PITIDO

retroceso=false;
if(desh) num_mov--;
recolocar();
return desh;
}

//*************************************************************//
//	Atras                                
	bool montana::rehacer(void)
// Devuelve true si ha habido retroceso y false si no
// En MONTANA la utilizacion de la lista UNDOS es DIFERENTE
// INI: LA COLUMNA DE INICIO **********************************
// FIN: EL LUGAR QUE OCUPABA EN LA COLUMNA DE INICIO **********
// CUANTAS: LA COLUMNA FINAL **********************************
// SEL: EL LUGAR QUE OCUPABA EN LA COLUMNA FINAL **************
// PERO AHORA AL REVES DE DESHACER
//*************************************************************//
{
int ini,fin,lugar_fin;
bool desh=true;
int karta,cs;
lista *alfa,*beta;

if (actual_mov->sig_mov!=NULL)	// No estamos en ultimo elemento de la lista
	{
	fin      =actual_mov->sig_mov->ini;
	lugar_fin=actual_mov->sig_mov->fin;
	ini      =actual_mov->sig_mov->cuantas;
	lugar_ini=actual_mov->sig_mov->selec;
	mov_pendiente=true;afin=false;retroceso=true;

	alfa=golum[ini]->primer_valor->sig;
	// Contamos las cartas que hay desde el principio a donde hemos pinchado
	for(int k=0;k<lugar_ini;k++) {if(alfa->sig!=NULL) alfa=alfa->sig;}
	karta=alfa->carta;  // ES UN PUTO AS, SEGURO
	float xf=carta[karta]->x;float yf=carta[karta]->y;float zf=carta[karta]->z;

	beta=golum[fin]->primer_valor->sig;
	// Contamos las cartas que hay desde el principio a donde hemos pinchado
	for(int k=0;k<lugar_fin;k++) {if(beta->sig!=NULL) beta=beta->sig;}
	cs=beta->carta;
	xmon=carta[cs]->x;ymon=carta[cs]->y;zmon=carta[cs]->z;

	carta[cs]->seleccionada=true;
	carta_seleccionada=cs;
	columna_inicio=fin;
	golum[fin]->num_sel=1;
	movimiento(xf,yf,zf,cs);
	alfa->carta=cs;
	beta->carta=karta;
	carta[karta]->x=xmon;
	carta[karta]->y=ymon;
	carta[karta]->z=zmon;
	alfa=golum[fin]->primer_valor->sig;
	
	carta[cs]->seleccionada=false;
	golum[fin]->num_sel=0;
	actual_mov=actual_mov->sig_mov;
	columna_inicio=NOCOL;carta_seleccionada=NOCARTA;
	desh=true;	
	}
else desh=false; // ESTAMOS EN PRIMER MOVIMIENTO, SE PODRIA DAR UN PITIDO
retroceso=false;
if(desh) num_mov++;
recolocar();
return desh;
}
