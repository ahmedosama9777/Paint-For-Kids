#ifndef UNDOSRACK_H
#define UNDOSRACK_H
#include"Figures\CFigure.h"
class UndoStack
{
private:
	int MaxFigCount;
	CFigure *Ulist[100];
	int Ucount;
public:
	UndoStack();
	void PushUstack(CFigure *s);
	CFigure *PopUstack();
};
#endif