from ProdukGame import ProdukGame
from Developer import Developer

# Subclass: GameFisik (turunan dari ProdukGame)
# Hierarchical Inheritance: Child 1 dari ProdukGame
class GameFisik(ProdukGame):
    def __init__(self, id_produk: str = "", judul: str = "", harga: float = 0.0, 
                 developer: Developer | None = None, platform: str = "", 
                 kondisi: str = "", berat_gram: int = 0):
        super().__init__(id_produk, judul, harga, developer)
        self._platform = platform
        self._kondisi = kondisi
        self._berat_gram = berat_gram

    # Getter & Setter
    def get_platform(self) -> str:
        return self._platform

    def set_platform(self, platform: str) -> None:
        self._platform = platform

    def get_kondisi(self) -> str:
        return self._kondisi

    def set_kondisi(self, kondisi: str) -> None:
        self._kondisi = kondisi

    def get_berat_gram(self) -> int:
        return self._berat_gram

    def set_berat_gram(self, berat_gram: int) -> None:
        self._berat_gram = berat_gram
