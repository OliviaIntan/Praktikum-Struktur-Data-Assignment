#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Input ukuran array tiga dimensi dari user
    int x_size, y_size, z_size;
    cout << "Masukkan ukuran array tiga dimensi (x y z): ";
    cin >> x_size >> y_size >> z_size;

    // Deklarasi array tiga dimensi sesuai dengan ukuran yang dimasukkan oleh pengguna
    vector<vector<vector<int>>> arr(x_size, vector<vector<int>>(y_size, vector<int>(z_size)));

    // Input elemen array dari user
    cout << "Masukkan elemen-elemen array:\n";
    for (int x = 0; x < x_size; ++x) {
        for (int y = 0; y < y_size; ++y) {
            for (int z = 0; z < z_size; ++z) {
                cout << "Array[" << x << "][" << y << "][" << z << "]: ";
                cin >> arr[x][y][z];
            }
        }
    }

    // Menampilkan elemen-elemen array
    cout << "Data array:\n";
    for (int x = 0; x < x_size; ++x) {
        for (int y = 0; y < y_size; ++y) {
            for (int z = 0; z < z_size; ++z) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}