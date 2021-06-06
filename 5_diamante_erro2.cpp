#include <iostream>

using namespace std;

class Object
{
public:
    int atributo;
    string toString()
    {
        return "Objeto";
    }
};

class TocadorDeVideo : public Object
{
public :
    string toString()
    {
        return "TocadorDeVideo";
    }
};

class TocadorDeAudio : public Object
{
public :
    string toString()
    {
        return "TocadorDeAudio";
    }
};

class TocadorDeMidia : public TocadorDeAudio, public TocadorDeVideo
{
public:
    string toString()
    {
        return "TocadorDeMidia";
    };
};


int main()
{
    TocadorDeMidia tm;
    tm.atributo = 2; // duplicado!
    cout << tm.toString() << endl;
    return 0;
}

