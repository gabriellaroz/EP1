#include "GerenciadorDeUsuario.h"
#include "Aluno.h"
#include "Professor.h"
#include <iostream>

using namespace std;

GerenciadorDeUsuario::GerenciadorDeUsuario(int maximo) : maximo(maximo) {
    Aluno *vetorAlunos[maximo - 1];
    Professor *vetorProfessores[maximo - 1];   
    for (int i = 0, i <= (maximo - 1), i++) {
        vetorAlunos[i] = nullptr;
        vetorProfessores[i] = nullptr;
    } 
}

GerenciadorDeUsuario::~GerenciadorDeUsuario() {
    for (int i = 0, i <= (maximo - 1), i++) {
        delete vetorAlunos[i];
        delete vetorProfessores[i];
    }
    delete vetorAlunos;
    delete vetorProfessores;
}


bool GerenciadorDeUsuario::adicionarAluno(Aluno* a) {
    for (int i = 0, i <= (maximo - 1), i++) {
        if (vetorAlunos[i] != nullptr && vetorAlunos[i]->nusp == a->nusp) {
            return false;
        }
    }
    for (int j = 0, j <= (maximo - 1), j++) {
        if (vetorAlunos[j] == nullptr) {
            vetorAlunos[j] = a;
            return true;
        }
    }
    return false;
}

bool GerenciadorDeUsuario::adicionarProfessor(Professor* a) {
    for (int i = 0, i <= (maximo - 1), i++) {
        if (vetorAluno[i] != nullptr && vetorProfessores[i]->nusp == a->nusp) {
            return false;
        }
    }
    for (int j = 0, j <= (maximo - 1), j++) {
        if (vetorProfessores[j] == nullptr) {
            vetorProfessores[j] = a;
            return true;
        }
    }
    return false;
}

Aluno* GerenciadorDeUsuario::getAluno(int nusp) {
    for (int i = 0, i <= (maximo - 1), i++) {
        if (vetorAlunos[i] != nullptr && vetorAlunos[i]->nusp == nusp) {
            return vetorAlunos[i];
        }
    }
    return nullptr;
}

Professor* GerenciadorDeUsuario::getProfessor(int nusp) {
    for (int i = 0, i <= (maximo - 1), i++) {
        if (vetorProfessores[i] != nullptr && vetorProfessores[i]->nusp == nusp) {
            return vetorProfessores[i];
        }
    }
    return nullptr;
}

Aluno** GerenciadorDeUsuario::getAlunos(int& quantidade) {
    int numDeAlunos = 0
    for (int i = 0, i <= (maximo - 1), i++) {
        if (vetorAlunos[i] != nullptr) {
            numDeAlunos = numDeAlunos + 1;
        }
    }
    quantidade = numDeAlunos;
    return *vetorAlunos;
} 

Professor** GerenciadorDeUsuario::getProfessores(int& quantidade){
    int numDeProfessores = 0
    for (int i = 0, i <= (maximo - 1), i++) {
        if (vetorProfessores[i] != nullptr) {
            numDeProfessores = numDeProfessores + 1;
        }
    }
    quantidade = numDeProfessores;
    return *vetorProfessores;
}

