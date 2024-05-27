#include <iostream>

using namespace std;

int faktorial_helper(int n);

int faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * faktorial_helper(n - 1);
}

int faktorial_helper(int n) {
    return faktorial(n);
}

int main() {
    int n;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;
    cout << "Faktorial dari " << n << " adalah: " << faktorial(n) << endl;
    return 0;
}




