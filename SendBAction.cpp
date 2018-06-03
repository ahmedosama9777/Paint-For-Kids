#include"SendBAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

SendBAction::SendBAction(ApplicationManager *pApp) :Action(pApp) {}

void SendBAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("All selected figures will be send to back !");
}
void SendBAction::Execute()
{
	ReadActionParameters();
	pManager->sendbselected();
}