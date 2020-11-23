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
// game.cpp: implementation of the game class->
//
//////////////////////////////////////////////////////////////////////

// Sonido
#include "wx/sound.h"
#define WAV_COLOCAR	_T("Data/1/final.wav")

#include "game.h"
#include "40.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//****************//
	game::game()
//****************//
{
//posX0=0.00000000f;
//posY0=1.11800003f;
//posZ0=6.14611244f;

//viewX0=0.00000000f;
//viewY0=1.54399431f;
//viewZ0=5.00611258f;

posX0=-0.69733799f;
posY0=0.20319366;
posZ0=-1.38202608f;

viewX0=0.38744837f;
viewY0=0.46800026f;
viewZ0=-1.86360002f;
//m_canvasframe=NULL;
afin=false;
for(int i=0;i<209;i++) {carta[i]=new cards;orden[i]=0;}
// ESTAMOS PARA 40 LADRONES 3 MAZOS
// LA COLUMNA MAZO la columna[0],fila[0]
golum[0]=new Ccolumna(-0.42f,0.4f,-1.2f,0,true,156,0.0000015f,0.0000015f,0.00009f,MAZO_NO,0);
// LA "COLUMNA" PILA
golum[1]=new Ccolumna(-0.30f,0.4f,-1.2f,1,true,0,0.0170f,0.f,0.00005f,MAZO_NO,0);
// LAS COLUMNAS
golum[ 2]=new Ccolumna(-0.605f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 3]=new Ccolumna(-0.495f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 4]=new Ccolumna(-0.385f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 5]=new Ccolumna(-0.275f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 6]=new Ccolumna(-0.165f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 7]=new Ccolumna(-0.055f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 8]=new Ccolumna( 0.055f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[ 9]=new Ccolumna( 0.165f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[10]=new Ccolumna( 0.275f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[11]=new Ccolumna( 0.385f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[12]=new Ccolumna( 0.495f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
golum[13]=new Ccolumna( 0.605f,0.2f,-1.2f,2,true,0,0.f,-0.03f,0.0001f,HUECO,0);
// LAS CASILLA FINALES
golum[14]=new Ccolumna(-0.495f,-0.39f,-1.2f,3,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[15]=new Ccolumna(-0.405f,-0.39f,-1.2f,3,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[16]=new Ccolumna(-0.315f,-0.39f,-1.2f,3,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[17]=new Ccolumna(-0.225f,-0.39f,-1.2f,3,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[18]=new Ccolumna(-0.135f,-0.39f,-1.2f,3,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[19]=new Ccolumna(-0.045f,-0.39f,-1.2f,3,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[20]=new Ccolumna( 0.045f,-0.39f,-1.2f,3,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[21]=new Ccolumna( 0.135f,-0.39f,-1.2f,3,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[22]=new Ccolumna( 0.225f,-0.39f,-1.2f,3,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[23]=new Ccolumna( 0.315f,-0.39f,-1.2f,3,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[24]=new Ccolumna( 0.405f,-0.39f,-1.2f,3,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
golum[25]=new Ccolumna( 0.495f,-0.39f,-1.2f,3,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
// LAS NO UTILIZABLES
golum[26]=new Ccolumna( 0.605f,-0.55f,-1.2f,4,false,0,0.0008f,0.00025f,0.0008f,FINAL,0);
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

num_golum=26;
// valor;       El AS vale 1, la K 13, la Q 12, la J 11, etc->
// tipo;        1=trebol, 2=rombo, 3=corazones, 4=picas
carta[ 0]->valor= 1;carta[ 0]->bitmap= 1;carta[ 0]->tipo=1;// Las cartas NEGRAS no necesario 
carta[ 1]->valor= 2;carta[ 1]->bitmap= 2;carta[ 1]->tipo=1;// ya esta por defecto
carta[ 2]->valor= 3;carta[ 2]->bitmap= 3;carta[ 2]->tipo=1;
carta[ 3]->valor= 4;carta[ 3]->bitmap= 4;carta[ 3]->tipo=1;
carta[ 4]->valor= 5;carta[ 4]->bitmap= 5;carta[ 4]->tipo=1;
carta[ 5]->valor= 6;carta[ 5]->bitmap= 6;carta[ 5]->tipo=1;
carta[ 6]->valor= 7;carta[ 6]->bitmap= 7;carta[ 6]->tipo=1;
carta[ 7]->valor= 8;carta[ 7]->bitmap= 8;carta[ 7]->tipo=1;
carta[ 8]->valor= 9;carta[ 8]->bitmap= 9;carta[ 8]->tipo=1;
carta[ 9]->valor=10;carta[ 9]->bitmap=10;carta[ 9]->tipo=1;
carta[10]->valor=11;carta[10]->bitmap=11;carta[10]->tipo=1;
carta[11]->valor=12;carta[11]->bitmap=12;carta[11]->tipo=1;
carta[12]->valor=13;carta[12]->bitmap=13;carta[12]->tipo=1;

carta[13]->valor= 1;carta[13]->bitmap=14;carta[13]->tipo=2;carta[13]->color=true;
carta[14]->valor= 2;carta[14]->bitmap=15;carta[14]->tipo=2;carta[14]->color=true;
carta[15]->valor= 3;carta[15]->bitmap=16;carta[15]->tipo=2;carta[15]->color=true;
carta[16]->valor= 4;carta[16]->bitmap=17;carta[16]->tipo=2;carta[16]->color=true;
carta[17]->valor= 5;carta[17]->bitmap=18;carta[17]->tipo=2;carta[17]->color=true;
carta[18]->valor= 6;carta[18]->bitmap=19;carta[18]->tipo=2;carta[18]->color=true;
carta[19]->valor= 7;carta[19]->bitmap=20;carta[19]->tipo=2;carta[19]->color=true;
carta[20]->valor= 8;carta[20]->bitmap=21;carta[20]->tipo=2;carta[20]->color=true;
carta[21]->valor= 9;carta[21]->bitmap=22;carta[21]->tipo=2;carta[21]->color=true;
carta[22]->valor=10;carta[22]->bitmap=23;carta[22]->tipo=2;carta[22]->color=true;
carta[23]->valor=11;carta[23]->bitmap=24;carta[23]->tipo=2;carta[23]->color=true;
carta[24]->valor=12;carta[24]->bitmap=25;carta[24]->tipo=2;carta[24]->color=true;
carta[25]->valor=13;carta[25]->bitmap=26;carta[25]->tipo=2;carta[25]->color=true;

carta[26]->valor= 1;carta[26]->bitmap=27;carta[26]->tipo=3;carta[26]->color=true;
carta[27]->valor= 2;carta[27]->bitmap=28;carta[27]->tipo=3;carta[27]->color=true;
carta[28]->valor= 3;carta[28]->bitmap=29;carta[28]->tipo=3;carta[28]->color=true;
carta[29]->valor= 4;carta[29]->bitmap=30;carta[29]->tipo=3;carta[29]->color=true;
carta[30]->valor= 5;carta[30]->bitmap=31;carta[30]->tipo=3;carta[30]->color=true;
carta[31]->valor= 6;carta[31]->bitmap=32;carta[31]->tipo=3;carta[31]->color=true;
carta[32]->valor= 7;carta[32]->bitmap=33;carta[32]->tipo=3;carta[32]->color=true;
carta[33]->valor= 8;carta[33]->bitmap=34;carta[33]->tipo=3;carta[33]->color=true;
carta[34]->valor= 9;carta[34]->bitmap=35;carta[34]->tipo=3;carta[34]->color=true;
carta[35]->valor=10;carta[35]->bitmap=36;carta[35]->tipo=3;carta[35]->color=true;
carta[36]->valor=11;carta[36]->bitmap=37;carta[36]->tipo=3;carta[36]->color=true;
carta[37]->valor=12;carta[37]->bitmap=38;carta[37]->tipo=3;carta[37]->color=true;
carta[38]->valor=13;carta[38]->bitmap=39;carta[38]->tipo=3;carta[38]->color=true;

carta[39]->valor= 1;carta[39]->bitmap=40;carta[39]->tipo=4;
carta[40]->valor= 2;carta[40]->bitmap=41;carta[40]->tipo=4;
carta[41]->valor= 3;carta[41]->bitmap=42;carta[41]->tipo=4;
carta[42]->valor= 4;carta[42]->bitmap=43;carta[42]->tipo=4;
carta[43]->valor= 5;carta[43]->bitmap=44;carta[43]->tipo=4;
carta[44]->valor= 6;carta[44]->bitmap=45;carta[44]->tipo=4;
carta[45]->valor= 7;carta[45]->bitmap=46;carta[45]->tipo=4;
carta[46]->valor= 8;carta[46]->bitmap=47;carta[46]->tipo=4;
carta[47]->valor= 9;carta[47]->bitmap=48;carta[47]->tipo=4;
carta[48]->valor=10;carta[48]->bitmap=49;carta[48]->tipo=4;
carta[49]->valor=11;carta[49]->bitmap=50;carta[49]->tipo=4;
carta[50]->valor=12;carta[50]->bitmap=51;carta[50]->tipo=4;
carta[51]->valor=13;carta[51]->bitmap=52;carta[51]->tipo=4;

carta[52]->valor= 1;carta[52]->bitmap= 1;carta[52]->tipo=1;
carta[53]->valor= 2;carta[53]->bitmap= 2;carta[53]->tipo=1;
carta[54]->valor= 3;carta[54]->bitmap= 3;carta[54]->tipo=1;
carta[55]->valor= 4;carta[55]->bitmap= 4;carta[55]->tipo=1;
carta[56]->valor= 5;carta[56]->bitmap= 5;carta[56]->tipo=1;
carta[57]->valor= 6;carta[57]->bitmap= 6;carta[57]->tipo=1;
carta[58]->valor= 7;carta[58]->bitmap= 7;carta[58]->tipo=1;
carta[59]->valor= 8;carta[59]->bitmap= 8;carta[59]->tipo=1;
carta[60]->valor= 9;carta[60]->bitmap= 9;carta[60]->tipo=1;
carta[61]->valor=10;carta[61]->bitmap=10;carta[61]->tipo=1;
carta[62]->valor=11;carta[62]->bitmap=11;carta[62]->tipo=1;
carta[63]->valor=12;carta[63]->bitmap=12;carta[63]->tipo=1;
carta[64]->valor=13;carta[64]->bitmap=13;carta[64]->tipo=1;

carta[65]->valor= 1;carta[65]->bitmap=14;carta[65]->tipo=2;carta[65]->color=true;
carta[66]->valor= 2;carta[66]->bitmap=15;carta[66]->tipo=2;carta[66]->color=true;
carta[67]->valor= 3;carta[67]->bitmap=16;carta[67]->tipo=2;carta[67]->color=true;
carta[68]->valor= 4;carta[68]->bitmap=17;carta[68]->tipo=2;carta[68]->color=true;
carta[69]->valor= 5;carta[69]->bitmap=18;carta[69]->tipo=2;carta[69]->color=true;
carta[70]->valor= 6;carta[70]->bitmap=19;carta[70]->tipo=2;carta[70]->color=true;
carta[71]->valor= 7;carta[71]->bitmap=20;carta[71]->tipo=2;carta[71]->color=true;
carta[72]->valor= 8;carta[72]->bitmap=21;carta[72]->tipo=2;carta[72]->color=true;
carta[73]->valor= 9;carta[73]->bitmap=22;carta[73]->tipo=2;carta[73]->color=true;
carta[74]->valor=10;carta[74]->bitmap=23;carta[74]->tipo=2;carta[74]->color=true;
carta[75]->valor=11;carta[75]->bitmap=24;carta[75]->tipo=2;carta[75]->color=true;
carta[76]->valor=12;carta[76]->bitmap=25;carta[76]->tipo=2;carta[76]->color=true;
carta[77]->valor=13;carta[77]->bitmap=26;carta[77]->tipo=2;carta[77]->color=true;

carta[78]->valor= 1;carta[78]->bitmap=27;carta[78]->tipo=3;carta[78]->color=true;
carta[79]->valor= 2;carta[79]->bitmap=28;carta[79]->tipo=3;carta[79]->color=true;
carta[80]->valor= 3;carta[80]->bitmap=29;carta[80]->tipo=3;carta[80]->color=true;
carta[81]->valor= 4;carta[81]->bitmap=30;carta[81]->tipo=3;carta[81]->color=true;
carta[82]->valor= 5;carta[82]->bitmap=31;carta[82]->tipo=3;carta[82]->color=true;
carta[83]->valor= 6;carta[83]->bitmap=32;carta[83]->tipo=3;carta[83]->color=true;
carta[84]->valor= 7;carta[84]->bitmap=33;carta[84]->tipo=3;carta[84]->color=true;
carta[85]->valor= 8;carta[85]->bitmap=34;carta[85]->tipo=3;carta[85]->color=true;
carta[86]->valor= 9;carta[86]->bitmap=35;carta[86]->tipo=3;carta[86]->color=true;
carta[87]->valor=10;carta[87]->bitmap=36;carta[87]->tipo=3;carta[87]->color=true;
carta[88]->valor=11;carta[88]->bitmap=37;carta[88]->tipo=3;carta[88]->color=true;
carta[89]->valor=12;carta[89]->bitmap=38;carta[89]->tipo=3;carta[89]->color=true;
carta[90]->valor=13;carta[90]->bitmap=39;carta[90]->tipo=3;carta[90]->color=true;

carta[91]->valor= 1;carta[91]->bitmap=40;carta[91]->tipo=4;
carta[92]->valor= 2;carta[92]->bitmap=41;carta[92]->tipo=4;
carta[93]->valor= 3;carta[93]->bitmap=42;carta[93]->tipo=4;
carta[94]->valor= 4;carta[94]->bitmap=43;carta[94]->tipo=4;
carta[95]->valor= 5;carta[95]->bitmap=44;carta[95]->tipo=4;
carta[96]->valor= 6;carta[96]->bitmap=45;carta[96]->tipo=4;
carta[97]->valor= 7;carta[97]->bitmap=46;carta[97]->tipo=4;
carta[98]->valor= 8;carta[98]->bitmap=47;carta[98]->tipo=4;
carta[99]->valor= 9;carta[99]->bitmap=48;carta[99]->tipo=4;
carta[100]->valor=10;carta[100]->bitmap=49;carta[100]->tipo=4;
carta[101]->valor=11;carta[101]->bitmap=50;carta[101]->tipo=4;
carta[102]->valor=12;carta[102]->bitmap=51;carta[102]->tipo=4;
carta[103]->valor=13;carta[103]->bitmap=52;carta[103]->tipo=4;

carta[104]->valor= 1;carta[104]->bitmap= 1;carta[104]->tipo=1;
carta[105]->valor= 2;carta[105]->bitmap= 2;carta[105]->tipo=1;
carta[106]->valor= 3;carta[106]->bitmap= 3;carta[106]->tipo=1;
carta[107]->valor= 4;carta[107]->bitmap= 4;carta[107]->tipo=1;
carta[108]->valor= 5;carta[108]->bitmap= 5;carta[108]->tipo=1;
carta[109]->valor= 6;carta[109]->bitmap= 6;carta[109]->tipo=1;
carta[110]->valor= 7;carta[110]->bitmap= 7;carta[110]->tipo=1;
carta[111]->valor= 8;carta[111]->bitmap= 8;carta[111]->tipo=1;
carta[112]->valor= 9;carta[112]->bitmap= 9;carta[112]->tipo=1;
carta[113]->valor=10;carta[113]->bitmap=10;carta[113]->tipo=1;
carta[114]->valor=11;carta[114]->bitmap=11;carta[114]->tipo=1;
carta[115]->valor=12;carta[115]->bitmap=12;carta[115]->tipo=1;
carta[116]->valor=13;carta[116]->bitmap=13;carta[116]->tipo=1;

carta[117]->valor= 1;carta[117]->bitmap=14;carta[117]->tipo=2;carta[117]->color=true;
carta[118]->valor= 2;carta[118]->bitmap=15;carta[118]->tipo=2;carta[118]->color=true;
carta[119]->valor= 3;carta[119]->bitmap=16;carta[119]->tipo=2;carta[119]->color=true;
carta[120]->valor= 4;carta[120]->bitmap=17;carta[120]->tipo=2;carta[120]->color=true;
carta[121]->valor= 5;carta[121]->bitmap=18;carta[121]->tipo=2;carta[121]->color=true;
carta[122]->valor= 6;carta[122]->bitmap=19;carta[122]->tipo=2;carta[122]->color=true;
carta[123]->valor= 7;carta[123]->bitmap=20;carta[123]->tipo=2;carta[123]->color=true;
carta[124]->valor= 8;carta[124]->bitmap=21;carta[124]->tipo=2;carta[124]->color=true;
carta[125]->valor= 9;carta[125]->bitmap=22;carta[125]->tipo=2;carta[125]->color=true;
carta[126]->valor=10;carta[126]->bitmap=23;carta[126]->tipo=2;carta[126]->color=true;
carta[127]->valor=11;carta[127]->bitmap=24;carta[127]->tipo=2;carta[127]->color=true;
carta[128]->valor=12;carta[128]->bitmap=25;carta[128]->tipo=2;carta[128]->color=true;
carta[129]->valor=13;carta[129]->bitmap=26;carta[129]->tipo=2;carta[129]->color=true;

carta[130]->valor= 1;carta[130]->bitmap=27;carta[130]->tipo=3;carta[130]->color=true;
carta[131]->valor= 2;carta[131]->bitmap=28;carta[131]->tipo=3;carta[131]->color=true;
carta[132]->valor= 3;carta[132]->bitmap=29;carta[132]->tipo=3;carta[132]->color=true;
carta[133]->valor= 4;carta[133]->bitmap=30;carta[133]->tipo=3;carta[133]->color=true;
carta[134]->valor= 5;carta[134]->bitmap=31;carta[134]->tipo=3;carta[134]->color=true;
carta[135]->valor= 6;carta[135]->bitmap=32;carta[135]->tipo=3;carta[135]->color=true;
carta[136]->valor= 7;carta[136]->bitmap=33;carta[136]->tipo=3;carta[136]->color=true;
carta[137]->valor= 8;carta[137]->bitmap=34;carta[137]->tipo=3;carta[137]->color=true;
carta[138]->valor= 9;carta[138]->bitmap=35;carta[138]->tipo=3;carta[138]->color=true;
carta[139]->valor=10;carta[139]->bitmap=36;carta[139]->tipo=3;carta[139]->color=true;
carta[140]->valor=11;carta[140]->bitmap=37;carta[140]->tipo=3;carta[140]->color=true;
carta[141]->valor=12;carta[141]->bitmap=38;carta[141]->tipo=3;carta[141]->color=true;
carta[142]->valor=13;carta[142]->bitmap=39;carta[142]->tipo=3;carta[142]->color=true;

carta[143]->valor= 1;carta[143]->bitmap=40;carta[143]->tipo=4;
carta[144]->valor= 2;carta[144]->bitmap=41;carta[144]->tipo=4;
carta[145]->valor= 3;carta[145]->bitmap=42;carta[145]->tipo=4;
carta[146]->valor= 4;carta[146]->bitmap=43;carta[146]->tipo=4;
carta[147]->valor= 5;carta[147]->bitmap=44;carta[147]->tipo=4;
carta[148]->valor= 6;carta[148]->bitmap=45;carta[148]->tipo=4;
carta[149]->valor= 7;carta[149]->bitmap=46;carta[149]->tipo=4;
carta[150]->valor= 8;carta[150]->bitmap=47;carta[150]->tipo=4;
carta[151]->valor= 9;carta[151]->bitmap=48;carta[151]->tipo=4;
carta[152]->valor=10;carta[152]->bitmap=49;carta[152]->tipo=4;
carta[153]->valor=11;carta[153]->bitmap=50;carta[153]->tipo=4;
carta[154]->valor=12;carta[154]->bitmap=51;carta[154]->tipo=4;
carta[155]->valor=13;carta[155]->bitmap=52;carta[155]->tipo=4;

carta[156]->valor= 1;carta[156]->bitmap= 1;carta[156]->tipo=1;
carta[157]->valor= 2;carta[157]->bitmap= 2;carta[157]->tipo=1;
carta[158]->valor= 3;carta[158]->bitmap= 3;carta[158]->tipo=1;
carta[159]->valor= 4;carta[159]->bitmap= 4;carta[159]->tipo=1;
carta[160]->valor= 5;carta[160]->bitmap= 5;carta[160]->tipo=1;
carta[161]->valor= 6;carta[161]->bitmap= 6;carta[161]->tipo=1;
carta[162]->valor= 7;carta[162]->bitmap= 7;carta[162]->tipo=1;
carta[163]->valor= 8;carta[163]->bitmap= 8;carta[163]->tipo=1;
carta[164]->valor= 9;carta[164]->bitmap= 9;carta[164]->tipo=1;
carta[165]->valor=10;carta[165]->bitmap=10;carta[165]->tipo=1;
carta[166]->valor=11;carta[166]->bitmap=11;carta[166]->tipo=1;
carta[167]->valor=12;carta[167]->bitmap=12;carta[167]->tipo=1;
carta[168]->valor=13;carta[168]->bitmap=13;carta[168]->tipo=1;

carta[169]->valor= 1;carta[169]->bitmap=14;carta[169]->tipo=2;carta[169]->color=true;
carta[170]->valor= 2;carta[170]->bitmap=15;carta[170]->tipo=2;carta[170]->color=true;
carta[171]->valor= 3;carta[171]->bitmap=16;carta[171]->tipo=2;carta[171]->color=true;
carta[172]->valor= 4;carta[172]->bitmap=17;carta[172]->tipo=2;carta[173]->color=true;
carta[173]->valor= 5;carta[173]->bitmap=18;carta[173]->tipo=2;carta[173]->color=true;
carta[174]->valor= 6;carta[174]->bitmap=19;carta[174]->tipo=2;carta[174]->color=true;
carta[175]->valor= 7;carta[175]->bitmap=20;carta[175]->tipo=2;carta[175]->color=true;
carta[176]->valor= 8;carta[176]->bitmap=21;carta[176]->tipo=2;carta[176]->color=true;
carta[177]->valor= 9;carta[177]->bitmap=22;carta[177]->tipo=2;carta[177]->color=true;
carta[178]->valor=10;carta[178]->bitmap=23;carta[178]->tipo=2;carta[178]->color=true;
carta[179]->valor=11;carta[179]->bitmap=24;carta[179]->tipo=2;carta[179]->color=true;
carta[180]->valor=12;carta[180]->bitmap=25;carta[180]->tipo=2;carta[180]->color=true;
carta[181]->valor=13;carta[181]->bitmap=26;carta[181]->tipo=2;carta[181]->color=true;

carta[182]->valor= 1;carta[182]->bitmap=27;carta[182]->tipo=3;carta[182]->color=true;
carta[183]->valor= 2;carta[183]->bitmap=28;carta[183]->tipo=3;carta[183]->color=true;
carta[184]->valor= 3;carta[184]->bitmap=29;carta[184]->tipo=3;carta[184]->color=true;
carta[185]->valor= 4;carta[185]->bitmap=30;carta[185]->tipo=3;carta[185]->color=true;
carta[186]->valor= 5;carta[186]->bitmap=31;carta[186]->tipo=3;carta[186]->color=true;
carta[187]->valor= 6;carta[187]->bitmap=32;carta[187]->tipo=3;carta[187]->color=true;
carta[188]->valor= 7;carta[188]->bitmap=33;carta[188]->tipo=3;carta[188]->color=true;
carta[189]->valor= 8;carta[189]->bitmap=34;carta[189]->tipo=3;carta[189]->color=true;
carta[190]->valor= 9;carta[190]->bitmap=35;carta[190]->tipo=3;carta[190]->color=true;
carta[191]->valor=10;carta[191]->bitmap=36;carta[191]->tipo=3;carta[191]->color=true;
carta[192]->valor=11;carta[192]->bitmap=37;carta[192]->tipo=3;carta[192]->color=true;
carta[193]->valor=12;carta[193]->bitmap=38;carta[193]->tipo=3;carta[193]->color=true;
carta[194]->valor=13;carta[194]->bitmap=39;carta[194]->tipo=3;carta[194]->color=true;

carta[195]->valor= 1;carta[195]->bitmap=40;carta[195]->tipo=4;
carta[196]->valor= 2;carta[196]->bitmap=41;carta[196]->tipo=4;
carta[197]->valor= 3;carta[197]->bitmap=42;carta[197]->tipo=4;
carta[198]->valor= 4;carta[198]->bitmap=43;carta[198]->tipo=4;
carta[199]->valor= 5;carta[199]->bitmap=44;carta[199]->tipo=4;
carta[200]->valor= 6;carta[200]->bitmap=45;carta[200]->tipo=4;
carta[201]->valor= 7;carta[201]->bitmap=46;carta[201]->tipo=4;
carta[202]->valor= 8;carta[202]->bitmap=47;carta[202]->tipo=4;
carta[203]->valor= 9;carta[203]->bitmap=48;carta[203]->tipo=4;
carta[204]->valor=10;carta[204]->bitmap=49;carta[204]->tipo=4;
carta[205]->valor=11;carta[205]->bitmap=50;carta[205]->tipo=4;
carta[206]->valor=12;carta[206]->bitmap=51;carta[206]->tipo=4;
carta[207]->valor=13;carta[207]->bitmap=52;carta[207]->tipo=4;
 // ES LA NOCARTA!!! (208)
carta[208]->valor=0;carta[208]->bitmap=LOGO;carta[208]->tipo=0;
carta[208]->mostrada=true;

cartas_colocadas=0;
num_mov=0;
carta_iluminada=carta_seleccionada=NOCARTA; // No hay carta seleccionada de momento
hemos_acabado=false;	// Pero si acaba de empezar el juego
x_ori=y_ori=z_ori=0.0f;	// Desplazamiento respecto al centro de la carta
						// cuando hemos pinchado con el raton
cambio_de_juego=false;
FASE_PRESENTACION=true;
juego_automatico=true;
esperar=false;
numero_juego=0;
columna_inicio=NOCOL;
columna_final=NOCOL;
numero_cartas=0;
mazo_juego=156;
ultima_columna=14;
for (int k=0;k<mazo_juego;k++) {
	carta[k]->x=0.f;
	carta[k]->y=0.f;
	carta[k]->z=crender.zcartas;  // -1.2f
	}
carta[208]->z=-1.2f;
primer_mov=new undos(NOCOL,NOCOL,1,0,NULL,NULL,false);
ultimo_mov=primer_mov;
actual_mov=primer_mov;
tipo_juego=G3;
redo=undo=false;
mover_permitido=true;
automatico_permitido=true;
descubierta=false;pases=0;
posX=0.f;
posY=-0.442f;
posZ=-0.133f;
viewX=0.f;
viewY=-0.016f;
viewZ=-1.273f;
vectorX=0.f;
vectorY=1.f;
vectorZ=0.f;
// Sonido
sonido_colocar = NULL;
colocarFile = WAV_COLOCAR;
if ( !sonido_colocar ){sonido_colocar = new wxSound;CreateSoundColocar(*sonido_colocar);}
}

//*****************//
	game::~game()
//*****************//
{
for(int i=0;i<209;i++){
	if(carta[i]!=NULL)   
		delete carta[i];}
for(int i=0;i<37;i++)
	{	
	if(golum[i]->ultimo_valor!=NULL)
		{
		while(golum[i]->ultimo_valor->ant!=NULL)
			{
			golum[i]->ultimo_valor=golum[i]->ultimo_valor->ant;
			delete(golum[i]->ultimo_valor->sig); // Liberamos puntero
			golum[i]->ultimo_valor->sig=NULL;
			}
		}
	if(golum[i]->primer_valor!=NULL) delete golum[i]->primer_valor;
	if(golum[i]!=NULL) delete golum[i];
	}

while(ultimo_mov->ant_mov!=NULL) {
	ultimo_mov=ultimo_mov->ant_mov;
	delete(ultimo_mov->sig_mov); // Liberamos puntero
	ultimo_mov->sig_mov=NULL;
	}
if(primer_mov!=NULL) delete primer_mov;
if(sonido_colocar)	delete sonido_colocar;
}

// CREA EL SONIDO PARA COLOCAR
// ---------------------------
bool game::CreateSoundColocar(wxSound& snd) const{
    return snd.Create(colocarFile);
}

//*************************************//
	void game::barajar(int a)
//*************************************//
{
int j;
int igual=0;
	if(!a){
		srand((unsigned)time(NULL));
		//printf("RANDMAX es %d\n",RAND_MAX);
		int numero_juego1=rand() % RAND_MAX; //2147483647 para DJGPP o 32767 para Dev-C++
		int numero_juego2=rand() % RAND_MAX; //Al multiplicar da un maximo de 1073676289
		numero_juego=numero_juego1*numero_juego2;
		//numero_juego=numero_juego1;
		srand(numero_juego);
	}else{
		srand(a);
	}
	//srand(40);	// Funciona. El juego 40 se puede realizar, pero dificil!!
				  	// Tambien el 103; curioso el 18481
	j=rand() % mazo_juego;  
	orden[0]=j;  // Primer resultado

	//printf("Numero 0 . %d\n",resultado[0]);

	for(int i=1; i<mazo_juego; i++){
		j=rand() % mazo_juego;
		for(int k=0;k<i;k++){
			if (orden[k]==j){
				igual=1;
				break;
			}
			else igual=0;
		}
		if (!igual)	{
			orden[i]=j;
			//	printf("Numero extraido en bola %d . %d\n",i,resultado[i]);
		}
		else{
			i--;
			//printf("Numero repetido: %d\n",j);
			//getch();
		}
	 }
	//inicio_especial();		 
}

//*********************************//
	void game::fase_presentacion()
//*********************************//
{
// PRIMERA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,10,true);
mueve_colum_reparto(0,11,true);mueve_colum_reparto(0,12,true);mueve_colum_reparto(0,13,true);
// SEGUNDA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,10,true);
mueve_colum_reparto(0,11,true);mueve_colum_reparto(0,12,true);mueve_colum_reparto(0,13,true);
// TERCERA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,10,true);
mueve_colum_reparto(0,11,true);mueve_colum_reparto(0,12,true);mueve_colum_reparto(0,13,true);
// CUARTA FILA
mueve_colum_reparto(0,2,true);mueve_colum_reparto(0,3,true);mueve_colum_reparto(0,4,true);
mueve_colum_reparto(0,5,true);mueve_colum_reparto(0,6,true);mueve_colum_reparto(0,7,true);
mueve_colum_reparto(0,8,true);mueve_colum_reparto(0,9,true);mueve_colum_reparto(0,10,true);
mueve_colum_reparto(0,11,true);mueve_colum_reparto(0,12,true);mueve_colum_reparto(0,13,true);
FASE_PRESENTACION=false;
}

//*******************************//
	void game::repetir_juego()
//*******************************//
{
for (int k=0;k<mazo_juego;k++) {
	carta[k]->x=0.f;
	carta[k]->y=0.f;
	carta[k]->z=crender.zcartas;  // -1.2f
	carta[k]->mostrada=false;
	carta[k]->seleccionada=false;
	}
carta[NOCARTA]->z=-1.2f;
cartas_colocadas=0;
carta_seleccionada=NOCARTA;
num_mov=0;
hemos_acabado=false;
FASE_PRESENTACION=true;
columna_inicio=NOCOL;
columna_final=NOCOL;
numero_cartas=0;
carta_iluminada=NOCARTA;
x_ori=y_ori=z_ori=0.0f;
cambio_de_juego=false;
esperar=false;
numero_cartas=0;
mazo_juego=156;
//Vaciar las golums de cartas
for(int i=0;i<36;i++)
	{
	golum[i]->num_cartas=0;
	golum[i]->num_sel=0;
	if(golum[i]->ultimo_valor!=NULL)
		{
		while(golum[i]->ultimo_valor->ant!=NULL)
			{
			golum[i]->ultimo_valor=golum[i]->ultimo_valor->ant;
			delete(golum[i]->ultimo_valor->sig); // Liberamos puntero
			golum[i]->ultimo_valor->sig=NULL;
			}
		}
	if(golum[i]->primer_valor!=NULL) delete golum[i]->primer_valor;
//	if(golum[i]!=NULL) delete golum[i];
	}
// Vaciar los undos y recrearlos
while(ultimo_mov->ant_mov!=NULL) {
	ultimo_mov=ultimo_mov->ant_mov;
	delete(ultimo_mov->sig_mov); // Liberamos puntero
	ultimo_mov->sig_mov=NULL;
	}
if(primer_mov!=NULL) delete primer_mov;
primer_mov=new undos(NOCOL,NOCOL,1,0,NULL,NULL,false);
ultimo_mov=primer_mov;
actual_mov=ultimo_mov;
juego_automatico=true;
}

//******************************//
	void game::inicio_especial()
//*****************************//
{
orden[0]=0;
 for(int i=1; i<mazo_juego; i++) orden[i]=i;
}

//***********************************//
	void game::ondobleclick(int cc)
//***********************************//
{
int karta=NOCARTA;
karta=que_carta_es(cc);
carta_seleccionada=karta;
if(karta!=NOCARTA && columna_inicio!=NOCOL) busca_sitio();
}

//****************************//
	bool game::repartir()
//***************************//
{
int cc;
// Meto la nocarta en todas las columnas validas
for (int k=0; k<num_golum;k++)	{
	golum[k]->primer_valor=new lista(NOCARTA,NULL,NULL);
	golum[k]->ultimo_valor=golum[k]->primer_valor;
	golum[k]->num_cartas=0;
	}
// Y toda la baraja en el mazo poco a poco
for(int k=0;k<mazo_juego;k++){
	cc=orden[mazo_juego-1-k];
	golum[0]->ultimo_valor->sig=new lista(cc,golum[0]->ultimo_valor,NULL);
	golum[0]->ultimo_valor=golum[0]->ultimo_valor->sig;
	carta[cc]->x=golum[0]->x+golum[0]->desp_x*k;
	carta[cc]->y=golum[0]->y+golum[0]->desp_y*k;
	carta[cc]->z=golum[0]->z+golum[0]->desp_z*k;
	golum[0]->num_cartas++;
	renderiza_ini();
	}
fase_presentacion();
mov_pendiente=false;
cuantas_serp=2;
return true;
}

//***************************************************************//
// Mueve cartas de una columna a otra y reasigna valores
// Lo hace a pantalla, pero solo para REPARTO inicial
void game::mueve_colum_reparto(int ini, int fin, bool mostrada)
//***************************************************************//
{
// Meto la primera carta de INI A FIN
// SERIA: muevo la carta de INI a FIN y cuando llegue alli
// La a�ado a FIN y luego la quito de INI
// La a�ado a FIN
// No se puede hacer directamente: HAY QUE UTILIZAR UNA VARIABLE AUXILIAR: CC
int cc=golum[ini]->ultimo_valor->carta;
float xfin=golum[fin]->x+(golum[fin]->desp_x*golum[fin]->num_cartas);
float yfin=golum[fin]->y+(golum[fin]->desp_y*golum[fin]->num_cartas);
float zfin=golum[fin]->z+(golum[fin]->desp_z*golum[fin]->num_cartas);
// La a�ado a FIN
golum[fin]->ultimo_valor->sig=new lista(cc,golum[fin]->ultimo_valor,NULL);
golum[fin]->ultimo_valor=golum[fin]->ultimo_valor->sig;
// La quito de INI
golum[ini]->ultimo_valor=golum[ini]->ultimo_valor->ant;
delete(golum[ini]->ultimo_valor->sig);
golum[ini]->ultimo_valor->sig=NULL;
if(golum[ini]->num_cartas) golum[ini]->num_cartas--;
// Reasigno valores x,y,z para la carta
movimiento_ini(xfin,yfin,zfin,cc);
carta[cc]->x=xfin;
carta[cc]->y=yfin;
carta[cc]->z=zfin;
if(mostrada) carta[cc]->mostrada=true;
else carta[cc]->mostrada=false;
golum[fin]->num_cartas++;
}

//*****************************************//
// Mueve UNA SOLA carta de una columna a otra y reasigna valores
// Lo hace a pantalla tambien
void game::mueve_golum(int ini, int fin)
//*****************************************//
{
// Meto la primera carta de INI A FIN
// SERIA: muevo la carta de INI a FIN y cuando llegue alli
// La a�ado a FIN y luego la quito de INI
// La a�ado a FIN
// No se puede hacer directamente: HAY QUE UTILIZAR UNA VARIABLE AUXILIAR: CC
int cc=golum[ini]->ultimo_valor->carta;
float xfin=golum[fin]->x+(golum[fin]->desp_x*golum[fin]->num_cartas);
float yfin=golum[fin]->y+(golum[fin]->desp_y*golum[fin]->num_cartas);
float zfin=golum[fin]->z+(golum[fin]->desp_z*golum[fin]->num_cartas);
if(fin==1 && golum[1]->num_cartas>58 && tipo_juego!=GOLF_AK2 && tipo_juego!=CANFIELD2){
	xfin=golum[1]->x+(golum[1]->desp_x*(golum[1]->num_cartas-59));
	yfin=golum[1]->y-0.05f;
	}
golum[fin]->ultimo_valor->sig=new lista(cc,golum[fin]->ultimo_valor,NULL);
golum[fin]->ultimo_valor=golum[fin]->ultimo_valor->sig;
if(!fin) carta[cc]->mostrada=false;	// Las CARTAS DEL MAZO ESTAN OCULTAS
if(!ini && undo) carta[cc]->mostrada=false;	// Las CARTAS DEL MAZO ESTAN OCULTAS
if(fin==1 && ini>1 && (tipo_juego==GOLF || tipo_juego==GOLF_AK || tipo_juego==GOLF_AK2 || tipo_juego==DOUBLES || tipo_juego==DOUBLES13)) retroceso=false;
if(redo || undo) retroceso=true;
movimiento(xfin,yfin,zfin,cc);
carta[cc]->x=xfin;
carta[cc]->y=yfin;
carta[cc]->z=zfin;

// La quito de INI
golum[ini]->ultimo_valor=golum[ini]->ultimo_valor->ant;
delete(golum[ini]->ultimo_valor->sig);
golum[ini]->ultimo_valor->sig=NULL;

if(golum[ini]->num_cartas) golum[ini]->num_cartas--;
// Para compatibilidad con selecciones (cosa rara) y para que vaya mas rapido
if(fin==1 || !fin) {
	golum[fin]->num_cartas++;retroceso=true;
	}
if(!fin) carta[cc]->mostrada=false;	// Las CARTAS DEL MAZO ESTAN OCULTAS
else carta[cc]->mostrada=true;
carta[cc]->seleccionada=false;
if(fin!=1 && fin) golum[fin]->num_cartas++; // Ya se sumaron antes
golum[ini]->num_sel=0;
retroceso=false;
}

//******************************************************//
// Mueve VARIAS CARTAS de una columna a otra y reasigna valores
// Lo hace a pantalla tambien
void game::mueve_multigolum(int ini, int fin)
//******************************************************//
{
// Meto la primera carta de INI A FIN
// SERIA: muevo la carta de INI a FIN y cuando llegue alli
// La añado a FIN y luego la quito de INI
// La añado a FIN
// No se puede hacer directamente: HAY QUE UTILIZAR UNA VARIABLE AUXILIAR: CC
lista *alfa=NULL;
int cc;
float xfin,yfin,zfin;
columna_final=fin;
if(undo)
	{
	alfa=golum[fin]->ultimo_valor;
	if(descubierta) carta[alfa->carta]->mostrada=false;
	}

alfa=golum[ini]->primer_valor->sig;
// Busco donde esta la carta seleccionada
for (int i=0;i<golum[ini]->num_cartas;i++)
	{
	if(alfa->carta==carta_seleccionada) {break;}
	else if(alfa->sig!=NULL) alfa=alfa->sig;
	}
// Hago el movimiento
if(redo || undo || !fin || !ini) retroceso=true;
// Para RAIL1 y RAIL2 retroceso es true
if(fin==1 && ini>1 && golum[ini]->textura==FINAL_G && tipo_juego != RAIL1 && tipo_juego != RAIL2) 
	retroceso=false;
cc=alfa->carta;
xfin=golum[fin]->x+(golum[fin]->desp_x*golum[fin]->num_cartas);
yfin=golum[fin]->y+(golum[fin]->desp_y*golum[fin]->num_cartas);
// Correccion efectuada el 23/02/2005
// Si no hay cartas el AS puede desaparecer (de ahi el mas 1)
zfin=golum[fin]->z+(golum[fin]->desp_z*golum[fin]->num_cartas);
if(fin==1 && golum[1]->num_cartas>58 && tipo_juego!=GOLF_AK2 && tipo_juego!=CANFIELD2){
	xfin=golum[1]->x+(golum[1]->desp_x*(golum[1]->num_cartas-59));
	yfin=golum[1]->y-0.05f;
	}
if(!fin) carta[cc]->mostrada=false;	// Las CARTAS DEL MAZO ESTAN OCULTAS
if(!ini && undo) carta[cc]->mostrada=false;	// Las CARTAS DEL MAZO ESTAN OCULTAS
movimiento(xfin,yfin,zfin,cc);	// Ya este movimiento las mueve todas

for(int kk=0;kk<golum[ini]->num_sel;kk++)
	{
	cc=alfa->carta;
	if(!fin) carta[cc]->mostrada=false;	// Las CARTAS DEL MAZO ESTAN OCULTAS
	else carta[cc]->mostrada=true;
	carta[cc]->seleccionada=false;
	// La/s a�ado a FIN
	golum[fin]->ultimo_valor->sig=new lista(cc,golum[fin]->ultimo_valor,NULL);
	golum[fin]->ultimo_valor=golum[fin]->ultimo_valor->sig;
	golum[fin]->num_cartas++;
	if(alfa->sig!=NULL) alfa=alfa->sig;
	}
// La/s quito de INI
for(int kk=0;kk<golum[ini]->num_sel;kk++)
	{
	golum[ini]->ultimo_valor=golum[ini]->ultimo_valor->ant;
	delete(golum[ini]->ultimo_valor->sig);
	golum[ini]->ultimo_valor->sig=NULL;
	}
golum[ini]->num_cartas=golum[ini]->num_cartas-golum[ini]->num_sel;
golum[ini]->num_sel=0;
// Ponemos la ultima carta de la columna como mostrada, menos el mazo
if(ini)
	{ 
	if(!carta[golum[ini]->ultimo_valor->carta]->mostrada)
		{
		carta[golum[ini]->ultimo_valor->carta]->mostrada=true;
		descubierta=true;	// Para el deshacer
		}
	}
retroceso=false;
}

//******************************************//
// Identifica la carta que se ha pinchado
int game::que_carta_es(int cc)
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
else if(cc==1 && !golum[0]->num_cartas)	// Es la ultima carta de la pila que ahora tiene
	{									// seleccion 1!!!
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

//*****************************************************//
// Devuelve TRUE si la carta es seleccionable
// segun las reglas del juego
bool game::es_seleccionable(int cc,int c)
//****************************************************//
{
if (cc==golum[c]->ultimo_valor->carta)
	{
	carta[cc]->seleccionada=true;
	golum[c]->num_sel=1;
	return true;
	}
else return false;
}

//************************************//
// Mueve de una columna a otra efectivamente
// si se verifican las reglas del juego
bool game::mover(int ini, int fin)
//***********************************//
{
int karta=NOCARTA;
// Del MAZO a la PILA
if(ini==0 && fin==1){
	afin=false;
	karta=golum[0]->ultimo_valor->carta;
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
	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	descubierta=false;
	return true;
	}	
// Se puede colocar de una COLUMNA/PILA a COLUMNA NO VACIAS
else if (golum[fin]->num_cartas && 
	carta[carta_seleccionada]->tipo ==carta[golum[fin]->ultimo_valor->carta]->tipo &&
	carta[carta_seleccionada]->valor==carta[golum[fin]->ultimo_valor->carta]->valor-1)
	{
	afin=false;
	mueve_golum(ini,fin);
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

	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	descubierta=false;
	return true;
	}
// Se puede colocar en una COLUMNA VACIA
else if (!golum[fin]->num_cartas)
	{
	afin=false;
	mueve_golum(ini,fin);
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

	columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
	num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
	descubierta=false;
	return true;
	}
else return false;
}

//**************************************//
	void game::mover_a_columna(int cc)
//**************************************//
{
lista *alfa;
int c;
//int karta=NOCARTA;
int ci=columna_inicio;

if(cc==1 && golum[0]->num_cartas)	// MAZO
	{
	// Primero nos cepillamos las posibles cartas seleccionadas
	alfa=golum[ci]->primer_valor->sig;
	for(int k=0;k<golum[ci]->num_cartas;k++){
		carta[alfa->carta]->seleccionada=false;
		alfa=alfa->sig;
		}
	golum[ci]->num_sel=0;
	mover(0,1);
	}
else if(cc==1 && !golum[0]->num_cartas)	// Es la ultima carta de la pila
	{									// que ahora tiene seleccion 1!!!
	if(golum[1]->num_cartas)
		{
		columna_final=NOCOL;		// No se permite mover cartas a la pila
		}
	else if(!golum[1]->num_cartas)	// Hemos pinchado una PILA sin cartas
		{
		columna_final=NOCOL;		// No se permite mover cartas a la pila
		}
	}
if(cc==2)	// PILA
	{
	if(golum[1]->num_cartas)
		{
		columna_final=NOCOL;		// No se permite mover cartas a la pila
		}
	else if(!golum[1]->num_cartas)	// Hemos pinchado una PILA sin cartas
		{
		columna_final=NOCOL;
		}
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

//*********************************************************
// Mira si la carta en cuestion cabe en alguna pila final	
	bool game::colocar_carta(int n,int ini)
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
			if (activar_sonido && sonido_colocar->IsOk())	sonido_colocar->Play(wxSOUND_ASYNC);
			devolver=true;cartas_colocadas++;
			num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
			columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
			descubierta=false;
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
			if (activar_sonido && sonido_colocar->IsOk())	sonido_colocar->Play(wxSOUND_ASYNC);
			devolver=true;cartas_colocadas++;
			num_mov++;if(esperar) {esperar=false;}//juego_automatico=true;}
			columna_inicio=columna_final=NOCOL;carta_seleccionada=NOCARTA;
			descubierta=false;
			break;
			}
		}
	}
return devolver;
}

//**********************************************
// Coloca cartas automaticamente de las columnas
	bool game::automatico(void)
//**********************************************
{
// FUNCION RECURSIVA. DEVUELVE VERDAD SI HA HABIDO COLOCACION DE CARTA
// EN PILA INFERIOR Y NO SE CANCELA HASTA QUE SE REVISE Y DEVUELVA FALSO
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

	for (l=2;l<ultima_columna;l++)	// Colocamos cartas de las columnas
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

	if(!golum[1]->num_cartas)	// No hay cartas en la pila
		{
		vuelta=false;break;
		}
	else if(golum[1]->num_cartas && !salir)	// Colocamos cartas de la pila
		{
		for(r=golum[1]->num_cartas;r;r--)
			{
			alfa=golum[1]->ultimo_valor;
			columna_inicio=1;
			carta_seleccionada=alfa->carta;
			if (!colocar_carta(carta_seleccionada,1)) {vuelta=false;break;}
			else {vuelta=true;break;}
			}	
		}	// Fin de los ifs
	}	// Fin del while
if (cs==NOCARTA) recolocar();
columna_inicio=ci;
carta_seleccionada=cs;
mov_pendiente=mv;
return vuelta;
}

//*********************************************************************//
// Busca automaticamente un sitio para la carta seleccionada o agarrada
	void game::busca_sitio(void)
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

// ESTE PROCESO COMENTADO SE REFIERE A QUE LE JUGADOR INTENTA COLOCAR
// EN UN SITIO DETERMINADO Y HAY QUE RECODIFICARLO SIN FILAS[] NI COLUMNAS[]
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
	for(int k=2;k<ultima_columna;k++)
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
	// Este no es su sitio. Hay que hacerlo para multiples cartas
	xf=golum[ci]->x+golum[ci]->desp_x*(golum[ci]->num_cartas-golum[ci]->num_sel);
	yf=golum[ci]->y+golum[ci]->desp_y*(golum[ci]->num_cartas-golum[ci]->num_sel);
	zf=golum[ci]->z+golum[ci]->desp_z*(golum[ci]->num_cartas-golum[ci]->num_sel);
	if(ci==1 && golum[1]->num_cartas>59 && tipo_juego!=GOLF_AK2 && tipo_juego!=CANFIELD2){
		xf=golum[1]->x+(golum[1]->desp_x*(golum[1]->num_cartas-60));
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

//**************************************//
// Busca automaticamente un sitio para la carta de la pila
void game::busca_sitio_boton_derecho()
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
		for(int k=2;k<ultima_columna;k++)
			{
			if(golum[k]->num_cartas && mover(1,k)) colocada=true;
			}
		}
	if(juego_automatico && mov_pendiente && !colocada)	// Es una carta que debe volver a su sitio
		{
		columna_inicio=1;afin=false;
		float x=golum[1]->x+golum[1]->desp_x*(golum[1]->num_cartas-1);
		float y=golum[1]->y+golum[1]->desp_y*(golum[1]->num_cartas-1);
		float z=golum[1]->z+golum[1]->desp_z*(golum[1]->num_cartas-1);
		if(golum[1]->num_cartas>58 && tipo_juego!=GOLF_AK2 && tipo_juego!=CANFIELD2){
			x=golum[1]->x+(golum[1]->desp_x*(golum[1]->num_cartas-59));
			y=golum[1]->y-0.05f;
			}
		movimiento(x,y,z,carta_seleccionada);
		}
	}
golum[1]->num_sel=0;
carta[cs]->seleccionada=false;
carta_seleccionada=NOCARTA;columna_inicio=NOCOL;mov_pendiente=false;
}

//*************************************************************//
//	Atras                                
	bool game::deshacer(void)
// Devuelve true si ha habido retroceso y false si no
// Si es true entonces hay que esperar a un movimiento para
// activar el automatico en el caso de que estuviera activado
//*************************************************************//
{
int ini,fin,cuantos,sel;
bool descu=descubierta;
bool desh=true;
bool automatic=juego_automatico;
lista *alfa;
cuantos=actual_mov->cuantas;
if((tipo_juego==KLONDIKE2 || tipo_juego==G40Y8) && cuantos>1 && pases){pases=0;golum[0]->textura=MAZO_SI;}
if(juego_automatico) juego_automatico=false;

for(;cuantos;cuantos--){
	if (actual_mov->ant_mov!=NULL)	// No estamos en primer elemento de la lista
		{
		ini=actual_mov->ini;
		fin=actual_mov->fin;
		sel=actual_mov->selec;
		descubierta=actual_mov->oculta;
		mov_pendiente=true;
		if(!ini) carta[carta_seleccionada]->mostrada=false;
		if(golum[fin]->tipo==3) {afin=true;cartas_colocadas=cartas_colocadas-sel;}
		else if(fin==1 && (tipo_juego==GOLF || tipo_juego==GOLF_AK || tipo_juego==GOLF_AK2 || tipo_juego==DOUBLES || tipo_juego==DOUBLES13)) {afin=true;cartas_colocadas--;}
		else afin=false;
		undo=true;
		golum[fin]->num_sel=sel;
		columna_inicio=fin;
		alfa=golum[fin]->ultimo_valor;
		for(int p=0;p<sel;p++){
			carta[alfa->carta]->seleccionada=true;
			if(p < sel-1) alfa=alfa->ant;	// Para que la ultima vez no lo haga
			}
		carta_seleccionada=alfa->carta;
		mueve_multigolum(fin,ini);
		columna_inicio=NOCOL;
		mov_pendiente=false;
		actual_mov=actual_mov->ant_mov;
		}
	else desh=false; // ESTAMOS EN PRIMER MOVIMIENTO, SE PODRIA DAR UN PITIDO
	}
juego_automatico=automatic;undo=false;
if(desh) num_mov--;
recolocar();
carta_seleccionada=NOCARTA;columna_inicio=columna_final=NOCOL;
descubierta=descu;	// Para no cambiar el valor de descubierta
return desh;
}

//*****************************************************************//
//	Adelante
	bool game::rehacer(void)
// Devuelve true si ha habido avance y false si no
// Si es true entonces hay que esperar a un movimiento 
// para activar el automatico en el caso de que estuviera activado
//*****************************************************************//
{
int ini,fin,cuantos,sel;
bool desh=true;
bool descu=descubierta;
bool automatic=juego_automatico;
lista *alfa;
if(juego_automatico) juego_automatico=false;

if (actual_mov->sig_mov!=NULL)	// No estamos en ultimo elemento de la lista
	{
	do	{
		ini=actual_mov->sig_mov->ini;
		fin=actual_mov->sig_mov->fin;
		cuantos=actual_mov->sig_mov->cuantas;
		if(tipo_juego==KLONDIKE2 && cuantos>1 && !pases){pases=1;golum[0]->textura=MAZO_NO;}
		sel=actual_mov->sig_mov->selec;
		descubierta=actual_mov->sig_mov->oculta;	// Hay que recuperar el valor de descubierta
		mov_pendiente=true;							// sino se puede tapar alguna carta que no corresponda
		if(golum[fin]->tipo==3) {afin=true;cartas_colocadas=cartas_colocadas+sel;}
		// Los juegos en los que la PILA hace de columna final
		else if(fin==1 && (tipo_juego==GOLF || tipo_juego==GOLF_AK || tipo_juego==GOLF_AK2 || tipo_juego==DOUBLES || tipo_juego==DOUBLES13)) {afin=true;cartas_colocadas++;}
		else afin=false;
		redo=true;
		golum[ini]->num_sel=sel;
		columna_inicio=ini;
		alfa=golum[ini]->ultimo_valor;
		for(int p=0;p<sel;p++){
			carta[alfa->carta]->seleccionada=true;
			if(p < sel-1) alfa=alfa->ant;	// Para que la ultima vez no lo haga
			}
		carta_seleccionada=alfa->carta;
		mueve_multigolum(ini,fin);
		columna_inicio=NOCOL;
		mov_pendiente=false;
		actual_mov=actual_mov->sig_mov;
		} while(actual_mov->sig_mov!=NULL && actual_mov->sig_mov->cuantas>cuantos);
	}
else desh=false; // ESTAMOS EN PRIMER MOVIMIENTO, SE PODRIA DAR UN PITIDO
juego_automatico=automatic;redo=false;
if(desh) num_mov++;
recolocar();
carta_seleccionada=NOCARTA;columna_inicio=columna_final=NOCOL;
descubierta=descu;
return desh;
}

//**********************************************
// Recoloca cartas de las columnas
	void game::recolocar(void)
//**********************************************
{
// Recoloca las cartas de las golums para que quepan
// Estos son los juegos en los que no se recolocan cartas
if(tipo_juego==GOLF		|| 
   tipo_juego==GOLF_AK	||
   tipo_juego==GOLF_AK2 ||
   tipo_juego==G4		||
   tipo_juego==IX		||
   tipo_juego==LUCKY	||
   tipo_juego==MONTANA) return;
   
lista *alfa=NULL;
for(int k=2;k<ultima_columna;k++)
	{
	// Recolocamos golums en y
	if(golum[k]->num_cartas && golum[k]->num_cartas<20 && golum[k]->desp_y!=-0.03f)
		{
		golum[k]->desp_y=-0.03f;
		alfa=golum[k]->primer_valor->sig;
		for(int m=0;m<golum[k]->num_cartas;m++)
			{
			carta[alfa->carta]->y=golum[k]->y+golum[k]->desp_y*m;
			alfa=alfa->sig;
			}
		}
	else if(golum[k]->num_cartas>19)
		{
		golum[k]->desp_y=-0.57f/(float)(golum[k]->num_cartas-1);
		alfa=golum[k]->primer_valor->sig;
		for(int m=0;m<golum[k]->num_cartas;m++)
			{
			carta[alfa->carta]->y=golum[k]->y+golum[k]->desp_y*m;
			alfa=alfa->sig;
			}
		}
	}
}


/*	
// Ilumina un sitio al pasar la carta seleccionada donde puede ir
	void game::ilumina_sitio(void)
// ---------------------------------------------------------------
{
bool colocada=false;
int cs=carta_seleccionada;
int ci=columna_inicio;
// Primero miramos si el jugador intenta colocar la carta
// en una columna determinada
for(int k=0;k<num_golum-1;k++) 
	{			// El ANCHO de carta y el ALTO de carta
	if(carta[cs]->x>columna[k+1]-0.04f     && 
	   carta[cs]->x<columna[k+1]+0.04f     &&
       carta[cs]->y>(fila[num_cartas[k]+1]-0.12f) &&
       carta[cs]->y<(fila[num_cartas[k]+1]+0.12f) &&
       ci!=PILA)
		{
		if(k==ci && num_cartas[k]>1)	// Es la misma columna; la dejamos donde esta
			{
			if(carta[cs]->tipo == carta[col[k][num_cartas[k]-2]]->tipo &&
			   carta[cs]->valor==juego->carta[col[k][num_cartas[k]-2]]->valor-1)
			     carta_iluminada=col[k][num_cartas[k]-2];
			else carta_iluminada=NOCARTA;
			break;
			}
		else if(mover_carta(ci,k,false))
			{
			carta_iluminada=col[k][num_cartas[k]-1];		
			break;
			}
		else
			{
			carta_iluminada=NOCARTA;
			carta_seleccionada=cs;
			columna_inicio=ci;
			}
		}  // Ahora queremos mover la carta de la pila a un sitio determinado
	else if (num_cartas[k] &&
			 carta[cs]->tipo ==carta[col[k][num_cartas[k]-1]]->tipo &&
			 carta[cs]->valor==carta[col[k][num_cartas[k]-1]]->valor-1 &&
			 carta[cs]->x>columna[k+1]-0.04f     &&
	         carta[cs]->x<columna[k+1]+0.04f	   &&
			 carta[cs]->y>(fila[num_cartas[k]+1]-0.12f) &&
			 carta[cs]->y<(fila[num_cartas[k]+1]+0.12f))
			                         
		{
		if(mover_carta(ci,k,false))
			{
			carta_iluminada=col[k][num_cartas[k]-1];
			break;
			}
		else
			{
			carta_iluminada=NOCARTA;
			carta_seleccionada=cs;
			columna_inicio=ci;
			}
		}
	}	// Fin del for
carta_seleccionada=cs;columna_inicio=ci;
}
*/

