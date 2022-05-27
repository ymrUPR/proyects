//CPP file con las implementaciones de las funciones a ser usadas en el programa
#include "func.h"

//La funcion Go tomara como input 3 cosas: currWeb, prevWeb y el input del usuario.
//Primero, verificara con el uso de rand si se conectara a un website. Si logra conectarse tomara los elementos (si alguno) que solo se pueden acceder con Forward y los eliminara con el proposito de hacer esos "websites" inaccesibles.
//Luego, hara push el website al que fue ingresado por el usuario al main stack.
//De no ser posible la conexion, no hara nada de esto.
void Go(stack<string>&currWeb, stack<string>&prevWeb, string &input){ 
  cout << "Requesting " << input << endl;
  if(rand()%10 < 7){
      while(!prevWeb.empty())
        prevWeb.pop();
    cout << "Connected succesfully!" << endl;
    currWeb.push(input);
  }
  else
    cout << "Couldn't connect!" << endl;
}

//La funcion Back, tomando como input los dos stacks creados en main, verificara si currWeb esta vacio, ya que su intencion es tomar el string del top y pasarlo al prevWeb stack, para poder ser possible reaccesar esa pagina con el uso de la funcion Forward. 
//Luego de hacer push ese string, le hara pop del currWeb stack.
void Back(stack<string>&currWeb, stack<string>&prevWeb){
  if (currWeb.empty())
    return;

  prevWeb.push(currWeb.top());
  currWeb.pop();
}

//La funcion Forward, tomando como input los dos stacks creados en main, verificara si el stack prevWeb esta vacio, ya para no accidentalmente accesar un string que no exista. El proposito de esta es mover el webpage del stack de prevWeb hacia el stack de currWeb que siempre sera la pagina accesada proxima al top de currWeb.
//Luego, le hara pop del prevWeb stack.
void Forward(stack<string>&currWeb, stack<string>&prevWeb){
  if (prevWeb.empty())
    return;
      
  currWeb.push(prevWeb.top());
  prevWeb.pop();
}

//La funcion choice tiene el proposito de verificar la seleccion del menu de web del usuario. Verificara si el input es algo fuera de las opciones del menu y le hara loop hasta que reciba algo del menu. 
//Hara return la opcion de forma de un caracter.
char choice(){
  char cho;
  while(cho != 'G' && cho != 'B' && cho != 'F' && cho != 'Q'){

    cout << "Opciones: " << "(G)o, (B)ack, (F)orward and (Q)uit"<< endl;
    cout << "Entra su opcion: ";
    cin >> cho;
    cho = toupper(cho);

  }
  return cho;
}