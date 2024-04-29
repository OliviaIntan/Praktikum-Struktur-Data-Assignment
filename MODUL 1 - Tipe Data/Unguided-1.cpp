#include <iostream>
#include <iostream>

// Fungsi untuk menghitung luas persegi
double hitungLuasPersegi(double sisi) {
    return sisi * sisi;
}

// Fungsi untuk menghitung volume kubus
double hitungVolumeKubus(double sisi) {
    return sisi * sisi * sisi;
}

int main() {
    double sisiPersegi = 5.0;
    double sisiKubus = 4.0;

    // Menggunakan fungsi hitungLuasPersegi
    double luasPersegi = hitungLuasPersegi(sisiPersegi);
    std::cout << "Luas persegi dengan sisi " << sisiPersegi << " adalah: " << luasPersegi << std::endl;

    // Menggunakan fungsi hitungVolumeKubus
    double volumeKubus = hitungVolumeKubus(sisiKubus);
    std::cout << "Volume kubus dengan sisi " << sisiKubus << " adalah: " << volumeKubus << std::endl;

    return 0;
}