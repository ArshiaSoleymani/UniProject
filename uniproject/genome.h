#ifndef GENOME_HPP
#define GENOME_HPP
#include<string>

#define DNASize 2
class genome
{
protected:

	//revers a string
	std::string Reverser(const std::string& input)const;
	//the number of wrong DNA supplments
	int WrongDNASupplmentNum(const genome& gen);


private:

	//main fields
	std::string RNA;
	std::string DNA[DNASize];
	//check thread to have not any char out of {A,T,G,C}
	bool NikolCheker(std::string thread);
	//create the supplement of any thread
	std::string CreateThreadSupplement(std::string thread);
	//create the supplement of any char
	char GetSupplement(char a);
	//replace a string or in another string
	std::string replace(std::string main, std::string replace, int index);
	std::string ToUpperST(std::string input);
public:

	void GetDNA(std::string s[DNASize])const;
	std::string GetRNA()const;
	bool setRNA(const std::string& rna);
	bool setDNA(const std::string dna[DNASize]);
	bool createDNAFromRNA();
	bool RNAShortJump(const char& Intended_nikol, const char& replaced_nikol, const int& num);
	bool DNAShortJump(const char& Intended_nikol, const char& replaced_nikol, const int& num);
	bool RNALongJump(const std::string& Intended_subthread, const std::string& replaced_subthread);
	bool DNALongJump(const std::string& Intended_subthread, const std::string& replaced_subthread);
	bool RNAReversJump(const std::string& Intended_subthread);
	bool DNAReversJump(const std::string& Intended_subthread);
	//the number of right supplement by a nikol {A,T,G,C}
	int SupplementNumByChar(const char& input);
};


#endif // !GENOME_HPP

