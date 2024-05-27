# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>
<p align="center">Nama: Olivia Intan Puspita</p>
<p align="center">NIM: 2311110006</p>
<p align="center">Kelas: S1SD-04-A</p>

## Dasar Teori

Sebagian besar algoritma dapat ditulis dalam bentuk rekursif. Keuntungan dari penulisan algoritma dalam bentuk rekursif adalah memudahkan dalam menerjemahkan ke dalam bahasa pemrograman dan program menjadi sangat ringkas. Selain memiliki beberapa keuntungan dalam implementasinya, algoritma dalam bentuk rekursif lebih mudah membuktikan kebenarannya dibandingkan dengan algoritma yang berbentuk iteratif [1].

Algoritma rekursif adalah suatu algoritma yang memanggil dirinya sendiri dengan input yang semakin mengecil dan berhenti pada suatu kondisi tertentu dari input tersebut. Secara umum, algoritma rekursif ditulis dalam sebuah fungsi yang terdiri dari kasus basis/pemberhentian dan fungsi yang memanggil dirinya sendiri sebagaimana diilustrasikan pada gambar di bawah ini[1]. 

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/f40a24fc-b464-4835-b228-6d1af535a444)

Fungsi rekursif terdiri atas dua bagian utama yakni basis dan rekurens. Basis merupakan bagian yang berisi nilai secara eksplisit dan berfungsi menghentikan perulangan yang dilakukan rekurens. Rekurens merupakan bagian dari objek yang mendefinisikan fungsi itu sendiri. Suatu rekurens harus mengarah ke basis. Rekurens akan berhenti ketika bertemu dengan basis. Jika tidak ada pertemuan itu akan terjadi perulangan tak terhingga di dalam fungsi tersebut yang tidak diinginkan [3].

Pengertian fungsi rekursif mempunyai satu atau lebih permasalahan dasar atau umum, yang berarti input fungsinya menghasilkan hasil yang mudah dengan tidak berulang, dan terdapat satu atau lebih masalah rekursif, yang berarti inputannya berulang sehingga programnya berulang untuk memanggil dirinya sendiri. Contohnya, pada fungsi faktorial dapat diselesaikan dengan rekursif pada persamaan 0! = 1 dan, untuk semua m > 0, m! = m(m-1)![2].

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/d87c0e33-5071-4b35-a1c4-72e17c3426bc) 
Gambar di atas adalah salah satu contoh rekursif untuk menghitung faktorial [4].

Terdapat dua jenis dalam algoritma rekursif:
1. Rekursif Langsung

Fungsi rekursif yang memanggil dirinya sendiri, sebagian besar pada contoh menunjukkan rekursif langsung.

2. Rekursif Tidak Langsung

Disebut juga rekursif timbal balik. Fungsi rekursif tidak langsung terjadi ketika suatu fungsi dipanggil bukan oleh dirinya sendiri melainkan oleh fungsi lain [2].

Kelebihan dari rekursif:
- Sangat mudah untuk melakukan perulangan dengan batasan yang luas dalam artian melakukan perulangan dalam skala yang besar
- Dapat melakukan perulangan dengan batasan fungsi

Kekurangan rekursif:
- Tidak bisa melakukan nested loop atau looping bersarang
- Biasanya membuat fungsi sulit untuk dipahami, hanya cocok untuk persoalan tertentu saja
- Memungkinkan terjadinya overflow pada stack, yang berarti stack tidak lagi mampu menangani permintaan pemanggilan fungsi karena kehabisan memori (stack adalah area memori yang dipakai untuk variable lokal untuk mengalokasikan memori ketika suatu fungsi dipanggil) [3].

## Langkah Praktikum

### Guided 1: Rekursif Langsung (Direct Recursion)
#### A. Program:

```C++
#include <iostream>

using namespace std;

void countdown(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    countdown(n - 1);
}

int main() {
    cout << "Rekursif Langsung: ";
    countdown(5);
    cout << endl;
    return 0;
}
```

#### B. Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/13296447-96ff-4037-9205-b4e1ba85d016)

#### C. Interpretasi:

- #### Interpretasi program

Program di atas merupakan salah satu implementasi sederhana dari rekursif langsung. Terdapat fungsi ```countdown(int n)``` pada program di atas, fungsi ini menerima bilangan bulat ```n```. Jika ```n``` sama dengan 0, fungsi langsung mengembalikan nilai. Namun jika tidak, maka nilai ```n``` akan dicetak dan diikuti dengan spasi ```cout << n << " "```. Lalu, fungsi juga akan memanggil dirinya sendiri dengan nilai ```n - 1```. Selanjutnya terdapat fungsi ```main()```, fungsi inilah yang akan dieksekusi nantinya. Pada fungsi ```main()``` mencetak pesan ```"Rekursif Langsung: "```. Kemudian fungsi ini memanggil fungsi ```countdown``` dimana pada program di atas memiliki nilai ```5```. Setelah itu fungsi mengembalikan nilai 0 ```return 0``` dimana itu menandakan bahwa program telah selesai.

- #### Interpretasi output

Sesuai dengan perintah yang terdapat pada fungsi ```main()```, program mencetak pesan ```Rekursif Langsung: ``` terlebih dahulu. Kemudian program melakukan hitung mundur nilai dari ```n``` yaitu 5. Penjelasan detailnya seperti ini:
1. Panggilan pertama ```countdown(5)```. Ini berarti ```n``` adalah 5 dan program mencetak ```5```. Kemudian fungsi ```countdown``` memanggil dirinya sendiri ```n - 1``` berarti 5-1 = 4

2. Panggilan kedua ```countdown(4)```. Ini berarti ```n``` adalah 4 dan program mencetak ```4```. Kemudian fungsi ```countdown``` memanggil dirinya sendiri ```n-1``` berarti 4-1 = 3

3. Panggilan ketiga ```countdown(3)```. Ini berarti ```n``` adalah 3 dan program mencetak ```3```. Kemudian fungsi ```countdown``` memanggil dirinya sendiri ```n-1``` berarti 3-1 = 2

3. Panggilan keempat ```countdown(2)```. Ini berarti ```n``` adalah 2 dan program mencetak ```2```. Kemudian fungsi ```countdown``` memanggil dirinya sendiri ```n-1``` berarti 2-1 = 1

3. Panggilan kelima ```countdown(1)```. Ini berarti ```n``` adalah 1 dan program mencetak ```1```. Kemudian fungsi ```countdown``` memanggil dirinya sendiri ```n-1``` berarti 1-1 = 0

3. Panggilan keenam ```countdown(0)```. Disini ```n``` adalah 0 yang berarti basis rekursif sudah tercapai ```if (n == 0)```, maka fungsi langsung mengembalikan nilai tanpa mencetak apapun. 

Sehingga, didapatkan hasil "Rekursif Langsung: 5, 4, 3, 2, 1".

### Guided 2: Rekursif Tidak Langsung (Indirect Recursion)
#### A. Program:

```C++
#include <iostream>

using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1);
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2);
    }
}

int main() {
    int num = 5;
    cout << "Rekursif Tidak Langsung: ";
    functionA(num);
    return 0;
}
```

#### B. Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/f417ca97-a58f-4f4c-9c4c-9e9d330979ea)

#### C. Interpretasi:

- #### Interpretasi program
Program di atas merupakan salah satu implementasi sederhana dari rekursif tidak langsung antara dua fungsi yaitu ```functionA``` dan ```functionB```. Untuk yang pertama program mendeklarasikan fungsi ```functionB```. Fungsi ini dideklarasikan di awal agar dapat dipanggil dalam ```functionA```. Setelah itu ```functionA``` didefinisikan. Pada ```funtionA``` menerima satu parameter bilangan bulat n.
Jika n lebih besar dari 0, fungsi mencetak nilai n diikuti dengan spasi ```cout << n << " "```, lalu memanggil ```functionB``` dengan nilai ```n - 1```. Lanjut mendefinisikan fungsi ```functionB```, sama seperti ```functionA```, ```functionB``` juga menerima satu parameter bilangan bulat n. Namun bedanya dengan ```functionA``` tadi, pada ```functionB``` jika n lebih besar dari 0, fungsi mencetak nilai n diikuti dengan spasi, lalu memanggil ```functionA``` dengan nilai ```n / 2```. Kemudian fungsi ```main()```. Pada fungsi ini variabel ```num``` dideklarasikan dan diinisialisasi dengan nilai ```5```. Kemudian program mencetak pesan "Rekursif Tidak Langsung: ". Setelah itu program memanggil ```functionA``` dengan argumen 5 ```functionA(num)```. Dan terakhir, fungsi mengembalikan nilai 0 ```return 0``` yang menandakan bahwa program telah selesai.

- #### Interpretasi output
Program ini memanggil ```functionA(5)``` sesuai dengan perintah yang terdapat pada fungsi ```main()```, sehingga didapatkan hasil output "Rekursif Tidak Langsung: 5 4 2 1". Langkah detailnya seperti ini:
1. ```functionA(5)``` mencetak ```5``` dan memanggil ```functionB(n-1)``` = ```functionB(5-1)``` = ```functionB(4)```.

2. ```functionB(4)``` mencetak ```4``` dan memanggil ```functionA(n/2)``` = ```functionA(4/2)``` = ```functionA(2)```.

3. ```functionA(2)``` mencetak ```2``` dan memanggil ```functionB(n-1)``` = ```functionB(2-1)``` = ```functionB(1)```.

4. ```functionB(1)``` mencetak ```1``` dan memanggil ```functionA(n-1)``` = ```functionA(1-1)``` = ```functionA(0)```.

5. ```functionA(0)``` tidak mencetak apapun karena kondisi ```n > 0``` tidak terpenuhi, sehingga rekursif berhenti.

## Tugas Praktikum
### Unguided

### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!
### Jawab:
#### A. Program:

```C++
#include <iostream>

using namespace std;

// Fungsi rekursif untuk menghitung faktorial
int faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * faktorial(n - 1);
}

int main() {
    int n;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;
    cout << "Faktorial dari " << n << " adalah: " << faktorial(n) << endl;
    return 0;
}
```

#### B. Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/fddbbb3b-7d71-4a06-b278-d9c981a1849f)

#### C. Interpretasi: 
- #### Interpretasi program
Program di atas adalah sebuah program rekursif langsung untuk menghitung faktorial dari sebuah inputan bilangan bulat positif. Disini fungsi ```faktorial``` menerima sebuah integer n ```faktorial(int n)``` dan memanggil dirinya sendiri secara langsung untuk menghitung faktorial dari n tersebut. Ketika n adalah 0 atau 1, fungsi akan mengembalikan 1 karena faktorial dari 0 dan 1 adalah 1, dan disinilah basis rekursif terjadi. Cara kerja atau perhitungan faktorial dari program ini adalah jika n lebih besar dari 1 maka fungsi memanggil dirinya sendiri dengan argumen ```n - 1``` dan mengalikan hasilnya dengan ```n``` ```(return n * faktorial(n - 1))```. Selanjutnya fungsi ```main()```, pada fungsi ini kita diminta untuk memasukkan atau menginputkan sebuah bilangan bulat positif. Setelah itu program membaca bilangan yang kita masukkan tadi ke dalam variabel n. Baru kemudian program memanggil fungsi faktorial dengan argumen n dan hasil dicetak. 

- #### Interpretasi output
Dapat kita ketahui pada output bahwa saya memasukkan bilangan bulat positif 7 untuk dihitung berapa faktorialnya. Cara kerja program ini yaitu program menghitung faktorial dengan memanggil fungsi faktorial secara rekursif sampai mencapai basis rekursif. Jika sudah mencapai basis rekursif program mengembalikan hasil perhitungan dari basis rekursi ke panggilan rekursif sebelumnya sampai hasil akhir diperoleh dan dicetak. Detailnya seperti ini:
- faktorial(7) memanggil faktorial(6)
- faktorial(6) memanggil faktorial(5)
- faktorial(5) memanggil faktorial(4)
- faktorial(4) memanggil faktorial(3)
- faktorial(3) memanggil faktorial(2)
- faktorial(2) memanggil faktorial(1)
- faktorial(1) memengembalikan 1 (karena 1 sehingga basis rekursif tercapai)

Perhitungan Faktorial:

- faktorial(2) = ```2 * faktorial(1)``` = 2 * 1 = 2

faktorial(2) memanggil faktorial(1) yang mengembalikan 1

- faktorial(3) = ```3 * faktorial(2)``` = 3 * 2 = 6

faktorial(3) memanggil faktorial(2) yang mengembalikan 2

- faktorial(4) = ```4 * faktorial(3)``` = 4 * 6 = 24

faktorial(4) memanggil faktorial(3) yang mengembalikan 6

- faktorial(5) = ```5 * faktorial(4)``` = 5 * 24 = 120

faktorial(5) memanggil faktorial(4) yang mengembalikan 24

- faktorial(6) = ```6 * faktorial(5)``` = 6 * 120 = 720

faktorial(6) memanggil faktorial(5) yang mengembalikan 120

- faktorial(7) = ```7 * faktorial(6)``` = 7 * 720 = 5040

faktorial(7) memanggil faktorial(6) yang mengembalikan 720

### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 diatas!
### Jawab:
#### A. Program:

```C++
#include <iostream>

using namespace std;

int faktorial_helper(int n);

int faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * faktorial_helper(n - 1);
}

int faktorial_helper(int n) {
    return faktorial(n);
}

int main() {
    int n;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;
    cout << "Faktorial dari " << n << " adalah: " << faktorial(n) << endl;
    return 0;
}
```

#### B. Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/05487a9f-f3ca-40cf-b240-6108feb9ecf1)

#### C. Interpretasi: 
- #### Interpretasi program
Pada program Rekursif Tidak Langsung (Indirect Recursion), kita akan membuat dua fungsi yang saling memanggil untuk menghitung faktorial, yaitu fungsi ```faktorial``` dan ```faktorial_helper```. Untuk yang pertama program mendeklarasikan fungsi ```faktorial_helper```. Fungsi ini dideklarasikan di awal agar dapat dipanggil dalam ```faktorial```. Selanjutnya fungsi ```faktorial```. Fungsi ini menerima sebuah integer n dan mengembalikan nilai faktorial dari n. Sama seperti tadi, ketika n adalah 0 atau 1, fungsi mengembalikan 1 karena faktorial dari 0 dan 1 adalah 1, dan disinilah basis rekursif terjadi. Kemudian jika n lebih besar dari 1, fungsi memanggil fungsi ```faktorial_helper``` dengan argumen n - 1 dan mengalikan hasilnya dengan n ```n * faktorial_helper(n-1)```. Selanjutnya fungsi ```faktorial_helper```. Fungsi ini memanggil kembali fungsi faktorial dengan argumen n ```faktorial(n)```. Karena ```faktorial``` memanggil ```faktorial_helper``` dan ```faktorial_helper``` memanggil ```faktorial```, sehingga menciptakan rekursif tidak langsung.
Kemudian fungsi ```main()```. Sama seperti program rekursif langsung tadi, pada fungsi ini kita diminta untuk memasukkan sebuah bilangan bulat positif. Lalu program membaca bilangan yang telah kita masukkan ke dalam variabel n, dan terakhir program memanggil fungsi faktorial dengan argumen n dan mencetak hasilnya.

- #### Interpretasi output
Sama seperti tadi, disini saya juga memasukkan bilangan bulat positif 7 untuk dihitung berapa faktorialnya. Cara kerja pada program rekursif tidak langsung ini adalah menghitung faktorial dengan cara fungsi ```faktorial``` memanggil ```faktorial_helper```, yang pada gilirannya memanggil kembali faktorial, menciptakan rekursif tidak langsung. Detail prosesnya seperti ini:

- ```faktorial(7)``` memanggil ```faktorial_helper(6)```
- ```faktorial_helper(6)``` memanggil ```faktorial(6)```
- ```faktorial(6)``` memanggil ```faktorial_helper(5)```
- ```faktorial_helper(5)``` memanggil ```faktorial(5)```
- ```faktorial(5)``` memanggil ```faktorial_helper(4)```
- ```faktorial_helper(4)``` memanggil ```faktorial(4)```
- ```faktorial(4)``` memanggil ```faktorial_helper(3)```
- ```faktorial_helper(3)``` memanggil ```faktorial(3)```
- ```faktorial(3)``` memanggil ```faktorial_helper(2)```
- ```faktorial_helper(2)``` memanggil ```faktorial(2)```
- ```faktorial(2)``` memanggil ```faktorial_helper(1)```
- ```faktorial_helper(1)``` memanggil ```faktorial(1)```
- ```faktorial(1)``` mengembalikan 1 (karena n = 1 sehingga basis rekursi tercapai)

Perhitungan Faktorial:

- faktorial(2) = ```2 * faktorial_helper(1)``` = 2 * 1 = 2

faktorial_helper(1) memanggil faktorial(1) yang mengembalikan 1
- faktorial(3) = ```3 * faktorial_helper(2)``` = 3 * 2 = 6

faktorial_helper(2) memanggil faktorial(2) yang mengembalikan 2

- faktorial(4) = ```4 * faktorial_helper(3)``` = 4 * 6 = 24

faktorial_helper(3) memanggil faktorial(3) yang mengembalikan 6

- faktorial(5) = ```5 * faktorial_helper(4)``` = 5 * 24 = 120

faktorial_helper(4) memanggil faktorial(4) yang mengembalikan 24

- faktorial(6) = ```6 * faktorial_helper(5)``` = 6 * 120 = 720

faktorial_helper(5) memanggil faktorial(5) yang mengembalikan 120

- faktorial(7) = ```7 * faktorial_helper(6)``` = 7 * 720 = 5040

faktorial_helper(6) memanggil faktorial(6) yang mengembalikan 720

## Kesimpulan
Rekursif merupakan suatu konsep algoritma yang bekerja dengan cara memanggil dirinya sendiri. Pada praktikum ini terdapat dua jenis rekursif, yaitu rekursif langsung dan rekursif tidak langsung. Karena rekursif bekerja dengan cara memanggil dirinya sendiri, sehingga rekursif memiliki beberapa kelebihan dan kekurangan. Kemudian salah satu implementasi dari program rekursif yaitu untuk menghitung nilai faktorial dari suatu bilangan bulat positif. Dengan menggunakan algoritma rekursif, membuat saya lebih mudah dalam mengimplementasikan pada program C++ karena kode program yang relatif pendek.

## Referensi
[1] Dr.P.H. Gunawan, Logika Matematika untuk Analisis Algoritma, Yogyakarta: Penerbit Andi, 2022.

[2] I. Irmawati, dkk, Buku Ajar Pemrograman, Jambi: PT. Sonpedia Publishing Indonesia, 2023.

[3] I.K.S. Buana, H. Setiawan, P.A.W. Putro, Pemrograman terstruktur, Aceh: Syiah Kuala Universitiy Press, 2021.

[4] H. Ela, Analisis Algoritma Rekursif Subtitusi, 2011.
