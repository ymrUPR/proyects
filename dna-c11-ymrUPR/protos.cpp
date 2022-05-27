#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

vector<string> split(const string &st);

//Mis prototipos:

string getName(vector<string> &v1);

vector<int> vectorChanger(vector<string> &v1);

vector<string> templateExtractor(ifstream &databaseFile);

map<vector<int>, string> mapCreator(ifstream &databaseFile);

string dnaStringCreator(ifstream &dnaFile);

int consecutivitySearch(string &dna, string);

void culpritFinder(string &dna, map<vector<int>, string> &mapa, vector<string> &v1);