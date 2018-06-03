#ifndef REDOSTACK_H
#define REDOSTACK_H
#include"Figures\CFigure.h"
class RedoStack
{
	enum { MaxFigCount = 100 };
private:
	CFigure *Rlist[MaxFigCount];
	int Rcount;
public:
	RedoStack();
	void PushRstack(CFigure *s);
	CFigure *PopRstack();
};
#endif