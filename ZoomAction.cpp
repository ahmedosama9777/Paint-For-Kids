#include"ZoomAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
ZoomAction::ZoomAction(ApplicationManager *pApp) :Action(pApp)
{
}
void ZoomAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ResizeFactor = pIn->GetZoom();
	switch (ResizeFactor)
	{
	case RQuarter:
		factor= 0.25;
		break;
	case RHalf:
		factor = 0.5;
		break;
	case RDouble:
		factor = 2;
		break;
	case RQuad:
		factor = 4;
		break;
	case EMPTY:
		pOut->PrintMessage("No Size was Selected");
		break;
	}

	pOut->PrintMessage("click on a location to zoom all figures to this location!");
	pIn->GetPointClicked(p.x, p.y);
	x = pIn->GetUserAction(p);
	if (x != DRAWING_AREA) 
			pManager->ExecuteAction(x);

		
		
	

	
}
void ZoomAction::Execute()
{
	ReadActionParameters();
	pManager->zoomall(p, factor);

}