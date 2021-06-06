#include <iostream>

using namespace std;

#include "Conta.h"
#include "ContaPoupanca.h"
#include "ContaCorrente.h"
#include "VetorContas.h"


int main()
{
    //Conta conta1("Pedro",3);
    cout << "Entre com o numero de contas a serem criadas:";
    int numeroDeContas;
    cin >> numeroDeContas;

    VetorContas Contas(numeroDeContas);

    for(int i=0; i<numeroDeContas; i++)
    {
        cout << "Entre com o tipo de conta (1:Conta corrente; 2:conta poupança)";
        int tipo;
        cin >> tipo;
        string nome;
        cout << "Entre com o nome do titular da conta:";
        cin >> nome;
        if(tipo==1)
        {
            ContaCorrente * conta = new ContaCorrente(nome,i+1,32);
            Contas.elementos[i]=conta;

        }
        if(tipo==2)
        {
            ContaPoupanca * conta = new ContaPoupanca(nome,i+1,1.01);
            Contas.elementos[i]=conta;
        }
        /*cout << "O tipo eh :" << typeid(Contas.elementos[i]).name() << "\n";
        if(dynamic_cast <ContaCorrente *> (Contas.elementos[i]) !=NULL) cout << "Eh conta corrente!";
        if(dynamic_cast <ContaPoupanca *> (Contas.elementos[i]) !=NULL) cout << "Eh conta poupanca!";*/

    }
    Contas.mostra();

    int operacao=0;
    do
    {
        cout << "Entre com a operacao a ser realizada (1:debitar; 2: creditar; 3:transferir; 4:imprime contas corrente; 5:imprime contas poupanca; 6:sair):";
        cin >> operacao;

        if(operacao==1)
        {
            cout << "Entre com o numero da conta:";
            int numero;
            cin >> numero;
            cout << "Entre com o valor:";
            float valor;
            cin >> valor;
            int indice = Contas.busca(numero);
            if(indice==-1)
                cout << "Conta nao encontrada" << endl;
            else
                Contas.elementos[indice]->debitar(valor);
        }
        if(operacao==2)
        {
            cout << "Entre com o numero da conta:";
            int numero;
            cin >> numero;
            cout << "Entre com o valor:";
            float valor;
            cin >> valor;
            int indice = Contas.busca(numero);
            if(indice==-1)
                cout << "Conta nao encontrada" << endl;
            else
                Contas.elementos[indice]->creditar(valor);
        }
        if(operacao==3)
        {
            cout << "Entre com o numero da conta de origem:";
            int numeroOrigem;
            cin >> numeroOrigem;
            cout << "Entre com o numero da conta de destino:";
            int numeroDestino;
            cin >> numeroDestino;
            cout << "Entre com o valor:";
            float valor;
            cin >> valor;
            Contas.transferir(numeroOrigem, numeroDestino,valor);
        }
        if(operacao==4)
            Contas.mostraContasCorrente();

        if(operacao==5)
            Contas.mostraContasPoupanca();

    }
    while(operacao!=6);


    return 0;
}






