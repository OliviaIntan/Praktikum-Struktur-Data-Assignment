# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>
<p align="center">Nama: Olivia Intan Puspita</p>
<p align="center">NIM: 2311110006</p>
<p align="center">Kelas: S1SD-04-A</p>

## Dasar Teori

### Pengantar
Algoritma Hash dapat melakukan proses tambah, hapus dan pencarian dalam waktu yang konstan (Weiss, 2012). Waktu konstan ini juga disebut sebagai kekompleksan waktu O(1). Teknik Hash merupakan suatu metode yang secara langsung mengakses data record dalam suatu tabel dengan melakukan penghitungan pada key yang menjadi alamat record pada tabel. Key merupakan suatu data yang unik dapat berupa nomor atau karakter string [1].

Proses Hash terdiri dari dua langkah yaitu:

a. Menghitung fungsi Hash

Fungsi Hash adalah suatu fungsi yang mengubah key menjadi alamat dalam tabel dengan memetakan key tersebut ke alamat dalam tabel.

b. Resolusi terhadap tabrakan (collision resolution)

Resolusi terhadap tabrakan merupakan proses untuk menangani kejadian dua atau lebih key yang dipetakan ke
alamat yang sama pada tabel. Caranya yaitu dengan mencari lokasi yang kosong dalam tabel Hash secara terurut. Atau bisa juga dengan menggunakan fungsi Hash yang lain untuk mencari lokasi yang kosong [1].

### Pengertian Hash Table
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/04c0b292-0866-46a6-ac63-0b6e5b7dc461)

Gambar Struktur Data Jenis Hash Table [2].

Hash Table adalah Array dengan sel-sel yang ukuranya telah di tentukan dan dapat berisi data atau key yang memiliki kesamaan dengan data. Namun kita bisa juga mengganti tabel array dalam bentuk tabel sementara di mysql yang memiliki record–rocord dan primary key yang sesuai dengan data tersebutsebagai acuan untuk insert, update, delete, search,dan link [3]. Tabel hash bekerja dengan menggunakan fungsi hash, yang mengubah kunci menjadi indeks dalam tabel [4]. 

### Operasi Hash Table
Beberapa operasi utama yang dapat digunakan dalam hash table, anatara lain:

- search: untuk mencari data

- Insert: untuk menyisipkan data

- delete: untuk menghapus data [2].

### Kelebihan dan Kekurangan Hash Table
Keunggulan dari hash table adalah lebih mudah dalam melakukan proses sinkronisasi jika dibandingkan dengan jenis struktur data lainnya. Penggunaan hash table terkadang menjadi lebih efisien dalam hal pencarian data sehingga serinhg digunakan dalam software untuk pengindeksan database. Namun hash table juga meiliki kekurangan yaitu adanya bentrokan data (collision) yang sangat besar sehingga menjadi tidak efisien [2].

## Langkah Praktikum

### Guided 1
#### A. Program:

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
   
    // Deletion
    ht.remove(4);
   
    // Traversal
    ht.traverse();
   
    return 0;
}
```

#### B. Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/e8d824e8-50e3-4dbd-9be6-4751f5fc2baa)

#### C. Interpretasi:

- #### Interpretasi program
Program di atas adalah sebuah implementasi dari hash table. Untuk yang pertama kita buat ukuran maksimum dari hash table dengan nama ```MAX_SIZE``` dan ukuran maksimumnya adalah 10. Selanjutnya fungsi sederhana hash ```hash_func```. Fungsi ini akan mengambil kunci ```key``` dan mengembalikan indeks dalam table hash dengan cara menghitung sisa pembagian atau modulus dari kunci dengan MAX_SIZE ```key % MAX_SIZE```. Kemudian struktur node ```struct Node```. Struktur Node disini merepresentasikan setiap node dalam hash table. Setiap node sendiri menyimpan kunci ```key```, nilai ```value```, dan pointer ```next``` yang akan menunjuk ke node berikutnya. Setelah itu ```class HashTable```. ```table``` sebagai array pointer ke node ```Node**``` yang berfungsi sebagai hash table. Class HashTable disini sebagai konstruktor dari ```HashTable()``` yang berfungsi untuk menginisialisasi hash table dengan ukuran ```MAX_SIZE``` dan mengatur semua pointer ke ```nullptr```. Kemudian dia juga sebagai destruktor ```~HashTable()``` yang berfungsi untuk menghapus semua node dalam hash table dengan tujuan membersihkan memori. Selanjutnya adalah operasi pada hash table. Untuk yang pertama yaitu ```insert```. ```insert``` berperan menambahkan pasangan kunci ```key``` dan nilai ```value``` ke dalam hash table. Cara kerjanya, jika ```key``` sudah ada maka ```value``` diupdate. Namun jika tidak, maka node baru ditambahkan di awal daftar pada indeks yang sesuai. Yang kedua yaitu ```get```. Cara kerjanya, ```get``` akan mencari nilai berdasarkan kunci ```key```. Dia akan mengembalikan nilai jika ```key``` ditemukan. Namun jika tidak, dia akan mengembalikan ```-1```. Kemudian yang ketiga yaitu ```remove```. Cara kerja ```remove``` adalah dia menghapus node berdasarkan ```key```. Setelah node dihapus dia akan mengelola pointer untuk memastikan daftar tetap terhubung. Lalu yang keempat dan metode yang terakhir yaitu ```traverse```. ```traverse``` ini berfungsi menampilkan semua elemen dalam hash table. Selanjutnya kita masuk ke dalam fungsi ```main()```. Pada fungsi main ini kita melakukan beberapa operasi. Seperti yang pertama ```insert``` menambahkan beberapa pasangan kunci dan nilai. Disini kita menambahkan 3 pasangan yaitu ```ht.insert(1, 10)```, ```ht.insert(2, 20)```, ```ht.insert(3, 30)```. Kunci 1, 2, 3 dimasukkan dengan nilai masing-masing 10, 20, dan 30. Yang kedua ```get``` mencari nilai berdasarkan kunci. Disini kita mencari ```ht.get(1)``` dan ```ht.get(4)```. Yang ketiga ```remove``` menghapus kunci. Disini kita melakukan penghapusan kunci 4 ```ht.remove(4)```. Namun, karena kunci 4 tidak ada dalam hash table maka operasi ini tidak mengubah apapun dalam hash table. Yang keempat dan terakhir ```traverse``` menampilkan semua elemen yang ada pada hash table.

- #### Interpretasi output
Dapat kita lihat hasil output:

```Get key 1: 10```

```Get key 4: -1```

Output tersebut didapat dari fungsi ```get```, dimana dilakukan pencarian ```key 1``` lalu ditemukan dengan nilai ```10```, sedangkan ```key 4``` tidak ditemukan, sehingga mengembalikan ```-1```.

Selanjutnya:

```1: 10```

```2: 20```

```3: 30```

Output tersebut didapat dari fungsi ```traverse```, dimana dilakukan pencetakan seluruh elemen pada hash table.

### Guided 2

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}
```

#### B. Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/78ebc8c3-9dd2-409a-b572-98f24aaedd73)

#### C. Interpretasi:

- #### Interpretasi program
Program di atas adalah salah satu implementasi dari hash table untuk menyimpan dan mengelola data nama dan nomor telepon karyawan. Untuk yang pertama kita buat konstanta yang mendefinisikan ukuran hash table yaitu ```TABLE_SIZE``` dan dengan ukuran ```11```. Pada program ini terdapat dua kelas, untuk kelas yang pertama yaitu ```class HashNode```. Kelas ini digunakan untuk menyimpan nama ```name``` dan nomor telepon ```phone_number``` dari karyawan. Selanjutnya kelas kedua yaitu ```class HashMap```. Kelas ```HashMap``` ini mendefinisikan hash table menggunakan array dari vektor ```table[TABLE_SIZE]``` yang menyimpan pointer ke ```HashNode```. Terdapat beberapa fungsi di dalam ```class HashNode```. Pertama, fungsi ```hashFunc``` yang digunakan untuk menghitung nilai hash dari nama karyawan yang diberikan dengan menjumlahkan nilai ASCII dari setiap nama karyawan dan mengambil modulus dengan TABLE_SIZE untuk menentukan letak indeksnya. Kedua, fungsi ```insert``` yang digunakan untuk menambahkan nama dan nomor telepon karyawan ke dalam hash table. Jika sudah ada data yang sama, maka fungsi akan memperbarui nomor teleponnya. Ketiga, fungsi ```remove``` yang digunakan untuk menghapus data dari hash table. Keempat, fungsi ```searchByName``` yang digunakan untuk mencari nomor telepon berdasarkan nama. Kelima, fungsi ```print``` yang digunakan untuk mencetak seluruh data hash table. Kemudian fungsi ```main```. Pada fungsi ```main``` pertama kita membuat objek ```employee_map``` dari kelas ```HashMap```. Setelah itu kita melakukan beberapa operasi, diantaranya menambahkan tiga data ke dalam hash table ```employee.map.insert("Mistah", "1234")```, ```employee_map.insert("Pastah", "5678")```, ```employee_map.insert("Ghana", "91011")```, mencari dan mencetak nomor telepon Mistah ```employee_map.searchByName("Mistah")``` dan Pastah ```employee_map.searchByName("Pastah")```, menghapus data Mistah ```employee_map.remove("Mistah")```, mencari kembali data Mistah ```employee_map.searchByName("Mistah")```, dan terakhir mencetak seluruh hash table ```employee_map.print()```.

- #### Interpretasi output
Dapat kita lihat hasil output: 

```Nomor Hp Mistah : 1234```

```Phone Hp Pastah : 5678```

Pertama kita melakukan pencarian nomor hp Mistah dan Pastah. Karena nama yang dicari termasuk pada data nama karyawan yang telah dimasukkan sebelumnya, sehingga nomor hp mereka ditemukan.

Kemudian kita menghapus data Mistah pada hash table

Setelah itu kita melakukan pencarian nomor hp Mistah kembali:

```Nomer Hp Mistah setelah dihapus :  ```

Karena data Mistah sudah kita hapus, itu berarti nomor serta nama Mistah sudah hilang dari daftar hash table, sehingga output kosong.

Terakhir kita mencetak seluruh hash table beserta nomor indeksnya

```4: [Pastah, 5678]```

```6: [Ghana, 91011]```

Dapat kita lihat bahwa data Pastah berada di indeks ke-4 sedangkan data Ghana berada di indeks ke-6. 

## Tugas Praktikum
### Unguided

### 1. Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan : a.	Setiap mahasiswa memiliki NIM dan nilai. b.	Program memiliki tampilan pilihan menu berisi poin C. c.	Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

### Jawab:
#### A. Program:

```C++
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class Mahasiswa {
public:
    int NIM;
    int nilai;
    Mahasiswa(int n, int v) : NIM(n), nilai(v) {}
};

class HashTable {
private:
    vector<list<Mahasiswa>> table;
    int size;

    int hashFunction(int NIM) {
        return NIM % size;
    }

public:
    HashTable(int s) : size(s) {
        table.resize(size);
    }

    void addData(int NIM, int nilai) {
        int index = hashFunction(NIM);
        table[index].push_back(Mahasiswa(NIM, nilai));
        cout << "Data dengan NIM " << NIM << " dan nilai " << nilai << " telah ditambahkan." << endl;
    }

    void deleteData(int NIM) {
        int index = hashFunction(NIM);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->NIM == NIM) {
                table[index].erase(it);
                cout << "Data dengan NIM " << NIM << " telah dihapus." << endl;
                return;
            }
        }
        cout << "Data dengan NIM " << NIM << " tidak ditemukan." << endl;
    }

    void searchByNIM(int NIM) {
        int index = hashFunction(NIM);
        for (auto& mhs : table[index]) {
            if (mhs.NIM == NIM) {
                cout << "Data ditemukan: NIM = " << mhs.NIM << ", Nilai = " << mhs.nilai << endl;
                return;
            }
        }
        cout << "Data dengan NIM " << NIM << " tidak ditemukan." << endl;
    }

    void searchByRange(int min, int max) {
        bool found = false;
        cout << "Mahasiswa dengan nilai dalam rentang " << min << " - " << max << ":" << endl;
        for (int i = 0; i < size; ++i) {
            for (auto& mhs : table[i]) {
                if (mhs.nilai >= min && mhs.nilai <= max) {
                    cout << "NIM = " << mhs.NIM << ", Nilai = " << mhs.nilai << endl;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "Tidak ada mahasiswa dengan nilai dalam rentang " << min << " - " << max << "." << endl;
        }
    }
};

int main() {
    HashTable ht(10);
    int choice, NIM, nilai;

    while (true) {
        cout << "Menu:\n";
        cout << "1. Tambah data\n";
        cout << "2. Hapus data\n";
        cout << "3. Cari data berdasarkan NIM\n";
        cout << "4. Cari data berdasarkan rentang nilai\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Masukkan NIM: ";
            cin >> NIM;
            cout << "Masukkan nilai: ";
            cin >> nilai;
            ht.addData(NIM, nilai);
            break;
        case 2:
            cout << "Masukkan NIM yang akan dihapus: ";
            cin >> NIM;
            ht.deleteData(NIM);
            break;
        case 3:
            cout << "Masukkan NIM yang dicari: ";
            cin >> NIM;
            ht.searchByNIM(NIM);
            break;
        case 4:
            int min, max;
            cout << "Masukkan rentang nilai (min max): ";
            cin >> min >> max;
            ht.searchByRange(min, max);
            break;
        case 5:
            return 0;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
```

#### B. Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/2f499ce9-d6fe-4fbc-bd26-b61dc733e755)

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/aa50cae3-94c9-4883-a1cd-0fae42aac4cc)

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/dd898a38-2533-43a5-9294-904964b4d5e0)

#### C. Interpretasi: 
- #### Interpretasi program
Sesuai dengan perintah pada soal, program di atas merupakan implementasi hash table untuk menyimpan data mahasiswa, dimana setiap mahasiswa memiliki NIM dan nilai. Terdapat 5 menu yang ada dalam program. Menu ```1: Tambah Data```, ```2: Hapus Data```, ```3: Cari data berdasarkan NIM```, ```4: Cari data berdasarkan rentang nilai```, ```5: Keluar```. Untuk yang pertama disini terdapat ```class Mahasiswa```. Kelas Mahasiswa ini memiliki dua atribut, yaitu ```NIM``` dan ```nilai```. Konstruktor ```class Mahasiswa``` digunakan untuk menginisialisasi objek dengan NIM dan nilai. Selanjutnya ```class HashTable```. ```class HashTable``` ini memiliki vektor yang berisi list dari objek Mahasiswa. Di dalam ```class HashTable``` terdapat fungsi ```hashFunction``` yang digunakan untuk menentukan indeks tabel hash berdasarkan NIM. Kemudian terdapat beberapa metode dalam ```class HashTable```. Pertama, metode ```addData``` untuk menambahkan data mahasiswa. Kedua, metode ```deleteData``` untuk menghapus data mahasiswa berdasarkan NIM. Ketiga, metode ```searchByNIM``` untuk mencari data mahasiswa berdasarkan NIM. Keempat, metode ```searchByRange``` untuk mencari dan menampilkan data mahasiswa berdasarkan rentang nilai yang diminta. Selanjutnya untuk yang terakhir fungsi ```main```. Dalam fungsi main ini terdapat loop yang menampilkan 5 menu interaktif dan memproses pilihan yang kita inputkan. Jadi disini, kita diminta untuk memilih operasi yang ingin dilakukan. Setelah kita menginputkan pilihan operasi, program akan memanggil metode yang sesuai dari kelas ```HashTable```.

- #### Interpretasi output
1. Tambah Data 

Menambahkan data dengan NIM: 2311003 dan nilai: 74

```Data dengan NIM 2311003 dan nilai 74 telah ditambahkan.```

2. Tambah Data

Menambahkan data dengan NIM: 2311006 dan nilai: 89

```Data dengan NIM 2311006 dan nilai 89 telah ditambahkan.```

3. Tambah Data

Menambahkan data dengan NIM: 2311013 dan nilai: 69

```Data dengan NIM 2311013 dan nilai 69 telah ditambahkan.```

4. Tambah Data

Menambahkan data dengan NIM: 2311018 dan nilai: 81

```Data dengan NIM 2311018 dan nilai 81 telah ditambahkan.```

5. Tambah Data

Menambahkan data dengan NIM: 2311024 dan nilai: 76

```Data dengan NIM 2311024 dan nilai 76 telah ditambahkan.```

6. Cari data berdasarkan NIM

Mencari data dengan NIM: 2311013

```Data ditemukan: NIM = 2311013, Nilai = 69```

7. Hapus data

Menghapus data dengan NIM: 2311013

```Data dengan NIM 2311013 telah dihapus.```

8. Cari data berdasarkan NIM

Mencari kembali data dengan NIM: 2311013

```Data dengan NIM 2311013 tudak ditemukan.```

9. Cari data berdasarkan rentang nilai

Mencari data dengan rentang nilai: (80 90)

```Mahasiswa dengan nilai dalam rentang 80 - 90:```

```NIM = 2311006, Nilai = 89```

```NIM = 2311018, Nilai = 81```

10. Cari data berdasarkan rentang nilai

Mencari data dengan rentang nilai: (70 80)

```Mahasiswa dengan nilai dalam rentang 70 - 80:```

```NIM = 2311003, Nilai = 74```

```NIM = 2311024, Nilai = 76```

11. Keluar

Dan program selesai dijalankan

## Kesimpulan
Hash Table adalah struktur data yang menyusun data ke dalam pasangan key dan value atau kunci dan nilai. Komponen utama dalam hash table biasanya terdiri dari array dan fungsi hash. Cara kerja hash table ini dengan cara mengambil input kunci dan memetakanya ke nilai indeks array menggunakan fungsi hash. Setelah itu, data disimpan pada posisi indeks array yang dihasilkan oleh fungsi hash. Terdapat 5 operasi dalam hash table yang diimplementasikan pada praktikum ini, operasi tersebut antara lain: insertion untuk memasukkan data baru, deletion untuk menghapus data, searching untuk mencari data, update untuk memperbarui data, dan traversal untuk mencetak seluruh data.

## Referensi
[1] V. Mutiawani, HashTable sebagai Alternatif dari Algoritma Pencarian Biner pada Aplikasi E-Acesia, vol. 8, no. 2, pp. 943-944, Juli 2014.

[2] O. Arifin, S.Kom., M.Cs, dkk, Dasar Pemrograman (Teori & Aplikasi), Jambi: PT. Sonpedia Publishing Indonesia, 2023

[3] M. Syahrir, Fatimatuzzahra, Integrasi Pendekatan Metode Custom Hashingdan Data Partitioninguntuk Mempercepat Proses Pencarian Frekuensi Item-setpada Algoritma Apriori, vol. 20, no. 1, pp. 152, November 2020.

[4] S. S. Wanda, A.MI., S.Pd., M.M., M.Kom, dkk, Pengantar Ilmu Komputer (Pandungan Komprehensif bagi Pemula), Jambi: PT. Sonpedia Publishing Indonesia, 2023.