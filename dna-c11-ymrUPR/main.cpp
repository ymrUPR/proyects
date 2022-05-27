

#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <queue>
#include <iostream>
#include <fstream>
#include "functions.cpp"
#include "protos.cpp"

using namespace std;


// Given the reference to a non-empty string, returns a vector
// of the strings that were separated by ","
// Example input: "name,AGATC,AATG,TATC"
// Output: {"name","AGATC","AATG","TATC"}. <-- a vector with 4 strings

int main(int argc, char **argv) {

  // Check if we have all the command line arguments
  if (argc != 3)  {
    cout << "Usage: " << argv[0]
         << " {database filename}  {dna filename} " << endl;
    exit(-1);
  }

  // Put the arguments into strings because I feel safer
  // doing so
  string databaseFilename(argv[1]);
  string dnaFilename(argv[2]);

  ifstream dbaseFile(databaseFilename);
  if (dbaseFile.is_open() == false) {
    cout << "Cannot open " << databaseFilename << endl;
    exit(-1);
  }

  ifstream dnaFile(dnaFilename);
  if (!dnaFile.is_open()) {
    cout << "Cannot open " << dnaFilename << endl;
    exit(-1);
  }

  //Variable, map and vector definitions

  map<vector<int>, string> dbMap; //Crear variable para aguantar el mapa del databaseFile.

  vector<string> templateVector; //Crear vector de strings para aguantar el template del databaseFile.

  string dnaSequence; //Crear string para aguantar la secuencia de DNA.

  //Functions in action.

  templateVector = templateExtractor(dbaseFile); //Llamar templateExtractor para extraer el template del databaseFile y guardarlo en el vector.

  dbMap = mapCreator(dbaseFile); //Llamar mapCreator para crear el mapa de todos los sospechosos dentro del databaseFile y guardarlo en el mapa.

  dnaSequence = dnaStringCreator(dnaFile); //Llamar dnaStringCreator para convertir la sequencia de DNA en un string y guardarlo.

  culpritFinder(dnaSequence, dbMap, templateVector); //Llamar la funcion culpritFinder para averiguar, si alguno, a quien le pertenece el DNA dentro del database usado.

}