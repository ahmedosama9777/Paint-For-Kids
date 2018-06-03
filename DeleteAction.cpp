#include"DeleteAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
DeleteAction::DeleteAction(ApplicationManager *pApp):Action(pApp){}
void DeleteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("All selected figures will be deleted !");
}
void DeleteAction::Execute()
{
	ReadActionParameters();
	pManager->DeleteSelected();
}