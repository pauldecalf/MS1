#pragma hdrstop
#pragma argsused
#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
  #endif



#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include "SNAfficheur.h"
 #include "SNLigne.h"
using namespace std;

 int SaisirBinaire()
{
 char bin[100];
 int nombre = 0;
 cin >> bin;
 for(int i=0;i<strlen(bin);i++)
 {
 nombre = nombre*2+(bin[i]-'0');
 }
 return nombre;
}
string EntierVersChaineEnBinaire(int nombre)
{
 ostringstream oss;
 bool copie = false;
 for(int i=31;i>=0;i--)
 {
 if(((nombre>>i)&1) == 1)
 {
 copie = true;
 }
 if(copie == true)
 {
 oss<<((nombre>>i)&1);
 }
 }
 return oss.str();
}


int _tmain(int argc, _TCHAR* argv[])
{
	SNAfficheur aff;
	SNLigne lg;

	int tm_mday;
	char phrase[200];
	int nb;
	int base;
	float val1;
	float val2;
	char operateur;
	float resultat;
	float k=1;
	int choix;
	char fonction[10];


	 aff.ModifierAdresseIPDuServeurUDP("172.20.182.57");
	 aff.ModifierPortDuServeurUDP(4321);


	cout << " Calcul(1),Trigo(2),Conversion(3)";
	cin >> choix;
	if (choix == 1)
	{
		cout << " saisir le calcul :";
		cin >> val1 >> operateur >> val2;
		if (operateur == '+') 
		{
			resultat = val1 + val2;
		}
		if (operateur == '-') 
		{
			resultat = val1 - val2;
		}
		if (operateur == '*') 
		{
			resultat = val1 * val2;
		}
		if (operateur == '/') 
		{
			  resultat = val1 / val2;

		}

	 sprintf(phrase,"%.3f %c %.3f = %.3f  date= %.3f ", val1, operateur, val2, resultat);

	}
	if (choix == 2)
	{
		cout << "Menu Trigo" << endl;
		cout << "Voulez-vous le resultat en degres (0) ou en radian (1)";
		cin >> choix;
		if (choix == 0)
		{
			k=3.14159265359/180;
		}
		cout <<"Saisir l'operation: ";
		cin >> fonction >> val1;
		val1=val1*k;
		if (strcmp (fonction,"cos") == 0) 
		{
			resultat = cos(val1);
		}
		if (strcmp (fonction,"sin") == 0) 
		{
			resultat = sin(val1);
		}
		if (strcmp (fonction,"tan") == 0)
		{
			resultat = tan(val1);
		}
		sprintf(phrase,"%s %.3f = %.3f",fonction, val1, resultat);
	}
	if (choix == 3) {

		cout << "Choix  de la base de saisie: Decimal(1), Hexa(2), Binaire(3)";
		cin >> base;

		if (base == 1) {
		  cout <<"saisir un nombre decimal: ";
		 cin >> dec >> nb;

		}
		 else

		 if (base == 2) {
		   cout <<"Saisir le nombre en hexa: ";
		  cin >> hex >> nb;
		 }

		 else

		 if (base == 3) {
		  cout <<"Saisir un nombre binaire: ";

		  nb = SaisirBinaire() ;


		 }


		 cout <<"Choix de la base d'affichage decimal (1), hexa(2)  binaire (3)";
		 cin >> base;

		 if (base == 1) {
		   cout << dec << nb;

		 }

		 if (base == 2) {
		  cout << hex << nb;
		 }

		 if (base == 3) {


		  cout << EntierVersChaineEnBinaire(nb);

		 }










	}



		 lg.ModifierMessage(phrase);

		 aff.EnvoyerLigneEnUDP(lg);

	cout <<"Resultat : " << resultat << endl;

	  cout <<"Phrase dans les logs : " << phrase;




	  cin.get();cin.get();cin.get();
	return 0;

}
