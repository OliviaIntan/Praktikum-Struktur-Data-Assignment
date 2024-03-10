# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Olivia Intan Puspita</p>

## Dasar Teori
Bahasa pemrograman atau dikenal
juga bahasa komputer adalah himpunan
dari aturan sintaks dan semantic yang
digunakan untuk mendefinisikan program
komputer. Kegunaan/ Tujuan dari
pemrograman adalah untuk mengisi suatu
program yang dapat melakukan suatu
perhitungan atau pekerjaan sesuai dengan
keinginan pembuat program [1].

Bjarne Stroustrup pada Bell Labs pertama kali mengembangkan C++ pada awal 1980-an. Untuk mendukung fitur-fitur pada C++, dibangun efisiensi dan sistem support untuk pemrograman tingkat rendah [3].

Dalam C++, terdapat 3 macam tipe data, yaitu tipe data primitif, tipe data abstrak, dan tipe data koleksi.

1. Tipe Data Primitif

Tipe data primitif adalah tipe data bawaan bahasa pemrograman dan bisa langsung digunakan programmer untuk mendeklarasikan variabel. Dalam C++, terdapat 7 tipe data yang termasuk tipe data primitif, 4 diantaranya yang akan dibahas yaitu: int, float, boolean, dan char.

Int dalam C++ seperti dalam matematika, adalah angka-angka berikut: -67, 0, 78. Integer positif tidak perlu memerlukan tanda + dan koma tidak dipakai pada sebuah integer [2].

Float dipakai dalam C++ untuk merepresentasikan sembarang nilai rill. Memori yang dialokasikan untuk sebuah nilai bertipe data float adalah 4 byte.

Boolean hanya memiliki dua nilai yaitu true dan false. Selain itu, true dan false dikenal pula dengan nilai logikal (Boolean). Tujuan utama tipe data ini adalah untuk memanipulasi ekspresi logikal (Boolean) [2].

Char merupakan tipe data integral terkecil. Ia umumnya dipakai untuk merepresentasikan karakter, yaitu huruf, dijit, dan simbol spesial. Beberapa nilai bertipe data char mencakup berikut: 'A', 'a', '0', '+'. Tipe data char hanya membolehkan datu simbol di tempatkan di antara tanda kutip tunggal. Jadi, nilai 'abc' bukanlah bertipe char [2]. 

2. Tipe Data Abstrak

Tipe Data Abstrak (ADT) adalah tipe data untuk objek yang perilakunya ditentukan oleh sekumpulan nilai dan serangkaian operasi. Definisi ADT hanya menyebutkan operasi apa yang akan dilakukan tetapi tidak menyebutkan bagaimana operasi tersebut akan dilaksanakan, Hal itu tidak menentukan bagaimana data akan diatur dalam memori dan algoritma apa yang akan digunakan untuk mengimplementasikan operasi. Disebut “abstrak” karena memberikan pandangan yang tidak bergantung pada implementasi.

3. Tipe Data Koleksi

Koleksi adalah tipe data yang berupa rangkaian atau kumpulan data yang berindeks. Terdapat tiga tipe dasar koleksi di C++ yaitu:

Array : koleksi statis dengan ukuran tetap dan hanya bisa mengelompokkan tipe data yang sama.

List : koleksi dinamis dengan ukuran adaptif dan bisa mengelompokkan tipe data yang sama ataupun berbeda.

Map : koleksi dinamis dengan ukuran adaptif dan bisa mengelompokkan tipe data yang sama ataupun berbeda dengan menggunakan pasangan <key, value>.

## Guided 

### 1. Guided 1: Tipe Data Primitif

```C++
#include <iostream>
using namespace std;
//main program
int main()
{
    char op;
    float num1, num2;
    // it allows user to enter operator i.e. +, -, *,/
    cin >> op;
    //it allow user to enter operands
    cin >> num1 >> num2;
    //switch statement begins
    switch (op) {
    // if user enter +
    case '+':
        cout << num1 + num2;
        break;
    // if user enter -
    case '-':
        cout << num1 - num2;
        break;
    // if user enter *
    case '*':
        cout << num1 * num2;
        break;
    // if user enter /
    case '/':
        cout << num1 / num2;
        break;
    // if the operator is other than +, -, * or /,
    //eror massage will display
    default:
        cout << "Eror! operator is not correct";
    }
    return 0;
}
```
Program di atas merupakan sebuah kalkulator sederhana yang meminta pengguna memasukkan operator (+, -, *, atau /) dan dua bilangan. 
Berikut adalah penjelasannya.

Variabel op pada program tersebut digunakan untuk mendeklarasikan operator, sedangkan num1 num2 digunakan untuk mendeklarasikan dua bilangan. Kemudian pengguna diminta untuk memasukkan operator (+, -, *, /) dan dua bilangan.

Switch statement pada program tersebut digunakan untuk memeriksa operator yang dimasukkan oleh pengguna. Jika operator yang dimasukkan adalah +, -, *, atau /, maka program akan melakukan operasi yang sesuai dan mencetak hasilnya. Namun jika operator tidak valid (misalnya, operator lain selain +, -, *, atau /), maka program akan mencetak pesan kesalahan "Eror! operator is not correct".


### 2. Guided 2: Tipe Data Abstrak

```C++
#include <stdio.h>

struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{
    //menggunakan struct
    struct Mahasiswa mhs1,mhs2;
    //mengisi nilai ke struct
    mhs1.name = "Olivia";
    mhs1.address = "Banyuwangi";
    mhs1.age = 19;
    mhs2.name = "Intan";
    mhs2.address = "Surabaya";
    mhs2.age = 20;

    //mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```
Program di atas merupakan contoh penggunaan struct untuk merepresentasikan data tentang mahasiswa. Program ini akan menampilkan data dua mahasiswa, yaitu mhs1 dan mhs2, yang telah diisi sebelumnya.
Berikut adalah penjelasannya.

Pada program tersebut, struct Mahasiswa didefinisikan dengan tiga anggota: name untuk menyimpan nama mahasiswa (tipe data pointer ke char), address untuk menyimpan alamat mahasiswa (tipe data pointer ke char), dan age untuk menyimpan umur mahasiswa (tipe data integer).

Dua variabel struct Mahasiswa dideklarasikan dalam fungsi main(), yaitu mhs1 dan mhs2.

Nilai-nilai untuk setiap anggota variabel struct mhs1 dan mhs2 diisi secara langsung menggunakan operator penugasan =.

Informasi tentang mahasiswa dari setiap variabel struct (name, address, dan age) dicetak menggunakan fungsi printf(). Setiap informasi dicetak dengan format yang sesuai dengan tipe datanya.

Apabila program dieksekusi maka program akan mencetak informasi tentang masing-masing mahasiswa, termasuk nama, alamat, dan umur.

### 3. Guided 3: Tipe Data Koleksi

```C++
#include <iostream>
using namespace std;
int main()
{
    //deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    //mencetak array
    cout << "Isi array pertama :" << nilai[0] << endl;
    cout << "Isi array kedua :" << nilai[1] << endl;
    cout << "Isi array ketiga :" << nilai[2] << endl;
    cout << "Isi array keempat :" << nilai[3] << endl;
    cout << "Isi array kelima :" << nilai[4] << endl;
    return 0;
}
```
Program di atas adalah contoh penggunaan array untuk menyimpan dan mengakses beberapa nilai dalam satu variabel. Berikut adalah penjelasannya:

Sebuah array dengan nama nilai dan tipe data integer serta berukuran 5 elemen dideklarasikan.
Setiap elemen dalam array diinisialisasi dengan nilai tertentu menggunakan operator indeks.

Setelah array diinisialisasi, program mencetak nilai dari setiap elemen array menggunakan pernyataan cout.
Untuk setiap elemen array, program menggunakan indeksnya untuk mengakses nilai dari elemen tersebut, dan kemudian nilai tersebut dicetak.

Masing-masing nilai dari elemen array dicetak dengan format "Isi array ke-X: NILAI", di mana X adalah indeks elemen array dan NILAI adalah nilai yang disimpan dalam elemen tersebut.

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas.
- Program
```C++
#include <iostream>
#include <iostream>

// Fungsi untuk menghitung luas persegi
double hitungLuasPersegi(double sisi) {
    return sisi * sisi;
}

// Fungsi untuk menghitung volume kubus
double hitungVolumeKubus(double sisi) {
    return sisi * sisi * sisi;
}

int main() {
    double sisiPersegi = 5.0;
    double sisiKubus = 4.0;

    // Menggunakan fungsi hitungLuasPersegi
    double luasPersegi = hitungLuasPersegi(sisiPersegi);
    std::cout << "Luas persegi dengan sisi " << sisiPersegi << " adalah: " << luasPersegi << std::endl;

    // Menggunakan fungsi hitungVolumeKubus
    double volumeKubus = hitungVolumeKubus(sisiKubus);
    std::cout << "Volume kubus dengan sisi " << sisiKubus << " adalah: " << volumeKubus << std::endl;

    return 0;
}
```
- Interpretasi

Program di atas adalah satu program yang memiliki dua fungsi, yaitu untuk menghitung luas persegi dan menghitung volume kubus. Berikut adalah penjelasannya:

Fungsi hitungLuasPersegi:
Fungsi ini mengambil satu parameter, yaitu panjang sisi persegi. Menghitung luas persegi dengan rumus sisi * sisi. Kemudian fungsi return untuk mengembalikan nilai luas persegi.

Fungsi hitungVolumeKubus: Fungsi ini juga mengambil satu parameter, yaitu panjang sisi kubus. Menghitung volume kubus dengan rumus sisi * sisi * sisi. Kemudian fungsi return untuk mengembalikan nilai volume kubus.

Fungsi utama (main):
Di dalam fungsi main, kita mendeklarasikan variabel sisiPersegi dan sisiKubus yang akan digunakan sebagai sisi persegi dan sisi kubus.

Selanjutnya, kita menggunakan fungsi hitungLuasPersegi untuk menghitung luas persegi dengan mengirimkan nilai sisi persegi sebagai argumen, dan menyimpan hasilnya di variabel luasPersegi.

Kemudian, kita menggunakan fungsi hitungVolumeKubus untuk menghitung volume kubus dengan mengirimkan nilai sisi kubus sebagai argumen, dan menyimpan hasilnya di variabel volumeKubus.

Terakhir, kita mencetak hasil perhitungan luas persegi dan volume kubus.

#### Output:
<img width="685" alt="Screenshot 2024-03-10 120237" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/ccefa6b4-0975-42f9-80ac-d4e3af492b3b">
Dari output dapat kita ketahui bahwa persegi dengan sisi 5 cm memiliki luas 25 cm dan kubus dengan sisi 4 cm memiliki volume 64 cm. 

#### Full code Screenshot:
<img width="960" alt="Screenshot 2024-03-10 120118" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/7791f1dc-b4fe-4b67-9671-f0f3acac66bc">
Dengan demikian, dapat disimpulkan bahwa program menggunakan tipe data primitif seperti integer dan float untuk menyimpan nilai panjang sisi persegi dan kubus. Penggunaan tipe data primitif ini memungkinkan program untuk menyimpan dan melakukan operasi matematika dasar dengan mudah, seperti penambahan, pengurangan, perkalian, dan pembagian, yang merupakan operasi dasar yang dibutuhkan dalam program tersebut.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

- Berikut adalah penjelasan secara detail mengenai fungsi dari class dan struct.

Class:

Class digunakan untuk membuat tipe data baru dengan menyatukan data dan fungsi-fungsi yang beroperasi pada data tersebut. Class memungkinkan abstraksi, enkapsulasi, pewarisan, dan polimorfisme.

Abstraksi: Class memungkinkan kita untuk membuat abstraksi dari objek dalam program. Ini berarti kita dapat mendefinisikan karakteristik (atau properti) dan perilaku (atau metode) dari objek tersebut tanpa harus mengkhawatirkan implementasi internalnya.

Enkapsulasi: Class memungkinkan kita untuk menggabungkan data (properti) dan operasi (metode) ke dalam satu entitas tunggal. Ini berarti kita dapat menyembunyikan implementasi internal dari objek, dan hanya mengekspos fungsionalitas yang dibutuhkan melalui antarmuka publik.

Pewarisan: Class mendukung konsep pewarisan, di mana sebuah class dapat mewarisi properti dan metode dari class lainnya. Ini memungkinkan untuk membuat hierarki class yang memudahkan pengelolaan dan perluasan kode.

Polimorfisme: Class mendukung polimorfisme, di mana objek dari class yang berbeda dapat diproses secara seragam melalui antarmuka yang sama. Ini memungkinkan untuk menangani objek dengan cara yang fleksibel, tergantung pada jenis objeknya.


Struct:

Struct digunakan untuk mengelompokkan beberapa variabel dengan tipe data yang berbeda ke dalam satu entitas tunggal. Ini memungkinkan untuk menyimpan dan mengelola data yang terkait bersama-sama.

Struct menyediakan cara yang mudah untuk mengakses dan mengelola data yang terkandung di dalamnya. Properti dari struct biasanya diakses langsung dengan menggunakan operator dot (.) setelah nama variabel struct.

Struct sering digunakan untuk membuat tipe data yang khusus, yang terdiri dari beberapa tipe data primitif. Ini memungkinkan untuk membuat struktur data yang kompleks dengan menyatukan data yang berbeda ke dalam satu unit.

Perbedaan utama antara class dan struct adalah dalam hal aksesibilitas default. Dalam class, anggota defaultnya adalah private, sedangkan dalam struct, anggota defaultnya adalah public. Namun, secara fungsional, keduanya dapat digunakan untuk tujuan yang serupa, yaitu untuk membuat tipe data baru yang terstruktur. Pilihan antara class dan struct tergantung pada kebutuhan spesifik dalam desain program.

- Program

```C++
#include <iostream>

// Contoh struct
struct Rectangle {
    // Anggota data
    float length;
    float width;

    // Method untuk menghitung luas
    float calculateArea() {
        return length * width;
    }
};

// Contoh class
class Circle {
private:
    // Anggota data
    float radius;

public:
    // Constructor
    Circle(float r) {
        radius = r;
    }

    // Method untuk menghitung luas
    float calculateArea() {
        return 3.14 * radius * radius;
    }
};

int main() {
    // Penggunaan struct
    Rectangle rect;
    rect.length = 5.0;
    rect.width = 3.0;
    std::cout << "Luas persegi panjang: " << rect.calculateArea() << std::endl;

    // Penggunaan class
    Circle circle(2.5);
    std::cout << "Luas lingkaran: " << circle.calculateArea() << std::endl;

    return 0;
}
```

- Interpretasi

Program di atas merupakan contoh penggunaan struct dan class. Berikut adalah penjelasannya:

Struct Rectangle digunakan untuk merepresentasikan persegi panjang. Struct memiliki dua anggota data: length yang merepresentasikan panjang dan width yang merepresentasikan lebar persegi panjang.
Struct juga memiliki method calculateArea() yang digunakan untuk menghitung luas persegi panjang.

Class Circle digunakan untuk merepresentasikan lingkaran. Class memiliki satu anggota data: radius, yang merepresentasikan jari-jari lingkaran.
Class memiliki method calculateArea() yang digunakan untuk menghitung luas lingkaran.

Fungsi main() dugunakan untuk membuat objek rect dari struct Rectangle dan objek circle dari class Circle.

Nilai-nilai anggota data dari objek rect diinisialisasi dengan nilai panjang dan lebar yang diberikan. Untuk objek circle, nilai jari-jari diinisialisasi melalui konstruktor.

Kemudian, kita memanggil method calculateArea() untuk menghitung luas dari objek rect dan circle, lalu mencetak hasilnya.

#### Output:
<img width="689" alt="Screenshot 2024-03-10 115929" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/26bce275-42b1-420b-998d-ed441cb6e1e9">
Dari output dapat kita ketahui bahwa persegi panjang dengan panjang 5 cm dan lebar 3 cm memiliki luas 15 cm dan lingkaran dengan jari-jari 2,5 cm memiliki luas 19,625 cm. 

#### Full code Screenshot:
<img width="960" alt="Screenshot 2024-03-10 115805" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/2d4a8d85-76a4-474f-b2a7-33f72ce9d89d">
Dengan demikian, dapat disimpulkan bahwa program menggunakan struktur data yang lebih terorganisir dengan memanfaatkan konsep struct dan class. Dimana struct digunakan untuk merepresentasikan persegi panjang, sementara class digunakan untuk merepresentasikan lingkaran. Program ini memanfaatkan konsep tipe data abstrak dengan menggunakan struct dan class untuk merepresentasikan objek-objek geometris. Dalam konteks ini, struct dan class memungkinkan untuk menyembunyikan detail implementasi internal dari objek, serta mengelola properti dan perilaku yang terkait dengan objek tersebut. 

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.
- Perbedaan dari array dengan map

Berikut adalah beberapa perbedaan utama antara keduanya.

1. Struktur Data

Array: Array adalah struktur data linier yang menyimpan elemen-elemennya dalam urutan berurutan di dalam memori. Setiap elemen memiliki indeks numerik yang unik yang digunakan untuk mengaksesnya.
Map: Map adalah struktur data asosiatif yang menyimpan pasangan kunci-nilai (key-value pairs). Setiap elemen dalam map memiliki kunci unik yang digunakan untuk mengakses nilainya. Kunci dapat berupa tipe data apapun, sedangkan nilai dapat berupa tipe data apapun juga.


2. Penyimpanan Elemen

Array: Elemen-elemen array disimpan secara berurutan dalam memori, dan elemen-elemen tersebut dapat diakses secara langsung menggunakan indeks numeriknya.
Map: Elemen-elemen map disimpan dalam struktur yang lebih kompleks, biasanya menggunakan struktur data seperti pohon pencarian biner atau tabel hash. Untuk mengakses nilai dari sebuah kunci, map melakukan pencarian berdasarkan kunci tersebut, bukan indeks numerik.


3. Indeks/Elemen yang Unik

Array: Setiap elemen dalam array memiliki indeks numerik yang unik, dimulai dari 0 hingga N-1, di mana N adalah ukuran array.
Map: Setiap kunci dalam map harus unik, sehingga tidak boleh ada dua kunci yang sama. Namun, nilai-nilai dalam map dapat berulang.


4. Ukuran dan Penambahan Elemen

Array: Ukuran array biasanya tetap setelah deklarasinya, artinya jumlah elemennya tidak bisa diubah setelahnya. Untuk menambah atau menghapus elemen, biasanya harus membuat array baru dan menyalin elemen-elemen yang ada.
Map: Map biasanya fleksibel dalam ukuran, yang berarti elemen-elemen dapat ditambahkan atau dihapus dengan mudah tanpa harus membuat map baru.


5. Kompleksitas Waktu untuk Mengakses

Array: Mengakses elemen dalam array memiliki kompleksitas waktu O(1), karena akses langsung dengan menggunakan indeks.
Map: Kompleksitas waktu untuk mengakses nilai berdasarkan kunci dalam map biasanya O(log N) atau O(1), tergantung pada struktur data yang digunakan (pohon pencarian biner memiliki kompleksitas O(log N), sementara tabel hash memiliki kompleksitas O(1)).

- Program
```C++
#include <iostream>
#include <map>
#include <string>
#include <sstream>

int main() {
    std::string kalimat;
    std::cout << "Masukkan sebuah kalimat: ";
    std::getline(std::cin, kalimat);

    // Menggunakan stringstream untuk membagi kalimat menjadi kata-kata
    std::stringstream ss(kalimat);
    std::string kata;
    std::map<std::string, int> kemunculan;

    // Menghitung kemunculan setiap kata
    while (ss >> kata) {
        kemunculan[kata]++;
    }

    // Mencetak hasil kemunculan setiap kata
    std::cout << "Jumlah kemunculan setiap kata dalam kalimat:\n";
    for (const auto& pair : kemunculan) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
```
- Interpretasi
Program di atas adalah contoh penggunaan map untuk menghitung kemunculan setiap kata dalam sebuah kalimat yang dimasukkan oleh pengguna. Berikut adalah penjelasannya.

Program meminta pengguna untuk memasukkan sebuah kalimat menggunakan std::getline(std::cin, kalimat). Kalimat yang dimasukkan oleh pengguna disimpan dalam variabel kalimat.

Setelah mendapatkan kalimat dari pengguna, program menggunakan std::stringstream untuk membagi kalimat menjadi kata-kata. Objek ss dibuat dengan menggunakan kalimat yang dimasukkan pengguna sebagai input.

Program membaca setiap kata dari objek ss menggunakan operator >> dan menyimpannya dalam variabel kata.

Program menggunakan std::map<std::string, int> dengan std::string sebagai kunci (kata) dan int sebagai nilai (jumlah kemunculan kata tersebut). Map ini digunakan untuk menyimpan jumlah kemunculan setiap kata dalam kalimat.

Selama pembacaan kata-kata dari objek ss, program memasukkan setiap kata ke dalam map kemunculan. Jika kata sudah ada dalam map, maka jumlah kemunculannya akan ditambah 1. Jika kata belum ada dalam map, maka kata tersebut akan ditambahkan ke dalam map dengan jumlah kemunculan 1.

Setelah selesai menghitung kemunculan setiap kata dalam kalimat, program mencetak hasilnya dengan melakukan iterasi melalui setiap pasangan kunci-nilai dalam map kemunculan. Setiap pasangan kunci-nilai (kata dan jumlah kemunculan) dicetak menggunakan loop for dan std::cout.

#### Output:
<img width="686" alt="Screenshot 2024-03-10 115428" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/b76135fc-f32f-4477-8967-eaa33ba0e265">
Dari output dapat kita ketahui bahwa pengguna memasukkan kalimat "aku harus menyelesaikan laporan ini karena ini adalah kewajibanku sebagai mahasiswa.". Lalu saat di cetak didapatkan hasil bahwa kata "ini" diulang sebanyak 2 kali, sedangkan kata yang lain masing-masing 1 kali.

#### Full code Screenshot:
<img width="960" alt="Screenshot 2024-03-10 115222" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/baea8611-83bd-4310-ba8f-fa04f60f0c62">
Dengan demikian, program ini merupakan contoh penggunaan tipe data koleksi (string, stringstream, dan map) dalam bahasa C++. Hal ini menunjukkan cara kita dapat menggunakan tipe data koleksi untuk menyimpan, memproses, dan menganalisis data dengan lebih efisien dalam program. Dengan memahami konsep tipe data koleksi, kita dapat mengelola data dengan cara yang terstruktur dan efektif.

## Kesimpulan
Ringkasan dan interpretasi pandangan saya dari hasil praktikum dan pembelajaran yang didapat yaitu:
- Hasil Praktikum

Hasil dari praktikum pertama ini, saya menjadi tahu mengenai karakteristik 3 tipe data, yaitu tipe data primitif, abstrak, dan koleksi. Saya juga menjadi lebih tau mengenai pengaplikasian berbagai tipe data pada bahasa pemograman C++ serta pengaplikasian pada tools yang digunakan.

- Pembelajaran yang didapat

Pada praktikum ini saya mendapat pembelajaran yang sangat banyak dan berarti, karena praktikum kali ini sangat berbeda dengan praktikum di semester 1 kemarin. Pada praktikum ini saya belajar banyak tentang bagaimana menggunakan C++, membuat akun github, membuat laporan di vs code, serta mengumpulkan laporan di repository github. Tentunya itu semua adalah hal yang baru untuk saya, tetapi karena hal tersebut juga saya bisa jadi lebih mengeksplor.

## Referensi
[1] Heri Herwanto, "DIAGNOSA STATISTIK PEMETAAN PEMAHAMAN BAHASA PEMOGRAMAN
SEBAGAI ACUAN UNTUK MEMPERSIAPKAN PENELITIAN MAHASISWA", JURNAL NUANSA INFORMATIKA, vol.13, no.2, pp. 33  Juli 2019.

[2] R.H. Sianipar, Pemrograman C++ Untuk Pemula. Indonesia: Penerbit INFORMATIKA, 2014.

[3] H. Al Fatta, Dasar Pemrograman C++ Disertai dengan Pengenalan Pemrograman Berorientasi Objek. Indonesia: Penerbit Andi, 2006.