#include "Program.h"

Program::Program(void)
{
}
Program::~Program(void)
{
}
void Program::NacteniSouboru(string nazev)
{
  fstream Soubor;
	Soubor.open(nazev + ".txt",ios::in);
	
	if(!Soubor.is_open())
	{
		cout<<"Nelze otevrit soubor-ukoncuji program"<<endl;
		return;
	}
	else
	{	
		getline(Soubor,text,'\0');
		Soubor.close();
	}
	
}
void Program::RozdeleniNaSlova()
{
	vector<char> poleznaku;
		
	for(unsigned int i=0;i<text.length();i++)
	{
		if(isalpha(text[i]))
		{
			poleznaku.push_back(text[i]);
		}
		else 
		{
			string temp;
			while(!poleznaku.empty())
			{

			temp+=poleznaku.front();
			poleznaku.erase(poleznaku.begin());
			
			}
			if(temp.length()!=0)
			{
				poleslov.push_back(temp);
			}
		}
	}
	if(!poleznaku.empty())
	{
		string temp;
		while(!poleznaku.empty())
		{
			temp+=poleznaku.front();
			poleznaku.erase(poleznaku.begin());
		}
		
			poleslov.push_back(temp);
	}
		
}
vector<string> Program::PoleSlov()const
{
	return poleslov;
}
