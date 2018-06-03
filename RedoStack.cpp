#include"RedoStack.h"
RedoStack::RedoStack()
{
	for(int i=0; i<MaxFigCount; i++)
		Rlist[i] = NULL;	
	Rcount=0;
}
void RedoStack::PushRstack(CFigure *s)
{
	if(Rcount < MaxFigCount )
	{
		Rcount++;
		Rlist[Rcount] = s;
	}
}
CFigure *RedoStack::PopRstack()
{
	if(Rcount>0)
	{
	CFigure *last=Rlist[Rcount];
	Rcount--;
	return last;
	}
	else return NULL;
}