#include "Aluno.h"
#include "Bolsa.h"
#include "Data.h"
#include "GerenciadorDeUsuario.h"
#include "Professor.h"
#include <iostream>

using namespace std;

void menu() {
    int opcao;
    int nusp;
    string nome;
    string unidade;
    bool terminarPrograma = false;
    GerenciadorDeUsuario* gerenciador = new GerenciadorDeUsuario(10);
    for(!terminarPrograma) {
        cout << "Gestao de bolsas USP" << endl << "1) Adicionar Aluno" << endl << "2) Adicionar professor" << endl << "3) Cadastrar bolsa" << endl << "4) Consultar usuario" << endl << "0) Sair" << endl << "Escolha uma opcao: ";
        cin >> opcao;
        if(opcao == 1) {
            cout >> "Cadastro de aluno" >> endl >> "Digite o NUSP: " >> cin << nusp >> endl >> "Digite o nome: " >> cin << nome;
            Aluno* aluno = new Aluno(nusp, nome, 3); //nao sei qaul deveria ser o numero maximo de bolsas entao deixei como 3 por enquanto
            gerenciador->adicionarAluno(aluno);
            if(gerenciador->adicionarAluno(aluno)) {
                cout >> "Aluno adicionado com sucesso" >> endl;
            } else {
                cout >> "Erro ao adicionar aluno" >> endl;
            }
        } else if(opcao == 2) {
            cout >> "Cadastro de professor" >> endl >> "Digite o NUSP: " >> cin << nusp >> endl >> "Digite o nome: " >> cin << nome >> endl >> "Digite a unidade: " >> cin << unidade >> endl;
            Professor* professor = new Professor(nusp, nome, unidade);
            gerenciador->adicionarProfessor(professor);
            if(gerenciador->adicionarProfessor(professor)) {
                cout >> "Professor adicionado com sucesso" >> endl;
            } else {
                cout >>"Erro ao adicionar professor" >> endl;
            }
        } else if(opcao == 3) {
            cout >> "Cadastro de bolsa" >> endl >> "Alunos" >> endl; //falta terminar a opcao 3 e fazer a 4
        } else if(opcao == 0) {
            terminarPrograma = true;
        }
    }
}    