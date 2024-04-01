# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Olivia Intan Puspita</p>

## Dasar Teori
Sorting atau pengurutan adalah proses menyusun elemen–elemen dari masukan awal acak menjadi keluaran akhir tertata dengan urutan tertentu. Kegiatan pengurutan data dapat ditemukan pada berbagai masalah dan  aplikasi. Misalkan pada kegiatan  mengurutkan nomor pasien pada sebuah  klinik [1]. Contoh penerapannya antara lain berupa rincian transaksi sesuai urutan tanggal dan jam pada  perbankan, daftar hadir yang diurutkan berdasarkan nomor induk dan daftar  pustaka yang diurutkan sesuai abjad pengarang ataupun katalog buku di  perpustakaan [3].

Ada banyak metode sorting, namun pada praktikum kali ini hanya akan dibahas 3 metode sorting atau pengurutan, yaitu Insertion sort, Bubble sort, dan Selection sort.

1. Insertion Sort

Insertion sort merupakan algoritma yang relatif lambat atau boros space, karena harus melakukan penggeseran sejumlah data (apabila menggunakan array), atau menggunakan linked list (list insertion sort). Cara kerja algoritma ini adalah mencari posisi yang tepat (linear search) dari data baru yang ingin dimasukkan [2].

2. Bubble Sort

Algoritma bubble sort adalah salah satu algoritma pengurutan yang paling simple, baik dalam hal pengertian maupun penerapannya. Ide dari algoritma ini adalah mengulang proses pembandingan antara  tiap-tiap  elemen array dan menukarnya apabila urutannya salah. Pembandingan elemen-elemen ini akan terus diulang hingga tidak perlu dilakukan penukaran lagi [1].

3. Selection Sort

Selection sort merupakan algoritma yang relatif cepat dibandingkan bubble sort, karena jumlah penukaran yang lebih sedikit. Cara kerja algoritma ini adalah mencari nilai terkecil/terbesar lalu menukar dengan posisi awal dari depa. Wprst case untuk algoritma ini adalah O(n^2) [2].

Beberapa  macam  algoritma  sorting  telah dibuat  karena  proses  tersebut  sangat  mendasar dan    sering    digunakan.    Oleh    karena    itu, pemahaman  atas  algoritma –algoritma  yang ada  sangatlah  berguna.  Selain  menjadi  suatu aplikasi  yang  berdiri  sendiri,  pengurutan  juga biasanya  menjadi  suatu  bagian  dari  algoritma yang lebih besar [3].

## Guided 

### 1. Guided 1: Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort

#### Program:
```C++
#include <iostream>

using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++){
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of if
        }//end of for loop
    }//end of while loop
}//end of bubble_sort

void print_array(double a[], int length) {
    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {

    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99.99};

    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
```
#### Interpretasi:
Program di atas merupakan program untuk mengurutkan sebuah array dari bilangan bertipe double yaitu bilangan desimal secara ascending menggunakan Algoritma Bubble Sort.

Berikut adalah penjelasan dari program di atas:

Untuk yang pertama yaitu fungsi bubble_sort yang merupakan fungsi untuk melakukan pengurutan array dari bilangan desimal. Fungsi ini menerima parameter sebuah array dari bilangan desimal (arr) dan panjang array (length). Algoritma Bubble Sort memiliki kompleksitas waktu rata-rata O(n^2), di mana n adalah jumlah elemen dalam array. Di dalam fungsi ini, terdapat dua loop bersarang. Loop pertama memiliki kompleksitas O(n) karena ia melakukan iterasi sebanyak n kali, di mana n adalah panjang array.
Di dalam loop pertama, terdapat loop kedua yang juga memiliki kompleksitas O(n), karena ia melakukan iterasi sebanyak (n - j) kali di setiap iterasi loop pertama, di mana j adalah jumlah iterasi yang telah dilakukan.
Jumlah total operasi dalam fungsi ini sekitar n^2. Fungsi ini hanya menggunakan ruang tambahan konstan. Oleh karena itu, kompleksitas ruangnya adalah O(1).

Selanjutnya Variabel boolean not_sorted diinisialisasi dengan nilai true untuk menunjukkan bahwa array belum diurutkan. Variabel not_sorted membutuhkan ruang konstan yang tidak bergantung pada ukuran array.

Di dalam sebuah loop while, program akan terus menjalankan langkah-langkah pengurutan selama array masih belum terurut. Pada awal setiap iterasi loop while, not_sorted diatur menjadi false, ini mengasumsikan bahwa array sudah terurut, kecuali jika ditemukan pasangan elemen yang belum terurut. Pada program juga terdapat sebuah loop for di dalamnya yang berfungsi untuk mengiterasi seluruh elemen array. Jika sebuah elemen lebih besar dari elemen yang berada di sebelah kanannya, maka keduanya akan ditukar posisinya, dan not_sorted diatur menjadi true untuk menandakan bahwa array masih belum terurut.

Kemudian Fungsi print_array digunakan untuk mencetak semua elemen array yang diberikan kepadanya. Fungsi ini memiliki kompleksitas waktu O(n), di mana n adalah jumlah elemen dalam array. Ini karena fungsi melakukan iterasi melalui setiap elemen dalam array dan mencetaknya. Fungsi ini juga memiliki kompleksitas ruang O(1) karena hanya menggunakan ruang tambahan konstan.

Selanjutnya ada fungsi main. Di dalam fungsi main ini sebuah array a dari bilangan pecahan didefinisikan dengan nilai-nilai awal. Array yang belum diurutkan dicetak menggunakan fungsi print_array. Fungsi bubble_sort dipanggil untuk mengurutkan array tersebut. Dan yang terakhir, array yang sudah diurutkan dicetak kembali menggunakan fungsi print_array. Total kompleksitas waktu untuk fungsi main adalah O(n^2) karena dominan oleh panggilan fungsi bubble_sort. Fungsi main juga menggunakan ruang tambahan konstan. Oleh karena itu, kompleksitas ruangnya juga adalah O(1).


#### Output:
<img width="222" alt="Screenshot 2024-03-29 164948" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/e6343731-3f66-4509-961c-78e401d4ba28">

Dari output dapat diketahui bahwa bilangan desimal yang semula tidak urut yaitu 22.1, 15.3, 8.2, 33.21, 99.99 oleh program berhasil diurutkan menjadi 8.2, 15.3, 22.1, 33.21, 99.99. Artinya, bilangan desimal di atas melakukan pengurutan secara ascending, yaitu pengurutan dari terkecil ke terbesar.


#### Full code Screenshot:
<img width="960" alt="Screenshot 2024-03-29 165203" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/a4020d6c-7f27-4561-bba5-5b5f2dfb7b6c">

Program ini menunjukkan bagaimana bubble sort dapat digunakan untuk mengurutkan array dari bilangan double yaitu bilangan desimal. Kompleksitas waktu program secara keseluruhan didominasi oleh kompleksitas waktu dari algoritma Bubble Sort di dalam fungsi bubble_sort. Kompleksitas ruang program keseluruhan sangat kecil dan tetap konstan karena hanya menggunakan ruang tambahan konstan untuk variabel-variabel sementara. Meskipun algoritma Bubble Sort sederhana, kompleksitas waktu yang tinggi membuatnya tidak efisien untuk penggunaan pada array yang besar.


### 2. Guided 2: Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort

#### Program:
```C++
#include <iostream>

using namespace std;

void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;

    for (i = 1; i < length; i++) {
        j = i;

        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }//end of while loop
    }//end of for loop
}

void print_array(char a[], int length) {

    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
}
```
#### Interpretasi:
Program di atas merupakan program untuk mengurutkan mengurutkan sebuah array dari karakter secara descending menggunakan Algoritma insertion sort.

Berikut adalah penjelasan dari program di atas:

Untuk yang pertama adalah Fungsi insertion_sort yang digunakan untuk melakukan pengurutan array dari karakter. Fungsi ini menerima parameter sebuah array dari karakter (arr) dan panjang array (length). Algoritma Insertion Sort memiliki kompleksitas waktu rata-rata O(n^2) dalam kasus terburuk, di mana n adalah jumlah elemen dalam array. Pada setiap iterasi, algoritma memindahkan elemen-elemen yang lebih besar ke posisi yang lebih awal dalam array.
Dalam fungsi insertion sort, terdapat loop for yang berjalan sebanyak n kali, dan di dalamnya, terdapat loop while yang dalam kasus terburuk dapat berjalan sebanyak i kali, di mana i adalah indeks dalam array. Jumlah total operasi dalam fungsi ini dapat mencapai sekitar n^2. Fungsi ini hanya menggunakan ruang tambahan konstan. Oleh karena itu, kompleksitas ruangnya adalah O(1).

Selanjutnya loop for. Di dalam loop for setiap elemen dari array dimulai dari indeks kedua (indeks 1) hingga akhir array diperiksa. Setiap elemen dipindahkan ke posisi yang tepat di dalam array terurut yang ada di sebelah kiri elemen tersebut. Proses ini dilakukan dengan membandingkan elemen saat ini dengan elemen-elemen yang telah diurutkan sebelumnya.

Kemudian loop while. Di dalam loop while elemen yang sedang diproses dibandingkan dengan elemen-elemen di sebelah kirinya. Jika elemen yang sedang diproses lebih kecil daripada elemen di sebelah kirinya, maka kedua elemen tersebut ditukar posisinya. Proses pertukaran terus dilakukan sampai elemen yang sedang diproses sudah berada di posisi yang tepat di dalam array terurut.

Lalu ada Fungsi print_array. Fungsi ini digunakan untuk mencetak semua elemen array yang diberikan kepadanya. Fungsi ini memiliki kompleksitas waktu O(n), di mana n adalah jumlah elemen dalam array. Ini karena fungsi melakukan iterasi melalui setiap elemen dalam array dan mencetaknya. Fungsi ini juga memiliki kompleksitas ruang O(1) karena hanya menggunakan ruang tambahan konstan.

Dan yang terakhir fungsi main. Terdapat beberapa fungsi di dalam fungsi main, yaitu: Sebuah array 'a'dari karakter didefinisikan dengan nilai-nilai awal. Array yang belum diurutkan dicetak menggunakan fungsi print_array. Kemudian Fungsi insertion_sort dipanggil untuk mengurutkan array tersebut. Dan array yang sudah diurutkan dicetak kembali menggunakan fungsi print_array. Total kompleksitas waktu untuk fungsi main adalah O(n^2) karena dominan oleh panggilan fungsi insertion_sort. Fungsi main juga menggunakan ruang tambahan konstan. Oleh karena itu, kompleksitas ruangnya juga adalah O(1).


#### Output:
<img width="236" alt="Screenshot 2024-03-29 190620" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/e5f07015-7de1-46bb-94fc-0fc08a74dd58">

Dari output dapat diketahui bahwa karakter yang semula tidak urut yaitu c, f, a, z, d, p oleh program berhasil diurutkan menjadi z, p, f, d, c, a. Artinya, karakter di atas melakukan pengurutan secara descending, yaitu pengurutan dari terbesar ke terkecil


#### Full code Screenshot:
<img width="960" alt="Screenshot 2024-03-29 230322" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/4682d8d6-a8d6-42e8-b256-ac058ac1aa95">

Program ini menunjukkan bagaimana insertion sort dapat digunakan untuk mengurutkan array dari karakter. Kompleksitas waktu program secara keseluruhan didominasi oleh kompleksitas waktu dari algoritma Insertion Sort di dalam fungsi insertion_sort. Kompleksitas ruang program keseluruhan sangat kecil dan tetap konstan karena hanya menggunakan ruang tambahan konstan untuk variabel-variabel sementara. Algoritma Insertion Sort digunakan dalam implementasi ini untuk mengurutkan array karakter dalam urutan menurun (dari besar ke kecil).


## Unguided 

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort! 

#### Program:
```C++
#include <iostream>

using namespace std;

void selectionSort(double arr[], int n) {
    int i, j, maxIndex;
    double temp;
    
    for (i = 0; i < n - 1; i++) {
        maxIndex = i;
        
        // Cari indeks elemen maksimum dari sisa array yang belum diurutkan
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        
        // Tukar elemen maksimum dengan elemen pertama dari sisa array yang belum diurutkan
        temp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArrayWithCommas(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    const int numStudents = 5;
    double ips[numStudents] = {3.8, 2.9, 3.3, 4.0, 2.4};

    cout << "IPS sebelum diurutkan: ";
    printArrayWithCommas(ips, numStudents);

    selectionSort(ips, numStudents);

    cout << "IPS setelah diurutkan dari yang terbesar hingga terkecil: ";
    printArrayWithCommas(ips, numStudents);

    return 0;
}
```
#### Interpretasi:
Program di atas merupakan program untuk mengurutkan Indeks Prestasi Semester (IPS) dari mahasiswa S1 IF 2016 G dari yang terbesar hingga terkecil menggunakan algoritma Selection Sort. 

Berikut adalah penjelasan dari program di atas:

Pertama adalah fungsi SelectionSort. Fungsi ini digunakan untuk mengurutkan array nilai IPS menggunakan algoritma Selection Sort. Fungsi ini menerima array arr yang berisi nilai IPS dan n yang merupakan jumlah elemen dalam array. Pada fungsi SelectionSort, Iterasi dilakukan dari indeks 0 hingga n-2 (indeks terakhir sebelum array habis). Di setiap iterasi, dilakukan pencarian elemen terbesar di antara elemen-elemen yang belum diurutkan. Setelah elemen terbesar ditemukan, elemen tersebut ditukar dengan elemen pertama dari sisa array yang belum diurutkan.

Kedua fungsi printArrayWithCommas. Fungsi ini digunakan untuk mencetak semua elemen dalam array dengan menambahkan tanda koma setelah setiap nilai, kecuali untuk nilai terakhir.

Ketiga fungsi main. Fungsi ini berfungsi untuk mendefinisikan konstanta numStudents yang menyatakan jumlah mahasiswa, membuat array ips yang berisi nilai-nilai IPS mahasiswa, mencetak nilai IPS sebelum diurutkan, memanggil fungsi selectionSort untuk mengurutkan array ips, dan mencetak nilai IPS setelah diurutkan.

#### Output:
<img width="440" alt="Screenshot 2024-03-29 231028" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/d93d180c-69fa-4fda-ba62-c4b6448b3be3">

Dari output dapat diketahui bahwa IPS sebelum diurutkan adalah 3.8, 2.9, 3.3, 4, 2.4 oleh program berhasil diurutkan menjadi 4, 3.8, 3.3, 2.9, 2.4. Artinya, Indeks Prestasi Semester (IPS) di atas berhasil melakukan pengurutan secara descending, yaitu pengurutan dari terbesar ke terkecil. Dapat dilihat juga bahwa tiap angka dipisahkan dengan tanda koma agar lebih rapi.


#### Full code Screenshot:
<img width="960" alt="Screenshot 2024-03-29 230931" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/205fef22-9dc8-47f4-a8af-fbaa6358b2cb">

Dengan demikian, program ini berhasil menghasilkan output berupa nilai IPS setelah diurutkan dari yang terbesar hingga terkecil dengan menggunakan selestion sort yang setiap nilai dipisahkan oleh tanda koma. Algoritma Selection Sort adalah salah satu dari berbagai algoritma pengurutan yang sederhana dan mudah dipahami. Meskipun relatif mudah diimplementasikan dan memiliki kompleksitas waktu yang stabil, yaitu O(n^2), algoritma ini kurang efisien untuk jumlah elemen yang besar. Selection Sort cocok digunakan untuk jumlah elemen yang kecil atau untuk tujuan pendidikan guna memahami dasar-dasar algoritma pengurutan. 

### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan nama-nama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!

#### Program:

```C++
#include <iostream>
#include <string>

using namespace std;

void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Tukar elemen jika elemen saat ini lebih besar dari elemen berikutnya
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArrayWithCommas(string arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    const int numResidents = 10;
    string residents[numResidents] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

    cout << "Nama warga sebelum diurutkan: ";
    printArrayWithCommas(residents, numResidents);

    bubbleSort(residents, numResidents);

    cout << "Nama warga setelah diurutkan sesuai alfabet: ";
    printArrayWithCommas(residents, numResidents);

    return 0;
}
```

#### Interpretasi:
Program di atas adalah program untuk mengurutkan 10 nama warga pak RT sesuai dengan alfabet menggunakan algoritma Bubble Sort.

Berikut adalah interpretasi dari program di atas:

Pertama bubbleSort. Fungsi ini digunakan untuk mengurutkan array nama warga menggunakan algoritma Bubble Sort. Fungsi ini menerima array arr yang berisi nama-nama warga dan n yang merupakan jumlah elemen dalam array. Pada bubbleSort, Iterasi dilakukan dari indeks 0 hingga n-2 (indeks terakhir sebelum array habis). Di setiap iterasi, dilakukan pencarian elemen terkecil di antara elemen-elemen yang belum diurutkan. Setelah elemen terkecil ditemukan, elemen tersebut ditukar dengan elemen pertama dari sisa array yang belum diurutkan.

Kedua printArrayWithCommas. Fungsi ini digunakan untuk mencetak semua elemen dalam array dengan menambahkan tanda koma setelah setiap nilai, kecuali untuk nilai terakhir.

Ketiga Fungsi main. Fungsi ini berfungsi untuk mendefinisikan konstanta numResidents yang menyatakan jumlah warga, membuat array residents yang berisi nama-nama warga, mencetak nama-nama warga sebelum diurutkan, memanggil fungsi bubbleSort untuk mengurutkan array residents, dan mencetak nama-nama warga setelah diurutkan sesuai dengan alfabet.

#### Output:
<img width="562" alt="Screenshot 2024-03-30 000024" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/7c5cb7f1-5a74-4196-871f-2b139bc698ac">

Dari hasil output dapat diketahui bahwa 10 warga dengan nama sebelum diurutkan adalah: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dadi, oleh program berhasil diurutkan menjadi: ana, ani, caca, cici, dadi, dida, dodo, sana, siti, situ. Artinya, 10 nama warga di atas berhasil melakukan pengurutan sesuai dengan alfabet atau secara ascending yaitu pengurutan dari terkecil ke terbesar. Dapat dilihat juga bahwa setiap nama dipisahkan dengan tanda koma agar lebih rapi.

#### Full code Screenshot:
<img width="960" alt="Screenshot 2024-03-29 235806" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/62eb57d6-a591-4c08-a961-fb945adad69d">

Dengan demikian, program ini menghasilkan output berupa nama-nama warga sebelum diurutkan dan nama-nama warga setelah diurutkan sesuai dengan alfabet dengan menggunakan bubble sort yang setiap nama dipisahkan oleh tanda koma. Dalam kesimpulannya, algoritma Bubble Sort merupakan algoritma pengurutan sederhana yang bekerja dengan membandingkan pasangan elemen berturut-turut dalam array dan menukar mereka jika urutannya salah. Meskipun mudah dipahami dan diimplementasikan, Bubble Sort memiliki kompleksitas waktu O(n^2), yang membuatnya kurang efisien untuk array dengan jumlah elemen yang besar. Meskipun demikian, Bubble Sort masih relevan sebagai algoritma pengurutan yang dipelajari dalam konteks pendidikan karena memperkenalkan konsep dasar tentang cara kerja algoritma pengurutan.

### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)!

#### Program:
```C++
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah karakter (n): ";
    cin >> n;

    vector<char> characters(n);

    for (int i = 0; i < n; ++i) {
        cout << "Karakter ke-" << i + 1 << ": ";
        cin >> characters[i];
    }

    cout << "Urutan karakter sebelum sorting: " << endl;
    for (char character : characters) {
        cout << character << "\t";
    }
    cout << endl;

    // Sorting secara ascending
    sort(characters.begin(), characters.end());
    cout << "Urutan karakter setelah ascending sort: " << endl;
    for (char character : characters) {
        cout << character << "\t";
    }
    cout << endl;

    // Sorting secara descending
    sort(characters.rbegin(), characters.rend());
    cout << "Urutan karakter setelah descending sort: " << endl;
    for (char character : characters) {
        cout << character << "\t";
    }
    cout << endl;

    return 0;
}
```
#### Interpretasi:

Program di atas adalah program untuk memasukkan sejumlah karakter (n) dan kemudian meminta pengguna untuk memasukkan n karakter. Setelah itu, program melakukan pengurutan karakter tersebut secara menaik (ascending) dan menurun (descending). 

Berikut adalah interpretasi dari program tersebut:

Pertama Fungsi main(). Fungsi ini memiliki beberapa fungsi, diantaranya: Meminta pengguna untuk memasukkan jumlah karakter (n) melalui input, membuat vektor characters untuk menyimpan karakter-karakter yang dimasukkan pengguna, meminta pengguna memasukkan n karakter satu per satu menggunakan loop for. Setiap karakter dimasukkan ke dalam vektor characters, setelah pengguna selesai memasukkan karakter, program mencetak urutan karakter sebelum pengurutan. Fungsi ini melakukan pengurutan karakter secara ascending menggunakan fungsi sort() dari library <algorithm>. Setelah pengurutan selesai, program mencetak urutan karakter setelah pengurutan secara ascending. Kemudian untuk melakukan pengurutan karakter secara descending menggunakan fungsi sort() dengan membalikkan iterator menggunakan rbegin() dan rend() dari library <algorithm>. Setelah pengurutan selesai, program mencetak urutan karakter setelah pengurutan secara descending.

Kedua fungsi sort() dari Library <algorithm>. Fungsi ini memiliki 2 jenis yaitu Sorting Ascending: Menggunakan sort(characters.begin(), characters.end()) untuk mengurutkan elemen-elemen dari yang terkecil ke terbesar dalam vektor characters dari elemen pertama hingga elemen terakhir. Sorting Descending: Menggunakan sort(characters.rbegin(), characters.rend()) untuk mengurutkan elemen-elemen dari yang terbesaar ke terkecil dalam vektor characters dari elemen terakhir hingga elemen pertama.

Ketiga fungsi cin dan cout dari Library <iostream>. Fungsi cin dapat disebut juga input karena digunakan untuk meminta pengguna memasukkan nilai. Fungsi cout dapat disebut juga output karena digunakan untuk mencetak nilai.

Keempat fungsi vector dari Library <vector>. Fungsi ini membuat vektor dengan menggunakan vector<char> characters(n) untuk menyimpan karakter-karakter yang dimasukkan pengguna. Penambahan Elemennya menggunakan push_back() atau indeks untuk menambahkan karakter ke dalam vektor. Fungsi ini mengakses Elemen menggunakan indeks untuk mengakses elemen-elemen dalam vektor.

#### Output:
<img width="229" alt="Screenshot 2024-03-30 003626" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/3bd6179b-747c-47ba-b55b-75232ebe896b">

Dari output dapat kita ketahui bahwa jumlah karakter yang diinputkan adalah 5, yang terdiri dari: a, c, b, e, dan d. Setelah itu program mencetak 3 jenis pengurutan. Pertama, urutan karakter sebelum sorting yaitu masih sama. Kedua, urutan karakter setelah ascending sort atau urutan dari terkecil ke terbesar yaitu a, b, c, d, e. Ketiga, urutan karakter setelah discending sort atau urutan dari terbesar ke terkecil yaitu e, d, c, b, a.

#### Full code Screenshot:
<img width="960" alt="Screenshot 2024-03-30 003458" src="https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/a343f169-fb2c-4dee-a2db-8f14d9cd856f">

Dengan demikian, program tersebut berhasil menghasilkan output sorting ascending (terkecil ke terbesar), sorting descending (terbesar ke terkecil), serta berhasil meminta user menginputkan suatu bilangan n dan menginputkan sejumlah n karakter.

## Kesimpulan
Ringkasan dan interpretasi pandangan saya dari hasil praktikum dan pembelajaran yang didapat yaitu:
- Hasil Praktikum

Hasil dari praktikum ketiga ini, saya menjadi tahu mengenai konsep dasar sorting dan juga jenis-jenis sorting, yang mana pada praktikum ini membahas insertion sort, bubble sort, dan selection sort. Setiap jenis sorting memiliki karakteristik dan fungsi yang berbeda-beda. Kemudian sorting berdasarkan pengurutannya dibagi menjadi dua, yaitu ascending yang berarti pengurutan dari terkecil hingga terbesar, dan descending yang berarti pengurutan dari terbesar hingga terkecil.

- Pembelajaran yang didapat

Pada praktikum ini saya kembali mendapat pembelajaran yang banyak dan berarti. Saya bisa lebih mengerti dalam mengimplementasikan program sorting di bahasa pemrograman C++. Pembelajaran lain yang saya dapat yaitu mengenai kompleksitas waktu dan ruang di setiap kode pada algoritma sorting.

## Referensi
[1] D. Septyantoro, R.A. Hasibuan, "ANALISIS DAN PERBANDINGAN KOMPLEKSITAS ALGORITMA EXCHANGE SORT DAN INSERTION SORT UNTUK PENGURUTAN DATA MENGGUNAKAN PYTHON", TEKINFO. vol.21, no. 1, pp. 48-50, 1 April 2020.

[2] K. Prayogo. Algoritma dan Struktur Data menggunakan Golang, Bonus: Intro Pemrograman Web. Indonesia, 2014.

[3] A.H. Saptadi, D.W. Sari, "ANALISISALGORITMA INSERTION SORT, MERGE SORT DAN IMPLEMENTASINYA DALAM BAHASA PEMROGRAMAN C++", Jurnal Infote. vol. 4, no. 2, pp. 10, 2 November 2012. 