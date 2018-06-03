#ifndef ADD_CIRC_ACTION_H
#define ADD_CIRC_ACTION_H

#include "Actions\Action.h"

//Add Circle Action class
class AddCircleAction: public Action
{
private:
	Point P1,P2;
	int Radius;
	GfxInfo CircGfxInfo;
	bool DRAW;
public:
	AddCircleAction(ApplicationManager *pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	
	//Add rectangle to the ApplicationManager
	virtual void Execute() ;
	
};

#endif