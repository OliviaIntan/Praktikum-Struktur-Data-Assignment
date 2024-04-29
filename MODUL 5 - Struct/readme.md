# <h1 align="center">Laporan Praktikum Modul Struct</h1>
<p align="center">Olivia Intan Puspita</p>

## Dasar Teori
Variabel pada bahasa c++ adalah bagian dari memori yang hanya dapat menampung satu data/informasi pada satu waktu, dimana data/informasi tersebut dapat berubah setelah dideklarasikan selama pengeksekusian program. Variabel dilambangkan dengan simbol yang didefinisikan oleh pemrogram dan variabel harus dideklarasikan terlebih dahulu sebelum dapat digunakan. Pendeklarasian variabel pada bahasa C++ adalah sebagai berikut 'tipe_data nama_variabel;'. Variabel dapat langsung diberi nilai awal pada saat pendeklarasiannya. Pendeklarasian variabel pada bahasa C++ adalah sebagai berikut 'tipe_data nama_variabel=nilai_awal;' [1]. Pada C++, kita dapat mendeklarasikan variabel dibagian mana saja dari program, bahkan diantara 2 kalimat oerintah. Variabel global dapat digunakan untuk setiap bagian dari program, maupun fungsi, walaupun dideklarasikan diakhir program. Lingkup dari variabel lokal terbatas. Hanya berlaku dimana varibel tersebut dideklarasikan. Jika dideklarasikan diawal fungsi (seperti dalam main) maka lingkup dari variabel tersebut adalah untuk seluruh fungsi main [3].

Structure/struktur adalah kumpulan elemen-elemen data yang digabungkan menjadi satu kesatuan. Masing-masing elemen data dikenal dengan sebutan field/kolom. Field data tersebut dapat memiliki tipe data yang sama ataupun berbeda. Walaupun field-field tersebut berada dalam satu kesatuan, masing-masing field tersebut dapat diakses secara individual. Field-field tersebut digabungkan menjadi satu dengan tujuan untuk kemudahan dalam operasinya [1]. Structure atau struct juga dapat diartikan kumpulan dari beberapa variabel dengan beragam tipe data yang dibungkus dalam satu variabel. Ada dua cara untuk mengakses member yang ada di dalam struct. Cara pertama adalah dengan cara mendeklarasikan object-nya terlebih dahulu di dalam struct-nya kemudian untuk mengaksesnya bisa menggunakan object yang telah dideklarasikan tadi. Kemudian cara kedua adalah dengan mendeklarasikan object-nya di dalam 'int main()' dengan cara memanggil nama struct-nya dan diikuti dengan nama object-nya [2].

## Guided 

### 1. Guided 1: Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.

```C++
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
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}
```
Program di atas merupakan sebuah struktur dengan nama buku yang datanya berisi judul_buku, pengarang, penerbit, tebal_halaman, dan harga_buku dengan data yang di isi manual kemudian ditampilkan. Berikut adalah penjelasannya.

Pertama, program di atas mendefinisikan sebuah struktur yang bernama 'buku', dimana struktur 'buku' tersebut memiliki lima anggota, yaitu 'judulBuku', 'pengarang', 'penerbit', 'tebalHalaman', dan 'hargaBuku'. Tipe data untuk setiap anggota juga disesuaikan, seperti string untuk 'judulBuku', 'pengarang', dan 'penerbit', lalu int untuk 'tebalHalaman' dan 'hargaBuku'. Kemudian terdapat fungsi main() untuk mengeksekusi program saat dijalankan. Untuk yang pertama yaitu mendeklarasikan variabel 'favorit' dengan tipe 'buku'. Ini adalah variabel yang akan digunakan untuk menyimpan data tentang buku favorit. Yang kedua yaitu mengisi data ke dalam variabel favorit. Data buku favorit diisi ke dalam variabel favorit menggunakan operator titik. Kemudian setiap anggota dari variabel favorit diisi dengan nilai yang sudah ditentukan. Yang ketiga yaitu menampilkan informasi buku favorit. Informasi tentang buku favorit ditampilkan ke layar menggunakan perintah 'cout'. Lalu diberikan kode '\t' yang berfungsi untuk membuat tab (kalimat menjorok ke depan) pada tampilan outputnya. Dan yang terakhir 'return 0' yang berfungsi untuk mengembalikan nilai 0 dan menandakan bahwa program telah berakhir.

#### Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/87cb5dba-c0f3-4951-8707-4f49597cb36a)

Dari output tersebut dapat kita ketahui data mengenai Buku Favorit Saya. Dimana, Judul Bukunya adalah 'The Alpha Girl's Guide, Pengarangnya adalah 'Henry Manampiring', Penerbitnya adalah 'Gagas Media', Tebal Halamannya adalah '253 halaman', dan Harga Bukunya adalah 'Rp 79000'.

#### Full code Screenshot:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/2bd9aea7-473e-4d96-8fac-d52efa345c42)

### 2. Guided 2: Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/12f96230-5238-4e8d-9b0e-15975e420ddf)

```C++
#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kelinci; // Menggunakan tipe data hewanDarat untuk kelinci
    kelinci.jumlahKaki = 4;
    kelinci.menyusui = true;
    kelinci.suara = "Citcit";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik";

    hewan serigala; // Tetap menggunakan tipe data hewan untuk serigala
    serigala.namaHewan = "Serigala";
    serigala.jenisKelamin = "Jantan";
    serigala.caraBerkembangbiak = "Melahirkan";
    serigala.alatPernafasan = "Paru-paru";
    serigala.tempatHidup = "Hutan terbuka";
    serigala.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKelinci" << endl;
    cout << "\tJumlah kaki : " << kelinci.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kelinci.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kelinci.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}
```
Program di atas merupakan program yang menampilkan tiga struktur dengan nama Hewan, Hewan Darat, dan Hewan Laut. Berikut adalah penjelasannya.

Seperti yang sudah diketahui di atas, program tersebut memiliki tiga struktur data yang didefinisikan. Pertama adalah struktur 'hewan'. Struktur ini memiliki lima anggota yang dimana menggambarkan karakteristik umum dari hewan sendiri. Lima anggota tersebut adalah 'namaHewan', 'jenisKelamin', 'caraBerkembangbiak', 'alatPernafasan', 'tempatHidup', dan 'Karnovira'. Untuk tipe data semuanya bertipe string, kecuali untuk 'Karnivora' bertipe data bool yang berarti true atau false. Kedua adalah struktur 'hewanDarat'. Struktur ini memiliki tiga anggota yang menggambarkan karakteristik dari hewan darat sendiri. Tiga anggota tersebut adalah 'jumlahKaki', 'menyusui', dan 'suara'. Untuk tipe datanya juga disesuaikan, 'jumlahKaki' bertipe data int, 'menyusui' bertipe data bool, dan 'suara' bertipe data string. Ketiga adalah struktur 'hewanLaut'. Struktur ini memiliki dua anggota yang menggambarkan karakteristik dari hewan laut sendiri. Dua anggota tersebut adalah 'bentukSirip' dan 'bentukPertahananDiri'. Tipe data yang digunakan keduanya juga sama, yaitu menggunakan string. Selanjutnya fungsi 'main()'. Dalam fungsi 'main()' program melakukan beberapa hal, diantaranya menginisialisasi objek hewan, dimana kelinci untuk hewanDarat, ikan untuk hewanLaut, dan serigala untuk hewan, dan kemudian mengisi data-datanya. Setelah itu, program menggunakan objek hewan tersebut untuk menampilkan informasi dari ketiga struktur yang sudah di isi data-datanya, lalu informasi dicetak ke layar menggunakan fungsi 'cout'. 

#### Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/39e07f19-995e-4ba8-b6e9-3e2fecc0b578)

Dari output tersebut dapat kita ketahui data mengenai karakteristik hewan, yang mana dibagi menjadi 3 kelompok. Kelompok pertama adalah Hewan yang di isi oleh Serigala. Serigala berjenis kelamin jantan, cara berkembang biaknya dengan melahirkan, alat pernafasannya menggunakan paru-paru, tempat hidupnya di hutan terbuka, dan tergolong ke dalam jenis hewan karnivora.
Kelompok kedua adalah Hewan Darat yang di isi oleh Kelinci. Kelinci memiliki jumlah kaki 4, termasuk hewan yang menyusui, dan memiliki suara citcit. Kelompok ketiga dan yang terakhir adalah Hewan Laut yang di isi oleh Ikan. Bentuk sirip ikan yaitu sirip ekor, dan ventuk pertahanan dirinya yaitu sisik.

#### Full code Screenshot:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/e83dd878-a68c-4efd-ae59-f0db4e6287b1)

## Unguided 

### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.

```C++
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
```
Program di atas adalah bentuk modifikasi dari guided pertama yang struktur bukunya diubah menjadi array yang berukuran lima dengan data yang diinputkan. Berikut adalah penjelasannya.

Struktur pada program di atas bernama buku yang memiliki lima array untuk menyimpan informasi tentang lima buku. Pada setiap array menyimpan informasi diantaranya: 'judulBuku', 'pengarang', 'penerbit', 'tebalHalaman', dan 'hargaBuku'. Selanjutnya, terdapat fungsi 'inputDataBuku' yang berfungsi untuk meminta kita memasukkan data suatu buku ke dalam struktur buku. Setiap kali dipanggil, fungsi ini akan meminta kita untuk memasukkan judul, pengarang, penerbit, jumlah halaman, dan harga untuk setiap buku. Karena array berjumlah lima sehingga program akan meminta kita memasukkan data buku sebanyak lima kali. Kemudian fungsi 'main()' yang di dalamnya terdapat beberapa hal. Pertama, mendeklarasikan variabel favorit dengan tipe buku. Kedua, memasukkan data buku menggunakan fungsi 'inputDataBuku'. Ketiga, menampilkan informasi buku favorit. Setelah pengguna memasukkan semua data, program menampilkan informasi tentang setiap buku yang telah dimasukkan. 

#### Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/646ad33e-5973-4e78-9f44-bb6e27d54443)

Dari output tersebut dapat kita ketahui data mengenai Buku Favorit Saya yang berjumlah lima. Setiap buku menampilkan informasi judul, pengarang, penerbit, tebal halaman, dan harga buku. 

#### Full code Screenshot:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/fe8cf1e5-a89d-43cf-bb89-d2afcd8f3d11)

Dengan demikian, dapat disimpulkan bahwa program di atas adalah bentuk modifikasi dari program guided 1. Pada program ini kita mengunakan array yang berjumlah 5 dan juga kita diminta untuk memasukkan data setiap bukunya.

### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I, berjenis Array. Bagaimana cara mengisi data dan menampilkannya?

Jika kita ingin menggunakan array dari struktur buku pada guided 1 untuk menyimpan beberapa buku, kita bisa mendeklarasikan array dari struktur buku tersebut kemudian mengisi setiap elemen array dengan data buku yang sudah ditentukan. 

```C++
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
```
Berikut adalah penjelasan program di atas.

Sama seperti program pada guided 1, program di atas dimulai dengan mendefinisikan sebuah struktur yang diberi nama buku dan struktur buku ini memiliki lima anggota diantaranya: 'judulBuku', 'pengarang', 'penerbit', 'tebalHalaman', dan 'hargaBuku'. Selanjutnya fungsi main(). Untuk yang pertama, array buku dengan ukuran 3 dideklarasikan sebagai daftarBuku. Kemudian data untuk setiap buku diisi ke dalam array daftarBuku. Setiap elemen array diisi dengan informasi karakteristik buku yang sudah ditentukan. Setelah array daftarBuku diisi, program mencetak informasi dalam array tersebut. Selanjutnya Loop for. Loop for digunakan untuk melintasi setiap elemen array daftarBuku, dan kemudian mencetak anggota-anggota buku tersebut satu per satu. Informasi setiap buku ditampilkan secara terformat ke layar.

#### Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/1948875d-9c98-4420-b66a-06b60134b0e9)

Dari output tersebut dapat kita ketahui data mengenai tiga Daftar Buku. Dimana untuk buku ke-1 berjudul The Alpha Girl's Guide, lalu buku ke-2 berjudul Sapiens di Ujung Tanduk, dan buku ke-3 berjudul Almond, dengan masing-masing karakteristik buku dapat dilihat pada gambar di atas.  

#### Full code Screenshot:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/1ae42954-bf87-437a-8e49-a22dca575786)

Dengan demikian, dapat disimpulkan bahwa program di atas mendeklarasikan array dari struktur buku dan berhasil memasukkan serta menampilkan data buku-buku dalam array. Setiap elemen dari array daftarBuku mewakili satu buku dengan anggota judul, pengarang, penerbit, tebal halaman, dan harga buku yang sesuai. 

## Kesimpulan
Ringkasan dan interpretasi pandangan saya dari hasil praktikum dan pembelajaran yang didapat yaitu:
- Hasil Praktikum

Hasil dari praktikum kelima ini, saya menjadi tahu mengenai konsep dasar struct dan implementasinya. Ternyata dalam penulisan struct tidak berpatokan pada 1 format penulisan, melainkan terdapat banyak format dalam penulisannya. Bukan hanya itu, saya juga menjadi tahu mengenai dasar variabel, jenis variabel yang dimana dibagi menjadi 2 yaitu variabel lokal dan variabel global, serta format penulisan variabel. 

- Pembelajaran yang didapat

Pada praktikum kelima ini, saya mendapat pembelajaran yang banyak dan berarti. Saya banyak belajar mengenai implementasi struct pada program c++ dan juga menerapkan array pada struct. Semua itu adalah pembelajaran baru dan tentunya bermanfaat untuk saya kedepannya. Kemudian saya juga tetap banyak belajar dari evaluasi praktikum sebelumnya agar lebih baik lagi.

## Referensi
[1] R. Firliana, M.Kom, dan P. Kasih, M.Kom, Algoritma & Pemrograman C++. Nganjuk: Adjie Media Nusantara, Januari 2018.

[2] M. Nugraha, Dasar Pemrograman Dengan C++ Materi Paling Dasar Untuk Menjadi Programmer Berbagai Platform. Deepublish, 2021.

[3] A. Huda, N. Ardi, A. Muabi, PENGANTAR CODING BERBASIS C/C++. Padang: UNP PRESS, 2021