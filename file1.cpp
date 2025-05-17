#include <iostream>
using namespace std;

class buku;
{
    string judul;
public:
    buku setJudul(string Judul)
    {
        this->judul = judul;
        return *this; //chain fungsion
    }

    string getJudul()
    {
        return this->judul;
    }
};