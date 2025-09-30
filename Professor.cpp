#include "Professor.h"
#include <iostream>

using namespace std; 

Professor::Professor(int nusp, string nome, string unidade): 
 nusp(nusp), nome(nome), unidade(unidade){
 }

 ~Professor::Professor(){}

 string Professor::getNome(){
    return nome; 
 }

 int Professor::getNusp(){
    return nusp;
 }

 string Professor::getUnidade(){
    return unidade;
 }
 