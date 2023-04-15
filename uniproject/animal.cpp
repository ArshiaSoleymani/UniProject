#include "animal.h"
#include "genome.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <math.h>

Cell animal::GetCell()const 
{
	return cell;
}

Cell* animal::GetCellPtr()
{
	return &cell;
}
animal::animal(Cell input_cell) {
	cell = input_cell;
}
float animal::GeneticSimilarityPercentage(animal& input_animal)
{
	std::string input_dna[DNASize], self_dna[DNASize];
	// nikols_similarity_percentage, gneral_similarity_percentage, final_similarity_percentage, total_similarity_percentage
	float  NSP = 0.0f, GSP = 0.0f, FSP = 0.0f, TSP = 0.0f;
	//nikols_similarity_factor, general_similarity_factor
	int  NSF, GSF;

	NSF = 1;
	GSF = 3;

	int length = input_animal.cell.GetChromosomesCount() <= cell.GetChromosomesCount() ? input_animal.cell.GetChromosomesCount() : cell.GetChromosomesCount();
	for (int i = 0; i < length; i++)
	{
		input_animal.cell.GetChromosome(i).GetDNA(input_dna);
		cell.GetChromosome(i).GetDNA(self_dna);
		//nikols_similarity_percentage
		NSP = (PercentageOfNikolsSimilarity(input_dna, self_dna, 'A') + PercentageOfNikolsSimilarity(input_dna, self_dna, 'T') + PercentageOfNikolsSimilarity(input_dna, self_dna, 'G') + PercentageOfNikolsSimilarity(input_dna, self_dna, 'C')) / 4;

		//gneral_similarity_percentage
		GSP = PercentageOfGeneralSimilarity(input_dna, self_dna);

		//final_similarity_percentage
		if ((NSP * NSF + GSP * GSF) != 0)
		{
			TSP += (NSP * NSF + GSP * GSF) / (GSF + NSF);
		}
	}

	FSP = TSP / length;

	return FSP;
}
bool animal::Death()
{
	bool suc = cell.Death();

	return suc;
}
animal animal::AsexualREpurduction()const
{
	float sevenpercent_of_Ksize;
	int static_chromosomes_size;
	//2n cell
	Cell n2_cell = cell.GetChromosomes();
	Cell new_cell = cell.GetChromosomes();

	bool right_child = false;
	while (!right_child)
	{
		for (int i = 0; i < cell.GetChromosomesCount(); i++)
		{
			n2_cell.PushBackChromosomesV(cell.GetChromosome(i));
		}
		//calculate how much index should be static
		sevenpercent_of_Ksize = float(cell.GetChromosomesCount()) * 5.0f / 10.0f;//70% of shoud be like pass
		//edtimate num of static chromosomes
		static_chromosomes_size = std::ceil(sevenpercent_of_Ksize);

		for (int i = 0; i < cell.GetChromosomesCount() - static_chromosomes_size; i++)
		{
			//creat 2 random number
			int rand_index, rand_index2;
			rand_index = RandomWithMax(new_cell.GetChromosomesCount());
			rand_index2 = RandomWithMax(n2_cell.GetChromosomesCount());
			//insert the random index of 2n Cell to the random index of new cell
			new_cell.InsertChromosomesV(n2_cell.GetChromosome(rand_index2), rand_index);

		}
		if (animal(new_cell) == animal(cell))
		{
			right_child = true;
		}
	}
	return animal(new_cell);
}
float  animal::PercentageOfNikolsSimilarity(std::string DNA_1[2], std::string DNA_2[2], char intended_nikol) {
	//number of nikols found
	float DNA_1_found = 0, DNA_2_found = 0;
	float output = 0.0f;
	for (int i = 0; i < DNASize; i++)
	{
		DNA_1_found += std::count(DNA_1[i].begin(), DNA_1[i].end(), intended_nikol);

		DNA_2_found += std::count(DNA_2[i].begin(), DNA_2[i].end(), intended_nikol);

	}
	if (DNA_2_found != 0 && DNA_1_found)
	{
		output = DNA_1_found > DNA_2_found ? (DNA_2_found / DNA_1_found) : (DNA_1_found / DNA_2_found) * 100;
	}

	return output;

}

float animal::PercentageOfGeneralSimilarity(std::string DNA_1[2], std::string DNA_2[2]) {
	float similarity_counter = 0.0f;
	float dnas_length = 0.0f;
	for (int i = 0; i < DNASize; i++)
	{
		dnas_length = int(DNA_1[i].length()) >= int(DNA_2[i].length()) ? DNA_2[i].length() : DNA_1[i].length();
		for (int y = 0; y < dnas_length; y++)
		{
			if (DNA_1[i][y] == DNA_2[i][y])
			{
				similarity_counter++;
			}
		}
	}
	float output = similarity_counter / (dnas_length * 2) * 100.0f;
	return output;
}

bool operator==(animal l, animal r) {
	if (l.GeneticSimilarityPercentage(r) >= 70.0f && l.cell.GetChromosomesCount() == r.cell.GetChromosomesCount())
	{
		return true;
	}
	return false;
}
animal operator+(animal l, animal r)
{
	if (l == r)
	{
		animal l_child = l.AsexualREpurduction();
		animal r_child = r.AsexualREpurduction();
		std::vector<genome> new_chromosomes;
		while (true)
		{
			if (l_child.cell.GetChromosomesCount() % 2 == 0)
			{
				new_chromosomes = l.cell.GetChromosomes();
				for (int i = 0; i < l.cell.GetChromosomesCount() / 2; i++)
				{
					new_chromosomes[l.RandomWithMax(l.cell.GetChromosomesCount())] = r.cell.GetChromosomes()[r.RandomWithMax(r.cell.GetChromosomesCount())];
				}
				animal child(new_chromosomes);
				if (child == r && child == l)
				{
					std::cout << "child created succesfuly" << std::endl;
					return child;
				}
			}
		}
	}
	else
	{
		std::cout << "they are'nt same type " << std::endl;
		return animal(Cell());
	}

}
int animal::RandomWithMax(const int& max)const {
	srand((unsigned)time(NULL));
	int output = rand() % max;
	return output;
}

