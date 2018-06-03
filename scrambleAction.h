#ifndef Scramble_Action_H
#define Scramble_Action_H

#include "Actions\Action.h"
class ScrambleAction :public Action
{
private:
	int  InvalidPicks;
	int  ValidPicks;
	double grade;
	bool*selectlist;
	bool toolaction;
	ActionType x;


public:
	ScrambleAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif