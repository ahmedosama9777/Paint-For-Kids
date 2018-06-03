#ifndef Pick_Action_H
#define Pick_Action_H

#include "Actions\Action.h"
class PickAction :public Action
{
private:
	int  InvalidPicks;
	int  ValidPicks;
	double grade;
	ActionType mode;
	int  r; int  c; int  t; int l;
	int modeId;  Point P1;
	bool toolaction;
	ActionType x;
public:
	PickAction(ApplicationManager *pApp, ActionType x);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif