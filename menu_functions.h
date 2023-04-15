#pragma once
#include<vector>
class genome;
class Cell;
class animal;
class menu_functions
{
public:
	//menu of genome part
	static void GenomeMenu();
	//set dna for menu
	static void SetDNAMenu(genome& gen);
	//set rna for menu
	static void SetRNAMenu(genome& gen);
	//show the percent of genetic similarity
	static void GenomeCDOR(genome& gen);
	static void GenomeRNAShortJump(genome& gen);
	static void GenomeDNAShortJump(genome& gen);
	static void GenomeRNALongJump(genome& gen);
	static void GenomeDNALongJump(genome& gen);
	static void GenomeRNAReversJump(genome& gen);
	static void GenomeDNAReversJump(genome& gen);
	static void GenomePrintRNA(const genome& gen);
	static void GenomePrintDNA(const genome& gen);
	//print all chromosomes of cell
	static void CellPrintChromosomes(Cell input_cell);
	static void CellMenu();
	static void CellDNAShortJump(Cell& cell);
	static void CellDNALongJump(Cell& cell);
	static void CellDNARversJump(Cell& cell);
	static void CellFindPalindromSupllment(const Cell& cell);
	static void CellDeath(Cell& cell);
	static void CellAdd(Cell& cell);
	static void CellRemove(Cell& cell);
	static void AnimalMenu();
	static void AnimalGSP(std::vector<animal>& animals);
	static void AnimalCompireType(const std::vector<animal>& animals);
	static void AnimalAsexualRepurduction(const std::vector<animal>& animals);
	static void AnimalSexualRepurduction(const std::vector<animal>& animals);
	static void AnimalCellDeath(std::vector<animal>& animals);
	static void AnimalPrint(const std::vector<animal>& animals);
	static void AnimalAdd(std::vector<animal>& animals);
	static void AnimalRemove(std::vector<animal>& animals);
	static void AnimalAddChromosome(std::vector<animal>& animals);
	static void AnimalReamoveChromosome(std::vector<animal>& animals);

	//cin a string and convet it to int
	static int CinIntInput();
};

