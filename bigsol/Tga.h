/*
 * Nehe Lesson 33 Code (ported to Linux//GLX by Patrick Schubert 2003
 * with help from the lesson 1 basecode for Linux/GLX by Mihael Vrbanec)
 */

#ifndef TGA_H_INCLUDED
#define TGA_H_INCLUDED

#include "Texture.h"
//#include <GL/glx.h>
#include <GL/gl.h>
//#include <X11/extensions/xf86vmode.h>
//#include <X11/keysym.h>
//#include <stdio.h>

typedef struct
{
	GLubyte Header[12];									/* TGA File Header */
} TGAHeader;

typedef struct
{
	GLubyte		header[6];								/* First 6 Useful Bytes From The Header */
	GLuint		bytesPerPixel;							/* Holds Number Of Bytes Per Pixel Used In The TGA File */
	GLuint		imageSize;								/* Used To Store The Image Size When Setting Aside Ram */
	GLuint		temp;									/* Temporary Variable */
	GLuint		type;
	GLuint		Height;									/* Height of Image */
	GLuint		Width;									/* Width ofImage */
	GLuint		Bpp;									/* Bits Per Pixel */
} TGA;


TGAHeader tgaheader;									/* TGA header */
TGA tga;												/* TGA image data */


GLubyte uTGAcompare[12] = {0,0,2, 0,0,0,0,0,0,0,0,0};	/* Uncompressed TGA Header */
GLubyte cTGAcompare[12] = {0,0,10,0,0,0,0,0,0,0,0,0};	/* Compressed TGA Header */
bool LoadTGA(TextureTGA * ,const char * );					/* Load a TGA file */
bool LoadUncompressedTGA(TextureTGA *,const char *,FILE *);	/* Load an Uncompressed file */
bool LoadCompressedTGA(TextureTGA *,const char *,FILE *);		/* Load a Compressed file */

#endif






