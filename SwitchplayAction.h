#ifndef Switchplay_Action_H
#define Switchplay_Action_H

#include "Actions\Action.h"
class SwitchplayAction :public Action
{
private:
	int  r; int  c; int  t; int l;
public:
	SwitchplayAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif