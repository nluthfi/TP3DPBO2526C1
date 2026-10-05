#ifndef TOKOGAME_CPP
#define TOKOGAME_CPP

#include "GameFisik.cpp"
#include "GameDigital.cpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Container Class: TokoGame
// Menerapkan Composition dan Array of Objects (vector<GameFisik> & vector<GameDigital>)
class TokoGame {
private:
    string namaToko;
    string alamat;
    vector<GameFisik> daftarFisik;       // Array of Object: Game Fisik
    vector<GameDigital> daftarDigital;   // Array of Object: Game Digital

    // Helper membuat garis pemisah tabel
    static string buatGaris(const vector<int> &lebar) {
        string garis = "+";
        for (int w : lebar) {
            garis += string(w, '-') + "+";
        }
        return garis;
    }

    // Helper format float/double
    static string formatDouble(double val) {
        ostringstream oss;
        oss << fixed << setprecision(1) << val;
        return oss.str();
    }

public:
    // Constructor default
    TokoGame() {
        this->namaToko = "";
        this->alamat = "";
    }

    // Constructor dengan parameter
    TokoGame(string namaToko, string alamat) {
        this->namaToko = namaToko;
        this->alamat = alamat;
    }

    // Setter & Getter
    void setNamaToko(const string &namaToko) { this->namaToko = namaToko; }
    void setAlamat(const string &alamat) { this->alamat = alamat; }
    string getNamaToko() const { return namaToko; }
    string getAlamat() const { return alamat; }

    vector<GameFisik>& getDaftarFisik() { return daftarFisik; }
    vector<GameDigital>& getDaftarDigital() { return daftarDigital; }

    // Tambah data ke dalam Array of Object
    void tambahGameFisik(const GameFisik &g) {
        daftarFisik.push_back(g);
    }

    void tambahGameDigital(const GameDigital &g) {
        daftarDigital.push_back(g);
    }

    // Pencarian berdasarkan ID
    int findFisik(const string &id) const {
        for (size_t i = 0; i < daftarFisik.size(); ++i) {
            if (daftarFisik[i].getIdProduk() == id) return (int)i;
        }
        return -1;
    }

    int findDigital(const string &id) const {
        for (size_t i = 0; i < daftarDigital.size(); ++i) {
            if (daftarDigital[i].getIdProduk() == id) return (int)i;
        }
        return -1;
    }

    // Hapus data
    bool hapusFisik(int index) {
        if (index >= 0 && index < (int)daftarFisik.size()) {
            daftarFisik.erase(daftarFisik.begin() + index);
            return true;
        }
        return false;
    }

    bool hapusDigital(int index) {
        if (index >= 0 && index < (int)daftarDigital.size()) {
            daftarDigital.erase(daftarDigital.begin() + index);
            return true;
        }
        return false;
    }

    // Tampilkan profil toko
    void tampilkanProfil() const {
        cout << "\n============================================================\n";
        cout << "PROFIL TOKO: " << namaToko << " (" << alamat << ")\n";
        cout << "Total Inventaris: " << daftarFisik.size() << " Game Fisik, " 
             << daftarDigital.size() << " Game Digital\n";
        cout << "============================================================\n";
    }

    // Tabel dinamis Game Fisik
    void tampilkanTabelFisik() const {
        if (daftarFisik.empty()) {
            cout << "\n(Katalog Game Fisik Masih Kosong)\n";
            return;
        }

        vector<string> headers = {"ID", "Judul Game", "Harga", "Developer", "Asal Dev", "Est.", "Platform", "Kondisi", "Berat"};
        vector<int> colW(headers.size());

        for (size_t i = 0; i < headers.size(); ++i) {
            colW[i] = (int)headers[i].length();
        }

        for (const auto &g : daftarFisik) {
            colW[0] = max(colW[0], (int)g.getIdProduk().length());
            colW[1] = max(colW[1], (int)g.getJudul().length());
            colW[2] = max(colW[2], (int)("Rp " + to_string((long long)g.getHarga())).length());
            colW[3] = max(colW[3], (int)g.getDeveloper().getNamaDev().length());
            colW[4] = max(colW[4], (int)g.getDeveloper().getNegaraAsal().length());
            colW[5] = max(colW[5], (int)to_string(g.getDeveloper().getTahunBerdiri()).length());
            colW[6] = max(colW[6], (int)g.getPlatform().length());
            colW[7] = max(colW[7], (int)g.getKondisi().length());
            colW[8] = max(colW[8], (int)(to_string(g.getBeratGram()) + " gr").length());
        }

        for (size_t i = 0; i < colW.size(); ++i) {
            colW[i] += 2;
        }

        string garis = buatGaris(colW);
        cout << "\n>> KATALOG GAME FISIK (DISC / CARTRIDGE) <<\n";
        cout << garis << "\n";
        cout << "|";
        for (size_t i = 0; i < headers.size(); ++i) {
            cout << " " << left << setw(colW[i] - 1) << headers[i] << "|";
        }
        cout << "\n" << garis << "\n";

        for (const auto &g : daftarFisik) {
            cout << "| " << left << setw(colW[0] - 1) << g.getIdProduk()
                 << "| " << setw(colW[1] - 1) << g.getJudul()
                 << "| " << setw(colW[2] - 1) << ("Rp " + to_string((long long)g.getHarga()))
                 << "| " << setw(colW[3] - 1) << g.getDeveloper().getNamaDev()
                 << "| " << setw(colW[4] - 1) << g.getDeveloper().getNegaraAsal()
                 << "| " << setw(colW[5] - 1) << g.getDeveloper().getTahunBerdiri()
                 << "| " << setw(colW[6] - 1) << g.getPlatform()
                 << "| " << setw(colW[7] - 1) << g.getKondisi()
                 << "| " << setw(colW[8] - 1) << (to_string(g.getBeratGram()) + " gr")
                 << "|\n";
        }
        cout << garis << "\n";
    }

    // Tabel dinamis Game Digital
    void tampilkanTabelDigital() const {
        if (daftarDigital.empty()) {
            cout << "\n(Katalog Game Digital Masih Kosong)\n";
            return;
        }

        vector<string> headers = {"ID", "Judul Game", "Harga", "Developer", "Asal Dev", "Est.", "Platform DRM", "Ukuran", "Kode Aktivasi"};
        vector<int> colW(headers.size());

        for (size_t i = 0; i < headers.size(); ++i) {
            colW[i] = (int)headers[i].length();
        }

        for (const auto &g : daftarDigital) {
            colW[0] = max(colW[0], (int)g.getIdProduk().length());
            colW[1] = max(colW[1], (int)g.getJudul().length());
            colW[2] = max(colW[2], (int)("Rp " + to_string((long long)g.getHarga())).length());
            colW[3] = max(colW[3], (int)g.getDeveloper().getNamaDev().length());
            colW[4] = max(colW[4], (int)g.getDeveloper().getNegaraAsal().length());
            colW[5] = max(colW[5], (int)to_string(g.getDeveloper().getTahunBerdiri()).length());
            colW[6] = max(colW[6], (int)g.getPlatformDRM().length());
            colW[7] = max(colW[7], (int)(formatDouble(g.getUkuranGB()) + " GB").length());
            colW[8] = max(colW[8], (int)g.getKodeAktivasi().length());
        }

        for (size_t i = 0; i < colW.size(); ++i) {
            colW[i] += 2;
        }

        string garis = buatGaris(colW);
        cout << "\n>> KATALOG GAME DIGITAL (SERIAL KEY / DRM) <<\n";
        cout << garis << "\n";
        cout << "|";
        for (size_t i = 0; i < headers.size(); ++i) {
            cout << " " << left << setw(colW[i] - 1) << headers[i] << "|";
        }
        cout << "\n" << garis << "\n";

        for (const auto &g : daftarDigital) {
            cout << "| " << left << setw(colW[0] - 1) << g.getIdProduk()
                 << "| " << setw(colW[1] - 1) << g.getJudul()
                 << "| " << setw(colW[2] - 1) << ("Rp " + to_string((long long)g.getHarga()))
                 << "| " << setw(colW[3] - 1) << g.getDeveloper().getNamaDev()
                 << "| " << setw(colW[4] - 1) << g.getDeveloper().getNegaraAsal()
                 << "| " << setw(colW[5] - 1) << g.getDeveloper().getTahunBerdiri()
                 << "| " << setw(colW[6] - 1) << g.getPlatformDRM()
                 << "| " << setw(colW[7] - 1) << (formatDouble(g.getUkuranGB()) + " GB")
                 << "| " << setw(colW[8] - 1) << g.getKodeAktivasi()
                 << "|\n";
        }
        cout << garis << "\n";
    }

    // Tampilkan semua katalog
    void tampilkanSemua() const {
        tampilkanProfil();
        tampilkanTabelFisik();
        tampilkanTabelDigital();
    }

    // Destructor
    ~TokoGame() {}
};

#endif
