# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Olivia Intan Puspita</p>

## Dasar Teori
Bahasa pemrograman merupakan suatu alat yang digunakan untuk berkomunikasi antara manusia dengan komputer [2]. Algoritma merupakan bagian terpenting dan tidak dapat dipisahkan dari pemrograman. Algoritma pengurutan (sorting) meletakkan elemen data kedalam kumpulan data urutan tertentu, proses pengurutan yang sebelumnya data disusun acak menjadi tersusun teratur menurut aturan tertentu [1].

Array adalah kumpulan data untuk menyimpan item bertipe data sama, biasanya pada pengurutan data adalah data dengan tipe sama. Setiap data disimpan dalam alamat memori yang berbeda yang disebut elemen array [1]. Komponen-komponen dari array antara lain nama array, nilai array, indeks array, jenis array.

Jenis-jenis array dibagi menjadi:
1. Array Satu Dimensi 

Array satu dimensi tidak lain adalah kumpulan elemen-elemen identik yang tersusun dalam satu baris, tetapi isi dari elemen tersebut boleh berbeda.  Dapat disebut juga dengan istilah vektor yang menggambarkan data dalam suatu urutanDeklarasi : Type_Data Nama_Variabel [index] Misalnya : int A[5]

2. Array Dua Dimensi

Array dua dimensi yang sering digambarkan sebagai sebuah matriks merupakan perluasan dari sebuah array satu dimensi. Jika array satu dimensi hanya terdiri dari sebuah baris dengan beberapa kolom elemen maka array dua dimensi terdiri dari beberapa baris dan beberapa kolom elemen yang bertipe sama. Pendeklarasian array dua dimensi hampir sama dengan pendeklarasian array satu dimensi, kecuali bahwa array dua dimensi terdapat dua jumlah elemen array yang terdapat di dalam kurung siku dan keduanya boleh tidak sama.Deklarasi : Type_Data Nama_Variabel [Index1] [index2]; Misal : int A[3][2]

3. Array Tiga Dimensi

Array tiga dimensi digunakan untuk mengelola data dalam bentuk 3 dimensi atautiga sisi. Deklarasi : Type_Data Nama_Variabel [index1] [ndex2] [index3]; Misal : int A [3][4][2]

4. Array Banyak Dimensi

Sebenarnya array banyak dimensi ini tidak terlalu sering dipakai seperti halnya array satu dimensi, dua dimensi, dan tiga dimensi. Array banyak dimensi ini pada dasarnya sama dengan array sebelumnya kecuali pada jumlah dimensinya. Deklarasi : Type_Data Nama_Variabel [index1] [ndex2] [index3] [ndex4]. Misal : int A [3][4][2][5] [3].

## Guided 

### 1. Guided 1: Program Input Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;
//Program input array 3 dimensi
int main()
{
    //Deklarasi array
    int arr[2][3][3];
    //Input elemen
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
            
        }
        cout << endl;
    }
    //Output array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << "Data Array[" << x << "] [" << y << "] [" << z << "] = " << arr[x][y][z] << endl;
            }
        }
    }
    cout << endl;
    //Tampilan array
    for (int x = 0; x < 2; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            for (int z = 0; z < 3; z++)
            {
                cout << arr[x][y][z] << ends;
            }
            cout << endl;
        }
        cout << endl;
    }
}
```
Program di atas merupakan salah satu contoh penggunaan array tiga dimensi. Array tiga dimensi digunakan untuk menyimpan data dalam tiga dimensi, pada program di atas memiliki dimensi [2][3][3]. 
Berikut adalah penjelasannya.
- Program dimulai dengan mendeklarasikan sebuah array tiga dimensi arr dengan ukuran [2][3][3]. Ini berarti ada 2 matriks, masing-masing matriks memiliki 3 baris dan 3 kolom.

- Selanjutnya, program meminta pengguna untuk memasukkan nilai untuk setiap elemen array dengan pesan yang menunjukkan indeks elemen tersebut. Ini dilakukan menggunakan tiga loop bersarang, yang mengiterasi melalui indeks x, y, dan z.

- Setelah semua nilai dimasukkan, program kemudian mencetak kembali nilai-nilai yang dimasukkan oleh pengguna bersama dengan indeksnya.

- Kemudian, program mencetak ulang nilai-nilai array dalam format yang sedikit berbeda. Nilai-nilai ini dicetak dalam tiga loop bersarang juga, tetapi setiap elemen dipisahkan dengan spasi dan setiap baris baru dipisahkan dengan newline. Hal ini bertujuan memberikan tampilan matriks yang lebih terstruktur.


### 2. Guided 2: Program Mencari Nilai Maksimal pada Array
```C++
#include <iostream>
using namespace std;

int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}
```
Program di atas merupakan sebuah program sederhana yang meminta pengguna untuk memasukkan panjang array dan nilai-nilai dalam array tersebut. Kemudian, program akan mencari nilai maksimum dari array yang diinputkan dan mencetak nilai maksimum beserta indeksnya.
Berikut adalah penjelasannya.

- Program meminta pengguna untuk memasukkan panjang array (a) melalui pesan "Masukkan panjang array: ".
Setelah pengguna memasukkan panjang array, program membuat array dengan panjang yang sesuai (int array[a]).

- Pengguna diminta untuk memasukkan nilai-nilai untuk setiap elemen array sebanyak panjang array yang telah diinputkan. Program menampilkan pesan "Array ke-i: " di mana 'i' adalah indeks elemen array yang sedang diminta inputnya.

- Setelah semua nilai dimasukkan, program mencari nilai maksimum dari array tersebut menggunakan loop for. Nilai maksimum diinisialisasi dengan nilai pertama dalam array (array[0]) dan kemudian dibandingkan dengan setiap elemen array. 
Jika nilai yang sedang diperiksa lebih besar dari nilai maksimum (maks), maka nilai maksimum diperbarui dengan nilai tersebut dan lokasi indeksnya disimpan dalam variabel lokasi.

- Setelah loop selesai, program mencetak nilai maksimum dan indeksnya dengan pesan "Nilai maksimum adalah maks berada di Array ke lokasi".


## Unguided 

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
- Program
```C++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Input panjang array dari user
    int length;
    cout << "Masukkan panjang array: ";
    cin >> length;

    // Deklarasi array sesuai panjang yang dimasukkan
    vector<int> arr(length);

    // Input elemen array dari user
    cout << "Masukkan " << length << " angka:\n";
    for (int i = 0; i < length; ++i) {
        cout << "Data array ke-" << (i + 1) << ": ";
        cin >> arr[i];
    }

    // Menampilkan data array
    cout << "Data Array :";
    for (int i = 0; i < length; ++i) {
        cout << " " << arr[i];
        if (i != length - 1) {
            cout << " ";
        }
    }
    cout << endl;

    // Menampilkan nomor genap
    cout << "Nomor Genap  :";
    bool isFirstEven = true;
    for (int i = 0; i < length; ++i) {
        if (arr[i] % 2 == 0) {
            if (!isFirstEven) {
                cout << ",";
            }
            cout << " " << arr[i];
            isFirstEven = false;
        }
    }
    cout << endl;

    // Menampilkan nomor ganjil
    cout << "Nomor Ganjil :";
    bool isFirstOdd = true;
    for (int i = 0; i < length; ++i) {
        if (arr[i] % 2 != 0) {
            if (!isFirstOdd) {
                cout << ",";
            }
            cout << " " << arr[i];
            isFirstOdd = false;
        }
    }
    cout << endl;

    return 0;
}
```
- Interpretasi

Program di atas merupakan sebuah program untuk memasukkan panjang array dan nilai-nilai elemen array. Setelah nilai-nilai dimasukkan, program akan mencetak kembali nilai-nilai tersebut bersama dengan klasifikasinya sebagai nomor genap atau ganjil.

Berikut penjelasan langkah kerja programnya:
- Pengguna diminta untuk memasukkan panjang array.
Array dengan panjang yang dimasukkan pengguna dideklarasikan menggunakan vector.
- Pengguna diminta untuk memasukkan nilai untuk setiap elemen array.
- Setelah semua nilai dimasukkan, program mencetak kembali nilai-nilai array dengan menampilkan setiap elemen array.
- Program kemudian mencetak nomor genap yang ada dalam array dengan melakukan iterasi melalui array dan memeriksa apakah setiap nilai adalah genap atau tidak. Jika nilai tersebut genap, maka nilai tersebut dicetak bersama dengan tanda koma.
- Program melakukan hal yang sama untuk mencetak nomor ganjil yang ada dalam array.


#### Output:
<img width="697" alt="Screenshot 2024-03-23 200236" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/a48c2221-96b8-4e6f-b315-07f243fd865e">

Dari output dapat diketahui bahwa pengguna memasukkan panjang array 10. Kemudian nilai untuk setiap elemen array yang dimasukkan secara berurutan yaitu 1, 2, 3, 4, 5, 6, 7, 8, 9, 10. Dari elemen array tersebut didapatkan hasil nomor genapnya adalah 2, 4, 6, 8, 10. Sedangkan untuk nomor ganjilnya adalah 1, 3, 5, 7, 9. 


#### Full code Screenshot:
<img width="960" alt="Screenshot 2024-03-23 200416" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/3d7a649f-801c-429a-b9d9-8e60d5228d54">

Dengan demikian, program ini memberikan informasi kepada pengguna tentang nilai-nilai dalam array yang dimasukkan, serta memisahkan nilai-nilai tersebut menjadi dua kelompok, yaitu nomor genap dan nomor ganjil.

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

- Program

```C++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Input ukuran array tiga dimensi dari user
    int x_size, y_size, z_size;
    cout << "Masukkan ukuran array tiga dimensi (x y z): ";
    cin >> x_size >> y_size >> z_size;

    // Deklarasi array tiga dimensi sesuai dengan ukuran yang dimasukkan oleh pengguna
    vector<vector<vector<int>>> arr(x_size, vector<vector<int>>(y_size, vector<int>(z_size)));

    // Input elemen array dari user
    cout << "Masukkan elemen-elemen array:\n";
    for (int x = 0; x < x_size; ++x) {
        for (int y = 0; y < y_size; ++y) {
            for (int z = 0; z < z_size; ++z) {
                cout << "Array[" << x << "][" << y << "][" << z << "]: ";
                cin >> arr[x][y][z];
            }
        }
    }

    // Menampilkan elemen-elemen array
    cout << "Data array:\n";
    for (int x = 0; x < x_size; ++x) {
        for (int y = 0; y < y_size; ++y) {
            for (int z = 0; z < z_size; ++z) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```

- Interpretasi

Program di atas adalah sebuah program untuk memasukkan elemen-elemen array tiga dimensi dan kemudian mencetak kembali elemen-elemen tersebut.

Berikut penjelasan langkah kerja programnya:
- Pengguna diminta untuk memasukkan ukuran array tiga dimensi, dimana disini tiga dimensinya yaitu x, y, dan z.
- Setelah ukuran dimasukkan, array tiga dimensi arr dideklarasikan menggunakan vector dari vector dari vector. Ini berarti array tiga dimensi ini memiliki tiga tingkat dimensi.
- Selanjutnya, program meminta pengguna untuk memasukkan nilai untuk setiap elemen array. Ini dilakukan dengan tiga loop bersarang, yang masing-masing bertanggung jawab untuk mengatur indeks x, y, dan z dari array. Loop x digunakan untuk mengatur baris, loop y untuk mengatur kolom, dan loop z untuk mengatur kedalaman array.
- Setelah semua nilai dimasukkan, program mencetak kembali elemen-elemen array sesuai dengan format array tiga dimensinya. Ini dilakukan dengan menggunakan tiga loop bersarang lagi untuk x, y, dan z, dan mencetak setiap elemen array.

#### Output:
<img width="771" alt="Screenshot 2024-03-23 201705" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/1c5af636-e3be-4ace-bef9-ef9778faafe4">

Dari output tersebut dapat dilihat bahwa pengguna memasukkan ukuran array tiga dimensi (x y z) dengan (2 3 3), sehingga didapatkan hasil output yang keluar seperti gambar di atas.

#### Full code Screenshot:
<img width="960" alt="Screenshot 2024-03-23 201828" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/13014541-743e-471f-9f28-9d8f0741e504">

Dengan demikian, program ini memungkinkan pengguna untuk memasukkan dan menampilkan array tiga dimensi dengan ukuran yang ditentukan oleh pengguna. Hal ini berguna dalam berbagai aplikasi yang melibatkan pemrosesan data tiga dimensi. 

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

- Program
```C++
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int size;
    cout << "Masukkan panjang array: ";
    cin >> size;

    // Meminta pengguna untuk memasukkan elemen-elemen array
    vector<int> arr(size);
    cout << "Masukkan " << size << " angka:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Array[" << i << "]: ";
        cin >> arr[i];
    }

    // Menampilkan menu
    cout << "\nMenu:\n";
    cout << "1. Cari nilai maksimum\n";
    cout << "2. Cari nilai minimum\n";
    cout << "3. Cari nilai rata-rata\n";
    cout << "Pilih menu (1/2/3): ";

    int choice;
    cin >> choice;

    // Memilih opsi sesuai dengan input pengguna
    switch (choice) {
        case 1: {
            int max_val = *max_element(arr.begin(), arr.end());
            cout << "Nilai maksimum: " << max_val << endl;
            break;
        }
        case 2: {
            int min_val = *min_element(arr.begin(), arr.end());
            cout << "Nilai minimum: " << min_val << endl;
            break;
        }
        case 3: {
            double sum = accumulate(arr.begin(), arr.end(), 0);
            double average = sum / size;
            cout << "Nilai rata-rata: " << average << endl;
            break;
        }
        default:
            cout << "Pilihan tidak valid.\n";
    }

    return 0;
}
```
- Interpretasi

Program di atas adalah program untuk memasukkan nilai-nilai array dan kemudian memilih opsi untuk mencari nilai maksimum, minimum, atau rata-rata dari array tersebut.

Berikut penjelasan langkah kerja programnya:
- Pertama, pada program tersebut pengguna diminta untuk memasukkan panjang array yang akan digunakan untuk menentukan jumlah elemen yang akan dimasukkan.
- Setelah panjang array dimasukkan, array arr dideklarasikan menggunakan vector, dan pengguna diminta untuk memasukkan nilai untuk setiap elemen array.
- Setelah semua nilai dimasukkan, program menampilkan menu dengan opsi untuk mencari nilai maksimum, minimum, atau rata-rata dari array.
- Pengguna memilih opsi dari menu.
Opsi 1: Program menggunakan fungsi max_element dari header <algorithm> untuk mencari nilai maksimum dalam array. 
Opsi 2: Program menggunakan fungsi min_element dari header <algorithm> untuk mencari nilai minimum dalam array.
Opsi 3: Program menggunakan fungsi accumulate dari header <numeric> untuk menjumlahkan semua elemen array dan kemudian membaginya dengan panjang array untuk mendapatkan rata-rata.
- Hasil pencarian nilai maksimum, minimum, atau rata-rata kemudian ditampilkan kepada pengguna.

#### Output:
<img width="772" alt="Screenshot 2024-03-23 211256" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/c585b790-e492-44e4-9e0f-e027a3346b80">

Dari output dapat kita ketahui bahwa pengguna memasukkan panjang array 5, lalu elemen array yang dimasukkan ada 2, 4, 6, 8, 10. Setelah itu pada pilihan menu pengguna memilih opsi 3 yang dimana itu adalah mencari nilai rata-rata, kemudian hasil output yang muncul dari pilihan 3 adalah 6. Hal ini terbukti benar.

#### Full code Screenshot:
<img width="960" alt="Screenshot 2024-03-23 211352" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/30bf3b28-10f9-427c-8bff-05defb655907">

Dengan demikian, program ini memungkinkan pengguna untuk dengan mudah melakukan analisis sederhana terhadap nilai-nilai dalam array mereka, seperti mencari nilai maksimum, minimum, dan rata-rata.

## Kesimpulan
Ringkasan dan interpretasi pandangan saya dari hasil praktikum dan pembelajaran yang didapat yaitu:
- Hasil Praktikum

Hasil dari praktikum kedua ini, saya menjadi tahu mengenai pengertian array, konsep array, jenis-jenis array, serta implementasi array pada kode program yang dibuat. Array ternyata sangat berperan penting di dalam pemrograman, apalagi setelah tau apa saja jenis-jenis array. Array bisa dibilang sebagai pondasi dalam membuat program yang berhubungan dengan matematis, oleh karena itu penting bagi saya untuk belajar lagi dan lebih memahami lagi terkait konsep array.

- Pembelajaran yang didapat

Pada praktikum ini saya kembali mendapat pembelajaran yang banyak dan berarti. Saya bisa lebih mengerti dalam mengimplementasikan program array di bahasa pemrograman C++. Tak hanya itu, untuk menginput gambar, mencari dasar teori, membuat interpretasi, saya juga lebih terbiasa. Semakin dilatih maka semakin terbiasa juga.

## Referensi
[1] E. Retnoningsih, "Algoritma Pengurutan Data (Sorting) Dengan Metode
Insertion Sort dan Selection Sort", INFORMATION MANAGEMENT FOR EDUCATORS AND PROFESSIONALS, Vol. 3, No. 1, pp. 96, Desember 2018.

[2] S. Anam, et al., Cara Mudah Belajar Bahasa Pemrograman C++. Indonesia: Universitas Brawijaya Press, 2021.

[3] M. A. Pratama, “STRUKTUR DATA ARRAY DUA DIMENSI  PADA PEMROGRAMAN C++”, 29 MarET 2020. [Online]. Available: osf.io/vyech. 