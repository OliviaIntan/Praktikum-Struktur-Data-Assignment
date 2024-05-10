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