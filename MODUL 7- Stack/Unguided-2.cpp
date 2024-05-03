#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Fungsi untuk membalikkan sebuah kata
string reverseWord(string word) {
    string reversedWord = "";
    for (int i = word.length() - 1; i >= 0; i--) {
        reversedWord += word[i];
    }
    return reversedWord;
}

// Fungsi untuk membalikkan kalimat menggunakan stack
string reverseSentence(string sentence) {
    stack<string> wordStack;
    string word, reversedSentence;

    // Memisahkan kalimat menjadi kata-kata dan dimasukkan ke dalam stack
    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] != ' ') {
            word += sentence[i];
        } else {
            wordStack.push(word);
            word = "";
        }
    }
    // Memasukkan kata terakhir ke dalam stack
    wordStack.push(word);

    // Membuat kalimat terbalik dari stack
    while (!wordStack.empty()) {
        reversedSentence += reverseWord(wordStack.top()) + " ";
        wordStack.pop();
    }

    return reversedSentence;
}

int main() {
    string sentence, reversedSentence;
    cout << "Masukkan kalimat: ";
    getline(cin, sentence);

    // Memeriksa apakah kalimat memiliki minimal 3 kata
    int spaceCount = 0;
    for (char c : sentence) {
        if (c == ' ') {
            spaceCount++;
        }
    }
    if (spaceCount < 2) {
        cout << "Kalimat harus memiliki minimal 3 kata." << endl;
        return 1;
    }

    reversedSentence = reverseSentence(sentence);

    cout << "Kalimat terbalik: " << reversedSentence << endl;

    return 0;
}