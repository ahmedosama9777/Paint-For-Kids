#ifndef REDOACTION_H
#define REDOACTION_H
#include "Actions\Action.h"

class RedoAction:public Action
{

public:
	RedoAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};
#endif