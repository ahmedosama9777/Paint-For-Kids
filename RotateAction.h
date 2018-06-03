#ifndef Rotate_Action_H
#define Rotate_Action_H

#include "Actions\Action.h"
class RotateAction :public Action
{
private:
	Point P1;
	double angle;

public:
	RotateAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif