#include "Data.h"

Data::Data(int mes, int ano) : 
    mes(mes), ano(ano){
}

Data::~Data(){}

int Data::getMes(){
    return mes;
}

int Data::getAno(){
    return ano;
}
