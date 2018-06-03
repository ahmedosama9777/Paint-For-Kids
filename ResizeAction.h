#ifndef RESIZE_ACTION_H
#define RESIZE_ACTION_H

#include "Actions\Action.h"

//Add Circle Action class
class ResizeAction: public Action
{
private:
	ActionType ResizeFactor;
public:
	ResizeAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;
	
};

#endif