#include "GerenciadorDeUsuario.h"
#include "Aluno.h"
#include "Professor.h"
#include <iostream>

using namespace std;

GerenciadorDeUsuario::GerenciadorDeUsuario(int maximo): 
maximoDeUsuarios(maximo){

~GerenciadorDeUsuario(){}
}

bool GerenciadorDeUsuario::adicionarAluno(Aluno* a){}

bool GerenciadorDeUsuario::adicionarProfessor(Professor* a){}

Aluno* GerenciadorDeUsuario::getAluno(int nusp){}

Professor* GerenciadorDeUsuario::getProfessor(int nusp){}

Aluno** GerenciadorDeUsuario::getAlunos(int& quantidade){} 

Professor** GerenciadorDeUsuario::getProfessores(int& quantidade){}
