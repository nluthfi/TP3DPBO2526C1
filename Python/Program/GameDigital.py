from ProdukGame import ProdukGame
from Developer import Developer

# Subclass: GameDigital (turunan dari ProdukGame)
# Hierarchical Inheritance: Child 2 dari ProdukGame
class GameDigital(ProdukGame):
    def __init__(self, id_produk: str = "", judul: str = "", harga: float = 0.0, 
                 developer: Developer | None = None, platform_drm: str = "", 
                 ukuran_gb: float = 0.0, kode_aktivasi: str = ""):
        super().__init__(id_produk, judul, harga, developer)
        self._platform_drm = platform_drm
        self._ukuran_gb = ukuran_gb
        self._kode_aktivasi = kode_aktivasi

    # Getter & Setter
    def get_platform_drm(self) -> str:
        return self._platform_drm

    def set_platform_drm(self, platform_drm: str) -> None:
        self._platform_drm = platform_drm

    def get_ukuran_gb(self) -> float:
        return self._ukuran_gb

    def set_ukuran_gb(self, ukuran_gb: float) -> None:
        self._ukuran_gb = ukuran_gb

    def get_kode_aktivasi(self) -> str:
        return self._kode_aktivasi

    def set_kode_aktivasi(self, kode_aktivasi: str) -> None:
        self._kode_aktivasi = kode_aktivasi
