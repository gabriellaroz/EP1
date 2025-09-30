#ifndef GERENCIADOR_H
#define GERENCIADOR_H 

class GerenciadorDeUsuario{ 

    public: 
    GerenciadorDeUsuario(int maximo);
    virtual ~GerenciadorDeUsuario();

    bool adicionarAluno(Aluno* a);
    bool adicionarProfessor(Professor* a);

    Aluno* getAluno(int nusp);
    Professor* getProfessor(int nusp);

    Aluno** getAlunos(int& quantidade);
    Professor** getProfessores(int& quantidade);

    private: 

    Aluno** alunos = nullptr; 
    Professor ** professores = nullptr; 
    int quantidadeDeAlunos = 0;
    int quantidadeDeProfessores = 0;
    int maximoDeUsuarios = 0;
}

