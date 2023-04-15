#include <iostream>
#include <stdlib.h>
#include "menu_functions.h"
using namespace std;
int main()
{
	bool exit = false;
	int input=20;
	while (!exit)
	{

		system("cls");
		cout << "Menu" << endl << endl;
		cout << "1:Genome" << endl;
		cout << "2:Cell" << endl;
		cout << "3:Animal" << endl;
		cout << "0:Exit" << endl;

		input = menu_functions::CinIntInput();

		switch (input)
		{
		case 0:
			exit = true;
			break;
		case 1:
			menu_functions::GenomeMenu();
			break;
		case 2:
			menu_functions::CellMenu();
			break;
		case 3:
			menu_functions::AnimalMenu();
			break;
		default:
			break;
		}
	}
}

