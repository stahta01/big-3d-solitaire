/*
Big Solitaries 3D
Copyright (C) 2006  Félix José Cladellas

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
// spider1.cpp: implementation of the spider1 class.
//
//////////////////////////////////////////////////////////////////////

#include "spider1.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

spider1::spider1()
{
//spider();
tipo_juego=SPIDER1;
// Cambiamos los valores de las cartas para solo dos palos: TREBOLES Y CORAZONES
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

carta[13]->valor= 1;carta[13]->bitmap=1;carta[13]->tipo=1;
carta[14]->valor= 2;carta[14]->bitmap=2;carta[14]->tipo=1;
carta[15]->valor= 3;carta[15]->bitmap=3;carta[15]->tipo=1;
carta[16]->valor= 4;carta[16]->bitmap=4;carta[16]->tipo=1;
carta[17]->valor= 5;carta[17]->bitmap=5;carta[17]->tipo=1;
carta[18]->valor= 6;carta[18]->bitmap=6;carta[18]->tipo=1;
carta[19]->valor= 7;carta[19]->bitmap=7;carta[19]->tipo=1;
carta[20]->valor= 8;carta[20]->bitmap=8;carta[20]->tipo=1;
carta[21]->valor= 9;carta[21]->bitmap=9;carta[21]->tipo=1;
carta[22]->valor=10;carta[22]->bitmap=10;carta[22]->tipo=1;
carta[23]->valor=11;carta[23]->bitmap=11;carta[23]->tipo=1;
carta[24]->valor=12;carta[24]->bitmap=12;carta[24]->tipo=1;
carta[25]->valor=13;carta[25]->bitmap=13;carta[25]->tipo=1;

carta[26]->valor= 1;carta[26]->bitmap=1;carta[26]->tipo=1;
carta[27]->valor= 2;carta[27]->bitmap=2;carta[27]->tipo=1;
carta[28]->valor= 3;carta[28]->bitmap=3;carta[28]->tipo=1;
carta[29]->valor= 4;carta[29]->bitmap=4;carta[29]->tipo=1;
carta[30]->valor= 5;carta[30]->bitmap=5;carta[30]->tipo=1;
carta[31]->valor= 6;carta[31]->bitmap=6;carta[31]->tipo=1;
carta[32]->valor= 7;carta[32]->bitmap=7;carta[32]->tipo=1;
carta[33]->valor= 8;carta[33]->bitmap=8;carta[33]->tipo=1;
carta[34]->valor= 9;carta[34]->bitmap=9;carta[34]->tipo=1;
carta[35]->valor=10;carta[35]->bitmap=10;carta[35]->tipo=1;
carta[36]->valor=11;carta[36]->bitmap=11;carta[36]->tipo=1;
carta[37]->valor=12;carta[37]->bitmap=12;carta[37]->tipo=1;
carta[38]->valor=13;carta[38]->bitmap=13;carta[38]->tipo=1;

carta[39]->valor= 1;carta[39]->bitmap=1;carta[39]->tipo=1;
carta[40]->valor= 2;carta[40]->bitmap=2;carta[40]->tipo=1;
carta[41]->valor= 3;carta[41]->bitmap=3;carta[41]->tipo=1;
carta[42]->valor= 4;carta[42]->bitmap=4;carta[42]->tipo=1;
carta[43]->valor= 5;carta[43]->bitmap=5;carta[43]->tipo=1;
carta[44]->valor= 6;carta[44]->bitmap=6;carta[44]->tipo=1;
carta[45]->valor= 7;carta[45]->bitmap=7;carta[45]->tipo=1;
carta[46]->valor= 8;carta[46]->bitmap=8;carta[46]->tipo=1;
carta[47]->valor= 9;carta[47]->bitmap=9;carta[47]->tipo=1;
carta[48]->valor=10;carta[48]->bitmap=10;carta[48]->tipo=1;
carta[49]->valor=11;carta[49]->bitmap=11;carta[49]->tipo=1;
carta[50]->valor=12;carta[50]->bitmap=12;carta[50]->tipo=1;
carta[51]->valor=13;carta[51]->bitmap=13;carta[51]->tipo=1;

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

carta[65]->valor= 1;carta[65]->bitmap=1;carta[65]->tipo=1;
carta[66]->valor= 2;carta[66]->bitmap=2;carta[66]->tipo=1;
carta[67]->valor= 3;carta[67]->bitmap=3;carta[67]->tipo=1;
carta[68]->valor= 4;carta[68]->bitmap=4;carta[68]->tipo=1;
carta[69]->valor= 5;carta[69]->bitmap=5;carta[69]->tipo=1;
carta[70]->valor= 6;carta[70]->bitmap=6;carta[70]->tipo=1;
carta[71]->valor= 7;carta[71]->bitmap=7;carta[71]->tipo=1;
carta[72]->valor= 8;carta[72]->bitmap=8;carta[72]->tipo=1;
carta[73]->valor= 9;carta[73]->bitmap=9;carta[73]->tipo=1;
carta[74]->valor=10;carta[74]->bitmap=10;carta[74]->tipo=1;
carta[75]->valor=11;carta[75]->bitmap=11;carta[75]->tipo=1;
carta[76]->valor=12;carta[76]->bitmap=12;carta[76]->tipo=1;
carta[77]->valor=13;carta[77]->bitmap=13;carta[77]->tipo=1;

carta[78]->valor= 1;carta[78]->bitmap=1;carta[78]->tipo=1;
carta[79]->valor= 2;carta[79]->bitmap=2;carta[79]->tipo=1;
carta[80]->valor= 3;carta[80]->bitmap=3;carta[80]->tipo=1;
carta[81]->valor= 4;carta[81]->bitmap=4;carta[81]->tipo=1;
carta[82]->valor= 5;carta[82]->bitmap=5;carta[82]->tipo=1;
carta[83]->valor= 6;carta[83]->bitmap=6;carta[83]->tipo=1;
carta[84]->valor= 7;carta[84]->bitmap=7;carta[84]->tipo=1;
carta[85]->valor= 8;carta[85]->bitmap=8;carta[85]->tipo=1;
carta[86]->valor= 9;carta[86]->bitmap=9;carta[86]->tipo=1;
carta[87]->valor=10;carta[87]->bitmap=10;carta[87]->tipo=1;
carta[88]->valor=11;carta[88]->bitmap=11;carta[88]->tipo=1;
carta[89]->valor=12;carta[89]->bitmap=12;carta[89]->tipo=1;
carta[90]->valor=13;carta[90]->bitmap=13;carta[90]->tipo=1;

carta[91]->valor= 1;carta[91]->bitmap=1;carta[91]->tipo=1;
carta[92]->valor= 2;carta[92]->bitmap=2;carta[92]->tipo=1;
carta[93]->valor= 3;carta[93]->bitmap=3;carta[93]->tipo=1;
carta[94]->valor= 4;carta[94]->bitmap=4;carta[94]->tipo=1;
carta[95]->valor= 5;carta[95]->bitmap=5;carta[95]->tipo=1;
carta[96]->valor= 6;carta[96]->bitmap=6;carta[96]->tipo=1;
carta[97]->valor= 7;carta[97]->bitmap=7;carta[97]->tipo=1;
carta[98]->valor= 8;carta[98]->bitmap=8;carta[98]->tipo=1;
carta[99]->valor= 9;carta[99]->bitmap=9;carta[99]->tipo=1;
carta[100]->valor=10;carta[100]->bitmap=10;carta[100]->tipo=1;
carta[101]->valor=11;carta[101]->bitmap=11;carta[101]->tipo=1;
carta[102]->valor=12;carta[102]->bitmap=12;carta[102]->tipo=1;
carta[103]->valor=13;carta[103]->bitmap=13;carta[103]->tipo=1;
}

spider1::~spider1()
{

}
