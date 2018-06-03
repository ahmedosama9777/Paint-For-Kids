#ifndef Cut_Action_H
#define Cut_Action_H
#include"Actions\Action.h"
class CutAction:public Action
{protected:
	
public:
	CutAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};
#endif