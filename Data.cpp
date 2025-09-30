#include "Data.h"
#include <iostream>

using namespace std;

Data::Data(int mes, int ano) : 
    mes(mes), ano(ano){
    }
Data::~Data(){}

int get Data::getMes(){
    return mes;
}

int Data::getAno(){
    return ano;
}
