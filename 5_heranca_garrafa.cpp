#include <iostream>
#include <string>

using namespace std;

class Garrafa
{
protected:
    string conteudo;
    string material;
    float volume;
public:
    Garrafa(string conteudo, string material, float volume)
    {
        this->conteudo = conteudo;
        this->material = material;
        this->volume = volume;
    };

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

class GarrafaTermica : public Garrafa
{
private:
    string tipoDeCopo;
public:
    GarrafaTermica(string conteudo, string material, float volume, string tipoDeCopo) : Garrafa(conteudo, material, volume)
    {
        this->tipoDeCopo = tipoDeCopo;
    }

    string pegaTipoDeCopo()
    {
        return tipoDeCopo;
    }

    void atribuiTipoDeCopo(string tipoDeCopo)
    {
        this->tipoDeCopo = tipoDeCopo;
    }
};

int main()
{
    Garrafa garrafa1("Leite", "Vidro",0.5);
    GarrafaTermica garrafa2("Agua", "Plastico", 1.0, "ComAlca");

    cout << "-----------------------------------------------------\n" << endl;
    cout << "Garrafa 1: " << endl;
    cout << "Conteudo:" << garrafa1.pegaConteudo() << endl;
    cout << "Material: "<< garrafa1.pegaMaterial() << endl;
    cout << "Volume: " << garrafa1.pegaVolume() << endl;

    cout << "-----------------------------------------------------\n" << endl;
    cout << "Garrafa 2: " << endl;
    cout << "Conteudo:" << garrafa2.pegaConteudo() << endl;
    cout << "Material: "<< garrafa2.pegaMaterial() << endl;
    cout << "Volume: " << garrafa2.pegaVolume() << endl;
    cout << "Tipo de copo: " << garrafa2.pegaTipoDeCopo() << endl;
}

