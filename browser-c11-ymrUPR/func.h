//Haader file con prototipos de funciones a ser usadas por el programa

#ifndef FUNC_H
#define FUNC_H


#include <iostream>
#include <stack>

using namespace std;

void Go(stack<string>&currWeb, stack<string>&prevWeb, string &input);

void Back(stack<string>&currWeb, stack<string>&prevWeb);

void Forward(stack<string>&currWeb, stack<string>&prevWeb);

char choice();

#endif
