#include <iostream>
#include <string>
using namespace std;

class mahasiswa {
private:
    string nama;
    int nim;
    float nilai;

public:
    mahasiswa(string n, int i) : nama(n), nim(i), nilai(0) {}

    void tampil() {
        cout << "Nama Mahasiswa : " << nama << endl;
        cout << "NIM            : " << nim << endl;
        cout << "Nilai          : " << nilai << endl << endl;
    }
};

class dosen {
private:
    string nama;
    string nidn;
    string pangkat;
    float gaji;
    
public:
    dosen(string n, string id, string p, float g) : nama(n), nidn(id), pangkat(p), gaji(g) {}
    friend float aksesGaji(Dosen* d);
    friend class Staff;
    void beriNilai(mahasiswa* m, float nilai);
};