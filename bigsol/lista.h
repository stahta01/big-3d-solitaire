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
// lista.h: interface for the lista class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_LISTA_H__)
#define _LISTA_H__

class lista{
public:
	
	int carta;	// Que carta es, de 0 en adelante
	lista *sig;				// Puntero a la carta siguiente 
	lista *ant;				// Puntero a la carta anterior

	
	lista();
	lista(int c,lista *a,lista *s);
	virtual ~lista();

};

#endif
