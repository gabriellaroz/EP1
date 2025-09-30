#ifndef ALUNO_H
#define ALUNO_H

class Aluno{
public:
    Aluno(int nusp, string nome, int maximo);
    virtual ~Aluno();

    string getNome();
    int getNusp();

    bool temConflitoDeBolsas(int)
}
#endif