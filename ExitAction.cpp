#include"ExitAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include<iostream>
using namespace std;
ExitAction::ExitAction(ApplicationManager *pApp, ActionType &act) :Action(pApp)
{
	actType = &act;
}
void ExitAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	checkF = pManager->checkbeforeexit2();
	checkB = pManager->checkbeforeexit();
	string b = "";
	pOut->PrintMessage("Are you sure you want to exit !? Press Y for yes and N for no");
	b = pIn->GetSrting(pOut);
	if (b == "Y" || b == "N")
	{
		s = b;
	}
	else
	{
		bool c = false;
		do {
			pOut->PrintMessage("Are you sure you want to exit !? Press Y for yes and N for no");
			s = pIn->GetSrting(pOut);
			cout << s << endl;
			if (s != "Y" || s != "N")
			{
				c = false;
			}
			else
			{
				c = true;
			}
		} while (c);
	}

}
void ExitAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ReadActionParameters();
	bool c;

	if (s == "Y")
	{
		cout << "BULLSHIT" << endl;
		if (checkB == false && checkF == false)
		{

		}
		else
		{
			string charr = "";
			do {
				pOut->PrintMessage("Do you want to save your progress !?");
				charr = pIn->GetSrting(pOut);
				cout << charr << endl;
				if (charr == "Y" || charr == "N")
				{
					c = false;
				}
				else
				{
					c = true;
				}
			} while (c == true);
			if (charr == "Y")
			{

				ActionType a = SAVE;
				pManager->ExecuteAction(a);
			}
			*actType = EXIT;
		}
	}
	if (s == "N")
	{
		*actType = LOAD;
		cout << "BULLSHIT777" << endl;
	}
}