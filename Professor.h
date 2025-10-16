#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>

class Professor {
public: 
    Professor(int nusp, string nome, string unidade);
    virtual ~Professor();

    int getNusp();
    string getNome();
    string getUnidade();
private: 
    int nusp = 0;
    string nome = "";
    string unidade = "";
};

#endif