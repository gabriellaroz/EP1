#include "Aluno.h"
#include "Data.h"
#include "Bolsa.h"
#include <iostream>
#include <string>

using namespace std;

Aluno::Aluno(int nusp, string nome, int maximo): 
nusp(nusp), nome(nome), maximo(maximo), quantidade(0){
bolsas = new Bolsa*[maximo];
}

Aluno::~Aluno(){
    int i;
    for(i = 0; i < quantidade; i++){
        delete bolsas[i];
    }
    delete[] bolsas;
}

int Aluno::getNusp(){
    return nusp;
}

string Aluno::getNome(){
    return nome;
}
bool Aluno::temConflitoDeBolsas(Data* inicio1, Data* fim1, Data* inicio2, Data* fim2) {
    bool intervalo1 = false;
    bool intervalo2 = false;

    if (fim1->getAno() < inicio2->getAno()){
        intervalo1 = true;
    } 
    else if (fim1->getAno() == inicio2->getAno() && fim1->getMes() < inicio2->getMes()){
        intervalo1 = true;
    }

    if (fim2->getAno() < inicio1->getAno()){
        intervalo2 = true;
    } 
    else if (fim2->getAno() == inicio1->getAno() && fim2->getMes() < inicio1->getMes()){
        intervalo2 = true;
    }

    if (intervalo1 || intervalo2) {
        return false;
    }
    return true;
}

bool Aluno::adicionar(Bolsa* bolsa){
    int i;
    if (quantidade >= maximo){
        return false;
    }

    for (i = 0; i < quantidade; i++){
        if (temConflitoDeBolsas(bolsa->getInicio(), bolsa->getFim(), bolsas[i]->getInicio(), bolsas[i]->getFim())){
            return false;
        }
    }
    bolsas[quantidade] = bolsa;
    quantidade++;
    return true;
}

Bolsa** Aluno::getBolsas(){
    return bolsas;
}

int Aluno::getQuantidadeDeBolsas(){
    return quantidade;
}

double Aluno::getValor(Data* data){
    int i;
    for (i = 0; i < quantidade; i++){
        Bolsa* b = bolsas[i];
        bool depoisInicio = (data->getAno() > b->getInicio()->getAno()) || (data->getAno() == b->getInicio()->getAno() && data->getMes() >= b->getInicio()->getMes());
        bool antesFim = (data->getAno() < b->getFim()->getAno()) || (data->getAno() == b->getFim()->getAno() && data->getMes() <= b->getFim()->getMes());

        if (depoisInicio && antesFim){
            return b->getValor(data);
        }
    }
    return 0;
}
 




