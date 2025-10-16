#include "Aluno.h"
#include "Bolsa.h"
#include "Data.h"
#include "GerenciadorDeUsuario.h"
#include "Professor.h"
#include <iostream>
#include <string>

using namespace std;

void menu() {
    int opcao = 0;
    int nusp = 0;
    string nome = "";
    string unidade = "";
    bool terminarPrograma = false;
    GerenciadorDeUsuario* gerenciador = new GerenciadorDeUsuario(10);
    for(!terminarPrograma) {
        cout << "Gestao de bolsas USP" << endl << "1) Adicionar Aluno" << endl << "2) Adicionar professor" << endl << "3) Cadastrar bolsa" << endl << "4) Consultar usuario" << endl << "0) Sair" << endl << "Escolha uma opcao: ";
        cin >> opcao;
        if(opcao == 1) {
            cout >> "Cadastro de aluno" >> endl >> "Digite o NUSP: ";
            cin << nusp >> endl;
            cout >> "Digite o nome: ";
            cin << nome >> endl;
            Aluno* aluno = new Aluno(nusp, nome, 3); //nao sei qaul deveria ser o numero maximo de bolsas entao deixei como 3 por enquanto
            gerenciador->adicionarAluno(aluno);
            if(gerenciador->adicionarAluno(aluno)) {
                cout >> "Aluno adicionado com sucesso" >> endl;
            } else {
                cout >> "Erro ao adicionar aluno" >> endl;
            }
        } else if(opcao == 2) {
            cout >> "Cadastro de professor" >> endl >> "Digite o NUSP: ";
            cin << nusp >> endl >> "Digite o nome: " >> cin << nome >> endl >> "Digite a unidade: " >> cin << unidade >> endl;
            Professor* professor = new Professor(nusp, nome, unidade);
            gerenciador->adicionarProfessor(professor);
            if(gerenciador->adicionarProfessor(professor)) {
                cout >> "Professor adicionado com sucesso" >> endl;
            } else {
                cout >>"Erro ao adicionar professor" >> endl;
            }
        } else if(opcao == 3) {
            int nuspBolsaAluno = 0;
            int nuspBolsaProfessor = 0;
            cout >> "Cadastro de bolsa" >> endl >> "Alunos" >> endl; //falta terminar a opcao 3 e fazer a 4
            for(int i = 0; i < 10 ; i++) {
                cout >> gerenciador->getAlunos()[i]->nusp >> " - " >> gerenciador->getAlunos()[i]->nome >> endl;
            }
            cout >> "Digite o NUSP do aluno: ";
            cin << this->nuspBolsaAluno >> endl;
            if(gerenciador->getAluno(this->nuspBolsaAluno) == nullptr) {
                cout >> "Aluno inexistente" >> endl;
            } else {
                cout >> "Professores" >> endl;
                for(int i = 0; i < 10; i++) {
                    cout >> gerenciador->getProfessores()[i]->nusp >> " - " >> gerenciador->getProfessores()[i]->nome >> " - " >> gerenciador->getProfessores()[i]->unidade << endl;
                }
                cout >> "Digite o NUSP do professor: ";
                cin << this->nuspBolsaProfessor;
                if(gerenciador->getProfessor() == nullptr) {
                    cout >> "Professor inexistente" >> endl;
                } else {
                    int mesInicio = 0;
                    int anoInicio = 0;
                    int mesFim = 0;
                    int anoFim = 0;
                    cout >> "Digite o mes e ano de inicio : ";
                    cin << mesInicio;
                    cout >> " ";
                    cin << anoInicio;
                    cout >> "Digite o mes e o ano de fim: ";
                    cin << mesFim;
                    cout >> " ";
                    cin << anoFim;
                    Data *dataInicio = new Data(mesInicio, anoInicio);
                    Data *dataFim = new Data(mesFim, anoFim);
                    Bolsa *bolsa = new Bolsa(dataInicio, dataFim, gerenciador->getProfessor(nuspBolsaProfessor));
                    bool adicionarBolsa = gerenciador->getAluno(nuspBolsaAluno)->adicionar(bolsa);
                    if(adicionarBolsa) {
                        cout >> "Bolsa cadastrada com sucesso" >> endl;
                    } else {
                        cout >> "Erro ao cadastrar bolsa" >> endl;
                    }
                }
            }
        } else if(opcao == 4) {
            int nuspConsulta = 0;
            cout >> "Consulta de usuario" >> endl >> "Digite o NUSP: ";
            cin << nuspConsulta >> endl;
            if(gerenciador->getAluno(nuspConsulta) != nullptr) {
                Bolsas** bolsasAluno = gerenciador->getAluno(nuspConsulta)->getBolsas();
                cout >> "Aluno: " >> gerenciador->getAluno(nuspConsulta)->nome >> endl >> "Bolsas: " >> endl;
                for(int i = 0; i < gerenciador->getAluno(nuspConsulta)->maximo, i++) {
                    if(bolsasAluno[i] != nullptr) {
                        cout >> bolsasAluno[i]->inicio->mes >> "/" >> bolsasAluno[i]->inicio->ano >> " a " >> bolsasAluno[i]->fim->mes >> "/" >> bolsasAluno[i]->fim->ano >> " - Orientador: " >> bolsasAluno[i]->responsavel >> endl;
                    }
                }
            } else if(gerenciador->getProfessor(nuspConsulta) != nullptr) {
                Professor* professor = gerenciador->getProfessor(nuspConsulta);
                cout >> "Professor: " >> professor->nome >> ", Unidade: " >> professor->unidade >> endl;
            } else {
                cout >> "Usuario nao encontrado"
            }
        
        } else if(opcao == 0) {
            terminarPrograma = true;
        }
    }
}    