// Kelas Komponen: Developer
// Merepresentasikan studio pengembang game (bagian dari ProdukGame via Komposisi)
public class Developer {
    private String namaDev;
    private String negaraAsal;
    private int tahunBerdiri;

    // Constructor default
    public Developer() {
        this.namaDev = "";
        this.negaraAsal = "";
        this.tahunBerdiri = 0;
    }

    // Constructor dengan parameter
    public Developer(String namaDev, String negaraAsal, int tahunBerdiri) {
        this.namaDev = namaDev;
        this.negaraAsal = negaraAsal;
        this.tahunBerdiri = tahunBerdiri;
    }

    // Getter & Setter
    public String getNamaDev() {
        return namaDev;
    }

    public void setNamaDev(String namaDev) {
        this.namaDev = namaDev;
    }

    public String getNegaraAsal() {
        return negaraAsal;
    }

    public void setNegaraAsal(String negaraAsal) {
        this.negaraAsal = negaraAsal;
    }

    public int getTahunBerdiri() {
        return tahunBerdiri;
    }

    public void setTahunBerdiri(int tahunBerdiri) {
        this.tahunBerdiri = tahunBerdiri;
    }
}
