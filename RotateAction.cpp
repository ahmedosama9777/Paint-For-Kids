#include "RotateAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"

RotateAction::RotateAction(ApplicationManager *pApp) :Action(pApp)
{}
void RotateAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
//	MenuItemImages[ITM_Rotate] = "images\\MenuItems\\Menu_rotate.jpg";
	pIn->GetPointClicked(P1.x, P1.y);
	if (P1.y > 17) 
		angle = 90;
	if(17<=P1.y<34)
		angle = 180;
	if (34<=P1.y<50)
		angle = 270;
}
void RotateAction::Execute()
{
	Output* pOut = pManager->GetOutput();

		ReadActionParameters();
		pManager->rotateselected(angle);
}