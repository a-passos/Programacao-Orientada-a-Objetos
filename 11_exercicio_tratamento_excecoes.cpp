#include <iostream>
#include <fstream>
#include <math.h>

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
    void subtracao(Complexo *complexo2)
    {
        real -= complexo2->real;
        imag -= complexo2->imag;
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
    int tamanho;
public:
    Complexo ** elementos;
    VetorComplexo(int numero)
    {
        alocaVetor(numero);
    }
    void alocaVetor(int numero)
    {
        elementos = new Complexo*[numero];
        tamanho = numero;
    }
    ~VetorComplexo()
    {
        desalocaVetor();
        cout << "Destruiu" << endl;
    }
    int getTamanho()
    {
        return tamanho;
    }
    void imprime()
    {
        for(int i=0; i<tamanho; i++)
            cout << elementos[i]->stringRetangular() << endl;
    }
    void salva(string nomeArquivo)
    {
        ofstream meuArquivo;
        meuArquivo.open(nomeArquivo);
        meuArquivo << tamanho << endl;
        for(int i=0; i<tamanho; i++)
        {
            meuArquivo << elementos[i]->getReal() << endl;
            meuArquivo << elementos[i]->getImag() << endl;
        }
        meuArquivo.close();
    }
    void desalocaVetor()
    {
        if(tamanho==0)
            return;
        for(int i=0; i<tamanho; i++)
            delete elementos[i];
        delete [] elementos;
        tamanho = 0;
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
            desalocaVetor();
            alocaVetor(tamanhoArquivo);
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

                elementos[indice] = new Complexo(parteReal,parteImaginaria);
                indice++;
            }
        }
        catch (std::ifstream::failure& e)
        {
            if(arquivo.eof())
            {
                if(indice<tamanho)
                    tamanho=indice;
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
    VetorComplexo * complexos1 = new VetorComplexo(5);

    complexos1->elementos[0] = new Complexo(1,2);
    complexos1->elementos[1] = new Complexo(3,4);
    complexos1->elementos[2] = new Complexo(6,7);
    complexos1->elementos[3] = new Complexo(8,9);
    complexos1->elementos[4] = new Complexo(10,11);

    cout << "Dados gerados" << endl;
    complexos1->imprime();
    complexos1->salva("Complexos.txt");

    // Segunda parte - recarrega os dados gerados
    complexos1->carrega("Complexos.txt");

    cout << endl;
    cout << "Dados Recarregados" << endl;
    complexos1->imprime();

    delete complexos1;

    return 0;
}


