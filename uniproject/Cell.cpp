#include "Cell.h"
#include <iostream>
#include <algorithm>

void Cell::SetChromosomeCount()
{
	chromosomes_count = chromosomes.size();
}

Cell::Cell() {
	SetChromosomeCount();
}

Cell::Cell(std::vector<genome> input_chromosomes)
{
	chromosomes = input_chromosomes;
	SetChromosomeCount();
}

void Cell::PushBackChromosomesV(const genome& gen)
{
	chromosomes.push_back(gen);
	SetChromosomeCount();
}

void Cell::PushBackChromosomesV(std::string dna[DNASize])
{
	genome gen;
	//che the input DNA
	bool suc = gen.setDNA(dna);
	if (suc)
	{
		chromosomes.push_back(gen);
		SetChromosomeCount();
	}
}

void Cell::InsertChromosomesV(const genome& gen, int index)
{
	if (index < chromosomes_count)
	{
		chromosomes[index]= gen;
		SetChromosomeCount();
	}
}


genome Cell::GetChromosome(const int& index)const
{
	if (index < chromosomes_count)
	{
		return chromosomes[index];
	}
}

std::vector<genome> Cell::GetChromosomes()const
{
	return chromosomes;
}

void Cell::RemoveChromosome(const int& index)
{
	if (index<chromosomes_count)
	{
		chromosomes.erase(chromosomes.begin() + index);
		SetChromosomeCount();
	}
}

int Cell::GetChromosomesCount()const
{
	return chromosomes_count;
}

bool Cell::Death()
{
	//if returnd true, chromosome gonna die 
	bool output = false;
	int unsupplements;
	int AT_supplements, GC_supplements;
	std::string dna[DNASize];

	for (int i = 0; i < chromosomes_count; i++)
	{
		//set nom of unsupplements
		unsupplements = WrongDNASupplmentNum(chromosomes[i]);
		if (unsupplements > 5)
		{
			chromosomes[i].GetDNA(dna);
			output = true;
			std::cout << dna[0] << std::endl;
			std::cout << dna[1] << std::endl;
			std::cout << "died" << std::endl << std::endl;
			//delete died chromosome
			chromosomes.erase(chromosomes.begin() + i);
			i--;
			//change chromosome count
			SetChromosomeCount();
			continue;
		}
		//cheking AT supplements vs GC supplements
		AT_supplements = chromosomes[i].SupplementNumByChar('A');
		GC_supplements = chromosomes[i].SupplementNumByChar('G');
		if (GC_supplements == 0)
		{
			GC_supplements = 1;
		}
		if (AT_supplements / GC_supplements > 3)
		{
			output = true;
			chromosomes[i].GetDNA(dna);
			std::cout << dna[0] << std::endl;
			std::cout << dna[1] << std::endl;
			std::cout << "died" << std::endl << std::endl;
			//delete died chromosome
			chromosomes.erase(chromosomes.begin() + i);
			i--;
			//change chromosome count
			SetChromosomeCount();
		}
	}
	return output;
}

bool Cell::DNALongJump(const std::string& thread_1, const std::string& thread_2, const int& first_index, const int& second_index)
{
	std::string dna[DNASize];
	//if returned true long jump eas succesfull
	bool suc = false;

	//chek input index to be not bigger than chromosome length
	if (first_index < chromosomes_count && second_index < chromosomes_count)
	{
		//first jump
		chromosomes[first_index].DNALongJump(thread_1, thread_2);
		chromosomes[first_index].GetDNA(dna);

		//second jump
		chromosomes[second_index].DNALongJump(thread_2, thread_1);
		chromosomes[second_index].GetDNA(dna);
		suc = true;
		return suc;
	}
	else
	{
		std::cout << "out of chromosomes range " << std::endl;
	}
	return suc;
}

bool Cell::DNAShortJump(const char& Intended_nikol, const char& replaced_nikol, const int& num, const int& index)
{
	std::string dna[DNASize];
	//if returned true short jump eas succesfull
	bool suc = false;

	//chek input index to be not bigger than chromosome length
	if (index < chromosomes_count)
	{
		chromosomes[index].GetDNA(dna);
		suc = chromosomes[index].DNAShortJump(Intended_nikol, replaced_nikol, num);

		return suc;
	}
	else
	{
		std::cout << "out of chromosomes range " << std::endl;
	}
	return suc;
}

bool Cell::DNAReversJump(const std::string& intended_subthread, const int& index)
{
	std::string dna[DNASize];
	//if returned true short jump eas succesfull
	bool suc = false;

	//chek input index to be not bigger than chromosome length
	if (index < chromosomes_count)
	{
		chromosomes[index].GetDNA(dna);
		suc = chromosomes[index].DNAReversJump(intended_subthread);
		std::cout << dna[0] << std::endl;
		std::cout << dna[1] << std::endl;

		return suc;
	}
	else
	{
		std::cout << "out of chromosomes range " << std::endl;
	}
	return suc;
}

bool Cell::FindPalindromSupllment()const
{
	std::string dna[DNASize];
	std::string subthread, reversed_subthread = "";
	bool suc = false;
	//a is the index of kromozomes vector
	for (int a = 0; a < chromosomes_count; a++)
	{
		chromosomes[a].GetDNA(dna);

		std::cout << std::endl << "in chromosome " << a + 1 << std::endl;
		// for first threaad
		for (int i = 0; i < dna[0].length() - 2; i++)
		{
			// i is index of begning
			for (int y = 3; y < dna[0].length() - i; y++)
			{
				//y is length of subthread
				//pick subthread from DNA thread
				subthread = dna[0].substr(i, y);
				reversed_subthread = genome::Reverser(subthread);
				if (subthread == reversed_subthread)
				{
					suc = true;
					std::cout << subthread << std::endl;
				}
			}
		}
		//for second thread
		for (int i = 0; i < dna[1].length() - 2; i++)
		{

			// i is index of begning
			for (int y = 3; y < dna[1].length() - i; y++)
			{
				//y is length of subthread
				//pick subthread from DNA thread
				subthread = dna[1].substr(i, y);
				reversed_subthread = genome::Reverser(subthread);
				if (subthread == reversed_subthread)
				{
					suc = true;
					std::cout << subthread << std::endl;
				}
			}
		}
	}
	return suc;
}
