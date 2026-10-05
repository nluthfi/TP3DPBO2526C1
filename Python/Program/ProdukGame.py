from Developer import Developer

# Base Class: ProdukGame
# Merepresentasikan data umum produk game, memiliki objek Developer (Komposisi)
class ProdukGame:
    def __init__(self, id_produk: str = "", judul: str = "", harga: float = 0.0, 
                 developer: Developer | None = None):
        self._id_produk = id_produk
        self._judul = judul
        self._harga = harga
        self._developer = developer if developer is not None else Developer()

    # Getter & Setter
    def get_id_produk(self) -> str:
        return self._id_produk

    def set_id_produk(self, id_produk: str) -> None:
        self._id_produk = id_produk

    def get_judul(self) -> str:
        return self._judul

    def set_judul(self, judul: str) -> None:
        self._judul = judul

    def get_harga(self) -> float:
        return self._harga

    def set_harga(self, harga: float) -> None:
        self._harga = harga

    def get_developer(self) -> Developer:
        return self._developer

    def set_developer(self, developer: Developer) -> None:
        self._developer = developer
