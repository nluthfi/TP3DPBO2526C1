#ifndef GAMEFISIK_CPP
#define GAMEFISIK_CPP

#include "ProdukGame.cpp"
#include <iostream>
#include <string>

using namespace std;

// Subclass: GameFisik (turunan dari ProdukGame)
// Hierarchical Inheritance: Child 1 dari ProdukGame
class GameFisik : public ProdukGame {
private:
    string platform;
    string kondisi;
    int beratGram;

public:
    // Constructor default
    GameFisik() : ProdukGame() {
        this->platform = "";
        this->kondisi = "";
        this->beratGram = 0;
    }

    // Constructor dengan parameter
    GameFisik(string idProduk, string judul, double harga, Developer developer,
              string platform, string kondisi, int beratGram)
        : ProdukGame(idProduk, judul, harga, developer) {
        this->platform = platform;
        this->kondisi = kondisi;
        this->beratGram = beratGram;
    }

    // Setter
    void setPlatform(const string &platform) {
        this->platform = platform;
    }

    void setKondisi(const string &kondisi) {
        this->kondisi = kondisi;
    }

    void setBeratGram(int beratGram) {
        this->beratGram = beratGram;
    }

    // Getter
    string getPlatform() const {
        return platform;
    }

    string getKondisi() const {
        return kondisi;
    }

    int getBeratGram() const {
        return beratGram;
    }

    // Destructor
    ~GameFisik() {}
};

#endif
