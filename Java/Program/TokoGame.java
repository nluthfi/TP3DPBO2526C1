import java.util.ArrayList;
import java.util.List;
import java.util.Locale;

// Container Class: TokoGame
// Menerapkan Composition dan Array of Objects (ArrayList<GameFisik> & ArrayList<GameDigital>)
public class TokoGame {
    private String namaToko;
    private String alamat;
    private List<GameFisik> daftarFisik;       // Array of Object: Game Fisik
    private List<GameDigital> daftarDigital;   // Array of Object: Game Digital

    // Helper membuat garis tabel
    private static String buatGaris(int[] lebar) {
        StringBuilder sb = new StringBuilder("+");
        for (int w : lebar) {
            sb.append("-".repeat(w)).append("+");
        }
        return sb.toString();
    }

    // Constructor default
    public TokoGame() {
        this.namaToko = "";
        this.alamat = "";
        this.daftarFisik = new ArrayList<>();
        this.daftarDigital = new ArrayList<>();
    }

    // Constructor dengan parameter
    public TokoGame(String namaToko, String alamat) {
        this.namaToko = namaToko;
        this.alamat = alamat;
        this.daftarFisik = new ArrayList<>();
        this.daftarDigital = new ArrayList<>();
    }

    // Getter & Setter
    public String getNamaToko() { return namaToko; }
    public void setNamaToko(String namaToko) { this.namaToko = namaToko; }

    public String getAlamat() { return alamat; }
    public void setAlamat(String alamat) { this.alamat = alamat; }

    public List<GameFisik> getDaftarFisik() { return daftarFisik; }
    public List<GameDigital> getDaftarDigital() { return daftarDigital; }

    // Tambah data
    public void tambahGameFisik(GameFisik g) {
        this.daftarFisik.add(g);
    }

    public void tambahGameDigital(GameDigital g) {
        this.daftarDigital.add(g);
    }

    // Cari index berdasarkan ID
    public int findFisik(String idTarget) {
        for (int i = 0; i < daftarFisik.size(); i++) {
            if (daftarFisik.get(i).getIdProduk().equals(idTarget)) {
                return i;
            }
        }
        return -1;
    }

    public int findDigital(String idTarget) {
        for (int i = 0; i < daftarDigital.size(); i++) {
            if (daftarDigital.get(i).getIdProduk().equals(idTarget)) {
                return i;
            }
        }
        return -1;
    }

    // Hapus data
    public boolean hapusFisik(int index) {
        if (index >= 0 && index < daftarFisik.size()) {
            daftarFisik.remove(index);
            return true;
        }
        return false;
    }

    public boolean hapusDigital(int index) {
        if (index >= 0 && index < daftarDigital.size()) {
            daftarDigital.remove(index);
            return true;
        }
        return false;
    }

    // Tampilkan profil toko
    public void tampilkanProfil() {
        System.out.println("\n============================================================");
        System.out.println("PROFIL TOKO: " + namaToko + " (" + alamat + ")");
        System.out.println("Total Inventaris: " + daftarFisik.size() + " Game Fisik, " 
                           + daftarDigital.size() + " Game Digital");
        System.out.println("============================================================");
    }

    // Tabel dinamis Game Fisik
    public void tampilkanTabelFisik() {
        if (daftarFisik.isEmpty()) {
            System.out.println("\n(Katalog Game Fisik Masih Kosong)");
            return;
        }

        String[] headers = {"ID", "Judul Game", "Harga", "Developer", "Asal Dev", "Est.", "Platform", "Kondisi", "Berat"};
        int[] colW = new int[headers.length];

        for (int i = 0; i < headers.length; i++) {
            colW[i] = headers[i].length();
        }

        for (GameFisik g : daftarFisik) {
            colW[0] = Math.max(colW[0], g.getIdProduk().length());
            colW[1] = Math.max(colW[1], g.getJudul().length());
            colW[2] = Math.max(colW[2], ("Rp " + (long)g.getHarga()).length());
            colW[3] = Math.max(colW[3], g.getDeveloper().getNamaDev().length());
            colW[4] = Math.max(colW[4], g.getDeveloper().getNegaraAsal().length());
            colW[5] = Math.max(colW[5], String.valueOf(g.getDeveloper().getTahunBerdiri()).length());
            colW[6] = Math.max(colW[6], g.getPlatform().length());
            colW[7] = Math.max(colW[7], g.getKondisi().length());
            colW[8] = Math.max(colW[8], (g.getBeratGram() + " gr").length());
        }

        for (int i = 0; i < colW.length; i++) {
            colW[i] += 2;
        }

        String garis = buatGaris(colW);
        System.out.println("\n>> KATALOG GAME FISIK (DISC / CARTRIDGE) <<");
        System.out.println(garis);

        StringBuilder hsb = new StringBuilder("|");
        for (int i = 0; i < headers.length; i++) {
            hsb.append(" ").append(String.format("%-" + (colW[i] - 1) + "s", headers[i])).append("|");
        }
        System.out.println(hsb.toString());
        System.out.println(garis);

        for (GameFisik g : daftarFisik) {
            String[] row = {
                g.getIdProduk(),
                g.getJudul(),
                "Rp " + (long)g.getHarga(),
                g.getDeveloper().getNamaDev(),
                g.getDeveloper().getNegaraAsal(),
                String.valueOf(g.getDeveloper().getTahunBerdiri()),
                g.getPlatform(),
                g.getKondisi(),
                g.getBeratGram() + " gr"
            };
            StringBuilder rsb = new StringBuilder("|");
            for (int i = 0; i < row.length; i++) {
                rsb.append(" ").append(String.format("%-" + (colW[i] - 1) + "s", row[i])).append("|");
            }
            System.out.println(rsb.toString());
        }

        System.out.println(garis);
    }

    // Tabel dinamis Game Digital
    public void tampilkanTabelDigital() {
        if (daftarDigital.isEmpty()) {
            System.out.println("\n(Katalog Game Digital Masih Kosong)");
            return;
        }

        String[] headers = {"ID", "Judul Game", "Harga", "Developer", "Asal Dev", "Est.", "Platform DRM", "Ukuran", "Kode Aktivasi"};
        int[] colW = new int[headers.length];

        for (int i = 0; i < headers.length; i++) {
            colW[i] = headers[i].length();
        }

        for (GameDigital g : daftarDigital) {
            colW[0] = Math.max(colW[0], g.getIdProduk().length());
            colW[1] = Math.max(colW[1], g.getJudul().length());
            colW[2] = Math.max(colW[2], ("Rp " + (long)g.getHarga()).length());
            colW[3] = Math.max(colW[3], g.getDeveloper().getNamaDev().length());
            colW[4] = Math.max(colW[4], g.getDeveloper().getNegaraAsal().length());
            colW[5] = Math.max(colW[5], String.valueOf(g.getDeveloper().getTahunBerdiri()).length());
            colW[6] = Math.max(colW[6], g.getPlatformDRM().length());
            colW[7] = Math.max(colW[7], String.format(Locale.US, "%.1f GB", g.getUkuranGB()).length());
            colW[8] = Math.max(colW[8], g.getKodeAktivasi().length());
        }

        for (int i = 0; i < colW.length; i++) {
            colW[i] += 2;
        }

        String garis = buatGaris(colW);
        System.out.println("\n>> KATALOG GAME DIGITAL (SERIAL KEY / DRM) <<");
        System.out.println(garis);

        StringBuilder hsb = new StringBuilder("|");
        for (int i = 0; i < headers.length; i++) {
            hsb.append(" ").append(String.format("%-" + (colW[i] - 1) + "s", headers[i])).append("|");
        }
        System.out.println(hsb.toString());
        System.out.println(garis);

        for (GameDigital g : daftarDigital) {
            String[] row = {
                g.getIdProduk(),
                g.getJudul(),
                "Rp " + (long)g.getHarga(),
                g.getDeveloper().getNamaDev(),
                g.getDeveloper().getNegaraAsal(),
                String.valueOf(g.getDeveloper().getTahunBerdiri()),
                g.getPlatformDRM(),
                String.format(Locale.US, "%.1f GB", g.getUkuranGB()),
                g.getKodeAktivasi()
            };
            StringBuilder rsb = new StringBuilder("|");
            for (int i = 0; i < row.length; i++) {
                rsb.append(" ").append(String.format("%-" + (colW[i] - 1) + "s", row[i])).append("|");
            }
            System.out.println(rsb.toString());
        }

        System.out.println(garis);
    }

    // Tampilkan semua katalog
    public void tampilkanSemua() {
        tampilkanProfil();
        tampilkanTabelFisik();
        tampilkanTabelDigital();
    }
}
