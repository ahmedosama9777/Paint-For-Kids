#include "PickAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include <stdlib.h>     /* srand, rand */
//int SelectAction::count = 0;
PickAction::PickAction(ApplicationManager *pApp, ActionType x) :Action(pApp)
{
	mode = x;
}
void PickAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	toolaction = 0;
	CFigure*fig;
	bool gameon = 0;
	InvalidPicks = 0;
	ValidPicks = 0;
	string s1 ;
	string s2;
	string s3;
	string s4;
	int v1;
	int v2;
	int loopcounter;
	int j = 0;



	if (mode == Type) {

		do {
			 v1 = rand() % 4;         // v1 in the range 0 to 3
			if (v1 == 0 && r) {
				pOut->PrintMessage("pick all rectangles");
				gameon = 1;
				modeId = 1;
				loopcounter = r;

			}
			else if (v1 == 1 && c) {
				pOut->PrintMessage("pick all circles");
				gameon = 1;
				modeId = 2;
				loopcounter = c;

			}
			else if (v1 == 2 && t) {
				pOut->PrintMessage("pick all triangles");
				gameon = 1;
				modeId = 3;
				loopcounter = t;

			}
			else if (v1 == 3 && l) {
				pOut->PrintMessage("pick all lines");
				gameon = 1;
				modeId = 4;
				loopcounter = l;

			}
		} while (!gameon);

		do {
			pIn->GetPointClicked(P1.x, P1.y);
			x = pIn->GetUserAction(P1);
			if (x != DRAWING_AREA) {
				toolaction = 1;
				break;
			}
			
			fig = pManager->GetFigure(P1.x, P1.y);
			if (fig != NULL&&  modeId == fig->gettype()) {

				fig->setDrawthis(0);
				pManager->UpdateInterface();
				ValidPicks++;
				j++;
				s1 = to_string(ValidPicks);
				s2 = to_string(InvalidPicks);
				pOut->PrintMessage("ValidPicks:  " + s1 + "        IN ValidPicks:  " + s2);
			}
			else {
				InvalidPicks++;
				s1 = to_string(ValidPicks);
				s2 = to_string(InvalidPicks);
				pOut->PrintMessage("try Again!!     ValidPicks:  " + s1 + "        IN ValidPicks:  " + s2);
				continue;
			}

			if (j == loopcounter ) {
				break;
			}
		} while (1);
		/*for (int i = 0; i < loopcounter ; i++) {
			pIn->GetPointClicked(P1.x, P1.y);
			x = pIn->GetUserAction(P1);
			if (x != DRAWING_AREA) {
				toolaction = 1;
				break;
			}
			fig = pManager->GetFigure(P1.x, P1.y);
			if (fig != NULL)

			{
				fig->setDrawthis(0);

				pManager->UpdateInterface();

				if (modeId == fig->gettype())
					ValidPicks++;
				else InvalidPicks++;
			}
			s1 = to_string(ValidPicks);
			s2 = to_string(InvalidPicks);
			s3 = to_string(loopcounter-i-1);

			pOut->PrintMessage("ValidPicks:  " + s1 + "        IN ValidPicks:  " + s2  +"    "+s3 +" trials to go " );

		}*/


	}//end mode 1x

	else if (mode == Fill) {
		
		int listcount;
		pickgame *fillcolorlist;
		fillcolorlist =pManager->fillcorollist(listcount);
		v1 = rand() % listcount;//chosse random color
		pOut->PrintMessage("select all "+ fillcolorlist[v1].colorname+ " filled figures");
		do {
			pIn->GetPointClicked(P1.x, P1.y);
			x = pIn->GetUserAction(P1);
			if (x != DRAWING_AREA) {
				toolaction = 1;
				break;
			}
			
			fig = pManager->GetFigure(P1.x, P1.y);
			if (fig != NULL&&  fig->getFillClr() == fillcolorlist[v1].colorname ) {

				fig->setDrawthis(0);
				pManager->UpdateInterface();
				ValidPicks++;
				j++;
				s1 = to_string(ValidPicks);
				s2 = to_string(InvalidPicks);
				pOut->PrintMessage("ValidPicks:  " + s1 + "        IN ValidPicks:  " + s2);
			}
			else {
				InvalidPicks++;
				s1 = to_string(ValidPicks);
				s2 = to_string(InvalidPicks);
				pOut->PrintMessage("try Again!!     ValidPicks:  " + s1 + "        IN ValidPicks:  " + s2);
				continue;
			}
			if (j == fillcolorlist[v1].colorcount ) {
				break;
			}
		} while (1);

		/*for (int i = 0; i < fillcolorlist[v1].colorcount; i++) {
			pIn->GetPointClicked(P1.x, P1.y);
			fig = pManager->GetFigure(P1.x, P1.y);
			x = pIn->GetUserAction(P1);
			if (x != DRAWING_AREA) {
				toolaction = 1;
				break;
			}
			if (fig != NULL)

			{
				fig->setDrawthis(0);
				pManager->UpdateInterface();

				if (fig->getFillClr()== fillcolorlist[v1].colorname)
					ValidPicks++;
				else InvalidPicks++;
			}
			s1 = to_string(ValidPicks);
			s2 = to_string(InvalidPicks);
			s3 = to_string(fillcolorlist[v1].colorcount - i-1);

			pOut->PrintMessage("ValidPicks:  " + s1 + "        IN ValidPicks:  " + s2 + "    " + s3 + " trials to go ");

		}*/
		
	}//end mode 2x
	
	else if (mode == Type_Fill) {
		int listcount;
		pickgame *fillcolorlist;
		fillcolorlist = pManager->fillcorollist(listcount);
		v2 = rand() % listcount;//here we choosed fill color fillcolorlist[v1].colorname
		gameon = 0;
		do {
			v1 = rand() % 4;         // v1 in the range 0 to 3
			if (v1 == 0 && r && fillcolorlist[v2].type[v1]) {
				gameon = 1;
				modeId = 1;
				///if (fillcolorlist[v2].type[v1] < fillcolorlist[v2].colorcount)loopcounter = fillcolorlist[v2].type[v1];
				//else loopcounter = fillcolorlist[v2].type[v1];
				loopcounter=fillcolorlist[v2].type[modeId - 1];
				pOut->PrintMessage("select all " + fillcolorlist[v2].colorname + " filled rectangle(s)"  );
			}
			else if (v1 == 1 && c && fillcolorlist[v2].type[v1]) {
				gameon = 1;
				modeId = 2;
				//if (fillcolorlist[v2].type[v1] < fillcolorlist[v2].colorcount)loopcounter = fillcolorlist[v2].type[v1];
				//else loopcounter = fillcolorlist[v2].type[v1];
				loopcounter = fillcolorlist[v2].type[modeId - 1];

				pOut->PrintMessage("select all " + fillcolorlist[v2].colorname + " filled circle(s)");
			}
			else if (v1 == 2 && t && fillcolorlist[v2].type[v1]) {
				gameon = 1;
				modeId = 3;
				//if (fillcolorlist[v2].type[v1] < fillcolorlist[v2].colorcount)loopcounter = fillcolorlist[v2].type[v1];
				//else loopcounter = fillcolorlist[v2].type[v1];
				loopcounter = fillcolorlist[v2].type[modeId - 1];

				pOut->PrintMessage("select all " + fillcolorlist[v2].colorname + " filled triangles(s)");
			}
			else if (v1 == 3 && l && fillcolorlist[v2].type[v1]) {
				gameon = 1;
				modeId = 4;
				//if (fillcolorlist[v2].type[v1] < fillcolorlist[v2].colorcount)loopcounter = fillcolorlist[v2].type[v1];
				//else loopcounter = fillcolorlist[v2].type[v1];
				loopcounter = fillcolorlist[v2].type[modeId - 1];

				pOut->PrintMessage("select all " + fillcolorlist[v2].colorname + " filled lines(s)");
			}
		} while (!gameon);

		do {
			int j = 0;
			pIn->GetPointClicked(P1.x, P1.y);
			x = pIn->GetUserAction(P1);
			if (x != DRAWING_AREA) {
				toolaction = 1;
				break;
			}
			
			fig = pManager->GetFigure(P1.x, P1.y);
			if (fig != NULL&&  fig->getFillClr() == fillcolorlist[v2].colorname && fig->gettype() == modeId) {

				fig->setDrawthis(0);
				pManager->UpdateInterface();
				ValidPicks++;
				j++;
				s1 = to_string(ValidPicks);
				s2 = to_string(InvalidPicks);
				pOut->PrintMessage("ValidPicks:  " + s1 + "        IN ValidPicks:  " + s2);
			}
			else {
				InvalidPicks++;
				s1 = to_string(ValidPicks);
				s2 = to_string(InvalidPicks);
				pOut->PrintMessage("try Again!!     ValidPicks:  " + s1 + "        IN ValidPicks:  " + s2);
				continue;
			}
			if (j == loopcounter ) {
				break;
			}
		} while (1);
		/*for (int i = 0; i < fillcolorlist[v2].type[modeId-1]; i++) {
			pIn->GetPointClicked(P1.x, P1.y);
			x = pIn->GetUserAction(P1);
			if (x != DRAWING_AREA) {
				toolaction = 1;
				break;
			}
			fig = pManager->GetFigure(P1.x, P1.y);
			if (fig != NULL)

			{
				fig->setDrawthis(0);
				pManager->UpdateInterface();

				if (fig->getFillClr() == fillcolorlist[v2].colorname && fig->gettype()== modeId)
					ValidPicks++;
				else InvalidPicks++;
			}
			s1 = to_string(ValidPicks);
			s2 = to_string(InvalidPicks);
			s3 = to_string(fillcolorlist[v2].type[modeId - 1] - i - 1);

			pOut->PrintMessage("ValidPicks:  " + s1 + "        IN ValidPicks:  " + s2 + "    " + s3 + " trials to go ");

		}*/





	}//end mode 3x

	else if (mode == Area) {
		int j = 0;

		v2 = rand() %2;
		int *list;
		list = pManager->areaorder(v2);
		if (v2 == 0)
			s1 = "ascending ";
		else
			s1 = "descending  ";

		pOut->PrintMessage("select all figures in " + s1+ " order");
		do {
			pIn->GetPointClicked(P1.x, P1.y);
			x = pIn->GetUserAction(P1);
			if (x != DRAWING_AREA) {
				toolaction = 1;
				break;
			}
			
			fig = pManager->GetFigure(P1.x, P1.y);
			if (fig != NULL&&  fig->getID() ==list[j]) {

				fig->setDrawthis(0);
				pManager->UpdateInterface();
				ValidPicks++;
				j++;
				s1 = to_string(ValidPicks);
				s2 = to_string(InvalidPicks);
				pOut->PrintMessage("ValidPicks:  " + s1 + "        IN ValidPicks:  " + s2);
			}
			else {
				InvalidPicks++;
				s1 = to_string(ValidPicks);
				s2 = to_string(InvalidPicks);
				pOut->PrintMessage("try Again!!     ValidPicks:  " + s1 + "        IN ValidPicks:  " + s2);
				continue;
			}
			if (j == r + c + t + l) {
				break;
			}
		} while (1);

	}//end mode 4x*/

}
void PickAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pManager->typecounter(r, c, t, l);

	ReadActionParameters();
	string s4;

	grade = 0;
	grade = (double)ValidPicks / (ValidPicks+ InvalidPicks) *100.0;
	s4 = to_string(grade);
	pOut->PrintMessage("your score: " + s4 + "%" + "  click anywhere to continue");

	pIn->GetPointClicked(P1.x, P1.y);
	//x = pIn->GetUserAction(P1);

	pManager->undohidden();
	if (toolaction)pManager->ExecuteAction(x);







}
