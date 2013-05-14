#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Program
{
public:
  Program(void);
	~Program(void);
	void NacteniSouboru(string nazev);	//nacte z txt souboru do retezce a rozdeli na slova
	void RozdeleniNaSlova();			//rozdeli retezec na slova
	vector<string> PoleSlov()const;		//funkce vraci pole slov
private:
	string text;						//nacteny text ze souboru
	vector<string> poleslov;			//pole rozdelenych slov
		
};

