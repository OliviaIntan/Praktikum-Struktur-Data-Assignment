#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan array buku dengan ukuran 3
    buku daftarBuku[3];

    // Mengisi data ke dalam array buku
    daftarBuku[0].judulBuku = "The Alpha Girl's Guide";
    daftarBuku[0].pengarang = "Henry Manampiring";
    daftarBuku[0].penerbit = "Gagas Media";
    daftarBuku[0].tebalHalaman = 253;
    daftarBuku[0].hargaBuku = 79000;

    daftarBuku[1].judulBuku = "Sapiens di Ujung Tanduk";
    daftarBuku[1].pengarang = "Iqbal Aji Daryono";
    daftarBuku[1].penerbit = "Bentang Pustaka";
    daftarBuku[1].tebalHalaman = 159;
    daftarBuku[1].hargaBuku = 63000;

    daftarBuku[2].judulBuku = "Almond";
    daftarBuku[2].pengarang = "Sohn Won Pyung";
    daftarBuku[2].penerbit = "Scholastic";
    daftarBuku[2].tebalHalaman = 222;
    daftarBuku[2].hargaBuku = 70000;

    // Menampilkan informasi buku-buku dalam array
    cout << "\tDaftar Buku" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "\nBuku ke-" << i+1 << ":" << endl;
        cout << "\tJudul Buku : " << daftarBuku[i].judulBuku << endl;
        cout << "\tPengarang : " << daftarBuku[i].pengarang << endl;
        cout << "\tPenerbit : " << daftarBuku[i].penerbit << endl;
        cout << "\tTebal Halaman: " << daftarBuku[i].tebalHalaman << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << daftarBuku[i].hargaBuku << endl;
    }
 
    return 0;
}
