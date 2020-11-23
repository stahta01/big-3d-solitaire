// Point3D.cpp: implementation of the Point3D class.
//
//////////////////////////////////////////////////////////////////////

#include "Point3D.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Point3D::Point3D()
{
}

Point3D::Point3D( float x, float y, float z )
{
setPos( x, y, z );
}

void Point3D::setPos( float _x, float _y, float _z )
{
x = _x;	y = _y;	z = _z;
}

/*
Point3D::Point3D( String line )
{
	string[] tokens = line.Split( ' ' );
	x = float.Parse( tokens[0] );
	y = float.Parse( tokens[1] );
	z = float.Parse( tokens[2] );
}


public override string ToString()
{
	return x + " " + y + " " + z;
}

public Object clone()
{
	Point3D o = new Point3D();
	o.x = x;
	o.y = y;
	o.z = z;
	return o;
}

*/
bool Point3D::equals( Point3D ob )
{
	Point3D o = (Point3D)ob;
	if ( (x == o.x) && (y == o.y) && (z == o.z) )
	return true;
	else
	return false;
} 	

// Here we overload the + operator so we can add vectors together 
Point3D Point3D:: operator +(Point3D vVector2)
{
// Return the added vectors result.
return Point3D(x + vVector2.x, y + vVector2.y, z+ vVector2.z);
}

// Here we overload the - operator so we can subtract vectors 
Point3D Point3D:: operator -(Point3D vVector2)
{
// Return the subtracted vectors result
return Point3D(x - vVector2.x, y - vVector2.y, z - vVector2.z);
}

// Here we overload the * operator so we can multiply by scalars
Point3D Point3D:: operator * (float num)
{
// Return the scaled vector
return Point3D(x * num, y * num, z * num);
}

// Here we overload the / operator so we can divide by a scalar
Point3D Point3D:: operator / (float num)
{
// Return the scale vector
return Point3D(x / num, y / num, z / num);
}


double Point3D::distance( Point3D p1, Point3D p2 )
{
return (sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y) + (p2.z - p1.z)*(p2.z - p1.z) ));
}

Point3D::~Point3D()
{

}
