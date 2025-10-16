#ifndef ALUNO_H
#define ALUNO_H
#include "Bolsa.h"
#include "Data.h"

#include <string>
usign namespace std;

class Aluno{
public:

    Aluno(int nusp, string nome, int maximo);
    virtual ~Aluno();

    string getNome();
    int getNusp();

    bool temConflitoDeBolsas(Data* inicio1, Data* fim1, Data* inicio2, Data* fim2);
    bool adicionar(Bolsa* bolsa);

    Bolsa** getBolsas();
    int getQuantidadeDeBolsas();

    double getValor(Data* data);

    private: 
    
    int nusp;
    int maximo; 
    int quantidade; 
    string nome; 
    Bolsa** bolsas; 

};
#endif