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