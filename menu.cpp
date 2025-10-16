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

    while (!terminarPrograma) {
        cout << "Gestao de bolsas USP" << endl
             << "1) Adicionar Aluno" << endl
             << "2) Adicionar Professor" << endl
             << "3) Cadastrar Bolsa" << endl
             << "4) Consultar Usuario" << endl
             << "0) Sair" << endl
             << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            cout << "Cadastro de aluno" << endl << "Digite o NUSP: ";
            cin >> nusp;
            cout << "Digite o nome (sem espacos): ";
            cin >> nome;

            Aluno* aluno = new Aluno(nusp, nome, 3); 
            if (gerenciador->adicionarAluno(aluno)) {
                cout << "Aluno adicionado com sucesso" << endl;
            } else {
                cout << "Erro ao adicionar aluno" << endl;
                delete aluno;
            }

        } else if (opcao == 2) {
            cout << "Cadastro de professor" << endl << "Digite o NUSP: ";
            cin >> nusp;
            cout << "Digite o nome (sem espacos): ";
            cin >> nome;
            cout << "Digite a unidade (sem espacos): ";
            cin >> unidade;

            Professor* professor = new Professor(nusp, nome, unidade);
            if (gerenciador->adicionarProfessor(professor)) {
                cout << "Professor adicionado com sucesso" << endl;
            } else {
                cout << "Erro ao adicionar professor" << endl;
                delete professor;
            }

        } else if (opcao == 3) {
            int nuspAluno, nuspProfessor;
            cout << "Cadastro de bolsa" << endl << "Alunos cadastrados:" << endl;
            for (int i = 0; i < 10; i++) {
                Aluno* a = gerenciador->getAluno(i);
                if (a != nullptr) {
                    cout << a->getNusp() << " - " << a->getNome() << endl;
                }
            }

            cout << "Digite o NUSP do aluno: ";
            cin >> nuspAluno;
            Aluno* aluno = gerenciador->getAluno(nuspAluno);
            if (!aluno) {
                cout << "Aluno inexistente" << endl;
                continue;
            }

            cout << "Professores cadastrados:" << endl;
            for (int i = 0; i < 10; i++) {
                Professor* p = gerenciador->getProfessor(i);
                if (p != nullptr) {
                    cout << p->getNusp() << " - " << p->getNome() << " - " << p->getUnidade() << endl;
                }
            }

            cout << "Digite o NUSP do professor: ";
            cin >> nuspProfessor;
            Professor* professor = gerenciador->getProfessor(nuspProfessor);
            if (!professor) {
                cout << "Professor inexistente" << endl;
                continue;
            }

            int mesInicio, anoInicio, mesFim, anoFim;
            cout << "Digite mes e ano de inicio: ";
            cin >> mesInicio >> anoInicio;
            cout << "Digite mes e ano de fim: ";
            cin >> mesFim >> anoFim;

            Data* dataInicio = new Data(mesInicio, anoInicio);
            Data* dataFim = new Data(mesFim, anoFim);
            Bolsa* bolsa = new Bolsa(dataInicio, dataFim, professor);

            if (aluno->adicionar(bolsa)) {
                cout << "Bolsa cadastrada com sucesso" << endl;
            } else {
                cout << "Erro ao cadastrar bolsa" << endl;
            }

        } else if (opcao == 4) {
            int nuspConsulta;
            cout << "Consulta de usuario" << endl << "Digite o NUSP: ";
            cin >> nuspConsulta;

            Aluno* aluno = gerenciador->getAluno(nuspConsulta);
            if (aluno) {
                Bolsa** bolsas = aluno->getBolsas();
                cout << "Aluno: " << aluno->getNome() << endl << "Bolsas: " << endl;
                for (int i = 0; i < 3; i++) { 
                    if (bolsas[i] != nullptr) {
                        cout << bolsas[i]->getInicio()->getMes() << "/" << bolsas[i]->getInicio()->getAno()
                             << " a " << bolsas[i]->getFim()->getMes() << "/" << bolsas[i]->getFim()->getAno()
                             << " - Orientador NUSP: " << bolsas[i]->getResponsavel()->getNusp() << endl;
                    }
                }
            } else {
                Professor* professor = gerenciador->getProfessor(nuspConsulta);
                if (professor) {
                    cout << "Professor: " << professor->getNome()
                         << ", Unidade: " << professor->getUnidade() << endl;
                } else {
                    cout << "Usuario nao encontrado" << endl;
                }
            }

        } else if (opcao == 0) {
            terminarPrograma = true;
        } else {
            cout << "Opcao invalida!" << endl;
        }
    }
}
