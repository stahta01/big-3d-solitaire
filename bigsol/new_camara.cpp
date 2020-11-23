/*
Big Solitaries 3D
Copyright (C) 2006  Félix José Cladellas

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
// new_camara.cpp: implementation of the new_camara class.
//
//////////////////////////////////////////////////////////////////////


#include "new_camara.h"

new_camara::new_camara()
{
Point3D vZero = Point3D( 0.0f, 0.0f, 0.0f );
Point3D vView = Point3D( 0.0f, 0.0f, -0.5f );
Point3D vUp   = Point3D( 0.0f, 1.0f, 0.0f );

m_vPosition	= vZero;
m_vView		= vView;
m_vUpVector	= vUp;
}


void new_camara::Look()
{
}

void new_camara::PositionCamera(float positionX, float positionY, float positionZ,
	                            float viewX,     float viewY,     float viewZ,
								float upPoint3DX,float upPoint3DY,float upPoint3DZ )
{
m_vPosition.setPos( positionX, positionY, positionZ );
m_vView.setPos( viewX, viewY, viewZ );
m_vUpVector.setPos( upPoint3DX, upPoint3DY, upPoint3DZ );
}


void new_camara::rotateView( float X, float Y, float Z )
{
Point3D Point3D;

Point3D.x = m_vView.x - m_vPosition.x;
Point3D.y = m_vView.y - m_vPosition.y;
Point3D.z = m_vView.z - m_vPosition.z;

if( X != 0.f )
	{
	m_vView.z = (float)(m_vPosition.z + sin(X)*Point3D.y + cos(X)*Point3D.z);
	m_vView.y = (float)(m_vPosition.y + cos(X)*Point3D.y - sin(X)*Point3D.z);
	}
if( Y != 0.f )
	{
	m_vView.z = (float)(m_vPosition.z + sin(Y)*Point3D.x + cos(Y)*Point3D.z);
	m_vView.x = (float)(m_vPosition.x + cos(Y)*Point3D.x - sin(Y)*Point3D.z);
	}
if( Z != 0.f )
	{
	m_vView.x = (float)(m_vPosition.x + sin(Z)*Point3D.y + cos(Z)*Point3D.x);
	m_vView.y = (float)(m_vPosition.y + cos(Z)*Point3D.y - sin(Z)*Point3D.x);
	}
}

void new_camara::RotateAroundPoint( float X, float Y, float Z)
{
Point3D Point3D;
Point3D.x = m_vPosition.x - m_vView.x;
Point3D.y = m_vPosition.y - m_vView.y;
Point3D.z = m_vPosition.z - m_vView.z;

if(X != 0){
	m_vPosition.z = (float)(m_vView.z + sin(X)*Point3D.y + cos(X)*Point3D.z);
	m_vPosition.y = (float)(m_vView.y + cos(X)*Point3D.y - sin(X)*Point3D.z);
	}
if(Y != 0 ){
	m_vPosition.z = (float)(m_vView.z + sin(Y)*Point3D.x + cos(Y)*Point3D.z);
	m_vPosition.x = (float)(m_vView.x + cos(Y)*Point3D.x - sin(Y)*Point3D.z);
	}
if(Z != 0){
	m_vPosition.x = (float)(m_vView.x + sin(Z)*Point3D.y + cos(Z)*Point3D.x);
	m_vPosition.y = (float)(m_vView.y + cos(Z)*Point3D.y - sin(Z)*Point3D.x);
	}
}

void new_camara::RotateAroundPoint( Point3D vCenter, float X, float Y, float Z){
Point3D Point3D;
Point3D.x = m_vPosition.x - vCenter.x;
Point3D.y = m_vPosition.y - vCenter.y;
Point3D.z = m_vPosition.z - vCenter.z;

if(X != 0){
	m_vPosition.z = (float)(vCenter.z + sin(X)*Point3D.y + cos(X)*Point3D.z);
	m_vPosition.y = (float)(vCenter.y + cos(X)*Point3D.y - sin(X)*Point3D.z);
	}
if(Y != 0 ){
	m_vPosition.z = (float)(vCenter.z + sin(Y)*Point3D.x + cos(Y)*Point3D.z);
	m_vPosition.x = (float)(vCenter.x + cos(Y)*Point3D.x - sin(Y)*Point3D.z);
	}
if(Z != 0){
	m_vPosition.x = (float)(vCenter.x + sin(Z)*Point3D.y + cos(Z)*Point3D.x);
	m_vPosition.y = (float)(vCenter.y + cos(Z)*Point3D.y - sin(Z)*Point3D.x);
	}
}

Point3D new_camara::getVectorRightAnglesAwayFromCamera(){
Point3D vCross = Point3D( 0.f, 0.f, 0.f );
Point3D vViewPoint3D = Point3D( m_vView.x - m_vPosition.x, m_vView.y - m_vPosition.y, m_vView.z - m_vPosition.z );
vCross.x = ((m_vUpVector.y * vViewPoint3D.z) - (m_vUpVector.z * vViewPoint3D.y));
vCross.y = ((m_vUpVector.z * vViewPoint3D.x) - (m_vUpVector.x * vViewPoint3D.z));
vCross.z = ((m_vUpVector.x * vViewPoint3D.y) - (m_vUpVector.y * vViewPoint3D.x));
return vCross;
}

void new_camara::StrafeCamera(float speed){
Point3D vCross = Point3D( 0.f, 0.f, 0.f );
Point3D vViewPoint3D = Point3D( m_vView.x - m_vPosition.x, m_vView.y - m_vPosition.y, m_vView.z - m_vPosition.z );
vCross.x = ((m_vUpVector.y * vViewPoint3D.z) - (m_vUpVector.z * vViewPoint3D.y));
vCross.y = ((m_vUpVector.z * vViewPoint3D.x) - (m_vUpVector.x * vViewPoint3D.z));
vCross.z = ((m_vUpVector.x * vViewPoint3D.y) - (m_vUpVector.y * vViewPoint3D.x));
m_vPosition.x += vCross.x * speed;
m_vPosition.z += vCross.z * speed;
m_vView.x += vCross.x * speed;
m_vView.z += vCross.z * speed;
}

void new_camara::raiseCameraY( float amount ){
	m_vPosition.y += amount;
	m_vView.y += amount;
}

void new_camara::raiseCameraX( float amount ){
	m_vPosition.x += amount;
	m_vView.x += amount;
}

void new_camara::raiseCameraZ( float amount ){
	m_vPosition.z += amount;
	m_vView.z += amount;
}

void new_camara::MoveCameraXZ(float speed)
{
Point3D point3D= Point3D( 0.f, 0.f, 0.f );
point3D.x = m_vView.x - m_vPosition.x;
point3D.y = m_vView.y - m_vPosition.y;
point3D.z = m_vView.z - m_vPosition.z;

m_vPosition.x += point3D.x * speed;
m_vPosition.z += point3D.z * speed;
m_vView.x += point3D.x * speed;
m_vView.z += point3D.z * speed;
}

void new_camara::MoveCameraYZ(float speed)
{
Point3D point3D= Point3D( 0.f, 0.f, 0.f );
point3D.x = m_vView.x - m_vPosition.x;
point3D.y = m_vView.y - m_vPosition.y;
point3D.z = m_vView.z - m_vPosition.z;

m_vPosition.y += point3D.y * speed;
m_vPosition.z += point3D.z * speed;
m_vView.y += point3D.x * speed;
m_vView.z += point3D.z * speed;
}

void new_camara::MoveCameraXY(float speed)
{
Point3D point3D= Point3D( 0.f, 0.f, 0.f );
point3D.x = m_vView.x - m_vPosition.x;
point3D.y = m_vView.y - m_vPosition.y;
point3D.z = m_vView.z - m_vPosition.z;

m_vPosition.x += point3D.x * speed;
m_vPosition.y += point3D.z * speed;
m_vView.x += point3D.x * speed;
m_vView.y += point3D.z * speed;
}
new_camara::~new_camara()
{

}
