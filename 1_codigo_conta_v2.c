/*
    Adicionadas as funcoes imprimeConta() e inicializaConta()
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct conta
{
    char nome[30];
    int numero;
    float saldo;
} tipoConta;

void imprimeConta(tipoConta conta, int num)
{
    printf("\nConta %d:\n",num);
    printf("-nome: %s\n",conta.nome);
    printf("-numero: %i\n",conta.numero);
    printf("-saldo: %4.2f\n",conta.saldo);
}

void inicializaConta(tipoConta * conta, char * nome, int numero, float saldo)
{
    strcpy((*conta).nome,nome);
    (*conta).numero = numero;
    (*conta).saldo = saldo;
}

void debitar(tipoConta * conta, float valor)
{
    (*conta).saldo -= valor;
}

void creditar(tipoConta * conta, float valor)
{
    (*conta).saldo += valor;
}

int main()
{
    tipoConta conta1;
    tipoConta conta2;

    inicializaConta(&conta1, "Joao da Silva", 11010,1000);
    inicializaConta(&conta2, "Jose de Jesus", 11011, 500);

    printf("\n---------------------------------------------\n");
    imprimeConta(conta1,1);
    imprimeConta(conta2,2);

    printf("\n---------------------------------------------\n");
    printf("\nDebita 500 da conta 1\n");
    printf("\nCredita 50 na conta 2\n");

    debitar(&conta1, 500);
    creditar(&conta2,50);
    printf("\n---------------------------------------------\n");

    imprimeConta(conta1,1);
    imprimeConta(conta2,2);
    
    return 0;
}

