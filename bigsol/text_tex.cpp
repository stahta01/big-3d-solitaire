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
#include "text_tex.h"

// quick and dirty bitmap loader...for 24 bit bitmaps with 1 plane only.  
// See http://www.dcs.ed.ac.uk/~mxr/gfx/2d/BMP.txt for more info.
// if mesa ever gets glaux, let me know.
// Carga una imagen sin tener que usar la libreria GLAUX
// De momento solo bmp de 24 bits
//**********************************************//
  int ImageLoad(char *filename, Image *image)
//**********************************************//
{
FILE *file;
unsigned long size;                 // size of the image in bytes.
unsigned long i;                    // standard counter.
unsigned short int planes;          // number of planes in image (must be 1) 
unsigned short int bpp;             // number of bits per pixel (must be 24)
char temp;                          // used to convert bgr to rgb color.

// make sure the file is there.
if ((file = fopen(filename, "rb"))==NULL)
    {
	printf("File Not Found : %s\n",filename);
	return 0;
    }
    
// seek through the bmp header, up to the width/height:
fseek(file, 18, SEEK_CUR);

// read the width
if ((i = fread(&image->sizeX, 4, 1, file)) != 1) {
	printf("Error reading width from %s.\n", filename);
	return 0;
    }
//printf("Width of %s: %lu\n", filename, image->sizeX);
    
    // read the height 
if ((i = fread(&image->sizeY, 4, 1, file)) != 1) {
	printf("Error reading height from %s.\n", filename);
	return 0;
    }
//printf("Height of %s: %lu\n", filename, image->sizeY);
    
// calculate the size (assuming 24 bits or 3 bytes per pixel).
size = image->sizeX * image->sizeY * 3;

    // read the planes
if ((fread(&planes, 2, 1, file)) != 1) {
	printf("Error reading planes from %s.\n", filename);
	return 0;
    }
if (planes != 1) {
	printf("Planes from %s is not 1: %u\n", filename, planes);
	return 0;
    }

// read the bpp
if ((i = fread(&bpp, 2, 1, file)) != 1) {
	printf("Error reading bpp from %s.\n", filename);
	return 0;
    }
if (bpp != 24) {
	printf("Bpp from %s is not 24: %u\n", filename, bpp);
	return 0;
    }
	
// seek past the rest of the bitmap header.
fseek(file, 24, SEEK_CUR);

// read the data. 
image->data = (char *) malloc(size);
if (image->data == NULL) {
	printf("Error allocating memory for color-corrected image data");
	return 0;	
    }

if ((i = fread(image->data, size, 1, file)) != 1) {
	printf("Error reading image data from %s.\n", filename);
	return 0;
    }

for (i=0;i<size;i+=3) { // reverse all of the colors. (bgr -> rgb)
	temp = image->data[i];
	image->data[i] = image->data[i+2];
	image->data[i+2] = temp;
    }
// we're done.
return 1;
}

/*******************************************/
	GLuint BuildFontBitmap(GLuint textura)	// Fuentes tipo textura	
/*******************************************/
{
	float	cx;											// Holds Our X Character Coord
	float	cy;											// Holds Our Y Character Coord
	int		loop;
	GLuint	labase;

	labase=glGenLists(256);								// Creating 256 Display Lists
	glBindTexture(GL_TEXTURE_2D, textura);				// Select Our Font Texture
	for (loop=0; loop<256; loop++)						// Loop Through All 256 Lists
	{
		cx=float(loop%16)/16.0f;						// X Position Of Current Character
		cy=float(loop/16)/16.0f;						// Y Position Of Current Character

		glNewList(labase+loop,GL_COMPILE);				// Start Building A List
			glBegin(GL_QUADS);							// Use A Quad For Each Character
				glTexCoord2f(cx,1-cy-0.0625f);			// Texture Coord (Bottom Left)
				glVertex2i(0,0);						// Vertex Coord (Bottom Left)
				glTexCoord2f(cx+0.0625f,1-cy-0.0625f);	// Texture Coord (Bottom Right)
				glVertex2i(16,0);						// Vertex Coord (Bottom Right)
				glTexCoord2f(cx+0.0625f,1-cy);			// Texture Coord (Top Right)
				glVertex2i(16,16);						// Vertex Coord (Top Right)
				glTexCoord2f(cx,1-cy);					// Texture Coord (Top Left)
				glVertex2i(0,16);						// Vertex Coord (Top Left)
			glEnd();									// Done Building Our Quad (Character)
			glTranslated(10,0,0);						// Move To The Right Of The Character
		glEndList();									// Done Building The Display List
	}													// Loop Until All 256 Are Built
	return(labase);
}

/*****************************************/
	GLvoid KillFontBitmap(GLuint labase)				// Delete The Font From Memory
/*****************************************/
{
	glDeleteLists(labase,256);							// Delete All 256 Display Lists
}

/**************************************************************************************************/
	GLvoid glPrintBitmap(GLint x, GLint y, char *string, int set, GLuint textura, GLuint labase)
/**************************************************************************************************/
{
	if (set>1) set=1;
	glBindTexture(GL_TEXTURE_2D, textura);				// Select Our Font Texture
	glDisable(GL_DEPTH_TEST);							// Disables Depth Testing
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPushMatrix();										// Store The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix
	glOrtho(0,640,0,480,-100,100);						// Set Up An Ortho Screen
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glPushMatrix();										// Store The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
	glTranslated(x,y,0);								// Position The Text (0,0 - Bottom Left)
	glListBase(labase-32+(128*set));					// Choose The Font Set (0 or 1)
	glCallLists(strlen(string),GL_BYTE,string);			// Write The Text To The Screen
	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glPopMatrix();										// Restore The Old Projection Matrix
	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glPopMatrix();										// Restore The Old Projection Matrix
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
}

/**************************************************/
//	GLuint LoadGLTexturesBitmap(char *Filename)			// Load Bitmaps And Convert To Textures
/**************************************************/
/*
{
        GLuint textura=FALSE;                           // Status Indicator
		AUX_RGBImageRec *TextureImage[1];               // Create Storage Space For The Textures
        memset(TextureImage,0,sizeof(void *)*1);        // Set The Pointer To NULL

        if (TextureImage[0]=LoadBMP(Filename))
        {
			textura=TRUE;                            
            glGenTextures(1, &textura);
            glBindTexture(GL_TEXTURE_2D, textura);
		    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX,
				         TextureImage[0]->sizeY, 0, GL_RGB, 
						 GL_UNSIGNED_BYTE, TextureImage[0]->data);
        }
		if (TextureImage[0])							// If Texture Exists
		    {
			 if (TextureImage[0]->data)			// If Texture Image Exists
			    free(TextureImage[0]->data);	// Free The Texture Image Memory
			free(TextureImage[0]);
		}
        return textura;                    
}
*/
/***************************************************/
	//GLuint BuildFontOutline(GLuint labase, HDC hDC)	// Build Our Bitmap Font Outline
/***************************************************/
/*
{
	GLYPHMETRICSFLOAT	gmf[256];					// Address Buffer For Font Storage
	HFONT	font;									// Windows Font ID

	labase = glGenLists(256);						// Storage For 256 Characters

	font = CreateFont(-12,							// Height Of Font
						0,							// Width Of Font
						0,							// Angle Of Escapement
						0,							// Orientation Angle
						FW_BOLD,					// Font Weight
						FALSE,						// Italic
						FALSE,						// Underline
						FALSE,						// Strikeout
						ANSI_CHARSET,				// Character Set Identifier
						OUT_TT_PRECIS,				// Output Precision
						CLIP_DEFAULT_PRECIS,		// Clipping Precision
						ANTIALIASED_QUALITY,		// Output Quality
						FF_DONTCARE|DEFAULT_PITCH,	// Family And Pitch
						"Arial");					// Font Name

	SelectObject(hDC, font);						// Selects The Font We Created

	wglUseFontOutlines(	hDC,						// Select The Current DC
						32,							// Starting Character
						96,							// Number Of Display Lists To Build
						labase,						// Starting Display Lists
						0.1f,						// Deviation From The True Outlines
						0.2f,						// Font Thickness In The Z Direction
						WGL_FONT_POLYGONS,			// Use Polygons, Not Lines
						gmf);						// Address Of Buffer To Recieve Data
return(labase);
}
*/
/*******************************************/
	GLvoid KillFontOutline(GLuint labase)	// Delete The Font Outline
/*******************************************/
{
  glDeleteLists(labase, 96);							// Delete All 256 Characters
}

/*******************************************************/
	GLvoid glPrintOutline(GLuint labase, char *text)	// Custom GL "Print" Routine for Outline
/*******************************************************/
{
  if (text == NULL)									// If There's No Text
    return;											// Do Nothing
  glPushAttrib(GL_LIST_BIT);						// Pushes The Display List Bits
    glListBase(labase-32);							// Sets The Base Character to 32
    glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);	// Draws The Display List Text
  glPopAttrib();									// Pops The Display List Bits
}

/*******************************************/
	//GLuint BuildFont(GLuint labase,HDC hDC)	// Build Our Bitmap Font
/*******************************************/
/*
{
	HFONT	font;										// Windows Font ID
	labase = glGenLists(96);								// Storage For 96 Characters
	font = CreateFont(	-24,							// Height Of Font
						6,								// Width Of Font
						0,								// Angle Of Escapement
						0,								// Orientation Angle
						FW_NORMAL,						// Font Weight
						FALSE,							// Italic
						FALSE,							// Underline
						FALSE,							// Strikeout
						ANSI_CHARSET,					// Character Set Identifier
						OUT_TT_PRECIS,					// Output Precision
						CLIP_DEFAULT_PRECIS,			// Clipping Precision
						ANTIALIASED_QUALITY,			// Output Quality
						FF_DONTCARE|DEFAULT_PITCH,		// Family And Pitch
						"Courier New");					// Font Name
	SelectObject(hDC, font);							// Selects The Font We Want
	wglUseFontBitmaps(hDC, 32, 96, labase);				// Builds 96 Characters Starting At Character 32
	return(labase);
}
*/
/***********************************/
	GLvoid KillFont(GLuint labase)	// Delete The Font
/***********************************/
{
	glDeleteLists(labase, 96);							// Delete All 96 Characters
}

/*******************************************************/
	GLvoid glPrint(GLuint labase, const char *fmt, ...)	// Custom GL "Print" Routine
/*******************************************************/
{
	char		text[256];								// Holds Our String
	va_list		ap;										// Pointer To List Of Arguments

	if (fmt == NULL)									// If There's No Text
		return;											// Do Nothing

	va_start(ap, fmt);									// Parses The String For Variables
	    vsprintf(text, fmt, ap);						// And Converts Symbols To Actual Numbers
	va_end(ap);											// Results Are Stored In Text

	glPushAttrib(GL_LIST_BIT);							// Pushes The Display List Bits
	glListBase(labase - 32);							// Sets The Base Character to 32
	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);	// Draws The Display List Text
	glPopAttrib();										// Pops The Display List Bits
}

// Esta funcion carga una imagen BMP para ser usada como textura.
// El ancho y alto deben ser potencias de 2, y al menos 64, maximo 128, por razones de compatibilidad
// As�, deber�a ser de 64,128 o 256 bits
// Si la textura se eleva como Minimapped se puede emplear cualquier tama�o
// COMO USA LA LABRERIA GLAUX y no esta implementada en Dev-C usaremos el otro cargador

//***********************************************//
//	AUX_RGBImageRec *LoadBMP(char *Filename)
//***********************************************//
/*
{
	FILE *File=NULL;				// Manejador del fichero
	// Chequeamos que hemos pasado un fichero
	if (!Filename) {					
		return NULL; }				// Si no devolvemos NULL
	
	// Chequeamos que el fichero existe
	File=fopen(Filename,"r");
	if (File) {								//Existe?
		fclose(File);						// Si es as�, cerramos el fichero
		return auxDIBImageLoad(Filename);}	// Cargamos el Bitmap y devolvemos el puntero
	return NULL;							// Si falla devolvemos NULL
}
*/
//******************************************//
	GLuint LoadGLTextures(char *Filename)	// Carga el Bitmap y lo convierte en Textura
//******************************************//
{
GLuint textura=false;				
// Load Texture
Image *image1;
   
// Allocate space for texture
image1 = (Image *) malloc(sizeof(Image));
if (image1 == NULL) return false;
if (!ImageLoad(Filename, image1)) return false;

glGenTextures(1, &textura);		// Create The Texture
// Typical Texture Generation Using Data From The Bitmap
glBindTexture(GL_TEXTURE_2D, textura);
glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX,
             image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);					 

glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);

//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST_MIPMAP_NEAREST);

//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR); 
gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image1->sizeX, image1->sizeY, GL_RGB, GL_UNSIGNED_BYTE, image1->data);

if (image1) {
	if (image1->data) free(image1->data);
	free(image1);
	}
return textura;					// Return The Status
}

//******************************************//
	GLuint* LoadPointerGLTextures(char *Filename)	// Carga el Bitmap y lo convierte en Textura
//******************************************//
{
GLuint *textura;
textura= new GLuint;
// Load Texture
Image *image1;
   
// Allocate space for texture
image1 = (Image *) malloc(sizeof(Image));
if (image1 == NULL) return false;
if (!ImageLoad(Filename, image1)) return false;

glGenTextures(1, textura);		// Create The Texture
// Typical Texture Generation Using Data From The Bitmap
glBindTexture(GL_TEXTURE_2D, *textura);
glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX,
             image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);					 

glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);

//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST_MIPMAP_NEAREST);

//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR); 
gluBuild2DMipmaps(GL_TEXTURE_2D, 3, image1->sizeX, image1->sizeY, GL_RGB, GL_UNSIGNED_BYTE, image1->data);

if (image1)
    {
	if (image1->data) free(image1->data);
	free(image1);
	}
return textura;					// Return The Status
}


//********************************************//
	//GLuint LoadGLTexturesRC(unsigned int IDB)	// Carga Texturas de bitmaps desde resource
//*******************************************//
/*
{
	HBITMAP hBMP;												// Handle Of The Bitmap
	BITMAP	BMP;												// Bitmap Structure
	GLuint	textura=FALSE;

	glGenTextures(1,&textura);		// Genera 1 Textura
		
		hBMP=(HBITMAP)LoadImage(GetModuleHandle(NULL),MAKEINTRESOURCE(IDB), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
		if (hBMP)										// Does The Bitmap Exist?
		{												// If So...
			GetObject(hBMP,sizeof(BMP), &BMP);			// Get The Object
														// hBMP: Handle To Graphics Object
														// sizeof(BMP): Size Of Buffer For Object Information
														// Buffer For Object Information
			glPixelStorei(GL_UNPACK_ALIGNMENT,4);		// Pixel Storage Mode (Word Alignment / 4 Bytes)
			glBindTexture(GL_TEXTURE_2D, textura);		// Bind Our Texture


			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
	

			//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);	// Linear Filtering
			//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR); // Mipmap Linear Filtering
			// Si LINEAR es muy lento, mejor NEAREST !!
			// Generate Mipmapped Texture (3 Bytes, Width, Height And Data From The BMP)
			gluBuild2DMipmaps(GL_TEXTURE_2D, 3, BMP.bmWidth, BMP.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
			DeleteObject(hBMP);									// Delete The Bitmap Object
		}
return textura;
}
*/
//**********************************************//
	//GLuint LoadGLTexturesOutline(char *Filename)	// Carga el Bitmap y lo convierte en Textura
//**********************************************//
/*
{
GLuint textura=FALSE;   // Status Indicator
// Load Texture
Image *image1;
   
// Allocate space for texture
image1 = (Image *) malloc(sizeof(Image));
if (image1 == NULL) return false;
if (!ImageLoad(Filename, image1)) return false;
textura=TRUE;				   // Set The Status To TRUE
glGenTextures(1, &textura);		// Create The Texture
glBindTexture(GL_TEXTURE_2D, textura);
glTexImage2D(GL_TEXTURE_2D, 0, 3, image1->sizeX,
             image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);	
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);

if (image1)
    {
	if (image1->data) free(image1->data);
	free(image1);
	}
	
return textura;					// Return The Status
}
*/
