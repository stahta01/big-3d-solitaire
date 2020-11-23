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

#ifndef RESOURCE_H_INCLUDED
#define RESOURCE_H_INCLUDED

typedef struct{
	char nombre[26];
	char grado[10];
	char decks[2];
	char ayuda[23];
	} juegos;
	
const juegos jocs[]=
{
	{"Canfield","Very Hard","1","Data/help/can.html"},
	{"Canfield Two Decks","Medium","2","Data/help/can2.html"},
	{"Canfield Superior","Medium","1","Data/help/cansup.html"},
	{"Corona","Hard","2","Data/help/corona.html"},
	{"Doubles","Easy","1","Data/help/dou.html"},
	{"Doubles 13","Easy","1","Data/help/dou13.html"},
	{"Easthaven","Medium","1","Data/help/east.html"},
	{"Emperor","Medium","2","Data/help/emperor.html"},
	{"Forty Thieves","Hard","2","Data/help/forty.html"},
	{"Forty and Eight","Medium","2","Data/help/forty8.html"},
	{"Forty Thieves Three Decks","Very Hard","3","Data/help/forty3.html"},
	{"Forty Thieves Four Decks","Very Hard","4","Data/help/forty4.html"},
	{"FreeCell","Medium","1","Data/help/free.html"},
	{"FreeCell Two Decks","Medium","2","Data/help/free2.html"},
	{"Golf","Easy","1","Data/help/golf.html"},
	{"Golf A-K","Easy","1","Data/help/golfak.html"},
	{"Golf A-K Two Decks","Easy","2","Data/help/golfak2.html"},
	{"Indian","Easy","2","Data/help/indian.html"},
	{"Klondike","Easy","1","Data/help/klon.html"},
	{"Klondike Two Decks","Easy","2","Data/help/klon2.html"},
	{"Lucky Fans","Easy","1","Data/help/fans.html"},
	{"Montana Three Redeals","Hard","1","Data/help/montana.html"},
	{"Ocean's Eleven","Medium","3","Data/help/ocean.html"},
	{"Rail One Deck","Medium","1","Data/help/rail1.html"},
	{"Rail Two Decks","Medium","2","Data/help/rail2.html"},
	{"Russian","Very Hard","1","Data/help/rus.html"},
	{"Russian Relaxed","Hard","1","Data/help/rusr.html"},
	{"Scarab","Medium","2","Data/help/scar.html"},
	{"Scorpion","Very Hard","1","Data/help/scor.html"},
	{"Simple Simon","Hard","1","Data/help/ssimon.html"},
	{"Spider","Very Hard","2","Data/help/sp.html"},
	{"Spider One Suite","Easy","2","Data/help/sp1s.html"},
	{"Spider Two Suites","Medium","2","Data/help/sp2s.html"},
	{"Spider Three Decks","Hard","3","Data/help/sp3d.html"},
	{"Spiderette","Very Hard","1","Data/help/spi.html"},
	{"Spiderette Relaxed","Hard","1","Data/help/spir.html"},
	{"Towers","Hard","1","Data/help/towers.html"},
	{"Yukon","Very Hard","1","Data/help/yukon.html"},
	{"Yukon Relaxed","Hard","1","Data/help/yukonr.html"},
	{"Z-Four","Hard","4","Data/help/zfour.html"},
	{"Klondike","Easy","1","Data/help/klon.html"}
};


#define IDB_CLUB1                       1
#define IDS_DIFICULT                    1
#define IDB_CLUB2                       2
#define IDB_CLUB3                       3
#define IDB_CLUB4                       4
#define IDB_CLUB5                       5
#define IDB_CLUB6                       6
#define IDB_CLUB7                       7
#define IDB_CLUB8                       8
#define IDB_CLUB9                       9
#define IDB_CLUB10                      10
#define IDB_CLUB11                      11
#define IDB_CLUB12                      12
#define IDB_CLUB13                      13
#define IDB_DIAMOND1                    14
#define IDB_DIAMOND2                    15
#define IDB_DIAMOND3                    16
#define IDB_DIAMOND4                    17
#define IDB_DIAMOND5                    18
#define IDB_DIAMOND6                    19
#define IDB_DIAMOND7                    20
#define IDB_DIAMOND8                    21
#define IDB_DIAMOND9                    22
#define IDB_DIAMOND10                   23
#define IDB_DIAMOND11                   24
#define IDB_DIAMOND12                   25
#define IDB_DIAMOND13                   26
#define IDB_HEART1                      27
#define IDB_HEART2                      28
#define IDB_HEART3                      29
#define IDB_HEART4                      30
#define IDB_HEART5                      31
#define IDB_HEART6                      32
#define IDB_HEART7                      33
#define IDB_HEART8                      34
#define IDB_HEART9                      35
#define IDB_HEART10                     36
#define IDB_HEART11                     37
#define IDB_HEART12                     38
#define IDB_HEART13                     39
#define IDB_SPADE1                      40
#define IDB_SPADE2                      41
#define IDB_SPADE3                      42
#define IDB_SPADE4                      43
#define IDB_SPADE5                      44
#define IDB_SPADE6                      45
#define IDB_SPADE7                      46
#define IDB_SPADE8                      47
#define IDB_SPADE9                      48
#define IDB_SPADE10                     49
#define IDB_SPADE11                     50
#define IDB_SPADE12                     51
#define IDB_SPADE13                     52
#define IDB_REVERSO                     200
#define IDI_ICON1                       234
#define IDC_CURSOR1                     239
#define IDB_ICONO                       262
#define IDB_LOGO                        268
#define IDR_MENU1                       276
#define IDD_DIALOG_SELECT               277
#define IDD_DIALOG1                     280
#define IDR_ACCELERATOR1                281
#define IDR_WAVE1                       292
#define IDR_WAVE2                       293
#define IDR_WAVE3                       302
#define IDR_WAVE4                       303
#define ID_DIALOG_SETUP                 304
#define IDD_ABOUT                       308
#define IDD_LICENSE                     309
#define IDD_DIALOG2                     313

#define NUMERO_DE_JUEGOS				40
#define WHEEL_DELTA						120		/* Value for rolling one detent */
#define FALSE							0
#define TRUE 							1
#define ID_RESTART_GAME					1000
#define ID_SELECT_NUMBER_GAME			1001
#define ID_CATEGORY						1002
#define ID_POPULAR						1003
#define ID_UNDOALL						1004
#define ID_REDOALL						1005
#define ID_CAMERA						1006
#define ID_HELP							1007
#define ID_ABOUT_HTML_WINDOW    		1015
#define ID_TIP    						1016
#define ID_CAMARA_STANDARD				1017
#define ID_CAMARA_MAIN					1018
#define ID_CAMARA						1019
#define ID_ESTADISTICAS					1020
#define ID_ZOOMIN						1021
#define ID_ZOOMOUT						1022
#define ID_BACKGROUND					1023
#define ID_SOUND						1024
#define ID_BEST_TIMES					1025

#define ID_DECK							1026
#define ID_OLDDECK						1027
#define ID_NEWDECK						1028
#define ID_FUNDECK						1029
#define ID_RETRODECK					1030

#define ID_IMAGE						1031
#define ID_IMAGEBLUE					1032
#define ID_IMAGEGREEN					1033
#define ID_IMAGEYELLOW					1034
#define ID_IMAGECUSTOM					1035
#define ID_IMAGECLASSIC					1036

#define ID_FRAMERATE					1041

#define IDC_EDIT1                       1042
#define IDC_DECKS                       1043
#define IDC_GAMES                       1044
#define IDC_GRADO                       1046
#define IDC_CHECK1                      1049
#define IDC_CHECK2                      1050
#define IDC_RADIO3                      1052
#define IDC_RADIO4                      1053
#define IDC_RADIO5                      1054
#define IDC_RADIO6                      1055
#define IDC_RADIO7                      1056
#define IDC_RADIO8                      1057
#define IDC_LIST2                       1058
#define IDC_CHECK3                      1060
#define IDC_AYUDA                       1064
#define IDC_STATIC1                     1068
#define ID_JUEGO_NEW                    						4000
#define ID_JUEGO_RESTART                						4001
#define ID_JUEGO_SELECT                 						4002
#define ID_JUEGO_OPEN                   						4003
#define ID_JUEGO_EXIT                   						4004
#define ID_SELECT_POPULAR_KLONDIKE      						4005
#define ID_SELECT_POPULAR_FREECELL      						4006
#define ID_SELECT_POPULAR_CANFIELD      						4007
#define ID_SELECT_POPULAR_SPIDER        						4008
#define ID_SELECT_POPULAR_FORTYTHIEVES  						4009
#define ID_SELECT_CATEGORY_FREECELL_FREECELL 					4010
#define ID_SELECT_CATEGORY_FREECELL_FREECELLTWODECKS 			4011
#define ID_SELECT_CATEGORY_FREECELL_TOWERS 						4012
#define ID_SELECT_CATEGORY_FORTYTHIEVES_FORTYTHIEVES 			4013
#define ID_SELECT_CATEGORY_FORTYTHIEVES_FORTYTHIEVESTHREEDECKS 	4014
#define ID_SELECT_CATEGORY_FORTYTHIEVES_FORTYTHIEVESFOURDECKS 	4015
#define ID_SELECT_CATEGORY_SPIDER_SPIDER 						4016
#define ID_SELECT_CATEGORY_SPIDER_SPIDERONESUITE 				4017
#define ID_SELECT_CATEGORY_SPIDER_SPIDERTWOSUITES 				4018
#define ID_SELECT_CATEGORY_SPIDER_SIMPLESIMON 					4019
#define ID_SELECT_CATEGORY_SPIDER_SCARAB 						4020
#define ID_SELECT_CATEGORY_GOLF_GOLF    						4021
#define ID_SELECT_CATEGORY_GOLF_GOLFAK  						4022
#define ID_SELECT_CATEGORY_GOLF_GOLFAKTWODECKS 					4023
#define ID_SELECT_CATEGORY_MONTANA_MONTANA 						4024
#define ID_SELECT_CATEGORY_KLONDIKE_KLONDIKE 					4025
#define ID_SELECT_CATEGORY_KLONDIKE_KLONDIKETWODECKS 			4026
#define ID_SELECT_CATEGORY_KLONDIKE_CANFIELD 					4027
#define ID_SELECT_CATEGORY_DOUBLES_DOUBLES 						4028
#define ID_SELECT_CATEGORY_DOUBLES_DOUBLES13 					4029
#define ID_SELECT_POPULAR_DOUBLES       						4030
#define ID_SELECT_POPULAR_GOLF          						4031
#define ID_EDIT_UNDOWHEELBACK           						4032
#define ID_EDIT_REDOWHEELFORWARD        						4033
#define ID_EDIT_UNDOALL                 						4034
#define ID_EDIT_REDOALL                 						4035
#define ID_AUTOMATIC                    						4036
#define ID_CAMERA_RESETVIEW             						4037
#define ID_CAMERA_FINALIZACION          						4038
#define ID_CAMERA_VIEW2                 						4039
#define ID_SETTINGS                     						4040
#define ID_HELP_ABOUT                   						4041
#define ID_SELECT_CHALLENGE             						4042
#define ID_TOOLBAR                      						4043
#define ID_STATUS                       						4044
#define ID_LICENSE                      						4045

#endif
