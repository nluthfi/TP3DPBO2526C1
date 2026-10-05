#ifndef GAMEDIGITAL_CPP
#define GAMEDIGITAL_CPP

#include "ProdukGame.cpp"
#include <iostream>
#include <string>

using namespace std;

// Subclass: GameDigital (turunan dari ProdukGame)
// Hierarchical Inheritance: Child 2 dari ProdukGame
class GameDigital : public ProdukGame {
private:
    string platformDRM;
    double ukuranGB;
    string kodeAktivasi;

public:
    // Constructor default
    GameDigital() : ProdukGame() {
        this->platformDRM = "";
        this->ukuranGB = 0.0;
        this->kodeAktivasi = "";
    }

    // Constructor dengan parameter
    GameDigital(string idProduk, string judul, double harga, Developer developer,
                string platformDRM, double ukuranGB, string kodeAktivasi)
        : ProdukGame(idProduk, judul, harga, developer) {
        this->platformDRM = platformDRM;
        this->ukuranGB = ukuranGB;
        this->kodeAktivasi = kodeAktivasi;
    }

    // Setter
    void setPlatformDRM(const string &platformDRM) {
        this->platformDRM = platformDRM;
    }

    void setUkuranGB(double ukuranGB) {
        this->ukuranGB = ukuranGB;
    }

    void setKodeAktivasi(const string &kodeAktivasi) {
        this->kodeAktivasi = kodeAktivasi;
    }

    // Getter
    string getPlatformDRM() const {
        return platformDRM;
    }

    double getUkuranGB() const {
        return ukuranGB;
    }

    string getKodeAktivasi() const {
        return kodeAktivasi;
    }

    // Destructor
    ~GameDigital() {}
};

#endif
