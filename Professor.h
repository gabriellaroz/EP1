#ifndef PROFESSOR_H
#define PROFESSOR_H

class Professor {
public: 
    Professor(int nusp, string nome, string unidade);
    virtual ~Professor();

    string getNome();
    int getNusp();
    string getUnidade();

private: 

 int nusp;
 string nome;
 string unidade;

}

#endif