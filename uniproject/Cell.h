#pragma once
#include "genome.h"
#include<vector>

class Cell : private genome
{
private:
	std::vector<genome> chromosomes;
	void SetChromosomeCount();
	//the number of chromosomes
	int chromosomes_count = 0;
protected:
public:
	Cell();
	Cell(std::vector<genome> input_chromosomes);
	//push back one chromosome to chromosomes with genome
	void PushBackChromosomesV(const genome& gen);
	//push back one chromosome to chromosomes with DNA
	void PushBackChromosomesV(std::string dna[DNASize]);

	void InsertChromosomesV(const genome&, int index);
	//get one chromosome by index
	genome GetChromosome(const int& index)const;
	//get all chromosomes
	std::vector<genome> GetChromosomes()const;

	void RemoveChromosome(const int &index);

	int GetChromosomesCount()const;
	bool Death();
	bool DNALongJump(const std::string& thread_1, const std::string& thread_2, const int& first_index, const int& second_index);
	bool DNAShortJump(const char& intended_nikols, const char& replaced_nikol, const int& num, const int& index);
	bool DNAReversJump(const std::string& Intended_thread, const int& index);
	bool FindPalindromSupllment()const;


};

