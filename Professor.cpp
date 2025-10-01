#include "Professor.h"
#include <iostream>

using namespace std; 

Professor::Professor(int nusp, string nome, string unidade): 
 nusp(nusp), nome(nome), unidade(unidade){
}

~Professor::Professor(){}

string getNome(){
   return nome; 
}

int getNusp(){
   return nusp;
}

string getUnidade(){
   return unidade;
}
 