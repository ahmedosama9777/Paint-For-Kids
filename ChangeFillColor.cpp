#include"ChangeFillColor.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
ChangeFillColor::ChangeFillColor(ApplicationManager *pApp):Action(pApp){}
void ChangeFillColor::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Changing Drawing Color, select a color from the palette...");
	FillColor=pIn->GetChangeFill();
}
void ChangeFillColor::Execute() 
{
	ReadActionParameters();
	if(pManager->SeeSelected())
		pManager->ChangeFillingColorSelected(FillColor);
	else
	pManager->ChangeFillingColor(FillColor);

}