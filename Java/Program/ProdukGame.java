// Base Class: ProdukGame
// Merepresentasikan data umum game, memiliki objek Developer (Komposisi)
public class ProdukGame {
    protected String idProduk;
    protected String judul;
    protected double harga;
    protected Developer developer; // Komposisi: Objek Developer di dalam ProdukGame

    // Constructor default
    public ProdukGame() {
        this.idProduk = "";
        this.judul = "";
        this.harga = 0.0;
        this.developer = new Developer();
    }

    // Constructor dengan parameter
    public ProdukGame(String idProduk, String judul, double harga, Developer developer) {
        this.idProduk = idProduk;
        this.judul = judul;
        this.harga = harga;
        this.developer = developer != null ? developer : new Developer();
    }

    // Getter & Setter
    public String getIdProduk() {
        return idProduk;
    }

    public void setIdProduk(String idProduk) {
        this.idProduk = idProduk;
    }

    public String getJudul() {
        return judul;
    }

    public void setJudul(String judul) {
        this.judul = judul;
    }

    public double getHarga() {
        return harga;
    }

    public void setHarga(double harga) {
        this.harga = harga;
    }

    public Developer getDeveloper() {
        return developer;
    }

    public void setDeveloper(Developer developer) {
        this.developer = developer;
    }
}
