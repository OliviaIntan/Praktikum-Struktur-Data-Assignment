#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int size;
    cout << "Masukkan panjang array: ";
    cin >> size;

    // Meminta pengguna untuk memasukkan elemen-elemen array
    vector<int> arr(size);
    cout << "Masukkan " << size << " angka:\n";
    for (int i = 0; i < size; ++i) {
        cout << "Array[" << i << "]: ";
        cin >> arr[i];
    }

    // Menampilkan menu
    cout << "\nMenu:\n";
    cout << "1. Cari nilai maksimum\n";
    cout << "2. Cari nilai minimum\n";
    cout << "3. Cari nilai rata-rata\n";
    cout << "Pilih menu (1/2/3): ";

    int choice;
    cin >> choice;

    // Memilih opsi sesuai dengan input pengguna
    switch (choice) {
        case 1: {
            int max_val = *max_element(arr.begin(), arr.end());
            cout << "Nilai maksimum: " << max_val << endl;
            break;
        }
        case 2: {
            int min_val = *min_element(arr.begin(), arr.end());
            cout << "Nilai minimum: " << min_val << endl;
            break;
        }
        case 3: {
            double sum = accumulate(arr.begin(), arr.end(), 0);
            double average = sum / size;
            cout << "Nilai rata-rata: " << average << endl;
            break;
        }
        default:
            cout << "Pilihan tidak valid.\n";
    }

    return 0;
}