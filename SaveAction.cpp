#include"SaveAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include <sstream>
#include <string>
SaveAction::SaveAction(ApplicationManager *pApp) :Action(pApp) {}
void SaveAction::ReadActionParameters()
{
	
}
void SaveAction::Execute()
{
	string FileName;

	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("enter the file name");
	Input* pIn = pManager->GetInput();
	FileName = pIn->GetSrting(pOut);
	std::stringstream ss;
	ss <<FileName<<".txt";
	std::string FileName1 = ss.str();
	OutFile.open(FileName1);
	pManager->SaveAll(OutFile);
	OutFile.close();

}
