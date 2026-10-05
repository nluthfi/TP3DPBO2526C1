// Subclass: GameDigital (turunan dari ProdukGame)
// Hierarchical Inheritance: Child 2 dari ProdukGame
public class GameDigital extends ProdukGame {
    private String platformDRM;
    private double ukuranGB;
    private String kodeAktivasi;

    // Constructor default
    public GameDigital() {
        super();
        this.platformDRM = "";
        this.ukuranGB = 0.0;
        this.kodeAktivasi = "";
    }

    // Constructor dengan parameter
    public GameDigital(String idProduk, String judul, double harga, Developer developer,
                       String platformDRM, double ukuranGB, String kodeAktivasi) {
        super(idProduk, judul, harga, developer);
        this.platformDRM = platformDRM;
        this.ukuranGB = ukuranGB;
        this.kodeAktivasi = kodeAktivasi;
    }

    // Getter & Setter
    public String getPlatformDRM() {
        return platformDRM;
    }

    public void setPlatformDRM(String platformDRM) {
        this.platformDRM = platformDRM;
    }

    public double getUkuranGB() {
        return ukuranGB;
    }

    public void setUkuranGB(double ukuranGB) {
        this.ukuranGB = ukuranGB;
    }

    public String getKodeAktivasi() {
        return kodeAktivasi;
    }

    public void setKodeAktivasi(String kodeAktivasi) {
        this.kodeAktivasi = kodeAktivasi;
    }
}
