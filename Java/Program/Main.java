import java.util.Locale;
import java.util.Scanner;

public class Main {
    private static TokoGame toko = new TokoGame("Pixel Vault Games", "Jl. Ganeca No. 10, Bandung");
    private static Scanner sc = new Scanner(System.in);
    private static boolean isRedirected = (System.console() == null);

    // Helper membaca baris dengan auto-echo jika stdin di-redirect
    private static String bacaBaris() {
        if (!sc.hasNextLine()) return "";
        String line = sc.nextLine();
        if (isRedirected) {
            System.out.println(line);
        }
        return line.trim();
    }

    // Cek apakah ID sudah ada
    private static boolean isIdExists(String id) {
        return (toko.findFisik(id) != -1 || toko.findDigital(id) != -1);
    }

    // 1. Tambah Data
    private static void tambahData() {
        System.out.println("\n=== TAMBAH DATA PRODUK GAME ===");
        System.out.println("Pilih Jenis Game:");
        System.out.println("1. Game Fisik (Kaset / Cartridge)");
        System.out.println("2. Game Digital (Serial Key / DRM)");
        System.out.print("Pilihan: ");

        String jenisStr = bacaBaris();
        if (jenisStr.isEmpty()) return;

        int jenis;
        try {
            jenis = Integer.parseInt(jenisStr);
        } catch (NumberFormatException e) {
            System.out.println("Pilihan tidak valid.");
            return;
        }

        if (jenis != 1 && jenis != 2) {
            System.out.println("Jenis game tidak valid.");
            return;
        }

        System.out.print("ID Produk          : ");
        String id = bacaBaris();
        if (id.isEmpty()) return;

        if (isIdExists(id)) {
            System.out.println("Error: ID produk sudah ada di sistem.");
            return;
        }

        System.out.print("Judul Game         : ");
        String judul = bacaBaris();

        System.out.print("Harga (Rp)         : ");
        double harga;
        try {
            harga = Double.parseDouble(bacaBaris());
        } catch (NumberFormatException e) {
            System.out.println("Input harga tidak valid.");
            return;
        }

        System.out.print("Nama Developer     : ");
        String namaDev = bacaBaris();

        System.out.print("Negara Asal Dev    : ");
        String negaraDev = bacaBaris();

        System.out.print("Tahun Berdiri Dev  : ");
        int tahunDev;
        try {
            tahunDev = Integer.parseInt(bacaBaris());
        } catch (NumberFormatException e) {
            System.out.println("Input tahun tidak valid.");
            return;
        }

        Developer dev = new Developer(namaDev, negaraDev, tahunDev);

        if (jenis == 1) {
            System.out.print("Platform Konsol    : ");
            String platform = bacaBaris();

            System.out.print("Kondisi Barang     : ");
            String kondisi = bacaBaris();

            System.out.print("Berat Fisik (gram) : ");
            int berat;
            try {
                berat = Integer.parseInt(bacaBaris());
            } catch (NumberFormatException e) {
                System.out.println("Input berat tidak valid.");
                return;
            }

            GameFisik gf = new GameFisik(id, judul, harga, dev, platform, kondisi, berat);
            toko.tambahGameFisik(gf);
            System.out.println("\n✅ Game Fisik \"" + judul + "\" berhasil ditambahkan!");
        } else {
            System.out.print("Platform DRM       : ");
            String platformDRM = bacaBaris();

            System.out.print("Ukuran Berkas (GB) : ");
            double ukuranGB;
            try {
                ukuranGB = Double.parseDouble(bacaBaris());
            } catch (NumberFormatException e) {
                System.out.println("Input ukuran tidak valid.");
                return;
            }

            System.out.print("Kode Aktivasi      : ");
            String kode = bacaBaris();

            GameDigital gd = new GameDigital(id, judul, harga, dev, platformDRM, ukuranGB, kode);
            toko.tambahGameDigital(gd);
            System.out.println("\n✅ Game Digital \"" + judul + "\" berhasil ditambahkan!");
        }
    }

    // 2. Tampilkan Data
    private static void tampilkanData() {
        toko.tampilkanSemua();
    }

    // 3. Update Data
    private static void updateData() {
        System.out.println("\n=== UPDATE DATA GAME ===");
        System.out.print("Masukkan ID Game: ");
        String id = bacaBaris();
        if (id.isEmpty()) return;

        int idxF = toko.findFisik(id);
        int idxD = toko.findDigital(id);

        if (idxF == -1 && idxD == -1) {
            System.out.println("Data game dengan ID \"" + id + "\" tidak ditemukan.");
            return;
        }

        System.out.print("Judul Baru        : ");
        String judul = bacaBaris();

        System.out.print("Harga Baru (Rp)   : ");
        double harga;
        try {
            harga = Double.parseDouble(bacaBaris());
        } catch (NumberFormatException e) { return; }

        System.out.print("Developer Baru    : ");
        String namaDev = bacaBaris();

        System.out.print("Asal Negara Dev   : ");
        String negaraDev = bacaBaris();

        System.out.print("Tahun Berdiri Dev : ");
        int tahunDev;
        try {
            tahunDev = Integer.parseInt(bacaBaris());
        } catch (NumberFormatException e) { return; }

        Developer devBaru = new Developer(namaDev, negaraDev, tahunDev);

        if (idxF != -1) {
            System.out.print("Platform Baru     : ");
            String platform = bacaBaris();

            System.out.print("Kondisi Baru      : ");
            String kondisi = bacaBaris();

            System.out.print("Berat Baru (gram) : ");
            int berat;
            try {
                berat = Integer.parseInt(bacaBaris());
            } catch (NumberFormatException e) { return; }

            GameFisik gf = toko.getDaftarFisik().get(idxF);
            gf.setJudul(judul);
            gf.setHarga(harga);
            gf.setDeveloper(devBaru);
            gf.setPlatform(platform);
            gf.setKondisi(kondisi);
            gf.setBeratGram(berat);
            System.out.println("\n✅ Data Game Fisik ID \"" + id + "\" berhasil diperbarui!");
        } else {
            System.out.print("Platform DRM Baru : ");
            String drm = bacaBaris();

            System.out.print("Ukuran Baru (GB)  : ");
            double ukuran;
            try {
                ukuran = Double.parseDouble(bacaBaris());
            } catch (NumberFormatException e) { return; }

            System.out.print("Kode Aktivasi Baru: ");
            String kode = bacaBaris();

            GameDigital gd = toko.getDaftarDigital().get(idxD);
            gd.setJudul(judul);
            gd.setHarga(harga);
            gd.setDeveloper(devBaru);
            gd.setPlatformDRM(drm);
            gd.setUkuranGB(ukuran);
            gd.setKodeAktivasi(kode);
            System.out.println("\n✅ Data Game Digital ID \"" + id + "\" berhasil diperbarui!");
        }
    }

    // 4. Hapus Data
    private static void hapusData() {
        System.out.println("\n=== HAPUS DATA GAME ===");
        System.out.print("Masukkan ID Game: ");
        String id = bacaBaris();
        if (id.isEmpty()) return;

        int idxF = toko.findFisik(id);
        int idxD = toko.findDigital(id);

        if (idxF == -1 && idxD == -1) {
            System.out.println("Data game tidak ditemukan.");
            return;
        }

        String judulTarget = (idxF != -1) ? toko.getDaftarFisik().get(idxF).getJudul() 
                                          : toko.getDaftarDigital().get(idxD).getJudul();

        System.out.println("Game yang akan dihapus: " + judulTarget);
        System.out.print("Yakin hapus? (y/n): ");
        String konfirmasi = bacaBaris();

        if (konfirmasi.equalsIgnoreCase("y")) {
            if (idxF != -1) {
                toko.hapusFisik(idxF);
            } else {
                toko.hapusDigital(idxD);
            }
            System.out.println("\n✅ Data berhasil dihapus.");
        } else {
            System.out.println("\nPenghapusan dibatalkan.");
        }
    }

    // 5. Cari Data
    private static void cariData() {
        System.out.println("\n=== CARI DATA GAME ===");
        System.out.print("Masukkan ID Game: ");
        String id = bacaBaris();
        if (id.isEmpty()) return;

        int idxF = toko.findFisik(id);
        int idxD = toko.findDigital(id);

        if (idxF != -1) {
            GameFisik g = toko.getDaftarFisik().get(idxF);
            System.out.println("\nData Game Fisik Ditemukan:");
            System.out.println("ID Produk       : " + g.getIdProduk());
            System.out.println("Judul Game      : " + g.getJudul());
            System.out.println("Harga           : Rp " + (long)g.getHarga());
            System.out.println("Developer       : " + g.getDeveloper().getNamaDev() + " (" 
                               + g.getDeveloper().getNegaraAsal() + ", Est. " 
                               + g.getDeveloper().getTahunBerdiri() + ")");
            System.out.println("Platform        : " + g.getPlatform());
            System.out.println("Kondisi         : " + g.getKondisi());
            System.out.println("Berat           : " + g.getBeratGram() + " gr");
        } else if (idxD != -1) {
            GameDigital g = toko.getDaftarDigital().get(idxD);
            System.out.println("\nData Game Digital Ditemukan:");
            System.out.println("ID Produk       : " + g.getIdProduk());
            System.out.println("Judul Game      : " + g.getJudul());
            System.out.println("Harga           : Rp " + (long)g.getHarga());
            System.out.println("Developer       : " + g.getDeveloper().getNamaDev() + " (" 
                               + g.getDeveloper().getNegaraAsal() + ", Est. " 
                               + g.getDeveloper().getTahunBerdiri() + ")");
            System.out.println("Platform DRM    : " + g.getPlatformDRM());
            System.out.printf(Locale.US, "Ukuran File     : %.1f GB\n", g.getUkuranGB());
            System.out.println("Kode Aktivasi   : " + g.getKodeAktivasi());
        } else {
            System.out.println("Data tidak ditemukan.");
        }
    }

    // Inisialisasi Data Default
    private static void inisialisasiDataDefault() {
        Developer fromsoft = new Developer("FromSoftware", "Jepang", 1986);
        Developer santaMonica = new Developer("Santa Monica Studio", "Amerika Serikat", 1999);
        Developer cdpr = new Developer("CD Projekt Red", "Polandia", 1994);
        Developer capcom = new Developer("Capcom", "Jepang", 1979);

        toko.tambahGameFisik(new GameFisik("GF001", "Elden Ring", 750000, fromsoft, "PlayStation 5", "Segel Baru", 120));
        toko.tambahGameFisik(new GameFisik("GF002", "God of War Ragnarok", 680000, santaMonica, "PlayStation 5", "Bekas Like-New", 130));
        toko.tambahGameFisik(new GameFisik("GF003", "Resident Evil 4 Remake", 590000, capcom, "Nintendo Switch", "Segel Baru", 80));

        toko.tambahGameDigital(new GameDigital("GD001", "Cyberpunk 2077: Phantom Liberty", 450000, cdpr, "Steam", 70.0, "CP77-PL-9921-X"));
        toko.tambahGameDigital(new GameDigital("GD002", "Armored Core VI", 600000, fromsoft, "Steam", 60.5, "AC6-FIRES-7712-B"));
    }

    private static void menu() {
        while (true) {
            System.out.println("\n==============================");
            System.out.println("    SISTEM DATA TOKO GAME");
            System.out.println("==============================");
            System.out.println("1. Tambah Data");
            System.out.println("2. Tampilkan Data");
            System.out.println("3. Update Data");
            System.out.println("4. Hapus Data");
            System.out.println("5. Cari Data");
            System.out.println("0. Keluar");
            System.out.println("==============================");
            System.out.print("Pilih menu: ");

            String pilihanStr = bacaBaris();
            if (pilihanStr.isEmpty()) break;

            int pilihan;
            try {
                pilihan = Integer.parseInt(pilihanStr);
            } catch (NumberFormatException e) {
                System.out.println("Pilihan tidak valid.");
                continue;
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
                    System.out.println("\nProgram selesai.");
                    return;
                default:
                    System.out.println("Pilihan tidak valid.");
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("=== PROGRAM TOKO GAME ===");
        inisialisasiDataDefault();
        menu();
    }
}
