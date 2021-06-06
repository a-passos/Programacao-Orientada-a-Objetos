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
    string pegaConteudo()
    {
        return this->conteudo; // nao precisa o "this"
    };

    void atribuiConteudo(string conteudo)
    {
        this->conteudo = conteudo;
    };

    string pegaMaterial()
    {
        return this->material;
    };

    void atribuiMaterial(string m)
    {
        material = m; // que material eh esse?
    };

    float pegaVolume()
    {
        return this->volume;
    };

    void atribuiVolume(float volume)
    {
        this->volume = volume;
    };
};

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

