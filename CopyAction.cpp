#include"CopyAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
CopyAction::CopyAction(ApplicationManager *pApp):Action(pApp){}
void CopyAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("All selected figures will be copied to clipboard ");
}
void CopyAction::Execute()
{
	ReadActionParameters();
	pManager->CpyToClipboard();
}