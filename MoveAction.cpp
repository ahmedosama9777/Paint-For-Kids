#include"MoveAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
MoveAction::MoveAction(ApplicationManager *pApp) :Action(pApp)
{
	
}
void MoveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("click on a location to move selected figures !");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}
void MoveAction::Execute()
{
	ReadActionParameters();
	pManager->MoveSelected(P1);
}