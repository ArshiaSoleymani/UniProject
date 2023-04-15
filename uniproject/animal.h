#pragma once
#include "Cell.h"
class animal : public Cell
{
private:

	Cell cell;
	//get the percent of DNA nikols similarity
	float PercentageOfNikolsSimilarity(std::string DNA_1[2], std::string DNA_2[2], char intended_nikol);
	//get the percent of DNA point to point similarity
	float PercentageOfGeneralSimilarity(std::string DNA_1[2], std::string DNA_2[2]);
	//return a random num with maximom
	int RandomWithMax(const int& max)const;

public:

	Cell GetCell()const;
	Cell* GetCellPtr();
	animal(Cell input_cell);
	float GeneticSimilarityPercentage(animal& input_animal);
	friend bool operator==(animal l, animal r);
	friend animal operator+(animal l, animal r);
	bool Death();
	animal AsexualREpurduction()const;
};

