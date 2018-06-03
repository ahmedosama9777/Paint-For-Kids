#include"ChangeWidthAction.h"

#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
ChangeWidthAction::ChangeWidthAction(ApplicationManager *pApp):Action(pApp){}
void ChangeWidthAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//get input
	WidthFactor=pIn->GetWidth();
	
}
void ChangeWidthAction::Execute() 
{
	ReadActionParameters();
	if(pManager->SeeSelected())
		pManager->ChangeBorderSelected(WidthFactor);
	else
	pManager->ChangeBorder(WidthFactor);
	

}