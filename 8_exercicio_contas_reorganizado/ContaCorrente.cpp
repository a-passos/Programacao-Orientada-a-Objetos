#include "ContaCorrente.h"

ContaCorrente::ContaCorrente(string nome, int numero, float taxaMensal) : Conta(nome, numero)
{
    this->taxaMensal = taxaMensal;
}
void ContaCorrente::atualizaConta()
{
    saldo -= taxaMensal;
}
