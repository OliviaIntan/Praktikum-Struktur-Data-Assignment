#include <iostream>

using namespace std;

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int n = sizeof(data) / sizeof(data[0]); // Menghitung jumlah elemen dalam array data
    int cari = 4;
    int count = 0;

    // Algoritma Sequential Search untuk mencari angka 4 dalam data
    for (int i = 0; i < n; ++i) {
        if(data[i] == cari) {
            count++;
        }
    }

    cout << "Jumlah angka 4 dalam data adalah: " << count << endl;

    return 0;
}