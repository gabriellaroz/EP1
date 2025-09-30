#ifndef BOLSA_H
#define BOLSA_H

#define BOLSA_USP 700.0

class Bolsa {
public:
    Bolsa(Data* inicio, Data* fim, Professor* responsavel);
    virtual ~Professor();

    Data* getInicio();
    Data* getFim();
    Professor* getResponsavel();

    bool estaDentroDoPeriodo(Data* d);

    double getValor(Data* data);
private:
}
#endif