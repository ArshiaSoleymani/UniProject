#include "genome.h"
#include <iostream>
#include <string>
#include<algorithm>

void genome::GetDNA(std::string s[DNASize])const
{
	copy(std::begin(DNA), std::end(DNA), s);
}

std::string genome::GetRNA()const
{
	return RNA;
}

bool genome::setRNA(const std::string& rna)
{

	//if be true a char out of{A,T,G,C} etered
	bool invaled_value = NikolCheker(ToUpperST(rna));

	if (!invaled_value)
	{

		if (rna != "")
		{
			RNA = ToUpperST(rna);
			std::cout << "RNA set success" << std::endl;
			return !invaled_value;
		}
		else
		{
			std::cout << "invaled value" << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "invaled value" << std::endl;
		return !invaled_value;
	}
}
bool genome::setDNA(const std::string dna[DNASize]) {

	//if be true a char out of{A,T,G,C} etered
	bool invaled_value = false;

	for (int i = 0; i < DNASize; i++)
	{
		invaled_value = NikolCheker(ToUpperST(dna[i]));
		if (invaled_value)
		{
			break;
		}
	}

	if (!invaled_value)
	{
		if (dna[0] != "" || dna[1] != "")
		{
			//both thread should have same length
			if (dna[0].length() > dna[1].length())
			{
				std::cout << "second thread is to short " << std::endl;
				return false;
			}
			else if (dna[0].length() < dna[1].length())
			{
				std::cout << "second thread is to long " << std::endl;
				return false;
			}
			else if (dna[0].length() == dna[1].length())
			{
				for (int i = 0; i < 2; i++)
				{
					DNA[i] = ToUpperST(dna[i]);
				}
				std::cout << "DNA set success" << std::endl;
				return true;
			}
		}
		else
		{
			std::cout << "invaled value" << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "invaled value" << std::endl;
		return false;
	}
}
bool genome::createDNAFromRNA() {

	std::string dna_from_rna[DNASize];
	bool suc = false;

	if (RNA != "")
	{
		dna_from_rna[0] = RNA;
		dna_from_rna[1] = CreateThreadSupplement(RNA);
		std::cout << dna_from_rna[0] << std::endl;
		std::cout << dna_from_rna[1] << std::endl;
		return suc;
	}
	return suc;
}
bool genome::RNAShortJump(const char& Intended_nikol, const char& replaced_nikol, const int& num) {

	bool suc = false;
	//counting replacing times
	int counter = 0;
	std::string new_RNA = RNA;

	//checking all char for jump
	if (toupper(Intended_nikol) == 'A' || toupper(Intended_nikol) == 'T' || toupper(Intended_nikol) == 'C' || toupper(Intended_nikol) == 'G')
	{
		if (toupper(replaced_nikol) == 'A' || toupper(replaced_nikol) == 'T' || toupper(replaced_nikol) == 'C' || toupper(replaced_nikol) == 'G')
		{
			for (int i = 0; i < RNA.length(); i++)
			{
				if (counter == num)
				{
					break;
				}
				//replcae wnated nikol in Intended nikol place
				if (RNA.at(i) == toupper(Intended_nikol))
				{
					new_RNA[i] = toupper(replaced_nikol);
					counter++;
				}
			}
		}

	}
	if (counter == 0)
	{
		return suc;
	}
	else
	{
		setRNA(new_RNA);

		suc = true;
		return suc;
	}
}
bool genome::DNAShortJump(const char& Intended_nikol, const char& replaced_nikol, const int& num) {

	bool suc = false;
	int counter = 0;
	std::string newDNA[DNASize];
	copy(std::begin(DNA), std::end(DNA), newDNA);


	if (toupper(Intended_nikol) == 'A' || toupper(Intended_nikol) == 'T' || toupper(Intended_nikol) == 'C' || toupper(Intended_nikol) == 'G')
	{
		if (toupper(replaced_nikol) == 'A' || toupper(replaced_nikol) == 'T' || toupper(replaced_nikol) == 'C' || toupper(replaced_nikol) == 'G')
		{
			//check thread 1
			for (int i = 0; i < DNA[0].length(); i++)
			{
				//counting replacing times
				if (counter == num)
				{
					break;
				}
				//checking all char for jump
				if (DNA[0].at(i) == toupper(Intended_nikol))
				{
					newDNA[0][i] = toupper(replaced_nikol);
					newDNA[1][i] = GetSupplement(toupper(replaced_nikol));
					counter++;
				}
			}
			//check thread 2
			for (int i = 0; i < DNA[1].length(); i++)
			{
				//counting replacing times
				if (counter == num)
				{
					break;
				}
				//checking all char for jump
				if (DNA[1].at(i) == toupper(Intended_nikol))
				{
					newDNA[1][i] = toupper(replaced_nikol);
					newDNA[0][i] = GetSupplement(toupper(replaced_nikol));
					counter++;
				}
			}
		}
	}
	if (counter != 0)
	{
		setDNA(newDNA);
		std::cout << counter;
		std::cout << " short jump succesful" << std::endl;

		suc = true;
		return suc;
	}
	return suc;
}
bool genome::RNALongJump(const  std::string& Intended_subthread, const  std::string& replaced_subthread) {

	std::string new_rna = RNA;
	bool suc = false;

	//find index of Intended nikols first char in RNA 
	size_t found = RNA.find(ToUpperST(Intended_subthread));
	//cheack dont be empty
	if (found != std::string::npos) {
		new_rna = replace(new_rna, ToUpperST(replaced_subthread), found);
		setRNA(ToUpperST(new_rna));

		suc = true;
		return suc;
	}
	else
	{
		std::cout << "cant find this thread" << std::endl;
	}
	return suc;
}
bool genome::DNALongJump(const  std::string& Intended_subthread, const  std::string& replaced_subthread)
{
	bool suc = false;
	std::string newDNA[DNASize];
	copy(std::begin(DNA), std::end(DNA), newDNA);

	//for thread 1
		//find index of Intended nikols first char in RNA 
	size_t found = DNA[0].find(ToUpperST(Intended_subthread));
	//cheack dont be empty
	if (found != std::string::npos) {

		newDNA[0] = replace(newDNA[0], ToUpperST(replaced_subthread), found);
		newDNA[1] = replace(newDNA[1], CreateThreadSupplement(ToUpperST(replaced_subthread)), found);
		setDNA(newDNA);

		suc = true;
		return suc;
	}
	else
	{
		//for thead 2
	//find index of Intended nikols first char in RNA 
		found = DNA[1].find(ToUpperST(Intended_subthread));
		//cheack dont be empty
		if (found != std::string::npos) {

			newDNA[1] = replace(newDNA[1], ToUpperST(replaced_subthread), found);
			newDNA[0] = replace(newDNA[0], CreateThreadSupplement(ToUpperST(replaced_subthread)), found);
			setDNA(newDNA);

			suc = true;
			return suc;
		}
		else
		{
			std::cout << "cant find this thread" << std::endl;
		}
	}
	return suc;
}
bool genome::RNAReversJump(const  std::string& Intended_subthread) {

	bool suc = false;
	std::string new_rna = RNA;

	//find index of Intended nikols first char in RNA 
	size_t found = RNA.find(ToUpperST(Intended_subthread));
	//cheack dont be empty
	if (found != std::string::npos) {

		new_rna = replace(new_rna, Reverser(ToUpperST(Intended_subthread)), found);
		setRNA(ToUpperST(new_rna));

		suc = true;
		return suc;
	}
	else
	{
		std::cout << "can not find this thread" << std::endl;
	}
	return suc;
}
bool genome::DNAReversJump(const  std::string& Intended_subthread)
{
	bool suc = false;
	std::string newDNA[DNASize];
	copy(std::begin(DNA), std::end(DNA), newDNA);

	//for first thread
		//find index of Intended nikols first char in RNA 
	size_t found = DNA[0].find(ToUpperST(Intended_subthread));
	//cheack dont be empty
	if (found != std::string::npos) {
		newDNA[0] = replace(newDNA[0], Reverser(ToUpperST(Intended_subthread)), found);
		newDNA[1] = replace(newDNA[1], CreateThreadSupplement(Reverser(ToUpperST(Intended_subthread))), found);
		setDNA(newDNA);

		suc = true;
		return suc;
	}
	else
	{
		//for second thread
		found = DNA[1].find(ToUpperST(Intended_subthread));
		if (found != std::string::npos) {

			newDNA[1] = replace(newDNA[1], Reverser(ToUpperST(Intended_subthread)), found);
			newDNA[0] = replace(newDNA[0], CreateThreadSupplement(Reverser(ToUpperST(Intended_subthread))), found);
			setDNA(newDNA);

			suc = true;
			return suc;
		}
		else
		{
			std::cout << "can not find this thread" << std::endl;
		}
	}
	return suc;
}


int genome::WrongDNASupplmentNum(const genome& gen)
{
	int counter = 0;

	for (int i = 0; i < gen.DNA[0].length(); i++)
	{
		if (gen.DNA[1][i] != GetSupplement(gen.DNA[0][i]))
		{
			counter++;
		}
	}
	return counter;
}
int genome::SupplementNumByChar(const char& input)
{
	int counter = 0;
	for (int i = 0; i < DNA[0].length(); i++)
	{
		if (DNA[1][i] == GetSupplement(DNA[0][i]))
		{
			if (DNA[0][i] == input || DNA[0][i] == GetSupplement(input))
			{
				counter++;
			}
		}
	}
	return counter;
}


bool genome::NikolCheker(std::string thread) {

	for (int i = 0; i < thread.length(); i++)
	{
		if (thread[i] != 'A' && thread[i] != 'T' && thread[i] != 'C' && thread[i] != 'G')
		{
			return true;
		}
	}
	return false;
}
std::string genome::CreateThreadSupplement(std::string thread) {

	char pics;
	std::string out_thread;
	for (int i = 0; i < thread.length(); i++)
	{
		pics = GetSupplement(thread.at(i));
		out_thread += pics;
	}
	return out_thread;
}
char genome::GetSupplement(char a) {
	char output = ' ';
	switch (a)
	{
	case 'A':
		output = 'T';
		break;
	case 'T':
		output = 'A';
		break;
	case 'G':
		output = 'C';
		break;
	case 'C':
		output = 'G';
		break;
	default:
		output = 'E';
		break;
	}
	return output;
}
std::string  genome::Reverser(const std::string& input)const {
	std::string output;
	for (int i = (input.length() - 1); i >= 0; i--)
	{
		output += input.at(i);
	}
	return output;
}
std::string  genome::replace(std::string main, std::string replace, int index) {

	std::string output = main;
	for (int i = index; i < replace.length() + index; i++)
	{
		output[i] = replace[i - index];
	}
	return output;
}
std::string  genome::ToUpperST(std::string input) {
	std::string output = input;
	std::transform(output.begin(), output.end(), output.begin(), toupper);
	return output;
}

