#ifndef Change_Fill_Color_H
#define Change_Fill_Color_H
#include"Actions\Action.h"
class ChangeFillColor: public Action 
{
	ActionType FillColor;
public:

	ChangeFillColor(ApplicationManager *pApp);
	ActionType GetFillColor() {return FillColor;}
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif