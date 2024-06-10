#include <iostream>

using namespace std;

int faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * faktorial(n-1);
}

int main() {
    int n;
    cout << "Masukkan bilangan bulat:" << endl;
    cin >> n; 
    cout << "Faktorial dari " << n << ": " << faktorial(n) << endl;
}