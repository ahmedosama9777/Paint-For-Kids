#include "SelectAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include<iostream>
int SelectAction::count=0;
SelectAction::SelectAction(ApplicationManager *pApp):Action(pApp)
{}
void SelectAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select one of the drawn figures !");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}
void SelectAction::Execute()
{
	//This action needs to read some parameters first
	CFigure*fig;
	do
	{
	ReadActionParameters();
	
	fig=pManager->GetFigure(P1.x,P1.y);
	if(fig!=NULL)
		if(fig->IsSelected()==false)
		{
			fig->SetSelected(true);
			count++;
		}
		else
		{
			fig->SetSelected(false);
			count--;
		}
		if(count==1)
		{
			pManager->Print();
		}
		pManager->UpdateInterface();
	}while(fig!=NULL);
}
void SelectAction::Decrement()
{
	count--;
}