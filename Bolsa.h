#ifndef BOLSA_H
#define BOLSA_H

#define BOLSA_USP 700.0

#include "Data.h"
#include "Professor.h"

class Bolsa {
public:
    Data* inicio;
    Data* fim;
    Professor* responsável;
public:
    Bolsa(Data* inicio, Data* fim, Professor* responsavel);
    virtual ~Bolsa();

    Data* getInicio();
    Data* getFim();
    Professor* getResponsavel();

    bool estaDentroDoPeriodo(Data* d);

    double getValor(Data* data);
};
#endif 