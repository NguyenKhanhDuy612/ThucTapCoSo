#pragma once
#include <float.h>

const int WINDOW_WIDTH			= 1250;
const int WINDOW_HIGHT			= 650;
const int RADIUS_VALUE 			= 19;
const int DELAY_VALUE			= 2;
const int MAX_INPUT				= 20;
const int MAX_VERTEX			= 30;
const int MAX_NAME_LENGTH		= 4; //include NULL '\0' character
const char VERTEX_NAME_BEGIN[]	= "1";
const char FILE_FILTER[] 		= "Graph File (*.graph)\0*.graph\0All File\0*.*\0";

enum keyCode
{
	KEY_BACKSPACE	= 8,
	KEY_ESC			= 27,
	KEY_ENTER		= 13,
	KEY_NULL		= -1,
	KEY_LQ 			= 113,
	ARROW_KEY		= 0
};

enum menuCode
{
	 PATHXY_MENU,  OPEN_MENU, SAVE_MENU, QUIT_MENU, ADD_VERTEX_MENU,
	ADD_EDGE_MENU, RENAME_VERTEX_MENU, DELETEVE_MENU, MOVEVE_MENU, CLEAN_GRAPH_MENU, HELP_MENU,NUM_OF_MENU
};

enum workingZone
{
	wLEFT	= 355, wbLEFT = 417,
	wTOP	= 20,
	wRIGHT	= WINDOW_WIDTH - 10,
	wBOTTOM	= 500
};

enum menuZone
{
	mLEFT	= 5,
		fLEFT	= 5,
	mTOP	= 20,	fTOP 	= 235,
	mRIGHT	= 340,
		fRIGHT 	= 340,
	mBOTTOM	= 215,
		fBOTTOM = 295
};
enum textZone
{
	tLEFT 	= 355,
	tTOP	= 500 + 10,
	tRIGHT	= WINDOW_WIDTH - 10,
	tBOTTOM	= WINDOW_HIGHT - 10
};
enum cursorXY
{
	xCURSOR 	= 355 + 5,
	yCURSOR		= tTOP + 5,
	TEXTHIGHT 	= 20 //For endl
};
enum adjacencyMatrixZone
{
	aLEFT 			= 5,
	aTOP 			= 315,
	aRIGHT 			= 340,
	aBOTTOM 		= WINDOW_HIGHT - 10,
	ADJUST_TEXT_X 	= aLEFT + 3,
	ADJUST_TEXT_Y 	= 315 + 14,
	aVERTEX_MAX_1	= 13,
	aVERTEX_MAX_2	= 21
};

enum weightValue
{
	DEFAULT_WEIGHT 	= 0,
	MAX_WEIGHT 		= 201,
	MIN_WEIGHT 		= 0
};
enum eulerCode
{
	NOT_EXIST_EULER = -2,
	EXIST_EULER		= -1
};


const double voCung	= MAX_VERTEX * MAX_WEIGHT + 1;
const float	canhRong 	= FLT_MIN; // FLT_MAX

