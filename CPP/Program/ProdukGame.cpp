#ifndef PRODUKGAME_CPP
#define PRODUKGAME_CPP

#include "Developer.cpp"
#include <iostream>
#include <string>

using namespace std;

// Base Class: ProdukGame
// Merepresentasikan data umum game, memiliki objek Developer (Komposisi)
class ProdukGame {
protected:
    string idProduk;
    string judul;
    double harga;
    Developer developer; // Komposisi: Objek Developer di dalam ProdukGame

public:
    // Constructor default
    ProdukGame() {
        this->idProduk = "";
        this->judul = "";
        this->harga = 0.0;
        this->developer = Developer();
    }

    // Constructor dengan parameter
    ProdukGame(string idProduk, string judul, double harga, Developer developer) {
        this->idProduk = idProduk;
        this->judul = judul;
        this->harga = harga;
        this->developer = developer;
    }

    // Setter
    void setIdProduk(const string &idProduk) {
        this->idProduk = idProduk;
    }

    void setJudul(const string &judul) {
        this->judul = judul;
    }

    void setHarga(double harga) {
        this->harga = harga;
    }

    void setDeveloper(const Developer &developer) {
        this->developer = developer;
    }

    // Getter
    string getIdProduk() const {
        return idProduk;
    }

    string getJudul() const {
        return judul;
    }

    double getHarga() const {
        return harga;
    }

    Developer getDeveloper() const {
        return developer;
    }

    // Destructor
    virtual ~ProdukGame() {}
};

#endif
