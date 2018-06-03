#include"RedoAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
RedoAction::RedoAction(ApplicationManager *pApp):Action(pApp)
{}
void RedoAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Redo is selected!!");
}
void RedoAction::Execute()
{
	ReadActionParameters();
	pManager->redo();
}