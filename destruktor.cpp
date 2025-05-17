#include <iostream>
using namespace std;

class angka{
private:
    int *arr;
    int panjang;
public:
    angka(int); //constructor
    ~angka() //destructor
    void cetakData();
    void isiData();
};
//Definisi member fucton
angka::angka(int i){ //constructor
    panjang = i;
    arr = new int[i];
    isiData();
}

angka::~angka(){ //descructor
    cout << endl;
    cetakData();
    delete[]arr;
    cout << "Alamat array sudah dilepaskan"<<endl;
}