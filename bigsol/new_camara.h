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
// new_camara.h: interface for the new_camara class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_NEW_CAMARA_H__)
#define _NEW_CAMARA_H__

#include "Point3D.h"

class new_camara  
{
public:
	// This is our camera class
	Point3D m_vPosition;	// The camera's position
	Point3D m_vView;		// The camera's View
	Point3D m_vUpVector;	// The camera's UpPoint3D
	new_camara();
	virtual ~new_camara();
	void Look();
	void PositionCamera(float positionX, float positionY, float positionZ,
						float viewX,     float viewY,     float viewZ,
						float upPoint3DX,float upPoint3DY,float upPoint3DZ );
	void rotateView( float X, float Y, float Z );
	//bool MoveCameraByMouse( Point prevPoint, Point mousePos );
	void RotateAroundPoint( float X, float Y, float Z);
	void RotateAroundPoint( Point3D vCenter, float X, float Y, float Z);
	Point3D getVectorRightAnglesAwayFromCamera();
	void StrafeCamera(float speed);
	void raiseCameraX( float amount );
	void raiseCameraY( float amount );
	void raiseCameraZ( float amount );
	void MoveCameraXZ(float speed);
	void MoveCameraYZ(float speed);
	void MoveCameraXY(float speed);
};

#endif
