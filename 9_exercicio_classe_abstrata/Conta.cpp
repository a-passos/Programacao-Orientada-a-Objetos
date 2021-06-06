#include "Conta.h"

int Conta::getNumero()
{
    return numero;
}
void Conta::imprimeConta()
{
    cout << "\nConta:" << numero << endl;
    cout << "-nome: " << nome << endl;
    cout << "-saldo: " << saldo << endl;
}
string Conta::toString()
{
    string saida = "Conta: ";
    saida += std::to_string(numero);
    saida += ", nome: ";
    saida += nome;
    saida += ", saldo: ";
    saida += std::to_string(saldo);
    return saida;
}

Conta::Conta(string nome, int numero)
{
    this->nome = nome;
    this->numero = numero;
    this->saldo = 0;
}

void Conta::debitar( float valor)
{
    saldo -= valor;
}

void Conta::creditar(float valor)
{
    saldo += valor;
}

