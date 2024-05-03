#include <iostream>
#include <stack>
#include <string>
#include <locale>

using namespace std;

// Menghapus karakter non-huruf dari string dan mengubah huruf menjadi lowercase
string preprocessString(const string &s) {
    string result;
    for (char c : s) {
        if (isalpha(c)) {
            result += tolower(c); // Mengubah huruf menjadi lowercase
        }
    }
    return result;
}

// Memeriksa apakah kalimat adalah palindrom atau bukan
bool isPalindrome(const string &s) {
    stack<char> charStack;
    string processedString = preprocessString(s);

    // Memasukkan setengah karakter pertama dari kalimat ke dalam stack
    int halfLength = processedString.length() / 2;
    for (int i = 0; i < halfLength; ++i) {
        charStack.push(processedString[i]);
    }

    // Membandingkan setengah karakter kedua dengan karakter dalam stack
    int indexToCompare = (processedString.length() + 1) / 2;
    for (int i = indexToCompare; i < processedString.length(); ++i) {
        if (processedString[i] != charStack.top()) {
            return false; // Tidak palindrom
        }
        charStack.pop();
    }

    return true; // Palindrom
}

int main() {
    string input;
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}