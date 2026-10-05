# Kelas Komponen: Developer
# Merepresentasikan studio pengembang game (bagian dari ProdukGame via Komposisi)
class Developer:
    def __init__(self, nama_dev: str = "", negara_asal: str = "", tahun_berdiri: int = 0):
        self._nama_dev = nama_dev
        self._negara_asal = negara_asal
        self._tahun_berdiri = tahun_berdiri

    # Getter & Setter
    def get_nama_dev(self) -> str:
        return self._nama_dev

    def set_nama_dev(self, nama_dev: str) -> None:
        self._nama_dev = nama_dev

    def get_negara_asal(self) -> str:
        return self._negara_asal

    def set_negara_asal(self, negara_asal: str) -> None:
        self._negara_asal = negara_asal

    def get_tahun_berdiri(self) -> int:
        return self._tahun_berdiri

    def set_tahun_berdiri(self, tahun_berdiri: int) -> None:
        self._tahun_berdiri = tahun_berdiri
