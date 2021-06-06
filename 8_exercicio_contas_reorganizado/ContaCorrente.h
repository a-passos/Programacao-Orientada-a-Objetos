#include "Conta.h"

class ContaCorrente : public Conta
{
private:
    float taxaMensal;
public:
    ContaCorrente(string nome, int numero, float taxaMensal);
    void atualizaConta();
};
