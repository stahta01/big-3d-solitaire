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
#ifndef __text_tex_h__
#ifndef __TEXT_TEX_H__

#define __text_tex_h__
#define __TEXT_TEX_H__

//#include <windows.h>		
#include <stdio.h>			
//#include <GL/glext.h>			
#include <GL/gl.h>	// Header File For The OpenGL32 Library
#include <GL/glu.h>	// Header File For The GLu32 Library		
//#include <gl\glaux.h>		
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#include <stdarg.h>

// Definición de funciones
GLuint BuildFontBitmap(GLuint);
GLvoid KillFontBitmap(GLuint);
GLvoid glPrintBitmap(GLint, GLint, char *, int, GLuint, GLuint);
//GLuint LoadGLTexturesBitmap(char *);

//GLuint BuildFont(GLuint,HDC);
GLvoid KillFont(GLuint);
GLvoid glPrint(GLuint, const char *,...);
GLuint LoadGLTextures(char *);
GLuint* LoadPointerGLTextures(const char *);

GLuint LoadGLTexturesRC(unsigned int);

//GLuint BuildFontOutline(GLuint,HDC);
GLvoid KillFontOutline(GLuint);
GLvoid glPrintOutline(GLuint, char *);
GLuint LoadGLTexturesOutline(char *);

struct Image {
    unsigned long sizeX;
    unsigned long sizeY;
    char *data;
    };

typedef struct Image Image;
int ImageLoad(const char *filename, Image *image);
//AUX_RGBImageRec *LoadBMP(char *);

#endif
#endif
