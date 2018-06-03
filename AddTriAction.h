#ifndef ADD_TRI_ACTION_H
#define ADD_TRI_ACTION_H
#include "Actions\Action.h"
//Add Triangle Action class
class AddTriAction: public Action
{
private:
	Point P1, P2, P3; //Triangle Corners
	GfxInfo TriGfxInfo;
	bool DRAW;
public:
	AddTriAction(ApplicationManager *pApp);

	//Reads triangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;
	
};
#endif