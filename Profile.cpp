#include "Profile.h"

profile::profile()
{
	user_name = "Guest";
}

profile::profile(string name="Player 1"): user_name(name)
{
	loadingScores();
}

void profile::setP_Name(string n)
{
	user_name = n;
}

string profile::getP_Name()
{
	return user_name;
}

void profile::setBestS(int score)
{
	user_score.push_back(score);
}

int profile::getBestS()
{
	if (user_score.empty()) {
		return 0;
	}
	else {
		return user_score.back();
	}
}

vector<int> profile::getPrevBestScores()
{
	return user_score;
}

void profile::SortProfil(vector<int>)
{

}

vector<string> profile::getAllProfNames()
{
	vector <string> ProfileNames;
	ifstream file("Profiles.txt");
	if (file.is_open()) {
		string name;
		while (getline(file, name)) {
			ProfileNames.push_back(name);
		}
	}
}

void profile::loadingScores()
{
	ifstream file(user_name + ".txt");
	if (file.is_open()) {
		user_score.clear();
		int score;
		while (file >> score) {
			user_score.push_back(score);
		}
	}
}

void profile::SavingScores()
{
	ofstream file(user_name + ".txt");
	if (file.is_open()) {
		for (int score : user_score) {
			file << score << endl;
		}
	}
}
