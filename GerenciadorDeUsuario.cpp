#include "GerenciadorDeUsuario.h"
#include "Aluno.h"
#include "Professor.h"
#include <iostream>
#include <string>

using namespace std;

GerenciadorDeUsuario::GerenciadorDeUsuario(int maximo) : maximo(maximo) {
    this->maximo = maximo;

    vetorAlunos = new Aluno*[maximo];
    vetorProfessores = new Professor*[maximo];

    for (int i = 0; i < maximo; i++) {
        vetorAlunos[i] = nullptr;
        vetorProfessores[i] = nullptr;
    }
}

GerenciadorDeUsuario::~GerenciadorDeUsuario() {
    int i;
    for (i = 0; i < (this->maximo); i++) {
        delete vetorAlunos[i];
        delete vetorProfessores[i];
    }
    delete[] vetorAlunos;
    delete[] vetorProfessores;
}


bool GerenciadorDeUsuario::adicionarAluno(Aluno* a) {
  int i, j;
    for (i = 0; i < maximo; i++) {
        if ((vetorAlunos[i] != nullptr && vetorAlunos[i]->getNusp() == a->getNusp()) ||
            (vetorProfessores[i] != nullptr && vetorProfessores[i]->getNusp() == a->getNusp())) {
            return false;
        }
    }
    for (j = 0; j < maximo; j++) {
        if (vetorAlunos[j] == nullptr) {
            vetorAlunos[j] = a;
            return true;
        }
    }
    return false; 
}

bool GerenciadorDeUsuario::adicionarProfessor(Professor* a) {
    // Verifica se já existe aluno ou professor com o mesmo NUSP
    for (int i = 0; i < maximo; i++) {
        if ((vetorProfessores[i] != nullptr && vetorProfessores[i]->getNusp() == a->getNusp()) ||
            (vetorAlunos[i] != nullptr && vetorAlunos[i]->getNusp() == a->getNusp())) {
            return false;
        }
    }

    // Adiciona o professor na primeira posição livre
    for (int j = 0; j < maximo; j++) {
        if (vetorProfessores[j] == nullptr) {
            vetorProfessores[j] = a;
            return true;
        }
    }

    return false; // sem espaço
}

Aluno* GerenciadorDeUsuario::getAluno(int nusp) {
    for (int i = 0; i < maximo; i++) {
        if (vetorAlunos[i] != nullptr && vetorAlunos[i]->getNusp() == nusp) {
            return vetorAlunos[i];
        }
    }
    return nullptr;
}

Professor* GerenciadorDeUsuario::getProfessor(int nusp) {
    for (int i = 0; i < maximo; i++) {
        if (vetorProfessores[i] != nullptr && vetorProfessores[i]->getNusp() == nusp) {
            return vetorProfessores[i];
        }
    }
    return nullptr;
}

Aluno** GerenciadorDeUsuario::getAlunos(int& quantidade) {
    quantidade = 0;
    for (int i = 0; i < maximo; i++) {
        if (vetorAlunos[i] != nullptr) {
            quantidade++;
        }
    }
    return vetorAlunos;
}

Professor** GerenciadorDeUsuario::getProfessores(int& quantidade) {
    quantidade = 0;
    for (int i = 0; i < maximo; i++) {
        if (vetorProfessores[i] != nullptr) {
            quantidade++;
        }
    }
    return vetorProfessores;
}