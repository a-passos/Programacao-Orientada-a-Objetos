#include <iostream>
#include <math.h>

using namespace std;

class Complexo
{
    private:
        float real;
        float imag;
    public:
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

int main()
{
    Complexo complexo1(3,4);
    Complexo complexo2(6,8);
    cout << "Parte real: " << complexo1.getReal() << endl;
    cout << "Parte imaginaria: " << complexo1.getImag() << endl;
    cout << "Magnitude: " << complexo1.getMagnitude() << endl;
    cout << "Angulo: " << complexo1.getAngulo() << endl;
    cout << "Forma retangular: " << complexo1.stringRetangular() << endl;
    cout << "Forma polar: " << complexo1.stringPolar() << endl;
    cout << complexo1.toString() << endl;
    complexo1.soma(&complexo2);
    cout << "Soma:" << complexo1.stringRetangular() << endl;
    complexo1.subtracao(&complexo2);
    cout << "Subtracao:" << complexo1.stringRetangular() << endl;
    complexo1.multiplicacao(&complexo2);
    cout << "Multiplicacao:" << complexo1.stringPolar() << endl;
    complexo1.divisao(&complexo2);
    cout << "Divisao:" << complexo1.stringPolar() << endl;
    cout << "Maior magnitude:" << comparaPorModulo(&complexo1,&complexo2).toString() << endl;

    return 0;
}

