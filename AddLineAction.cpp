#include "AddLineAction.h"
#include "CLine.h"

#include "ApplicationManager.h"

#include "GUI\Input.h"
#include "GUI\Output.h"
#include<iostream>
using namespace std;
AddLineAction::AddLineAction(ApplicationManager * pApp):Action(pApp)
{}

void AddLineAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at first endpoint");
	
	//Read 1st endpoint and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Line: Click at second endpoint");

	//Read 2nd endpoint and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	if (P1.y <= UI.ToolBarHeight || P2.y <= UI.ToolBarHeight || P1.y >= (UI.height - UI.StatusBarHeight) || P2.y >= (UI.height - UI.StatusBarHeight))
		{
			DRAW = 0;
			cout<<"eh el habal dah";
	}
	else
		DRAW = 1;


	
	LineGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
	LineGfxInfo.FillClr = pOut->getCrntFillColor();
	LineGfxInfo.BorderWdth = pOut->getCrntPenWidth();

	pOut->ClearStatusBar();

}

//Execute the action
void AddLineAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	if (DRAW == 1) {
		//Create a line with the parameters read from the user
		CLine *L = new CLine(P1, P2, LineGfxInfo);

		//Add the line to the list of figures
		pManager->AddFigure(L);
	}
}