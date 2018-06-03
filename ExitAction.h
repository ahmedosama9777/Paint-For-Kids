#ifndef EXITACTION_H
#define EXITACTION_H
#include"Actions\Action.h"
#include <fstream>
class ExitAction :public Action
{
	bool checkF;
	string s;
	bool checkB;
	ActionType *actType;
public:

	ExitAction(ApplicationManager *pApp, ActionType &act);
	virtual void ReadActionParameters();
	virtual void Execute();

};
#endif