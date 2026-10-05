from GameFisik import GameFisik
from GameDigital import GameDigital

# Container Class: TokoGame
# Menerapkan Composition dan Array of Objects (list[GameFisik] & list[GameDigital])
class TokoGame:
    def __init__(self, nama_toko: str = "", alamat: str = ""):
        self._nama_toko = nama_toko
        self._alamat = alamat
        self._daftar_fisik: list[GameFisik] = []
        self._daftar_digital: list[GameDigital] = []

    # Helper membuat garis tabel
    @staticmethod
    def _buat_garis(lebar: list[int]) -> str:
        return "+" + "+".join("-" * w for w in lebar) + "+"

    # Getter & Setter
    def get_nama_toko(self) -> str: return self._nama_toko
    def set_nama_toko(self, nama_toko: str) -> None: self._nama_toko = nama_toko

    def get_alamat(self) -> str: return self._alamat
    def set_alamat(self, alamat: str) -> None: self._alamat = alamat

    def get_daftar_fisik(self) -> list[GameFisik]: return self._daftar_fisik
    def get_daftar_digital(self) -> list[GameDigital]: return self._daftar_digital

    # Tambah data
    def tambah_game_fisik(self, g: GameFisik) -> None:
        self._daftar_fisik.append(g)

    def tambah_game_digital(self, g: GameDigital) -> None:
        self._daftar_digital.append(g)

    # Cari index berdasarkan ID
    def find_fisik(self, id_target: str) -> int:
        for i, g in enumerate(self._daftar_fisik):
            if g.get_id_produk() == id_target:
                return i
        return -1

    def find_digital(self, id_target: str) -> int:
        for i, g in enumerate(self._daftar_digital):
            if g.get_id_produk() == id_target:
                return i
        return -1

    # Hapus data
    def hapus_fisik(self, index: int) -> bool:
        if 0 <= index < len(self._daftar_fisik):
            self._daftar_fisik.pop(index)
            return True
        return False

    def hapus_digital(self, index: int) -> bool:
        if 0 <= index < len(self._daftar_digital):
            self._daftar_digital.pop(index)
            return True
        return False

    # Tampilkan profil toko
    def tampilkan_profil(self) -> None:
        print("\n============================================================")
        print(f"PROFIL TOKO: {self._nama_toko} ({self._alamat})")
        print(f"Total Inventaris: {len(self._daftar_fisik)} Game Fisik, {len(self._daftar_digital)} Game Digital")
        print("============================================================")

    # Tabel dinamis Game Fisik
    def tampilkan_tabel_fisik(self) -> None:
        if not self._daftar_fisik:
            print("\n(Katalog Game Fisik Masih Kosong)")
            return

        headers = ["ID", "Judul Game", "Harga", "Developer", "Asal Dev", "Est.", "Platform", "Kondisi", "Berat"]
        col_w = [len(h) for h in headers]

        for g in self._daftar_fisik:
            col_w[0] = max(col_w[0], len(g.get_id_produk()))
            col_w[1] = max(col_w[1], len(g.get_judul()))
            col_w[2] = max(col_w[2], len(f"Rp {int(g.get_harga())}"))
            col_w[3] = max(col_w[3], len(g.get_developer().get_nama_dev()))
            col_w[4] = max(col_w[4], len(g.get_developer().get_negara_asal()))
            col_w[5] = max(col_w[5], len(str(g.get_developer().get_tahun_berdiri())))
            col_w[6] = max(col_w[6], len(g.get_platform()))
            col_w[7] = max(col_w[7], len(g.get_kondisi()))
            col_w[8] = max(col_w[8], len(f"{g.get_berat_gram()} gr"))

        col_w = [w + 2 for w in col_w]
        garis = self._buat_garis(col_w)

        print("\n>> KATALOG GAME FISIK (DISC / CARTRIDGE) <<")
        print(garis)
        header_row = "|" + "".join(f" {h:<{col_w[i] - 1}}|" for i, h in enumerate(headers))
        print(header_row)
        print(garis)

        for g in self._daftar_fisik:
            row = [
                g.get_id_produk(),
                g.get_judul(),
                f"Rp {int(g.get_harga())}",
                g.get_developer().get_nama_dev(),
                g.get_developer().get_negara_asal(),
                str(g.get_developer().get_tahun_berdiri()),
                g.get_platform(),
                g.get_kondisi(),
                f"{g.get_berat_gram()} gr"
            ]
            row_str = "|" + "".join(f" {val:<{col_w[i] - 1}}|" for i, val in enumerate(row))
            print(row_str)

        print(garis)

    # Tabel dinamis Game Digital
    def tampilkan_tabel_digital(self) -> None:
        if not self._daftar_digital:
            print("\n(Katalog Game Digital Masih Kosong)")
            return

        headers = ["ID", "Judul Game", "Harga", "Developer", "Asal Dev", "Est.", "Platform DRM", "Ukuran", "Kode Aktivasi"]
        col_w = [len(h) for h in headers]

        for g in self._daftar_digital:
            col_w[0] = max(col_w[0], len(g.get_id_produk()))
            col_w[1] = max(col_w[1], len(g.get_judul()))
            col_w[2] = max(col_w[2], len(f"Rp {int(g.get_harga())}"))
            col_w[3] = max(col_w[3], len(g.get_developer().get_nama_dev()))
            col_w[4] = max(col_w[4], len(g.get_developer().get_negara_asal()))
            col_w[5] = max(col_w[5], len(str(g.get_developer().get_tahun_berdiri())))
            col_w[6] = max(col_w[6], len(g.get_platform_drm()))
            col_w[7] = max(col_w[7], len(f"{g.get_ukuran_gb():.1f} GB"))
            col_w[8] = max(col_w[8], len(g.get_kode_aktivasi()))

        col_w = [w + 2 for w in col_w]
        garis = self._buat_garis(col_w)

        print("\n>> KATALOG GAME DIGITAL (SERIAL KEY / DRM) <<")
        print(garis)
        header_row = "|" + "".join(f" {h:<{col_w[i] - 1}}|" for i, h in enumerate(headers))
        print(header_row)
        print(garis)

        for g in self._daftar_digital:
            row = [
                g.get_id_produk(),
                g.get_judul(),
                f"Rp {int(g.get_harga())}",
                g.get_developer().get_nama_dev(),
                g.get_developer().get_negara_asal(),
                str(g.get_developer().get_tahun_berdiri()),
                g.get_platform_drm(),
                f"{g.get_ukuran_gb():.1f} GB",
                g.get_kode_aktivasi()
            ]
            row_str = "|" + "".join(f" {val:<{col_w[i] - 1}}|" for i, val in enumerate(row))
            print(row_str)

        print(garis)

    # Tampilkan seluruh katalog
    def tampilkan_semua(self) -> None:
        self.tampilkan_profil()
        self.tampilkan_tabel_fisik()
        self.tampilkan_tabel_digital()
