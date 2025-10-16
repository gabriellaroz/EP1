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
    for(;terminarPrograma == false;"") {
        cout << "Gestao de bolsas USP" << endl << "1) Adicionar Aluno" << endl << "2) Adicionar professor" << endl << "3) Cadastrar bolsa" << endl << "4) Consultar usuario" << endl << "0) Sair" << endl << "Escolha uma opcao: ";
        cin >> opcao;
        if(opcao == 1) {
            cout << "Cadastro de aluno" << endl << "Digite o NUSP: ";
            cin >> nusp;
            cout << "Digite o nome: ";
            cin >> nome;
            Aluno* aluno = new Aluno(nusp, nome, 3); //nao sei qaul deveria ser o numero maximo de bolsas entao deixei como 3 por enquanto
            gerenciador->adicionarAluno(aluno);
            if(gerenciador->adicionarAluno(aluno)) {
                cout << "Aluno adicionado com sucesso" << endl;
            } else {
                cout << "Erro ao adicionar aluno" << endl;
            }
        } else if(opcao == 2) {
            cout << "Cadastro de professor" << endl << "Digite o NUSP: ";
            cin >> nusp;
            cout << "Digite o nome: ";
            cin >> nome;
            cout << "Digite a unidade: ";
            cin >> unidade;
            Professor* professor = new Professor(nusp, nome, unidade);
            gerenciador->adicionarProfessor(professor);
            if(gerenciador->adiciogitnarProfessor(professor)) {
                cout << "Professor adicionado com sucesso" << endl;
            } else {
                cout << "Erro ao adicionar professor" << endl;
            }
        } else if(opcao == 3) {
            int nuspBolsaAluno = 0;
            int nuspBolsaProfessor = 0;
            cout << "Cadastro de bolsa" << endl << "Alunos" << endl; //falta terminar a opcao 3 e fazer a 4
            Aluno** alunos = gerenciador->getAlunos();
            Professor** professores = gerenciador->getProfessores();
            for(int i = 0; i < 10 ; i++) {
                cout << alunos[i]->getNusp() << " - " << alunos[i]->getNome() << endl;
            }
            cout << "Digite o NUSP do aluno: ";
            cin >> nuspBolsaAluno;
            if(gerenciador->getAluno(nuspBolsaAluno) == nullptr) {
                cout << "Aluno inexistente" << endl;
            } else {
                cout << "Professores" << endl;
                for(int i = 0; i < 10; i++) {
                    cout << professores[i]->getNusp() << " - " << professores[i]->getNome() << " - " << professores[i]->getUnidade() << endl;
                }
                cout << "Digite o NUSP do professor: ";
                cin >> nuspBolsaProfessor;
                if(gerenciador->getProfessor() == nullptr) {
                    cout << "Professor inexistente" << endl;
                } else {
                    int mesInicio = 0;
                    int anoInicio = 0;
                    int mesFim = 0;
                    int anoFim = 0;
                    cout << "Digite o mes e ano de inicio : ";
                    cin >> mesInicio;
                    cout << " ";
                    cin >> anoInicio;
                    cout << "Digite o mes e o ano de fim: ";
                    cin >> mesFim;
                    cout << " ";
                    cin >> anoFim;
                    Data *dataInicio = new Data(mesInicio, anoInicio);
                    Data *dataFim = new Data(mesFim, anoFim);
                    Bolsa *bolsa = new Bolsa(dataInicio, dataFim, gerenciador->getProfessor(nuspBolsaProfessor));
                    bool adicionarBolsa = gerenciador->getAluno(nuspBolsaAluno)->adicionar(bolsa);
                    if(adicionarBolsa) {
                        cout << "Bolsa cadastrada com sucesso" << endl;
                    } else {
                        cout << "Erro ao cadastrar bolsa" << endl;
                    }
                }
            }
        } else if(opcao == 4) {
            int nuspConsulta = 0;
            cout << "Consulta de usuario" << endl << "Digite o NUSP: ";
            cin >> nuspConsulta;
            if(gerenciador->getAluno(nuspConsulta) != nullptr) {
                Bolsa** bolsasAluno = gerenciador->getAluno(nuspConsulta)->getBolsas();
                cout << "Aluno: " << gerenciador->getAluno(nuspConsulta)->getNome() << endl << "Bolsas: " << endl;
                for(int i = 0; i < gerenciador->getAluno(nuspConsulta)->maximo, i++) {
                    if(bolsasAluno[i] != nullptr) {
                        cout << bolsasAluno[i]->getInicio()->getMes() << "/" << bolsasAluno[i]->getInicio()->getAno() << " a " << bolsasAluno[i]->getFim()->getMes() << "/" << bolsasAluno[i]->getFim()->getAno() << " - Orientador: " << bolsasAluno[i]->getResponsavel() << endl;
                    }
                }
            } else if(gerenciador->getProfessor(nuspConsulta) != nullptr) {
                Professor* professor = gerenciador->getProfessor(nuspConsulta);
                cout << "Professor: " << professor->getNome() << ", Unidade: " << professor->getUnidade() << endl;
            } else {
                cout << "Usuario nao encontrado" << endl;
            }
        } else if(opcao == 0) {
            terminarPrograma = true;
        }
    }
}    