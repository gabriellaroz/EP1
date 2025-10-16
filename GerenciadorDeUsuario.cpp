#include "GerenciadorDeUsuario.h"
#include "Aluno.h"
#include "Professor.h"
#include <iostream>
#include <string>

using namespace std;

GerenciadorDeUsuario::GerenciadorDeUsuario(int maximo) : maximo(maximo) {
    Aluno** vetorAlunos[this->maximo - 1];
    Professor** vetorProfessores[this->maximo - 1];   
    for (int i = 0, i < (this->maximo ), i++) {
        vetorAlunos[i] = nullptr;
        vetorProfessores[i] = nullptr;
    } 
}

GerenciadorDeUsuario::~GerenciadorDeUsuario() {
    for (int i = 0, i < (this->maximo), i++) {
        delete vetorAlunos[i];
        delete vetorProfessores[i];
    }
    delete[] vetorAlunos;
    delete[] vetorProfessores;
}


bool GerenciadorDeUsuario::adicionarAluno(Aluno* a) {
    for (int i = 0; i < (this->maximo); i++) {
        if (vetorAlunos[i] != nullptr && vetorAlunos[i]->nusp == a->nusp) {
            return false;
        }
    }
    for (int j = 0, j < (this->maximo), j++) {
        if (vetorAlunos[j] == nullptr) {
            vetorAlunos[j] = a;
            return true;
        }
    }
    return false;
}

bool GerenciadorDeUsuario::adicionarProfessor(Professor* a) {
    for (int i = 0; i < (this->maximo); i++) {
        if (vetorAluno[i] != nullptr && vetorProfessores[i]->nusp == a->nusp) {
            return false;
        }
    }
    for (int j = 0, j < (this->maximo), j++) {
        if (vetorProfessores[j] == nullptr) {
            vetorProfessores[j] = a;
            return true;
        }
    }
    return false;
}

Aluno* GerenciadorDeUsuario::getAluno(int nusp) {
    for (int i = 0; i < (this->maximo); i++) {
        if (vetorAlunos[i] != nullptr && vetorAlunos[i]->nusp == nusp) {
            return vetorAlunos[i];
        }
    }
    return nullptr;
}

Professor* GerenciadorDeUsuario::getProfessor(int nusp) {
    for (int i = 0; i < (this->maximo); i++) {
        if (vetorProfessores[i] != nullptr && vetorProfessores[i]->nusp == nusp) {
            return vetorProfessores[i];
        }
    }
    return nullptr;
}

Aluno** GerenciadorDeUsuario::getAlunos(int& quantidade) {
    int numDeAlunos = 0;
    Aluno** alunosRegistrados = new Aluno*[quantidade];
    for (int i = 0; i < (this->maximo); i++) {
        if (vetorAlunos[i] != nullptr) {
            alunosRegistrados[numDeAlunos] = vetorAlunos[i];
            numDeAlunos++;
        }
    }
    this->quantidade = numDeAlunos;
    return alunosRegistrados;
} 

Professor** GerenciadorDeUsuario::getProfessores(int& quantidade){
    int numDeProfessores = 0;
    Professor** professoresRegistrados = new Professor*[quantidade];
    for (int i = 0; i <= (this->maximo - 1); i++) {
        if (vetorProfessores[i] != nullptr) {
            professoresRegistrados[numDeProfessores] = vetorProfessores[i];
            numDeProfessores++;
        }
    }
    this->quantidade = numDeProfessores;
    return professoresRegistrados;
}

