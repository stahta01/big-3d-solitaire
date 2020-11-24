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
// Point3D.h: interface for the Point3D class.
//
//////////////////////////////////////////////////////////////////////

#ifndef POINT3D_H_INCLUDED
#define POINT3D_H_INCLUDED

#include <math.h>

class Point3D  
{
public:
	float x;
	float y;
	float z;
	Point3D();
	Point3D( float x, float y, float z );
	//Point3D( String line );
	virtual ~Point3D();
	void setPos( float _x, float _y, float _z );
	static double distance( Point3D p1, Point3D p2 );
	bool equals( Point3D ob );
	Point3D operator + (Point3D vVector2);
	Point3D operator - (Point3D vVector2);
	Point3D operator * (float num);
	Point3D operator / (float num);
};

#endif
