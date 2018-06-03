#ifndef SendB_Action_H
#define SendB_Action_H
#include"Actions\Action.h"

class SendBAction :public Action
{
private:
	Point P1;
public:
	SendBAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};
#endif