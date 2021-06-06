#include <iostream>

using namespace std;

class Conta
{
protected:
    string nome;
    int numero;
    float saldo;
public:
    void imprimeConta()
    {
        cout << "\nConta:" << numero << endl;
        cout << "-nome: " << nome << endl;
        cout << "-saldo: " << saldo << endl;
    }

    string toString()
    {
        string saida = "Conta: ";
        saida += std::to_string(numero);
        saida += ", nome: ";
        saida += nome;
        saida += ", saldo: ";
        saida += std::to_string(saldo);
        return saida;
    }

    Conta()
    {
        nome = "";
        numero = 0;
        saldo = 0.0;
    }

    Conta(string nome, int numero)
    {
        this->nome = nome;
        this->numero = numero;
        this->saldo = 0;
    }

    void debitar( float valor)
    {
        saldo -= valor;
    }

    void creditar(float valor)
    {
        saldo += valor;
    }

    friend void copiaConta(Conta * contaDestino, Conta contaOrigem);
};

class ContaCorrente : public Conta
{
    friend class ContaPoupanca;
private:
    float taxaMensal;
public:
    ContaCorrente()
    {

    }

    ContaCorrente(string nome, int numero, float taxaMensal) : Conta(nome, numero)
    {
        this->taxaMensal = taxaMensal;
    }

    void atualizaConta()
    {
        saldo -= taxaMensal;
    }

    friend void copiaContaCorrente(ContaCorrente * contaDestino, ContaCorrente contaOrigem);
};


class ContaPoupanca : public Conta
{
private:
    float taxaDeJuros;
public:
    ContaPoupanca()
    {

    }

    ContaPoupanca(string nome, int numero, float taxaDeJuros) : Conta (nome, numero)
    {
        this->taxaDeJuros = taxaDeJuros;
    }

    void atualizaConta()
    {
        saldo *= taxaDeJuros;
    }

    void converte(ContaCorrente conta, int numero, float taxaDeJuros)
    {
        this->nome = conta.nome;
        this->saldo = conta.saldo;
        this->numero = numero;
        this->taxaDeJuros = taxaDeJuros;
    }

    friend void copiaContaPoupanca(ContaPoupanca * contaDestino, ContaPoupanca contaOrigem);
};


void copiaConta(Conta * contaDestino, Conta contaOrigem)
{
    (*contaDestino).saldo = contaOrigem.saldo;
    (*contaDestino).numero = contaOrigem.numero;
    (*contaDestino).nome = contaOrigem.nome;
}

void copiaContaCorrente(ContaCorrente * contaDestino, ContaCorrente contaOrigem)
{
    copiaConta(contaDestino, contaOrigem);
    (*contaDestino).taxaMensal = contaOrigem.taxaMensal;
}

void copiaContaPoupanca(ContaPoupanca * contaDestino, ContaPoupanca contaOrigem)
{
    copiaConta(contaDestino, contaOrigem);
    (*contaDestino).taxaDeJuros = contaOrigem.taxaDeJuros;
}

void transferir(Conta * contaOrigem, Conta * contaDestino, float valor)
{
    contaOrigem->debitar(valor);
    contaDestino->creditar(valor);
}


int main()
{
    ContaPoupanca conta1("Joao da Silva", 11010, 1.01);
    ContaCorrente conta2("Jose de Jesus", 11011, 32);

    conta1.creditar(1000);
    conta2.creditar(500);

    cout << "\n---------------------------------------------\n";
    cout << conta1.toString() << endl;
    cout << conta2.toString() << endl;

    cout << "\n---------------------------------------------\n";
    cout << "\nDebita 500 da conta 1\n";
    cout << "\nCredita 50 na conta 2\n";

    conta1.debitar(500);
    conta2.creditar(50);
    printf("\n---------------------------------------------\n");

    cout << conta1.toString() << endl;
    cout << conta2.toString() << endl;

    cout << "\n---------------------------------------------\n";
    cout << "transfere 50 da conta 1 para conta2\n";

    transferir(&conta1,&conta2,50);
    cout << conta1.toString() << endl;
    cout << conta2.toString() << endl;

    cout << "\n---------------------------------------------\n";
    cout << "Atualizacao mensal\n";

    conta1.atualizaConta();
    conta2.atualizaConta();

    cout << conta1.toString() << endl;
    cout << conta2.toString() << endl;

    cout << "\n---------------------------------------------\n";
    cout << "Copia de conta\n";

    ContaPoupanca contaPoupancaTemp;
    ContaCorrente contaCorrenteTemp;

    copiaContaPoupanca(&contaPoupancaTemp,conta1);
    copiaContaCorrente(&contaCorrenteTemp,conta2);

    cout << contaPoupancaTemp.toString() << endl;
    cout << contaCorrenteTemp.toString() << endl;

    cout << endl;
    for(int i=0; i<12; i++)
        contaPoupancaTemp.atualizaConta();

    cout << "Previsao de saldo em 12 meses" << endl << endl;
    cout << contaPoupancaTemp.toString() << endl;

    cout << "\n---------------------------------------------\n";

    contaPoupancaTemp.converte(contaCorrenteTemp,11012, 1.01);
    for(int i=0; i<12; i++)
        contaPoupancaTemp.atualizaConta();

    cout << endl;
    cout << "Previsao de saldo em 12 meses" << endl << endl;
    cout << contaPoupancaTemp.toString() << endl;


    return 0;
}








