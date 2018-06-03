#include"BringFAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

BringFAction::BringFAction(ApplicationManager *pApp) :Action(pApp) {}

void BringFAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("All selected figures will be bring to front !");
}
void BringFAction::Execute()
{
	ReadActionParameters();
	pManager->bringfselected();
}