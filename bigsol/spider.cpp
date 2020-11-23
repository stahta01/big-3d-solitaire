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
// spider.cpp: implementation of the spider class.
//
//////////////////////////////////////////////////////////////////////

#include "wx_defines.h"
#include <wx/defs.h>

#include <wx/sound.h>
#include <wx/string.h>

#include "spider.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

spider::spider()
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
golum[0]=new Ccolumna(-0.42f,0.4f,-1.2f,0,true,0,0.0000015f,0.0000015f,0.00015f,MAZO_NO,0);
// LA "COLUMNA" PILA NO EXISTE
golum[1]=new Ccolumna(-0.30f,0.4f,-1.2f,4,false,0,0.0170f,0.f,0.f,MAZO_NO,0);
// LAS COLUMNAS (10)
golum[ 2]=new Ccolumna(-0.54f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 3]=new Ccolumna(-0.42f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 4]=new Ccolumna(-0.30f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 5]=new Ccolumna(-0.18f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 6]=new Ccolumna(-0.06f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 7]=new Ccolumna( 0.06f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 8]=new Ccolumna( 0.18f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 9]=new Ccolumna( 0.30f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[10]=new Ccolumna( 0.42f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[11]=new Ccolumna( 0.54f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
// LAS FINALES (8)
golum[12]=new Ccolumna(-0.09f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
golum[13]=new Ccolumna( 0.f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
golum[14]=new Ccolumna( 0.09f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
golum[15]=new Ccolumna( 0.18f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
golum[16]=new Ccolumna( 0.27f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
golum[17]=new Ccolumna( 0.36f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
golum[18]=new Ccolumna( 0.45f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
golum[19]=new Ccolumna( 0.54f,0.4f,-1.2f,3,false,0,0.0005f,0.00025f,0.0008f,FINAL_AK,0);
// LAS NO UTILIZABLES
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


num_golum=20;	// Siempre es una mas: de la 0 a la 12 => 13
mazo_juego=104;
ultima_columna=12;	// Una mas. Son las columnas seleccionables
juego_automatico=true;
tipo_juego=SPIDER;
mover_permitido=true;
automatico_permitido=false;
}

spider::~spider()
{

}

void spider::fase_presentacion()
{
mueve_colum_reparto(0,2,false);mueve_colum_reparto(0,2,false);
mueve_colum_reparto(0,2,false);mueve_colum_reparto(0,2,false);
mueve_colum_reparto(0,2,true);
mueve_colum_reparto(0,3,false);mueve_colum_reparto(0,3,false);
mueve_colum_reparto(0,3,false);mueve_colum_reparto(0,3,false);
mueve_colum_reparto(0,3,true);
mueve_colum_reparto(0,4,false);mueve_colum_reparto(0,4,false);
mueve_colum_reparto(0,4,false);mueve_colum_reparto(0,4,false);
mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,false);mueve_colum_reparto(0,5,false);
mueve_colum_reparto(0,5,false);mueve_colum_reparto(0,5,false);
mueve_colum_reparto(0,5,true);
mueve_colum_reparto(0,6,false);mueve_colum_reparto(0,6,false);
mueve_colum_reparto(0,6,false);mueve_colum_reparto(0,6,true);
mueve_colum_reparto(0,7,false);mueve_colum_reparto(0,7,false);
mueve_colum_reparto(0,7,false);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,false);mueve_colum_reparto(0,8,false);
mueve_colum_reparto(0,8,false);mueve_colum_reparto(0,8,true);
mueve_colum_reparto(0,9,false);mueve_colum_reparto(0,9,false);
mueve_colum_reparto(0,9,false);mueve_colum_reparto(0,9,true);
mueve_colum_reparto(0,10,false);mueve_colum_reparto(0,10,false);
mueve_colum_reparto(0,10,false);mueve_colum_reparto(0,10,true);
mueve_colum_reparto(0,11,false);mueve_colum_reparto(0,11,false);
mueve_colum_reparto(0,11,false);mueve_colum_reparto(0,11,true);

FASE_PRESENTACION=false;
}

void spider::repetir_juego()
{
game::repetir_juego();
mazo_juego=104;juego_automatico=true;
for(int k=2;k<12;k++) golum[k]->desp_y=-0.03f;
}

//*****************************************************//
// Devuelve TRUE si la carta es seleccionable
// segun las reglas del juego
bool spider::es_seleccionable(int cc,int c)
//****************************************************//
{
lista *alfa=NULL;
int b=0;
int karta_anterior=cc;
golum[c]->num_sel=0;
carta[cc]->seleccionada=true;

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
		if(!(carta[alfa->carta]->tipo==carta[karta_anterior]->tipo &&
		   carta[alfa->carta]->valor==carta[karta_anterior]->valor-1))
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
bool spider::mover(int ini, int fin)
//***********************************//
{
bool avanti=false;
int total_cartass=0;
for(int k=2;k<ultima_columna;k++)
	{
	if (golum[k]->num_cartas) avanti=true;
	else {avanti=false;break;}
	}
// Por si acaso hay menos cartas que columnas !!
// y no dejara hacer el avanti (sacar cartas del mazo)
for(int k=2;k<ultima_columna;k++)
	total_cartass+=golum[k]->num_cartas;
if(total_cartass<(ultima_columna-2)) avanti=true;

// Del MAZO a las COLUMNAS
if(ini==0 && fin==1 && avanti)
	{
	// Metemos una carta en cada una de las columnas si hay cartas
	// y todas las columnas estan rellenadas
	for(int k=2;k<ultima_columna;k++)
		{
		if(golum[0]->num_cartas){
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
		}
	num_mov++;descubierta=false;
	return true;
	}
else if(ini==0 && fin==1 && !avanti)
	{
	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	descubierta=false;
	return false;
	}
// Se puede colocar de una COLUMNA/PILA a COLUMNA NO VACIAS
else if(golum[fin]->num_cartas && 
		//carta[carta_seleccionada]->tipo==carta[golum[fin]->ultimo_valor->carta]->tipo &&  // Con esta condicion tengo el SPIDER DURO
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
// Se puede colocar en una COLUMNA VACIA. Puede ir cualquiera
else if (!golum[fin]->num_cartas)
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


//************************************//
// Mueve de una columna a otra efectivamente
// si son del mismo palo
bool spider::mover_a_palo(int ini, int fin)
//***********************************//
{
// Del MAZO a las COLUMNAS
if(ini==0 && fin==1) return false;
// De COLUMNA/PILA a COLUMNA CON MISMO PALO
else if(golum[fin]->num_cartas && 
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

//*********************************************************
// Mira si la carta en cuestion cabe en alguna pila final	
	bool spider::colocar_carta(int n,int ini)
//*********************************************************
{
bool devolver=false;
//lista *alfa=NULL;
//alfa=golum[ini]->ultimo_valor;
// Deseleccionamos todas las cartas
/*
for(int q=0;q<13;q++)
	{
	carta_seleccionada=alfa->carta;
	carta[carta_seleccionada]->seleccionada=false;
	alfa=alfa->ant;
	}
*/
for(int g=ultima_columna;g<num_golum;g++)
	{
	if (!golum[g]->num_cartas)
		{
		/*columna_inicio=ini;
		/for(int p=0;p<13;p++)
			{
			afin=false;
			alfa=golum[ini]->ultimo_valor;
			carta_seleccionada=alfa->carta;
			carta[carta_seleccionada]->seleccionada=true;
			golum[ini]->num_sel=1;
			mueve_multigolum(ini,g);
			carta[carta_seleccionada]->seleccionada=false;
			}
		*/
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

//**************************************//
	void spider::mover_a_columna(int cc)
//**************************************//
{
lista *alfa;
int c;
//int karta=NOCARTA;
int ci=columna_inicio;

if(cc==1 && golum[0]->num_cartas)	// MAZO
	{
	alfa=golum[ci]->primer_valor->sig;
	for(int k=0;k<golum[ci]->num_cartas;k++){
		carta[alfa->carta]->seleccionada=false;
		alfa=alfa->sig;
		}
	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	golum[ci]->num_sel=0;
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

//******************************************//
// Identifica la carta que se ha pinchado
int spider::que_carta_es(int cc)
//******************************************//
{
lista *alfa=NULL;
int c,b;
int karta=NOCARTA;
if(cc==1 && golum[0]->num_cartas)	// MAZO
	{
	mover(0,1);
	return NOCARTA;
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
// Busca automaticamente un sitio para la carta de la pila
void spider::busca_sitio_boton_derecho()
//**************************************//
{
// Nada que hacer
}

//*********************************************************************//
// Busca automaticamente un sitio para la carta seleccionada o agarrada
	void spider::busca_sitio(void)
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
// Si el juego automatico esta activado
// mira si se puede colocar en columnas finales
if(!juego_automatico && !colocada &&
    golum[columna_inicio]->num_sel==13)
	if(colocar_carta(carta_seleccionada,columna_inicio) && !colocada)	// Si se ha colocado la carta volvemos
		{
		colocada=true;
		}
// Buscamos sitio en columnas ocupadas del mismo palo
if(!colocada)
	{
	for(int k=2;k<ultima_columna;k++)
		{
		if(golum[k]->num_cartas)
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

//**********************************************
// Coloca cartas automaticamente de las columnas
	bool spider::automatico(void)
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
