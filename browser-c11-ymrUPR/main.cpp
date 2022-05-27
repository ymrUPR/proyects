//Yadiel Mercado Rivera
//801 19 5597

#include "func.h"
#include <iostream>
#include <stack>

using namespace std;


const string redBegin = "\x1B[31m";
const string redEnd = "\033[0m";
const string greenBegin = "\x1B[32m";
const string greenEnd = "\033[0m";


int main() {
  bool flag = 1;  //Variable booleana para usarse en el while loop 

  stack<string> currWeb, prevWeb; 
  //currWeb es el main stack que se utilizara para leer las paginas de web a las que se estan accediendo mientras que prevWeb esta para guardar aquellas paginas accedidas al llamarse las funciones Back y Forward

  string input, visitor; 
  //input es la variable que aceptara como ingreso el "website" a visitar y la variable visitor es una variable placeholder por si el main stack esta vacio y evitar problemas con el programa, su funcion es mostrar cual pagina esta siendo visitada.

  cout << "Bienvenido al simulador de browser.";
  while(flag){

    if(currWeb.empty())
      visitor = "nowhere";

    cout << endl <<"-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
    cout << "Currently visiting: " << visitor << endl;
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;

    switch(choice()){ //Switch statement para cada seleccion. Back, forward y go verifican si el stack esta vacio ya para no acceder un elemento nulo.
      
      case 'G': 
        cout << "Enter website: ";
        cin >> input;
        Go(currWeb, prevWeb, input);
        visitor = currWeb.empty() ? "nowhere" : currWeb.top();
        break;
      
      case 'B': 
        Back(currWeb, prevWeb);
        visitor = currWeb.empty() ? "nowhere" : currWeb.top();
        break;

      case 'F':
        Forward(currWeb, prevWeb);
        visitor = currWeb.empty() ? "nowhere" : currWeb.top();
        break;

      case 'Q':
        flag = 0; //Cambio de variable flag para terminar el loop/programa.
        break;
    }

  }
  return 0;
} 