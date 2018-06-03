#ifndef Paste_Action_H
#define Paste_Action_H
#include"Actions\Action.h"
class PasteAction:public Action
{
private:
	Point P1;
public:
	PasteAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;
};
#endif