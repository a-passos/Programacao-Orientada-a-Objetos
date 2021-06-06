#ifndef CONTA_H
#define CONTA_H

#include <iostream>

using namespace std;

class Conta
{
protected:
    string nome;
    int numero;
    float saldo;
public:
    int getNumero();
    void imprimeConta();
    string toString();
    Conta(string nome, int numero);
    void debitar( float valor);
    void creditar(float valor);
};

#endif // CONTA_H
