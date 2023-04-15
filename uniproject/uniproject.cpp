// uniproject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "animal.h"
using namespace std;
int main()
{
	bool suc = false;

	genome obj;
	std::vector<genome>kromozoms;
	string DNA[2] = { "aaggttccggttaa","ttccaaggccaatt" };
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "ccggccggccgg";
	DNA[1] = "ggccggccggcc";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "ttaattaattaa";
	DNA[1] = "aattaattaatt";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "ttggaaggccaa";
	DNA[1] = "aaccttccggtt";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "aaggaaggaagg";
	DNA[1] = "ttccttccttcc";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "ccggttggccgg";
	DNA[1] = "ggccaaccggcc";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "ccaaggttggcc";
	DNA[1] = "ggttccaaccgg";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "aattaattaatt";
	DNA[1] = "ttaattaattaa";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "ttggaaggccaa";
	DNA[1] = "aaccttccggtt";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "ggttggttggtt";
	DNA[1] = "ccaaccaaccaa";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "gtacgctacgat";
	DNA[1] = "gcatgcatggca";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "aaccaaccaacc";
	DNA[1] = "ttggttggttgg";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}

	animal anim(kromozoms);

	kromozoms.clear();

	DNA[0] = "ccggttggccgg";
	DNA[1] = "ggccaaccggcc";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "ggttaaccggtt";
	DNA[1] = "ccaattggccaa";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "ttaattaattaa";
	DNA[1] = "aattaattaatt";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "ttggaaggccaa";
	DNA[1] = "aaccttccggtt";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "aaggaaggaagg";
	DNA[1] = "ttccttccttcc";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "ggttaaccaatt";
	DNA[1] = "ccaattggttaa";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "ccaaggttggcc";
	DNA[1] = "ggttccaaccgg";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "ttttaaaatttt";
	DNA[1] = "aaaattttaaaa";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "ttggaaggccaa";
	DNA[1] = "aaccttccggtt";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "ggttggttggtt";
	DNA[1] = "ccaaccaaccaa";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "aattaattaatt";
	DNA[1] = "ttaattaattaa";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	DNA[0] = "aaccaaccaacc";
	DNA[1] = "ttggttggttgg";
	suc = obj.setDNA(DNA);
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	animal anim2(kromozoms);


	anim.Death();
	cout << anim.kromozomes[1].DNA[0];
	if (suc)
	{
		kromozoms.push_back(obj);
	}
	//animal child = anim+anim2;
	//bool aa = anim == anim2 ? true : false;
	//cout << aa<<endl;
	//cout << child.GeneticSimilarityPercentage(anim2)<<endl;
	//cout << child.GeneticSimilarityPercentage(anim2) << endl;


	//Cell obj2(kromozoms);
	//suc = obj2.Death();
	//if (!suc)
	//{
	//cout << endl << endl << endl << asd << endl << endl << aa;
	//}


}

