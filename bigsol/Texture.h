/*
 * Nehe Lesson 33 Code (ported to Linux//GLX by Patrick Schubert 2003
 * with help from the lesson 1 basecode for Linux/GLX by Mihael Vrbanec)
 */

#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

//#include <GL/glx.h>
#include <GL/gl.h>
//#include <X11/extensions/xf86vmode.h>
//#include <X11/keysym.h>

// TEXTURAS TIPO TGA
typedef struct{
	GLubyte	* imageData;									/* Image Data (Up To 32 Bits) */
	GLuint	bpp;											/* Image Color Depth In Bits Per Pixel */
	GLuint	width;											/* Image Width */
	GLuint	height;											/* Image Height */
	GLuint	texID;											/* Texture ID Used To Select A Texture */
	GLuint	type;											/* Image Type (GL_RGB, GL_RGBA) */
} TextureTGA;	

// TEXTURAS TIPO PNG
typedef struct {
  GLsizei width;
  GLsizei height;
  GLenum format;
  GLint internalFormat;
  GLuint id;
  GLubyte *texels;
} TexturePNG;
#endif
