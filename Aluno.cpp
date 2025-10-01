#include "Aluno.h"
#include "Data.h"
#include <iostream>

using namespace std;

Aluno::Aluno(int nusp, string nome, int maximo): 
nusp(nusp), nome(nome), maximo(maximo), quantidade(0){}

Aluno::~Aluno(){}

int Aluno::getNusp(){
    return nusp;
}

string Aluno::getNome(){
    return nome;
}
bool Aluno::temConflitoDeBolsas(Data* inicio1, Data* fim1, Data* inicio2, Data* fim2){
    bool intervalo1 = false;
    bool intervalo2 = false;

    
    if (fim1->getAno() < inicio2->getAno()){
        intervalo1 = true;

    }else if (fim1->getAno() == inicio2->getAno() && fim1->getMes() < inicio2->getMes()){
        intervalo1 = true;
    }

    if (fim2->getAno() < inicio1->getAno()){
        intervalo2 = true;

    } else if (fim2->getAno() == inicio1->getAno() && fim2->getMes() < inicio1->getMes()){
        intervalo2 = true;
    }

    if (intervalo1 || intervalo2){
        return false;
    }
    return true;
}

bool Aluno::adicionar(Bolsa* bolsa) {
  
}


Bolsa** Aluno::getBolsas(){
    return bolsas;
}

double Aluno::getValor(Data* data) {
}






