// Subclass: GameFisik (turunan dari ProdukGame)
// Hierarchical Inheritance: Child 1 dari ProdukGame
public class GameFisik extends ProdukGame {
    private String platform;
    private String kondisi;
    private int beratGram;

    // Constructor default
    public GameFisik() {
        super();
        this.platform = "";
        this.kondisi = "";
        this.beratGram = 0;
    }

    // Constructor dengan parameter
    public GameFisik(String idProduk, String judul, double harga, Developer developer,
                     String platform, String kondisi, int beratGram) {
        super(idProduk, judul, harga, developer);
        this.platform = platform;
        this.kondisi = kondisi;
        this.beratGram = beratGram;
    }

    // Getter & Setter
    public String getPlatform() {
        return platform;
    }

    public void setPlatform(String platform) {
        this.platform = platform;
    }

    public String getKondisi() {
        return kondisi;
    }

    public void setKondisi(String kondisi) {
        this.kondisi = kondisi;
    }

    public int getBeratGram() {
        return beratGram;
    }

    public void setBeratGram(int beratGram) {
        this.beratGram = beratGram;
    }
}
