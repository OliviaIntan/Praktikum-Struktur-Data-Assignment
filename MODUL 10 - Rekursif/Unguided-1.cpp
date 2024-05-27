#include <iostream>

using namespace std;

// Fungsi rekursif untuk menghitung faktorial
int faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * faktorial(n - 1);
}

int main() {
    int n;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;
    cout << "Faktorial dari " << n << " adalah: " << faktorial(n) << endl;
    return 0;
}