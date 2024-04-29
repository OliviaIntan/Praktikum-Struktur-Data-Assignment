#include <iostream>
#include <map>
#include <string>
#include <sstream>

int main() {
    std::string kalimat;
    std::cout << "Masukkan sebuah kalimat: ";
    std::getline(std::cin, kalimat);

    // Menggunakan stringstream untuk membagi kalimat menjadi kata-kata
    std::stringstream ss(kalimat);
    std::string kata;
    std::map<std::string, int> kemunculan;

    // Menghitung kemunculan setiap kata
    while (ss >> kata) {
        kemunculan[kata]++;
    }

    // Mencetak hasil kemunculan setiap kata
    std::cout << "Jumlah kemunculan setiap kata dalam kalimat:\n";
    for (const auto& pair : kemunculan) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}