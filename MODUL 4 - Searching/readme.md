# <h1 align="center">Laporan Praktikum Modul Searching</h1>
<p align="center">Olivia Intan Puspita</p>

## Dasar Teori
Cara terbaik untuk memahami suatu algoritma adalah menganggapnya sebagai resep. Ada banyak cara untuk memanggang kue, tetapi dengan mengikuti resep, seorang tukang roti tahu untuk memanaskan oven terlebih dahulu, kemudian mengukur tepung, menambahkan mentega, keping cokelat, dll sampai kue yang diinginkan selesai. Dengan menggunakan algoritma, seorang programmer atau ilmuwan komputer dapat memberi tahu mesinnya untuk meminta database A untuk angka penjualan bulan lalu, membandingkannya dengan bulan sebelumnya dan bulan yang sama tahun lalu, dan kemudian menampilkannya dalam grafik batang [1]. 

Terdapat beberapa algoritma pencarian yang dapat digunakan, di antaranya adalah adalah Sequential Search dan Binary Search. 
1. Algoritma Sequential Search 

Algoritma Sequential Search yang biasanya disebut sebagai pendekatan pencarian secara beruntun merupakan pencarian yang diawali dari elemen awal sampai dengan elemen akhir secara beruntun hingga bisa menemukan elemen yang akan dikunjungi. Algoritma ini mampu melakukan pencarian dengan array yang data-datanya tidak perlu melalui pengurutan data sebelumnya. Cara kerja algoritma ini adalah dengan melakukan perbandingan antara data yang ada dengan data yang akan dicari satu per satu secara berurutan sampai dapat menemukan datanya [2].

2. Algoritma Binary Search

Algoritma Binary Search digunakan untuk kebutuhan pencarian dengan waktu yang cepat. Sebenarnya, dalam kehidupan sehari-hari kita sering menerapkan pencarian bagi dua. Untuk mencari kata tertentu di dalam kamus kita tidak membuka kamus itu dari halaman awal sampai halaman akhir satu persatu, namun kita mencarinya dengan cara membelah atau membagi dua buku itu. Jika kata yang dicari tidak terletak di halaman pertemuan itu kita mencari lagi di belahan bagian kiri atau belahan bagian kanan dengan cara membagi dua belahan yang dimaksud, begitu seterusnya  sampai  kata  yang dicari ditemukan. Hal ini hanya bisa dilakukan jika kata-kata di dalam kamus sudah terurut [3].

## Guided 

### 1. Guided 1: Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.

```C++
#include <iostream>

using namespace std;

int main() {
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    int ketemu = false;
    int i;

    // Algoritma Sequential Search
    for (i = 0; i < n; i++) {
        if(data[i] == cari) {
            ketemu = true;
            break;
        }
    }
        cout << "\t Progran Sequential Search Sederhana\n" << endl;
        cout << " data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}"<< endl;

    if (ketemu){
        cout << "\n angka "<< cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;
}
```
Program di atas merupakan sebuah program untuk mencari data tertentu pada sebuah array dengan menggunakan Sequential Search. Berikut adalah penjelasannya.

Array "data" pada program di atas berisi bilangan bulat sejumlah "n". Kemudian, variabel "cari" berisi angka yang ingin dicari dalam array. Lalu, variabel "ketemu" digunakan untuk menandai apakah angka yang dicari sudah ditemukan atau belum, yang dimana awalnya diatur sebagai false. Dan terakhir variabel "i" digunakan sebagai indeks pencarian.

Selanjutnya, program di atas melakukan pencarian berurutan dalam array "data" menggunakan perulangan "for". Jika angka yang dicari ditemukan, variabel "ketemu" di awal tadi diubah menjadi "true" dan program keluar dari perulangan lalu program mencetak pesan bahwa "angka tersebut ditemukan pada indeks ke-". Namun sebaliknya, jika angka tidak ditemukan, program mencetak pesan bahwa "tidak dapat ditemukan pada data". Program kemudian mencetak hasil pencarian menggunakan algoritma Sequential Search.

#### Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/039ff706-58fb-4b51-8f8e-31623d200e88)

Dari output tersebut dapat kita ketahui bahwa, dari data yang berjumlah 10 yaitu 9, 4, 1, 7, 5, 12, 4, 13, 4, 10, angka 10 ditemukan pada indeks ke-9. 

#### Full code Screenshot:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/edf90c23-fb1d-44ca-af2d-ae9ecab5ebc6)

Kesimpulannya, program di atas menggunakan algoritma Sequential Search untuk mencari data tertentu dalam array. Cara kerja Sequential Search yaitu dengan mencari data secara berurutan dalam array hingga data yang dicari ditemukan atau seluruh array telah diperiksa.

### 2. Guided 2: Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search

```C++
#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

int Data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for (i = 0; i < 7; i++) {
        min = i;
        for (j = i + 1; j < 7; j++) {
            if (Data[j] < Data[min]) {
                min = j;
            }
        }
        temp = Data[i];
        Data[i] = Data[min];
        Data[min] = temp;
    }
}

void binarysearch() {
    // searching
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 7;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if (Data[tengah] == cari) {
            b_flag = 1;
            break;
        }
        else if (Data[tengah] < cari) {
            awal = tengah + 1;
        }
        else {
            akhir = tengah - 1;
        }
    }
    if(b_flag == 1) {
        cout << "\n Data ditemukan pada index ke- " << tengah << endl;
    }
    else {
        cout << "\n Data tidak ditemukan\n";
    }
}

int main () {
    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Data : ";

    //tampilkan data awal
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << Data[x];
    }
    cout << endl;

    cout << "\n Masukkan data yang ingin Anda cari : ";
    cin >> cari;
    cout << "\n Data diurutkan : ";

    // urutkan data dengan selection sort
    selection_sort();

    // tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << Data[x];
    }
    cout << endl;

    binarysearch();

    _getche();
    return EXIT_SUCCESS;
}
```
Program di atas merupakan program untuk mencari data tertentu dimana menggunakan implementasi Binary Search pada array yang telah diurutkan menggunakan Selection Sort. Berikut adalah penjelasannya.

Pertama, program mendefinisikan array "Data" yang berisi 7 bilangan bulat dan variabel "cari" yang berfungsi untuk menyimpan nilai yang akan dicari dalam array. Selanjutnya, fungsi selection_sort() yang berfungsi untuk mengurutkan array "Data" menggunakan selection sort. Fungsi ini secara berulang memilih elemen terkecil dari sisa array yang belum diurutkan dan menukarnya dengan elemen pertama.

Kemudian fungsi binarysearch(). Fungsi ini melakukan pencarian biner pada array yang telah diurutkan. Apabila nilai yang dicari lebih kecil dari nilai tengah, pencarian selanjutnya akan dilakukan pembagian data menjadi dua bagian pada bagian kiri, dan sebaliknya. Pada fungsi ini juga mencetak pesan apakah nilai ditemukan atau tidak beserta indeksnya.

Lalu di dalam fungsi main(), judul "BINARY SEARCH", array "Data" sebelum diurutkan, pesan "Masukkan data yang ingin Anda cari", dan Array yang sudah diurutkan menggunakan selection_sort(), semuanya dicetak. Setelah itu, fungsi binarysearch() dipanggil untuk melakukan pencarian pada nilai yang dimasukkan tadi dan hasil pencarian beserta indeksnya akan dicetak.

Terakhir, terdapat "_getche()" yang berfungsi untuk menahan konsol agar tetap terbuka setelah program selesai dijalankan dan program mengembalikan nilai "EXIT_SUCCESS" yang menunjukkan bahwa program telah berjalan dengan sukses.

#### Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/1d8484c2-eeea-4546-b44a-c1c9d63e877d)

Dari output tersebut dapat kita ketahui bahwa, data sebelum diurutkan adalah 1, 8, 2, 5, 4, 9, 7. Lalu saya memasukkan data 7 untuk dicari. Setelah itu, program berjalan untuk mengurutkan data terlebih dahulu menjadi 1, 2, 4, 5, 7, 8, 9, dan ditemukanlah data 7 pada indeks ke-4 dari data tersebut. 

#### Full code Screenshot:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/342d47eb-3b32-410e-8d97-31867a77878a)

Kesimpulannya, program di atas bertujuan untuk mencari nilai tertentu dalam array menggunakan algoritma Binary Search setelah mengurutkan array menggunakan algoritma Selection Sort.

## Unguided 

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Fungsi untuk mencari sebuah huruf pada sebuah string menggunakan Binary Search
int binarySearch(const string &sentence, char target) {
    int left = 0;
    int right = sentence.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Jika huruf pada indeks tengah adalah target, kembalikan indeks tengah
        if (sentence[mid] == target)
            return mid;
        // Jika huruf pada indeks tengah kurang dari target, cari di sebelah kanan
        else if (sentence[mid] < target)
            left = mid + 1;
        // Jika huruf pada indeks tengah lebih dari target, cari di sebelah kiri
        else
            right = mid - 1;
    }

    // Jika tidak menemukan huruf, kembalikan -1
    return -1;
}

int main() {
    string input;
    char target;

    cout << "Masukkan kalimat: ";
    getline(cin, input);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> target;

    // Memisahkan kalimat menjadi kata-kata
    stringstream ss(input);
    string word;
    vector<string> words;
    while (ss >> word) {
        words.push_back(word);
    }

    // Mencari huruf dalam setiap kata dan menampilkan hasil
    for (int i = 0; i < words.size(); ++i) {
        int index = binarySearch(words[i], target);
        if (index != -1) {
            cout << "Huruf '" << target << "' ditemukan pada indeks " << index << " dalam kata \"" << words[i] << "\"" << endl;
            // Menghitung indeks absolut huruf dalam kalimat
            int absolute_index = index;
            for (int j = 0; j < i; ++j) {
                absolute_index += words[j].size(); // Tidak perlu menambahkan 1 karena tidak ada spasi
            }
            cout << "Huruf '" << target << "' ditemukan pada indeks absolut " << absolute_index << " dalam kalimat." << endl;
            return 0;
        }
    }

    cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << endl;

    return 0;
}
```
Program di atas adalah program untuk mencari huruf dalam setiap kata pada kalimat yang diinputkan dengan menggunakan Binary Search. Berikut adalah penjelasannya:

Pertama, kita diminta untuk memasukkan sebuah kalimat dan kalimat tersebut disimpan dalam variabel "input". Setelah itu, kita diminta memasukkan huruf yang ingin dicari dalam kalimat, lalu huruf tersebut disimpan dalam variabel "target". Selanjutnya, program memproses kalimat yang diinputkan menggunakan objek "stringstream". Kalimat-kalimat yang sudah diinputkan kemudian dipisahkan menjadi kata-kata, dan setiap kata disimpan dalam vektor "words".

Kemudian, terdapat fungsi "absolute_index" yang akan menjumlahkan panjang kata-kata sebelum kata yang berisi huruf yang ditemukan, dan juga mengakumulasikan panjang spasi di antara kata-kata tersebut. Namun, ketika huruf yang dicari berada di awal kalimat, program akan mencetak pesan "huruf tidak ditemukan". Hal ini terjadi karena ketika huruf yang dicari berada di awal kalimat, tidak ada spasi sebelumnya, sehingga perhitungan indeks absolut menjadi salah.

Setelah memisahkan kata-kata, program melakukan pencarian huruf yang diinginkan ("target") dalam setiap kata menggunakan fungsi "binarySearch". Jika huruf ditemukan dalam suatu kata, program mencetak pesan "Huruf ditemukan pada indeks dalam kata" dan "Huruf ditemukan  pada indeks absolut dalam kalimat". Namun, jika huruf tidak ditemukan dalam semua kata, program mencetak pesan "Huruf tersebut tidak ditemukan dalam kalimat".

#### Output:
![Screenshot 2024-04-04 104206](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/4d5041be-5355-4182-9aa0-65be1ca94b46)

Dari output tersebut dapat kita ketahui bahwa, saya menginputkan kalimat "hari ini panas", kemudian saya mencari huruf "n". Setelah program berjalan, didapatkan hasil bahwa Huruf "n" ditemukan pada indeks 1 dalam kata "ini" dan Huruf "n" ditemukan pada indeks absolut 5 dalam kalimat. 

#### Full code Screenshot:
![Screenshot 2024-04-04 104508](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/a5242ef9-7081-4b80-bf31-7a44f653b281)

Kesimpulannya, Binary Search merupakan algoritma pencarian yang efisien digunakan untuk mencari sebuah nilai dalam kumpulan data terurut. Program di atas memberikan hasil yang akurat apabila huruf yang dicari benar-benar terdapat dalam kalimat yang diinputkan. Pada program di atas juga diasumsikan bahwa setiap kata dalam kalimat dianggap sudah terurut.  

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk mengecek apakah sebuah karakter adalah huruf vokal atau bukan
bool isVowel(char c) {
    // Mengubah huruf kecil menjadi huruf besar untuk memudahkan pengecekan
    c = toupper(c);
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat
int countVowels(const string &sentence) {
    int count = 0;
    for (char c : sentence) {
        if (isalpha(c) && isVowel(c)) {
            count++;
        }
    }
    return count;
}

int main() {
    string sentence;

    cout << "Masukkan kalimat: ";
    getline(cin, sentence);

    int vowelCount = countVowels(sentence);

    cout << "Jumlah huruf vokal dalam kalimat tersebut adalah: " << vowelCount << endl;

    return 0;
}
```
Program di atas merupakan sebuah program untuk menghitung banyaknya huruf vocal yang terdapat dalam sebuah kalimat yang diinputkan. Berikut adalah penjelasannya.

Pada program di atas, fungsi "isVowel" digunakan untuk mengecek apakah sebuah karakter adalah huruf vokal atau bukan. Fungsi ini mengembalikan "true" jika karakter yang diberikan adalah salah satu dari huruf vokal yaitu A, I, U, E, O dan mengembalikan "false" jika tidak. 

Kemudian terdapat fungsi "countVowels" yang berfungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat. Program melakukan iterasi melalui setiap karakter dalam kalimat dan memanggil fungsi "isVowel" untuk setiap karakter yang merupakan huruf. Apabila karakter tersebut adalah huruf vokal, maka jumlah huruf vokal akan bertambah.

Selanjutnya, di dalam "main" program meminta kita untuk menginputkan sebuah kalimat menggunakan "getline". Lalu, program memanggil fungsi "countVowels" dengan kalimat yang diinputkan kita tadi sebagai argumen. Dan terakhir, hasil jumlah huruf vokal kemudian dicetak.

#### Output:
![Screenshot 2024-04-04 111239](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/f95e5482-6802-4f94-9863-8e0e3784e903)

Dari output tersebut dapat kita ketahui bahwa, saya menginputkan kalimat "algoritma struktur data", kemudian program berjalan untuk mencari jumlah huruf vokal yang terdapat dalam kalimat. Didapatkan hasil bahwa jumlah huruf vokal dalam kalimat tersebut adalah 8, yaitu a, o, i, a, u, u, a, a. 

#### Full code Screenshot:
![Screenshot 2024-04-04 111345](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/82210fc0-6d9d-4677-8f4c-e4cd7e7f6e52)

Kesimpulannya, program di atas merupakan implementasi sederhana untuk menghitung jumlah huruf vokal dalam sebuah kalimat dengan menggunakan fungsi isVowel untuk mengecek karakter huruf vokal dan fungsi countVowels untuk menghitung jumlahnya, sehingga program di atas berhasil mengecek huruf vokal dan menghitung jumlah huruf vokal dalam kalimat yang dimasukkan oleh pengguna. 

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
#include <iostream>

using namespace std;

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int n = sizeof(data) / sizeof(data[0]); // Menghitung jumlah elemen dalam array data
    int cari = 4;
    int count = 0;

    // Algoritma Sequential Search untuk mencari angka 4 dalam data
    for (int i = 0; i < n; ++i) {
        if(data[i] == cari) {
            count++;
        }
    }

    cout << "Jumlah angka 4 dalam data adalah: " << count << endl;

    return 0;
}
```
Program di atas adalah program untuk mencari jumlah angka 4 pada sebudah data dengan menggunakan Sequential Search. Berikut adalah penjelasannya.

Pertama, array "data" yang berisi 10 angka, yaitu 9, 4, 1, 4, 7, 10, 5, 4, 12, dan 4 didefinisikan dahulu. Kemudian terdapat variabel "n" yang berfungsi untuk mengetahui jumlah elemen dalam array "data". Selanjutnya, variabel "cari" yang diinisialisasi dengan angka 4, dimana angka tersebut merupakan angka yang ingin dicari dalam array.

Kemudian, untuk mencari setiap kemunculan angka 4 dalam array "data", program menggunakan Sequential Search. Setiap kali angka 4 ditemukan, variabel "count" akan bertambah satu. Lalu setelah selesai mencari, program mencetak jumlah angka 4 yang ditemukan dalam data.

#### Output:
![Screenshot 2024-04-04 113323](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/8ac6004d-1028-4d88-a3f2-44f5f549e794)

Dari output tersebut dapat kita ketahui bahwa, array "data" yang berisi 10 angka, yaitu 9, 4, 1, 4, 7, 10, 5, 4, 12, dan 4, setelah program berjalan untuk mencari jumlah angka 4 dalam data, didapatkan hasil bahwa jumlah angka 4 dalam data adalah sebanyak 4.

#### Full code Screenshot:
![Screenshot 2024-04-04 113226](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/69056a9d-ea9b-4448-a675-d8829637888d)

Kesimpulannya, program di atas merupakan implementasi pencarian jumlah kemunculan angka 4 dalam sebuah array data menggunakan Sequential Search. Dengan menggunakan Sequential Search, program dapat mencari angka 4 dalam data secara berurutan dan memberikan hasil pencarian yang akurat.

## Kesimpulan
Ringkasan dan interpretasi pandangan saya dari hasil praktikum dan pembelajaran yang didapat yaitu:
- Hasil Praktikum

Hasil dari praktikum keempat ini, saya menjadi tahu mengenai konsep dasar algoritma searching. Kemudian, saya juga menjadi tau bahwa terdapat 2 metode pada algoritma seraching, yaitu Sequential Search dan Binary Search. Selain itu, saya juga dapat memahami perbedaan karakteristik antara Sequential Search dan Binary Search.

- Pembelajaran yang didapat

Pada praktikum ini, saya mendapat pembelajaran yang banyak dan berarti. Saya banyak belajar mengenai implementasi algoritma searching Sequential Search dan Binary Search pada program c++. Kemudian saya juga lebih banyak belajar dari evaluasi praktikum kemarin terkait cara interpretasi dari setiap fungsi dan kode program. 

## Referensi
[1] F. Yanti dan E.S. Eriana, Algoritma Sorting dan Searching. Eureka Media Aksara, 16 Maret 2024.

[2] Y. Rahmanto, dkk, "Penerapan Algoritma Sequential Search pada Aplikasi Kamus Bahasa Ilmiah Tumbuhan", Jurnal Buana Informatika, vol. 12, no. 1, pp. 22-23, 1 April 2021.

[3] N. Imamah, M.I. Bahari, "PERBANDINGAN ALGORITMA SEQUENTIAL SEARCH DAN ALGORITMA BINARY SEARCH PADA APLIKASI KAMUS BAHASA INDONESIA MENGGUNAKAN PHP DAN JQUERY", Jurnal Informatika, vol. 8, no. 1, pp. 2-3, Juni 2021.