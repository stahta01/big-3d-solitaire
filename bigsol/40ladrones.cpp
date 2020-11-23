/*
 Big Solitaries 3D
 Copyright (C) 2006/07  Félix José Cladellas

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
// For compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"
#ifdef __BORLANDC__
#pragma hdrstop
#endif
#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif
#include <wx/timer.h>
#include "wx/toolbar.h"
#include "wx/image.h"
#include "wx/aboutdlg.h"
// these headers are only needed for custom about dialog
//#include "wx/statline.h"
//#include "wx/generic/aboutdlgg.h"
//#include "wx/filedlg.h"
#include "wx/propdlg.h"
#include "wx/datetime.h"
#include "wx/image.h"
#include "wx/bookctrl.h"
#include "wx/artprov.h"
#include "wx/imaglist.h"
#include "wx/sysopt.h"
#include "wx/tipdlg.h"
#include "wx/numdlg.h"
#include "wx/choicdlg.h"
#include "wx/dirdlg.h"
// HTML
#include "wx/textfile.h"
#include "wx/html/htmlwin.h"
#include "html.h"
// Estadisticas
#include "scorefil.h"
#include "scoredg.h"
#include "playerdg.h"
#include "bestTimesdg.h"
#include "wx/stockitem.h"
// Tree
#include "treejuegos.h"
// HILOS
#include "wx/thread.h"
// Colores
#include "colores.h"
// define this to use XPMs everywhere (by default, BMPs are used under Win)
// BMPs use less space, but aren't compiled into the executable on other platforms
#ifdef __WXMSW__
#define USE_XPM_BITMAPS 0
#else
#define USE_XPM_BITMAPS 1
#endif
#if USE_XPM_BITMAPS && defined(__WXMSW__) && !wxUSE_XPM_IN_MSW
#error You need to enable XPM support to use XPM bitmaps with toolbar!
#endif // USE_XPM_BITMAPS
/*
#if USE_XPM_BITMAPS
#include "bitmaps/new.xpm"
#include "bitmaps/open.xpm"
#include "bitmaps/copy.xpm"
#include "bitmaps/tutorial.xpm"
#include "bitmaps/undo.xpm"
#include "bitmaps/redo.xpm"
#include "bitmaps/quit.xpm"
#endif // USE_XPM_BITMAPS
*/
#if !wxUSE_GLCANVAS
#error "OpenGL required: set wxUSE_GLCANVAS to 1 and rebuild the library"
#endif
// INICIO
#include "40.h"
#include "40ladrones.h"
#include "new_camara.h"
#include "Crender.h"
#include "cards.h"
#include "ladrones40_2.h"
#include "ladrones40_4.h"
#include "ladrones40y8.h"
#include "golf.h"
#include "golf_ak.h"
#include "golf_ak2.h"
#include "montana.h"
#include "montecarlo.h"
#include "montecarlo13.h"
#include "klondike.h"
#include "klondike2.h"
#include "freecell.h"
#include "freecell2.h"
#include "corona.h"
#include "canfield.h"
#include "canfield2.h"
#include "canfield_sup.h"
#include "towers.h"
#include "spider.h"
#include "spider1.h"
#include "spider2.h"
#include "spider3.h"
#include "spiderette.h"
#include "spideretter.h"
#include "scarab.h"
#include "simplesimon.h"
#include "yukon.h"
#include "rail1.h"
#include "rail2.h"
#include "emperor.h"
#include "russian.h"
#include "yukon_nk.h"
#include "russian_nk.h"
#include "oceans.h"
#include "scorpion.h"
#include "lucky.h"
#include "indian.h"
#include "easthaven.h"
#include "z_four.h"
//#include "textfile.h"
#include "Tga.h"
// Sonido
#include "wx/sound.h"
// MUSICA MIKMOD
//#include <unistd.h>
//#include <mikmod.h>
// MUSICA BASSMOD
//#include "bassmod.h"
// TEXTURAS PNG
#include <png.h>

#define WAV_WIN	_T("Data/1/win.wav")
bool arranque=false;
bool hemos_arrancado=false;
bool estadistica_computada=false;
bool record_grabado=false;
int window;
void createMenu(void);
void menu(int value);
int xx0, yy0;
float alpha, beta;
#define TEST	1
// VARIABLES GLOBALES DE WXWIDGETS //
MyFrame *frame;
wxToolBarBase *toolBar;
wxMenu *winMenuAuto;
wxMenu *winMenuFile;
wxMenu *winMenuOpen;
wxMenu *winMenuCamara;
wxMenu *winOptions;
wxMenu *winMenuHelp;
wxMenu *winMenuDeck;
wxMenu *winMenuImage;

// PARA LA TOOLBAR. Constants
static const long TOOLBAR_STYLE = wxTB_FLAT | wxTB_DOCKABLE | wxTB_TEXT;
enum {
	IDM_TOOLBAR_TOGGLETOOLBARSIZE = 200,
	IDM_TOOLBAR_TOGGLETOOLBARROWS,
	IDM_TOOLBAR_TOGGLETOOLTIPS,
	IDM_TOOLBAR_TOGGLECUSTOMDISABLED,
	IDM_TOOLBAR_TOGGLE_TOOLBAR,
	IDM_TOOLBAR_TOGGLE_HORIZONTAL_TEXT,
	IDM_TOOLBAR_TOGGLE_ANOTHER_TOOLBAR,
	IDM_TOOLBAR_CHANGE_TOOLTIP,
	IDM_TOOLBAR_SHOW_ICONS,
	IDM_TOOLBAR_CUSTOM_PATH,
	IDM_TOOLBAR_TOP_ORIENTATION,
	ID_COMBO = 1000,
	ID_SPIN = 1001
};
// VARIABLES GLOBALES
bool fondo_color=false;
//char otros[90];
//int base_outline; // Para la fuente outline
//int base_textura; // Para la fuente tipo textura
game *juego;
Crender crender;
int tipo_juego=0;
char caja[7]; // Memoria para los cuadraditos
//	0 para el verde, 1 para el amarillo, 2 para el azul, 3 para el magenta
int color_base=0;
int num_movimientos=0;
int num_cartas_colocadas=0;
int segundos_actuales=0;
float color[]    = { 1.f, 1.f, 1.0f, 1.f };
float color_ini[]= { 0.f, 0.f, 0.f, 1.f };
float color_fin[]= { 0.f, 0.5f, 0.f, 1.f };
float color_cas[]= { 0.f, 0.95f, 0.f, 1.f };
//float	color_menu[]={0.f,1.f,0.f,0.75f};
float zfondo=-1.21f;
float color_texto[]= { 0.8f, 0.8f, 0.8f, 0.75f };
float color_barra[]= { 1.0f, 0.5f, 0.2f, 0.75f };
int superseleccion=0; // La superseleccion
int total_juegos[40];
int juegos_ganados[40];
// Texturas nuevas tipo TGA
/*
char *files_texturas2[53]={
	"Data/1/nada","Data/1/Club1.tga","Data/1/Club2.tga","Data/1/Club3.tga","Data/1/Club4.tga",
	"Data/1/Club5.tga","Data/1/Club6.tga","Data/1/Club7.tga","Data/1/Club8.tga","Data/1/Club9.tga",
	"Data/1/Club10.tga","Data/1/Club11.tga","Data/1/Club12.tga","Data/1/Club13.tga","Data/1/Diamond1.tga",
	"Data/1/Diamond2.tga","Data/1/Diamond3.tga","Data/1/Diamond4.tga","Data/1/Diamond5.tga","Data/1/Diamond6.tga",
	"Data/1/Diamond7.tga","Data/1/Diamond8.tga","Data/1/Diamond9.tga","Data/1/Diamond10.tga",
	"Data/1/Diamond11.tga","Data/1/Diamond12.tga","Data/1/Diamond13.tga","Data/1/Heart1.tga",
	"Data/1/Heart2.tga","Data/1/Heart3.tga","Data/1/Heart4.tga","Data/1/Heart5.tga",
	"Data/1/Heart6.tga","Data/1/Heart7.tga","Data/1/Heart8.tga","Data/1/Heart9.tga",
	"Data/1/Heart10.tga","Data/1/Heart11.tga","Data/1/Heart12.tga","Data/1/Heart13.tga",
	"Data/1/Spade1.tga","Data/1/Spade2.tga","Data/1/Spade3.tga","Data/1/Spade4.tga",
	"Data/1/Spade5.tga","Data/1/Spade6.tga","Data/1/Spade7.tga","Data/1/Spade8.tga",
	"Data/1/Spade9.tga","Data/1/Spade10.tga","Data/1/Spade11.tga","Data/1/Spade12.tga",
	"Data/1/Spade13.tga"
};
*/
// Texturas nuevas tipo BMP
const char *files_texturas2[53]={
	"Data/1/nada","Data/1/Club1.bmp","Data/1/Club2.bmp","Data/1/Club3.bmp","Data/1/Club4.bmp",
	"Data/1/Club5.bmp","Data/1/Club6.bmp","Data/1/Club7.bmp","Data/1/Club8.bmp","Data/1/Club9.bmp",
	"Data/1/Club10.bmp","Data/1/Club11.bmp","Data/1/Club12.bmp","Data/1/Club13.bmp","Data/1/Diamond1.bmp",
	"Data/1/Diamond2.bmp","Data/1/Diamond3.bmp","Data/1/Diamond4.bmp","Data/1/Diamond5.bmp","Data/1/Diamond6.bmp",
	"Data/1/Diamond7.bmp","Data/1/Diamond8.bmp","Data/1/Diamond9.bmp","Data/1/Diamond10.bmp",
	"Data/1/Diamond11.bmp","Data/1/Diamond12.bmp","Data/1/Diamond13.bmp","Data/1/Heart1.bmp",
	"Data/1/Heart2.bmp","Data/1/Heart3.bmp","Data/1/Heart4.bmp","Data/1/Heart5.bmp",
	"Data/1/Heart6.bmp","Data/1/Heart7.bmp","Data/1/Heart8.bmp","Data/1/Heart9.bmp",
	"Data/1/Heart10.bmp","Data/1/Heart11.bmp","Data/1/Heart12.bmp","Data/1/Heart13.bmp",
	"Data/1/Spade1.bmp","Data/1/Spade2.bmp","Data/1/Spade3.bmp","Data/1/Spade4.bmp",
	"Data/1/Spade5.bmp","Data/1/Spade6.bmp","Data/1/Spade7.bmp","Data/1/Spade8.bmp",
	"Data/1/Spade9.bmp","Data/1/Spade10.bmp","Data/1/Spade11.bmp","Data/1/Spade12.bmp",
	"Data/1/Spade13.bmp"
};
// Texturas viejas
const char *files_texturas1[53]={
	"Data/2/nada","Data/2/Club1.bmp","Data/2/Club2.bmp","Data/2/Club3.bmp","Data/2/Club4.bmp",
	"Data/2/Club5.bmp","Data/2/Club6.bmp","Data/2/Club7.bmp","Data/2/Club8.bmp","Data/2/Club9.bmp",
	"Data/2/Club10.bmp","Data/2/Club11.bmp","Data/2/Club12.bmp","Data/2/Club13.bmp","Data/2/Diamond1.bmp",
	"Data/2/Diamond2.bmp","Data/2/Diamond3.bmp","Data/2/Diamond4.bmp","Data/2/Diamond5.bmp","Data/2/Diamond6.bmp",
	"Data/2/Diamond7.bmp","Data/2/Diamond8.bmp","Data/2/Diamond9.bmp","Data/2/Diamond10.bmp",
	"Data/2/Diamond11.bmp","Data/2/Diamond12.bmp","Data/2/Diamond13.bmp","Data/2/Heart1.bmp",
	"Data/2/Heart2.bmp","Data/2/Heart3.bmp","Data/2/Heart4.bmp","Data/2/Heart5.bmp",
	"Data/2/Heart6.bmp","Data/2/Heart7.bmp","Data/2/Heart8.bmp","Data/2/Heart9.bmp",
	"Data/2/Heart10.bmp","Data/2/Heart11.bmp","Data/2/Heart12.bmp","Data/2/Heart13.bmp",
	"Data/2/Spade1.bmp","Data/2/Spade2.bmp","Data/2/Spade3.bmp","Data/2/Spade4.bmp",
	"Data/2/Spade5.bmp","Data/2/Spade6.bmp","Data/2/Spade7.bmp","Data/2/Spade8.bmp",
	"Data/2/Spade9.bmp","Data/2/Spade10.bmp","Data/2/Spade11.bmp","Data/2/Spade12.bmp",
	"Data/2/Spade13.bmp"
};
// Texturas Fun tipo PNG
const char *files_texturasFun[53]={
	"Data/3/0.png","Data/3/Club1.png","Data/3/Club2.png","Data/3/Club3.png","Data/3/Club4.png",
	"Data/3/Club5.png","Data/3/Club6.png","Data/3/Club7.png","Data/3/Club8.png","Data/3/Club9.png",
	"Data/3/Club10.png","Data/3/Club11.png","Data/3/Club12.png","Data/3/Club13.png","Data/3/Diamond1.png",
	"Data/3/Diamond2.png","Data/3/Diamond3.png","Data/3/Diamond4.png","Data/3/Diamond5.png","Data/3/Diamond6.png",
	"Data/3/Diamond7.png","Data/3/Diamond8.png","Data/3/Diamond9.png","Data/3/Diamond10.png",
	"Data/3/Diamond11.png","Data/3/Diamond12.png","Data/3/Diamond13.png","Data/3/Heart1.png",
	"Data/3/Heart2.png","Data/3/Heart3.png","Data/3/Heart4.png","Data/3/Heart5.png",
	"Data/3/Heart6.png","Data/3/Heart7.png","Data/3/Heart8.png","Data/3/Heart9.png",
	"Data/3/Heart10.png","Data/3/Heart11.png","Data/3/Heart12.png","Data/3/Heart13.png",
	"Data/3/Spade1.png","Data/3/Spade2.png","Data/3/Spade3.png","Data/3/Spade4.png",
	"Data/3/Spade5.png","Data/3/Spade6.png","Data/3/Spade7.png","Data/3/Spade8.png",
	"Data/3/Spade9.png","Data/3/Spade10.png","Data/3/Spade11.png","Data/3/Spade12.png",
	"Data/3/Spade13.png"
};
// Texturas Retro
const char *files_texturas4[53]={
	"Data/3/0.tga","Data/4/Club1.tga","Data/4/Club2.tga","Data/4/Club3.tga","Data/4/Club4.tga",
	"Data/4/Club5.tga","Data/4/Club6.tga","Data/4/Club7.tga","Data/4/Club8.tga","Data/4/Club9.tga",
	"Data/4/Club10.tga","Data/4/Club11.tga","Data/4/Club12.tga","Data/4/Club13.tga","Data/4/Diamond1.tga",
	"Data/4/Diamond2.tga","Data/4/Diamond3.tga","Data/4/Diamond4.tga","Data/4/Diamond5.tga","Data/4/Diamond6.tga",
	"Data/4/Diamond7.tga","Data/4/Diamond8.tga","Data/4/Diamond9.tga","Data/4/Diamond10.tga",
	"Data/4/Diamond11.tga","Data/4/Diamond12.tga","Data/4/Diamond13.tga","Data/4/Heart1.tga",
	"Data/4/Heart2.tga","Data/4/Heart3.tga","Data/4/Heart4.tga","Data/4/Heart5.tga",
	"Data/4/Heart6.tga","Data/4/Heart7.tga","Data/4/Heart8.tga","Data/4/Heart9.tga",
	"Data/4/Heart10.tga","Data/4/Heart11.tga","Data/4/Heart12.tga","Data/4/Heart13.tga",
	"Data/4/Spade1.tga","Data/4/Spade2.tga","Data/4/Spade3.tga","Data/4/Spade4.tga",
	"Data/4/Spade5.tga","Data/4/Spade6.tga","Data/4/Spade7.tga","Data/4/Spade8.tga",
	"Data/4/Spade9.tga","Data/4/Spade10.tga","Data/4/Spade11.tga","Data/4/Spade12.tga",
	"Data/4/Spade13.tga"
};
int cual=-1; // El juego seleccionado
int hours=0;
int minutes=0;
float seconds=0.f;
new_camara camara;
new_camara camara_backup;
bool is_auto_enabled;
bool is_auto_checked;
int resX=1024;
int resY=768;
//int	bits_color=32;
bool activar_sonido=true;
// A INTERFACE
bool boton_pulsado=false;// Boton izquierdo del raton pulsado para desplazamiento
bool camara_lenta=FALSE;
bool ABANDONAR=false; // Abandona la partida
bool doble_click=true; // Para evitar que al hacer doble click la carta se quede
// en la misma columna por la rutina de colocacion de carta manual
double xx, yy, zz; // Para mover la carta con el cursor
bool retroceso=false;
int cursor_en_menu=0;
int opcion=NADA; // Opcion que se pide confirmacion
bool respuesta=false; // Respuesta a YES/NOT
bool hubo_seleccion=false; // Para evitar que tras seleccion se inicie siempre
// la misma serie
float rot=0.0f; // Rotacion
float rotraro=0.0f; // Rotacion
// Luces
// Luz general de toda la escena
//float	LightAmbient[]= { 0.2f, 0.2f, 1.0f, 1.0f };
//float	LightPosition[]={ 0.0f, 0.0f,-1.0f, 0.0f }; 
int velocidad=1; // A menor velocidad mas rapido va
float rotfont=0.0f; // Para rotacion inicial del titulo
int contador=1;
//bool	light=TRUE;		// Luz ON/OFF
char buffer[128];
char bufferTiempo[10];
char buffer2[255];
double base_cil=0.0;
int cuantas_serp=2;
bool info=false;
bool JUEGO_FINALIZADO=false;
bool hemos_pinchado_start=false;
bool hemos_seleccionado_jugador=false;
bool mov_pendiente=false; // Hay movimiento pendiente por tener agarrada una carta si es true
// Para mover las cartas pinchandolas
GLint viewport[4];
GLdouble modelview[16];
GLdouble projection[16];
GLdouble winx, winy, winz;
// Camara
GLdouble mat_proy[16];
// TreeJuegos
DialogoArbol *arbolJuegos;
// FPS
#include <sys/time.h>
//static struct timeval _tstart, _tend;
//static struct timezone tz;

// ***** //
//  FPS  //
// ***** //
static long  frames=0;
static float lastTime = 0.0f;
float fTimeOld=0.f;
float fTime=0.f;
LARGE_INTEGER currentTime;

LARGE_INTEGER TimerFreq;	// Timer Frequency.
LARGE_INTEGER TimeStart;	// Time of start.
LARGE_INTEGER TimeCur;		// Current time.

static int frame_rate = 60;
//static long frames=0;
//static float lastTime = 0.0f;
//float currentTime=0.f;
//float fTimeOld=0.f;

// LUCES
//GLfloat ambientA[] = { 0.2f, 0.8f, 0.2f, 1.f };
//GLfloat diffuseA[] = { 0.2f, 0.8f, 0.2f, 1.f };
//GLfloat positionA[] = { 0.f, 0.f, -1.f, 0.f };

//GLfloat ambientB[] = { 1.f, 1.f, 1.f, 1.f };
//GLfloat diffuseB[] = { 1.f, 1.f, 1.f, 1.f };
//GLfloat positionB[] = { -1.f, -1.f, 1.f, 0.f };

// TEXTURAS
GLuint *textura[90]; // Memoria para texturas
GLuint *fondo;
GLuint *background;
GLuint *deckOld[53];
//TextureTGA *deckStandard[53];
GLuint *deckStandard[53];
TextureTGA *deckRetro[53];
TexturePNG *deckFun[53];
TexturePNG *fondoPNG;

// MUSICA
// MODULE *module;
// int module_count=0;

// DECLARACION DE FUNCIONES
void movimiento(float, float, float, int);
void movimiento_ini(float xfin, float yfin, float zfin, int n);
void renderiza_ini(void);
void chequea_automaticos(void);
void guardar_camara(void);
void restaurar_camara(void);
void restablece_automaticos(void);
void computar_estadistica_perdida(void);
//inline bool	LockFrameRate(int frame_rate = 450);// Sí funciona. Si la tarjeta da mas bloqueamos el fps a un maximo

inline bool LockFrameRate() {
	if(juego->hemos_acabado) return true;
	QueryPerformanceCounter(&TimeCur);	// Actualizamos tiempos
	fTime=(float)((double)(TimeCur.QuadPart-TimeStart.QuadPart)/(double)TimerFreq.QuadPart);
	if((fTime - lastTime) > (1.0f / frame_rate)){
		lastTime = fTime;	// Reset the last time
		return true;
	}
	return false;
}
// ************************** //
// CARGA DE TEXTURAS TIPO PNG //
// ************************** //
void GetPNGtextureInfo (int color_type, TexturePNG *texinfo){
  switch (color_type){
    case PNG_COLOR_TYPE_GRAY:
    	texinfo->format = GL_LUMINANCE;
    	texinfo->internalFormat = 1;
    break;

    case PNG_COLOR_TYPE_GRAY_ALPHA:
    	texinfo->format = GL_LUMINANCE_ALPHA;
    	texinfo->internalFormat = 2;
    break;

    case PNG_COLOR_TYPE_RGB:
    	texinfo->format = GL_RGB;
    	texinfo->internalFormat = 3;
    break;

    case PNG_COLOR_TYPE_RGB_ALPHA:
    	//fprintf(stdout,"La textura es de tipo GL_RGBA\r");
    	texinfo->format = GL_RGBA;
    	texinfo->internalFormat = 4;
    break;

    default:
      /* Badness */
      break;
    }
}

TexturePNG *ReadPNGFromFile (const char *filename){
	TexturePNG *texinfo;
	png_byte magic[8];
	png_structp png_ptr;
	png_infop info_ptr;
	int bit_depth, color_type;
	FILE *fp = NULL;
	png_bytep *row_pointers = NULL;
	int i;

	fp = fopen (filename, "rb");
	if (!fp) {
		fprintf (stderr, "error: couldn't open \"%s\"!\n", filename);
		return NULL;
    }

	// read magic number
	fread (magic, 1, sizeof (magic), fp);

	// check for valid magic number
	if (!png_check_sig (magic, sizeof (magic))) {
		fprintf (stderr, "error: \"%s\" is not a valid PNG image!\n", filename);
		fclose (fp);
		return NULL;
    }

	// create a png read struct
	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr) {
		fclose (fp);
		return NULL;
    }

	// create a png info struct
	info_ptr = png_create_info_struct (png_ptr);
	if (!info_ptr){
		fclose (fp);
		png_destroy_read_struct (&png_ptr, NULL, NULL);
		return NULL;
    }

	// create our OpenGL texture object
	texinfo = (TexturePNG *)malloc (sizeof (TexturePNG));

	// initialize the setjmp for returning properly after a libpng error occured
	if (setjmp (png_jmpbuf (png_ptr))) {
		fclose (fp);
		png_destroy_read_struct (&png_ptr, &info_ptr, NULL);

		if (row_pointers)
			free (row_pointers);

		if (texinfo){
			if (texinfo->texels)
				free (texinfo->texels);
			free (texinfo);
      	}
		return NULL;
	}

  /* setup libpng for using standard C fread() function
     with our FILE pointer */
  png_init_io (png_ptr, fp);

  /* tell libpng that we have already read the magic number */
  png_set_sig_bytes (png_ptr, sizeof (magic));

  /* read png info */
  png_read_info (png_ptr, info_ptr);

  /* get some usefull information from header */
  bit_depth = png_get_bit_depth (png_ptr, info_ptr);
  color_type = png_get_color_type (png_ptr, info_ptr);

  /* convert index color images to RGB images */
  if (color_type == PNG_COLOR_TYPE_PALETTE)
    png_set_palette_to_rgb (png_ptr);

  /* convert 1-2-4 bits grayscale images to 8 bits
     grayscale. */
  if (color_type == PNG_COLOR_TYPE_GRAY && bit_depth < 8)
#if PNG_LIBPNG_VER_SONUM > 12 // 12 = 1.2
    png_set_expand_gray_1_2_4_to_8(png_ptr);
#else
    png_set_gray_1_2_4_to_8 (png_ptr); // Was last valid before 1.2.9
#endif

  if (png_get_valid (png_ptr, info_ptr, PNG_INFO_tRNS))
    png_set_tRNS_to_alpha (png_ptr);

  if (bit_depth == 16)
    png_set_strip_16 (png_ptr);
  else if (bit_depth < 8)
    png_set_packing (png_ptr);

  /* update info structure to apply transformations */
  png_read_update_info (png_ptr, info_ptr);

  /* retrieve updated information */
  png_get_IHDR (png_ptr, info_ptr,
		(png_uint_32*)(&texinfo->width),
		(png_uint_32*)(&texinfo->height),
		&bit_depth, &color_type,
		NULL, NULL, NULL);

  /* get image format and components per pixel */
  GetPNGtextureInfo (color_type, texinfo);

  /* we can now allocate memory for storing pixel data */
  texinfo->texels = (GLubyte *)malloc (sizeof (GLubyte) * texinfo->width
	       * texinfo->height * texinfo->internalFormat);

  /* setup a pointer array.  Each one points at the begening of a row. */
  row_pointers = (png_bytep *)malloc (sizeof (png_bytep) * texinfo->height);

  for (i = 0; i < texinfo->height; ++i)
    {
      row_pointers[i] = (png_bytep)(texinfo->texels +
	((texinfo->height - (i + 1)) * texinfo->width * texinfo->internalFormat));
    }

  /* read pixel data using row pointers */
  png_read_image (png_ptr, row_pointers);

  /* finish decompression and release memory */
  png_read_end (png_ptr, NULL);
  png_destroy_read_struct (&png_ptr, &info_ptr, NULL);

  /* we don't need row pointers anymore */
  free (row_pointers);

  fclose (fp);
  return texinfo;
}

//GLuint LoadPNG(TexturePNG *png_tex,const char *filename) {
TexturePNG *LoadPNG(const char *filename) {
	TexturePNG *png_tex = NULL;
	png_tex = ReadPNGFromFile (filename);
	if (png_tex && png_tex->texels) {
		// generate texture
		glGenTextures (1, &png_tex[0].id);
		glBindTexture (GL_TEXTURE_2D, png_tex[0].id);

		// setup some parameters for texture filters and mipmapping
		glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		/*
		glTexImage2D(GL_TEXTURE_2D, 0, png_tex[0].internalFormat,
					 png_tex[0].width, png_tex[0].height, 0, png_tex->format,
					 GL_UNSIGNED_BYTE, png_tex[0].texels);
		*/
		gluBuild2DMipmaps(GL_TEXTURE_2D, png_tex->internalFormat,
						  png_tex->width, png_tex->height,
						  png_tex->format, GL_UNSIGNED_BYTE, png_tex->texels);
		
		// OpenGL has its own copy of texture data
		//fprintf(stdout,"En Crea texturaPNG.ID: %u: Ancho: %u, Alto %u\r",png_tex->id,png_tex->width,png_tex->height);
		//free (png_tex->texels);
		//free (png_tex);
		return png_tex;
	}
	return NULL;
}
// ************************** //
// CARGA DE TEXTURAS TIPO TGA //
// ************************** //
bool LoadTGA(TextureTGA *texture,const char *filename) {
	FILE * fTGA;													/* File pointer to texture file */
	fTGA = fopen(filename, "rb");									/* Open file for reading */

	if(fTGA == NULL) {
		fprintf(stderr,"Error could not open texture file %s",filename);
		return false;												
	}

	if(fread(&tgaheader, sizeof(TGAHeader), 1, fTGA) == 0)			/* Attempt to read 12 byte header from file */
	{
		printf("Error could not read file header");					/* If it fails, display an error message */
		if(fTGA != NULL)											/* Check to seeiffile is still open */
		{
			fclose(fTGA);											/* If it is, close it */
		}
		return false;												/* Exit function */
	}

	if(memcmp(uTGAcompare, &tgaheader, sizeof(tgaheader)) == 0)	/* See if header matches the predefined header of */
	{																/* an Uncompressed TGA image */
		//printf("Cargando TGA no comprimido\r");
		LoadUncompressedTGA(texture, filename, fTGA);					/* If so, jump to Uncompressed TGA loading code */
	}
	else if(memcmp(cTGAcompare, &tgaheader, sizeof(tgaheader)) == 0)	/* See if header matches the predefined header of */
	{																	/* an RLE compressed TGA image */
		//printf("Cargando TGA comprimido\r");
		LoadCompressedTGA(texture, filename, fTGA);						/* If so, jump to Compressed TGA loading code */
	}
	else																/* If header matches neither type */
	{
		printf("Error TGA file be type 2 or type 10 ");				/* Display an error */
		fclose(fTGA);
		return false;												/* Exit function */
	}
	return true;														/* All went well, continue on */
}

bool LoadUncompressedTGA(TextureTGA *texture, const char *filename, FILE *fTGA){
	GLuint cswap;														/* TGA Loading code nehe.gamedev.net) */
	if(fread(tga.header, sizeof(tga.header), 1, fTGA) == 0){
		printf("Error could not read info header");						/* Display error */
		if(fTGA != NULL)												/* if file is still open */
		{
			fclose(fTGA);												/* Close it */
		}
		return false;
	}

	texture->width  = tga.header[1] * 256 + tga.header[0];					/* Determine The TGA Width	(highbyte*256+lowbyte) */
	texture->height = tga.header[3] * 256 + tga.header[2];					/* Determine The TGA Height	(highbyte*256+lowbyte) */
	texture->bpp	= tga.header[4];										/* Determine the bits per pixel */
	tga.Width		= texture->width;										/* Copy width into local structure */
	tga.Height		= texture->height;										/* Copy height into local structure */
	tga.Bpp			= texture->bpp;											/* Copy BPP into local structure */

	if((texture->width <= 0) || (texture->height <= 0) || ((texture->bpp != 24) && (texture->bpp !=32)))	/* Make sure all information is valid */
	{
		printf("Error invalid texture information");						/* Display Error */
		if(fTGA != NULL)													/* Check if file is still open */
		{
			fclose(fTGA);													/* If so, close it */
		}
		return false;														/* Return failed */
	}

	if(texture->bpp == 24)													/* If the BPP of the image is 24... */
	{
		texture->type	= GL_RGB;											/* Set Image type to GL_RGB */
	}
	else																	/* Else if its 32 BPP */
	{
		texture->type	= GL_RGBA;											/* Set image type to GL_RGBA */
	}

	tga.bytesPerPixel	= (tga.Bpp / 8);									/* Compute the number of BYTES per pixel */
	tga.imageSize		= (tga.bytesPerPixel * tga.Width * tga.Height);		/* Compute the total amout ofmemory needed to store data */
	texture->imageData	= (GLubyte *)malloc(tga.imageSize);							/* Allocate that much memory */

	if(texture->imageData == NULL)											/* If no space was allocated */
	{
		printf("Error could not allocate memory for image");				/* Display Error */
		fclose(fTGA);														/* Close the file */
		return false;														/* Return failed */
	}

	if(fread(texture->imageData, 1, tga.imageSize, fTGA) != tga.imageSize)	/* Attempt to read image data */
	{
		printf("Error could not read image data");							/* Display Error */
		if(texture->imageData != NULL)										/* If imagedata has data in it */
		{
			free(texture->imageData);										/* Delete data from memory */
		}
		fclose(fTGA);														/* Close file */
		return false;														/* Return failed */
	}

	/* Byte Swapping Optimized By Steve Thomas */
	for(cswap = 0; cswap < (GLuint)tga.imageSize; cswap += tga.bytesPerPixel)
	{
		texture->imageData[cswap] ^= texture->imageData[cswap+2] ^=
		texture->imageData[cswap] ^= texture->imageData[cswap+2];
	}

	fclose(fTGA);
	// Build A Texture From The Data
	glGenTextures(1, &texture->texID);								// Generate OpenGL texture IDs
	glBindTexture(GL_TEXTURE_2D, texture->texID);						// Bind Our Texture
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// Linear Filtered
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	// Linear Filtered
	GLuint		type=GL_RGBA;	// Set The Default GL Mode To RBGA (32 BPP)
	if (texture[0].bpp==24){
		type=GL_RGB;
	}
	//glTexImage2D(GL_TEXTURE_2D, 0, type, texture->width, texture->height, 0, type, GL_UNSIGNED_BYTE, texture->imageData);
	gluBuild2DMipmaps (GL_TEXTURE_2D,4,texture[0].width,texture[0].height,type,GL_UNSIGNED_BYTE,texture[0].imageData);
	return true;											// Texture Building Went Ok, Return True
}

bool LoadCompressedTGA(TextureTGA *texture,const char *filename, FILE *fTGA){
	GLuint pixelcount	= 0;												/* Number of pixels in the image */
	GLuint currentpixel	= 0;												/* Current pixel being read */
	GLuint currentbyte	= 0;												/* Current byte */
	GLubyte * colorbuffer = (GLubyte *)malloc(tga.bytesPerPixel);			/* Storage for 1 pixel */

	if(fread(tga.header, sizeof(tga.header), 1, fTGA) == 0)				/* Attempt to read header */
	{
		printf("Error could not read info header");							/* Display Error */
		if(fTGA != NULL)													/* If file is open */
		{
			fclose(fTGA);													/* Close it */
		}
		return false;														/* Return failed */
	}

	texture->width  = tga.header[1] * 256 + tga.header[0];					/* Determine The TGA Width	(highbyte*256+lowbyte) */
	texture->height = tga.header[3] * 256 + tga.header[2];					/* Determine The TGA Height	(highbyte*256+lowbyte) */
	texture->bpp	= tga.header[4];										/* Determine Bits Per Pixel */
	tga.Width		= texture->width;										/* Copy width to local structure */
	tga.Height		= texture->height;										/* Copy width to local structure */
	tga.Bpp			= texture->bpp;											/* Copy width to local structure */
	
	pixelcount=tga.Height*tga.Width;

	if((texture->width <= 0) || (texture->height <= 0) || ((texture->bpp != 24) && (texture->bpp !=32)))	/*Make sure all texture info is ok */
	{
		printf("Error Invalid texture information");						/* If it isnt...Display error */
		if(fTGA != NULL)													/* Check if file is open */
		{
			fclose(fTGA);													/* Ifit is, close it */
		}
		return false;														/* Return failed */
	}

	tga.bytesPerPixel	= (tga.Bpp / 8);									/* Compute BYTES per pixel */
	tga.imageSize		= (tga.bytesPerPixel * tga.Width * tga.Height);		/* Compute amout of memory needed to store image */
	texture->imageData	= (GLubyte *)malloc(tga.imageSize);					/* Allocate that much memory */

	if(texture->imageData == NULL)											/* If it wasnt allocated correctly.. */
	{
		printf("Error could not allocate memory for image");				/* Display Error */
		fclose(fTGA);														/* Close file */
		return false;														/* Return failed */
	}

	do
	{
		GLubyte chunkheader = 0;											/* Storage for "chunk" header */

		if(fread(&chunkheader, sizeof(GLubyte), 1, fTGA) == 0)				/* Read in the 1 byte header */
		{
			printf("Error could not read RLE header");						/*Display Error */
			if(fTGA != NULL)												/* If file is open */
			{
				fclose(fTGA);												/* Close file */
			}
			if(texture->imageData != NULL)									/* If there is stored image data */
			{
				free(texture->imageData);									/* Delete image data */
			}
			return false;													/* Return failed */
		}

		if(chunkheader < 128)												/* If the ehader is < 128, it means the that is the number of RAW color packets minus 1 */
		{
			short counter;													/* that follow the header */
			chunkheader++;													/* add 1 to get number of following color values */
			for(counter = 0; counter < chunkheader; counter++)				/* Read RAW color values */
			{
				if(fread(colorbuffer, 1, tga.bytesPerPixel, fTGA) != tga.bytesPerPixel) /* Try to read 1 pixel */
				{
					printf("Error could not read image data");				/* IF we cant, display an error */

					if(fTGA != NULL)										/* See if file is open */
					{
						fclose(fTGA);										/* If so, close file */
					}

					if(colorbuffer != NULL)									/* See if colorbuffer has data in it */
					{
						free(colorbuffer);									/* If so, delete it */
					}

					if(texture->imageData != NULL)										/* See if there is stored Image data */
					{
						free(texture->imageData);										/* If so, delete it too */
					}

					return false;														/* Return failed */
				}
																						/* write to memory */
				texture->imageData[currentbyte		] = colorbuffer[2];				    /* Flip R and B vcolor values around in the process */
				texture->imageData[currentbyte + 1	] = colorbuffer[1];
				texture->imageData[currentbyte + 2	] = colorbuffer[0];

				if(tga.bytesPerPixel == 4)												/* if its a 32 bpp image */
				{
					texture->imageData[currentbyte + 3] = colorbuffer[3];				/* copy the 4th byte */
				}

				currentbyte += tga.bytesPerPixel;										/* Increase thecurrent byte by the number of bytes per pixel */
				currentpixel++;															/* Increase current pixel by 1 */

				
				if(currentpixel > pixelcount)											// Make sure we havent read too many pixels
				{
					printf("Error too many pixels read AQUI");								// if there is too many... Display an error!

					if(fTGA != NULL)													// If there is a file open
					{
						fclose(fTGA);													// Close file
					}

					if(colorbuffer != NULL)												// If there is data in colorbuffer
					{
						free(colorbuffer);												// Delete it
					}

					if(texture->imageData != NULL)										// If there is Image data
					{
						free(texture->imageData);										// delete it
					}

					return false;														// Return failed
				}
				
			}
		}
		else																			/* chunkheader > 128 RLE data, next color  reapeated chunkheader - 127 times */
		{
			short counter;
			chunkheader -= 127;															/* Subteact 127 to get rid of the ID bit */
			if(fread(colorbuffer, 1, tga.bytesPerPixel, fTGA) != tga.bytesPerPixel)		/* Attempt to read following color values */
			{
				printf("Error could not read from file");			/* If attempt fails.. Display error (again) */

				if(fTGA != NULL)														/* If thereis a file open */
				{
					fclose(fTGA);														/* Close it */
				}

				if(colorbuffer != NULL)													/* If there is data in the colorbuffer */
				{
					free(colorbuffer);													/* delete it */
				}

				if(texture->imageData != NULL)											/* If thereis image data */
				{
					free(texture->imageData);											/* delete it */
				}

				return false;															/* return failed */
			}

			for(counter = 0; counter < chunkheader; counter++)					/* copy the color into the image data as many times as dictated */
			{																			/* by the header */
				texture->imageData[currentbyte		] = colorbuffer[2];					/* switch R and B bytes areound while copying */
				texture->imageData[currentbyte + 1	] = colorbuffer[1];
				texture->imageData[currentbyte + 2	] = colorbuffer[0];

				if(tga.bytesPerPixel == 4)												/* If TGA images is 32 bpp */
				{
					texture->imageData[currentbyte + 3] = colorbuffer[3];				/* Copy 4th byte */
				}

				currentbyte += tga.bytesPerPixel;										/* Increase current byte by the number of bytes per pixel */
				currentpixel++;															/* Increase pixel count by 1 */
				
				
				if(currentpixel > pixelcount)											// Make sure we havent written too many pixels
				{
					printf("Error too many pixels read en bucle2");						// if there is too many... Display an error!
					//printf("ancho %u alto %u",tga.Height,tga.Width);
					//printf("pixels leidos %u",currentpixel);
					//printf("pixels maximos %u",pixelcount);
					if(fTGA != NULL)													// If there is a file open
					{
						fclose(fTGA);													// Close file
					}

					if(colorbuffer != NULL)												// If there is data in colorbuffer
					{
						free(colorbuffer);												// Delete it
					}

					if(texture->imageData != NULL)										// If there is Image data
					{
						free(texture->imageData);										// delete it
					}

					return false;														// Return failed
				}
				
			}
		}
	}

	while(currentpixel < pixelcount);													/* Loop while there are still pixels left */
	fclose(fTGA);																		/* Close the file */
	// Build A Texture From The Data
	glGenTextures(1, &texture[0].texID);					// Generate OpenGL texture IDs

	glBindTexture(GL_TEXTURE_2D, texture[0].texID);			// Bind Our Texture
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);	// Linear Filtered
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);	// Linear Filtered
			
	GLuint		type=GL_RGBA;								// Set The Default GL Mode To RBGA (32 BPP)
	if (texture[0].bpp==24)									// Was The TGA 24 Bits
	{
		type=GL_RGB;										// If So Set The 'type' To GL_RGB
	}
	//glTexImage2D(GL_TEXTURE_2D, 0, type, texture[0].width, texture[0].height, 0, type, GL_UNSIGNED_BYTE, texture[0].imageData);
	gluBuild2DMipmaps (GL_TEXTURE_2D,4,texture[0].width,texture[0].height,type,GL_UNSIGNED_BYTE,texture[0].imageData);
	return true;
}
void computar_estadistica_perdida() {
	frame->swJuego.Start(0);
	if (!juego->hemos_acabado) {
		if(tipo_juego == KLONDIKE3)	total_juegos[KLONDIKE-7000]++;
		else 						total_juegos[tipo_juego-7000]++;
		frame->m_scoreFile->Escribe(frame->jugador, total_juegos,juegos_ganados);
	} else {
		// Ya se computo la estadistica por terminar el juego
		estadistica_computada=false;
		// Ya se grabo el record al grabar el juego
		record_grabado=false;
	}
}
void restablece_automaticos() {
	if (juego->esperar) {
		// Ponemos automaticos en espera
		// porque estamos en los undo/redo
		if (is_auto_enabled) {
			winMenuAuto->Enable(wxID_COPY, false);
		}
		toolBar->EnableTool(wxID_COPY, false);
	} else {
		if (is_auto_enabled) {
			// Ponemos el boton de automatico a su posicion anterior
			winMenuAuto->Enable(wxID_COPY, true);
			toolBar->EnableTool(wxID_COPY, true);
			if (is_auto_checked) {
				toolBar->ToggleTool(wxID_COPY, true);
				juego->juego_automatico=true;
				winMenuAuto->Check(wxID_COPY, true);
			}
		} else { // Aqui esta el problema de los automaticos !!!!!
			if (is_auto_checked) {
				toolBar->ToggleTool(wxID_COPY, true);
				juego->juego_automatico=true;
				winMenuAuto->Check(wxID_COPY, true);
			}
		}
		if (juego->actual_mov->sig_mov==NULL) {
			// Ponemos los redos desactivados
			// porque se ha salido de los undo/redo
			toolBar->EnableTool(wxID_REDO, false);
			winMenuAuto->Enable(wxID_REDO, false);
			winMenuAuto->Enable(ID_REDOALL, false);
		}
	}
	//toolBar->Realize();
}
void guardar_camara() {
	camara_backup=camara;
}
void restaurar_camara() {
	camara=camara_backup;
}
void chequea_automaticos(void) {
	if (juego->automatico_permitido) {
		winMenuAuto->Enable(wxID_COPY, true);
		toolBar->EnableTool(wxID_COPY, true);
		if (juego->juego_automatico) {
			toolBar->ToggleTool(wxID_COPY, true);
			winMenuAuto->Check(wxID_COPY, true);
		} else {
			toolBar->ToggleTool(wxID_COPY, false);
			winMenuAuto->Check(wxID_COPY, false);
		}
	} else {
		if (!juego->juego_automatico) {
			winMenuAuto->Enable(wxID_COPY, false);
			winMenuAuto->Check(wxID_COPY, false);
			toolBar->ToggleTool(wxID_COPY, false);
			toolBar->EnableTool(wxID_COPY, false);
		} else {
			winMenuAuto->Check(wxID_COPY, true);
			winMenuAuto->Enable(wxID_COPY, false);
			toolBar->ToggleTool(wxID_COPY, true);
			toolBar->EnableTool(wxID_COPY, false);
		}
	}
	is_auto_checked=toolBar->GetToolState(wxID_COPY ); // Da si esta chequeado o no
	is_auto_enabled=toolBar->GetToolEnabled(wxID_COPY); // Da si esta enabled o no
	// Ademas inicializa varias variables para el inicio de juegos
	restaurar_camara();
	winMenuAuto->Check(wxID_COPY, true);

	toolBar->EnableTool(wxID_REDO, false);
	toolBar->EnableTool(wxID_UNDO, false);

	winMenuAuto->Enable(wxID_UNDO, false);
	winMenuAuto->Enable(wxID_REDO, false);
	winMenuAuto->Enable(ID_UNDOALL, false);
	winMenuAuto->Enable(ID_REDOALL, false);
	//toolBar->Realize();
}
void ConstruirCaja(int num, float ix, float iy) {
	caja[num]=glGenLists(1); // Generamos 1 List
	glNewList(caja[num], GL_COMPILE); // Start With The Cube List
	glBegin(GL_TRIANGLE_STRIP);
	// Cara de frente
	glNormal3f( 0.0f, 0.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(ix, iy, 0.0f); //Arriba derecha
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-ix, iy, 0.0f); //Arriba izquierda
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(ix, -iy, 0.0f); //Abajo  derecha
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-ix, -iy, 0.0f); //Abajo  izquierda
	glEnd();
	glEndList();
	// Primer triangulo con v0,v1,v2; segundo triangulo con v2,v1,v3
}
void triangulo(int num, float ix, float iy) {
	caja[(int)num]=glGenLists(1); // Generamos 1 List
	glNewList(caja[(int)num], GL_COMPILE); // Start With The Cube List
	glBegin(GL_TRIANGLES);
	// Cara de frente
	glNormal3f( 0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.5f, 1.0f);
	glVertex3f(0.f, iy, 0.0f); //Arriba centro
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(ix, -iy, 0.0f); //Abajo  derecha
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-ix, -iy, 0.0f); //Abajo  izquierda
	glEnd();
	glEndList();
}
void movimiento(float xfin, float yfin, float zfin, int n) {
	GLfloat xdesp, ydesp, zdesp;
	int v;
	bool animacion=true;
	// Velocidades variables
	if (velocidad<18)
		velocidad=18; // Para evitar dividir por cero
	if (!juego->afin)
		v=velocidad/6;
	else
		v=velocidad*2/5;
	//printf("Velocidad es: %d \n",velocidad);
	if (camara_lenta)
		v=100;
	juego->carta[n]->z=crender.zcartas+crender.desp_sel;
	juego->carta_seleccionada=n;
	if (retroceso && !camara_lenta)
		v=2;//v=velocidad/14;
	xdesp=(xfin-juego->carta[n]->x)/(GLfloat) v;
	ydesp=(yfin-juego->carta[n]->y)/(GLfloat) v;
	zdesp=(zfin-juego->carta[n]->z)/(GLfloat) v;
	mov_pendiente=true;
	while (animacion) {
		// Va a toda hostia porque no hay control de tiempos !!!
		// Voy a meter un bloqueo de frames. OK
		frame->m_canvas->Swap();
		juego->carta[n]->x=juego->carta[n]->x+xdesp;
		juego->carta[n]->y=juego->carta[n]->y+ydesp;
		juego->carta[n]->z=juego->carta[n]->z+zdesp;
		frame->m_canvas->renderiza(GL_RENDER);
		if (contador<v) {
			contador++;
			if (!retroceso)
				rot-=360.0f/(v-1);
		} else {
			contador=1;
			animacion=false;
			rot=0.0f;
		}
	}
	juego->carta_seleccionada=NOCARTA;
	juego->afin=false;
	mov_pendiente=false;
}
bool OpenGLCanvas::proceso_de_carga(int a, GLint modo) {
	color[3]    = 0.7f;
	color_ini[3]= 0.7f;
	color_fin[3]= 0.7f;
	color_cas[3]= 0.7f;
	SetCurrent(*m_glcontext);
	zfondo=-42.0f;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpiamos los buffers de pantalla y Depth
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	glGetIntegerv(GL_VIEWPORT, viewport);
	glGetDoublev(GL_MODELVIEW_MATRIX,modelview);
	glGetDoublev(GL_PROJECTION_MATRIX,projection);
	if (!gluProject((GLdouble)-0.06f, (GLdouble)0.38f, (GLdouble)-1.20f+0.3f,
			modelview, projection, viewport, &winx, &winy, &winz))
		return false;

	// FONDO DE PANTALLA
	glLoadIdentity();
	glDisable(GL_TEXTURE_2D);
	glBegin(GL_QUADS);
	glColor4fv(color_ini);
	glVertex3f(-24.955f, -24.68f, zfondo);
	glColor4fv(color_ini);
	glVertex3f( 24.955f, -24.68f, zfondo);
	glColor4fv(color_fin);
	glVertex3f( 24.955f, 24.68f, zfondo);
	glColor4fv(color_fin);
	glVertex3f(-24.955f, 24.68f, zfondo);
	glEnd();
	if(a) {
		deckOld[a]=new GLuint;
		textura[a]=NULL;
		deckRetro[a]=new TextureTGA;
		//deckStandard[a]=new TextureTGA;
		deckStandard[a]=new GLuint;
		if (!(deckOld[a]      = LoadPointerGLTextures(files_texturas1[a])))return false;
		if (!(deckStandard[a] = LoadPointerGLTextures(files_texturas2[a])))return false;
		//if (!LoadTGA(deckStandard[a],files_texturas2[a]))			return false;
		if (!LoadTGA(deckRetro[a],files_texturas4[a]))				return false;
		textura[a]=deckStandard[a];
		//textura[a]=&(deckStandard[a]->texID);
	}
	glColor4fv(color);
	glEnable(GL_TEXTURE_2D);
	glColor4fv(color);

	if (!a) {
		serp3D(53);
		glColor4fv(color);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glLoadIdentity();
		glDisable(GL_TEXTURE_2D);
		glLineWidth(4.0f);
		if (!hemos_pinchado_start) {
			glBegin(GL_QUADS);
			glColor4fv(color_ini);
			glVertex3f(-0.2f, 0.075f, -1.0f);
			glVertex3f( 0.2f, 0.075f, -1.0f);
			glColor4fv(color_fin);
			glVertex3f( 0.2f, -0.075f, -1.0f);
			glVertex3f(-0.2f, -0.075f, -1.0f);
			glEnd();
			glBegin(GL_LINES);
			glColor4fv(color_barra);
			glVertex3f(-0.2f, 0.075f, -1.0f);
			glVertex3f( 0.2f, 0.075f, -1.0f);
			glVertex3f( 0.2f, -0.075f, -1.0f);
			glVertex3f(-0.2f, -0.075f, -1.0f);
			glEnd();
		}
		glBlendFunc(GL_SRC_ALPHA,GL_ONE);
		glEnable(GL_TEXTURE_2D);
		if (modo == GL_SELECT) {
			glInitNames();
			glPushName(1);
		}
		glColor4f(.8f, 0.8f, 0.8f, 1.f);
		glBindTexture(GL_TEXTURE_2D,*textura[PANEL]);
		if (modo==GL_SELECT)
			glLoadName(START);
		if (!hemos_pinchado_start) {
			glLoadIdentity();
			glTranslatef(0.0f, 0.0f, crender.zcartas+0.3f);
			glCallList(caja[2]);
		}
		if (modo==GL_SELECT)
			glPopName();
		glColor4fv(color_texto);
		//if (!hemos_pinchado_start) {
			//glPrintBitmap (292, 231, "Start", 1, textura[FUENTE], base_textura);
		//}
		glDisable(GL_BLEND);
	} else
		serp3D(a-1);
	base_cil+=0.1;
	color[3]    = 1.f;
	color_ini[3]= 1.f;
	color_fin[3]= 1.f;
	color_cas[3]= 1.f;
	//wxMilliSleep(1);
	SwapBuffers(); // Swap Buffers (Double Buffering)
	return true;
}
void OpenGLCanvas::serp3D(int a){
	for (int cc=1; cc<a; cc++) {
		glLoadIdentity();
		double xcil=0.48*sin(-base_cil/5+cc/9.);
		double ycil=0.38*cos(-base_cil/9+cc/15.);
		//double zcil=-0.5*(cos(-base_cil/10+cc/20.))-1.5;
		double zcil=4.0*(cos(-base_cil/10+cc/20.)-1);
		glTranslated(xcil, ycil, zcil);
		glBindTexture(GL_TEXTURE_2D, *textura[cc]);
		glCallList(caja[0]);
	}
	//glLoadIdentity();
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	//glEnable(GL_BLEND);
	//glColor3f(1.0f, 0.5f, 0.0f);
	// Se imprime el texto de copyright
	//glPrintBitmap (370, 25, "Big Solitaires 3D v1.1", 1, textura[FUENTE], base_textura);
	//glDisable(GL_BLEND);
}
void movimiento_ini(float xfin, float yfin, float zfin, int n) {
	//MSG		msg;			// Estructura de mensajes de ventana
	int v;
	bool animacion=true;
	v=3;
	juego->carta_seleccionada=n;
	juego->carta[n]->z=juego->carta[n]->z+0.03f; // o sea, desp_z*30;
	GLfloat xdesp=(xfin-juego->carta[n]->x)/(GLfloat) v;
	GLfloat ydesp=(yfin-juego->carta[n]->y)/(GLfloat) v;
	GLfloat zdesp=(zfin-juego->carta[n]->z)/(GLfloat) v;

	while (animacion) {
		// Va a toda hostia porque no hay control de tiempos !!!
		// Voy a meter un bloqueo de frames. OK
		frame->m_canvas->Swap();
		juego->carta[n]->x=juego->carta[n]->x+xdesp;
		juego->carta[n]->y=juego->carta[n]->y+ydesp;
		juego->carta[n]->z=juego->carta[n]->z+zdesp;
		renderiza_ini();
		if (contador<v)
			contador++;
		else {
			contador=1;
			animacion=false;
		}
	}
	juego->carta_seleccionada=NOCARTA;
	juego->afin=false;
}
void renderiza_ini(void) {
	float x, y, z;
	int textur=0;
	int cc;
	lista *alfa=NULL;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpiamos los buffers de pantalla y Depth
	glMatrixMode (GL_MODELVIEW);
	if(fondo_color == true){
		// *********** //
		// FONDO COLOR //
		// *********** //
		glLoadIdentity();
		glDisable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
		glColor4fv(color_fin);
		glVertex3f(-1.f, -0.6f, zfondo);
		glColor4fv(color_ini);
		glVertex3f( 1.f, -0.6f, zfondo);
		glColor4fv(color_fin);
		glVertex3f( 1.f, 0.6f, zfondo);
		glColor4fv(color_ini);
		glVertex3f(-1.f, 0.6f, zfondo);
		glEnd();
		glColor4fv(color);
		// ********* //
		// FIN COLOR //
		// ********* //
		glLoadIdentity();
		glEnable(GL_TEXTURE_2D);
	}else{
		// ************ //
		// FONDO IMAGEN //
		// ************ //
		glLoadIdentity();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, *fondo);
		glLoadIdentity();
		glBegin(GL_QUADS);
		glNormal3f(0.0f,0.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-.76f,-.6f,zfondo);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( .76f,-.6f,zfondo);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( .76f, .6f,zfondo);		
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-.76f, .6f,zfondo);
		glEnd();
		// ********** //
		// FIN IMAGEN //
		// ********** //
	}
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	// Hay que pintar las GOLUMS VACIAS para que no desaparezcan 
	// al mover las cartas
	for (int c=0; c<juego->num_golum; c++) {
		if (juego->golum[c]->selec) // Es un GOLUM seleccionable
		{
			textur=juego->golum[c]->textura;
			x= juego->golum[c]->x;
			y= juego->golum[c]->y;
			z= juego->golum[c]->z;
			glLoadIdentity();
			glTranslatef(x, y, z);
			glBindTexture(GL_TEXTURE_2D, *textura[textur]);
			glColor4fv(color_cas);
			glCallList(caja[0]);
			glColor4fv(color);
		}
	}

	// Dibujamos las columnas
	for (int c=0; c<juego->num_golum; c++) {
		if (juego->golum[c]->num_cartas) {
			// Vamos al primer elemento de la lista
			alfa=juego->golum[c]->primer_valor->sig;
			for (int k=0; k<juego->golum[c]->num_cartas; k++) {
				cc=alfa->carta;
				textur=juego->carta[cc]->bitmap;
				if (!juego->carta[cc]->mostrada)
					textur=0;
				x=juego->carta[cc]->x;
				y=juego->carta[cc]->y;
				z=juego->carta[cc]->z;
				glLoadIdentity();
				glTranslatef(x, y, z);
				glBindTexture(GL_TEXTURE_2D, *textura[textur]);
				if (!(juego->carta[cc]->valor==1 && tipo_juego==MONTANA))
					glCallList(caja[0]);
				if (alfa->sig !=NULL)
					alfa=alfa->sig;
			}
		} else if (!juego->golum[c]->num_cartas && juego->golum[c]->tipo!=4) {
			textur=juego->golum[c]->textura;
			x=juego->golum[c]->x;
			y=juego->golum[c]->y;
			z=juego->golum[c]->z;
			glLoadIdentity();
			glTranslatef(x, y, z);
			glBindTexture(GL_TEXTURE_2D, *textura[textur]);
			glColor4fv(color_cas);
			if (juego->golum[c]->tipo==3)
				glCallList(caja[6]);
			else
				glCallList(caja[0]);
			glColor4fv(color);
		}
	}
	// Y ahora la carta que se mueve
	if (juego->carta_seleccionada!=NOCARTA) {
		glLoadIdentity();
		glTranslatef(juego->carta[juego->carta_seleccionada]->x,
				juego->carta[juego->carta_seleccionada]->y,
				juego->carta[juego->carta_seleccionada]->z);
		glBindTexture(GL_TEXTURE_2D, *textura[0]);
		glCallList(caja[0]);
	}
	frame->m_canvas->Swap();
}
int OpenGLCanvas::renderiza(GLint modo) {
	float x,y,z;
	int textur=0;
	int cc;
	lista *alfa=NULL;
	float fInterval=fTime-fTimeOld;
	// Update fps stats
	if (fInterval > 5.0f) { // Cada 5 segundos actualizamos FPS
		sprintf(buffer, "Fps: %3.0f", frames/fInterval);
		if (juego->FASE_PRESENTACION)
			velocidad=1;
		else
			velocidad=((GLuint)(frames/fInterval));
		frames=0;
		fTimeOld=fTime;
		frame->SetStatusText(buffer, 5);
	}
	/*
	 if(juego->hemos_acabado){
	 int lugar=-12;
	 //float xcil=0.4*sin(-base_cil/5+lugar/9.) + 0.2*cos(base_cil/13+lugar/21.);
	 float ycil=0.38*cos(-base_cil/9+lugar/15.);
	 //glTranslated(xcil,ycil,crender.zcartas+0.02f+52*0.0001f);	
	 
	 //camara.m_vPosition.x=xcil;
	 //camara.m_vPosition.y=ycil;
	 //camara.m_vPosition.z=crender.zcartas+0.02f+12*0.0001f;
	 
	 //camara.m_vView.x=xcil;
	 camara.m_vView.y=.5f+ycil;
	 //camara.m_vView.z=crender.zcartas+0.02f+lugar*0.0001f;
	 camara.m_vView.z=crender.zcartas-1.2f;
	 
	 //camara.MoveCamera(0.001f*signo);
	 //camara.RotateAroundPoint(0.f,0.f,-0.001f*signo);
	 //camara.StrafeCamera(-0.001f*signo);
	 }
	 */
	// Bonito efecto si no limpiamos los buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpiamos los buffers de pantalla y Depth

	if (modo==GL_RENDER) {
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity(); // Reset The Projection Matrix
		gluPerspective(45.0f, (GLfloat)resX/(GLfloat)resY, 0.1f, 100.0f); // Calculate The Aspect Ratio Of The Window
		//FIN restauraGL
		// Vamos con la camara
		//glMatrixMode (GL_PROJECTION);
		//glLoadMatrixd(mat_proy);
		gluLookAt(camara.m_vPosition.x, camara.m_vPosition.y,
				camara.m_vPosition.z, camara.m_vView.x, camara.m_vView.y,
				camara.m_vView.z, camara.m_vUpVector.x,
				camara.m_vUpVector.y, camara.m_vUpVector.z);
	}

	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	if(fondo_color == true){
		// *********** //
		// FONDO COLOR //
		// *********** //
		glLoadIdentity();
		glDisable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
		glColor4fv(color_fin);
		glVertex3f(-1.f, -0.6f, zfondo);
		glColor4fv(color_ini);
		glVertex3f( 1.f, -0.6f, zfondo);
		glColor4fv(color_fin);
		glVertex3f( 1.f, 0.6f, zfondo);
		glColor4fv(color_ini);
		glVertex3f(-1.f, 0.6f, zfondo);
		glEnd();
		glColor4fv(color);
		// ********* //
		// FIN COLOR //
		// ********* //
		glLoadIdentity();
		glEnable(GL_TEXTURE_2D);
	}else{
		// ************ //
		// FONDO IMAGEN //
		// ************ //
		glLoadIdentity();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, *fondo);
		glLoadIdentity();
		glBegin(GL_QUADS);
		glNormal3f(0.0f,0.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-.76f,-.6f,zfondo);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( .76f,-.6f,zfondo);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( .76f, .6f,zfondo);		
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-.76f, .6f,zfondo);
		glEnd();
		// ********** //
		// FIN IMAGEN //
		// ********** //
	}
	if (juego->FASE_PRESENTACION) {
		return juego->repartir();
	}

	// Activamos luces
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);
	
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	
	// Hay que pintar las GOLUMS VACIAS para que no desaparezcan 
	// al mover las cartas
	for (int c=0; c<juego->num_golum; c++) {
		if (juego->golum[c]->selec) // Es un GOLUM seleccionable
		{
			textur=juego->golum[c]->textura;
			x= juego->golum[c]->x;
			y= juego->golum[c]->y;
			z= juego->golum[c]->z-0.0001f;
			glLoadIdentity();
			glTranslatef(x, y, z);
			glBindTexture(GL_TEXTURE_2D, *textura[textur]);
			glColor4fv(color_cas);
			glCallList(caja[0]);
			glColor4fv(color);
		}
	}

	superseleccion=1; // Asignara un id para cada carta "pinchable"
	int cartas_sel=0; // Posibles cartas seleccionables

	if (modo == GL_SELECT&& !opcion) // Estamos en modo seleccion
	{ // y fuera de menu?
		// Vamos a contar las cartas seleccionables
		for (int c=0; c<juego->num_golum; c++) {
			if (juego->golum[c]->tipo==0&& juego->golum[c]->num_cartas)
				cartas_sel++;
			else if (juego->golum[c]->tipo==1&& juego->golum[c]->num_cartas)
				cartas_sel++;
			else if (juego->golum[c]->tipo==2&& juego->golum[c]->num_cartas)
				//cartas_sel=cartas_sel+juego->golum[c]->num_cartas;
				cartas_sel+=juego->golum[c]->num_cartas;
			else if (juego->golum[c]->tipo==2&& !juego->golum[c]->num_cartas)
				cartas_sel++;
		}
		glInitNames(); // Inicializamos la pila de nombres
		glPushName(cartas_sel); // Tantas cartas tenemos seleccionables
	}

	// Dibujamos las columnas
	// Primero la columna del mazo (pueden ser varias!!!)
	for (int c=0; c<juego->num_golum; c++) {
		if (juego->golum[c]->num_cartas && juego->golum[c]->tipo==0) // Es un MAZO
		{
			// Vamos al primer elemento de la lista
			alfa=juego->golum[c]->primer_valor->sig;
			for (int k=0; k<juego->golum[c]->num_cartas-1; k++) // Todas menos una para la superseleccion
			{
				cc=alfa->carta;
				textur=juego->carta[cc]->bitmap;
				if (!juego->carta[cc]->mostrada)
					textur=0;
				x=juego->carta[cc]->x;
				y=juego->carta[cc]->y;
				z=juego->carta[cc]->z;
				glLoadIdentity();
				glTranslatef(x, y, z);
				glBindTexture(GL_TEXTURE_2D, *textura[textur]);
				glCallList(caja[0]);
				if (alfa->sig !=NULL)
					alfa=alfa->sig;
			}
		} else if (juego->golum[c]->num_cartas && juego->golum[c]->tipo==1) // Es una PILA
		{
			// Vamos al primer elemento de la lista
			alfa=juego->golum[c]->primer_valor->sig;
			for (int k=0; k<juego->golum[c]->num_cartas-1; k++) // Todas menos una para la superseleccion
			{
				cc=alfa->carta;
				textur=juego->carta[cc]->bitmap;
				if (!juego->carta[cc]->mostrada)
					textur=0;
				x=juego->carta[cc]->x;
				y=juego->carta[cc]->y;
				z=juego->carta[cc]->z;
				glLoadIdentity();
				glTranslatef(x, y, z);
 				glBindTexture(GL_TEXTURE_2D, *textura[textur]);
				glCallList(caja[0]);
				if (alfa->sig !=NULL)
					alfa=alfa->sig;
			}
		}
	}
	// Las ultimas cartas del mazo o pila
	for (int c=0; c<juego->num_golum; c++) {
		if (juego->golum[c]->num_cartas && juego->golum[c]->tipo==0) // Es un MAZO
		{
			// Vamos al ultimo elemento de la lista
			alfa=juego->golum[c]->ultimo_valor;
			cc=alfa->carta;
			textur=juego->carta[cc]->bitmap;
			if (!juego->carta[cc]->mostrada)
				textur=0;
			x=juego->carta[cc]->x;
			y=juego->carta[cc]->y;
			z=juego->carta[cc]->z;
			if (modo==GL_SELECT&& !opcion)
				glLoadName(superseleccion++);
			glLoadIdentity();
			glTranslatef(x, y, z);
			glBindTexture(GL_TEXTURE_2D, *textura[textur]);
			glCallList(caja[0]);
		} else if (!juego->golum[c]->num_cartas && juego->golum[c]->textura==MAZO_SI && juego->golum[c]->tipo==0) // ES UN MAZO RECICLABLE
		{
			if (modo==GL_SELECT&& !opcion)
				glLoadName(superseleccion++);
			x=juego->golum[c]->x;
			y=juego->golum[c]->y;
			z=juego->golum[c]->z-0.0001f;
			glLoadIdentity();
			glTranslatef(x, y, z);
			glBindTexture(GL_TEXTURE_2D, *textura[MAZO_SI]);
			glCallList(caja[0]);
		} else if (juego->golum[c]->num_cartas && juego->golum[c]->tipo==1)// Es una PILA
		{
			// Vamos al ultimo elemento de la lista
			alfa=juego->golum[c]->ultimo_valor;
			cc=alfa->carta;
			textur=juego->carta[cc]->bitmap;
			if (!juego->carta[cc]->mostrada)
				textur=0;
			x=juego->carta[cc]->x;
			y=juego->carta[cc]->y;
			z=juego->carta[cc]->z;
			glLoadIdentity();
			glTranslatef(x, y, z);
			glBindTexture(GL_TEXTURE_2D, *textura[textur]);
			if (!juego->carta[cc]->seleccionada) {
				if (modo==GL_SELECT&& !opcion)
					glLoadName(superseleccion);
				glCallList(caja[0]);
			} else if (juego->carta[cc]->seleccionada && modo==GL_SELECT
					&& !opcion) {
				glLoadName(superseleccion);
				glCallList(caja[0]);
			}
		}
	}

	// Ahora el resto de GOLUMS TIPO COLUMNA
	for (int c=0; c<juego->num_golum; c++) {
		if (juego->golum[c]->num_cartas && juego->golum[c]->tipo==2) // Es una COLUMNA
		{
			// Vamos al primer elemento de la lista
			alfa=juego->golum[c]->primer_valor->sig;
			for (int k=0; k<juego->golum[c]->num_cartas; k++)// Todas para la superseleccion
			{
				cc=alfa->carta;
				textur=juego->carta[cc]->bitmap;
				if (!juego->carta[cc]->mostrada)
					textur=0;
				x=juego->carta[cc]->x;
				y=juego->carta[cc]->y;
				z=juego->carta[cc]->z;
				superseleccion=c*100+k;
				glLoadIdentity();
				glTranslatef(x, y, z);
				glBindTexture(GL_TEXTURE_2D, *textura[textur]);
				if (juego->carta[cc]->seleccionada) { // Para el doble click; sino no se puede seleccionar
					if (modo==GL_SELECT&& !opcion) {
						glLoadName(superseleccion);
						glCallList(caja[0]);
					} else if (tipo_juego!=MONTANA)
						break; // No necesario pintar si esta selec; mas adelante se dibuja
				} else {
					if (modo==GL_SELECT&& !opcion)
						glLoadName(superseleccion);
					if (!(juego->carta[cc]->valor==1&& tipo_juego==MONTANA))
						glCallList(caja[0]);
				}
				if (alfa->sig !=NULL)
					alfa=alfa->sig;
			}
		}
	}

	// Ahora las GOLUMS VACIAS que sean seleccionables
	// Esto incluye las FINALES VACIAS seleccionables
	for (int c=0; c<juego->num_golum; c++) {
		if (!juego->golum[c]->num_cartas && juego->golum[c]->selec) // Es un GOLUM seleccionable
		{
			// Vamos al primer elemento de la lista
			textur=juego->golum[c]->textura;
			x= juego->golum[c]->x;
			y= juego->golum[c]->y;
			z= juego->golum[c]->z-0.0001f;
			superseleccion=c*100;
			if (modo==GL_SELECT&& !opcion)
				glLoadName(superseleccion);
			glLoadIdentity();
			glTranslatef(x, y, z);
			glBindTexture(GL_TEXTURE_2D, *textura[textur]);
			if (juego->golum[c]->textura==MAZO_SI) // ES UN MAZO RECICLABLE
			{
				//if((ciclo%60)>0 && ((ciclo)%60)<30) 
				glBindTexture(GL_TEXTURE_2D, *textura[MAZO_SI]);
				//else glBindTexture(GL_TEXTURE_2D, textura[MAZO_SI2]);
				//ciclo++;
			}
			glColor4fv(color_cas);
			if (juego->golum[c]->tipo==3)
				glCallList(caja[6]);
			else
				glCallList(caja[0]);
			glColor4fv(color);
		}
	}
	// Cerramos seleccion
	if (modo==GL_SELECT&& !opcion) {
		glPopName();
	}

	// Las GOLUMS FINALES NO VACIAS PERO LO PUEDEN SER CON EL UNDO
	if (juego->columna_inicio!=NOCOL
			&& juego->golum[juego->columna_inicio]->tipo==3) { // Es una FINAL VACIA
		textur=juego->golum[juego->columna_inicio]->textura;
		x =juego->golum[juego->columna_inicio]->x;
		y =juego->golum[juego->columna_inicio]->y;
		z =juego->golum[juego->columna_inicio]->z;
		glLoadIdentity();
		glTranslatef(x, y, z);
		glBindTexture(GL_TEXTURE_2D, *textura[textur]);
		glColor4fv(color_cas);
		glCallList(caja[6]);
		glColor4fv(color);
	}

	// Si quito estas lineas no desaparece el AS
	// pero al retroceder desaparece el as si solo hay dos cartas
	// Solo pinto al retroceder
	/*
	 if(juego->columna_final!=NOCOL && juego->golum[juego->columna_final]->tipo==3 && juego->undo)
	 {	 // Es una FINAL VACIA
	 textur=juego->golum[juego->columna_final]->textura;
	 x     =juego->golum[juego->columna_final]->x;
	 y     =juego->golum[juego->columna_final]->y;
	 z     =juego->golum[juego->columna_final]->z;
	 glLoadIdentity();glTranslatef(x,y,z);
	 glBindTexture(GL_TEXTURE_2D, textura[textur]);
	 glColor4fv(color_cas);glCallList(caja[6]);glColor4fv(color);
	 }
	 */
	// Las GOLUMS FINALES
	for (int c=0; c<juego->num_golum; c++) {
		if (juego->golum[c]->num_cartas && juego->golum[c]->tipo==3) // Es una FINAL CON CARTAS
		{
			// Vamos al primer elemento de la lista
			alfa=juego->golum[c]->primer_valor->sig;
			for (int k=0; k<juego->golum[c]->num_cartas; k++) {
				cc=alfa->carta;
				textur=juego->carta[cc]->bitmap;
				if (!juego->carta[cc]->mostrada)
					textur=0;
				x=juego->carta[cc]->x;
				y=juego->carta[cc]->y;
				z=juego->carta[cc]->z;
				glLoadIdentity();
				glTranslatef(x, y, z);
 				glBindTexture(GL_TEXTURE_2D, *textura[textur]);
				if (cc!=juego->carta_seleccionada)
					glCallList(caja[6]);
				if (alfa->sig != NULL)
					alfa=alfa->sig;
			}
		} else if (!juego->golum[c]->num_cartas && juego->golum[c]->tipo==3) // Es una FINAL VACIA
		{
			textur=juego->golum[c]->textura;
			x =juego->golum[c]->x;
			y =juego->golum[c]->y;
			z =juego->golum[c]->z;
			glLoadIdentity();
			glTranslatef(x, y, z);
			glBindTexture(GL_TEXTURE_2D, *textura[textur]);
			glColor4fv(color_cas);
			glCallList(caja[6]);
			glColor4fv(color);
		}
	}
	/*********************************************************************/
	/********************** LA/s CARTA/s SELECCIONADA/s ******************/
	/*********************************************************************/
	if (juego->carta_seleccionada!=NOCARTA&& juego->columna_inicio!=NOCOL) {
		float despx=0.f;
		float despy=0.f;
		float despz=0.f;
		int cual_col=2;
		alfa=juego->golum[juego->columna_inicio]->primer_valor->sig;
		for (int k=0; k<juego->golum[juego->columna_inicio]->num_cartas; k++) {
			if (juego->carta[alfa->carta]->seleccionada) {
				glLoadIdentity();
				if (!juego->carta[alfa->carta]->mostrada)
					textur=0;
				else
					textur=juego->carta[alfa->carta]->bitmap;
				x=juego->carta[alfa->carta]->x
						=juego->carta[juego->carta_seleccionada]->x+despx;
				y=juego->carta[alfa->carta]->y
						=juego->carta[juego->carta_seleccionada]->y+despy;
				z=juego->carta[alfa->carta]->z
						=juego->carta[juego->carta_seleccionada]->z+despz;
				glTranslatef(x, y, z);
				if (juego->afin)					glRotatef(rot, 0.0f, 0.0f, 1.0f);
				if(!mov_pendiente) {
					// Algo de transparencia y un pequeño cambio de color...
					//color[0]    = 1.0f;
					//color[1]    = 0.3f;
					//color[2]    = 0.3f;
					color[3]    = 0.8f;
					glColor4fv(color);
				}
				glBindTexture(GL_TEXTURE_2D, *textura[textur]);
				if (juego->afin || retroceso)		glCallList(caja[0]);
				else								glCallList(caja[1]);
				color[3]=1.0f;
				glColor4fv(color);
				if (juego->columna_final==NOCOL)	cual_col=juego->columna_inicio;
				else								cual_col=juego->columna_final;
				despx+=juego->golum[cual_col]->desp_x;
				despy+=juego->golum[cual_col]->desp_y;
				despz+=juego->golum[cual_col]->desp_z;
			}
			if (alfa->sig!=NULL)
				alfa=alfa->sig;
		}
	}

	// ANIMACION FINAL DE JUEGO
	// ------------------------
	if (juego->hemos_acabado) { // La serpiente de cartas
		for (int cc=1; cc<cuantas_serp; cc++) {
			glLoadIdentity();
			double xcil=0.4*sin(-base_cil/5+cc/9.) + 0.2
					*cos(base_cil/13+cc/21.);
			double ycil=0.38*cos(-base_cil/9+cc/15.);
			glTranslated(xcil, ycil, crender.zcartas+0.02f+cc*0.0001f);
			glBindTexture(GL_TEXTURE_2D, *textura[cc]);
			glCallList(caja[0]);
			//camara.RotateAroundPoint(0.f,0.f,0.f);
			//camara.m_vPosition.y+=(float)xcil*0.001f;
			//camara.m_vPosition.x+=(float)xcil*0.001f;
			//camara.m_vPosition.z-=(float)xcil*0.00025f;
			//camara.m_vPosition.y-=(float)xcil*0.0005f;
		}
		//	if(camara.m_vPosition.x<1.5f) camara.m_vPosition.x+=0.001f;
		//	camara.m_vPosition.z-=0.002f
		//	camara.RotateAroundPoint(0.f,0.5f,0.f);
	}

	// Tener en cuenta esto de la carta iluminada
	//if(juego->carta_iluminada==juego->col[r][k]){glColor4fv(color_cas);glCallList(caja[0]);glColor4fv(color);}

	// TOMA DE DATOS PARA MOVER LA CARTA CON EL CURSOR
	// -------------------------------------------------
	// No sirve para nada
	/*
	 glLoadIdentity();
	 glGetIntegerv(GL_VIEWPORT, viewport);
	 glGetDoublev(GL_MODELVIEW_MATRIX,modelview);
	 glGetDoublev(GL_PROJECTION_MATRIX,projection);
	 float zw=juego->carta[juego->carta_seleccionada]->z;
	 //if(!gluProject((GLdouble)-0.06f,(GLdouble)0.38f,(GLdouble)zw,modelview,projection,viewport,&winx,&winy,&winz))
	 if(!gluProject((GLdouble)0.f,(GLdouble)0.f,(GLdouble)zw,modelview,projection,viewport,&winx,&winy,&winz))
	 //if(!gluProject((GLdouble)0.f,(GLdouble)0.f,(GLdouble)zw,modelview,projection,viewport,&winx,&winy,&winz))
	 return false;
	 */
	// INFORMACION DE JUEGO Y CARTAS QUE QUEDAN
	// ---------------------------------------------
	//glLoadIdentity();
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	//glEnable(GL_BLEND);
	//glColor4fv(color_texto);

	// DESactivamos luces
	//glDisable(GL_LIGHTING);
	//glDisable(GL_LIGHT0);
	//glDisable(GL_LIGHT1);
	
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	if (!juego->hemos_acabado) {
		long actual=frame->swJuego.Time();
		hours=(int)(actual/3600000.);
		minutes=(int)((actual/60000.)-((float)hours*60000));
		seconds=(actual-(float)(minutes*60000)-(float)(hours*3600000))/1000.;
	}
	sprintf(buffer2, "Pile: %d cards", juego->golum[0]->num_cartas);
	frame->SetStatusText(buffer2, 1);
	if (juego->num_mov != num_movimientos) {
		num_movimientos=juego->num_mov;
		sprintf(buffer2, "Move: %d ", juego->num_mov);
		frame->SetStatusText(buffer2, 2);
	}
	if (juego->cartas_colocadas != num_cartas_colocadas) {
		num_cartas_colocadas=juego->cartas_colocadas;
		sprintf(buffer2, "Put: %d cards", juego->cartas_colocadas);
		frame->SetStatusText(buffer2, 3);
	}
	if (segundos_actuales != (int)seconds) {
		segundos_actuales=(int)seconds;
		if (seconds < 10.0f) {
			if (minutes < 10)
				sprintf(bufferTiempo, "0%1d:0%1d:0%1.f", hours, minutes,seconds);
			else
				sprintf(bufferTiempo, "0%1d:%2d:0%1.f", hours, minutes, seconds);
		} else {
			if (minutes < 10)
				sprintf(bufferTiempo, "0%1d:0%1d:%2.f", hours, minutes, seconds);
			else
				sprintf(bufferTiempo, "0%1d:%2d:%2.f", hours, minutes, seconds);
		}
		sprintf(buffer2, "Time: %s", bufferTiempo);
		frame->SetStatusText(buffer2, 4);
	}
	rotraro-=45.0f/velocidad;
	base_cil+=0.1;
	if (juego->hemos_acabado && cuantas_serp<53)		cuantas_serp++;
	return TRUE;
}
int OpenGLCanvas::renderiza_vacio() {
	float x, y, z;
	int textur=0;
	// Bonito efecto si no limpiamos los buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpiamos los buffers de pantalla y Depth

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // Reset The Projection Matrix
	gluPerspective(45.0f, (GLfloat)resX/(GLfloat)resY, 0.1f, 100.0f); // Calculate The Aspect Ratio Of The Window
	//FIN restauraGL
	// Vamos con la camara
	//glMatrixMode (GL_PROJECTION);
	//glLoadMatrixd(mat_proy);
	gluLookAt(camara.m_vPosition.x, camara.m_vPosition.y,
			camara.m_vPosition.z, camara.m_vView.x, camara.m_vView.y,
			camara.m_vView.z, camara.m_vUpVector.x,
			camara.m_vUpVector.y, camara.m_vUpVector.z);

	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	if(fondo_color == true){
		// *********** //
		// FONDO COLOR //
		// *********** //
		glLoadIdentity();
		glDisable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
		glColor4fv(color_fin);
		glVertex3f(-1.f, -0.6f, zfondo);
		glColor4fv(color_ini);
		glVertex3f( 1.f, -0.6f, zfondo);
		glColor4fv(color_fin);
		glVertex3f( 1.f, 0.6f, zfondo);
		glColor4fv(color_ini);
		glVertex3f(-1.f, 0.6f, zfondo);
		glEnd();
		glColor4fv(color);
		// ********* //
		// FIN COLOR //
		// ********* //
		glLoadIdentity();
		glEnable(GL_TEXTURE_2D);
	}else{
		// ************ //
		// FONDO IMAGEN //
		// ************ //
		glLoadIdentity();
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, *fondo);
		glLoadIdentity();
		glBegin(GL_QUADS);
		glNormal3f(0.0f,0.0f,1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-.76f,-.6f,zfondo);	
		glTexCoord2f(1.0f, 0.0f); glVertex3f( .76f,-.6f,zfondo);	
		glTexCoord2f(1.0f, 1.0f); glVertex3f( .76f, .6f,zfondo);		
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-.76f, .6f,zfondo);
		glEnd();
		// ********** //
		// FIN IMAGEN //
		// ********** //
	}
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	// Hay que pintar las GOLUMS VACIAS para que no desaparezcan 
	// al mover las cartas
	for (int c=0; c<juego->num_golum; c++) {
		if (juego->golum[c]->selec) // Es un GOLUM seleccionable
		{
			textur=juego->golum[c]->textura;
			x= juego->golum[c]->x;
			y= juego->golum[c]->y;
			z= juego->golum[c]->z-0.0001f;
			glLoadIdentity();
			glTranslatef(x, y, z);
			glBindTexture(GL_TEXTURE_2D, *textura[textur]);
			glColor4fv(color_cas);
			glCallList(caja[0]);
			glColor4fv(color);
		}
	}
	// Las ultimas cartas del mazo o pila
	for (int c=0; c<juego->num_golum; c++) {
		if (juego->golum[c]->textura==MAZO_SI && juego->golum[c]->tipo==0) // ES UN MAZO RECICLABLE
		{
			x=juego->golum[c]->x;
			y=juego->golum[c]->y;
			z=juego->golum[c]->z-0.0001f;
			glLoadIdentity();
			glTranslatef(x, y, z);
			glBindTexture(GL_TEXTURE_2D, *textura[MAZO_SI]);
			glCallList(caja[0]);
		}
	}

	// Ahora las GOLUMS VACIAS que sean seleccionables
	// Esto incluye las FINALES VACIAS seleccionables
	for (int c=0; c<juego->num_golum; c++) {
		if (juego->golum[c]->selec) // Es un GOLUM seleccionable
		{
			// Vamos al primer elemento de la lista
			textur=juego->golum[c]->textura;
			x= juego->golum[c]->x;
			y= juego->golum[c]->y;
			z= juego->golum[c]->z-0.0001f;
			superseleccion=c*100;
			glLoadIdentity();
			glTranslatef(x, y, z);
			glBindTexture(GL_TEXTURE_2D, *textura[textur]);
			if (juego->golum[c]->textura==MAZO_SI) // ES UN MAZO RECICLABLE
			{
				//if((ciclo%60)>0 && ((ciclo)%60)<30) 
				glBindTexture(GL_TEXTURE_2D, *textura[MAZO_SI]);
				//else glBindTexture(GL_TEXTURE_2D, textura[MAZO_SI2]);
				//ciclo++;
			}
			glColor4fv(color_cas);
			if (juego->golum[c]->tipo==3)
				glCallList(caja[6]);
			else
				glCallList(caja[0]);
			glColor4fv(color);
		}
	}
	// Las GOLUMS FINALES NO VACIAS PERO LO PUEDEN SER CON EL UNDO
	if (juego->columna_inicio!=NOCOL
			&& juego->golum[juego->columna_inicio]->tipo==3) { // Es una FINAL VACIA
		textur=juego->golum[juego->columna_inicio]->textura;
		x =juego->golum[juego->columna_inicio]->x;
		y =juego->golum[juego->columna_inicio]->y;
		z =juego->golum[juego->columna_inicio]->z;
		glLoadIdentity();
		glTranslatef(x, y, z);
		glBindTexture(GL_TEXTURE_2D, *textura[textur]);
		glColor4fv(color_cas);
		glCallList(caja[6]);
		glColor4fv(color);
	}

	// Las GOLUMS FINALES
	for (int c=0; c<juego->num_golum; c++) {
		if (juego->golum[c]->tipo==3) // Es una FINAL VACIA
		{
			textur=juego->golum[c]->textura;
			x =juego->golum[c]->x;
			y =juego->golum[c]->y;
			z =juego->golum[c]->z;
			glLoadIdentity();
			glTranslatef(x, y, z);
			glBindTexture(GL_TEXTURE_2D, *textura[textur]);
			glColor4fv(color_cas);
			glCallList(caja[6]);
			glColor4fv(color);
		}
	}
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	return TRUE;
}
int OpenGLCanvas::dame_cartaID(int x, int y) // Busca carta pinchada
{
	int objetos_encontrados=0;
	GLuint buf_selec[128]; // Buffer de Seleccion (4*objeto) en 40 ladrones
	GLint i, j, k;
	int nombre, z1, z2;

	glGetIntegerv(GL_VIEWPORT, viewport);
	glSelectBuffer(128, buf_selec);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix ();
	glLoadIdentity ();
	glRenderMode(GL_SELECT);
	gluPickMatrix(x, viewport[3]-y, 1, 1, viewport);
	// We set the Perspective
	gluPerspective(45.0f, (float)resX/(float)resY, 0.1f, 100.0f); // 50
	gluLookAt(camara.m_vPosition.x, camara.m_vPosition.y,
			camara.m_vPosition.z, camara.m_vView.x, camara.m_vView.y,
			camara.m_vView.z, camara.m_vUpVector.x, camara.m_vUpVector.y,
			camara.m_vUpVector.z);
	// We call the menu
	if (tipo_juego)
		renderiza(GL_SELECT);
	else
		proceso_de_carga(0, GL_SELECT);
	objetos_encontrados = glRenderMode(GL_RENDER);
	// We choose the Visualisation Matrix
	glMatrixMode(GL_PROJECTION);
	// We load the saved matrix	
	glPopMatrix ();
	// We choose the Visualisation Matrix
	glMatrixMode(GL_MODELVIEW);
	int objeto_old=0;
	int objeto=0;

	if (objetos_encontrados > 0) {
		j = 0; // Variable temporal
		for (i = 0; i < objetos_encontrados; i++) {
			nombre= buf_selec[j];
			j++;
			z1 = buf_selec[j];
			j++;
			z2 = buf_selec[j];
			j++;
			for (k = 0; k < nombre; k++) {
				objeto=buf_selec[j];
				if (buf_selec[j] == 0)
					return 0; // MAZO
				if (buf_selec[j] == 1)
					return 1; // PILA
				if (buf_selec[j] == START)
					return START;
				j++;
			}
			if (objeto>objeto_old)
				objeto_old=objeto;
		}
	}
	return objeto;
}

// Implementation of Test-GLCanvas
// LOS EVENTOS
BEGIN_EVENT_TABLE(OpenGLCanvas, wxGLCanvas)
EVT_SIZE(OpenGLCanvas::OnSize)
EVT_PAINT(OpenGLCanvas::OnPaint)
EVT_ERASE_BACKGROUND(OpenGLCanvas::OnEraseBackground)
EVT_KEY_DOWN( OpenGLCanvas::OnKeyDown )
EVT_KEY_UP( OpenGLCanvas::OnKeyUp )
EVT_ENTER_WINDOW( OpenGLCanvas::OnEnterWindow )
EVT_IDLE( OpenGLCanvas::idle )
//EVT_MOUSE_EVENTS (OpenGLCanvas::onMouseEvent)
EVT_LEFT_DOWN (OpenGLCanvas::onMouseEvent)
EVT_LEFT_UP (OpenGLCanvas::onMouseEvent)
EVT_LEFT_DCLICK (OpenGLCanvas::onMouseEvent)
//EVT_MIDDLE_DOWN
//EVT_MIDDLE_UP
//EVT_MIDDLE_DCLICK
EVT_RIGHT_DOWN (OpenGLCanvas::onMouseEvent)
//EVT_RIGHT_UP
//EVT_RIGHT_DCLICK
EVT_MOTION (OpenGLCanvas::onMouseEvent)
//EVT_ENTER_WINDOW
//EVT_LEAVE_WINDOW
EVT_MOUSEWHEEL(OpenGLCanvas::onMouseWheel)
END_EVENT_TABLE()
OpenGLCanvas::OpenGLCanvas(wxWindow *parent, wxWindowID id,
		const wxPoint& pos, const wxSize& size, long style, const wxString& name)
#if !wxCHECK_VERSION(3, 0, 0)
: wxGLCanvas(parent, (wxGLCanvas*) NULL, id, pos, size, style|wxFULL_REPAINT_ON_RESIZE , name ), m_glcontext(0)
#else
: wxGLCanvas(parent, id, (const int *) NULL, pos, size, style|wxFULL_REPAINT_ON_RESIZE , name ), m_glcontext(0)
#endif
{
#if wxCHECK_VERSION(3, 0, 0)
    m_glcontext = new wxGLContext(this, NULL);
#endif
	m_init = false;
	m_gllist = 0;
	m_rleft = WXK_LEFT;
	m_rright = WXK_RIGHT;
	m_up = WXK_UP;
	m_down = WXK_DOWN;
	m_home = WXK_HOME;
	m_end = WXK_END;
	m_insert = WXK_INSERT;
	m_del = WXK_DELETE;
	m_avpag = WXK_PAGEUP;
	m_repag = WXK_PAGEDOWN;
	m_NUMPAD5 = WXK_NUMPAD5;
	m_F1 = WXK_F1;
	m_F5 = WXK_F5;
	m_F6 = WXK_F6;
	m_F7 = WXK_F7;
	m_F8 = WXK_F8;
	m_F2 = WXK_F2;
	m_F3 = WXK_F3;
	m_NUMPAD1 = WXK_NUMPAD1;
	m_NUMPAD2 = WXK_NUMPAD2;
	m_NUMPAD3 = WXK_NUMPAD3;
	m_NUMPAD4 = WXK_NUMPAD4;
	m_NUMPAD5 = WXK_NUMPAD5;
	m_NUMPAD7 = WXK_NUMPAD7;
	m_NUMPAD8 = WXK_NUMPAD8;
	m_NUMPAD9 = WXK_NUMPAD9;
	#if TEST
		m_escape = WXK_ESCAPE;
	#endif
	// Sonido
	sonido_win = NULL;
	swinFile = WAV_WIN;
	if ( !sonido_win ) {
		sonido_win = new wxSound;
		CreateSoundWin(*sonido_win);
	}
}
// CREA EL SONIDO GANAR
bool OpenGLCanvas::CreateSoundWin(wxSound& snd) const {
	return snd.Create(swinFile);
}
OpenGLCanvas::~OpenGLCanvas() {
    delete m_glcontext;
}
void OpenGLCanvas::onMouseEvent(wxMouseEvent& e) {
	int cartaID;
	doble_click=false;
	if (e.LeftDown()) {
		if (!mov_pendiente) {
			wxPoint pt = e.GetPosition();
			//pt = ScreenToClient(pt);
			boton_pulsado=true;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity(); // Reset The Projection Matrix
			gluPerspective(45.0f, (GLfloat)resX/(GLfloat)resY, 0.1f, 100.0f); // Calculate The Aspect Ratio Of The Window
			gluLookAt (camara.m_vPosition.x, camara.m_vPosition.y,
					camara.m_vPosition.z, camara.m_vView.x,
					camara.m_vView.y, camara.m_vView.z,
					camara.m_vUpVector.x, camara.m_vUpVector.y,
					camara.m_vUpVector.z);
			glMatrixMode (GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(camara.m_vPosition.x, camara.m_vPosition.y,
					camara.m_vPosition.z, camara.m_vView.x,
					camara.m_vView.y, camara.m_vView.z,
					camara.m_vUpVector.x, camara.m_vUpVector.y,
					camara.m_vUpVector.z);
			float screen_z;
			glGetDoublev( GL_MODELVIEW_MATRIX, modelview);
			glGetDoublev( GL_PROJECTION_MATRIX, projection);
			glGetIntegerv( GL_VIEWPORT, viewport);
			float winXX = (float)pt.x;
			float winYY = (float)viewport[3] - (float)pt.y;
			glReadPixels(pt.x, int(winYY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &screen_z );
			gluUnProject(winXX, winYY, screen_z, modelview, projection,
					viewport, &xx, &yy, &zz);
			juego->x_ori=xx;
			juego->y_ori=yy;
			cartaID = dame_cartaID(e.GetX(), e.GetY());
			if (juego->carta_seleccionada!=NOCARTA&& juego->columna_inicio
					!=NOCOL) {
				juego->mover_a_columna(cartaID);
			} else if (cartaID>0&& cartaID<6000) { // Hasta 59 columnas seleccionables
				juego->carta_seleccionada=juego->que_carta_es(cartaID);
			}
			switch (cartaID) {
			case START:
				hemos_pinchado_start=true;
				frame->MostrarJugadores();
				if (hemos_seleccionado_jugador) {
					frame->MuestraJuegos();
				}
				respuesta=false;
				opcion=NADA;
				/* Activamos menus */
				winMenuFile->Enable(wxID_NEW, true);
				winMenuFile->Enable(ID_RESTART_GAME, true);
				winMenuFile->Enable(ID_SELECT_NUMBER_GAME, true);
				winMenuOpen->Enable(wxID_OPEN, true);
				winMenuOpen->Enable(ID_POPULAR, true);
				winOptions->Enable(ID_CAMARA, true);
				winOptions->Check(ID_CAMARA_STANDARD, false);
				winOptions->Check(ID_CAMARA_MAIN, true);
				winMenuFile->Enable(ID_ESTADISTICAS, true);
				winMenuFile->Enable(ID_BEST_TIMES, true);
				winMenuHelp->Enable(ID_HELP, true);
				/* Activamos la toolbar */
				toolBar->EnableTool(wxID_NEW, true);
				toolBar->EnableTool(wxID_OPEN, true);
				toolBar->EnableTool(wxID_UNDO, true);
				toolBar->EnableTool(wxID_REDO, true);
				toolBar->EnableTool( ID_HELP, true);
				toolBar->Realize();
				juego->esperar=false;
				chequea_automaticos();
				restablece_automaticos();
				if (hemos_seleccionado_jugador && frame->TiposAlArrancar=="yes") {
					frame->MostrarTip();
				}
				break;
			case 0:
				if (juego->carta_seleccionada!=NOCARTA) {
					juego->columna_inicio=NOCOL;
					juego->carta_seleccionada=NOCARTA;
				}
				// Nada debe de pasar

				// INICIO RESTAURAGL
				//glMatrixMode(GL_PROJECTION);
				//glLoadIdentity();				// Reset The Projection Matrix
				//gluPerspective(45.0f,(GLfloat)resX/(GLfloat)resY,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window
				// FIN RESTAURAGL
				break;
			} // Fin del switch
		} // Fin del if(!movimiento pendiente)

		if (juego != NULL) {
			juego->x_ori=(float)(juego->x_ori)
					-juego->carta[juego->carta_seleccionada]->x;
			juego->y_ori=(float)(juego->y_ori)
					-juego->carta[juego->carta_seleccionada]->y;
		}

	} else if (e.RightDown()) {
		if (!juego->FASE_PRESENTACION && !mov_pendiente && !opcion
				&& juego->carta_seleccionada==NOCARTA) {
			juego->esperar=false;
			restablece_automaticos();
			juego->busca_sitio_boton_derecho();
		}
	} else if (e.LeftDClick()) {
		doble_click=true;
		juego->carta_seleccionada=NOCARTA;
		juego->columna_inicio=NOCOL;
		if (!mov_pendiente) {
			cartaID = dame_cartaID(e.GetX(), e.GetY());
			juego->ondobleclick(cartaID);
		}
		juego->esperar=false;
		restablece_automaticos();
		doble_click=false;
	} else if (e.Dragging()) {
		wxPoint pt = e.GetPosition();
		//pt = ScreenToClient(pt);
		if (boton_pulsado && juego->carta_seleccionada!=NOCARTA
				&& juego->mover_permitido) {
			if (juego->carta_seleccionada!=NOCARTA) {
				juego->carta[juego->carta_seleccionada]->z=crender.zcartas
						+crender.desp_sel;
			}
			mov_pendiente=true;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity(); // Reset The Projection Matrix
			gluPerspective(45.0f, (GLfloat)resX/(GLfloat)resY, 0.1f, 100.0f); // Calculate The Aspect Ratio Of The Window
			gluLookAt (camara.m_vPosition.x, camara.m_vPosition.y,
					camara.m_vPosition.z, camara.m_vView.x,
					camara.m_vView.y, camara.m_vView.z,
					camara.m_vUpVector.x, camara.m_vUpVector.y,
					camara.m_vUpVector.z);
			glMatrixMode (GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(camara.m_vPosition.x, camara.m_vPosition.y,
					camara.m_vPosition.z, camara.m_vView.x,
					camara.m_vView.y, camara.m_vView.z,
					camara.m_vUpVector.x, camara.m_vUpVector.y,
					camara.m_vUpVector.z);
			float screen_z;
			glGetDoublev( GL_MODELVIEW_MATRIX, modelview);
			glGetDoublev( GL_PROJECTION_MATRIX, projection);
			glGetIntegerv( GL_VIEWPORT, viewport);
			float winXX = (float)pt.x;
			float winYY = (float)viewport[3] - (float)pt.y;
			glReadPixels(pt.x, int(winYY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &screen_z );
			gluUnProject(winXX, winYY, screen_z, modelview, projection,
					viewport, &xx, &yy, &zz);
			juego->carta[juego->carta_seleccionada]->x=(float)xx
					-(float)juego->x_ori;
			juego->carta[juego->carta_seleccionada]->y=(float)yy
					-(float)juego->y_ori;
		}
	} else if (e.LeftUp()) {
		// Boton liberado
		if (boton_pulsado && mov_pendiente) { // Se ha soltado la carta agarrada
			juego->busca_sitio();
			mov_pendiente=false;
			juego->esperar=false;
			restablece_automaticos();
		}
		boton_pulsado=false;
	}
}
void OpenGLCanvas::onMouseWheel(wxMouseEvent& e) {
	int m_wheelRotation=0;
	m_wheelRotation += e.GetWheelRotation();
	// ********************* UNDO ******************** //
	if (juego->carta_seleccionada==NOCARTA&& !juego->hemos_acabado
			&& m_wheelRotation == -WHEEL_DELTA) {
		if (juego->deshacer()) { // && juego->juego_automatico) {
			juego->esperar=true;
			juego->juego_automatico=false;
			winMenuAuto->Enable(wxID_REDO, true);
			winMenuAuto->Enable(ID_REDOALL, true);
			toolBar->EnableTool(wxID_REDO, true);
			restablece_automaticos();
		}
		if (juego->actual_mov->ant_mov==NULL) {
			// ESTAMOS EN PRIMER MOVIMIENTO. IMPOSIBLE DESHACER DE NUEVO
			winMenuAuto->Enable(wxID_UNDO, false);
			winMenuAuto->Enable(ID_UNDOALL, false);
			toolBar->EnableTool(wxID_UNDO, false);
		}
	}
	// ********************* REDO ******************** //
	if (juego->carta_seleccionada==NOCARTA&& !juego->hemos_acabado
			&& m_wheelRotation == WHEEL_DELTA) {
		if (juego->rehacer() && juego->juego_automatico) {
			juego->esperar=true;
			juego->juego_automatico=false;
		}
		winMenuAuto->Enable(wxID_UNDO, true);
		winMenuAuto->Enable(ID_UNDOALL, true);
		toolBar->EnableTool(wxID_UNDO, true);
		if (juego->actual_mov->sig_mov==NULL) {
			winMenuAuto->Enable(wxID_REDO, false);
			winMenuAuto->Enable(ID_REDOALL,false);
			toolBar->EnableTool(wxID_REDO, false);
		}
	}
	toolBar->Realize();
}
void OpenGLCanvas::idle(wxIdleEvent& e) {
	//char bb[12];
	//sprintf(bb, "%d", juego->numero_juego);
	//fprintf(stderr,"Numero de juego %s que corresponde al %d\n",bb,juego->numero_juego);
	
	// VERIFICAMOS SI PARTIDA GANADA
	if (juego->cartas_colocadas == juego->mazo_juego) {
		juego->hemos_acabado=true;
		toolBar->EnableTool(wxID_UNDO, false);
		winMenuAuto->Enable(wxID_UNDO, false);
		winMenuAuto->Enable(ID_UNDOALL, false);
		winMenuAuto->Enable(wxID_REDO, false);
		winMenuAuto->Enable(ID_REDOALL,false);
		toolBar->EnableTool(wxID_REDO, false);
		//toolBar->Realize();
		if (estadistica_computada==false) {
			if(tipo_juego == KLONDIKE3) {
				total_juegos[KLONDIKE-7000]++;
				juegos_ganados[KLONDIKE-7000]++;
			}else{
				total_juegos[tipo_juego-7000]++;
				juegos_ganados[tipo_juego-7000]++;
			}
			frame->m_scoreFile->Escribe(frame->jugador, total_juegos,juegos_ganados);
			estadistica_computada=true;
			// Tocamos aplausos
			if (activar_sonido && sonido_win->IsOk()) {
				sonido_win->Play(wxSOUND_ASYNC);
			}
		}
		// Guardamos posicion de la camara
		guardar_camara();
		// Guardamos tiempo record si se produce
		// -------------------------------------
		if (record_grabado==false) {
			bool klondike3=false;
			if(tipo_juego == KLONDIKE3) {
				tipo_juego=KLONDIKE;
				klondike3=true;
			}
			if ( *(frame->BestTime [tipo_juego-7000])=="--:--:--") {
				*(frame->BestJugador[tipo_juego-7000])=frame->jugador;
				*(frame->BestTime [tipo_juego-7000])=bufferTiempo;
				char b[11];
				sprintf(b, "%d", juego->numero_juego);
				*(frame->BestNumber [tipo_juego-7000])=b;
			} else {
				// Medimos tiempos en segundos
				int tiempoJuego=hours*3600+minutes*60+segundos_actuales;
				char valor[9];
				sprintf(valor, "%s", frame->BestTime[tipo_juego-7000]->c_str());
				char h[3];
				h[0]=valor[0];
				h[1]=valor[1];
				h[2]='\0';
				int ih=atoi(h);
				char m[3];
				m[0]=valor[3];
				m[1]=valor[4];
				m[2]='\0';
				int im=atoi(m);
				char s[3];
				s[0]=valor[6];
				s[1]=valor[7];
				s[2]='\0';
				int is=atoi(s);
				int recordAntiguo=ih*3600+im*60+is;
				if (tiempoJuego < recordAntiguo) {
					char recordNuevo[9];
					sprintf(recordNuevo, "%d", juego->numero_juego);
					*(frame->BestTime [tipo_juego-7000])=bufferTiempo;
					*(frame->BestNumber [tipo_juego-7000])=recordNuevo;
					*(frame->BestJugador[tipo_juego-7000])=frame->jugador;
					wxMessageDialog dialogClick( NULL, frame->jugador + ", you have the new time record in this game!!",_T("New time record"), wxOK|wxICON_EXCLAMATION);
					dialogClick.ShowModal();
				}
			}
			record_grabado=true;
			if(klondike3==true)	tipo_juego=KLONDIKE3;
		}
	} // FIN VERIFICACION PARTIDA GRABADA
	if (juego->esperar==false) {
		// VERIFICAMOS UNDOS/REDOS
		if (juego->num_mov && !juego->hemos_acabado) {
			toolBar->EnableTool(wxID_UNDO, true);
			winMenuAuto->Enable(wxID_UNDO, true);
			winMenuAuto->Enable(ID_UNDOALL, true);
		}
		if (juego->actual_mov->ant_mov==NULL) {
			// ESTAMOS EN PRIMER MOVIMIENTO. IMPOSIBLE DESHACER DE NUEVO
			winMenuAuto->Enable(wxID_UNDO, false);
			winMenuAuto->Enable(ID_UNDOALL, false);
			toolBar->EnableTool(wxID_UNDO, false);
		}
		if (juego->actual_mov->sig_mov==NULL) {
			// ESTAMOS EN ULTIMO MOVIMIENTO. IMPOSIBLE REDO
			winMenuAuto->Enable(wxID_REDO, false);
			winMenuAuto->Enable(ID_REDOALL,false);
			toolBar->EnableTool(wxID_REDO, false);
		}
		//toolBar->Realize();
		restablece_automaticos();
	}
	//chequea_automaticos();
	if (juego->numero_juego>0) {
		sprintf(buffer2, "%s number %u", jocs[tipo_juego-7000].nombre, juego->numero_juego);
		frame->SetStatusText(buffer2);
	}
	Refresh(false);
}
void OpenGLCanvas::OnEnterWindow(wxMouseEvent& WXUNUSED(event)) {
	SetFocus();
}
void OpenGLCanvas::OnPaint(wxPaintEvent& WXUNUSED(event)) {
	wxPaintDC dc(this);
	// Init OpenGL once, but after SetCurrent
	if (!m_init) {
		InitGL();
		m_init = true;
	}
	if (arranque==false) {
		textura[HUECO]=new GLuint;
		if (!(textura[HUECO]= LoadPointerGLTextures("Data/1/inicio5.bmp")));
		textura[PANEL]=new GLuint;
		if (!(textura[PANEL]= LoadPointerGLTextures("Data/1/game.bmp")));
		textura[MAZO_NO]=new GLuint;
		if (!(textura[MAZO_NO]= LoadPointerGLTextures("Data/1/mazo_no.bmp")));
		textura[MAZO_SI]=new GLuint;
		if (!(textura[MAZO_SI]= LoadPointerGLTextures("Data/1/mazo_si.bmp")));
		textura[HUECO_K]=new GLuint;
		if (!(textura[HUECO_K]= LoadPointerGLTextures("Data/1/hueco_k.bmp")));
		textura[HUECO_2]=new GLuint;
		if (!(textura[HUECO_2]= LoadPointerGLTextures("Data/1/hueco_2.bmp")));
		textura[FINAL_AK]=new GLuint;
		if (!(textura[FINAL_AK]=LoadPointerGLTextures("Data/1/final_ak.bmp")));
		textura[FINAL_G]=new GLuint;
		if (!(textura[FINAL_G]= LoadPointerGLTextures("Data/1/apoyo.bmp")));
		textura[APOYO]=new GLuint;
		if (!(textura[APOYO]= LoadPointerGLTextures("Data/1/apoyo1.bmp")));
		textura[FINAL]=new GLuint;
		if (!(textura[FINAL]= LoadPointerGLTextures("Data/1/final_1.bmp")));
		textura[FINAL_2]=new GLuint;
		if (!(textura[FINAL_2]= LoadPointerGLTextures("Data/1/final_2.bmp")));
		textura[FINAL_3]=new GLuint;
		if (!(textura[FINAL_3]= LoadPointerGLTextures("Data/1/final_3.bmp")));
		textura[FINAL_4]=new GLuint;
		if (!(textura[FINAL_4]= LoadPointerGLTextures("Data/1/final_4.bmp")));
		textura[FINAL_5]=new GLuint;
		if (!(textura[FINAL_5]= LoadPointerGLTextures("Data/1/final_5.bmp")));
		textura[FINAL_6]=new GLuint;
		if (!(textura[FINAL_6]= LoadPointerGLTextures("Data/1/final_6.bmp")));
		textura[FINAL_7]=new GLuint;
		if (!(textura[FINAL_7]= LoadPointerGLTextures("Data/1/final_7.bmp")));
		textura[FINAL_8]=new GLuint;
		if (!(textura[FINAL_8]= LoadPointerGLTextures("Data/1/final_8.bmp")));
		textura[FINAL_9]=new GLuint;
		if (!(textura[FINAL_9]= LoadPointerGLTextures("Data/1/final_9.bmp")));
		textura[FINAL_10]=new GLuint;
		if (!(textura[FINAL_10]=LoadPointerGLTextures("Data/1/final_10.bmp")));
		textura[FINAL_J]=new GLuint;
		if (!(textura[FINAL_J]= LoadPointerGLTextures("Data/1/final_j.bmp")));
		textura[FINAL_Q]=new GLuint;
		if (!(textura[FINAL_Q]= LoadPointerGLTextures("Data/1/final_q.bmp")));
		textura[FINAL_K]=new GLuint;
		if (!(textura[FINAL_K]= LoadPointerGLTextures("Data/1/final_k.bmp")));
		// Cargamos texturas PNG
		for(int a=1;a<53;a++){
			deckFun[a]=LoadPNG(files_texturasFun[a]);
		}
		// CARGAMOS TEXTURA DE FONDO COMO UN PUNTERO
		fondo = new GLuint;
		//fondo= LoadPointerGLTextures("Data/1/fondoverde.bmp");
		fondoPNG=LoadPNG("Data/1/fondoverde.png");
		fondo=&(fondoPNG->id);
		
		QueryPerformanceFrequency(&TimerFreq);
		QueryPerformanceCounter(&TimeStart);
		
		// CELLS A VERDE
		color_base=0;
		color_cas[0]=0.f;color_cas[1]=0.95f;color_cas[2]=0.f;
		color_fin[0]=0.f;color_fin[1]=0.65f;color_fin[2]=0.f;
		
		for (int l=1; l<53; l++)
			if (!proceso_de_carga(l, GL_RENDER));
		
		ConstruirCaja(1, 0.0575f, 0.08625f); // Es la carta mas grande
		ConstruirCaja(5, 0.02f, 0.03f); // Es la barra de herramientas
		ConstruirCaja(4, 0.05f, 0.025f); // Es el cuadradito para yes,not y reset
		ConstruirCaja(6, 0.04f, 0.06f); // Es la carta FINAL
		juego=new game();
		arranque=true;
	}
	if (!tipo_juego) {
		proceso_de_carga(0, GL_RENDER);
	}
	if (hemos_arrancado==false) {
		//INICIO restauraGL();
		//glMatrixMode(GL_PROJECTION);
		//glLoadIdentity();				// Reset The Projection Matrix
		//gluPerspective(45.0f,(GLfloat)resX/(GLfloat)resY,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window
		//FIN restauraGL();
		proceso_de_carga(0, GL_RENDER);
		//Swap();
		//SwapBuffers();
		//if(juego->juego_automatico && !juego->hemos_acabado) juego->automatico();
	}
	if (hemos_arrancado==true) {
		//INICIO restauraGL();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity(); // Reset The Projection Matrix
		gluPerspective(45.0f, (GLfloat)resX/(GLfloat)resY, 0.1f, 100.0f); // Calculate The Aspect Ratio Of The Window
		//FIN restauraGL();
		renderiza(GL_RENDER);
		Swap();
		if (juego->juego_automatico && !juego->hemos_acabado)
			juego->automatico();
	}
}

void OpenGLCanvas::Swap(){
	do{
		wxMilliSleep(1);
	}while(!LockFrameRate());
	frames++;
	SwapBuffers();
}

/*
 * EL Swap de PSD
bool OpenGLCanvas::Swap() {
	wxMilliSleep(10);
	if (!hemos_arrancado) {
		SwapBuffers();
		return true;
	}
	if (LockFrameRate()) {
		frames++;
		SwapBuffers();
		return true;
	}
	return false;
}
*/
/*
void OpenGLCanvas::Swap() {
	//float fInterval=currentTime-fTimeOld;
	//if(hemos_arrancado){
		//do {
		//	wxMilliSleep(1);
		//} while(!LockFrameRate());
	while(!LockFrameRate()){
		wxMilliSleep(1);
	}
	//}else{
	//	wxMilliSleep(1);
	//}
	//lastTime = currentTime;
	//module_count++;
	frames++;
	SwapBuffers();
	// Recargamos modulo musical
	//if (module_count==3 && module) {
	//
	//if (Player_Active()) {
		//module_count = 0;
	//	MikMod_Update();
	//}else if(!Player_Active()){
	//	Player_Free(module);
	//	module = Player_Load("mods/test.s3m", 4, 0);
	//	if (module) {
	//		Player_Start(module);
	//	}
	//}
	//
	//}	
	
	// Si no ponemos un descanso, la cpu se pone al 100%
	// A 0 se calienta mucho la GPU; mejor a 5
	//wxMilliSleep(10);
	//Get current time in seconds (milliseconds * .001 = seconds)
	//currentTime = frame->swGeneral.Time() * 0.001f;
	// ============================ 
	// PONEMOS EL FRAME_RATE EN 500
	// ============================
	// TIENE MUCHO QUE VER CON LA RESOLUCION DE TIEMPOS. 1 ms.
	// Ponemos a 4ms, es decir,  1/250
	//if ((currentTime - lastTime) > 0.004f) {
	//printf("Tiempo actual: %5.10f\r",currentTime);
	//printf("Ultimo tiempo: %5.10f\r",lastTime);
	//printf("Diferencia:    %5.10f\r\r",currentTime-lastTime);
	//lastTime = currentTime; // Reset the last time
	//frames++;
	//SwapBuffers();
	//return true;
	//}
	//	return false;
}
*/
void OpenGLCanvas::OnSize(wxSizeEvent& event) {
	/*
	 // this is also necessary to update the context on some platforms
	 wxGLCanvas::OnSize(event);
	 // set GL viewport (not called by wxGLCanvas::OnSize on all platforms...)
	 GetClientSize(&resX, &resY);
	 #ifndef __WXMOTIF__
	 if (GetContext())
	 #endif
	 //SetCurrent();
	 //glViewport(0, 0, (GLint) resX, (GLint) resY);
	 if (!resY) resY=1;									// Evita dividir por cero y alto ventana 1 minimo
	 glViewport(0,0,resX,resY);							// Reset el actual Viewport
	 glMatrixMode(GL_PROJECTION);						// Selecciona la Matriz de Proyeccion
	 glLoadIdentity();									// Resetea    la Matriz de Proyeccion
	 // Calcula el aspecto de la ventana
	 gluPerspective(45.0f,(GLfloat)resX/(GLfloat)(resY),0.1f,50.0f);
	 glGetDoublev(GL_PROJECTION_MATRIX,mat_proy);
	 glMatrixMode(GL_MODELVIEW);							// Selecciona la Matriz Modelview
	 glLoadIdentity();									// Resetea    la Matriz Modelview
	 */
#if !wxCHECK_VERSION(3, 0, 0)
	// this is also necessary to update the context on some platforms
	wxGLCanvas::OnSize(event);
#endif // !wxCHECK_VERSION(3, 0, 0)
	// set GL viewport (not called by wxGLCanvas::OnSize on all platforms...)
	int w, h;
	GetClientSize(&w, &h);
	if (!m_init) {
		InitGL();
		glViewport(0, 0, (GLint) w, (GLint) h);
	}
}
void OpenGLCanvas::OnEraseBackground(wxEraseEvent& WXUNUSED(event)) {
	// Do nothing, to avoid flashing.
}
void OpenGLCanvas::InitGL() {
#if !wxCHECK_VERSION(3, 0, 0)
    wxGLCanvas::SetCurrent();
    m_glcontext = wxGLCanvas::GetContext();
#else
    SetCurrent(*m_glcontext);
#endif
	// We call this right after our OpenGL window is created.
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // This Will Clear The Background Color To Black
	glClearDepth(1.0); // Enables Clearing Of The Depth Buffer
	glDepthFunc(GL_LESS); // The Type Of Depth Test To Do
	glEnable(GL_DEPTH_TEST); // Enables Depth Testing
	glShadeModel(GL_SMOOTH); // Enables Smooth Color Shading
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // Reset The Projection Matrix
	gluPerspective(45.0f, (GLfloat)resX/(GLfloat)resY, 0.1f, 100.0f); // Calculate The Aspect Ratio Of The Window
	glMatrixMode(GL_MODELVIEW);
	textura[0]=new GLuint;
	if (!(background= LoadPointerGLTextures("Data/1/reverso3.bmp")));
	deckFun[0]=LoadPNG(files_texturasFun[0]);
	deckRetro[0]=new TextureTGA;
	if (!LoadTGA(deckRetro[0],"Data/4/0.tga"));
	textura[0]=background;

	//gettimeofday(&_tstart, &tz);

	// LUCES
	//glLightfv(GL_LIGHT0, GL_AMBIENT, ambientA);
	//glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseA);
	//glLightfv(GL_LIGHT0, GL_POSITION, positionA);

	//glLightfv(GL_LIGHT1, GL_AMBIENT, ambientB);
	//glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseB);
	//glLightfv(GL_LIGHT1, GL_POSITION, positionB);

	//glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	//glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

	//glFrontFace(GL_CW);
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHT1);
	//glEnable(GL_AUTO_NORMAL);
	//glEnable(GL_NORMALIZE);
	//glEnable(GL_DEPTH_TEST);
	
	//base_textura=BuildFontBitmap(textura[FUENTE]);
	sprintf(buffer2, "Loading...");
	frame->SetStatusText(buffer2, 1);
	// El resto de texturas se cargan en CreaGLVentana
	ConstruirCaja(2, 0.16f, 0.025f); // Es el cuadradito para el menu
	ConstruirCaja(0, 0.05f, 0.075f); // Es la carta
	ConstruirCaja(3, 0.1f, 0.06f); // Es el cuadradito para el logo
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f); // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST); // Activa Depth Testing
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST); // Antialiasing
	glDepthFunc(GL_LEQUAL); // El tipo de Depth Testing a hacer
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//LightAmbient[0]=.0f;LightAmbient[1]=.7f;
	//LightAmbient[2]=.0f;LightAmbient[3]=.0f;
	//LightPosition[3]=-10.0f;

	for (int k=0; k<40; k++) {
		total_juegos[k] = 0;
		juegos_ganados[k] = 0;
	}
	// Position		View						Up Vector
	//camara.PositionCamera(0, 0.0f, 6,	0, 0.0f, 0,					0, 1, 0);
	camara.PositionCamera(0.f, 0.f, .0f, 0.0f, 0.0f, crender.zcartas, 0, 1, 0);
	camara_backup.PositionCamera(0.f, 0.f, .0f, 0.0f, 0.0f, crender.zcartas, 0,	1, 0);
	frame->ColorPorDefecto="Green";
	// SITUAMOS LOS COLORES POR DEFECTO
	if (frame->ColorPorDefecto==_T("Green")) {
		//	VERDE
		color_base=0;
		color_cas[0]=0.f;
		color_cas[1]=0.95f;
		color_cas[2]=0.f;
		color_fin[0]=0.f;
		color_fin[1]=0.65f;
		color_fin[2]=0.f;
	} else if (frame->ColorPorDefecto==_T("Yellow")) {
		// YELLOW
		color_base=1;
		color_cas[0]=0.95f;
		color_cas[1]=0.95f;
		color_cas[2]=0.f;
		color_fin[0]=0.65f;
		color_fin[1]=0.65f;
		color_fin[2]=0.f;
	} else if (frame->ColorPorDefecto==_T("Cyan")) {
		// CYAN
		color_base=2;
		color_cas[0]=0.f;
		color_cas[1]=0.95f;
		color_cas[2]=0.95f;
		color_fin[0]=0.f;
		color_fin[1]=0.65f;
		color_fin[2]=0.65f;
	} else if (frame->ColorPorDefecto==_T("Magenta")) {
		// MAGENTA
		color_base=3;
		color_cas[0]=0.995f;
		color_cas[1]=0.6f;
		color_cas[2]=0.995f;
		color_fin[0]=0.65f;
		color_fin[1]=0.f;
		color_fin[2]=0.65f;
	}
}
void OpenGLCanvas::restauraGL() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // Reset The Projection Matrix
	gluPerspective(45.0f, (GLfloat)resX/(GLfloat)resY, 0.1f, 100.0f); // Calculate The Aspect Ratio Of The Window
}
void OpenGLCanvas::mov_camara_vacio(float pxfin, float pyfin, float pzfin,
		float vxfin, float vyfin, float vzfin, float factor)
{
	// factor es la velocidad para este tramo de movimiento de la camara
	int v=80;
	bool animacion=true;
	if (velocidad<18)
		velocidad=18; // Para evitar dividir por cero
	else
		v=velocidad;
	//printf("Velocidad es %d\r",v);
	float vf=factor*(float)v;
	int vz=(int)vf;

	float pxini=camara.m_vPosition.x;
	float pyini=camara.m_vPosition.y;
	float pzini=camara.m_vPosition.z;

	float vxini=camara.m_vView.x;
	float vyini=camara.m_vView.y;
	float vzini=camara.m_vView.z;

	float pxdesp=(pxfin-pxini)/(float)vz;
	float pydesp=(pyfin-pyini)/(float)vz;
	float pzdesp=(pzfin-pzini)/(float)vz;

	float vxdesp=(vxfin-vxini)/(float)vz;
	float vydesp=(vyfin-vyini)/(float)vz;
	float vzdesp=(vzfin-vzini)/(float)vz;

	while (animacion) {
		Swap();
		camara.m_vPosition.x+=pxdesp;
		camara.m_vPosition.y+=pydesp;
		camara.m_vPosition.z+=pzdesp;
		camara.m_vView.x+=vxdesp;
		camara.m_vView.y+=vydesp;
		camara.m_vView.z+=vzdesp;
		renderiza_vacio();
		if (contador<vz) {
			contador++;
		} else {
			contador=1;
			animacion=false;
		}
	}
}
void OpenGLCanvas::mov_camara(float pxfin, float pyfin, float pzfin,
		float vxfin, float vyfin, float vzfin, float factor)
{
	// factor es la velocidad para este tramo de movimiento de la camara
	int v=80;
	bool animacion=true;
	if (velocidad<18)
		velocidad=18; // Para evitar dividir por cero
	else
		v=velocidad;
	//printf("Velocidad es %d\r",v);
	float vf=factor*(float)v;
	int vz=(int)vf;

	float pxini=camara.m_vPosition.x;
	float pyini=camara.m_vPosition.y;
	float pzini=camara.m_vPosition.z;

	float vxini=camara.m_vView.x;
	float vyini=camara.m_vView.y;
	float vzini=camara.m_vView.z;

	float pxdesp=(pxfin-pxini)/(float)vz;
	float pydesp=(pyfin-pyini)/(float)vz;
	float pzdesp=(pzfin-pzini)/(float)vz;

	float vxdesp=(vxfin-vxini)/(float)vz;
	float vydesp=(vyfin-vyini)/(float)vz;
	float vzdesp=(vzfin-vzini)/(float)vz;

	while (animacion) {
		Swap();
		camara.m_vPosition.x+=pxdesp;
		camara.m_vPosition.y+=pydesp;
		camara.m_vPosition.z+=pzdesp;
		camara.m_vView.x+=vxdesp;
		camara.m_vView.y+=vydesp;
		camara.m_vView.z+=vzdesp;
		renderiza(GL_RENDER);
		if (contador<vz) {
			contador++;
		} else {
			contador=1;
			animacion=false;
		}
	}
}
void OpenGLCanvas::recorrido_out() {
	// wxMilliSleep(500);
	// A LA CAMARA DE REPARTO
	mov_camara( juego->posX0, juego->posY0, juego->posZ0,
				juego->viewX0,juego->viewY0, juego->viewZ0,2.f);
}
void OpenGLCanvas::recorrido_in() {
	srand((unsigned)time(NULL));
	int sorteo= rand() % 4;
	//fprintf(stderr,"sorteo: %d\n",sorteo);
	if(sorteo == 0){
		camara.m_vPosition.x = -0.34655973f;
		camara.m_vPosition.y = 0.31800011f;
		camara.m_vPosition.z = -1.16811860f;
		camara.m_vView.x = -0.34655973f;
		camara.m_vView.y = 0.74400079f;
		camara.m_vView.z = -2.30811858f;
	}
	if(sorteo == 1){
		camara.m_vPosition.x = 0.84498727f;
		camara.m_vPosition.y = -1.10151279f;
		camara.m_vPosition.z = -1.14405560f;
		camara.m_vView.x = 1.27740264f;
		camara.m_vView.y = 0.02000000f;
		camara.m_vView.z = -1.33455789f;
	}
	if(sorteo == 2){
		camara.m_vPosition.x = 0.01063490f; 
		camara.m_vPosition.y = -0.02517513f; 
		camara.m_vPosition.z = -2.33109784f; 
		camara.m_vView.x = 0.01063490f; 
		camara.m_vView.y = 0.00400000f; 
		camara.m_vView.z = -1.11447704f; 
	}

	// A LA CAMARA NORMAL
	mov_camara_vacio( juego->posX, juego->posY, juego->posZ,
					  juego->viewX,juego->viewY, juego->viewZ,2.f);
	
	camara.m_vPosition.x = juego->posX;
	camara.m_vPosition.y = juego->posY;
	camara.m_vPosition.z = juego->posZ;
	camara.m_vView.x = juego->viewX;
	camara.m_vView.y = juego->viewY;
	camara.m_vView.z = juego->viewZ;
	
	winOptions->Check(ID_CAMARA_STANDARD, false);
	winOptions->Check(ID_CAMARA_MAIN, true);
	
}
void OpenGLCanvas::recorrido() {
	// wxMilliSleep(500);
	// A LA CAMARA DE REPARTO
	mov_camara( juego->posX0, juego->posY0, juego->posZ0,
				juego->viewX0,juego->viewY0, juego->viewZ0,2.f);
	
	srand((unsigned)time(NULL));
	int sorteo= rand() % 4;
	//fprintf(stderr,"sorteo: %d\n",sorteo);
	if(sorteo == 0){
		camara.m_vPosition.x = -0.34655973f;
		camara.m_vPosition.y = 0.31800011f;
		camara.m_vPosition.z = -1.16811860f;
		camara.m_vView.x = -0.34655973f;
		camara.m_vView.y = 0.74400079f;
		camara.m_vView.z = -2.30811858f;
	}
	if(sorteo == 1){
		camara.m_vPosition.x = 0.84498727f;
		camara.m_vPosition.y = -1.10151279f;
		camara.m_vPosition.z = -1.14405560f;
		camara.m_vView.x = 1.27740264f;
		camara.m_vView.y = 0.02000000f;
		camara.m_vView.z = -1.33455789f;
	}
	if(sorteo == 2){
		camara.m_vPosition.x = 0.01063490f; 
		camara.m_vPosition.y = -0.02517513f; 
		camara.m_vPosition.z = -2.33109784f; 
		camara.m_vView.x = 0.01063490f; 
		camara.m_vView.y = 0.00400000f; 
		camara.m_vView.z = -1.11447704f; 
	}
	// A LA CAMARA NORMAL
	mov_camara_vacio(camara_backup.m_vPosition.x,
					 camara_backup.m_vPosition.y,
					 camara_backup.m_vPosition.z,
					 camara_backup.m_vView.x,
					 camara_backup.m_vView.y,
					 camara_backup.m_vView.z,2.0f);
}
void OpenGLCanvas::OnKeyDown(wxKeyEvent& event){
	// MANEJA LAS TECLAS PARA EL MOVIMIENTO DE LA CAMARA
	long evkey = event.GetKeyCode();
	m_Key = evkey;
	if (m_Key == m_rleft) {
		camara.StrafeCamera(0.004f);
	} else if (m_Key == m_rright) {
		camara.StrafeCamera(-0.004f);
	} else if (m_Key == m_home) {
		camara.RotateAroundPoint(-0.004f, 0.f, 0.f);
	} else if (m_Key == m_end) {
		camara.RotateAroundPoint(0.004f, 0.f, 0.f);
	} else if (m_Key == m_up) {
		camara.raiseCameraY(0.004f);
	} else if (m_Key == m_down) {
		camara.raiseCameraY(-0.004f);
	} else if (m_Key == m_insert) {
		camara.RotateAroundPoint(0.f, 0.f, 0.004f);
	} else if (m_Key == m_del) {
		camara.RotateAroundPoint(0.f, 0.f, -0.004f);
	} else if (m_Key == m_avpag) {
		camara.MoveCameraXZ(-0.004f);
	} else if (m_Key == m_repag) {
		camara.MoveCameraXZ(0.004f);
	} else if (m_Key == m_NUMPAD1) {
		camara.MoveCameraYZ(-0.004f);
	} else if (m_Key == m_NUMPAD2) {
		camara.MoveCameraYZ(0.004f);
	} else if (m_Key == m_NUMPAD3) {
		camara.MoveCameraXY(-0.004f);
	} else if (m_Key == m_NUMPAD4) {
		camara.MoveCameraXY(0.004f);
	} else if (m_Key == m_F1) {
		//recorrido();
		if(tipo_juego>0)	frame->AyudaGameHTML();
	} else if (m_Key == m_F5) {
		camara.RotateAroundPoint(0.f, 0.004f, 0.f);
	} else if (m_Key == m_F6) {
		camara.RotateAroundPoint(0.f, -0.004f, 0.f);
	} else if (m_Key == m_F7) {
		camara.raiseCameraX(0.004f);
	} else if (m_Key == m_F8) {
		camara.raiseCameraX(-0.004f);
	} else if (m_Key == m_F2) {
		camara.raiseCameraZ(0.004f);
	} else if (m_Key == m_F3) {
		camara.raiseCameraZ(-0.004f);
	} else if (m_Key == m_NUMPAD5) {
		// Realiza una impresion en consola de las coordenadas de los tres points
		sprintf(buffer2, "pos.setPos (%8.8ff,%8.8ff,%8.8ff);\r",
				camara.m_vPosition.x, camara.m_vPosition.y,
				camara.m_vPosition.z);
		fprintf(stderr,"%s\n",buffer2);
		sprintf(buffer2, "view.setPos(%8.8ff,%8.8ff,%8.8ff);\r",
				camara.m_vView.x, camara.m_vView.y, camara.m_vView.z);
		fprintf(stderr,"%s\n",buffer2);
		sprintf(buffer2, "Vector: %8.8ff,%8.8ff,%8.8ff\r",
				camara.m_vUpVector.x, camara.m_vUpVector.y,
				camara.m_vUpVector.z);
		fprintf(stderr,"%s\n",buffer2);
	}
#if TEST
	else if (m_Key == m_escape) {
		//FINAL FORZOSO
		juego->cartas_colocadas = juego->mazo_juego;
	}
#endif
	winOptions->Check(ID_CAMARA_STANDARD, false);winOptions->Check(ID_CAMARA_MAIN, false);
	camara_backup=camara;
	event.Skip();
}
void OpenGLCanvas::OnKeyUp(wxKeyEvent& event) {
	m_Key = 0;
	event.Skip();
}
// EVENTOS PRINCIPALES PARA EL MENU
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(wxID_EXIT, MyFrame::OnExit)
EVT_MENU(wxID_HELP,MyFrame::OnAboutHTML)
EVT_MENU(ID_HELP,MyFrame::OnHelpGameHTML)
EVT_MENU(wxID_NEW, MyFrame::OnNewGame)
EVT_MENU(ID_RESTART_GAME, MyFrame::OnRestartGame)
EVT_MENU(ID_SELECT_POPULAR_CANFIELD, MyFrame::OnCanfield)
EVT_MENU(ID_SELECT_POPULAR_DOUBLES, MyFrame::OnDoubles)
EVT_MENU(ID_SELECT_POPULAR_FORTYTHIEVES, MyFrame::OnFortyThieves)
EVT_MENU(ID_SELECT_POPULAR_FREECELL, MyFrame::OnFreecell)
EVT_MENU(ID_SELECT_POPULAR_GOLF, MyFrame::OnGolf)
EVT_MENU(ID_SELECT_POPULAR_KLONDIKE, MyFrame::OnKlondike)
EVT_MENU(ID_SELECT_POPULAR_SPIDER, MyFrame::OnSpider)
EVT_MENU(ID_TIP, MyFrame::ShowTip)
EVT_MENU(ID_LICENSE, MyFrame::ShowLicense)
EVT_MENU(ID_BACKGROUND, MyFrame::SelectBackgroundColor)
EVT_MENU(ID_CAMARA_STANDARD, MyFrame::CamaraStandard)
EVT_MENU(ID_FRAMERATE, MyFrame::FrameRateNumericEntry)
EVT_MENU(ID_CAMARA_MAIN, MyFrame::CamaraMain)
EVT_MENU(wxID_OPEN, MyFrame::MuestraArbolJuegos)
EVT_MENU(ID_ESTADISTICAS, MyFrame::Estadisticas)
EVT_MENU(ID_BEST_TIMES, MyFrame::MejoresTiempos)
EVT_MENU(ID_SOUND, MyFrame::OnActivarSonido)
EVT_MENU(ID_ZOOMIN, MyFrame::Zoomin)
EVT_MENU(ID_ZOOMOUT, MyFrame::Zoomout)
EVT_MENU(wxID_COPY, MyFrame::Automaticos)
EVT_MENU(ID_SELECT_NUMBER_GAME, MyFrame::NumericEntry)
EVT_MENU(ID_UNDOALL, MyFrame::OnUndoAll)
EVT_MENU(ID_REDOALL, MyFrame::OnRedoAll)
EVT_MENU(wxID_UNDO, MyFrame::OnUndo)
EVT_MENU(wxID_REDO, MyFrame::OnRedo)
EVT_MENU(ID_NEWDECK, MyFrame::OnNewDeck)
EVT_MENU(ID_OLDDECK, MyFrame::OnOldDeck)
EVT_MENU(ID_FUNDECK, MyFrame::OnFunDeck)
EVT_MENU(ID_RETRODECK, MyFrame::OnRetroDeck)
EVT_MENU(ID_IMAGEBLUE, MyFrame::OnImageBlue)
EVT_MENU(ID_IMAGEGREEN, MyFrame::OnImageGreen)
EVT_MENU(ID_IMAGEYELLOW, MyFrame::OnImageYellow)
EVT_MENU(ID_IMAGECUSTOM, MyFrame::OnImageOpen)
EVT_MENU(ID_IMAGECLASSIC, MyFrame::OnImageClassic)
END_EVENT_TABLE()

// ARRANQUE DE LA APLICACION
MyFrame::MyFrame(wxWindow *parent, const wxString& title, const wxPoint& pos,
		const wxSize& size, long style)
: wxFrame(parent, wxID_ANY, title, pos, size, style) {
	config = new wxConfig("bigsol");
	if ( config->Read("MostrarTipos", &TiposAlArrancar) ) {}
	if ( config->Read("Color", &ColorPorDefecto) ) {
	} else {
		ColorPorDefecto="Green";
	}
	for(int i=0;i<40;i++) {
		BestTime[i]=new wxString(_T("--:--:--"));
		sprintf(buffer,"BestTimes%d",i);
		if ( config->Read(buffer, BestTime[i]) ) {
		} else {
		}
		BestJugador[i]=new wxString(_T("-"));
		sprintf(buffer,"BestJugador%d",i);
		if ( config->Read(buffer, BestJugador[i]) ) {
		} else {
		}
		BestNumber[i]=new wxString(_T("-"));
		sprintf(buffer,"BestNumber%d",i);
		if ( config->Read(buffer, BestNumber[i]) ) {
		} else {

		}
	}
	swGeneral.Start(0);
	m_playerDialog=0;
	//wxString name = wxTheApp->GetAppName();
	//if (name.Length() <= 0) name = _T("bigsol");
	wxString name=_T("bigsol");
	m_scoreFile = new ScoreFile(name);
	//SetCursor(* m_handCursor);
	//SetCursor(* m_arrowCursor);
	m_canvas = NULL;
	m_tbar = NULL;
	m_smallToolbar = true;
	m_horzText = false;
	m_useCustomDisabled = false;
	m_showTooltips = true;
	Centre(wxHORIZONTAL);
	// Crea una status bar con 6 subdivisiones 
	wxStatusBar *st=CreateStatusBar(6);
	// Si ponemos -1 cogerá el resto de la barra
	int anchos[6]= {300,100,80,100,120,-1};
	int estilos[6]= {wxSB_NORMAL,wxSB_FLAT,wxSB_FLAT,wxSB_FLAT,wxSB_FLAT,wxSB_FLAT};
	st->SetStatusWidths(6, anchos);
	st->SetStatusStyles(6, estilos);
	SetIcon(wxIcon("Data/1/icon1.ico"));
	m_toolbarPosition = TOOLBAR_TOP;
	// Create the toolbar
	RecreateToolbar();
	
	// Inicializamos MIKMOD
	/*
	MikMod_RegisterAllDrivers();
	MikMod_RegisterAllLoaders();
	md_mode |= DMODE_SOFT_MUSIC;
	if (MikMod_Init("")) {
		fprintf(stderr, "Could not initialize sound, reason: %s\n",
		MikMod_strerror(MikMod_errno));
		//return 1;
	}

	module = Player_Load("mods/nosmokin.xm", 26, 0);
	if (module) {
		// start module
		Player_Start(module);
	}
	*/
	
	// Inicializamos BASSMOD
	/*
	if (!BASSMOD_Init(-1,44100,0)) fprintf(stderr,"Can't initialize device\r\n");
	char *mu[]={"Data/sounds/nosmokin.xm","Data/sounds/obsess.xm"};
	if (!BASSMOD_MusicLoad(FALSE,mu[1],0,0,BASS_MUSIC_LOOP|BASS_MUSIC_RAMPS|BASS_MUSIC_SURROUND|BASS_MUSIC_CALCLEN)){
		fprintf(stderr,"Can't play the file\r\n");
	}else{
		fprintf(stdout,"Tocando \"%s\" [%d orders]\r\n",BASSMOD_MusicGetName(),(int)BASSMOD_MusicGetLength(FALSE));
	}
	if(!BASSMOD_SetVolume(25)){
	    	fprintf(stderr,"No puedo ajustar el volumen\r\n");
	}
	BASSMOD_MusicPlay();
	*/
}
#if USE_GENERIC_TBAR
wxToolBar* MyFrame::OnCreateToolBar(long style,wxWindowID id,const wxString& name) {
	return (wxToolBar *)new wxToolBarSimple(this,id,wxDefaultPosition,wxDefaultSize,style,name);
}
#endif // USE_GENERIC_TBAR
void MyFrame::Zoomin(wxCommandEvent& WXUNUSED(event)) {
	//camara.MoveCamera(0.006f);
	//camara_backup=camara;
	//winOptions->Check(ID_CAMARA_STANDARD, false);
	//winOptions->Check(ID_CAMARA_MAIN, false);
}
// La entrada numerica para regualr el Frame Rate
void MyFrame::FrameRateNumericEntry(wxCommandEvent& WXUNUSED(event)) {
	long fr=(long)frame_rate;
	long res = wxGetNumberFromUser(
				_T("If you set the frame rate too high\nthe use of CPU could to up so much"),
				_T("Frame rate [24-300] "), _T("Set the max. frame rate"),fr,24,300,this);
	if (res == -1) {
	} else {
		//if (res == 0)	res = frame_rate;
		//if (res > 300)	res=300;
		frame_rate = (int)res;
	}
}
void MyFrame::OnActivarSonido(wxCommandEvent& WXUNUSED(event)) {
	activar_sonido=!activar_sonido;
}
void MyFrame::Zoomout(wxCommandEvent& WXUNUSED(event)) {
	//camara.MoveCamera(-0.006f);
	//camara_backup=camara;
	//winOptions->Check(ID_CAMARA_STANDARD, false);
	//winOptions->Check(ID_CAMARA_MAIN, false);
}
void MyFrame::OnImageOpen(wxCommandEvent& event){
    wxFileDialog dialog(
                    this,
                    _T("Select the file to load. PNG only"),
                    wxEmptyString,
                    wxEmptyString,
                    _T("PNG files (*.png)|*.PNG"));
    dialog.CentreOnParent();
    dialog.SetDirectory(wxGetHomeDir());
    if (dialog.ShowModal() == wxID_OK){
    	/*
        wxString info;
        info.Printf(_T("Full file name: %s\n")
                    _T("Path: %s\n")
                    _T("Name: %s"),
                    dialog.GetPath().c_str(),
                    dialog.GetDirectory().c_str(),
                    dialog.GetFilename().c_str());
        */
    	sprintf(buffer2, "%s", dialog.GetPath().c_str());
    	//if(fondo != NULL) {	
    	//	delete fondo; 
    	//	fondo= new GLuint;
    	//}
    	//fondo= LoadPointerGLTextures(buffer2);
    	fondoPNG=LoadPNG(buffer2);
    	fondo=&(fondoPNG->id);
        //wxMessageDialog dialog2(this, info, _T("Selected file"));
        //dialog2.ShowModal();
    	winMenuImage->Check(ID_IMAGEGREEN, false);
    	winMenuImage->Check(ID_IMAGEYELLOW, false);
    	winMenuImage->Check(ID_IMAGEBLUE, false);
    	winMenuImage->Check(ID_IMAGECLASSIC, false);
    	
    	winMenuImage->Enable(ID_IMAGEBLUE, true);
    	winMenuImage->Enable(ID_IMAGEGREEN, true);
    	winMenuImage->Enable(ID_IMAGEYELLOW, true);
    	winMenuImage->Enable(ID_IMAGECLASSIC, true);
    	
    	fondo_color=false;
    }
}
void MyFrame::OnImageClassic(wxCommandEvent& event){
	winMenuImage->Check(ID_IMAGEGREEN, false);
	winMenuImage->Check(ID_IMAGEYELLOW, false);
	winMenuImage->Check(ID_IMAGEBLUE, false);
	
	winMenuImage->Enable(ID_IMAGEBLUE, true);
	winMenuImage->Enable(ID_IMAGEGREEN, true);
	winMenuImage->Enable(ID_IMAGEYELLOW, true);
	winMenuImage->Enable(ID_IMAGECLASSIC, false);
	
	color_base=0;
	color_cas[0]=0.f;color_cas[1]=0.95f;color_cas[2]=0.f;
	color_fin[0]=0.f;color_fin[1]=0.65f;color_fin[2]=0.f;
	ColorPorDefecto="Green";
	fondo_color=true;
}
void MyFrame::OnImageBlue(wxCommandEvent& event){
	//if(fondo != NULL) {
	//	delete fondo;
	//	fondo= new GLuint;
	//}
	fondoPNG=LoadPNG("Data/1/fondo.png");
	fondo=&(fondoPNG->id);
	winMenuImage->Check(ID_IMAGEGREEN, false);
	winMenuImage->Check(ID_IMAGEYELLOW, false);
	winMenuImage->Check(ID_IMAGECLASSIC, false);
	
	winMenuImage->Enable(ID_IMAGEBLUE, false);
	winMenuImage->Enable(ID_IMAGEGREEN, true);
	winMenuImage->Enable(ID_IMAGEYELLOW, true);
	winMenuImage->Enable(ID_IMAGECLASSIC, true);
	
	color_base=2;
	color_cas[0]=0.f;color_cas[1]=0.95f;color_cas[2]=0.95f;
	color_fin[0]=0.f;color_fin[1]=0.65f;color_fin[2]=0.65f;
	ColorPorDefecto="Cyan";
	fondo_color=false;
}
void MyFrame::OnImageGreen(wxCommandEvent& event){
	//if(fondo != NULL) {
	//	delete fondo;
	//	fondo= new GLuint;
	//}
	fondoPNG=LoadPNG("Data/1/fondoverde.png");
	fondo=&(fondoPNG->id);
	winMenuImage->Check(ID_IMAGEBLUE, false);
	winMenuImage->Check(ID_IMAGEYELLOW, false);
	winMenuImage->Check(ID_IMAGECLASSIC, false);
	
	winMenuImage->Enable(ID_IMAGEBLUE, true);
	winMenuImage->Enable(ID_IMAGEGREEN, false);
	winMenuImage->Enable(ID_IMAGEYELLOW, true);
	winMenuImage->Enable(ID_IMAGECLASSIC, true);
	
	color_base=0;
	color_cas[0]=0.f;color_cas[1]=0.95f;color_cas[2]=0.f;
	color_fin[0]=0.f;color_fin[1]=0.65f;color_fin[2]=0.f;
	ColorPorDefecto="Green";
	fondo_color=false;
}
void MyFrame::OnImageYellow(wxCommandEvent& event){
	//LoadTGA(&fondoTGA,"Data/1/fondoamarillo.tga");
	fondoPNG=LoadPNG("Data/1/fondoamarillo.png");
	fondo=&(fondoPNG->id);
	winMenuImage->Check(ID_IMAGEGREEN, false);
	winMenuImage->Check(ID_IMAGEBLUE, false);
	winMenuImage->Check(ID_IMAGECLASSIC, false);
	
	winMenuImage->Enable(ID_IMAGEBLUE, true);
	winMenuImage->Enable(ID_IMAGEGREEN, true);
	winMenuImage->Enable(ID_IMAGEYELLOW, false);
	winMenuImage->Enable(ID_IMAGECLASSIC, true);
	
	color_base=1;
	color_cas[0]=0.95f;color_cas[1]=0.95f;color_cas[2]=0.f;
	color_fin[0]=0.65f;color_fin[1]=0.65f;color_fin[2]=0.f;
	ColorPorDefecto="Yellow";
	fondo_color=false;
}
void MyFrame::OnNewDeck(wxCommandEvent& event){
	for(int a=1;a<53;a++){
//		textura[a]='\0';
		textura[a]=deckStandard[a];
		//textura[a]=&(deckStandard[a]->texID);
	}
	textura[0]=background;
	winMenuDeck->Check(ID_OLDDECK, false);
	winMenuDeck->Check(ID_FUNDECK, false);
	winMenuDeck->Check(ID_RETRODECK, false);
	
	winMenuDeck->Enable(ID_OLDDECK, true);
	winMenuDeck->Enable(ID_NEWDECK, false);
	winMenuDeck->Enable(ID_FUNDECK, true);
	winMenuDeck->Enable(ID_RETRODECK, true);
}
void MyFrame::OnOldDeck(wxCommandEvent& event){
	for(int a=1;a<53;a++){
//		textura[a]='\0';
		textura[a]=deckOld[a];
	}
	textura[0]=background;
	winMenuDeck->Check(ID_NEWDECK, false);
	winMenuDeck->Check(ID_FUNDECK, false);
	winMenuDeck->Check(ID_RETRODECK, false);
	
	winMenuDeck->Enable(ID_OLDDECK, false);
	winMenuDeck->Enable(ID_NEWDECK, true);
	winMenuDeck->Enable(ID_FUNDECK, true);
	winMenuDeck->Enable(ID_RETRODECK, true);
}
void MyFrame::OnFunDeck(wxCommandEvent& event){
	for(int a=1;a<53;a++){
		//textura[a]='\0';
		textura[a]=&(deckFun[a]->id);
	}
	textura[0]=&(deckFun[0]->id);
	
	winMenuDeck->Check(ID_NEWDECK, false);
	winMenuDeck->Check(ID_OLDDECK, false);
	winMenuDeck->Check(ID_RETRODECK, false);
	
	winMenuDeck->Enable(ID_OLDDECK, true);
	winMenuDeck->Enable(ID_NEWDECK, true);
	winMenuDeck->Enable(ID_FUNDECK, false);
	winMenuDeck->Enable(ID_RETRODECK, true);
}
void MyFrame::OnRetroDeck(wxCommandEvent& event){
	for(int a=1;a<53;a++){
//		textura[a]='\0';
		textura[a]=&(deckRetro[a]->texID);
	}
	textura[0]=&(deckRetro[0]->texID);
	
	winMenuDeck->Check(ID_NEWDECK, false);
	winMenuDeck->Check(ID_OLDDECK, false);
	winMenuDeck->Check(ID_FUNDECK, false);
	
	winMenuDeck->Enable(ID_OLDDECK, true);
	winMenuDeck->Enable(ID_NEWDECK, true);
	winMenuDeck->Enable(ID_FUNDECK, true);
	winMenuDeck->Enable(ID_RETRODECK, false);
}
void MyFrame::OnExit(wxCommandEvent& WXUNUSED(event)) {
	// Liberamos Bassmod
	//BASSMOD_Free();
	/*
	if (module) {
		Player_Stop();
		Player_Free(module);
	}
	*/
	// Computamos estadistica y salimos
	if (hemos_arrancado==true)
		computar_estadistica_perdida();
	if (arbolJuegos) {
		arbolJuegos->Destroy();
	}
	config->Write("MostrarTipos", TiposAlArrancar);
	config->Write("Color", ColorPorDefecto);

	for (int i=0; i<40; i++) {
		sprintf(buffer, "BestTimes%d", i);
		config->Write(buffer, *BestTime[i]);
		sprintf(buffer, "BestJugador%d", i);
		config->Write(buffer, *BestJugador[i]);
		sprintf(buffer, "BestNumber%d", i);
		config->Write(buffer, *BestNumber[i]);
	}
	if (m_canvas)
		delete m_canvas;
	if (config)
		delete config;
	if (m_scoreFile)
		delete m_scoreFile;
	delete juego;
	juego=NULL;
	for(int a=1;a<53;a++){
		//if(deckOld[a] != NULL)	delete deckOld[a];
		glDeleteTextures(1, deckOld[a]);
		glDeleteTextures(1, deckStandard[a]);
	}
	for(int a=1;a<90;a++){
		//if(textura[a])	delete textura[a];
		glDeleteTextures(1, textura[a]);
	}
	glDeleteTextures (1, fondo);
	for(int a=0;a<53;a++){
		free(deckFun[a]->texels);
		free(deckFun[a]);
	}
	for(int a=0;a<53;a++){
		free(deckRetro[a]->imageData);
		free(deckRetro[a]);
		//free(deckStandard[a]->imageData);
		//free(deckStandard[a]);
	}
	free(fondoPNG->texels);
	free(fondoPNG);
	Close(true);
}
void MyFrame::Automaticos(wxCommandEvent& e) {
	if (!juego->esperar && juego->automatico_permitido) {
		juego->juego_automatico=!juego->juego_automatico;
		if (juego->juego_automatico) {
			toolBar->ToggleTool(wxID_COPY, true);
			winMenuAuto->Check(wxID_COPY, true);
		} else {
			toolBar->ToggleTool(wxID_COPY, false);
			winMenuAuto->Check(wxID_COPY, false);
		}
		is_auto_checked=toolBar->GetToolState(wxID_COPY ); // Da si esta chequeado o no
		toolBar->Realize();
	}
}
void MyFrame::CamaraMain(wxCommandEvent& WXUNUSED(event)) {
	/*
	winOptions->Check(ID_CAMARA_STANDARD, false);
	winOptions->Check(ID_CAMARA_MAIN, true);
	m_canvas->mov_camara(juego->posX, juego->posY, juego->posZ,juego->viewX, juego->viewY, juego->viewZ,2.0f);
	camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
			juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
			juego->vectorY, juego->vectorZ);
	guardar_camara();
	*/
	if( winOptions->IsChecked(ID_CAMARA_MAIN) == true){
		winOptions->Check(ID_CAMARA_STANDARD, false);
		winOptions->Check(ID_CAMARA_MAIN, true);
		m_canvas->mov_camara(juego->posX, juego->posY, juego->posZ,juego->viewX, juego->viewY, juego->viewZ,2.0f);
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
							  juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
							  juego->vectorY, juego->vectorZ);
		guardar_camara();
	}else{
		winOptions->Check(ID_CAMARA_STANDARD, false);
		winOptions->Check(ID_CAMARA_MAIN, true);
	}
}
void MyFrame::CamaraStandard(wxCommandEvent& WXUNUSED(event)) {
	/*
	winOptions->Check(ID_CAMARA_STANDARD, true);
	winOptions->Check(ID_CAMARA_MAIN, false);
	m_canvas->mov_camara(0.0f,0.0f,0.1f,0.0f,0.0f,crender.zcartas,2.0f);
	camara.m_vPosition.x=0.0f;
	camara.m_vPosition.y=0.0f;
	camara.m_vPosition.z=0.1f;
	camara.m_vView.x=0.0f;
	camara.m_vView.y=0.0f;
	camara.m_vView.z=crender.zcartas;
	camara.m_vUpVector.x=.0f;
	camara.m_vUpVector.y=1.0f;
	camara.m_vUpVector.z=.0f;
	guardar_camara();
	*/
	if( winOptions->IsChecked(ID_CAMARA_STANDARD) == true){
		winOptions->Check(ID_CAMARA_STANDARD, true);
		winOptions->Check(ID_CAMARA_MAIN, false);
		m_canvas->mov_camara(0.0f,0.0f,0.1f,0.0f,0.0f,crender.zcartas,2.0f);
		camara.m_vPosition.x=0.0f;
		camara.m_vPosition.y=0.0f;
		camara.m_vPosition.z=0.1f;
		camara.m_vView.x=0.0f;
		camara.m_vView.y=0.0f;
		camara.m_vView.z=crender.zcartas;
		camara.m_vUpVector.x=.0f;
		camara.m_vUpVector.y=1.0f;
		camara.m_vUpVector.z=.0f;
		guardar_camara();
	}else{
		winOptions->Check(ID_CAMARA_STANDARD, true);
		winOptions->Check(ID_CAMARA_MAIN, false);
	}
}
void MyFrame::ShowLicense(wxCommandEvent& event) {
	LicenseHTML dialog(this, wxID_ANY, wxT("License"));
	if (dialog.ShowModal() == wxID_OK) {
	}
}
void MyFrame::OnAboutHTML(wxCommandEvent& event) {
	BigAbouHTML dialog(this, wxID_ANY, wxT("Big Solitaires 3D"));
	if (dialog.ShowModal() == wxID_OK) {
	}
}
void MyFrame::OnHelpGameHTML(wxCommandEvent& event) {
	sprintf(buffer2, "%s Help", jocs[tipo_juego-7000].nombre);
	HelpGameHTML dialog(this, wxID_ANY, buffer2);
	if (dialog.ShowModal() == wxID_OK) {
	}
}
void MyFrame::AyudaGameHTML() {
	sprintf(buffer2, "%s Help", jocs[tipo_juego-7000].nombre);
	HelpGameHTML dialog(this, wxID_ANY, buffer2);
	if (dialog.ShowModal() == wxID_OK) {
	}
}
void MyFrame::ShowTip(wxCommandEvent& WXUNUSED(event)) {
	static size_t s_index = (size_t)-1;
	if (s_index == (size_t)-1) {
		srand(time(NULL));
		// this is completely bogus, we don't know how many lines are there
		// in the file, but who cares, it's a demo only...
		s_index = rand() % 5;
	}
	wxTipProvider *tipProvider = wxCreateFileTipProvider(_T("Data/help/tips.txt"),
			s_index);
	bool showAtStartup = wxShowTip(this, tipProvider);
	if (showAtStartup ) {
		TiposAlArrancar="yes";
		// wxMessageBox(_T("Will show tips on startup"), _T("Tips dialog"), wxOK | wxICON_INFORMATION, this);
	} else {
		TiposAlArrancar="not";
	}
	s_index = tipProvider->GetCurrentTip();
	delete tipProvider;
}
void MyFrame::MostrarTip() {
	static size_t s_index = (size_t)-1;
	if (s_index == (size_t)-1) {
		srand(time(NULL));
		// this is completely bogus, we don't know how many lines are there
		// in the file, but who cares, it's a demo only...
		s_index = rand() % 5;
	}
	wxTipProvider *tipProvider = wxCreateFileTipProvider(_T("Data/help/tips.txt"),
			s_index);
	bool showAtStartup = wxShowTip(this, tipProvider);
	if (showAtStartup ) {
		TiposAlArrancar="yes";
		//        wxMessageBox(_T("Will show tips on startup"), _T("Tips dialog"), wxOK | wxICON_INFORMATION, this);
	} else {
		TiposAlArrancar="not";
	}
	s_index = tipProvider->GetCurrentTip();
	delete tipProvider;
}
void MyFrame::SelectBackgroundColor(wxCommandEvent& WXUNUSED(event)) {
	ColoresDialog *cd=new ColoresDialog(this);
	wxString color;
	if (int res=cd->ShowModal()) {
		if(res==wxID_OK) {
			color=cd->m_color;
			if( color==_T("Green")) { //VERDE
				color_base=0;
				color_cas[0]=0.f;color_cas[1]=0.95f;color_cas[2]=0.f;
				color_fin[0]=0.f;color_fin[1]=0.65f;color_fin[2]=0.f;
				ColorPorDefecto="Green";
			} else if(color==_T("Yellow")) { // YELLOW
				color_base=1;
				color_cas[0]=0.95f;color_cas[1]=0.95f;color_cas[2]=0.f;
				color_fin[0]=0.65f;color_fin[1]=0.65f;color_fin[2]=0.f;
				ColorPorDefecto="Yellow";
			} else if(color==_T("Cyan")) { // CYAN
				color_base=2;
				color_cas[0]=0.f;color_cas[1]=0.95f;color_cas[2]=0.95f;
				color_fin[0]=0.f;color_fin[1]=0.65f;color_fin[2]=0.65f;
				ColorPorDefecto="Cyan";
			} else if(color==_T("Magenta")) { // MAGENTA
				color_base=3;
				color_cas[0]=0.85f;color_cas[1]=0.f;color_cas[2]=0.85f;
				color_fin[0]=0.65f;color_fin[1]=0.f;color_fin[2]=0.65f;
				ColorPorDefecto="Magenta";
				// RGB 232,31,24
				/*
				 color_fin[0]=(float)232/255;
				 color_fin[1]=(float)31/255;
				 color_fin[2]=(float)24/255;
				 color_cas[0]=0.99f;	color_cas[1]=0.99f;	color_cas[2]=0.99f;
				 */
			}
		}
		cd->Destroy();
	}
}
void MyFrame::MuestraArbolJuegos(wxCommandEvent& WXUNUSED(event)) {
	if (!arbolJuegos) {
		arbolJuegos = new DialogoArbol(this);
	}
	int resultado=arbolJuegos->ShowModal();
	arbolJuegos->m_treeCtrl->seleccionado=NULL;
	arbolJuegos->finalizado=false;
	if (hemos_arrancado==true) {
		computar_estadistica_perdida();
	} else {
		hemos_arrancado=true;
	}
	if (resultado!=wxID_CANCEL) {
		tipo_juego=resultado;
		hubo_seleccion=true;
		EstableceJuego(true);
	}
}
void MyFrame::MuestraJuegos() {
	tipo_juego=CANFIELD;
	if (!arbolJuegos) {
		arbolJuegos = new DialogoArbol(this);
	}
	int resultado=0;
	resultado=arbolJuegos->ShowModal();
	if (resultado > 6999) {
		if (hemos_arrancado==true) {
			computar_estadistica_perdida();
		} else {
			hemos_arrancado=true;
		}
		arbolJuegos->m_treeCtrl->seleccionado=NULL;
		arbolJuegos->finalizado=false;
		tipo_juego=resultado;
		hubo_seleccion=true;
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity(); // Reset The Projection Matrix
		gluPerspective(45.0f, (GLfloat)resX/(GLfloat)resY, 0.1f, 100.0f); // Calculate The Aspect Ratio Of The Window
		color_fin[1]=0.6f;
		zfondo=-1.21f;
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		camara.m_vPosition.x=0.0f;
		camara.m_vPosition.y=-0.45f;
		camara.m_vPosition.z=-0.06f;
		camara.m_vView.x=0.0f;
		camara.m_vView.y=-0.024f;
		camara.m_vView.z=crender.zcartas;
		camara.m_vUpVector.x=0.0f;
		camara.m_vUpVector.y=1.0f;
		camara.m_vUpVector.z=0.0f;
		guardar_camara();
		EstableceJuego(false);
	} else {
		arbolJuegos->Destroy();
		delete m_scoreFile;
		delete juego;
		Close(true);
	}
}
void MyFrame::MostrarJugadores() {
	// if player name not set (and selection dialog is not displayed)
	// then ask the player for their name
	if (jugador.Length() == 0&& !m_playerDialog) {
		m_playerDialog = new PlayerSelectionDialog(this, m_scoreFile);
		m_playerDialog->ShowModal();
		jugador = m_playerDialog->GetPlayersName();
		if (jugador.Length() > 0) {
			// user entered a name - lookup their score
			m_scoreFile->Lee(jugador);
			m_playerDialog->Destroy();
			m_playerDialog = 0;
			hemos_seleccionado_jugador=true;
			for (int j=0; j<40; j++) {
				total_juegos[j] =(int)frame->m_scoreFile->myGames[j];
				juegos_ganados[j]=(int)frame->m_scoreFile->myWins[j];
			}
		} else {
			// user cancelled the dialog - exit the app
			//((wxFrame*)GetParent())->Close(true);
			delete juego;
			delete m_scoreFile;
			Close(true);
		}
	}
}
void MyFrame::Estadisticas(wxCommandEvent& WXUNUSED(event)) {
	m_estadisticas = new ScoreDialog(this, total_juegos,juegos_ganados,jugador);
	m_estadisticas->ShowModal();
	m_estadisticas->Destroy();
}
void MyFrame::MejoresTiempos(wxCommandEvent& WXUNUSED(event)) {
	BestTimesDialog *m_bestTimes = new BestTimesDialog(this, this->BestTime, this->BestJugador,this->BestNumber);
	m_bestTimes->ShowModal();
	m_bestTimes->Destroy();
}
void MyFrame::EstableceJuego(bool cam) {
	hubo_seleccion=true;
	if(cam==true)m_canvas->recorrido_out();
	if (tipo_juego==G2) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new ladrones40_2;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==CORONA) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new corona;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==G40Y8) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new ladrones40y8;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==G3) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new game;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==G4) {
		ConstruirCaja(0, 0.04f, 0.06f);
		ConstruirCaja(1, 0.05f, 0.075f);
		ConstruirCaja(6, 0.03f, 0.045f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new ladrones40_4;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==IX) {
		ConstruirCaja(0, 0.04f, 0.06f);
		ConstruirCaja(1, 0.05f, 0.075f);
		ConstruirCaja(6, 0.03f, 0.045f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new z_four;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==GOLF) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new golf;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==GOLF_AK) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new golf_ak;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==GOLF_AK2) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new golf_ak2;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==CANFIELD) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new canfield;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==CANFIELD2) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new canfield2;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==CANFIELD_SUP) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new canfield_sup;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==DOUBLES) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new montecarlo;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==DOUBLES13) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new montecarlo13;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==MONTANA) {
		ConstruirCaja(0, 0.048f, 0.072f);
		ConstruirCaja(1, 0.0555f, 0.08325f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new montana;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==KLONDIKE) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new klondike;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==KLONDIKE3) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new klondike;
		juego->tipo_juego=KLONDIKE3;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==KLONDIKE2) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete(juego);
		juego=new klondike2;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==INDIAN) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new indian;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==EASTHAVEN) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new easthaven;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==FREECELL) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new freecell;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==FREECELL2) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new freecell2;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==EMPEROR) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new emperor;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==OCEANS) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new oceans;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==TOWERS) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new towers;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==SCORPION) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new scorpion;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==SCARAB) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new scarab;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==SIMPLESIMON) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new simplesimon;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==SPIDER) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new spider;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==SPIDERETTE) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new spiderette;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==SPIDERETTER) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new spideretter;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==SPIDER2) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new spider2;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==SPIDER1) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new spider1;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==SPIDER3) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new spider3;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==YUKON) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new yukon;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==YUKON_NK) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new yukon_nk;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==LUCKY) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new lucky;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==RAIL1) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new rail1;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==RAIL2) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new rail2;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==RUSSIAN) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new russian;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	} else if (tipo_juego==RUSSIAN_NK) {
		ConstruirCaja(0, 0.05f, 0.075f);
		ConstruirCaja(1, 0.0575f, 0.08625f);
		ConstruirCaja(6, 0.04f, 0.06f);
		respuesta=false;
		opcion=NADA;
		if (hubo_seleccion) {
			srand(time(NULL));
			hubo_seleccion=false;
		}
		delete juego;
		juego=new russian_nk;
		if(cam==true) m_canvas->recorrido_in();
		camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
				juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
				juego->vectorY, juego->vectorZ);
		guardar_camara();
		juego->barajar(0);
		chequea_automaticos();
	}
	sprintf(buffer2, "%s number %u", jocs[tipo_juego-7000].nombre,juego->numero_juego);
	frame->SetStatusText(buffer2);
}
void MyFrame::NumericEntry(wxCommandEvent& WXUNUSED(event)) {
	/*
	 long res = wxGetNumberFromUser(_T(""),
	 _T("Enter the number:"),
	 _T("Select number game"),
	 1,juego->numero_juego,2147483647, this);
	 */
	sprintf(buffer2, "%u", juego->numero_juego);
	wxTextEntryDialog dialog(this, _T("Enter number game [1-1073676289]"),
			_T("Select number game"), buffer2, wxOK | wxCANCEL);

	if (dialog.ShowModal() == wxID_OK) {
		wxString svalor=dialog.GetValue();
		long res;
		bool resultado=svalor.ToLong(&res, 10);
		if (resultado && res > 0 && res <= 1073676289) {
			computar_estadistica_perdida();
			hubo_seleccion=true;
			juego->repetir_juego();
			juego->barajar(res);
			chequea_automaticos();
			juego->numero_juego=res;
			sprintf(buffer2, "%s number %u", jocs[tipo_juego-7000].nombre,juego->numero_juego);
			SetStatusText(buffer2);
		} else {
			// Mostramos mensaje de error
			wxMessageBox(_T("Value not valid"), _T(""), wxOK
					| wxICON_EXCLAMATION, this);
		}
	}
}
void MyFrame::OnCanfield(wxCommandEvent& event) {
	computar_estadistica_perdida();
	if (tipo_juego!=CANFIELD)
		juego->cambio_de_juego=true;
	tipo_juego=CANFIELD;
	ConstruirCaja(0, 0.05f, 0.075f);
	ConstruirCaja(1, 0.0575f, 0.08625f);
	ConstruirCaja(6, 0.04f, 0.06f);
	respuesta=false;
	opcion=NADA;
	if (hubo_seleccion) {
		srand(time(NULL));
		hubo_seleccion=false;
	}
	delete juego;
	juego=new canfield;
	camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
			juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
			juego->vectorY, juego->vectorZ);
	guardar_camara();
	juego->barajar(0);
	chequea_automaticos();
	sprintf(buffer2, "%s number %u", jocs[tipo_juego-7000].nombre,juego->numero_juego);
	SetStatusText(buffer2);
}
void MyFrame::OnDoubles(wxCommandEvent& event) {
	computar_estadistica_perdida();
	if (tipo_juego!=DOUBLES)
		juego->cambio_de_juego=true;
	tipo_juego=DOUBLES;
	ConstruirCaja(0, 0.05f, 0.075f);
	ConstruirCaja(1, 0.0575f, 0.08625f);
	ConstruirCaja(6, 0.04f, 0.06f);
	respuesta=false;
	opcion=NADA;
	if (hubo_seleccion) {
		srand((unsigned)time(NULL));
		hubo_seleccion=false;
	}
	delete juego;
	juego=new montecarlo;
	camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
			juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
			juego->vectorY, juego->vectorZ);
	guardar_camara();
	juego->barajar(0);
	chequea_automaticos();
	sprintf(buffer2, "%s number %u", jocs[tipo_juego-7000].nombre,juego->numero_juego);
	SetStatusText(buffer2);
}
void MyFrame::OnFortyThieves(wxCommandEvent& event) {
	computar_estadistica_perdida();
	if (tipo_juego!=G2)
		juego->cambio_de_juego=true;
	tipo_juego=G2;
	opcion=G2;
	ConstruirCaja(0, 0.05f, 0.075f);
	ConstruirCaja(1, 0.0575f, 0.08625f);
	ConstruirCaja(6, 0.04f, 0.06f);
	respuesta=false;
	opcion=NADA;
	if (hubo_seleccion) {
		srand((unsigned)time(NULL));
		hubo_seleccion=false;
	}
	delete juego;
	juego=new ladrones40_2;
	camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
			juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
			juego->vectorY, juego->vectorZ);
	guardar_camara();
	juego->barajar(0);
	chequea_automaticos();
	sprintf(buffer2, "%s number %u", jocs[tipo_juego-7000].nombre,juego->numero_juego);
	SetStatusText(buffer2);
}
void MyFrame::OnFreecell(wxCommandEvent& event) {
	computar_estadistica_perdida();
	if (tipo_juego!=FREECELL)
		juego->cambio_de_juego=true;
	tipo_juego=FREECELL;
	ConstruirCaja(0, 0.05f, 0.075f);
	ConstruirCaja(1, 0.0575f, 0.08625f);
	ConstruirCaja(6, 0.04f, 0.06f);
	respuesta=false;
	opcion=NADA;
	if (hubo_seleccion) {
		srand(time(NULL));
		hubo_seleccion=false;
	}
	delete juego;
	juego=new freecell;
	camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
			juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
			juego->vectorY, juego->vectorZ);
	guardar_camara();
	juego->barajar(0);
	chequea_automaticos();
	sprintf(buffer2, "%s number %u", jocs[tipo_juego-7000].nombre,juego->numero_juego);
	SetStatusText(buffer2);
}
void MyFrame::OnGolf(wxCommandEvent& event) {
	computar_estadistica_perdida();
	if (tipo_juego!=GOLF)
		juego->cambio_de_juego=true;
	tipo_juego=GOLF;
	ConstruirCaja(0, 0.05f, 0.075f);
	ConstruirCaja(1, 0.0575f, 0.08625f);
	ConstruirCaja(6, 0.04f, 0.06f);
	respuesta=false;
	opcion=NADA;
	if (hubo_seleccion) {
		srand(time(NULL));
		hubo_seleccion=false;
	}
	delete juego;
	juego=new golf;
	camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
			juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
			juego->vectorY, juego->vectorZ);
	guardar_camara();
	juego->barajar(0);
	chequea_automaticos();
	sprintf(buffer2, "%s number %u", jocs[tipo_juego-7000].nombre,juego->numero_juego);
	SetStatusText(buffer2);
}
void MyFrame::OnKlondike(wxCommandEvent& event) {
	computar_estadistica_perdida();
	if (tipo_juego!=KLONDIKE)
		juego->cambio_de_juego=true;
	tipo_juego=KLONDIKE;
	ConstruirCaja(0, 0.05f, 0.075f);
	ConstruirCaja(1, 0.0575f, 0.08625f);
	ConstruirCaja(6, 0.04f, 0.06f);
	respuesta=false;
	opcion=NADA;
	if (hubo_seleccion) {
		srand((unsigned)time(NULL));
		hubo_seleccion=false;
	}
	delete juego;
	juego=new klondike;
	camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
			juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
			juego->vectorY, juego->vectorZ);
	guardar_camara();
	juego->barajar(0);
	chequea_automaticos();
	sprintf(buffer2, "%s number %u", jocs[tipo_juego-7000].nombre,juego->numero_juego);
	SetStatusText(buffer2);
}
void MyFrame::OnSpider(wxCommandEvent& event) {
	//m_canvas->recorrido_out();
	computar_estadistica_perdida();
	if (tipo_juego!=SPIDER)
		juego->cambio_de_juego=true;
	tipo_juego=SPIDER;
	ConstruirCaja(0, 0.05f, 0.075f);
	ConstruirCaja(1, 0.0575f, 0.08625f);
	ConstruirCaja(6, 0.04f, 0.06f);
	respuesta=false;
	opcion=NADA;
	if (hubo_seleccion) {
		srand((unsigned)time(NULL));
		hubo_seleccion=false;
	}
	delete juego;
	juego=new spider;
	//m_canvas->recorrido_in();
	camara.PositionCamera(juego->posX, juego->posY, juego->posZ,
			juego->viewX, juego->viewY, juego->viewZ, juego->vectorX,
			juego->vectorY, juego->vectorZ);
	guardar_camara();
	juego->barajar(0);
	chequea_automaticos();
	sprintf(buffer2, "%s number %u", jocs[tipo_juego-7000].nombre,juego->numero_juego);
	SetStatusText(buffer2);
}
void MyFrame::OnRestartGame(wxCommandEvent& event) {
	//JUEGO REINICIADO
	opcion=NADA;
	//restaurar_camara();
	computar_estadistica_perdida();
	if (hubo_seleccion) {
		srand((unsigned)time(NULL));
		hubo_seleccion=false;
	}
	juego->repetir_juego();
	juego->barajar(juego->numero_juego);
	chequea_automaticos();
	sprintf(buffer2, "%s number %u", jocs[tipo_juego-7000].nombre,juego->numero_juego);
	SetStatusText(buffer2);
}
void MyFrame::OnNewGame(wxCommandEvent& event) {
	//JUEGO NUEVO
	m_canvas->recorrido();
	opcion=NADA;
	//restaurar_camara();
	computar_estadistica_perdida();
	if (hubo_seleccion) {
		srand((unsigned)time(NULL));
		hubo_seleccion=false;
	}
	juego->repetir_juego();
	juego->barajar(0);
	//sprintf(buffer2,"%s number %u",jocs[tipo_juego-7000].nombre,juego->numero_juego);
	chequea_automaticos();
	sprintf(buffer2, "%s number %u", jocs[tipo_juego-7000].nombre,
			juego->numero_juego);
	SetStatusText(buffer2);
}
void MyFrame::OnUndo(wxCommandEvent& event) {
	if (juego->carta_seleccionada==NOCARTA&& !juego->hemos_acabado) {
		//if(juego->deshacer() && juego->juego_automatico) {juego->esperar=true;juego->juego_automatico=false;}
		if (juego->deshacer()) { // && juego->juego_automatico) {
			juego->esperar=true;
			juego->juego_automatico=false;
			winMenuAuto->Enable(wxID_REDO, true);
			winMenuAuto->Enable(ID_REDOALL, true);
			toolBar->EnableTool(wxID_REDO, true);
			restablece_automaticos();
		}
		if (juego->actual_mov->ant_mov==NULL) {
			// ESTAMOS EN PRIMER MOVIMIENTO. IMPOSIBLE DESHACER DE NUEVO
			winMenuAuto->Enable(wxID_UNDO, false);
			winMenuAuto->Enable(ID_UNDOALL, false);
			toolBar->EnableTool(wxID_UNDO, false);
		}
	}
	toolBar->Realize();
}
void MyFrame::OnRedo(wxCommandEvent& event) {
	if (juego->carta_seleccionada==NOCARTA&& !juego->hemos_acabado) {
		//if(juego->rehacer()  && juego->juego_automatico) {juego->esperar=true;juego->juego_automatico=false;}
		if (juego->rehacer() && juego->juego_automatico) {
			juego->esperar=true;
			juego->juego_automatico=false;
		}
		winMenuAuto->Enable(wxID_UNDO, true);
		winMenuAuto->Enable(ID_UNDOALL, true);
		toolBar->EnableTool(wxID_UNDO, true);
		if (juego->actual_mov->sig_mov==NULL) {
			winMenuAuto->Enable(wxID_REDO, false);
			winMenuAuto->Enable(ID_REDOALL,false);
			toolBar->EnableTool(wxID_REDO, false);
		}
	}
	toolBar->Realize();
}
void MyFrame::OnUndoAll(wxCommandEvent& event) {
	if (juego->carta_seleccionada==NOCARTA&& !juego->hemos_acabado) {
		while (juego->deshacer()) {
		}// && juego->juego_automatico);
		juego->esperar=true;
		juego->juego_automatico=false;
	}
	winMenuAuto->Enable(ID_REDOALL, true);
	winMenuAuto->Enable(wxID_REDO, true);
	toolBar->EnableTool(wxID_REDO, true);
	winMenuAuto->Enable(ID_UNDOALL, false);
	winMenuAuto->Enable(wxID_UNDO, false);
	toolBar->EnableTool(wxID_UNDO, false);
	toolBar->Realize();
}
void MyFrame::OnRedoAll(wxCommandEvent& event) {
	if (juego->carta_seleccionada==NOCARTA&& !juego->hemos_acabado) {
		while (juego->rehacer()) {
		}
		//juego->juego_automatico) {juego->esperar=true;juego->juego_automatico=false;}
	}
	winMenuAuto->Enable(ID_REDOALL, false);
	winMenuAuto->Enable(wxID_REDO, false);
	toolBar->EnableTool(wxID_REDO, false);
	winMenuAuto->Enable(ID_UNDOALL, true);
	winMenuAuto->Enable(wxID_UNDO, true);
	toolBar->EnableTool(wxID_UNDO, true);
	toolBar->Realize();
}

/*static*/MyFrame *MyFrame::Create(MyFrame *parentFrame, bool isCloneWindow) {
	wxString str = wxT("Big Solitaires 3D");
	//if (isCloneWindow)	str += wxT(" - Clone");
	frame = new MyFrame(NULL, str, wxDefaultPosition,wxSize(resX, resY));
	//frame->SetMaxSize(frame->GetMaxSize());
	// Make a menubar
	winMenuFile = new wxMenu;
	winMenuFile->Append(wxID_NEW, _T("&New Game"), _T("Start a new game"));
	winMenuFile->Enable(wxID_NEW, false);
	winMenuFile->Append(ID_RESTART_GAME,_T("&Restart Game"),_T("Restart current game"));
	winMenuFile->Enable(ID_RESTART_GAME, false);
	winMenuFile->Append(ID_SELECT_NUMBER_GAME,_T("&Select Number Game"),_T("Start a game with number selection"));
	winMenuFile->Enable(ID_SELECT_NUMBER_GAME, false);
	winMenuFile->AppendSeparator();
	winMenuFile->Append(ID_ESTADISTICAS,_T("S&tatistics"),_T("View player statistics"));
	winMenuFile->Enable(ID_ESTADISTICAS, false);
	winMenuFile->Append(ID_BEST_TIMES,_T("&Best times"),_T(""));
	winMenuFile->Enable(ID_BEST_TIMES, false);
	winMenuFile->AppendSeparator();
	winMenuFile->Append(wxID_EXIT, _T("&Quit"));

	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(winMenuFile, _T("&Game"));

	winMenuOpen = new wxMenu();
	wxMenuItem* menuItem3 = new wxMenuItem( winMenuOpen, wxID_OPEN, wxString( wxT("&Open Game") ) , _T("Open list of games"), wxITEM_NORMAL );
	winMenuOpen->Append(menuItem3 );
	winMenuOpen->Enable(wxID_OPEN, false);

	winMenuOpen->AppendSeparator();
	wxMenu* m_menu3;
	m_menu3 = new wxMenu();
	wxMenuItem* menuItem5 = new wxMenuItem( m_menu3, ID_SELECT_POPULAR_CANFIELD, wxString( wxT("   &Canfield") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append(menuItem5 );
	//m_menu3->Enable(ID_NEW, false);
	wxMenuItem* menuItem6 = new wxMenuItem( m_menu3, ID_SELECT_POPULAR_DOUBLES, wxString( wxT("   &Doubles") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append(menuItem6 );
	wxMenuItem* menuItem7 = new wxMenuItem( m_menu3, ID_SELECT_POPULAR_FORTYTHIEVES, wxString( wxT("   Forty &Thieves          ") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append(menuItem7 );
	wxMenuItem* menuItem8 = new wxMenuItem( m_menu3, ID_SELECT_POPULAR_FREECELL, wxString( wxT("   &Freecell") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append(menuItem8 );
	wxMenuItem* menuItem9 = new wxMenuItem( m_menu3, ID_SELECT_POPULAR_GOLF, wxString( wxT("   &Golf") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append(menuItem9 );
	wxMenuItem* menuItem10 = new wxMenuItem( m_menu3, ID_SELECT_POPULAR_KLONDIKE, wxString( wxT("   &Klondike") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append(menuItem10 );
	wxMenuItem* menuItem11 = new wxMenuItem( m_menu3, ID_SELECT_POPULAR_SPIDER, wxString( wxT("   &Spider") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append(menuItem11 );
	winMenuOpen->Append( ID_POPULAR, wxT("&Popular"), m_menu3);
	menuBar->Append(winMenuOpen, wxT("&Select") );
	winMenuOpen->Enable(ID_POPULAR, false);

	winMenuAuto = new wxMenu;
	winMenuAuto->Append(wxID_UNDO, _T("&Undo"),	_T("Undo last move    Wheel back"));
	winMenuAuto->Enable(wxID_UNDO, false);
	winMenuAuto->Append(wxID_REDO, _T("&Redo"),	_T("Redo move         Wheel forward"));
	winMenuAuto->Enable(wxID_REDO, false);
	winMenuAuto->Append(ID_UNDOALL,_T("U&ndo All"),_T("Undo all moves"));
	winMenuAuto->Enable(ID_UNDOALL, false);
	winMenuAuto->Append(ID_REDOALL,_T("R&edo All"),_T("Redo all moves"));
	winMenuAuto->Enable(ID_REDOALL, false);
	winMenuAuto->AppendSeparator();
	winMenuAuto->AppendCheckItem(wxID_COPY, _T("&Automatic"),_T("Set Automatic On/Off"));
	menuBar->Append(winMenuAuto, _T("&Edit"));

	winOptions = new wxMenu;

	winMenuCamara = new wxMenu();
	wxMenuItem* menuCstandar = new wxMenuItem( winMenuCamara, ID_CAMARA_STANDARD, wxString( wxT("   &Standard view") ) , _T("Camera in style 2D"), wxITEM_CHECK );
	winMenuCamara->Append(menuCstandar);
	wxMenuItem* menuCmain = new wxMenuItem( winMenuCamara, ID_CAMARA_MAIN, wxString( wxT("   &MainView") ) , _T("Reset the camera"), wxITEM_CHECK );
	winMenuCamara->Append(menuCmain);
	winOptions->Append( ID_CAMARA, wxT("&Camera"), winMenuCamara);
	winOptions->Enable(ID_CAMARA, false);
	winOptions->AppendSeparator();
	winOptions->AppendCheckItem(ID_SOUND,_T("&Sound"),_T("Set sound On/Off"));
	winOptions->Check(ID_SOUND, true);
	winOptions->Append(ID_FRAMERATE,_T("&Frame rate"),_T("Set the maximum frame rate"));
	winOptions->AppendSeparator();
	winMenuDeck = new wxMenu();	
	wxMenuItem* menuOldDeck = new wxMenuItem( winMenuDeck, ID_OLDDECK, wxString( wxT("   &Old deck") ) , _T("Old Deck"), wxITEM_CHECK );
	winMenuDeck->Append(menuOldDeck);
	wxMenuItem* menuNewDeck = new wxMenuItem( winMenuDeck, ID_NEWDECK, wxString( wxT("   &Standard deck") ) , _T("Standard Deck"), wxITEM_CHECK );
	winMenuDeck->Append(menuNewDeck);
	wxMenuItem* menuFunDeck = new wxMenuItem( winMenuDeck, ID_FUNDECK, wxString( wxT("   &Fun deck") ) , _T("Fun Deck"), wxITEM_CHECK );
	winMenuDeck->Append(menuFunDeck);
	wxMenuItem* menuRetroDeck = new wxMenuItem( winMenuDeck, ID_RETRODECK, wxString( wxT("   &Retro deck") ) , _T("Retro Deck"), wxITEM_CHECK );
	winMenuDeck->Append(menuRetroDeck);
	winOptions->Append( ID_DECK, wxT("&Decks"), winMenuDeck );
	winMenuDeck->Check(ID_NEWDECK, true);
	winMenuDeck->Enable(ID_NEWDECK, false);
	
	winMenuImage = new wxMenu();	
	wxMenuItem* menuImageClassic = new wxMenuItem( winMenuImage, ID_IMAGECLASSIC, wxString( wxT("   Cla&ssic background") ) , _T("Classic background"), wxITEM_CHECK );
	winMenuImage->Append(menuImageClassic);	
	wxMenuItem* menuImageBlue = new wxMenuItem( winMenuImage, ID_IMAGEBLUE, wxString( wxT("   &Blue image") ) , _T("Blue image"), wxITEM_CHECK );
	winMenuImage->Append(menuImageBlue);
	wxMenuItem* menuImageGreen = new wxMenuItem( winMenuImage, ID_IMAGEGREEN, wxString( wxT("   &Green image") ) , _T("Green image"), wxITEM_CHECK );
	winMenuImage->Append(menuImageGreen);
	wxMenuItem* menuImageYellow = new wxMenuItem( winMenuImage, ID_IMAGEYELLOW, wxString( wxT("   &Yellow image") ) , _T("Yellow image"), wxITEM_CHECK );
	winMenuImage->Append(menuImageYellow);
	winMenuImage->AppendSeparator();
	wxMenuItem* menuImageCustom = new wxMenuItem( winMenuImage, ID_IMAGECUSTOM, wxString( wxT("&Custom image (PNG only)") ) , _T("Load image"), wxITEM_NORMAL );
	winMenuImage->Append(menuImageCustom);
	
	winOptions->Append( ID_IMAGE, wxT("&Backgrounds"), winMenuImage );
	winMenuImage->Check(ID_IMAGEGREEN, true);
	winMenuImage->Enable(ID_IMAGEGREEN, false);
	winOptions->Append(ID_BACKGROUND,_T("C&ell color  "),_T("Choose color for cells"));	
	menuBar->Append(winOptions, _T("&Options"));

	winMenuHelp = new wxMenu;
	winMenuHelp->Append(ID_HELP,_T("&Help game"),_T("Show help about current game"));
	winMenuHelp->Enable(ID_HELP, false);
	winMenuHelp->Append(ID_TIP,_T("&Tip of the day"),_T("Show tip of the day"));
	winMenuHelp->AppendSeparator();
	winMenuHelp->Append(ID_LICENSE,_T("&License"),_T(""));
	winMenuHelp->Append(wxID_HELP, _T("&About"), _T(""));
	menuBar->Append(winMenuHelp, _T("&Help"));
	frame->SetMenuBar(menuBar);
	//frame->CreateStatusBar();
	//if (parentFrame){
	//    frame->m_canvas = new OpenGLCanvas( frame, parentFrame->m_canvas,wxID_ANY, wxDefaultPosition, wxDefaultSize );
	//}
	//else{
	frame->m_canvas = new OpenGLCanvas(frame, wxID_ANY,wxDefaultPosition, wxDefaultSize);
	//}
	// Show the frame
	//frame->ShowFullScreen(TRUE);
	frame->Show(TRUE);
	return frame;
}
void MyFrame::OnNewWindow(wxCommandEvent& WXUNUSED(event)) {
	(void) Create(this, true);
}
// ******* //
// TOOLBAR //
// ******* //
void MyFrame::RecreateToolbar(){
    // delete and recreate the toolbar
    //wxToolBarBase *toolBar = GetToolBar();
    toolBar = GetToolBar();
    long style = toolBar ? toolBar->GetWindowStyle() : TOOLBAR_STYLE;
    delete toolBar;
    SetToolBar(NULL);
	// long style = GetToolBar()->GetWindowStyle();
    style &= ~(wxTB_NOICONS | wxTB_TEXT);
    toolBar = CreateToolBar(style, ID_TOOLBAR);
    // Set up toolbar
    enum {
        Tool_new,
        Tool_open,
        Tool_copy,
        Tool_undo,
        Tool_redo,
        Tool_quit,
        Tool_tutorial,
        Tool_Max
    };
    wxBitmap toolBarBitmaps[Tool_Max];
    
#if USE_XPM_BITMAPS
    #define INIT_TOOL_BMP(bmp) \
        toolBarBitmaps[Tool_##bmp] = wxBitmap(bmp##_xpm)
#else // !USE_XPM_BITMAPS
    #define INIT_TOOL_BMP(bmp) \
        toolBarBitmaps[Tool_##bmp] = wxBITMAP(bmp)
#endif // USE_XPM_BITMAPS/!USE_XPM_BITMAPS

    INIT_TOOL_BMP(new);
    INIT_TOOL_BMP(open);
    INIT_TOOL_BMP(copy);
    INIT_TOOL_BMP(undo);
    INIT_TOOL_BMP(redo);
    INIT_TOOL_BMP(quit);
    INIT_TOOL_BMP(tutorial);
    int w = toolBarBitmaps[Tool_undo].GetWidth(),
        h = toolBarBitmaps[Tool_undo].GetHeight();
    if ( !m_smallToolbar ){
        w *= 2;h *= 2;
        for ( size_t n = Tool_undo; n < WXSIZEOF(toolBarBitmaps); n++ ){
            toolBarBitmaps[n] = wxBitmap(toolBarBitmaps[n].ConvertToImage().Scale(w, h));
        }
    }
    toolBar->SetToolBitmapSize(wxSize(w, h));
    toolBar->AddTool(wxID_NEW, _T("New"),   toolBarBitmaps[Tool_new], wxNullBitmap, wxITEM_NORMAL,_T("New game"),_T("Start a new game"));
    toolBar->AddTool(wxID_OPEN, _T("Open"), toolBarBitmaps[Tool_open], wxNullBitmap, wxITEM_NORMAL, _T("Select game"), _T("Select a card game"));
    toolBar->AddTool(wxID_COPY, _T("Copy"), toolBarBitmaps[Tool_copy], _T("Automatic on/off"), wxITEM_CHECK);
    toolBar->AddSeparator();
    toolBar->AddTool(wxID_UNDO, _T("Undo"), toolBarBitmaps[Tool_undo], _T("Undo"), wxITEM_NORMAL);
    toolBar->AddTool(wxID_REDO, _T("Redo"), toolBarBitmaps[Tool_redo], _T("Redo"), wxITEM_NORMAL);
    toolBar->AddSeparator();
	toolBar->AddTool(ID_HELP, _T("Help"), toolBarBitmaps[Tool_tutorial], _T("Help game"), wxITEM_NORMAL);
	toolBar->AddSeparator();
    toolBar->AddTool(wxID_EXIT, _T("Quit"), toolBarBitmaps[Tool_quit], _T("Quit"), wxITEM_NORMAL);
    toolBar->EnableTool( wxID_NEW, false );
    toolBar->EnableTool( wxID_OPEN, false );
    toolBar->EnableTool( wxID_UNDO, false );
    toolBar->EnableTool( wxID_REDO, false );
    toolBar->EnableTool( ID_HELP, false );
    toolBar->Realize();
//	toolBar->SetRows(!(toolBar->IsVertical()) ? m_rows : 10 / m_rows);
}
// Application object ( equivalent to main() )
IMPLEMENT_APP(BigSol)
bool BigSol::OnInit() {
	// Create the main frame window
	(void) MyFrame::Create(NULL);
	SetAppName(_T("Big Solitaires 3D"));
	return true;
}
