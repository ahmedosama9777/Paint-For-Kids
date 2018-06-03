#ifndef Change_Border_ACTION_H
#define Change_Border_ACTION_H

#include "Actions\Action.h"

//Add Circle Action class
class ChangeWidthAction: public Action
{
private:
	ActionType WidthFactor;
public:
	ChangeWidthAction(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;
	
};
#endif