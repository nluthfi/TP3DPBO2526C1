#ifndef DEVELOPER_CPP
#define DEVELOPER_CPP

#include <iostream>
#include <string>

using namespace std;

// Kelas Komponen: Developer
// Merepresentasikan studio pengembang game (bagian dari ProdukGame via Komposisi)
class Developer {
private:
    string namaDev;
    string negaraAsal;
    int tahunBerdiri;

public:
    // Constructor default
    Developer() {
        this->namaDev = "";
        this->negaraAsal = "";
        this->tahunBerdiri = 0;
    }

    // Constructor dengan parameter
    Developer(string namaDev, string negaraAsal, int tahunBerdiri) {
        this->namaDev = namaDev;
        this->negaraAsal = negaraAsal;
        this->tahunBerdiri = tahunBerdiri;
    }

    // Setter
    void setNamaDev(const string &namaDev) {
        this->namaDev = namaDev;
    }

    void setNegaraAsal(const string &negaraAsal) {
        this->negaraAsal = negaraAsal;
    }

    void setTahunBerdiri(int tahunBerdiri) {
        this->tahunBerdiri = tahunBerdiri;
    }

    // Getter
    string getNamaDev() const {
        return namaDev;
    }

    string getNegaraAsal() const {
        return negaraAsal;
    }

    int getTahunBerdiri() const {
        return tahunBerdiri;
    }

    // Destructor
    ~Developer() {}
};

#endif
