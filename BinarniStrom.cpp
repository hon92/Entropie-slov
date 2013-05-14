#include "BinarniStrom.h"

BinarniStrom::BinarniStrom(void)
{
  root=NULL;
}
BinarniStrom::~BinarniStrom(void)
{
	smazaniStromu_postorder(root);
}
double BinarniStrom::entropiecelkem=0;

void BinarniStrom::vnitrniVlozeni(Uzel *&koren, string s)
{
	if(koren==NULL)
	{
		koren=new Uzel;
		koren->slovo=s;
		koren->cetnost=1;
		koren->pravy=NULL;
		koren->levy=NULL;
		return;
	}
	if(s < koren->slovo)
	{
		vnitrniVlozeni(koren->levy,s);
		return;
	}
	if(s > koren->slovo)
	{
		vnitrniVlozeni(koren->pravy,s);
		return;
	}
}
bool BinarniStrom::vnitrniVyhledani(Uzel * koren, string s)
{
	if(koren==NULL)
	{
		return false;
	}
	if(koren->slovo==s)
	{
		koren->cetnost++;
		return true;
	}
	if(s < koren->slovo)
	{
		return vnitrniVyhledani(koren->levy,s);
	}
	else
	{
		return vnitrniVyhledani(koren->pravy,s);
	}
}
void BinarniStrom::vypis_inorder(Uzel * koren)
{
	if(koren!=NULL)
	{
		vypis_inorder(koren->levy);
		vypisPolozku(koren);
		vypis_inorder(koren->pravy);
	}
}
void BinarniStrom::smazaniStromu_postorder(Uzel *p)
{
	if(p!=NULL)
	{
		smazaniStromu_postorder(p->levy);
		smazaniStromu_postorder(p->pravy);
		delete p;
	}
}
void BinarniStrom::pridatUzel(string s)
{
	vnitrniVlozeni(root,s);
}
bool BinarniStrom::najitUzel(string s)
{
	return vnitrniVyhledani(root,s);
}
void BinarniStrom::vypis()
{
	vypis_inorder(root);
	
	if(entropiecelkem!=0)
	cout<<"Celkova entropie: "<<"\""<<entropiecelkem<<"\""<<endl;
}
void BinarniStrom::vypisPolozku(Uzel *p)
{
	if(p->slovo.length()==0)
	{
		return;
	}
	entropieslova=-(log(p->cetnost/(double)celkemslov)/log(2.0));
	entropiecelkem+=p->cetnost * entropieslova;
	
	cout<<"Slovo: "<<"\""<<p->slovo<<"\" "<<endl;
	cout<<"Cetnost: "<<"\""<<p->cetnost<<"\" "<<endl;
	cout<<"Entropie: "<<"\""<<entropieslova<<"\""<<endl;
	cout<<"-----------------------------------"<<endl;
}
void BinarniStrom::vypisPolozkuDoSouboru(Uzel *p)
{
	File<<"Slovo: "<<"\""<<p->slovo<<"\" "<<endl;
	File<<"Cetnost: "<<"\""<<p->cetnost<<"\" "<<endl;
	File<<"Entropie: "<<"\""<<entropieslova<<"\""<<endl;
	File<<"-----------------------------------"<<endl;
}
void BinarniStrom::vypisDoSouboru_inorder(Uzel *koren)
{
	if(koren!=NULL)
	{
		vypisDoSouboru_inorder(koren->levy);
		vypisPolozkuDoSouboru(koren);
		vypisDoSouboru_inorder(koren->pravy);
	}
}
void BinarniStrom::nastavCelkemSlov(int c)
{
	celkemslov=c;
}
void BinarniStrom::vypisDoSouboru()
{
	File.open("vypisentropie.txt",ios::out);
	
	vypisDoSouboru_inorder(root);

	if(entropiecelkem!=0)
		File<<"Celkova entropie: "<<"\""<<entropiecelkem<<"\""<<endl;

	File.close();
}
void BinarniStrom::naplnitStrom(vector<string> &tmp)
{
	while(!tmp.empty())
	{
		najitUzel(tmp.back());
		pridatUzel(tmp.back());
		tmp.pop_back();
	}
}
