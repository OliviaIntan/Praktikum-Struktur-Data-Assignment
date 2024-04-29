#include <iostream>
#include <string>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku[5];
    string pengarang[5];
    string penerbit[5];
    int tebalHalaman[5];
    int hargaBuku[5];
};

// Fungsi untuk mengisi data buku
void inputDataBuku(buku &data, int index) {
    cout << "Masukkan data untuk buku ke-" << index + 1 << ":" << endl;
    cout << "Judul Buku   : ";
    cin.ignore();
    getline(cin, data.judulBuku[index]);
    cout << "Pengarang    : ";
    getline(cin, data.pengarang[index]);
    cout << "Penerbit     : ";
    getline(cin, data.penerbit[index]);
    cout << "Tebal Halaman: ";
    cin >> data.tebalHalaman[index];
    cout << "Harga Buku   : Rp ";
    cin >> data.hargaBuku[index];
    cout << endl;
}

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Memasukkan data buku menggunakan fungsi inputDataBuku
    for (int i = 0; i < 5; ++i) {
        inputDataBuku(favorit, i);
    }

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "\tInformasi buku ke-" << i + 1 << ":" << endl;
        cout << "\tJudul Buku : " << favorit.judulBuku[i] << endl;
        cout << "\tPengarang : " << favorit.pengarang[i] << endl;
        cout << "\tPenerbit : " << favorit.penerbit[i] << endl;
        cout << "\tTebal Halaman: " << favorit.tebalHalaman[i] << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << favorit.hargaBuku[i] << endl;
        cout << endl;
    }

    return 0;
}
