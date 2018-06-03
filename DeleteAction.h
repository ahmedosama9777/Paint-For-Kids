#ifndef Delete_Action_H
#define Delete_Action_H
#include"Actions\Action.h"
class DeleteAction:public Action
{
	public:
	DeleteAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};
#endif