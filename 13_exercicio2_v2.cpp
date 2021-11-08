#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
using namespace std;

class Complexo
{
private:
    float real;
    float imag;
public:
    Complexo()
    {
        real = 0.0;
        imag = 0.0;
    }
    Complexo(float real,float imag)
    {
        setReal(real);
        setImag(imag);
    }
    float getReal()
    {
        return real;
    }
    float getImag()
    {
        return imag;
    }
    void setReal(float real)
    {
        this->real = real;
    }
    void setImag(float imag)
    {
        this->imag = imag;
    }
    float getMagnitude()
    {
        return sqrt(real * real + imag * imag);
    }
    float getAngulo()
    {
        return atan2(imag,real);
    }
    void soma(Complexo *complexo2)
    {
        real += complexo2->real;
        imag += complexo2->imag;
    }
    Complexo operator+(Complexo& complexo2)
    {
        Complexo resultado;
        resultado.real = this->real + complexo2.getReal();
        resultado.imag = this->imag + complexo2.getImag();
        return resultado;
    }
    void subtracao(Complexo *complexo2)
    {
        real -= complexo2->real;
        imag -= complexo2->imag;
    }
    Complexo operator-(Complexo& complexo2)
    {
        Complexo resultado;
        resultado.real = this->real - complexo2.getReal();
        resultado.imag = this->imag - complexo2.getImag();
        return resultado;
    }

    void multiplicacao(Complexo * complexo2)
    {
        float modulo1 = getMagnitude();
        float angulo1 = getAngulo();
        float modulo2 = complexo2->getMagnitude();
        float angulo2 = complexo2->getAngulo();
        float moduloResultante = modulo1 * modulo2;
        float anguloResultante = angulo1 + angulo2;
        real = moduloResultante * cos(anguloResultante);
        imag = moduloResultante * sin(anguloResultante);
    }
    Complexo operator*(Complexo& complexo2)
    {
        float modulo1 = getMagnitude();
        float angulo1 = getAngulo();
        float modulo2 = complexo2.getMagnitude();
        float angulo2 = complexo2.getAngulo();
        float moduloResultante = modulo1 * modulo2;
        float anguloResultante = angulo1 + angulo2;

        Complexo resultado;
        resultado.real = moduloResultante * cos(anguloResultante);
        resultado.imag = moduloResultante * sin(anguloResultante);
        return resultado;
    }

    void divisao(Complexo * complexo2)
    {
        float modulo1 = getMagnitude();
        float angulo1 = getAngulo();
        float modulo2 = complexo2->getMagnitude();
        float angulo2 = complexo2->getAngulo();
        float moduloResultante = modulo1 / modulo2;
        float anguloResultante = angulo1 - angulo2;
        real = moduloResultante * cos(anguloResultante);
        imag = moduloResultante * sin(anguloResultante);
    }

    Complexo operator/(Complexo& complexo2)
    {
        float modulo1 = getMagnitude();
        float angulo1 = getAngulo();
        float modulo2 = complexo2.getMagnitude();
        float angulo2 = complexo2.getAngulo();
        float moduloResultante = modulo1 / modulo2;
        float anguloResultante = angulo1 - angulo2;

        Complexo resultado;
        resultado.real = moduloResultante * cos(anguloResultante);
        resultado.imag = moduloResultante * sin(anguloResultante);
        return resultado;
    }
    string stringRetangular()
    {
        string saida = "(";
        saida += to_string(real);
        saida += ",";
        saida += to_string(imag);
        saida += ")";
        return saida;
    }
    string stringPolar()
    {
        string saida = "(";
        saida += to_string(getMagnitude());
        saida += ",";
        saida += to_string(getAngulo()*180/3.1415926535);
        saida += ")";
        return saida;
    }
    string toString()
    {
        return stringRetangular();
    }
};

Complexo comparaPorModulo(Complexo * complexo1,Complexo * complexo2)
{
    if(complexo1->getMagnitude()>complexo2->getMagnitude())
        return (*complexo1);
    else
        return (*complexo2);
}

class Imprimivel
{
    virtual void imprime() = 0;
};

class Arquivavel
{
    virtual void salva(string nomeArquivo) = 0;
    virtual void carrega(string nomeArquivo) = 0;
};

class VetorComplexo : Imprimivel, Arquivavel
{
private:
public:
    std::vector <Complexo> elementos;
    VetorComplexo()
    {
    }
    ~VetorComplexo()
    {
        elementos.clear();
        cout << "Destruiu" << endl;
    }
    int getTamanho()
    {
        return elementos.size();
    }
    void imprime()
    {
        for(int i=0; i<elementos.size(); i++)
            cout << elementos[i].stringRetangular() << endl;
    }
    void salva(string nomeArquivo)
    {
        ofstream meuArquivo;
        meuArquivo.open(nomeArquivo);
        meuArquivo << elementos.size() << endl;
        for(int i=0; i<elementos.size(); i++)
        {
            meuArquivo << elementos[i].getReal() << endl;
            meuArquivo << elementos[i].getImag() << endl;
        }
        meuArquivo.close();
    }
    void carrega(string nomeArquivo)
    {
        string linha;
        ifstream arquivo(nomeArquivo);
        int indice = 0;
        try
        {
            arquivo.exceptions (std::ifstream::eofbit |
                                std::ifstream::failbit |
                                std::ifstream::badbit);
            getline(arquivo, linha);
            int tamanhoArquivo = stoi(linha);
            elementos.clear();
            while(getline(arquivo, linha))
            {
                float parteReal, parteImaginaria;

                cout << "Carregou do arquivo:" << linha << endl;
                try
                {
                    parteReal = stof(linha);
                }
                catch(...)
                {
                    cout << "Erro carregando o numero " << indice << endl;
                    cout << "Erro de conversao na parte real! Atribuido o valor 0!"<<endl;
                    parteReal = 0;
                };

                getline(arquivo, linha);
                cout << "Carregou do arquivo:" << linha << endl;
                try
                {
                    parteImaginaria = stof(linha);
                }
                catch(...)
                {
                    cout << "Erro carregando o numero " << indice << endl;
                    cout << "Erro de conversao na parte imaginaria! Atribuido o valor 0!"<<endl;
                    parteImaginaria = 0;
                }

                elementos.push_back(Complexo(parteReal,parteImaginaria));
                indice++;
            }
        }
        catch (std::ifstream::failure& e)
        {
            if(arquivo.eof())
            {
                arquivo.close();
                std::cout <<"Fim de arquivo, fechou!\n";
            }
            else
            {
                if(!arquivo)
                    std::cerr << "Arquivo inexistente!\n";
                else
                {
                    std::cerr << "Excecao no tratamento do arquivo\n";
                    std::cerr << e.what() << std::endl;
                }
            }
        }
    }
};

int main()
{
    // Primeira parte - gera o arquivo de texto
    VetorComplexo * complexos1 = new VetorComplexo();

    complexos1->elementos.push_back(Complexo(1,2));
    complexos1->elementos.push_back(Complexo(3,4));
    complexos1->elementos.push_back(Complexo(6,7));
    complexos1->elementos.push_back(Complexo(8,9));
    complexos1->elementos.push_back(Complexo(10,11));

    cout << "Dados gerados" << endl;
    complexos1->imprime();
    complexos1->salva("Complexos.txt");

    // Segunda parte - recarrega os dados gerados
    complexos1->carrega("Complexos.txt");

    cout << endl;
    cout << "Dados Recarregados" << endl;
    complexos1->imprime();

    delete complexos1;

    // Teste dos operadores
    Complexo a = Complexo(3,4);
    Complexo b = Complexo(6,8);
    Complexo c = a + b;

    cout << endl;
    cout << a.toString() << " + " << b.toString() << " = " << c.toString() << endl;
    c = a - b;
    cout << a.toString() << " - " << b.toString() << " = " << c.toString() << endl;
    c = a * b;
    cout << a.toString() << " * " << b.toString() << " = " << c.stringPolar() << endl;
    c = a / b;
    cout << a.toString() << " / " << b.toString() << " = " << c.stringPolar() << endl;

    return 0;
}


