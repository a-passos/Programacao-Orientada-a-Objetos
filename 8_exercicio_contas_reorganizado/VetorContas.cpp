#include "VetorContas.h"

VetorContas::VetorContas(int numero)
{
    elementos = new Conta *[numero];
    tamanho = numero;
}
VetorContas::~VetorContas()
{
    delete [] elementos;
    cout << "Destruiu" << endl;
}
int VetorContas::getTamanho()
{
    return tamanho;
}
void VetorContas::mostra()
{
    for(int i=0; i<tamanho; i++)
        cout << elementos[i]->toString() << endl;
}
int VetorContas::busca(int numero)
{
    for(int i=0; i<tamanho; i++)
    {
        if(elementos[i]->getNumero()==numero)
            return i;
    }
    return -1;
}
void VetorContas::transferir(int numeroOrigem, int numeroDestino, float valor)
{
    int indiceOrigem = busca(numeroOrigem);
    int indiceDestino = busca(numeroDestino);
    if(indiceOrigem==-1)
        cout << "Conta de origem nao encontrada" << endl;
    else if(indiceDestino==-1)
        cout << "Conta de destino nao encontrada" << endl;
    else
    {
        elementos[indiceOrigem]->debitar(valor);
        elementos[indiceDestino]->creditar(valor);
    }
}

