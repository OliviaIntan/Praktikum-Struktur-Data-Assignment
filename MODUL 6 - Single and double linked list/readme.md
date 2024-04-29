# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Olivia Intan Puspita</p>

## Dasar Teori

Program adalah kumpulan instruksi komputer, sedangkan metode dan tahapan sistematis dalam program adalah algoritma. Algoritma dapat dtuliskan dengan banyak cara, mulai dari menggunakan bahasa alami yang digunakan sehari-hari, simbol grafik bagan alir, sampai menggunakan bahasa pemrograman seperti bahasa C++ [2].

Pemakaian struktur data yang tepat di dalam proses
pemrograman akan menghasilkan algoritma yang lebih jelas dan tepat, sehingga menjadikan program secara keseluruhan lebih efisien dan sederhana. Struktur data yang
″standar″ yang biasanya digunakan dibidang informatika adalah Linked List.

Linked list merupakan struktur data yang memiliki kelebihan dalam efisiensi memori dan kecepatan dalam menyisipkan data. Linked list berguna untuk menyimpan beberapa data dalam memori [1]. Konsep linked list yaitu struktur data yang setiap itemnya dihubungkan satu sama lain dengan menggunakan pointer [3].

Secara umum, sebuah list bertipe T adalah sebuah barisan elemen-elemen bertipe T beserta ooperasi-operasinya yang melipiti:
1. Membuat list (menginisialisasi list), yaitu membuat list menjadi kosong
2. Menentukan apakah status list kosong atau tidak
3. Menentukan apakah status list penuh atau tidak
4. Mengetaui panjang (jumlah elemen) list
5. Mengambil sebarang node dari list (menghapus node)
6. Mengakses sebarang node dalam list, dengan membaca nilai atau mengganti nilai yang ada dengan nilai baru
7. MenyisipKkan node baru ke dlam list di sebarang lokasi [1]

- 1. Single Linked List

Single Linked List merupakan suatu linked list yang hanya memiliki satu variabel pointer saja. Dimana pointer tersebut menunjuk ke node selanjutnya. Biasanya field
pada tail menunjuk ke NULL. Terdapat dua Single Linked List, yaitu Circular dan Non Circular.

Single Linked List Circular adalah Single Linked List yang pointer nextnya menunjuk pada dirinya sendiri. Jika Single Linked List tersebut terdiri dari beberapa node, maka pointer next pada node terakhir akan menunjuk ke node terdepannya. Single artinya field pointer-nya hanya satu buah saja dan satu arah. Circular artinya pointer next-nya akan menunjuk pada dirinya sendiri sehingga berputar. Ilustrasi Single Linked List Circular: Setiap node pada linked list mempunyai field yang berisi pointer ke node berikutnya, dan juga memiliki field yang berisi data. Pada akhir linked list, node terakhir akan menunjuk ke node terdepan sehingga linked list tersebut berputar. Node terakhir akan menunjuk lagi ke head. 

Single Linked List Non Circular. Single artinya field pointer-nya hanya satu buah saja dan satu arah. Linked List artinya node-node tersebut saling terhubung satu sama lain. Ilustrasi Single Linked List Non Circular: Setiap node pada linked list mempunyai field yang berisi pointer ke node berikutnya, dan juga memiliki field yang berisi data. Pada akhir linked list, node terakhir akan menunjuk ke NULL yang akan digunakan sebagai kondisi berhenti pada saat pembacaan isi linked list.

- 2. Double Linked List

Elemen-elemen dihubungkan dengan dua pointer dalam satu elemen. Struktur ini menyebabkan list melintas baik ke depan maupun ke belakang. Masing-masing elemen pada double linked list terdiri dari tiga bagian, disamping data dan pointer next, masing-masing dilengkapi dengan pointer prev yang menunjuk ke elemen sebelumnya. Double linked list dibentuk dengan menyusun sejumlah elemen sehingga pointer next menujuk ke elemen yang mengikutinya dan pointer prev menujuk ke elemen yang mendahuluinya. Untuk menunjukkan head dari double linked list, maka pointer prev dari elemen pertama menujuk NULL. Untuk menunjukkan tail dari double linked list tersebut, maka pointer next dari elemen terakhir menunjuk NULL [2].

## Guided 

### 1. Guided 1: Latihan Single Linked List

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Tambah Data di Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data di Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data di Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data = data;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah Data di Depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Tengah
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Semua Node
void clearList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3); tampil();
    insertBelakang(5); tampil();
    insertDepan(2); tampil();
    insertDepan(1); tampil();
    hapusDepan(); tampil();
    hapusBelakang(); tampil();
    insertTengah(7, 2); tampil();
    hapusTengah(2); tampil();
    ubahDepan(1); tampil();
    ubahBelakang(8); tampil();
    ubahTengah(11, 2); tampil();
    clearList();
    return 0;
}
```
Program di atas merupakan contoh implementasi dari single Linked List. Dalam program tersebut, setiap node memiliki tipe data Node yang terdiri dari dua anggota, yaitu data yang merupakan nilai yang disimpan dalam node dan next yang merupakan pointer ke node selanjutnya dalam list. Terdapat beberapa fungsi dalam program tersebut. Pertama fungsi init() yang berfungsi untuk menginisialisasi pointer kepala (head) dan pointer ekor (tail) ke NULL. Lalu ada fungsi isEmpty() yang mengembalikan true jika linked list kosong atau jika pointer kepala (head) adalah NULL. Selanjutnya insertDepan(int nilai) yang berfungsi untuk menambahkan data di bagian depan atau awal. insertBelakang(int nilai) yang berfungsi untuk menambahkan data di bagian belakang atau akhir. Lalu ada hitungList() untuk menghitung jumlah node dalam linked list dengan mengiterasi melalui setiap node dari kepala hingga ekor. insertTengah(int data, int posisi) berfungsi untuk menambahkan data atau nilai di posisi yang ditentukan. hapusDepan() untuk menghapus data pertama atau awal. hapusBelakang() untuk menghapus data terakhir atau belakang. hapusTengah(int posisi) untuk menghapus data pada posisi yang ditentukan dalam linked list. Selanjutnya ada fungsi ubahDepan(int data) untuk mengubah nilai data awal atau pertama. ubahTengah(int data, int posisi) dimana berfungsi untuk mengubah nilai data dengan posisi yang ditentukan. ubahBelakang(int data) untuk mengubah nilai data belakang atau akhir. Kemudian clearList() untuk menghapus semua data dari linked list. Fungsi tampil() untuk menampilkan seluruh data dalam linked list. Fungsi-fungsi di atas kemudian dipanggil dalam fungsi main(). Di dalam fungsi main(), linked list diinisialisasi menggunakan init(), kemudian dilakukan berbagai operasi pada linked list.

#### Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/52ee8590-c587-4b87-88a2-faef512ebad0)

Dari hasil output tersebut dapat kita ketahui bahwa, pertama kita menambahkan angka 3 di depan lalu ditampilkan. Setelah itu kita tambahkan angka 5 di belakang lalu ditampilkan. Kemudian angka 2 kita tambahkan di depan, ini berarti posisi angka 3 tadi bergeser lalu ditampilkan. Selanjutnya kita tambahkan angka 1 di depan, maka angka 2 akan bergeser lalu ditampilkan. Kemudian kita hapus depan dimana itu adalah posisi angka 1, setelah itu ditampilkan. Lanjut hapus belakang yang itu merupakan angka 5, lalu ditampilkan. Kemudian kita tambahkan nilai tengah dengan angka 7 dan berada di posisi kedua, lalu ditampilkan. Setelah itu kita hapus data tengah yang berada di posisi kedua, berarti angka 7 tadi, lalu ditampilkan. Selanjutnya kita ubah depan menjadi angka 1 dan kita ubah belakang menjadi angka 8, lalu ditampilkan. Lanjut kita juga mengubah tengah yang berada di posisi 2 menjadi angka 11,lalu ditampilkan. Dan yang terakhir kita bersihkan list, maka list berhasil terhapus. 

#### Full code Screenshot:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/fcc169d6-61d9-44b9-9aad-e6cf72af93c5)


### 2. Guided 2: Latihan Double Linked List

```C++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Program di atas merupakan contoh implementasi dari doubly linked list. Program di atas memiliki dua kelas, yaitu Node yang merepresentasikan setiap elemen dalam linked list, dan DoublyLinkedList yang berisi operasi-operasi yang dapat dilakukan pada linked list. Fungsi push(int data) berfungsi untuk menambahkan data baru ke depan linked list, sedangkan fungsi pop() untuk menghapus data dari depan. Fungsi update(int oldData, int newData) berfungsi untuk mengubah atau memperbarui data lama menjadi data baru. Sekanjutnya fungsi deleteAll() berfungsi untuk menghapus semua data dari linked list. Fungsi display() berarti menampilkan semua data. Kemudian di dalam fungsi main() kita diberikan beberapa pilihan untuk melakukan berbagai operasi. Kita dapat memilih untuk menambahkan data baru, menghapus data, memperbarui data, membersihkan data, menampilkan data, dan yang terakhir keluar dari program. Selama kita belum memilih angka 6 maka program akan terus berjalan dalam loop hingga kita memilih angka 6 yaitu keluar.


#### Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/2fc84073-7741-47f8-a2d0-9aeaad5f0fce)
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/1ebf4f7a-146a-4e30-bca3-9df5ccf0f409)

Dari output di atas dapat kita ketahui bahwa, Pertama saya memasukkan pilihan 1 lalu menambahkan data dengan angka 7. Selanjutnya saya memasukkan pilihan 1 kembali lalu menambahkan data dengan angka 8. Lanjut pilihan 3 yaitu untuk meperbarui data, dimana data yang awalnya angka 7 saya ubah menjadi angka 9. Kemudian saya memasukkan pilihan 2 yaitu menghapus data. Setelah itu saya memasukkan pilihan 5 karena ingin menampilkan data. Dan dapat terlihat data yang ditampilkan adalah angka 9. Terakhir, saya pilih angka 6 lalu program selesai.

#### Full code Screenshot:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/07b8850e-b74c-451a-af4b-bc67f73d023c)

### 3. Guided 3: Linked List Circular 

```C++
#include <iostream>
using namespace std;

/// Program Single Linked List Circular

// Deklarasi Struct Node
struct Node {
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init() {
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty() {
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru 
void buatNode(string data) {
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList() {
    bantu = head;
    int jumlah = 0;
    
    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

// Tambah Depan
void insertDepan(string data) {
    // Buat Node Baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Belakang
void insertBelakang(string data) {
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        baru->data = data;

        // Transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus) {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head) {
                hapus = hapus->next;
            }

            while (tail->next != hapus) {
                tail = tail->next;
            }
            
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi) {
    if (isEmpty() == 0) {
        // Transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearlist() {
    if (head != NULL) {
        hapus = head->next;

        while (hapus != head) {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }

        delete head;
        head = NULL;
    }

    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    if (isEmpty() == 0) {
        tail = head;

        do {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head) ;

        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
```
Program di atas adalah implementasi dari linked list circular. Linked list cvircular sendiri adalah struktur data linked list di mana setiap node memiliki pointer yang menunjuk ke node berikutnya, dan node terakhir menunjuk kembali ke node pertama. Untuk yang pertama mendeklarasi struct node terlebih dahulu. Lalu terdapat fungsi init() yang berfungsi menginisialisasi pointer head dan tail menjadi NULL. Setelah itu pengecekan yang dilakukan oleh fungsi isEmpty(), dimana fungsi ini mengembalikan nilai 1 jika linked list kosong, dan 0 jika tidak. Lanjut membuat node baru dengan fungsi buatNode(string data). Kemudian menghitung list jumlah data menggunakan fungsi hitungList(). Sekanjutnya fungsi insertDepan(string data) yang berfungsi sama, yaitu menambahkan data di posisi depan. Lalu insertBelakang(string data) menambahkan data di posisi belakang, dan insertTengah(string data, int posisi) menambahkan data dengan posisi yang ditentukan. Kemudian terdapat fungsi hapusDepan() untuk menghapus node depan atau pertama, fungsi hapusBelakang() untuk menghapus node belakang atau terakhir, dan hapusTengah(int posisi) untuk menghapus data pada posisi yang ditentukan. Selanjutnya, terdapat fungsi clearlist() untuk menghapus semua data dan fungsi tampil() untuk menampilkan semua data. Dan dapat kita lihat di dalam fungsi main() terdapat beberapa operasi yang dilakukan dimana ini nanti menentukan output yang keluar.

### Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/80fc7dcf-0ff3-4a14-b057-f35db04a6e6c)

Dari output tersebut dapat kita ketahui bahwa, yang pertama kita menambahkan 'Ayam' di depan lalu ditampilkan. Lanjut kita menambahkan 'Bebek' di depan juga, ini berarti menggeser posisi 'Ayam' lalu ditampilkan. Kemudian kita menambahkan 'Cicak' di belakang lalu ditampilkan. Lalu kita menambahkan 'Domba' di belakang juga, ini berarti menggeser posisi 'Cicak', lalu ditampilkan. Selanjutnya kita menghapus belakang lalu ditampilkan, menghapus depan lalu ditampilkan, dan kita menambahkan 'Sapi' di tengah yaitu di posisi 2 lalu ditampilkan. Kemudian kita menghapus tengah yaitu posisi 2, dan setelah itu ditampilkan.

### Full code Screenshot:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/b8463cc4-d230-4d97-b72f-b35bc578c6fb)

## Unguided 
Buatlah program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. 

- Program
```C++
#include <iostream>
#include <string>
#include <iomanip> // Library untuk setw
using namespace std;

// Deklarasi Struct Node
struct Node {
    string nama;
    string nim;
    Node *next;
};

Node *head = NULL;

// Inisialisasi Node
void init() {
    head = NULL;
}

// Mengecek apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Menambah Data di Depan
void insertDepan(string nama, string nim) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = head;
    head = baru;
    cout << "Data telah ditambahkan" << endl;
}

// Menambah Data di Belakang
void insertBelakang(string nama, string nim) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    baru->next = NULL;
    if (isEmpty()) {
        head = baru;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Data telah ditambahkan" << endl;
}

// Menambah Data di Tengah
void insertTengah(string nama, string nim, int posisi) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->nim = nim;
    if (posisi == 1 || isEmpty()) {
        insertDepan(nama, nim);
    } else {
        Node *temp = head;
        for (int i = 1; i < posisi - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }
        baru->next = temp->next;
        temp->next = baru;
        cout << "Data telah ditambahkan" << endl;
    }
}

// Menghapus Node di Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        head = head->next;
        delete hapus;
        cout << "Data posisi mahasiswa yang dipilih berhasil dihapus" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Menghapus Node di Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        if (head->next == NULL) {
            hapusDepan();
        } else {
            Node *hapus = head;
            Node *sebelumHapus = NULL;
            while (hapus->next != NULL) {
                sebelumHapus = hapus;
                hapus = hapus->next;
            }
            sebelumHapus->next = NULL;
            delete hapus;
            cout << "Data posisi mahasiswa yang dipilih berhasil dihapus" << endl;
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

// Menghapus Node di Tengah
void hapusTengah(int posisi) {
    if (!isEmpty()) {
        if (posisi == 1) {
            hapusDepan();
        } else {
            Node *hapus = head;
            Node *sebelumHapus = NULL;
            for (int i = 1; i < posisi && hapus->next != NULL; i++) {
                sebelumHapus = hapus;
                hapus = hapus->next;
            }
            if (hapus != NULL) {
                sebelumHapus->next = hapus->next;
                delete hapus;
                cout << "Data posisi mahasiswa yang dipilih berhasil dihapus" << endl;
            } else {
                cout << "Posisi tidak valid" << endl;
            }
        }
    } else {
        cout << "List kosong!" << endl;
    }
}

// Mengubah Data di Depan
void ubahDepan(string namaBaru, string nimBaru) {
    if (!isEmpty()) {
        string namaLama = head->nama;
        string nimLama = head->nim;
        head->nama = namaBaru;
        head->nim = nimBaru;
        cout << "Data (" << namaLama << ", " << nimLama << ") telah diubah menjadi (" << namaBaru << ", " << nimBaru << ")" << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Mengubah Data di Belakang
void ubahBelakang(string namaBaru, string nimBaru) {
    if (!isEmpty()) {
        Node *temp = head;
        string namaLama, nimLama;
        while (temp->next != NULL) {
            namaLama = temp->nama;
            nimLama = temp->nim;
            temp = temp->next;
        }
        namaLama = temp->nama;
        nimLama = temp->nim;
        temp->nama = namaBaru;
        temp->nim = nimBaru;
        cout << "Data (" << namaLama << ", " << nimLama << ") telah diubah menjadi (" << namaBaru << ", " << nimBaru << ")" << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Mengubah Data di Tengah
void ubahTengah(string namaBaru, string nimBaru, int posisi) {
    if (!isEmpty()) {
        Node *temp = head;
        string namaLama, nimLama;
        for (int i = 1; i < posisi && temp != NULL; i++) {
            namaLama = temp->nama;
            nimLama = temp->nim;
            temp = temp->next;
        }
        if (temp != NULL) {
            namaLama = temp->nama;
            nimLama = temp->nim;
            temp->nama = namaBaru;
            temp->nim = nimBaru;
            cout << "Data (" << namaLama << ", " << nimLama << ") pada posisi " << posisi << " telah diubah menjadi (" << namaBaru << ", " << nimBaru << ")" << endl;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Menghapus Semua Node
void hapusList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    cout << "List berhasil terhapus!" << endl;
}

void tampilkan() {
    if (!isEmpty()) {
        cout << "=============================================================" << endl;
        cout << "DATA MAHASISWA" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "| No.\t| NAMA\t\t\t  | NIM\t\t\t    |" << endl;
        cout << "-------------------------------------------------------------" << endl;
        int counter = 1;
        Node *temp = head;
        while (temp != NULL) {
            cout << "| " << counter << "\t| " << left << setw(24) << temp->nama << "| " << setw(24) << temp->nim << "|" << endl;
            temp = temp->next;
            counter++;
        }
        cout << "-------------------------------------------------------------" << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    int pilihan;
    string nama, nim;
    int posisi;

    do {
        cout << "=============================================================" << endl;
        cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "=============================================================" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. Tampilkan" << endl;
        cout << "0. Keluar" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "Pilih Operasi : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                insertDepan(nama, nim);
                break;
            case 2:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                insertBelakang(nama, nim);
                break;
            case 3:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                insertTengah(nama, nim, posisi);
                break;
            case 4:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                ubahDepan(nama, nim);
                break;
            case 5:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                ubahBelakang(nama, nim);
                break;
            case 6:
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                ubahTengah(nama, nim, posisi);
                break;
            case 7:
                hapusDepan();
                break;
            case 8:
                hapusBelakang();
                break;
            case 9:
                cout << "Masukkan posisi : ";
                cin >> posisi;
                hapusTengah(posisi);
                break;
            case 10:
                hapusList();
                break;
            case 11:
                tampilkan();
                break;
            case 0:
                cout << "Terima kasih, program selesai" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
        }
    } while (pilihan != 0);

    return 0;
}
```
- Interpretasi

Program di atas adalah contoh program menu Linked List Non Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. Untuk yang pertama Deklarasi Struct Node, kita mendefinisikan struktur data untuk node dalam linked list. Setiap node memiliki dua string untuk menyimpan nama dan NIM mahasiswa, serta pointer next untuk menunjuk ke node berikutnya. Kemudian terdapat beberapa fungsi pada program di atas. Fungsi init() berfungsi untuk mengnisialisasi pointer head menjadi NULL. Fungsi isEmpty() untuk mengecek apakah list kosong. Selanjutnya fungsi insertDepan(string nama, string nim) yang berfungsi untuk menambahkan data di depan atau pertama. Pada fungsi ini, pertama membuat node baru dengan data nama dan nim yang diberikan. Selanjutnya, node baru tersebut ditautkan ke node pertama saat ini dengan menetapkan next node baru ke head, dan kemudian head diperbarui untuk menunjuk ke node baru. Akhirnya, fungsi mencetak pesan konfirmasi. Lalu fungsi insertBelakang(string nama, string nim) yang digunakan untuk menambahkan data baru di belakang atau akhir. Apabila linked list kosong, node baru langsung dijadikan sebagai node pertama (head). Namun apabila tidak, fungsi ini menemukan node terakhir dalam linked list dengan melakukan iterasi melalui semua node menggunakan pointer temp, dan kemudian menautkan node baru di belakang node terakhir. Selanjujtnya fungsi insertTengah(string nama, string nim, int posisi) yang berfungsi untuk menambahkan data di tengah dengan posisi yang ditentukan. Apabila posisi adalah 1 atau linked list kosong, fungsi ini akan memanggil insertDepan() untuk menambahkan node di depan. Apabila tidak, fungsi ini mencari node pada posisi sebelumnya (posisi - 1) dan menautkan node baru di antara node tersebut dan node setelahnya. Kemudian fungsi hapusDepan() yang berfungsi untuk menghapus data depan atau pertama. Lalu fungsi hapusBelakang() untuk menghapus node belakang atau terakhir. Apabila linked list hanya memiliki satu node, fungsi ini akan memanggil hapusDepan() untuk menghapus node tersebut. Jika tidak, fungsi ini menemukan node sebelum node terakhir, kemudian menghapus node terakhir tersebut. Kemudian fungsi hapusTengah(int posisi) untuk menghapus data pada posisi yang ditentukan. Selanjutnya fungsi ubahDepan(string namaBaru, string nimBaru), fungsi ini untuk mengubah data awal atau pertama. Lalu ubahBelakang(string namaBaru, string nimBaru) untuk mengubah data belakang atau terakhir, dan ubahTengah(string namaBaru, string nimBaru, int posisi) untuk mengubah data pada pada posisi yang ditentukan. Setelah itu terdapat fungsi hapusList() yang berfungsi untuk menghapus semua data. Fungsi tampilkan() untuk menampilkan seluruh data mahasiswa. Fungsi ini melakukan iterasi melalui semua node dalam linked list, dan untuk setiap node, ia mencetak nomor urut, nama, dan NIM mahasiswa dalam format yang ditentukan. Jika linked list kosong, fungsi akan mencetak pesan bahwa list masih kosong. Dan terakhir fungsi main(), dimana disini merupakan program utama yang melakukan operasi-operasi pada linked list menggunakan menu yang sudah disediakan. Total terdapat 12 menu beserta menu keluar. Disini kita diminta untuk memilih operasi yang ingin dilakukan, setelah kita selesai memilih operasi, program akan mengeksekusi operasi tersebut dan menampilkan hasilnya. Kita dapat terus memilih operasi dan baru akan berhenti apabila kita sudah memilih untuk keluar dari program.

### 1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan  NIM mahasiswa!

#### Output:
- Tampilan Menu:

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/4c0674e0-969e-447c-ab2f-1f232d5fd154)

Dapat dilihat pada output di atas, terdapat judul 'PROGRAM SINGLE LINKED LIST NON-CIRCULAR' yang diapit oleh 2 garis sehingga terlihat cantik dan rapi. Kemudian dibawahnya terdapat 11 tampilan menu yang dimulai dari 'Tambah Depan' hingga 'Tampilkan', lalu 0 untuk menu 'Keluar'. Dan setelah itu terdapat tulisan 'Pilih Operasi' yang dipisahkan dengan tampilan menu menggunakan garis.

- Tampilan Operasi Tambah:

-Tambah Depan

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/ae38466b-4356-4058-b67e-ffc183308aad)

Saat kita pilih operasi 1 maka program mengarah ke 'Tambah Depan'. Setekah itu kita diminta untuk memasukkan nama serta nim data yang ingin ditambahkan kemudian data berhasil ditambahkan.

-Tambah Belakang

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/fae8ea61-df45-4bd8-af9c-83edd25aa060)

Saat kita pilih operasi 2 maka program mengarah ke 'Tambah Belakang'. Setelah itu sama, kita diminta untuk memasukkan nama serta nim data yang ingin ditambahkan dan kemudian data berhasil ditambahkan.

-Tambah Tengah

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/af205282-d2b2-4be9-8028-eea285fec877)

Saat kita pilih operasi 3 maka program mengarah ke 'Tambah Tengah'. Setelah itu sama seperti 'Tambah Depan' dan 'Tambah Belakang', namun yang membedakan pada menu ini kita diminta untuk memasukkan posisi data yang ingin kita tambahkan. Setelah itu data berhasil ditambahkan.

- Tampilan Operasi Ubah:

-Ubah Depan

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/e96280a2-4512-4411-8270-63b9a465eb12)

Saat kita pilih operasi 4 maka program mengarah ke 'Ubah Depan'. Disini kita diminta untuk memasukkan nama serta nim baru. Setelah itu data nama dan nim lama berhasil diubah menjadi data nama dan nim baru.

-Ubah Belakang

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/262f13a8-10a6-491f-8e8a-977c6bf64572)

Saat kita pilih operasi 5 maka program mengarah ke 'Ubah Belakang'. Disini tampilan sama seperti 'Ubah Depan'.

-Ubah Tengah

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/ea8801cb-3f16-4c6b-b29e-1188924c577e)

Saat kita pilih operasi 6 maka program mengarah ke 'Ubah Tengah'. Disini tampilan sama seperti 'Ubah Depan' dan 'Ubah Belakang', namun karena di 'Tambah Tengah' tadi terdapat perintah memasukkan posisi, maka di 'Ubah Tengah' juga sama.

- Tampilan Operasi Tampilkan:

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/9497a731-1278-4f28-acd5-861911b2397d)

Saat kita pilih operasi 11 maka program mengarah ke 'Tampilkan'. Disini data ditampilkan dalam bentuk tabel menggunakan garis-garis sehingga terlihat cantik, rapi, dan terstruktur. Dimana pada tabel terdapat 3 kolom yaitu 'No.', 'NAMA', dan juga 'NIM'.

- Tampilan Operasi Hapus:

-Hapus Belakang

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/d52ef365-2434-4744-8a50-f8e73555bf21)

Saat kita pilih operasi 8 maka program mengarah ke 'Hapus Belakang'. Disini langsung data posisi mahasiswa yang dipilih berhasil dihapus.

-Hapus Tengah

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/e0733aa6-11e8-431d-920f-32ded31ecc19)

Saat kita pilih operasi 9 maka program mengarah ke 'Hapus Tengah'. Disini kita diminta untuk memasukkan posisi data, lalu data posisi mahasiswa yang dipilih berhasil dihapus.

- Menampilkan Operasi Hapus List:

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/b6b3baff-17b7-4b14-8fd6-0877b885fe02)

Saat kita pilih operasi 10 maka program mengarah ke 'Hapus List'. Disini list data yang sudah dibuat tadi berhasil terhapus. 

- Menampilkan Operator Keluar

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/ac2ab317-343b-4184-b610-c34faf7ffc75)

Saat kita pilih operasi 0 maka program mengarah ke 'Keluar'. Saat operator ini dipilih maka program selesai dijalankan. 

#### Full code Screenshot:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/47a60277-bd09-4230-9b56-18b26e1be162)


### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu  tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah) 

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/59c60934-3610-419a-8902-b8451dcc0d07)

#### Output:
- Menggunakan operator 'Tambah Depan' untuk data ke-1

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/d7a482b0-e1e8-4e37-a7c1-8c6b5b312c78)

- Menggunakan operator 'Tambah Belakang'' untuk data ke-10 atau data akhir

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/871b4ebd-b3bd-476c-bec9-e4c1a4c8c828)

- Menggunakan operator 'Tambah Tengah' untuk data selain ke-1 dan ke-10

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/9853c3fe-0627-4f56-86ac-1739c16f745b)
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/6180ef21-6e3d-44ac-8b25-63c73ee6ecab)
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/3a3bc9ae-fbae-4f71-b616-2b53eadd1f09)
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/223a7d75-e0e2-4271-a0bb-d864c38380e0)
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/45a46a66-1321-47b0-8587-c3affd7d990b)
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/137a011c-2864-4564-aef9-ed792daddae8)
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/219a56c5-faaf-445e-a8e4-027cbeb352ec)
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/fa5c7f76-7250-4d2e-9c3b-4149a8fb3d8f)

- Menampilkan data

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/f2c2057e-790e-43ad-98fa-c27e164d90b9)

Dapat kita lihat, 10 data telah berhasil ditambahkan dalam tabel. Tabel disusun secara terstruktur, rapi, dan cantik untuk dipandang.
  
#### Full code Screenshot:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/7fcc8fec-0952-48f5-90c3-f07bc0472966)

### 3. Lakukan perintah berikut:  

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/42af3696-1378-4796-9826-00696fcaf199)

#### Output:
- a. Tambahkan data berikut diantara Farrel dan Denis: Wati 2330004 

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/3c5bacb2-70ab-4bdd-8456-906083266e46)

Disini kita pilih operator 3 yaitu 'Tambah Tengah' untuk menambahkan nama serta NIM Wati, lalu kita masukkan posisi datanya yaitu di posisi ke-4.

- b. Hapus data Denis 

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/1c4b8710-720a-4d62-b394-2d151ec3630e)

Disini kita pilih operator 9 yaitu 'Hapus Tengah' untuk menghapus data Denis. Data Denis yang awalnya berada di posisi ke-4 berubah menjadi di posisi ke-5 karena tadi ditambahkan data Wati yang diletakkan di antara Farrel dan Denis. Itu artinya Wati berada di atas data Denis, sehingga posisi data Denis menurun.

- c. Tambahkan data berikut di awal: Owi 2330000 

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/f0fbd2f8-8d03-4d87-afdb-6fd4b8ee9433)

Disini kita pilih operator 1 yaitu 'Tambah Depan' untuk menambahkan data Owi di awal.

- d. Tambahkan data berikut di akhir: David 23300100 

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/e50a7882-6c74-4602-a9bf-ea6379779513)

Disini kita pilih operator 2 yaitu 'Tambah Belakang' untuk menambahkan data David di akhir.

- e. Ubah data Udin menjadi data berikut: Idin 23300045

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/597bd45f-b2cc-4941-852b-d3ab77e299aa)

Disini kita pilih operator 6 yaitu 'Ubah Tengah' untuk mengubah data Udin dengan NIM 23300048 yang berada di posisi ke-9 menjadi data Idin dengan NIM 23300045.

- F. Ubah data terakhir menjadi berikut: Lucy 23300101

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/38ffefba-df8d-4243-bf44-d089d66124f8)

Disini kita pilih operator 5 yaitu 'Ubah Belakang' untuk mengubah data terakhir yaitu David dengan NIM 23300100 menjadi data Lucy dengan NIM 23300101.

- g. Hapus data awal 

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/5fb794b8-f434-46eb-b0b7-91f6f05c7b1a)

Disini kita pilih operator 7 yaitu 'Hapus Depan' untuk menghapus data awal.

- h. Ubah data awal menjadi berikut: Bagas 2330002 

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/a114221e-55e0-4cc0-b094-949c42ef645c)

Disini kita pilih operator 4 yaitu 'Ubah Depan' untuk mengubah data awal yaitu Jawad dengan NIM 23300001 menjadi data Bagas dengan NIM 2330002.

- i. Hapus data akhir

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/7af95760-fdec-478e-b02d-8c201bae779e)

Disini kita pilih operator 8 yaitu 'Hapus Belakang' untuk menghapus data akhir.

- j. Tampilkan seluruh data

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/cf8fc174-c886-4586-bb0b-982ef94b9459)

Disini kita pilih operator 11 yaitu 'Tampilkan' untuk menampilkan seluruh data. Dapat dilihat pada gambar di atas, itu merupakan tampilan data terbaru setelah dilakukan beberapa perubahan.

#### Full code Screenshot:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/64c3e4e8-c891-4a01-9f40-ff7477630e5c)

## Kesimpulan
Ringkasan dan interpretasi pandangan saya dari hasil praktikum dan pembelajaran yang didapat yaitu:
- Hasil Praktikum

Hasil dari praktikum keenam ini, saya menjadi tahu mengenai 2 materi sekaligus, yaitu single and double linked list dan juga linked list circular non circular. Pada single and double linked list, saya menjadi paham mengenai perbedaan konsep dasar antara single dan double linked list, saya juga menjadi tau bagaimana penerapan dalam bahasa pemrograman c++ diantara keduanya. Lalu untuk linked list circular and non circular, saya menjadi tau dan paham mengenai materi linked list circular dan non circular, mulai dari perbedaan hingga karakteristik masing-masing. Kemudian saya juga dapat berlatih membuat linked list circular dan non circular, serta saya dapat menerapkan keduanya pada bahasa pemrograman c++.

- Pembelajaran yang didapat

Pada praktikum keenam ini, saya mendapat pembelajaran yang banyak dan berarti. Saya banyak belajar mengenai karakteristik single and double linked list serta implementasinya pada program c++, dan tak lupa juga karakteristik serta penerapan linked list circular dan non circular pada program c++. Kemudian tidak bisa dilupakan juga mengenai laporan praktikum yang ada dua di dalam 1 minggu. Tentu ini hal yang sangat berarti, karena dengan hal tersebut memaksa saya untuk belajar lebih dari biasanya, menggunakan waktu istirahat untuk mengerjakan laporan, serta tetap mengevaluasi laporan mulai dari kode program hingga interpretasi agar terus lebih baik setiap minggunya.

## Referensi
[1] H. Sismoro, K. Iskandar, Struktur Data & Pemrograman Dengan Pascal. Indonesia: Penerbit Andi, 2004.

[2] A. Sindar RMS, ST., M.TI, STRUKTUR DATA DAN ALGORITMA DENGAN C++. Indonesia: CV. AA. RIZKY, 2019.

[3] D. Sanjaya, Asyiknya Belajar Struktur Data di Planet C++. Indonesia: Elex Media Komputindo, 2005.