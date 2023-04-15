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


};

