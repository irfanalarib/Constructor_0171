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

    friend class dosen;
};

class dosen {
private:
    string nama;
    string nidn;
    string pangkat;
    float gaji;

public:
    dosen(string n, string id, string p, float g) : nama(n), nidn(id), pangkat(p), gaji(g) {}
    friend float aksesGaji(dosen* d);
    friend class Staff;
    void beriNilai(mahasiswa* m, float nilai);
};

class Staff {
private:
    string nama;
    int idStaff;
    float gaji;

public:
    Staff(string n, int id, float g) : nama(n), idStaff(id), gaji(g) {}

    void ubahPangkat(dosen* d, string pangkatBaru) {
        d->pangkat = pangkatBaru;
    }

      friend float lihatGajiStaff(Staff* s);
};

float aksesGaji(dosen* d) {
    return d->gaji;
}

float lihatGajiStaff(Staff* s) {
    return s->gaji;
}

class Universitas {
public:
    void tampilGajiDosen(dosen* d) {
        cout << "Gaji Dosen     : " << aksesGaji(d) << endl;
    }

    void tampilGajiStaff(Staff* s) {
        cout << "Gaji Staff     : " << lihatGajiStaff(s) << endl;
    }
};

void dosen::beriNilai(mahasiswa* m, float nilai) {
    m->nilai = nilai;
}

int main() {
    mahasiswa m1("Irfan", 24171);
    dosen d1("Pak Haris", "9876", "Lektor", 9000000);
    Staff s1("Pak Andi", 1001, 5000000);
    Universitas u;

    d1.beriNilai(&m1, 85.5);
    m1.tampil();

    cout << "Pangkat sebelum diubah: Lektor" << endl;
    s1.ubahPangkat(&d1, "Guru Besar");
    cout << "Pangkat sesudah diubah oleh staff." << endl;

    u.tampilGajiDosen(&d1);
    u.tampilGajiStaff(&s1);

    return 0;
}