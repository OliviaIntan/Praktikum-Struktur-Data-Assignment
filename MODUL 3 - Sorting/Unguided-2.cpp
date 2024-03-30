#include <iostream>
#include <string>

using namespace std;

void bubbleSort(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Tukar elemen jika elemen saat ini lebih besar dari elemen berikutnya
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArrayWithCommas(string arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    const int numResidents = 10;
    string residents[numResidents] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

    cout << "Nama warga sebelum diurutkan: ";
    printArrayWithCommas(residents, numResidents);

    bubbleSort(residents, numResidents);

    cout << "Nama warga setelah diurutkan sesuai alfabet: ";
    printArrayWithCommas(residents, numResidents);

    return 0;
}