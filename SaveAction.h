#ifndef Save_Action_H
#define Save_Action_H
#include"Actions\Action.h"
#include <fstream>
class SaveAction :public Action
{
	ofstream OutFile;
public:

	SaveAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};
#endif