#include <iostream>
#include <string.h>

#include <iomanip>
#include <sstream>

using namespace std;

class conta
{
    public:
        string nome;
        int numero;
        float saldo;

        void imprimeConta(void)
        {
            cout << "Conta: " << numero << std::endl;
            cout << "-titular: " << nome << std::endl;
            cout << "-saldo: " << saldo << std::endl << std::endl;
        }
        string to_string()
        {
            string saida = nome;
            saida += " ";
            saida += std::to_string(numero);
            saida += " ";
            //saida += std::to_string(saldo);
            std::stringstream stream;
            stream << std::fixed << std::setprecision(2) << saldo;
            saida += stream.str();

            return saida;
        }
        void inicializaConta(string nome, int numero, float saldo)
        {
            (*this).nome = nome;
            (*this).numero = numero;
            (*this).saldo = saldo;
        }
        void debitar(float valor)
        {
            saldo -= valor;
        }
        void creditar(float valor)
        {
            saldo += valor;
        }
        void transferir(class conta * contaDestino,float quantia)
        {
            if(saldo >= quantia)
            {
                debitar(quantia);
                (*contaDestino).creditar(quantia);
            }
        }
};

int main()
{
    conta conta1;
    conta conta2;

    conta1.inicializaConta("Joao da Silva", 11010,1000);
    conta2.inicializaConta("Jose de Jesus", 11011, 500);

    cout << "_____________________________________________\n";

    cout << conta1.to_string() << std::endl;
    cout << conta2.to_string() << std::endl;

    cout << "_____________________________________________\n";
    cout << "Debita 500 da conta 1\n";
    cout << "Credita 50 na conta 2\n";

    conta1.debitar(500);
    conta2.creditar(50);

    cout << "_____________________________________________\n";

    cout << conta1.to_string() << std::endl;
    cout << conta2.to_string() << std::endl;

    cout << "_____________________________________________\n";
    cout << "Transfere 100 da conta 1 para a conta 2\n\n";

    conta1.transferir(&conta2, 100);

    cout << conta1.to_string() << std::endl;
    cout << conta2.to_string() << std::endl;

    cout << "_____________________________________________\n";
    cout << "Transfere 500 da conta 1 para a conta 2\n\n";

    conta1.transferir(&conta2, 500);

    cout << conta1.to_string() << std::endl;
    cout << conta2.to_string() << std::endl;

    cout << "_____________________________________________\n";

    return 0;
}

