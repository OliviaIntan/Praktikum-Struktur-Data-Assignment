#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Masukkan jumlah karakter (n): ";
    cin >> n;

    vector<char> characters(n);

    for (int i = 0; i < n; ++i) {
        cout << "Karakter ke-" << i + 1 << ": ";
        cin >> characters[i];
    }

    cout << "Urutan karakter sebelum sorting: " << endl;
    for (char character : characters) {
        cout << character << "\t";
    }
    cout << endl;

    // Sorting secara ascending
    sort(characters.begin(), characters.end());
    cout << "Urutan karakter setelah ascending sort: " << endl;
    for (char character : characters) {
        cout << character << "\t";
    }
    cout << endl;

    // Sorting secara descending
    sort(characters.rbegin(), characters.rend());
    cout << "Urutan karakter setelah descending sort: " << endl;
    for (char character : characters) {
        cout << character << "\t";
    }
    cout << endl;

    return 0;
}