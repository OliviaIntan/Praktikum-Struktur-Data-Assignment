#include <iostream>

using namespace std;

int main() {
    int n = 6;
    int data[n] = {1, 2, 3, 4, 5, 5};
    int cari = 5; 
    int ketemu = false;
    int i;

    for (i = 0; i < n; i++) {
        if (data[i] == cari) {
            ketemu = true;
            break;
        }
    }

    if (ketemu) {
        cout << "Angka " << cari << " berada pada index ke-" << i << endl;
    } else {
        cout << "Angka tidak ditemukan" << endl;
    }
    return 0;
}
    
    