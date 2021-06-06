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
    Garrafa();
    Garrafa(string cont, string mat, float vol);
    ~Garrafa();
    string pegaConteudo();
    void atribuiConteudo(string s);
    string pegaMaterial();
    void atribuiMaterial(string s);
    float pegaVolume();
    void atribuiVolume(float v);
};

Garrafa::Garrafa()
{
    std::cout << "Seja feita uma garrafa vazia!" << std::endl;
}

Garrafa::Garrafa(string cont, string mat, float vol)
{
    std::cout << "Seja feita uma garrafa!" << std::endl;
    atribuiConteudo(cont);
    atribuiMaterial(mat);
    atribuiVolume(vol);
}

Garrafa::~Garrafa()
{
    std::cout << "That's all folks!" << std::endl;
}

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
    Garrafa * garrafa1 = new Garrafa("Leite", "Vidro",0.5);
    Garrafa * garrafa2 = new Garrafa("Agua", "Plastico",1.0);
    Garrafa * garrafa3 = new Garrafa();
    Garrafa * garrafas = new Garrafa[10]();

    cout << "Conteudo da garrafa 1: ";
    cout << garrafa1->pegaConteudo() << endl;
    cout << "Material da garrafa 1: ";
    cout << garrafa1->pegaMaterial() << endl << endl;
    cout << "Conteudo da garrafa 2: " << garrafa2->pegaConteudo() << endl;
    //garrafa1.volume = -0.350; // Pode?
    delete garrafa1;
    delete garrafa2;
    delete garrafa3;
    delete [] garrafas;
}

