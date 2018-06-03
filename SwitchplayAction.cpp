#include "SwitchplayAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
SwitchplayAction::SwitchplayAction(ApplicationManager *pApp) :Action(pApp)
{}
void SwitchplayAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (r + c + t + l == 1) {
		pOut->PrintMessage("only one figure exist better to return to draw mode ");
		pOut->CreatePlayToolBar();
	}
	else if (r + c + t + l < 1) {
		pOut->PrintMessage("no figure exist can't enter play mode go back draw some figures ");
	}
	else{

		pOut->CreatePlayToolBar();
	}



}
void SwitchplayAction::Execute()
{
	pManager->typecounter(r, c, t, l);

	ReadActionParameters();

}