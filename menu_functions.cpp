#include <iostream>
#include <string>
#include "menu_functions.h"
#include "animal.h"
#include "Cell.h"
#include "genome.h"

using namespace std;
void menu_functions::GenomeMenu() {
	//if be true get back to the main menu
	bool back = false;
	int input;
	genome gen;
	system("cls");
	SetDNAMenu(gen);
	SetRNAMenu(gen);

	while (!back)
	{
		system("cls");
		cout << "Genome Menu" << endl << endl;
		cout << "1:createDNAFromRNA" << endl;
		cout << "2:RNAShortJump" << endl;
		cout << "3:DNAShortJump" << endl;
		cout << "4:RNALongJump" << endl;
		cout << "5:DNALongJump" << endl;
		cout << "6:RNAReversJump" << endl;
		cout << "7:DNAReversJump" << endl;
		cout << "0:Back to main menu" << endl;
		input = CinIntInput();
		system("cls");
		switch (input)
		{
		case 0:
			back = true;
			break;
		case 1:
			GenomeCDOR(gen);
			break;
		case 2:
			GenomeRNAShortJump(gen);
			break;
		case 3:
			GenomeDNAShortJump(gen);
			break;
		case 4:
			GenomeRNALongJump(gen);
			break;
		case 5:
			GenomeDNALongJump(gen);
			break;
		case 6:
			GenomeRNAReversJump(gen);
			break;
		case 7:
			GenomeDNAReversJump(gen);
			break;

		default:
			break;
		}
	}
}
void menu_functions::SetDNAMenu(genome& gen) {
	bool suc = false;
	string input_dna[DNASize];
	while (!suc)
	{
		suc = true;
		cout << "Entering DNA content:" << endl;

		for (int i = 0; i < DNASize; i++)
		{
			cout << "Enter DNA thread " << i + 1 << ":" << endl << endl;
			cin >> input_dna[i];
		}
		suc = gen.setDNA(input_dna);
	}
}
void menu_functions::SetRNAMenu(genome& gen) {

	bool suc = false;
	int input;
	string input_RNA;
	while (!suc)
	{
		cout << "Entering RNA content:" << endl;
		cin >> input_RNA;
		suc = gen.setRNA(input_RNA);
	}
}
void menu_functions::GenomeCDOR(genome& gen) {
	system("cls");
	bool suc = gen.createDNAFromRNA();
	if (suc)
	{
		cout << "RNA:" << gen.GetRNA() << endl;
		cout << "create DNA was succesfull" << endl;
	}

	cout << "Press enter to continue" << endl;
	cin.get();
	cin.get();
}
void menu_functions::GenomeRNAShortJump(genome& gen) {
	system("cls");
	GenomePrintRNA(gen);
	char intended_nikol = ' ', replce_nikol = ' ';
	int time;
	cout << "Enter intended nikol" << endl;
	cin >> intended_nikol;
	cout << "Enter replcae nikol" << endl;
	cin >> replce_nikol;
	cout << "Enter the number of time you want RNA do jump" << endl;
	time = CinIntInput();
	bool suc = gen.RNAShortJump(intended_nikol, replce_nikol, time);
	if (suc)
	{
		cout << "RNA short jump was succesfull" << endl;
		GenomePrintRNA(gen);
	}
	cout << "Press enter to continue" << endl;
	cin.get();
	cin.get();
}
void menu_functions::GenomeDNAShortJump(genome& gen) {
	system("cls");
	GenomePrintDNA(gen);
	char intended_nikol = ' ', replce_nikol = ' ';
	int time;
	cout << "Enter intended nikol" << endl;
	cin >> intended_nikol;
	cout << "Enter replcae nikol" << endl;
	cin >> replce_nikol;
	cout << "Enter the number of time you want DNA do jump" << endl;
	time = CinIntInput();
	bool suc = gen.DNAShortJump(intended_nikol, replce_nikol, time);
	if (suc)
	{
		cout << "DNA short jump was succesfull" << endl;
		GenomePrintDNA(gen);
	}
	else
	{
		cout << "DNA short jump was'nt succesfull" << endl;
		GenomePrintDNA(gen);
	}
	cout << "Press enter to continue" << endl;
	cin.get();
	cin.get();
}
void menu_functions::GenomeRNALongJump(genome& gen) {
	system("cls");
	GenomePrintRNA(gen);
	string intended_thread, replace_thread;
	cout << "Enter intended thread " << endl;
	cin >> intended_thread;
	cout << "Enter replace thread " << endl;
	cin >> replace_thread;
	bool suc = gen.RNALongJump(intended_thread, replace_thread);
	if (suc)
	{
		cout << "RNA long jump was succesfull" << endl;
		GenomePrintRNA(gen);
	}
	cout << "Press enter to continue" << endl;
	cin.get();
	cin.get();
}
void menu_functions::GenomeDNALongJump(genome& gen) {
	system("cls");
	GenomePrintDNA(gen);
	string intended_thread, replace_thread;
	cout << "Enter intended thread " << endl;
	cin >> intended_thread;
	cout << "Enter replace thread " << endl;
	cin >> replace_thread;
	bool suc = gen.DNALongJump(intended_thread, replace_thread);
	if (suc)
	{
		string dna[DNASize];
		gen.GetDNA(dna);
		cout << "DNA long jump was succesfull" << endl;
		GenomePrintDNA(gen);
	}
	cout << "Press enter to continue" << endl;
	cin.get();
	cin.get();
}
void menu_functions::GenomeRNAReversJump(genome& gen) {
	system("cls");
	GenomePrintRNA(gen);
	string intended_thread;
	cout << "Enter intended thread " << endl;
	cin >> intended_thread;
	bool suc = gen.RNAReversJump(intended_thread);
	if (suc)
	{
		cout << "RNA revers jump was succesfull" << endl;
		GenomePrintRNA(gen);
	}
	cout << "Press enter to continue" << endl;
	cin.get();
	cin.get();
}
void menu_functions::GenomeDNAReversJump(genome& gen) {
	system("cls");
	GenomePrintDNA(gen);
	string intended_thread;
	cout << "Enter intended thread " << endl;
	cin >> intended_thread;
	bool suc = gen.DNAReversJump(intended_thread);
	if (suc)
	{
		cout << "DNA revers jump was succesfull" << endl;
		GenomePrintDNA(gen);
	}
	cout << "Press enter to continue" << endl;
	cin.get();
	cin.get();
}
void menu_functions::GenomePrintRNA(const genome& gen) {
	cout << "RNA: " << endl;
	cout << gen.GetRNA() << endl << endl;
}
void menu_functions::GenomePrintDNA(const genome& gen) {
	string dna[DNASize];
	gen.GetDNA(dna);
	cout << "DNA: " << endl;
	cout << dna[0] << endl;
	cout << dna[1] << endl << endl;
}
void menu_functions::CellPrintChromosomes(Cell input_cell) {
	for (int i = 0; i < input_cell.GetChromosomesCount(); i++)
	{
		cout << "chromosome " << i + 1 << ":" << endl;
		GenomePrintDNA(input_cell.GetChromosome(i));
	}
}


void menu_functions::CellMenu() {

	Cell cell;
	genome gen;
	bool back = false, suc = false;
	int input;

	system("cls");
	cout << "Enter the number of chromosomes" << endl;

	input = CinIntInput();

	for (int i = 0; i < input; i++)
	{
		cout << i + 1 << ": ";
		SetDNAMenu(gen);
		cell.PushBackChromosomesV(gen);
	}
	input = 0;
	while (!back)
	{
		system("cls");
		cout << "Cell Menu" << endl << endl;
		cout << "1:DNA short jump" << endl;
		cout << "2:DNA long jump" << endl;
		cout << "3:DNA revers jump" << endl;
		cout << "4:Find palindrom supllment" << endl;
		cout << "5:Cell death" << endl;
		cout << "6:Print cell" << endl;
		cout << "7:Add chromosomes" << endl;
		cout << "8:Remove chromosomes" << endl;
		cout << "0:Back to main menu" << endl << endl << endl << endl;

		input = CinIntInput();
		string y_or_n;
		system("cls");
		switch (input)
		{
		case 0:

			system("cls");
			cout << "if you go back all data will gone " << endl;
			cout << "are you sure you wanna leave? y-n " << endl;
			while (true)
			{
				cin >> y_or_n;
				if (y_or_n == "y")
				{
					back = true;
					break;
				}
				else if (y_or_n == "n")
				{
					break;
				}
				else
				{
					cout << "choose y:yes or n:no " << endl;
				}
			}
			break;
		case 1:
			CellDNAShortJump(cell);
			break;
		case 2:
			CellDNALongJump(cell);
			break;
		case 3:
			CellDNARversJump(cell);
			break;
		case 4:
			CellFindPalindromSupllment(cell);
			break;
		case 5:
			CellDeath(cell);
			break;
		case 6:
			CellPrintChromosomes(cell);
			cout << "Press enter to continue" << endl;
			cin.get();
			cin.get();
			break;
		case 7:
			CellAdd(cell);
			break;
		case 8:
			CellRemove(cell);
			break;
		default:
			break;
		}
	}


}
void menu_functions::CellDNAShortJump(Cell& cell) {

	if (cell.GetChromosomesCount() >= 1)
	{

		system("cls");
		char intended_nikol = ' ', replce_nikol = ' ';
		int time, index;

		CellPrintChromosomes(cell);

		cout << "Enter index of chromosome " << endl;
		index = CinIntInput();
		index--;
		system("cls");
		GenomePrintDNA(cell.GetChromosome(index));

		cout << "Enter intended nikol" << endl;
		cin >> intended_nikol;
		cout << "Enter replcae nikol" << endl;
		cin >> replce_nikol;
		cout << "Enter the number of time you want DNA do jump" << endl;
		time = CinIntInput();
		bool suc = cell.DNAShortJump(intended_nikol, replce_nikol, time, index);
		if (suc)
		{
			cout << "DNA short jump was succesfull" << endl;
			GenomePrintDNA(cell.GetChromosome(index));
		}
		else
		{
			cout << "DNA short jump was'nt succesfull" << endl;
			GenomePrintDNA(cell.GetChromosome(index));
		}
		cout << "Press enter to continue" << endl;
		cin.get();
		cin.get();
	}
	else
	{
		cout << "there is no chromosome to jump  " << endl << endl;
		cout << "Press enter to continue" << endl;
		cin.get();
		cin.get();
	}
}
void menu_functions::CellDNALongJump(Cell& cell) {

	if (cell.GetChromosomesCount() >= 1)
	{
		system("cls");
		string thread_1, thread_2;
		int index_1, index_2;

		CellPrintChromosomes(cell);

		cout << "Enter first index chromosome " << endl;
		index_1 = CinIntInput();
		cout << "Enter second index chromosome " << endl;
		index_2 = CinIntInput();
		index_1--;
		index_2--;
		system("cls");
		GenomePrintDNA(cell.GetChromosome(index_1));
		GenomePrintDNA(cell.GetChromosome(index_2));

		cout << "Enter first thread" << endl;
		cin >> thread_1;
		cout << "Enter second thread" << endl;
		cin >> thread_2;
		bool suc = cell.DNALongJump(thread_1, thread_2, index_1, index_2);
		if (suc)
		{
			cout << "DNA long jump was succesfull" << endl;
			GenomePrintDNA(cell.GetChromosome(index_1));
			GenomePrintDNA(cell.GetChromosome(index_2));
		}
		else
		{
			cout << "DNA long jump was'nt succesfull" << endl;
			GenomePrintDNA(cell.GetChromosome(index_1));
			GenomePrintDNA(cell.GetChromosome(index_2));
		}
		cout << "Press enter to continue" << endl;
		cin.get();
		cin.get();
	}
	else
	{
		cout << "there is no chromosome to jump  " << endl << endl;
		cout << "Press enter to continue" << endl;
		cin.get();
		cin.get();
	}
}
void menu_functions::CellDNARversJump(Cell& cell) {

	if (cell.GetChromosomesCount() >= 1)
	{
		system("cls");
		string intended_subthread;
		int  index;

		CellPrintChromosomes(cell);

		cout << "Enter index of chromosome " << endl;
		index = CinIntInput();
		index--;
		system("cls");
		GenomePrintDNA(cell.GetChromosome(index));

		cout << "Enter intended subthread" << endl;
		cin >> intended_subthread;

		bool suc = cell.DNAReversJump(intended_subthread, index);
		if (suc)
		{
			cout << "DNA revers jump was succesfull" << endl;
			GenomePrintDNA(cell.GetChromosome(index));
		}
		else
		{
			cout << "DNA revers jump was'nt succesfull" << endl;
			GenomePrintDNA(cell.GetChromosome(index));
		}
		cout << "Press enter to continue" << endl;
		cin.get();
		cin.get();
	}
	else
	{
		cout << "there is no chromosome to jump  " << endl << endl;
		cout << "Press enter to continue" << endl;
		cin.get();
		cin.get();
	}
}
void menu_functions::CellFindPalindromSupllment(const Cell& cell) {

	if (cell.GetChromosomesCount() >= 1)
	{
		system("cls");
		cout << "all palindroms of all chromosomes :" << endl;
		bool suc = cell.FindPalindromSupllment();

		if (suc)
		{
			cout << endl << "Finding palindroms was succesfull" << endl;
		}
		cout << "Press enter to continue" << endl;
		cin.get();
		cin.get();
	}
	else
	{
		cout << "there is no chromosome to find  " << endl << endl;
		cout << "Press enter to continue" << endl;
		cin.get();
		cin.get();
	}
}
void menu_functions::CellDeath(Cell& cell) {

	if (cell.GetChromosomesCount() >= 1)
	{
		system("cls");
		cout << "all dead cells :" << endl;
		bool suc = cell.Death();

		if (suc)
		{
			cout << "cell dieing was succesfull" << endl;
		}
		else
		{
			cout << "cell dieing was'nt succesfull" << endl;
		}
		cout << "Press enter to continue" << endl;
		cin.get();
		cin.get();
	}
	else
	{
		cout << "there is no chromosome to find  " << endl << endl;
		cout << "Press enter to continue" << endl;
		cin.get();
		cin.get();
	}
}
void menu_functions::CellAdd(Cell& cell) {

	genome gen;
	bool back = false, suc = false;
	int input;

	system("cls");
	cout << "Enter the number of chromosomes you wanna add" << endl;
	input = CinIntInput();
	for (int i = 0; i < input; i++)
	{
		cout << i + 1 << ":" << endl;
		SetDNAMenu(gen);
		cell.PushBackChromosomesV(gen);
	}

	system("cls");
	cout << "Adiing chromosome was succesfull " << endl << endl;
	CellPrintChromosomes(cell);
	cout << "Press enter to continue" << endl;
	cin.get();
	cin.get();
}
void menu_functions::CellRemove(Cell& cell) {

	if (cell.GetChromosomesCount() >= 1)
	{
		int input;
		system("cls");

		CellPrintChromosomes(cell);
		cout << "Enter intended chromosome : " << endl;

		while (true)
		{
			input = CinIntInput();
			input--;

			if (0 <= input && input < cell.GetChromosomesCount())
			{
				cell.RemoveChromosome(input);

				system("cls");
				cout << "Removing chromosome was succesfull " << endl << endl;
				CellPrintChromosomes(cell);
				break;
			}
			else
			{
				cout << "chose 1 to " << cell.GetChromosomesCount() << endl;
			}
		}
		cout << "Press enter to continue" << endl;
		cin.get();
		cin.get();
	}
	else
	{
		cout << "there is no chromosome to find  " << endl << endl;
		cout << "Press enter to continue" << endl;
		cin.get();
		cin.get();
	}
}


