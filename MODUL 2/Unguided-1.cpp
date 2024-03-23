#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Input panjang array dari user
    int length;
    cout << "Masukkan panjang array: ";
    cin >> length;

    // Deklarasi array sesuai panjang yang dimasukkan
    vector<int> arr(length);

    // Input elemen array dari user
    cout << "Masukkan " << length << " angka:\n";
    for (int i = 0; i < length; ++i) {
        cout << "Data array ke-" << (i + 1) << ": ";
        cin >> arr[i];
    }

    // Menampilkan data array
    cout << "Data Array :";
    for (int i = 0; i < length; ++i) {
        cout << " " << arr[i];
        if (i != length - 1) {
            cout << " ";
        }
    }
    cout << endl;

    // Menampilkan nomor genap
    cout << "Nomor Genap  :";
    bool isFirstEven = true;
    for (int i = 0; i < length; ++i) {
        if (arr[i] % 2 == 0) {
            if (!isFirstEven) {
                cout << ",";
            }
            cout << " " << arr[i];
            isFirstEven = false;
        }
    }
    cout << endl;

    // Menampilkan nomor ganjil
    cout << "Nomor Ganjil :";
    bool isFirstOdd = true;
    for (int i = 0; i < length; ++i) {
        if (arr[i] % 2 != 0) {
            if (!isFirstOdd) {
                cout << ",";
            }
            cout << " " << arr[i];
            isFirstOdd = false;
        }
    }
    cout << endl;

    return 0;
}