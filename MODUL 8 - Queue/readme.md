# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Olivia Intan Puspita</p>

## Dasar Teori

Kaidah utama dalam konsep queue adalah FIFO yang merupakan singkatan dari First In First Out, artinya adalah data yang pertama kali dimasukkan atau disimpan, maka data tersebut adalah yang pertama kali akan diakses atau dikeluarkan. Analoginya sama dengan antrian di sebuah loket pembelian tiket kereta, orang yang datang lebih dahulu, maka akan dilayani terlebih dahulu, dan akan selesai lebih dulu dari orang-orang yang datang setelahnya [1]. 

Queue atau Antrian merupakan kumpulan elemen dengan penyisipan dan penghapusan elemen yang dilakukan dari sisi/gerbang yang berbeda. Penyisipan dilakukan dari gerbang belakang dan penghapusan dilakukan dari gerbang depan [2].Struktur data antrian adalah struktur data linier di mana elemen-elemennya disimpan dalam urutan tertentu dan elemen baru hanya dapat ditambahkan di satu ujung (disebut "rear" atau "tail"), sedangkan elemen yang sudah ada hanya dapat dihapus dari ujung yang lain (disebut "front" atau "head"). Penambahan data dilakukan pada sebuah ujung sebuah list, sedangkan penghapusan data dilakukan pada ujung yang lain. Data yang dihapus adalah data yang paling awal [4].

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/1ba5b821-4735-46c0-a46d-72e39bc5e00f)

Gambar di atas menunjukkan 5 elemen (A, B, C, D, E) dimasukkan secara berturut-turut dari belakang. Maka elemen A yang merupakan elemen pertama masuk sehingga menempati posisi paling depan, elemen E yang merupakan elemen terakhir masuk sehingga elemen E menempati posisi paling belakang [2].

Dalam istilah pemrograman, menempatkan item dalam antrian disebut enqueue, dan menghapus item dari antrian disebut dequeue. Berikut ini jenis dari antrian:

- Simple Queue
- Circular Queue
- Priority Queue
- Double Ended Queue [3].

Antrian adalah objek (struktur data abstrak - ADT) yang memungkinkan operasi berikut:

- Enqueue: Tambahkan elemen ke akhir antrian
- Dequeue: Hapus elemen dari depan antrian
- IsEmpty: Periksa apakah anytrian kosong
- IsFull : Periksa apakah antrian sudah penuh
- Peek   : Dapatkan nilai bagian depan antrian tanpa menghapusnya [3].


## Guided 

### 1. Guided 1: 

```C++
#include <iostream>

using namespace std;

const int maksimalQueue = 5; 
int front = 0; 
int back = 0;

string queueTeller[5]; 

bool isFull() { 
    if (back == maksimalQueue) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() { 
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { 
    if (isFull()) {
        cout << "Antrian Penuh" << endl;
    } else {
        if (isEmpty()) { 
            queueTeller[0] = data;
            front++;
            back++;
        } else { 
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { 
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { 
    return back;
}

void clearQueue() { 
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { 
    cout << "Data antrian teller: " << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```

Program di atas merupakan sebuah implementasi dari queue yang menggunakan array. Pertama, program di atas melakukan deklarasi variabel global seperti maksimalQueue, front, back, dan array queueTeller yang digunakan untuk menyimpan elemen-elemen antrian. Setelah itu terdapat beberapa fungsi. Fungsi isFull() digunakan untuk mengecek apakah queue penuh atau tidak. Lalu isEmpty() digunakan untuk mengecek apakah queue kosong atau tidak. Pengecekan tersebut didasarkan pada nilai back. Selanjutnya terdapat fungsi enqueueAntrian(string data) yang digunakan untuk menambahkan elemen baru ke dalam antrian. Apabila antrian penuh, maka akan menampilkan pesan "Antrian Penuh". Apabila tidak, maka elemen baru ditambahkan ke posisi back dalam array queueTeller. Kemudian fungsi dequeueAntrian(). Fungsi ini digunakan untuk menghapus elemen dari depan antrian. Semua elemen akan digeser ke kiri untuk mengisi posisi yang kosong. Selanjutnya fungsi countQueue() yang digunakan untuk mengembalikan jumlah elemen yang saat ini berada dalam antrian, yaitu nilai dari variabel back. Kemudian fungsi clearQueue(). Fungsi ini digunakan untuk mengosongkan seluruh antrian dengan mengatur ulang nilai front dan back, serta menghapus semua elemen dalam array. Setelah itu fungsi viewQueue(). Fungsi ini digunakan untuk menampilkan seluruh elemen yang ada dalam queue beserta nomor urutannya. Program akan mencetak pesan "(kosong) apabila suatu posisi dalam antrian kosong. Kemudian yang terakhir fungsi main(). Pada fungsi main() ini, kita menambahkan beberapa elemen ke dalam antrian menggunakan enqueueAntrian(), kemudian kita menampilkan antrian menggunakan viewQueue(), lanjut mencetak pesan "Jumlah antrian" yang jumlah elemen dihitung menggunakan countQueue(), lalu satu elemen dihapus menggunakan dequeueAntrian(), kemudian menampilkan antrian lagi, mencetak jumlah antrian kembali, dan kemudian kita mengosongkan antrian mengunakan clearqueue(), setelah itu kita tampilkan kembali dan terakhir kita menampilkan jumlah elemen lagi. 

#### Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/e0c43f54-95bb-4882-9e95-112b895a2767)

Dari output tersebut dapat kita ketahui, terdapat 5 antrian yang dimana 2 terisi yaitu Andi dan Maya sedangkan 3 sisanya kosong. Sehingga dapat dihitung jumlah antrian ada 2. Kemudian data antrian Andi dihapus, sehingga hanya tersisa Maya dan sekarang jumlah antrian menjadi tinggal 1. Lalu semua data antrian dikosongkan kemudian dihitung kembali jumlah antriannya dan didapatkan jumlah antrian saat ini 0.

#### Full code Screenshot:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/402aa948-b7bc-43f2-a9a5-ae5842e0216e)

Program di atas merupakan sebuah implementasi dari queue yang menggunakan array. 

## Unguided 

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

```C++
#include <iostream>
using namespace std;

// Struktur node untuk merepresentasikan elemen dalam linked list
struct Node {
    string data;
    Node* next;
    
    // Konstruktor untuk node baru
    Node(string value) : data(value), next(nullptr) {}
};

// Kelas Queue yang mengimplementasikan antrian menggunakan linked list
class Queue {
private:
    Node* front; // Pointer ke depan antrian
    Node* rear;  // Pointer ke belakang antrian

public:
    // Konstruktor
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor untuk membersihkan memori
    ~Queue() {
        clearQueue();
    }

    // Method untuk menambahkan elemen ke belakang antrian
    void enqueueAntrian(string data) {
        Node* newNode = new Node(data);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Method untuk menghapus elemen dari depan antrian
    void dequeueAntrian() {
        if (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
        } else {
            cout << "Antrian kosong" << endl;
        }
    }

    // Method untuk mengecek apakah antrian kosong
    bool isEmpty() {
        return front == nullptr;
    }

    // Method untuk membersihkan seluruh antrian
    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    // Method untuk menampilkan elemen-elemen dalam antrian
    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            cout << "Data antrian teller: " << endl;
            Node* current = front;
            int i = 1;
            while (current != nullptr) {
                cout << i++ << ". " << current->data << endl;
                current = current->next;
            }
        }
    }

    // Method untuk menghitung jumlah elemen dalam antrian
    int countQueue() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main() {
    Queue antrian;
    antrian.enqueueAntrian("Andi");
    antrian.enqueueAntrian("Maya");
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;
    antrian.dequeueAntrian();
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;
    antrian.clearQueue();
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;
    return 0;
}
```

Program di atas merupakan implementasi queue yang terdapat pada guided yang diubah dari array menjadi linked list. Dalam program ini, elemen-elemen dalam antrian disimpan menggunakan linked ist. Setiap elemen direpresentasikan oleh sebuah node, dan setiap node memiliki dua bagian, yaitu data yang menyimpan nilai elemen dan pointer ke node berikutnya dalam linked list. Sama seperti pada guided, program ini juga menggunakan operasi enqueue untuk menambahkan elemen baru ke belakang antrian, dequeue untuk menghapus elemen dari depan antrian, isEmpty untuk memeriksa apakah antrian kosong, viewQueue untuk menampilkan semua elemen dalam antrian, countQueue untuk menghitung jumlah elemen dalam antrian, dan clearQueue untuk menghapus semua elemen dalam antrian. Fungsi main pada program ini masih sama dengan yang ada pada guided.

#### Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/2f8a23c3-35a5-48dc-a82b-097501bf3537)

Dari output di atas kita dapat melihat tampilan dari antrian menjadi lebih rapi dan terstruktur. Untuk yang pertama data antrian teller ada 2 yaitu Andi dan Maya. Setelah itu data antrian dihapus 1 sehingga jumlahnya sisa 1 yaitu Maya. Lalu antrian dikosongkan sehingga jumlah antrian saat ini adalah 0.

#### Full code Screenshot:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/8beb343c-aab4-46bf-b509-b0699e005d83)

Program di atas merupakan implementasi dari queue yang diubah menjadi menggunakan linked list.

### 2.  Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
#include <iostream>
using namespace std;

// Struktur node untuk merepresentasikan elemen dalam linked list
struct Node {
    string nama;
    string nim;
    Node* next;
    
    // Konstruktor untuk node baru
    Node(string nama, string nim) : nama(nama), nim(nim), next(nullptr) {}
};

// Kelas Queue yang mengimplementasikan antrian menggunakan linked list
class Queue {
private:
    Node* front; // Pointer ke depan antrian
    Node* rear;  // Pointer ke belakang antrian

public:
    // Konstruktor
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor untuk membersihkan memori
    ~Queue() {
        clearQueue();
    }

    // Method untuk menambahkan elemen ke belakang antrian
    void enqueueAntrian(string nama, string nim) {
        Node* newNode = new Node(nama, nim);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Method untuk menghapus elemen dari depan antrian
    void dequeueAntrian() {
        if (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
            if (front == nullptr) {
                rear = nullptr;
            }
        } else {
            cout << "Antrian kosong" << endl;
        }
    }

    // Method untuk mengecek apakah antrian kosong
    bool isEmpty() {
        return front == nullptr;
    }

    // Method untuk membersihkan seluruh antrian
    void clearQueue() {
        while (!isEmpty()) {
            dequeueAntrian();
        }
    }

    // Method untuk menampilkan elemen-elemen dalam antrian
    void viewQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            cout << "Data antrian mahasiswa: " << endl;
            Node* current = front;
            int i = 1;
            while (current != nullptr) {
                cout << i++ << ". Nama: " << current->nama << ", NIM: " << current->nim << endl;
                current = current->next;
            }
        }
    }

    // Method untuk menghitung jumlah elemen dalam antrian
    int countQueue() {
        int count = 0;
        Node* current = front;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main() {
    Queue antrian;
    antrian.enqueueAntrian("Andi", "23100001");
    antrian.enqueueAntrian("Maya", "23100002");
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;
    antrian.dequeueAntrian();
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;
    antrian.clearQueue();
    antrian.viewQueue();
    cout << "Jumlah antrian = " << antrian.countQueue() << endl;
    return 0;
}
```

Program di atas merupakan implementasi queue yang menggunakan linked list dengan tambahan atribut Nama dan NIM Mahasiswa. Dalam program di atas, setiap node dalam linked list memiliki dua atribut tambahan, yaitu nama yang mewakili nama mahasiswa dan nim yang mewakili NIM mahasiswa. Masih sama dengan penjelasan sebelumnya, program ini juga menggunakan beberapa operasi queue, yaitu operasi enqueue untuk menambahkan elemen baru ke belakang antrian, dequeue untuk menghapus elemen dari depan antrian, isEmpty untuk memeriksa apakah antrian kosong, viewQueue untuk menampilkan semua elemen dalam antrian, countQueue untuk menghitung jumlah elemen dalam antrian, dan clearQueue untuk menghapus semua elemen dalam antrian. Fungsi main pada program ini juga masih sama dengan yang sebelumnya. Namun, pada fungsi enqueueAntrian dan viewQueue terdapat perbedaan dari program sebelumnya. Pada program ini, fungsi enqueueAntrian menerima dua parameter tambahan untuk menyimpan nama dan NIM mahasiswa saat menambahkan elemen baru ke dalam antrian. Sedangkan fungsi viewQueue diperbarui untuk menampilkan nama dan NIM mahasiswa dari setiap elemen dalam antrian.

#### Output:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/98850d4f-275c-4c40-ae10-58998c56c760)

Dari output di atas kita dapat melihat tampilan dari antrian menjadi lebih rapi dan terstruktur serta ditambah atribut nama serta NIM mahasiswa. Untuk nama mahasiswa masih sama yaitu Andi dan Maya. Lalu untuk NIM Andi saya buat 23100001 dan NIM Maya adalah 23100002. Sama seperti sebelumnya, yang pertama data antrian teller ada 2 yaitu Andi dengan NIM 23100001 dan Maya dengan NIM 23100002. Setelah itu data antrian dihapus 1 sehingga jumlahnya sisa 1 yaitu Maya dengan NIM 23100002. Lalu antrian dikosongkan sehingga jumlah antrian saat ini adalah 0.
  
#### Full code Screenshot:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/c341b64f-79e4-435e-b570-9dd23ee5ec0b)

Program di atas merupakan implementasi queue yang menggunakan linked list dengan tambahan atribut Nama dan NIM Mahasiswa.

## Kesimpulan
Ringkasan dan interpretasi pandangan saya dari hasil praktikum dan pembelajaran yang didapat yaitu:

- Hasil Praktikum

Hasil dari praktikum kedelapan ini, saya menjadi paham mengenai definisi dan konsep dari queue. Tak hanya itu, saya juga menjadi tau jenis-jenis operasi yang terdapat pada queue serta implementasinya pada program C++.  

- Pembelajaran yang didapat

Pada praktikum kedelapan ini, saya kembali mendapat pembelajaran yang berarti. Saya banyak belajar mengenai karakteristik queue serta implementasinya pada program C++. Dari praktikum delapan ini juga saya mendapat pembelajaran mengenai operasi-operasi yang terdapat pada queue dan juga implementasinya. Lalu mengenai laporan praktikum, saya tetap mengevaluasi laporan, mulai dari kode program, interpretasi, hingga pencarian dasar teori, dengan harapan dapat lebih baik dari minggu sebelumnya.

## Referensi
[1] M.B. Chaniago, C.K. Sastradipraja, Buku Ajar Algoritma dan Struktur Data. Bandung: Kaizen Media Publishing, 2022.

[2] M. Erkamim, S.Kom., M.Kom, dkk, Buku Ajar Algoritma dan Struktur Data. Indonesia: PT. Sonpedia Publishing Indonesia, 2024.

[3] Z. Musiafa, S.Kom., M.Kom., STRUKTUR DATA DAN IMPLEMENTASI ALGORITMA (SDIA) Pemrograman Python C C++ Java. Jakarta: Balai Pustaka, 2022.

[4] Dr. A.S. Nugroho, M.Eng, "Algoritma & Struktur Data Algoritma & Struktur Data."