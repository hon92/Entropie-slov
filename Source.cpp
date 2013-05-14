#include <iostream>
#include <string>
using namespace std;
#include "BinarniStrom.h"
#include "Program.h"

int main()
{
  BinarniStrom strom;
	Program file;
	string nazevsouboru;

	cout<<"Zadej nazev souboru pro cteni: ";
	cin>>nazevsouboru ;

	file.NacteniSouboru(nazevsouboru);
	file.RozdeleniNaSlova();

	strom.nastavCelkemSlov(file.PoleSlov().size());
	strom.naplnitStrom(file.PoleSlov());
	strom.vypis();
	strom.vypisDoSouboru();
			
	return 0;
}
