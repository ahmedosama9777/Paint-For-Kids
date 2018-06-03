#include"UndoStack.h"
#include<iostream>
using namespace std;
UndoStack::UndoStack()
{
	MaxFigCount=100;
	Ucount=0;
	for(int i=0; i<MaxFigCount; i++)
	{
		Ulist[i] = NULL;	
	}
}
void UndoStack::PushUstack(CFigure *s)
{
	if(Ucount < MaxFigCount )
	{
		Ucount++;
		
		Ulist[Ucount] = s;
	}
	if(Ucount==MaxFigCount)
	{
		for(int i=0;i<MaxFigCount-1;i++)
		{
			Ulist[i]=Ulist[i+1];
		}
		Ulist[MaxFigCount]=s;
	}
}
CFigure *UndoStack::PopUstack()
{
	if(Ucount>0)
	{
	CFigure *last=Ulist[Ucount];
	Ucount--;
	
	return last;
	}
	else return NULL;
}