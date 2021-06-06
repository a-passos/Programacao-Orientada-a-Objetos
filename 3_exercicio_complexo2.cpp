#include <iostream>
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

class VetorComplexo
{
    private:
        int tamanho;
    public:
        Complexo * elementos;
        VetorComplexo(int numero)
        {
            elementos = new Complexo[numero];
            tamanho = numero;
        }
        ~VetorComplexo()
        {
            delete [] elementos;
            cout << "Destruiu" << endl;
        }
        int getTamanho()
        {
            return tamanho;
        }
        void mostra()
        {
            for(int i=0;i<tamanho;i++)
                cout << elementos[i].stringRetangular() << endl;
        }
};

int main()
{
    VetorComplexo * complexos1 = new VetorComplexo(10);
    VetorComplexo complexos2(10);
    complexos1->mostra();
    complexos2.mostra();
    delete complexos1;

    return 0;
}
