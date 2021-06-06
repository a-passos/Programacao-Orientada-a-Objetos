#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include "Conta.h"

class ContaPoupanca : public Conta
{
private:
    float taxaDeJuros;
public:
    ContaPoupanca(string nome, int numero, float taxaDeJuros);
    void atualizaConta();
};

#endif
