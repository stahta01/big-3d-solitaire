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
// Class automatically generated by Dev-C++ New Class wizard

#ifndef MONTANA_H
#define MONTANA_H

#include "game.h" // inheriting class's header file

/*
 * No description
 */
class montana : public game
{
public:
    float	xmon,ymon,zmon;	// Es la posicion original de la carta seleccionada
                            // por si tiene que volver a su sitio
    int		lugar_ini;		// Lugar donde estaba la carta pinchada
	int	pases;			// Pases posibles (son tres)
    void	fase_presentacion();
	bool	es_seleccionable(int cc,int c);
	void	busca_sitio_boton_derecho();
	void	busca_sitio(void);
	int		que_carta_es(int cc);
	bool	colocar_carta(int n,int ini);
	void	repetir_juego();
	void	barajar_resto();
	void	recuento();
	bool	mover(int ini,int k);
	bool	rehacer(void);
	bool	deshacer(void);
			montana();
	virtual	~montana();
};

#endif // MONTANA_H

