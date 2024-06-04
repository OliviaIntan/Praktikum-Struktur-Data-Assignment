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