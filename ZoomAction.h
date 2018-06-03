#ifndef Zoom_Action_H
#define Zoom_Action_H
#include"Actions\Action.h"
class ZoomAction :public Action
{
private:
	Point p;
	ActionType ResizeFactor;
	double factor;
	bool toolaction;
	ActionType x;

public:
	ZoomAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};
#endif