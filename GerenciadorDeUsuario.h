#ifndef GERENCIADORDEUSUARIO_H
#define GERENCIADORDEUSUARIO_H 

#include "Aluno.h"
#include "Professor.h"


class GerenciadorDeUsuario{ 
private: 
    int maximo;
    Aluno** vetorAlunos;
    Professor** vetorProfessores;
    
public:
    GerenciadorDeUsuario(int maximo);
    virtual ~GerenciadorDeUsuario();

    bool adicionarAluno(Aluno* a);
    bool adicionarProfessor(Professor* a);

    Aluno* getAluno(int nusp);
    Professor* getProfessor(int nusp);

    Aluno** getAlunos(int& quantidade);
    Professor** getProfessores(int& quantidade);
};

#endif