#include <iostream>

using namespace std;

class Object
{
public:
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

};


int main()
{
    TocadorDeMidia tm;
    cout << tm.toString() << endl;
    return 0;
}

