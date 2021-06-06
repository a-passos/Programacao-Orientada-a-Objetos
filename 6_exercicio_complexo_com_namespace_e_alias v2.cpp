#include <iostream>
#include <math.h>

using namespace std;


namespace ComplexMath
{
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
        friend Complexo soma(Complexo *complexo1,Complexo *complexo2);
        friend Complexo subtracao(Complexo *complexo1,Complexo *complexo2);
        friend Complexo multiplicacao(Complexo *complexo1,Complexo *complexo2);
        friend Complexo divisao(Complexo *complexo1,Complexo *complexo2);
    };

    Complexo soma(Complexo *complexo1,Complexo *complexo2)
    {
        Complexo resultado;
        resultado.real = complexo1->real+complexo2->real;
        resultado.imag = complexo1->imag+complexo2->imag;
        return resultado;
    }
    Complexo subtracao(Complexo *complexo1,Complexo *complexo2)
    {
        Complexo resultado;
        resultado.real = complexo1->real-complexo2->real;
        resultado.imag = complexo1->imag-complexo2->imag;
        return resultado;
    }
    Complexo multiplicacao(Complexo *complexo1,Complexo *complexo2)
    {
        float modulo1 = complexo1->getMagnitude();
        float angulo1 = complexo1->getAngulo();
        float modulo2 = complexo2->getMagnitude();
        float angulo2 = complexo2->getAngulo();
        float moduloResultante = modulo1 * modulo2;
        float anguloResultante = angulo1 + angulo2;
        Complexo resultado;
        resultado.real = moduloResultante * cos(anguloResultante);
        resultado.imag = moduloResultante * sin(anguloResultante);
        return resultado;
    }
    Complexo divisao(Complexo *complexo1,Complexo *complexo2)
    {
        float modulo1 = complexo1->getMagnitude();
        float angulo1 = complexo2->getAngulo();
        float modulo2 = complexo2->getMagnitude();
        float angulo2 = complexo2->getAngulo();
        float moduloResultante = modulo1 / modulo2;
        float anguloResultante = angulo1 - angulo2;
        Complexo resultado;
        resultado.real = moduloResultante * cos(anguloResultante);
        resultado.imag = moduloResultante * sin(anguloResultante);
        return resultado;
    }
    Complexo comparaPorModulo(Complexo * complexo1,Complexo * complexo2)
    {
        if(complexo1->getMagnitude()>complexo2->getMagnitude())
            return (*complexo1);
        else
            return (*complexo2);
    }
}

namespace CM = ComplexMath;

int main()
{
    CM::Complexo complexo1(6,8);
    CM::Complexo complexo2(3,4);
    cout << "numero1:" << complexo1.toString() << endl;
    cout << "numero2:" << complexo2.toString() << endl;

    cout << endl << "Forma 1:" << endl;

    CM::Complexo complexo3 = CM::soma(&complexo1,&complexo2);
    cout << "numero1 + numero2 =" << complexo3.toString() << endl;

    complexo3 = CM::subtracao(&complexo1,&complexo2);
    cout << "numero1 - numero2 =" << complexo3.toString() << endl;

    complexo3 = CM::multiplicacao(&complexo1,&complexo2);
    cout << "numero1 x numero2 =" << complexo3.toString() << endl;

    complexo3 = CM::divisao(&complexo1,&complexo2);
    cout << "numero1 / numero2 =" << complexo3.toString() << endl;

    cout << endl<< "Forma 2:" << endl;

    cout << "numero1 + numero2 =" << CM::soma(&complexo1,&complexo2).toString() << endl;
    cout << "numero1 - numero2 =" << CM::subtracao(&complexo1,&complexo2).toString() << endl;
    cout << "numero1 x numero2 =" << CM::multiplicacao(&complexo1,&complexo2).toString() << endl;
    cout << "numero1 / numero2 =" << CM::divisao(&complexo1,&complexo2).toString() << endl;

    return 0;
}


