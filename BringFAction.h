
#ifndef BringF_Action_H
#define BringF_Action_H
#include"Actions\Action.h"

class BringFAction :public Action
{
private:
	Point P1;
public:
	BringFAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};
#endif