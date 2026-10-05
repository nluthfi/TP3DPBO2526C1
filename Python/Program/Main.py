import sys
from Developer import Developer
from GameFisik import GameFisik
from GameDigital import GameDigital
from TokoGame import TokoGame

toko = TokoGame("Pixel Vault Games", "Jl. Ganeca No. 10, Bandung")
is_redirected = not sys.stdin.isatty()

def is_id_exists(id_target: str) -> bool:
    return toko.find_fisik(id_target) != -1 or toko.find_digital(id_target) != -1

def baca_baris() -> str:
    try:
        line = sys.stdin.readline()
        if not line:
            return ""
        val = line.rstrip("\r\n")
        if is_redirected:
            print(val)
        return val.strip()
    except EOFError:
        return ""

def tambah_data():
    print("\n=== TAMBAH DATA PRODUK GAME ===")
    print("Pilih Jenis Game:")
    print("1. Game Fisik (Kaset / Cartridge)")
    print("2. Game Digital (Serial Key / DRM)")
    print("Pilihan: ", end="", flush=True)

    jenis_str = baca_baris()
    if not jenis_str: return

    try:
        jenis = int(jenis_str)
    except ValueError:
        print("Pilihan tidak valid.")
        return

    if jenis not in (1, 2):
        print("Jenis game tidak valid.")
        return

    print("ID Produk          : ", end="", flush=True)
    id_produk = baca_baris()
    if not id_produk: return

    if is_id_exists(id_produk):
        print("Error: ID produk sudah ada di sistem.")
        return

    print("Judul Game         : ", end="", flush=True)
    judul = baca_baris()
    if not judul: return

    print("Harga (Rp)         : ", end="", flush=True)
    try:
        harga = float(baca_baris())
    except ValueError:
        print("Input harga tidak valid.")
        return

    print("Nama Developer     : ", end="", flush=True)
    nama_dev = baca_baris()
    print("Negara Asal Dev    : ", end="", flush=True)
    negara_dev = baca_baris()
    print("Tahun Berdiri Dev  : ", end="", flush=True)
    try:
        tahun_dev = int(baca_baris())
    except ValueError:
        print("Input tahun tidak valid.")
        return

    dev = Developer(nama_dev, negara_dev, tahun_dev)

    if jenis == 1:
        print("Platform Konsol    : ", end="", flush=True)
        platform = baca_baris()
        print("Kondisi Barang     : ", end="", flush=True)
        kondisi = baca_baris()
        print("Berat Fisik (gram) : ", end="", flush=True)
        try:
            berat = int(baca_baris())
        except ValueError:
            print("Input berat tidak valid.")
            return

        gf = GameFisik(id_produk, judul, harga, dev, platform, kondisi, berat)
        toko.tambah_game_fisik(gf)
        print(f'\n✅ Game Fisik "{judul}" berhasil ditambahkan!')
    else:
        print("Platform DRM       : ", end="", flush=True)
        platform_drm = baca_baris()
        print("Ukuran Berkas (GB) : ", end="", flush=True)
        try:
            ukuran = float(baca_baris())
        except ValueError:
            print("Input ukuran tidak valid.")
            return
        print("Kode Aktivasi      : ", end="", flush=True)
        kode = baca_baris()

        gd = GameDigital(id_produk, judul, harga, dev, platform_drm, ukuran, kode)
        toko.tambah_game_digital(gd)
        print(f'\n✅ Game Digital "{judul}" berhasil ditambahkan!')

def tampilkan_data():
    toko.tampilkan_semua()

def update_data():
    print("\n=== UPDATE DATA GAME ===")
    print("Masukkan ID Game: ", end="", flush=True)
    id_target = baca_baris()
    if not id_target: return

    idx_f = toko.find_fisik(id_target)
    idx_d = toko.find_digital(id_target)

    if idx_f == -1 and idx_d == -1:
        print(f'Data game dengan ID "{id_target}" tidak ditemukan.')
        return

    print("Judul Baru        : ", end="", flush=True)
    judul = baca_baris()
    print("Harga Baru (Rp)   : ", end="", flush=True)
    try:
        harga = float(baca_baris())
    except ValueError: return
    print("Developer Baru    : ", end="", flush=True)
    nama_dev = baca_baris()
    print("Asal Negara Dev   : ", end="", flush=True)
    negara_dev = baca_baris()
    print("Tahun Berdiri Dev : ", end="", flush=True)
    try:
        tahun_dev = int(baca_baris())
    except ValueError: return

    dev_baru = Developer(nama_dev, negara_dev, tahun_dev)

    if idx_f != -1:
        print("Platform Baru     : ", end="", flush=True)
        platform = baca_baris()
        print("Kondisi Baru      : ", end="", flush=True)
        kondisi = baca_baris()
        print("Berat Baru (gram) : ", end="", flush=True)
        try:
            berat = int(baca_baris())
        except ValueError: return

        gf = toko.get_daftar_fisik()[idx_f]
        gf.set_judul(judul)
        gf.set_harga(harga)
        gf.set_developer(dev_baru)
        gf.set_platform(platform)
        gf.set_kondisi(kondisi)
        gf.set_berat_gram(berat)
        print(f'\n✅ Data Game Fisik ID "{id_target}" berhasil diperbarui!')
    else:
        print("Platform DRM Baru : ", end="", flush=True)
        drm = baca_baris()
        print("Ukuran Baru (GB)  : ", end="", flush=True)
        try:
            ukuran = float(baca_baris())
        except ValueError: return
        print("Kode Aktivasi Baru: ", end="", flush=True)
        kode = baca_baris()

        gd = toko.get_daftar_digital()[idx_d]
        gd.set_judul(judul)
        gd.set_harga(harga)
        gd.set_developer(dev_baru)
        gd.set_platform_drm(drm)
        gd.set_ukuran_gb(ukuran)
        gd.set_kode_aktivasi(kode)
        print(f'\n✅ Data Game Digital ID "{id_target}" berhasil diperbarui!')

def hapus_data():
    print("\n=== HAPUS DATA GAME ===")
    print("Masukkan ID Game: ", end="", flush=True)
    id_target = baca_baris()
    if not id_target: return

    idx_f = toko.find_fisik(id_target)
    idx_d = toko.find_digital(id_target)

    if idx_f == -1 and idx_d == -1:
        print("Data game tidak ditemukan.")
        return

    judul_target = toko.get_daftar_fisik()[idx_f].get_judul() if idx_f != -1 else toko.get_daftar_digital()[idx_d].get_judul()
    print(f"Game yang akan dihapus: {judul_target}")
    print("Yakin hapus? (y/n): ", end="", flush=True)
    konfirmasi = baca_baris()

    if konfirmasi.lower() == 'y':
        if idx_f != -1:
            toko.hapus_fisik(idx_f)
        else:
            toko.hapus_digital(idx_d)
        print("\n✅ Data berhasil dihapus.")
    else:
        print("\nPenghapusan dibatalkan.")

def cari_data():
    print("\n=== CARI DATA GAME ===")
    print("Masukkan ID Game: ", end="", flush=True)
    id_target = baca_baris()
    if not id_target: return

    idx_f = toko.find_fisik(id_target)
    idx_d = toko.find_digital(id_target)

    if idx_f != -1:
        g = toko.get_daftar_fisik()[idx_f]
        print("\nData Game Fisik Ditemukan:")
        print(f"ID Produk       : {g.get_id_produk()}")
        print(f"Judul Game      : {g.get_judul()}")
        print(f"Harga           : Rp {int(g.get_harga())}")
        print(f"Developer       : {g.get_developer().get_nama_dev()} ({g.get_developer().get_negara_asal()}, Est. {g.get_developer().get_tahun_berdiri()})")
        print(f"Platform        : {g.get_platform()}")
        print(f"Kondisi         : {g.get_kondisi()}")
        print(f"Berat           : {g.get_berat_gram()} gr")
    elif idx_d != -1:
        g = toko.get_daftar_digital()[idx_d]
        print("\nData Game Digital Ditemukan:")
        print(f"ID Produk       : {g.get_id_produk()}")
        print(f"Judul Game      : {g.get_judul()}")
        print(f"Harga           : Rp {int(g.get_harga())}")
        print(f"Developer       : {g.get_developer().get_nama_dev()} ({g.get_developer().get_negara_asal()}, Est. {g.get_developer().get_tahun_berdiri()})")
        print(f"Platform DRM    : {g.get_platform_drm()}")
        print(f"Ukuran File     : {g.get_ukuran_gb():.1f} GB")
        print(f"Kode Aktivasi   : {g.get_kode_aktivasi()}")
    else:
        print("Data tidak ditemukan.")

def inisialisasi_data_default():
    fromsoft = Developer("FromSoftware", "Jepang", 1986)
    santa_monica = Developer("Santa Monica Studio", "Amerika Serikat", 1999)
    cdpr = Developer("CD Projekt Red", "Polandia", 1994)
    capcom = Developer("Capcom", "Jepang", 1979)

    toko.tambah_game_fisik(GameFisik("GF001", "Elden Ring", 750000, fromsoft, "PlayStation 5", "Segel Baru", 120))
    toko.tambah_game_fisik(GameFisik("GF002", "God of War Ragnarok", 680000, santa_monica, "PlayStation 5", "Bekas Like-New", 130))
    toko.tambah_game_fisik(GameFisik("GF003", "Resident Evil 4 Remake", 590000, capcom, "Nintendo Switch", "Segel Baru", 80))

    toko.tambah_game_digital(GameDigital("GD001", "Cyberpunk 2077: Phantom Liberty", 450000, cdpr, "Steam", 70.0, "CP77-PL-9921-X"))
    toko.tambah_game_digital(GameDigital("GD002", "Armored Core VI", 600000, fromsoft, "Steam", 60.5, "AC6-FIRES-7712-B"))

def menu():
    while True:
        print("\n==============================")
        print("    SISTEM DATA TOKO GAME")
        print("==============================")
        print("1. Tambah Data")
        print("2. Tampilkan Data")
        print("3. Update Data")
        print("4. Hapus Data")
        print("5. Cari Data")
        print("0. Keluar")
        print("==============================")
        print("Pilih menu: ", end="", flush=True)

        pilihan_str = baca_baris()
        if not pilihan_str:
            break

        try:
            pilihan = int(pilihan_str)
        except ValueError:
            print("Pilihan tidak valid.")
            continue

        if pilihan == 1:
            tambah_data()
        elif pilihan == 2:
            tampilkan_data()
        elif pilihan == 3:
            update_data()
        elif pilihan == 4:
            hapus_data()
        elif pilihan == 5:
            cari_data()
        elif pilihan == 0:
            print("\nProgram selesai.")
            break
        else:
            print("Pilihan tidak valid.")

def main():
    print("=== PROGRAM TOKO GAME ===")
    inisialisasi_data_default()
    menu()

if __name__ == "__main__":
    main()
