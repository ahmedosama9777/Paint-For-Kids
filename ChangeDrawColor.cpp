#include"ChangeDrawColor.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
ChangeDrawColor::ChangeDrawColor(ApplicationManager *pApp):Action(pApp){}
void ChangeDrawColor::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Changing Drawing Color, select a color from the palette...");
	DrawColor=pIn->GetChangeDraw();
}
void ChangeDrawColor::Execute() 
{
	ReadActionParameters();
	if(pManager->SeeSelected())
	{
		pManager->ChangeDrawingColorSelected(DrawColor);
	}
	else
	{
	pManager->ChangeDrawingColor(DrawColor);
	}
}