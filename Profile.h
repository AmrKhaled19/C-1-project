#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


class profile
{
private:
	string user_name;
	vector <int> user_score;
	vector <string> p_names;

public:
	profile();
	profile(string name);

	//Accessors and Mutators for each of the: profile names, Bestscores;
	void setP_Name(string n);
	string getP_Name();

	void setBestS(int score);
	int getBestS();

	//for storing the old best score;
	vector <int>getPrevBestScores();
	void SortProfil(vector<int>);

	//To get the previous scores names and saving them;
	static vector <string> getAllProfNames();
	void loadingScores();
	void SavingScores();
};

