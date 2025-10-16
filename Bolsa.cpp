#include "Bolsa.h"
#include <iostream>
#include <string>

using namespace std;

Bolsa::Bolsa(Data* inicio, Data* fim, Professor* responsavel)
: inicio(inicio), fim(fim), responsavel(responsavel) {
}

Bolsa::~Bolsa() {
    delete inicio;
    delete fim;
}

Data* Bolsa::getInicio() {
    return inicio;
}

Data* Bolsa::getFim() {
    return fim;
}

Professor* Bolsa::getResponsavel() {
    return responsavel;
}

bool Bolsa::estaDentroDoPeriodo(Data* d) {
    if (inicio->getAno() == fim->getAno()) {
        if (d->getAno() == inicio->getAno() &&
            d->getMes() >= inicio->getMes() && d->getMes() <= fim->getMes()) {
            return true;
        } else {
            return false;
        }
    } 
    else if (d->getAno() == inicio->getAno()) {
        if (d->getMes() >= inicio->getMes()) {
            return true;
        } else {
            return false;
        }
    } 
    else if (d->getAno() == fim->getAno()) {
        if (d->getMes() <= fim->getMes()) {
            return true;
        } else {
            return false;
        }
    } 
    else if (d->getAno() > inicio->getAno() && d->getAno() < fim->getAno()) {
        return true;
    } 
    else {
        return false;
    }
}

double Bolsa::getValor(Data* data) {
    if (estaDentroDoPeriodo(data)) {
        return BOLSA_USP;
    } else {
        return 0;
    }
}
