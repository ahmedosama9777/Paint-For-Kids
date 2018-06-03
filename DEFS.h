#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contais some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_CIRC,		//Draw Circle
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	CHNG_BK_CLR,	//Change background color
	CHNG_BorderWidth,
	Select,
	RESIZE,			//Resize a figure(s)
	Zoom,
	DEL,			//Delete a figure(s)
	MOVE,			//Move a figure(s)
	Copy,
	Cut,
	Paste,
	SAVE,			//Save the whole graph to a file
	LOAD,		//Load a graph from a file
	UNDO,           //undo an action
	REDO,           // redo an action
	EXIT,			//Exit the application

	ROTATE,			//Rotate a figure(s)
	SEND_BACK,		//Send a figure to the back of all figures
	BRNG_FRNT,		//Bring a figure to the front of all figures
	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,			//Switch interface to Play mode
			
	scramble,
	pick,
	Type,
	Fill,
	Type_Fill,
	Area,
	
	
	DIndigo,
	DBlue,
	DYellow,
	DGreen,
	DPink,
	DOrange,
	DRed,
	DViolet,
	DBrown,
	DBlack,

	FIndigo,
	FBlue,
	FYellow,
	FGreen,
	FPink,
	FOrange,
	FRed,
	FViolet,
	FBrown,
	FNo,

	BIndigo,
	BBlue,
	BYellow,
	BGreen,
	BPink,
	BOrange,
	BRed,
	BViolet,
	BBrown,
	BBlack,

	WQuarter,
	WHalf,
	WDouble,
	WQuad,
	
	
	RQuarter,
	RHalf,
	RDouble,
	RQuad,
	EXITZOOM,
};

struct Point	//To be used for figures points
{ 
	Point()
	{
		x=0;
		y=0;
	}
	int x,y; 
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	GfxInfo()
	{
		DrawClr=BLUE;
		FillClr=GREEN;
		isFilled=false;
		BorderWdth=3;
	}
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif