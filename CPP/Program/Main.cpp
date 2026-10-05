#include "TokoGame.cpp"
#include <iostream>
#include <limits>
#include <string>
#include <unistd.h>

using namespace std;

TokoGame toko("Pixel Vault Games", "Jl. Ganeca No. 10, Bandung");

// Cek apakah input di-redirect dari file (misal via `./main < input.txt`)
bool isRedirected() {
    return !isatty(STDIN_FILENO);
}

// Helper untuk membaca baris string dengan auto-echo jika stdin di-redirect
bool bacaInput(string &val) {
    if (!getline(cin, val)) return false;
    if (isRedirected()) {
        cout << val << "\n";
    }
    return true;
}

// Helper untuk membaca angka dengan auto-echo jika stdin di-redirect
template<typename T>
bool bacaAngka(T &val) {
    if (!(cin >> val)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    if (isRedirected()) {
        cout << val << "\n";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}

// Cek apakah ID sudah ada
bool isIdExists(const string &id) {
    return (toko.findFisik(id) != -1 || toko.findDigital(id) != -1);
}

// 1. Tambah Data
void tambahData() {
    cout << "\n=== TAMBAH DATA PRODUK GAME ===\n";
    cout << "Pilih Jenis Game:\n";
    cout << "1. Game Fisik (Kaset / Cartridge)\n";
    cout << "2. Game Digital (Serial Key / DRM)\n";
    cout << "Pilihan: ";

    int jenis;
    if (!bacaAngka(jenis)) {
        cout << "Pilihan tidak valid.\n";
        return;
    }

    if (jenis != 1 && jenis != 2) {
        cout << "Jenis game tidak valid.\n";
        return;
    }

    string id, judul, namaDev, negaraDev;
    double harga;
    int tahunDev;

    cout << "ID Produk          : ";
    if (!bacaInput(id) || id.empty()) return;

    if (isIdExists(id)) {
        cout << "Error: ID produk sudah ada di sistem.\n";
        return;
    }

    cout << "Judul Game         : ";
    if (!bacaInput(judul)) return;

    cout << "Harga (Rp)         : ";
    if (!bacaAngka(harga)) {
        cout << "Input harga tidak valid.\n";
        return;
    }

    cout << "Nama Developer     : ";
    if (!bacaInput(namaDev)) return;

    cout << "Negara Asal Dev    : ";
    if (!bacaInput(negaraDev)) return;

    cout << "Tahun Berdiri Dev  : ";
    if (!bacaAngka(tahunDev)) {
        cout << "Input tahun tidak valid.\n";
        return;
    }

    Developer dev(namaDev, negaraDev, tahunDev);

    if (jenis == 1) {
        string platform, kondisi;
        int berat;

        cout << "Platform Konsol    : ";
        if (!bacaInput(platform)) return;

        cout << "Kondisi Barang     : ";
        if (!bacaInput(kondisi)) return;

        cout << "Berat Fisik (gram) : ";
        if (!bacaAngka(berat)) {
            cout << "Input berat tidak valid.\n";
            return;
        }

        GameFisik gf(id, judul, harga, dev, platform, kondisi, berat);
        toko.tambahGameFisik(gf);
        cout << "\n✅ Game Fisik \"" << judul << "\" berhasil ditambahkan!\n";
    } else {
        string platformDRM, kode;
        double ukuranGB;

        cout << "Platform DRM       : ";
        if (!bacaInput(platformDRM)) return;

        cout << "Ukuran Berkas (GB) : ";
        if (!bacaAngka(ukuranGB)) {
            cout << "Input ukuran tidak valid.\n";
            return;
        }

        cout << "Kode Aktivasi      : ";
        if (!bacaInput(kode)) return;

        GameDigital gd(id, judul, harga, dev, platformDRM, ukuranGB, kode);
        toko.tambahGameDigital(gd);
        cout << "\n✅ Game Digital \"" << judul << "\" berhasil ditambahkan!\n";
    }
}

// 2. Tampilkan Data
void tampilkanData() {
    toko.tampilkanSemua();
}

// 3. Update Data
void updateData() {
    cout << "\n=== UPDATE DATA GAME ===\n";
    cout << "Masukkan ID Game: ";
    string id;
    if (!bacaInput(id) || id.empty()) return;

    int idxF = toko.findFisik(id);
    int idxD = toko.findDigital(id);

    if (idxF == -1 && idxD == -1) {
        cout << "Data game dengan ID \"" << id << "\" tidak ditemukan.\n";
        return;
    }

    string judul, namaDev, negaraDev;
    double harga;
    int tahunDev;

    cout << "Judul Baru        : ";
    if (!bacaInput(judul)) return;

    cout << "Harga Baru (Rp)   : ";
    if (!bacaAngka(harga)) return;

    cout << "Developer Baru    : ";
    if (!bacaInput(namaDev)) return;

    cout << "Asal Negara Dev   : ";
    if (!bacaInput(negaraDev)) return;

    cout << "Tahun Berdiri Dev : ";
    if (!bacaAngka(tahunDev)) return;

    Developer devBaru(namaDev, negaraDev, tahunDev);

    if (idxF != -1) {
        string platform, kondisi;
        int berat;

        cout << "Platform Baru     : ";
        if (!bacaInput(platform)) return;

        cout << "Kondisi Baru      : ";
        if (!bacaInput(kondisi)) return;

        cout << "Berat Baru (gram) : ";
        if (!bacaAngka(berat)) return;

        GameFisik &gf = toko.getDaftarFisik()[idxF];
        gf.setJudul(judul);
        gf.setHarga(harga);
        gf.setDeveloper(devBaru);
        gf.setPlatform(platform);
        gf.setKondisi(kondisi);
        gf.setBeratGram(berat);
        cout << "\n✅ Data Game Fisik ID \"" << id << "\" berhasil diperbarui!\n";
    } else {
        string drm, kode;
        double ukuran;

        cout << "Platform DRM Baru : ";
        if (!bacaInput(drm)) return;

        cout << "Ukuran Baru (GB)  : ";
        if (!bacaAngka(ukuran)) return;

        cout << "Kode Aktivasi Baru: ";
        if (!bacaInput(kode)) return;

        GameDigital &gd = toko.getDaftarDigital()[idxD];
        gd.setJudul(judul);
        gd.setHarga(harga);
        gd.setDeveloper(devBaru);
        gd.setPlatformDRM(drm);
        gd.setUkuranGB(ukuran);
        gd.setKodeAktivasi(kode);
        cout << "\n✅ Data Game Digital ID \"" << id << "\" berhasil diperbarui!\n";
    }
}

// 4. Hapus Data
void hapusData() {
    cout << "\n=== HAPUS DATA GAME ===\n";
    cout << "Masukkan ID Game: ";
    string id;
    if (!bacaInput(id) || id.empty()) return;

    int idxF = toko.findFisik(id);
    int idxD = toko.findDigital(id);

    if (idxF == -1 && idxD == -1) {
        cout << "Data game tidak ditemukan.\n";
        return;
    }

    string judulTarget = (idxF != -1) ? toko.getDaftarFisik()[idxF].getJudul() 
                                      : toko.getDaftarDigital()[idxD].getJudul();

    cout << "Game yang akan dihapus: " << judulTarget << "\n";
    cout << "Yakin hapus? (y/n): ";
    string konfirmasi;
    if (!bacaInput(konfirmasi)) return;

    if (konfirmasi == "y" || konfirmasi == "Y") {
        if (idxF != -1) {
            toko.hapusFisik(idxF);
        } else {
            toko.hapusDigital(idxD);
        }
        cout << "\n✅ Data berhasil dihapus.\n";
    } else {
        cout << "\nPenghapusan dibatalkan.\n";
    }
}

// 5. Cari Data
void cariData() {
    cout << "\n=== CARI DATA GAME ===\n";
    cout << "Masukkan ID Game: ";
    string id;
    if (!bacaInput(id) || id.empty()) return;

    int idxF = toko.findFisik(id);
    int idxD = toko.findDigital(id);

    if (idxF != -1) {
        const GameFisik &g = toko.getDaftarFisik()[idxF];
        cout << "\nData Game Fisik Ditemukan:\n";
        cout << "ID Produk       : " << g.getIdProduk() << "\n";
        cout << "Judul Game      : " << g.getJudul() << "\n";
        cout << "Harga           : Rp " << (long long)g.getHarga() << "\n";
        cout << "Developer       : " << g.getDeveloper().getNamaDev() << " (" 
             << g.getDeveloper().getNegaraAsal() << ", Est. " 
             << g.getDeveloper().getTahunBerdiri() << ")\n";
        cout << "Platform        : " << g.getPlatform() << "\n";
        cout << "Kondisi         : " << g.getKondisi() << "\n";
        cout << "Berat           : " << g.getBeratGram() << " gr\n";
    } else if (idxD != -1) {
        const GameDigital &g = toko.getDaftarDigital()[idxD];
        cout << "\nData Game Digital Ditemukan:\n";
        cout << "ID Produk       : " << g.getIdProduk() << "\n";
        cout << "Judul Game      : " << g.getJudul() << "\n";
        cout << "Harga           : Rp " << (long long)g.getHarga() << "\n";
        cout << "Developer       : " << g.getDeveloper().getNamaDev() << " (" 
             << g.getDeveloper().getNegaraAsal() << ", Est. " 
             << g.getDeveloper().getTahunBerdiri() << ")\n";
        cout << "Platform DRM    : " << g.getPlatformDRM() << "\n";
        cout << "Ukuran File     : " << g.getUkuranGB() << " GB\n";
        cout << "Kode Aktivasi   : " << g.getKodeAktivasi() << "\n";
    } else {
        cout << "Data tidak ditemukan.\n";
    }
}

// Inisialisasi Data Default
void inisialisasiDataDefault() {
    Developer fromsoft("FromSoftware", "Jepang", 1986);
    Developer santaMonica("Santa Monica Studio", "Amerika Serikat", 1999);
    Developer cdpr("CD Projekt Red", "Polandia", 1994);
    Developer capcom("Capcom", "Jepang", 1979);

    toko.tambahGameFisik(GameFisik("GF001", "Elden Ring", 750000, fromsoft, "PlayStation 5", "Segel Baru", 120));
    toko.tambahGameFisik(GameFisik("GF002", "God of War Ragnarok", 680000, santaMonica, "PlayStation 5", "Bekas Like-New", 130));
    toko.tambahGameFisik(GameFisik("GF003", "Resident Evil 4 Remake", 590000, capcom, "Nintendo Switch", "Segel Baru", 80));

    toko.tambahGameDigital(GameDigital("GD001", "Cyberpunk 2077: Phantom Liberty", 450000, cdpr, "Steam", 70.0, "CP77-PL-9921-X"));
    toko.tambahGameDigital(GameDigital("GD002", "Armored Core VI", 600000, fromsoft, "Steam", 60.5, "AC6-FIRES-7712-B"));
}

// Fungsi Menu Utama
void menu() {
    while (true) {
        cout << "\n==============================\n";
        cout << "    SISTEM DATA TOKO GAME\n";
        cout << "==============================\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Update Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Cari Data\n";
        cout << "0. Keluar\n";
        cout << "==============================\n";
        cout << "Pilih menu: ";

        int pilihan;
        if (!bacaAngka(pilihan)) {
            break;
        }

        switch (pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                tampilkanData();
                break;
            case 3:
                updateData();
                break;
            case 4:
                hapusData();
                break;
            case 5:
                cariData();
                break;
            case 0:
                cout << "\nProgram selesai.\n";
                return;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    }
}

int main() {
    cout << "=== PROGRAM TOKO GAME ===\n";
    inisialisasiDataDefault();
    menu();
    return 0;
}
