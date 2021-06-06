#include "ContaPoupanca.h"

ContaPoupanca::ContaPoupanca(string nome, int numero, float taxaDeJuros) : Conta (nome, numero)
{
    this->taxaDeJuros = taxaDeJuros;
}
void ContaPoupanca::atualizaConta()
{
    saldo *= taxaDeJuros;
}
