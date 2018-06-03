#include"CutAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
CutAction::CutAction(ApplicationManager *pApp):Action(pApp){}
void CutAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("All selected figures will be cut !");
}
void CutAction::Execute()
{
	ReadActionParameters();
	pManager->CpyToClipboard();
	pManager->DeleteSelected();
}