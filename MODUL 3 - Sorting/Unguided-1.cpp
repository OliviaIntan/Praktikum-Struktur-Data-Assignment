#include <iostream>

using namespace std;

void selectionSort(double arr[], int n) {
    int i, j, maxIndex;
    double temp;
    
    for (i = 0; i < n - 1; i++) {
        maxIndex = i;
        
        // Cari indeks elemen maksimum dari sisa array yang belum diurutkan
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        
        // Tukar elemen maksimum dengan elemen pertama dari sisa array yang belum diurutkan
        temp = arr[maxIndex];
        arr[maxIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArrayWithCommas(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    const int numStudents = 5;
    double ips[numStudents] = {3.8, 2.9, 3.3, 4.0, 2.4};

    cout << "IPS sebelum diurutkan: ";
    printArrayWithCommas(ips, numStudents);

    selectionSort(ips, numStudents);

    cout << "IPS setelah diurutkan dari yang terbesar hingga terkecil: ";
    printArrayWithCommas(ips, numStudents);

    return 0;
}