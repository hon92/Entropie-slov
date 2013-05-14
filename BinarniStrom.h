#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <vector>
using namespace std;

struct Uzel
{
  string slovo;
	int cetnost;
	Uzel * levy;
	Uzel * pravy;
};

class BinarniStrom
{
public:
	BinarniStrom(void);
	~BinarniStrom(void);
	void pridatUzel(string);						//prida uzel do stromu
	bool najitUzel(string);							//vyhleda uzel stromu
	void vypis();									//vypis stromu
	void nastavCelkemSlov(int);						//nastavi celkovy pocet slov
	void vypisDoSouboru();							//vypise data do souboru
	void naplnitStrom(vector<string>&);				//naplni strom

private:
	void vypisPolozku(Uzel *p);						//vypis jednotlive polozky na obrazovku
	void vypisPolozkuDoSouboru(Uzel*);				//vypis jednotlive polozky do souboru
	void vnitrniVlozeni(Uzel *&koren, string);		//rekurzivni vkladani uzlu
	bool vnitrniVyhledani(Uzel * koren, string);	//rekurzivni hledani uzlu
	void vypis_inorder(Uzel * koren);				//inorder - rekurzivni vypis
	void smazaniStromu_postorder(Uzel *p);			//postorder - rekurzivni smazani uzlu
	Uzel * root;									//koren
	double entropieslova;							//entropie jednotlivych slov
	static double entropiecelkem;					//celkova entropie textu
	int celkemslov;									//celkovy pocet slov
	void vypisDoSouboru_inorder(Uzel*);				//zapise do souboru
	fstream File;									

};

