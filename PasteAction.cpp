#include"PasteAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
PasteAction::PasteAction(ApplicationManager *pApp):Action(pApp){}
void PasteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Click on a location to paste selected figures!");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->ClearStatusBar();
}
void PasteAction::Execute()
{
	ReadActionParameters();
	pManager->PasteSelected(P1);
}