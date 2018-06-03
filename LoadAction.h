#ifndef Load_Action_H
#define Load_Action_H
#include"Actions\Action.h"
#include <fstream>
class LoadAction :public Action
{
	bool check;
	string filename;
public:

	LoadAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};
#endif