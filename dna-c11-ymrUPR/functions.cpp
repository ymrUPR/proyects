#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <queue>
#include <iostream>
#include <fstream>
#include "protos.cpp"

using namespace std;

// Given the reference to a non-empty string, returns a vector
// of the strings that were separated by ","
// Example input: "name,AGATC,AATG,TATC"
// Output: {"name","AGATC","AATG","TATC"}. <-- a vector with 4 strings
vector<string> split(const string &st) {
  vector<string> v;
  int stFrom = 0;
  int stTo  = st.find(",",stFrom);
  while (stTo >= 0) {
    v.push_back(st.substr(stFrom, stTo - stFrom));
    stFrom = stTo + 1;
    stTo  = st.find(",",stFrom);
  }
  if (stTo != st.length()-1) v.push_back(st.substr(stFrom));
  return v;
}

//Mis funciones:


/*The getName function will recieve a vector with the contents of a file.
It's sole purpose is to find the name inside itself, extract it and erase
that memory spot so that the vector won't have an empty element. It will return 
a name it extracted.*/
string getName(vector<string>&v1){
  string name = v1[0];
  v1.erase(v1.begin());
  return name;
}

/*The vectorChanger function will recieve a vector of strings that are numbers.
It's sole purpose is to create a new vector (this time holding ints) to "change"
the contents of the vector from strings to ints. It will return this new vector
of ints it created.  */
vector<int> vectorChanger(vector<string> &v1){
  vector<int> changedVector;
  for(int i = 0; i < v1.size(); i++)
    changedVector.push_back(stoi(v1[i]));

  return changedVector;
}

/*The templateExtractor function will recieve an ifstream type variable used to
access and read the specified database file. It's sole purpose is to create a vector
of strings that will hold the template given in the beginning of the database file.
Example = for small.csv, the template's vector will hold ["name", "AGAT", "AATG" ,"TATC"]
Since it only needs the first line of whichever database file it recieves, it will only
ever recieve content from the first line of the file. It will return this templateVector
of strings.*/
vector<string> templateExtractor(ifstream &databaseFile){
   if (databaseFile.is_open() == false){
    cout << "Error when opening specified file. " << endl;
    exit(-1);
  }

  vector<string> templateVector;
  string st;
  databaseFile >> st;
  return templateVector = split(st);
}


/*The function mapCreator is a peculiar function I've created for this program. This function will recieve an ifstream variable used to access and read the specified file. This function will create a map that will hold each person inside the database file as a value by calling the getName function and it will get the vector of that person's DNA sequence repetition through the usage of the vectorChanger function, thus using the vector as the map's key. It will return the map of all the data in the database.*/
map<vector<int>, string> mapCreator(ifstream &databaseFile){
  if (databaseFile.is_open() == false){
    cout << "Error when opening specified file. " << endl;
    exit(-1);
  }

  int count = 0;
  map<vector<int>, string> mapa;

  while(databaseFile.eof() == false){
    string st;
    databaseFile >> st;
    vector<string> tempVector = split(st);

    string name = getName(tempVector);
    vector<int> keyVector = vectorChanger(tempVector);

    mapa[keyVector] = name;
  } 
  databaseFile.clear();
  databaseFile.seekg(0);
  return mapa;
}

/*The function dnaStringCreator will recieve an ifstream variable to access and read through the specified DNA sequence file. It's purpose is to create a string that will hold the entirety of the DNA sequence to facilitate iterating through each element in the DNA. It will return the string that holds the DNA sequence. */
string dnaStringCreator(ifstream &dnaFile){
  if (dnaFile.is_open() == false){
    cout << "Error when opening specified file. " << endl;
    exit(-1);
    }
  string content;
  dnaFile >> content;
  dnaFile.clear();
  dnaFile.seekg(0);
  return content;
}

/*The function consecutivitySearch will recieve two things: The DNA sequence string returned by the dnaStringCreator function and the substring it is tasked with locating in the dna sequence. The task for this function is to find the MAXIMUM amount of times the substring repeats itself in a consecutive matter. It does this by splitting the dna string in chunks of equal size to the substring and comparing if the chunk contains the same elements as the substring. If it does, it will increase the consecutivity counter by 1 and move the i the same amount as the size of the substring (in order to move on to the next chunk). If it is NOT the same, it will update the max consecutives if the consCount is greater than the maxCons, reset the consCount and increase i by 1, in order to move on to exactly 1 element in order not to skip through any element in the string. Lastly before returning, it will check if consCount still holds a value after exiting the for loop for one last chance at updating the maxCons just in case consCount is greater. It will return an int maxCons.  */
int consecutivitySearch(string &dna, string str){
  int maxCons = 0;
  int consCount = 0;

  for(int i = 0; i < dna.size();){
    if(str == dna.substr(i, str.size())){
      consCount++;
      i += str.size();
    }
    else{
      maxCons = maxCons < consCount ? consCount : maxCons;
      consCount = 0;
      i++;
    }
    
  }
  maxCons = maxCons < consCount ? consCount : maxCons;
  return maxCons;
}

/*The function culpritFinder will recieve three things: the string containing the DNA sequence, the map created by mapCreator with all the information of a database and a vector of strings containing the template of the database. This function's purpose is to find (if any) to whom the DNA sequence belongs to. It does this by creating a culpritVector that will hold the amount of times each substring repeats itself inside the DNA sequence. This will be figured out by looping through the templateVector (which contains all the substrings to be found) and pushing back whatever consecutivitySearch returns as the max amount of consecutive repeats it found for the substring it was given. Lastly, it will check if it finds a value inside the map by using the culpritVector as a key. If it is in the map, then we've found the owner of the DNA, otherwise, that means the culprit is still out there... */
void culpritFinder(string &dna, map<vector<int>, string> &mapa, vector<string>&v1){

  vector<int> culpritVector;
  for(int i = 1; i < v1.size(); i++){
    culpritVector.push_back(consecutivitySearch(dna, v1[i]));
  }

  cout << "CULPRIT VECTOR: ";
  for(int i = 0; i < culpritVector.size(); i++){
    cout << culpritVector[i] << ", ";
  }
  cout << endl;
  if(mapa.count(culpritVector))
    cout << "The culprit is: " << mapa[culpritVector] << endl;
  else
    cout << "Not in the database! "<< mapa[culpritVector] << endl;
}