#include"ResizeAction.h"

#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
ResizeAction::ResizeAction(ApplicationManager *pApp):Action(pApp){}
void ResizeAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//get input
	ResizeFactor=pIn->GetResize();
	
}
void ResizeAction::Execute() 
{
	ReadActionParameters();
	pManager->ResizeSelected(ResizeFactor);
	

}