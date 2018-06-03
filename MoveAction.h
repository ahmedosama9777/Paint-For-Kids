#ifndef Move_Action_H
#define Move_Action_H
#include"Actions\Action.h"
class MoveAction:public Action
{
private:
	Point P1;
public:
	MoveAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};
#endif