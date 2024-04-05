#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Fungsi untuk mencari sebuah huruf pada sebuah string menggunakan Binary Search
int binarySearch(const string &sentence, char target) {
    int left = 0;
    int right = sentence.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Jika huruf pada indeks tengah adalah target, kembalikan indeks tengah
        if (sentence[mid] == target)
            return mid;
        // Jika huruf pada indeks tengah kurang dari target, cari di sebelah kanan
        else if (sentence[mid] < target)
            left = mid + 1;
        // Jika huruf pada indeks tengah lebih dari target, cari di sebelah kiri
        else
            right = mid - 1;
    }

    // Jika tidak menemukan huruf, kembalikan -1
    return -1;
}

int main() {
    string input;
    char target;

    cout << "Masukkan kalimat: ";
    getline(cin, input);

    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> target;

    // Memisahkan kalimat menjadi kata-kata
    stringstream ss(input);
    string word;
    vector<string> words;
    while (ss >> word) {
        words.push_back(word);
    }

    // Mencari huruf dalam setiap kata dan menampilkan hasil
    for (int i = 0; i < words.size(); ++i) {
        int index = binarySearch(words[i], target);
        if (index != -1) {
            cout << "Huruf '" << target << "' ditemukan pada indeks " << index << " dalam kata \"" << words[i] << "\"" << endl;
            // Menghitung indeks absolut huruf dalam kalimat
            int absolute_index = index;
            for (int j = 0; j < i; ++j) {
                absolute_index += words[j].size(); // Tidak perlu menambahkan 1 karena tidak ada spasi
            }
            cout << "Huruf '" << target << "' ditemukan pada indeks absolut " << absolute_index << " dalam kalimat." << endl;
            return 0;
        }
    }

    cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat." << endl;

    return 0;
}