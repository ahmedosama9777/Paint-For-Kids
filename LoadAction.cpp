#include"LoadAction.h"
#include "ApplicationManager.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include"DEFS.h"
#include<iostream>
using namespace std;

LoadAction::LoadAction(ApplicationManager *pApp) :Action(pApp) {}
void LoadAction::ReadActionParameters()
{
	check=pManager->CheckBeforeLoad();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(check==true)
	{
		pOut->PrintMessage("Enter file name to be loaded:");
		filename=pIn->GetSrting(pOut);

	}
	else if(check==false)
	{
		pOut->PrintMessage("do you want to save your progress: press y or n");
		string s=pIn->GetSrting(pOut);
		if(s=="y"||s=="n")
		{

		if(s=="y")
		{
			ActionType a=SAVE;
			pManager->ExecuteAction(a);
			pOut->PrintMessage("Enter file name to be loaded:");
			filename=pIn->GetSrting(pOut);
		}
		if(s=="n")
		{
			pOut->PrintMessage("Enter file name to be loaded:");
			filename=pIn->GetSrting(pOut);
		}
		}
		else
		{
			string ch="";
			bool c;
		do
		{
			pOut->PrintMessage("do you want to save your progress: press Y or N");
			ch=pIn->GetSrting(pOut);
			cout<<ch<<endl;
			
			if((ch!="Y") || (ch!="N"))
			{
				c=false;
			}
			else c=true;
		}while(c);
		if(ch=="Y")
		{
			ActionType a=SAVE;
			pManager->ExecuteAction(a);
			pOut->PrintMessage("Enter file name to be loaded:");
			filename=pIn->GetSrting(pOut);
		}
		if(ch=="N")
		{
			pOut->PrintMessage("Enter file name to be loaded:");
			filename=pIn->GetSrting(pOut);
		}
		}
	}
		
		
	pOut->ClearDrawArea();
}
void LoadAction::Execute()
{
	ReadActionParameters();
	pManager->load(filename);

}