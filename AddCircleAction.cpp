#include "AddCircleAction.h"
#include "CCircle.h"

#include "ApplicationManager.h"

#include "GUI\Input.h"
#include "GUI\Output.h"
#include"string"

AddCircleAction::AddCircleAction(ApplicationManager * pApp):Action(pApp)
{}

void AddCircleAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at first point");
	
	//Read 1st point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at second point");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	float d2 = (P1.x - P2.x)*(P1.x - P2.x) + (P1.y - P2.y)*(P1.y - P2.y);
	Radius = sqrt(d2);

	if ((P1.x - Radius) <= 0 || (P1.x + Radius) >= UI.width || (P1.y - Radius) <= UI.ToolBarHeight || (P1.y + Radius) >= (UI.height - UI.StatusBarHeight) || P1.y <= UI.ToolBarHeight || P1.y >= (UI.height - UI.StatusBarHeight) || P2.y <= UI.ToolBarHeight || P2.y >= (UI.height - UI.StatusBarHeight))
		DRAW = 0;
	else
		DRAW = 1;

	if(UI.filled)
		CircGfxInfo.isFilled=true;
	else
		CircGfxInfo.isFilled = false;
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	CircGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircleAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	if (DRAW) {
		//Create a Circle with the parameters read from the user
		CCircle *C = new CCircle(P1, Radius, CircGfxInfo);

		//Add the Circle to the list of figures
		pManager->AddFigure(C);
	}
}