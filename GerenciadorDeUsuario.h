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

    Aluno** alunos;
    Professor ** professores; 
    int quantidadeDeAlunos;
    int quantidadeDeProfessores;
    int maximoDeUsuarios;
}

