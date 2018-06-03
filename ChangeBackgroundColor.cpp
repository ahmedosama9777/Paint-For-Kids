#include"ChangeBackgroundColor.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
ChangeBackgroundColor::ChangeBackgroundColor(ApplicationManager *pApp):Action(pApp){}
void ChangeBackgroundColor::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Changing Drawing Color, select a color from the palette...");
	BkColor=pIn->GetChangeBk();
}
void ChangeBackgroundColor::Execute() 
{
	ReadActionParameters();
	pManager->ChangeBkColor(BkColor);

}