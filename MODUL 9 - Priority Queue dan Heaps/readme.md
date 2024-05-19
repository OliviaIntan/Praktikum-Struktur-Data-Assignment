# <h1 align="center">Laporan Praktikum Modul Priority Queue dan Heaps</h1>
<p align="center">Nama: Olivia Intan Puspita</p>
<p align="center">NIM: 2311110006</p>
<p align="center">Kelas: S1SD-04-A</p>

## Dasar Teori

Di dalam ilmu komputer, priority queue adalah tipe data abstrak seperti struktur data queue, akan tetapi setiap elemen mempunyai "prioritas" yang masing-masing telah ditetapkan. Pada priority queue,  elemen  dengan  prioritas  lebih  tinggi  disajikan  sebelum  elemen  dengan  prioritas  lebih  rendah. Pada beberapa implementasi, ketika dua elemen memiliki prioritas yang sama, maka mereka dilayani sesuai  dengan  urutan  di  mana  mereka  masuk,  akan tetapi  dalam  implementasi  lainnya,  penempatan elemen dengan prioritas yang sama tidak di izinkan [1]. 

Priority Queue berdasarkan aturan elemen yang prioritasnya lebih tinggi, diproses lebih dahulu dibandingkan dengan elemen yang prioritasnya lebih rendah dan dua elemen dengan prioritas yang sama, diproses sesuai dengan urutan mereka sewaktu dimasukkan ke dalam priority queue [3]. Priority queue memiliki kompleksitas waktu proses insert Ο(1) dan proses delete Ο(log n) [2].

Priority queue dapat diimplementasikan menggunakan struktur data berikut: 
- Array
- Linked List
- Heap data strcture
- Binary search tree

Heap merupakan struktur data yang memenuhi kriteria heap (yaitu nilai parent harus selalu lebih besar dari nilai anak, max heap). Terdapat juga min heap yaitu nilai parent harus selalu lebih kecil dari nilai anak. Heap dapat digunakan untuk berbagai algoritma seperti untuk mengimplementasikan priority queue atau untuk melakukan sorting [4].

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/01215444-1fd8-4ffc-b51f-e7daf199690d)

HeapSort adalah struktur data yang berbentuk pohon yang memenuhi sifat-sifat heap yaitu jika B adalah anak dari A,maka nilai yang tersimpan di simpul A lebih besar atau sama dengan nilai yang tersimpan di simpul B. Hal ini mengakibatkan elemen dengan nilai terbesar selalu berada pada posisi akar, dan heap ini disebut max heap (bila perbandingannya diterbalikkan, yaitu elemen terkecilnya selalu berada di simpul akar, heap ini disebut min heap). Karena itulah, heap biasa dipakai untuk mengimplementasikan priority queue [5].

Berikut adalah operasi yang terdapat dalam heap:
- insert: Menyisipkan elemen baru
- ekstrakMax: Mengekstrak elemen dengan prioritas maksimum
- remove: Menghapus elemen 
- getMax: Mengembalikan elemen dengan prioritas maksimum.
- changePriority: Mengubah prioritas elemen 

Contoh implementasi priority queue dalam heap:

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/1fb3103d-9403-4a23-aca7-3cbf2478f599)

## Langkah Praktikum

### Guided 
#### A. Program:

```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i =parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize -1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " " ;
    }
    std::cout << "\n";

    std:: cout << "Node with maximum priority :" << extractMax() << "\n";

    std::cout << "Priority queue after extracting maximum : ";
    for (int i = 0;i <= heapSize; ++ i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
```

#### B. Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/3a07691f-ca25-4c42-b1e6-9a9ce2f0800e)

#### C. Interpretasi:

- #### Interpretasi program

Program di atas merupakan implementasi sebuah Priority Queue dan Heap yang menggunakan array. Pada program di atas heap yang digunakan adalah Max-Heap. 

Untuk yang pertama dapat kita ketahui bahwa program di atas menggunakan Array ```H[50]``` yang berarti ukuran maksimal elemen heap adalah 50. Kemudian terdapat variabel ```heapSize``` yang digunakan untuk menyimpan jumlah elemen dalam heap. -1 pada variabel ini digunakan untuk menunjukkan heap kosong. 

Selanjutnya terdapat beberapa fungsi pada program di atas. Untuk yang pertama adalah fungsi yang digunakan untuk mengetahui indeks orang tua dan anak. ```int parent(int i)``` untuk mengembalikan indeks orang tua dari elemen pada indeks i, ```int leftChild(int i)``` untuk mengembalikan indeks anak kiri, dan ```int rightChild(int i)``` untuk mengembalikan indeks anak kanan. Lalu yang kedua adalah fungsi yang digunakan untuk memperbaiki heap. ```void shiftUp(int i)``` untuk mengembalikan elemen pada indeks i ke atas hingga property heap terpenuhi (yaitu orang tua selalu lebih besar dari anak), dan ```void shiftDown(int i)``` digunakan untuk menurunkan elemen. Kemudian yang ketiga ada fungsi yang digunakan untuk mengelola heap. ```void insert(int p)``` untuk menambahkan elemen p ke dalam heap, ```int extractMax()``` untuk mengambil dan menghapus elemen terbesar dari heap, ```void changePriority(int i, int p)``` untuk mengubah prioritas elemen pada indeks i ke nilai p dan menyesuaikan posisi elemen tersebut, ```int getMax()``` untuk mengembalikan elemen terbesar di heap tanpa menghapusnya, dan ```void remove(int i)``` untuk menghapus elemen dari heap. Cara kerjanya elemen yang akan dihapus akan dengan dijadikan elemen terbesar terlebih dahulu, lalu setelah menjadi nilai maks maka akan dilakukan ekstrak maks atau pengambilan nilai maksimum, dan setelah itu elemen yang dipilih tadi berhasil dihapus. Lalu yang keempat dan terakhir yaitu fungsi ```main()```. Dari fungsi main dapat kita lihat fungsi utama program di atas. Pada program di atas kita menambahkan elemen ke dalam heap, setelah itu mencetak heap, mengambil elemen terbesar, mencetak heap kembali, kemudian mengubah prioritas, dan terakhir menghapus elemen.

- #### Interpretasi output

Output yang keluar pada gambar di atas sesuai dengan perintah yang kita buat pada fungsi main. Dimana dapat kita ketahui bahwa: 
1. Output pertama

```Priority Queue : 45 31 14 13 20 7 11 12 7```

 Ini kita dapat dari memasukkan elemen ke dalam heap dengan urutan 45, 20, 14, 12, 31, 7, 11, 13, 7, di mana setiap elemen induk lebih besar atau sama dengan elemen anak-anaknya. 
 
 2. Output kedua
 
 ```Node with maximum priority:45```
 
Disini elemen terbesar (45) diambil. 

3. Output ketiga

```Priority queue after extracting maximum: 31 20 14 13 7 7 11 12```

Setelah 45 diambil, heap disusun kembali. Kemudian elemen terakhir (7) dipindahkan ke posisi root dan kemudian dilakukan ```shiftDown``` untuk mempertahankan properti heap. 

4. Output keempat

```Priority queue after priority change: 49 20 31 13 7 7 11 12```

Disini kita melakukan perubahan pada indeks ke-2 yaitu 14 yang diubah menjadi 49. Kemudian karena 49 lebih besar dari sebelumnya, sehingga dipindahkan ke atas. 

5. Output kelima

```Priority queue after removing the element: 49 20 31 12 7 7 11```

Disini dilakukan penghapusan pada indeks ke-3 yaitu 13 dengan cara mengganti denga nilai yang lebih besar dari nilai terbesar, baru setelah itu elemen dihapus. 

## Tugas Praktikum
### Unguided 

### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user.
### Jawab:
#### A. Program:

```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

void printHeap() {
    std::cout << "Heap: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int choice, value, index;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Extract Max\n";
        std::cout << "3. Get Max\n";
        std::cout << "4. Change Priority\n";
        std::cout << "5. Remove\n";
        std::cout << "6. Print Heap\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter value to insert: ";
                std::cin >> value;
                insert(value);
                break;
            case 2:
                std::cout << "Extracted max: " << extractMax() << "\n";
                break;
            case 3:
                std::cout << "Max value: " << getMax() << "\n";
                break;
            case 4:
                std::cout << "Enter index and new priority: ";
                std::cin >> index >> value;
                changePriority(index, value);
                break;
            case 5:
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                remove(index);
                break;
            case 6:
                printHeap();
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice, try again.\n";
        }
    } while (choice != 0);

    return 0;
}
```

#### B. Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/1dcfa100-ae58-498f-811b-756ec37fba33)

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/aa491983-b116-4b20-965a-01d0a96800b3)

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/d75f9d34-db0e-46ac-9aa1-20f0f652184f)

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/a582c6b9-283b-4bad-9335-0d19ddbd4ae0)

#### C. Interpretasi: 
- #### Interpretasi program
Program di atas adalah bentuk modifikasi dari guided yang mana heap dikonstruksi secara manual berdasarkan input user. Pada program modifikasi ini juga diberi fungsi untuk mencetak menu interaktif dengan tujuan agar tampilan lebih cantik dan juga terstruktur sehingga kita dapat dengan mudah melakukan operasi yang kita inginkan. 

Terdapat 6 menu yang dapat kita pilih pada program di atas. Menu pertama yaitu ```Insert``` atau yang bisa disebut operasi tambah. Pada menu pertama ini kita memasukkan nilai yang ingin kita tambahkan ke dalam heap. Kemudian menu yang kedua adalah ```Extract Max``` atau yang bisa disebut operasi ambil maksimum. Pada menu ini kita mengambil dan menghapus elemen terbesar (root) dari heap. Menu yang ketiga adalah ```Get Max``` atau yang bisa disebut operasi dapat maksimum. Pada menu ini kita melihat elemen terbesar tanpa menghapusnya dari heap. Menu yang keempat adalah ```Change Priority``` atau yang bisa disebut operasi ubah prioritas. Pada menu ini kita memperbarui nilai elemen pada indeks yang kita inginkan. Menu yang kelima adalah ```Remove``` atau yang bisa disebut operasi hapus. Sesuai namanya, pada menu ini kita menghapus elemen pada indeks yang kita inginkan. Menu yang keenam adalah ```Print Heap```. Jika kita ingin melihat semua elemen di heap maka kita memilih menu ini. Dan yang terakhir, apabila kita ingin keluar dari program maka kita pilih menu 0 yaitu ```Exit```.

- #### Interpretasi output

1. Menu 1: Memasukkan elemen ```17``` ke heap

2. Menu 1: Memasukkan elemen ```29``` ke heap

3. Menu 1: Memasukkan elemen ```35``` ke heap

4. Menu 1: Memasukkan elemen ```5``` ke heap

5. Menu 1: Memasukkan ```41``` ke heap

6. Menu 6: Mencetak heap saat ini ```41, 35, 29, 5, 17```

7. Menu 2: Mengambil nilai maksimum yaitu ```45```

8. Menu 3: Mendapatkan nilai maksimum yaitu ```35```

9. Menu 4: Mengubah elemen pada indeks 1 yaitu ```17``` menjadi ```23```

10. Menu 6: Mencetak heap saat ini ```35, 23, 29, 5```

11. Menu 5: Menghapus elemen pada indeks 2 yaitu ```29```

12. Menu 6: Mencetak heap saat ini ```35, 23, 5```

13. Menu 0: Keluar dari program


## Kesimpulan

Priority queue adalah jenis queue yang dimana setiap elemen memiliki prioritas tertentu. Cara kerja priority queue yaitu dengan memproses elemen dengan prioritas lebih tinggi dulu, baru setelah itu memproses elemen dengan prioritas lebih rendah. Salah satu contoh implementasi dari priority queue adalah heap. Heap menjadi salah satu implementasi dalam priority queue karena keefisiensinya, sehingga menjadikan heap paling umum digunakan. 

Heap disebut juga struktur data yang berbentuk pohon karena elemen terbesar selalu berada di akar. Jenis heap sendiri ada dua, yaitu: Max-Heap dan Min-Heap. Sesuai namanya, yaitu max atau maksimal, maka konsep max-heap ini elemen induk selalu lebih besar atau sama dengan elemen anaknya.Sedangkan min atau minimal, maka konsep min-heap ini elemen induk selalu lebih kecil atau sama dengan elemen anaknya.
Terdapat beberapa operasi utama dalam heap, yaitu sebagai berikut.
- Insert: Menambahkan elemen ke dalam heap
- Extract Max: Menghapus elemen terbesar dan menyesuaikan heap
- Get Max: Mengembalikan elemen terbesar dalam heap tanpa menghapusnya
- Change priority: Mengubah elemen atau memperbarui heap
- Remove: Menghapus elemen tertentu dari heap

## Referensi
[1] I. Sholeh, Penerapan Decrease and Conquer untuk Manajemen Tugas Kuliah Informatika, Jurnal Teknik Informatika dan Sistem Informasi, vol. 1, no. 2, pp. 4, Desember 2021.

[2] I.G.N.L. Wijayakusuma, S.C. Yowani, Penanggulangan Kasus DPT Ganda dengan Menggunakan Algoritma Quiksort dan Priority Queue, Jurnal Matematika, vol. 9, no. 2, pp. 102, Desember 2019.

[3] J.A.Aryadi, dkk., Implementasi Algoritma Queue untuk Menentukan Prioritas Pelayanan Umum di Rumah Sakit", Jurnal Informatika dan Komputer, vol. 7, no.2, hal. 219, September 2023.

[4] K. Prayogo, Algoritma dan Struktur Data menggunakan Golang, Bonus: Intro Pemrograman Web. Indonesia: Kiswono Prayogo, 2014.

[5] F.L.Tobing, F.A. Twince Tobing, J.Peranginangin, Implementasi Algoritma Heapsort dalam Game Pembelajaran Algoritma Sorting, vol. 3, no. 2, hal. 332, Oktober 2022.
