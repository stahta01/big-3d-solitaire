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
// spider2.cpp: implementation of the spider2 class.
//
//////////////////////////////////////////////////////////////////////

#include "spider2.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

spider2::spider2()
{
//spider();
tipo_juego=SPIDER2;
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

carta[13]->valor= 1;carta[13]->bitmap=27;carta[13]->tipo=3;carta[13]->color=true;
carta[14]->valor= 2;carta[14]->bitmap=28;carta[14]->tipo=3;carta[14]->color=true;
carta[15]->valor= 3;carta[15]->bitmap=29;carta[15]->tipo=3;carta[15]->color=true;
carta[16]->valor= 4;carta[16]->bitmap=30;carta[16]->tipo=3;carta[16]->color=true;
carta[17]->valor= 5;carta[17]->bitmap=31;carta[17]->tipo=3;carta[17]->color=true;
carta[18]->valor= 6;carta[18]->bitmap=32;carta[18]->tipo=3;carta[18]->color=true;
carta[19]->valor= 7;carta[19]->bitmap=33;carta[19]->tipo=3;carta[19]->color=true;
carta[20]->valor= 8;carta[20]->bitmap=34;carta[20]->tipo=3;carta[20]->color=true;
carta[21]->valor= 9;carta[21]->bitmap=35;carta[21]->tipo=3;carta[21]->color=true;
carta[22]->valor=10;carta[22]->bitmap=36;carta[22]->tipo=3;carta[22]->color=true;
carta[23]->valor=11;carta[23]->bitmap=37;carta[23]->tipo=3;carta[23]->color=true;
carta[24]->valor=12;carta[24]->bitmap=38;carta[24]->tipo=3;carta[24]->color=true;
carta[25]->valor=13;carta[25]->bitmap=39;carta[25]->tipo=3;carta[25]->color=true;

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

carta[65]->valor= 1;carta[65]->bitmap=27;carta[65]->tipo=3;carta[65]->color=true;
carta[66]->valor= 2;carta[66]->bitmap=28;carta[66]->tipo=3;carta[66]->color=true;
carta[67]->valor= 3;carta[67]->bitmap=29;carta[67]->tipo=3;carta[67]->color=true;
carta[68]->valor= 4;carta[68]->bitmap=30;carta[68]->tipo=3;carta[68]->color=true;
carta[69]->valor= 5;carta[69]->bitmap=31;carta[69]->tipo=3;carta[69]->color=true;
carta[70]->valor= 6;carta[70]->bitmap=32;carta[70]->tipo=3;carta[70]->color=true;
carta[71]->valor= 7;carta[71]->bitmap=33;carta[71]->tipo=3;carta[71]->color=true;
carta[72]->valor= 8;carta[72]->bitmap=34;carta[72]->tipo=3;carta[72]->color=true;
carta[73]->valor= 9;carta[73]->bitmap=35;carta[73]->tipo=3;carta[73]->color=true;
carta[74]->valor=10;carta[74]->bitmap=36;carta[74]->tipo=3;carta[74]->color=true;
carta[75]->valor=11;carta[75]->bitmap=37;carta[75]->tipo=3;carta[75]->color=true;
carta[76]->valor=12;carta[76]->bitmap=38;carta[76]->tipo=3;carta[76]->color=true;
carta[77]->valor=13;carta[77]->bitmap=39;carta[77]->tipo=3;carta[77]->color=true;

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

spider2::~spider2()
{

}
