#ifndef Select_Action_H
#define Select_Action_H

#include "Actions\Action.h"
class SelectAction:public Action
{
private:
	Point P1;
	static int count;
public:
	SelectAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
	static void Decrement();
};
#endif