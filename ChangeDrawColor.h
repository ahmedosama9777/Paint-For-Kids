#ifndef Change_Color_H
#define Change_Color_H
#include"Actions\Action.h"
class ChangeDrawColor: public Action 
{
	ActionType DrawColor;
public:

	ChangeDrawColor(ApplicationManager *pApp);
	ActionType GetDrawColor() {return DrawColor;}
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif