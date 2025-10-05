#include "Bolsa.h"
#include <iostream>

using namespace std;

Bolsa::Bolsa(Data* inicio, Data* fim, Professor* responsavel): inicio(inicio), fim(fim), responsavel(responsavel) {
}

Bolsa::~Bolsa() {
    delete inicio;
    delete fim;
}

Data* Bolsa:: getInicio() {
    return inicio;
}

Data* Bolsa: getFim() {
    return fim;
}

Professor* Bolsa:: getResponsavel() {
    return responsavel;
}

bool Bolsa:: estaDentroDoPeriodo(Data* d) {
    if (inicio->ano == fim->ano) {
        if (d->mes >= inicio->mes && d->mes <= fim->mes) {
            return true;
        }
    } else if (d->mes >= fim->mes && d->ano == fim->ano) {
        return true;
    } else if (d->mes >= inicio->mes && d->ano == inicio->ano) {
        return true;
    } else {
        return false;
    }
} 

double Bolsa::getValor(Data* data) {
    if (estaDentroDoPeriodo) {
        return BOLSA_USP;
    } else {
        return 0;
    }
}
