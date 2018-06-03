#include "AddTriAction.h"
#include "CTriangle.h"

#include "ApplicationManager.h"

#include "GUI\Input.h"
#include "GUI\Output.h"

AddTriAction::AddTriAction(ApplicationManager * pApp):Action(pApp)
{}

void AddTriAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");
	
	//Read 3rd corner and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);
	if (P1.y <= UI.ToolBarHeight || P2.y <= UI.ToolBarHeight || P3.y <= UI.ToolBarHeight || P1.y >= (UI.height - UI.StatusBarHeight) || P2.y >= (UI.height - UI.StatusBarHeight) || P3.y >= (UI.height - UI.StatusBarHeight))
		DRAW = 0;
	else
		DRAW = 1;
	if(UI.filled)
		TriGfxInfo.isFilled=true;
	else
		TriGfxInfo.isFilled = false;
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();
	TriGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	if (DRAW) {
		//Create a Triangle with the parameters read from the user
		CTriangle *T = new CTriangle(P1, P2, P3, TriGfxInfo);

		//Add the Triangle to the list of figures
		pManager->AddFigure(T);
	}
}