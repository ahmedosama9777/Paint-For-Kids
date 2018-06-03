#include "ScrambleAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include <stdlib.h>     /* srand, rand */

ScrambleAction::ScrambleAction(ApplicationManager *pApp) :Action(pApp)
{
}
void ScrambleAction::ReadActionParameters()
{
	toolaction = 0;
	InvalidPicks = 0;
	ValidPicks = 0;
	string s1, s2, s3;
	CFigure*left;
	CFigure*right;
	Point p;
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	bool donewiththisfig=1;

	do {
		if(donewiththisfig) left = pManager->randomselect();
		if (left == NULL)break;

		pOut->drawcenterline();
		pManager->UpdateInterface();
		pOut->drawcenterline();

		pIn->GetPointClicked(p.x, p.y);
		x=pIn->GetUserAction(p);
		if (x != DRAWING_AREA) {
			toolaction = 1;
			break;

		}

		else {
			right = pManager->GetFigure(p.x, p.y);

			if (right != NULL && left->getID() == right->getID()) {
				ValidPicks++;
				left->setDrawthis(0);
				right->setDrawthis(0);
				s1 = to_string(ValidPicks);
				s2 = to_string(InvalidPicks);
				pOut->PrintMessage("ValidPicks:  " + s1 + "        IN ValidPicks:  " + s2);
				donewiththisfig = 1;


			}
			else {
				InvalidPicks++;
				s1 = to_string(ValidPicks);
				s2 = to_string(InvalidPicks);
				pOut->PrintMessage("try Again!!     ValidPicks:  " + s1 + "        IN ValidPicks:  " + s2);
				donewiththisfig = 0;
				continue;


				pManager->UpdateInterface();
				pOut->drawcenterline();

			}
		}
	} while (1);


}
void ScrambleAction::Execute()
{
	string s1;

	Output* pOut = pManager->GetOutput();

	selectlist = pManager->saveselected();
	pManager->unselectall();
    pManager->scramblefig();
	pManager->movetoleft();
	

	pOut->drawcenterline();



	ReadActionParameters();
	grade = (double)ValidPicks / (ValidPicks+ InvalidPicks) *100.0;
	s1 = to_string(grade);
	pOut->PrintMessage("your score: " + s1 + "%");

	pManager->deletedublicate();//delete the right figues
	pManager->undoselected(selectlist); //reselect all seleced figure
	pManager->undotemp();//undo zoom
	pManager->undohidden();//show all hidden figures
	pManager->UpdateInterface();

	if (toolaction)pManager->ExecuteAction(x);


}