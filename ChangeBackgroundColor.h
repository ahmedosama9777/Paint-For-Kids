#ifndef Change_Bk_Color_H
#define Change_Bk_Color_H
#include"Actions\Action.h"
class ChangeBackgroundColor: public Action 
{
	ActionType BkColor;
public:

	ChangeBackgroundColor(ApplicationManager *pApp);
	ActionType GetDrawColor() {return BkColor;}
	virtual void ReadActionParameters();
	virtual void Execute();
};
#endif