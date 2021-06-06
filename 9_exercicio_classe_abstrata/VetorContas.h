#ifndef VETORCONTAS_H
#define VETORCONTAS_H

#include "Conta.h"

class VetorContas
{
private:
    int tamanho;
public:
    Conta ** elementos;
    VetorContas(int numero);
    ~VetorContas();
    int getTamanho();
    void mostra();
    void mostraContasCorrente();
    void mostraContasPoupanca();
    int busca(int numero);
    void transferir(int numeroOrigem, int numeroDestino, float valor);
};

#endif // VETORCONTAS_H
