# <h1 align="center">Laporan Praktikum Modul Priority Graph dan Tree</h1>
<p align="center">Nama: Olivia Intan Puspita</p>
<p align="center">NIM: 2311110006</p>
<p align="center">Kelas: S1SD-04-A</p>

## Dasar Teori

### A. Graph
### Pengertian Graph
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/640b2698-a7fd-4153-ba7d-4cb64e72e294)

Graph adalah jenis struktur data yan terdiri dari berbagai node yang saling terhubung. Node pada jenis ini disebut sebagai simpul dimana akan ada garis yang menghubungkan dari setiap simpul tersebut [1].

Graph menggambarkan suatu kumpulan objek dimana pasangan dari objek tersebut terhubung oleh sebuah link. Objek yang saling terhubung tergambarkan oleh sebuah titik yang disebut sebagai verteks. Sedangkan link yang menghubungkan verteks disebut dengan edge [1].

### Jenis-jenis Graph
1. Directed graph: Garis yang terhubung ke semua simpul.
2. Undirected graph: Tidak semua simpul terhubung dengan garis [1].
3. Weighted graph: Graf berbobot dimana setiap busur mempunyai nilai.

### Kelebihan dan Kekurangan
Keunggulan graph yaitu dapat membantu untuk memeriksa hubungan antar node dengan cepat dan juga cocok digunakan untuk grafik yang tidak banyak mengandung node. Sementara kekuraangannya adalah perlu waktu yang lebih lama dalam hal memodifikasi data [1].

### B. Tree
### Pengertian Tree
Tree (pohon) merupakan salah satu jenis struktur data yang terdiri dari simpul-simpul (nodes) yang saling terhubung (edges) satu sama lain secara hierarkis. Nodes dalam implementadinya dapat merepresentasikan data, sementara edges adalah jalan atau lintasan yang menghubungkan santara nodes [2]. Pohon adalah bentuk khusus dari suatu graf yang banyak diterapkan untuk berbagai keperluan. Misalnya struktur organisasi suatu perusahaan, sislsilah suatu keluarga, skema sistem gugur suatu pertandingan, dan ikatan kimia suatu molekul [3].

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/4a79ba82-bbfd-4796-a862-2f5723d335cd)

Pada contoh di atas dapat diketahui bahwa A adalah akar (root). Akar A memiliki dua anak (child) yaitu B dan C. B memiliki dua daun (leaf) yaitu D dan E. Begitupun dengan F dan G merupakan daun dari C [2].

### Binary Tree atau Pohon Biner
Jika sebuah simpul pada pohon memiliki sebanyak-banyaknya dua anak, pohon tersebut dinamakan pohon biner. 

Dua anak dari tiap simpul pada pohon biner disebut dengan anak kiri dan anak kanan, seperti ditunjukkan pada gambar. Simpul pada pohon biner tidak harus memiliki dua anak; ia bisa hanya memiliki anak kiri saja, atau hanya anak kanan saja, atau simpul juga bisa tidak memiliki anak sama sekali (pada kasus itu, simpul disebut dengan daun) [4].

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/090f3231-5e58-4b4c-8047-d0ec16007ed0)

### Penjelajahan Pohon
Penjelajahan pohon berarti mengunjungi setiap simpul dalam urutan tertentu. Ada tiga cara dalam menjelajah sebuah pohon.
1. Metode inOrder

a. Memanggil dirinya untuk menjelajah subpohon kiri dari simpul

b. Mengunjungi simpul

c. Memanggil dirinya untuk menjelajah subpohon kanan dari simpul

2. Metode preOrder

a. Mengunjungi simpul

b. Memanggil dirinya untuk menjelajah subpohon kiri

c. Memanggil dirinya untuk menjelajah subpohon kanan

3. Metode postOrder

a. Memanggil dirinya untuk menjelajah subpohon kiri

b. Memanggil dirinya untuk menjelajah subpohon kanan

c. Mengunjungi simpul [4].

## Langkah Praktikum

### Guided 1: Program Graph
#### A. Program:

```C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0},
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")";
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```

#### B. Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/db447f9d-7d77-496a-b362-b73b7410228b)

#### C. Interpretasi:

- #### Interpretasi program
Program di atas merupakan implementasi dari graf. Untuk yang pertama kita mendeklarasikan array ```simpul``` terlebih dahulu. Dalam array ini berisi 7 nama-nama kota yang nantinya menjadi simpul dalam graf. Selanjutnya kita mendeklarasikan matriks ```busur```. Dalam matriks ini berisi jarak antar kota. Pada program di atas nilai pada busur dinyatakan ```busur[7][7]```. Kita misalkan nilai pada ```busur[i][j]```, jika nilai pada busur bukan nol maka berarti ada jalan dari kota ```simpul[i]``` ke kota ```simpul[j]``` dengan jarak yang sudah ditentukan oleh nilai di atas. Kemudian terdapat fungsi ```tampilGraph```. Sesuai namanya, fungsi ini digunakan untuk menampilkan graf agar mudah dibaca. Dia mencetak setiap kota yang terhubung beserta dengan jaraknya. Lalu yang terakhir fungsi ```main```. Fungsi utama ini melakukan pemanggilan ```tampilGraph``` untuk mencetak graf. 

- #### Interpretasi output
Dari output di atas kita dapat mengetahui jarak antar kota-kota:
1. Ciamis

```Bandung (7) Bekasi (8)```

Terhubung ke Bandung dengan jarak 7 dan ke Bekasi dengan jarak 8

2. Bandung

```Bekasi (5) Purwokerto (15)```

Terhubung ke Bekasi dengan jarak 5 dan ke Purwokerto dengan jarak 15

3. Bekasi

```Bandung (6) Cianjur (5)```

Terhubung ke Bandung dengan jarak 6 dan ke Cianjur dengan jarak 5

4. Tasikmalaya

```Bandung (5) Cianjur (2) Purwokerto (4)```

Terhubung ke Bandung dengan jarak 5, ke Cianjur dengan jarak 2, dan ke Purwokerto dengan jarak 4

5. Cianjur

```Ciamis (23) Tasikmalaya (10) Yogyakarta (8)```

Terhubung ke Ciamis dengan jarak 23, ke Tasikmalaya dengan jarak 10, dan ke Yogyakarta dengan jarak 8

6. Purwokerto

```Cianjur (7) Yogyakarta (3)```

Terhubung ke Cianjur dengan jarak 7 dan ke Yogyakarta dengan jarak 3

7. Yogyakarta

```Cianjur (9) Purwokerto (4)```

Terhubung ke Cianjur dengan jarak 9 dan ke Purwokerto dengan jarak 4

### Guided 2: Program Tree
#### A. Program:

```C++
#include <iostream>
using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

int main() {
    TNode *zero = new TNode(0);
    // 0
    // /\
    // NULL NULL

    TNode *one = new TNode(1);
    TNode *five = new TNode(5);
    TNode *seven = new TNode(7);
    TNode *eight = new TNode(8);
    TNode *nine = new TNode(9);

    seven->left = one;
    // 7
    // /\
    // 1 NULL

    seven->right = nine;
    // 7
    // /\
    // 1 9

    one->left = zero;
    // 7
    // /\
    // 1 9
    // /\
    // 0 NULL

    one->right = five;
    // 7
    // /\
    // 1 9
    // /\
    // / \ / \
    // 0 5 8 NULL

    nine->left = eight;
    // 7
    // /\
    // /\ /\
    // 0 5 8 NULL

    preOrder(seven);
    cout << endl;

    inOrder(seven);
    cout << endl;

    postOrder(seven);
    cout << endl;


    return 0;
}
```

#### B. Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/1cb64f60-6062-4fcf-bd86-60a255fe924b)

#### C. Interpretasi:

- #### Interpretasi program
Program di atas merupakan implementasi dari binary tree atau pohon biner. Dalam program di atas pertama terdapat struktur ```TNode``` yang merepresentasikan sebuah node dalam pohon biner. Setiap node memiliki ```data``` dan dua pointer yaitu ```left``` yang menunjuk ke anak kiri dan ```right``` yang menunjuk ke anak kanan. Kemudian konstruktor ```TNode(int value)``` untuk menginisialisasi data dan mengatur anak kiri dan kanan menjadi ```NULL```. Selanjutnya melakukan traversal atau penjelajahan yang dimana ada tiga metode. Pertama ```preOrder```, dalam preOrder ini node sekarang dicetak terlebih dahulu kemudian dilakukan penjelajahan ke subpohon kiri dan subpohon kanan. Kedua ```inOrder```, dalam inOrder ini penjelajahan dilakukan ke subpohon kiri terlebih dahulu, kemudian node sekarang dicetak, dan setelah itu dilakukan penjelajahan ke subpohon kanan. Ketiga ```postOrder```, dalam postOrder ini penjelajahan dilakukan ke subpohon kiri terlebih dahulu, kemudian ke subpohon kanan, dan setelah itu node sekarang dicetak. Lalu selanjutnya fungsi ```main```. Di dalam fungsi main ini node pohon dibentuk dan dihubungkan satu sama lain.

- #### Interpretasi output
1. preOrder: ```7 1 0 5 9 8```

Node sekarang dicetak terlebih dahulu, kemudian subpohon kiri dan subpohon kanan.

2. inOrder: ```0 1 5 7 8 9```

Subpohon kiri dicetak terlebih dahulu, kemudian node sekarang, dan setelah itu subpohon kanan.

3. postOrder: ```0 5 1 8 9 7```

Subpohon kiri dicetak terlebih dahulu, kemudian subpohon kanan, dan setelah itu node sekarang.

## Tugas Praktikum
### Unguided 
*Cantumkan NIM pada salah satu variabel di dalam program. Contoh : int nama_22102003;
### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

### Jawab:
#### A. Program:

```C++
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // Inisialisasi variabel NIM
    int OliviaIntanPuspita_2311110006 = 2311110006;
    
    int jumlahSimpul;
    cout << "Silakan masukkan jumlah simpul : ";
    cin >> jumlahSimpul;

    vector<string> simpul(jumlahSimpul);
    cout << "Silakan masukkan nama simpul" << endl;
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> simpul[i];
    }

    vector<vector<int>> busur(jumlahSimpul, vector<int>(jumlahSimpul, 0));
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < jumlahSimpul; ++i) {
        for (int j = 0; j < jumlahSimpul; ++j) {
            cout << simpul[i] << "--> " << simpul[j] << " = ";
            cin >> busur[i][j];
        }
    }

    cout << "\n";
    cout << setw(10) << " ";
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << setw(10) << simpul[i];
    }
    cout << endl;
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << setw(10) << simpul[i];
        for (int j = 0; j < jumlahSimpul; ++j) {
            cout << setw(10) << busur[i][j];
        }
        cout << endl;
    }

    return 0;
}
```

#### B. Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/635a27a1-83f7-4da3-95f1-41403666ef55)

#### C. Interpretasi: 
- #### Interpretasi program
Program di atas merupakan program graph untuk menghitung jarak dari sebuah kota ke kota lainnya dengan menggunakan inputan user. Di awal kita melakukan inisialisasi variabel NIM ```OliviaIntanPuspita_2311110006```. Selanjutnya terdapat ```jumlahSimpul```, disini kita diminta untuk memasukkan jumlah simpul yang ingin dimasukkan ke dalam graf. Kemudian ```vector simpul``` yang akan menyimpan nama simpul dalam vektor. Jadi, kita diminta untuk memasukkan nama setiap simpulnya. Setelah itu ```vector busur```, disini kita diminta untuk memasukkan bobot setiap simpul ke simpul lainnya. Bobot tersebut kemudian disimpan dalam matriks ```busur```. Lalu yang terakhir program akan menampilkan matriks ketetanggaan yang menunjukkan bobot dari tiap simpul ke simpul lainnya.

- #### Interpretasi output
Dari output di atas terlihat bahwa:
1. Kita memasukkan jumlah simpul sebanyak 2
2. Kita memberikan nama tiap simpulnya

```Simpul 1 : BALI``` 

```Simpul 2 : PALU```

3. Kita memasukkan bobot antar simpul. 

```BALI--> BALI = 0```

```BALI--> PALU = 3```

```PALU--> BALI = 4```

```PALU--> PALU = 0```

4. Program mencetak matriks ketetanggan

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!
### Jawab:
#### A. Program:

```C++
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    // konstruktor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

TNode* masukkanNode(TNode *akar, int nilai) {
    if (akar == NULL) {
        return new TNode(nilai);
    }
    if (nilai < akar->data) {
        akar->left = masukkanNode(akar->left, nilai);
    } else {
        akar->right = masukkanNode(akar->right, nilai);
    }
    return akar;
}

TNode* cariNode(TNode *akar, int nilai) {
    if (akar == NULL || akar->data == nilai) {
        return akar;
    }
    if (nilai < akar->data) {
        return cariNode(akar->left, nilai);
    } else {
        return cariNode(akar->right, nilai);
    }
}

void tampilkanAnak(TNode *node) {
    if (node == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }
    cout << "Node " << node->data << " memiliki anak: ";
    if (node->left != NULL) {
        cout << node->left->data << " (kiri) ";
    }
    if (node->right != NULL) {
        cout << node->right->data << " (kanan) ";
    }
    if (node->left == NULL && node->right == NULL) {
        cout << "Tidak ada anak";
    }
    cout << endl;
}

void tampilkanKeturunan(TNode *node) {
    if (node == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }
    cout << "Keturunan dari node " << node->data << ": ";
    queue<TNode*> q;
    q.push(node);
    bool pertama = true;
    while (!q.empty()) {
        TNode *saat_ini = q.front();
        q.pop();
        if (saat_ini != node) {
            cout << saat_ini->data << " ";
        }
        if (saat_ini->left != NULL) {
            q.push(saat_ini->left);
        }
        if (saat_ini->right != NULL) {
            q.push(saat_ini->right);
        }
    }
    cout << endl;
}

void tampilkanMenu() {
    cout << "1. Masukkan node" << endl;
    cout << "2. Traversal pre-order" << endl;
    cout << "3. Traversal in-order" << endl;
    cout << "4. Traversal post-order" << endl;
    cout << "5. Tampilkan anak dari node" << endl;
    cout << "6. Tampilkan keturunan dari node" << endl;
    cout << "7. Keluar" << endl;
    cout << "Masukkan pilihan Anda: ";
}

int main() {
    TNode *akar = NULL;
    int pilihan, nilai;

    do {
        tampilkanMenu();
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai untuk dimasukkan: ";
                cin >> nilai;
                akar = masukkanNode(akar, nilai);
                break;
            case 2:
                cout << "Traversal pre-order: ";
                preOrder(akar);
                cout << endl;
                break;
            case 3:
                cout << "Traversal in-order: ";
                inOrder(akar);
                cout << endl;
                break;
            case 4:
                cout << "Traversal post-order: ";
                postOrder(akar);
                cout << endl;
                break;
            case 5:
                cout << "Masukkan nilai node untuk menampilkan anak-anak: ";
                cin >> nilai;
                tampilkanAnak(cariNode(akar, nilai));
                break;
            case 6:
                cout << "Masukkan nilai node untuk menampilkan keturunan: ";
                cin >> nilai;
                tampilkanKeturunan(cariNode(akar, nilai));
                break;
            case 7:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 7);

    return 0;
}
```

#### B. Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/98acf23c-9900-41bb-a0a5-7bd36145c3e5)

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/daee9ef3-9239-4b01-bd62-a1468bc519d2)

#### C. Interpretasi: 
- #### Interpretasi program
Program di atas merupakan modifikasi dari guided tree sebelumnya. Dimana pada program ini ditambahkan fungsi untuk menampilkan node child dan descendant dari node yang diinput kan. Program ini juga memiliki 7 menu untuk melakukan beberapa operasi seperti: memasukkan node ke dalam pohon, melakukan traversal pre-order, in-order, dan post-order, menampilkan anak-anak dari node tertentu, menampilkan keturunan dari node tertentu, dan terakhir keluar dari program. Sama seperti sebelumnya untuk yang pertama terdapat struktur ```TNode```, struktur ini mendefinisikan node dalam pohon biner yaitu left (anak kiri), dan right (anak kanan). Kemudian terdapat fungsi Traversal atau penjelajahan. Fungsi ini digunakan untuk melakukan tiga traversal yaitu ```preOrder```, ```inOrder```, dan ```postOrder```. Selanjutnya fungsi Insert dan Find yang digunakan untuk menambahkan node baru ke dalam pohon. Lalu terdapat juga fungsi ```cariNode``` yang digunakan untuk mencari node dengan nilai tertentu. Kemudian terdapat fungsi ```tampilkanAnak``` yang digunakan untuk menampilkan anak-anak dari node tertentu, dan fungsi ```tampilkanKeturunan``` yang digunakan untuk menampilkan seluruh keturunan dari node tertentu.

- #### Interpretasi output
Dari output di atas dapat kita lihat operasi apa saja yang telah dilakukan, yaitu sebagai berikut:

1. Pilih menu 1: Masukkan node

Memasukkan nilai ```63``` untuk ditambahkan ke dalam pohon 

2. Pilih menu 1: Masukkan node

Memasukkan nilai ```27``` untuk ditambahkan ke dalam pohon 

3. Pilih menu 1: Masukkan node

Memasukkan nilai ```99``` untuk ditambahkan ke dalam pohon 

4. Pilih menu 2: Traversal pre-order

Menampilkan node dalam urutan preOrder dimana urutannya adalah akar, kiri, kanan : ```63 27 99```

5. Pilih menu 3: Traversal in-order

Menampilkan node dalam urutan inOrder dimana urutannya adalah kiri, akar, kanan : ```27 63 99```

6. Pilih menu 4: Traversal post-order

Menampilkan node dalam urutan postOrder dimana urutannya adalah kiri, kanan, akar : ```27 99 63```

7. Pilih menu 5: Tampilkan anak dari nood

Menampilkan anak-anak dari node 63: ```Node 63 memiliki anak: 27 (kiri) dan 99 (kanan).

8. Pilih menu 6: Tampilkan keturunan dari node

Menampilkan seluruh keturunan dari node 63: ```Keturunan dari node 63: adalah 27 99```

9. Pilih menu 7: Keluar

Menghentikan program

## Kesimpulan
Graph atau yang biasa disebut graf adalah suatu struktur data yang luarannya menampilkan hubungan antara objek menggunakan suatu simpul atau yang biasa disebut vertex dan sisi atau yang biasa disebut edge. Dalam algoritma terdapat 3 jenis graph, yaitu directed graph, undirected graph, dan weight graph. Salah satu representasi dari graph sendiri yaitu dengan matriks. 

Tree adalah struktur data yang menyerupai pohon. Hal ini karena pohon terdiri dari satu node yang terurut dalam grafik terhubung. Terdapat binary tree atau pohon biner yang dimana simpulnya tidak lebih dari 2. Terdapat beberapa operasi dalam tree yang salah satunya adalah traverse. Traverse sendiri merupakan penjelajahan pada pohon yang memiliki 3 metode, yaitu preOrder, inOrder, dan postOrder.

## Referensi
[1] O. Arifin, S.Kom., M.Cs, dkk, Dasar Pemrograman (Teori & Aplikasi), Jambi: PT. Sonpedia Publishing Indonesia, 2023.

[2] M. Erkamim, S.Kom., M.Kom, dkk, Buku Ajar Algoritma dan Struktur Data, Indonesia: PT. Sonpedia Publishing Indonesia, 2024.

[3] Amrullah, Aplikasi Graf Pohon dalam Algoritma Huffman, vol. VI, no. 1, pp. 25, Maret 2011.

[4] V. Siahaan, Buku Resep Algoritma dan Struktur Data dengan Java, Sumatera Utara: Balige Publishing, 2020.

