#include <iostream>
#include <string>

using namespace std;

class Garrafa
{
private:
    string conteudo;
    string material;
    float volume;
public:
    string pegaConteudo();
    void atribuiConteudo(string s);
    string pegaMaterial();
    void atribuiMaterial(string s);
    float pegaVolume();
    void atribuiVolume(float v);
};

string Garrafa::pegaConteudo()
{
    return this->conteudo;
}

void Garrafa::atribuiConteudo(string s)
{
    this->conteudo = s;
}

string Garrafa::pegaMaterial()
{
    return this->material;
}

void Garrafa::atribuiMaterial(string s)
{
    this->material = s;
}

float Garrafa::pegaVolume()
{
    return this->volume;
}

void Garrafa::atribuiVolume(float v)
{
    this->volume = v;
}


int main()
{
    Garrafa garrafa1;
    Garrafa garrafa2;
    string conteudo1 = "Leite";
    string conteudo2 = "Agua";
    string material1 = "Vidro";
    string material2 = "Plastico";

    garrafa1.atribuiConteudo(conteudo1);
    garrafa2.atribuiConteudo(conteudo2);

    garrafa1.atribuiMaterial(material1);
    garrafa2.atribuiMaterial(material2);

    cout << "Conteudo da garrafa 1: ";
    cout << garrafa1.pegaConteudo() << endl;
    cout << "Material da garrafa 1: ";
    cout << garrafa1.pegaMaterial() << endl << endl;
    cout << "Conteudo da garrafa 2: " << garrafa2.pegaConteudo() << endl;
    //garrafa1.volume = -0.350; // Pode?
}

