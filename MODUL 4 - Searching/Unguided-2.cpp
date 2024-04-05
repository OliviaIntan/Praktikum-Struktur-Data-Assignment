#include <iostream>
#include <string>

using namespace std;

// Fungsi untuk mengecek apakah sebuah karakter adalah huruf vokal atau bukan
bool isVowel(char c) {
    // Mengubah huruf kecil menjadi huruf besar untuk memudahkan pengecekan
    c = toupper(c);
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat
int countVowels(const string &sentence) {
    int count = 0;
    for (char c : sentence) {
        if (isalpha(c) && isVowel(c)) {
            count++;
        }
    }
    return count;
}

int main() {
    string sentence;

    cout << "Masukkan kalimat: ";
    getline(cin, sentence);

    int vowelCount = countVowels(sentence);

    cout << "Jumlah huruf vokal dalam kalimat tersebut adalah: " << vowelCount << endl;

    return 0;
}