#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    // Inisialisasi variabel NIM
    int OliviaIntanPuspita_2311110006 = 2311110006;
    
    int jumlahSimpul;
    cout << "Silakan masukkan jumlah simpul : ";
    cin >> jumlahSimpul;

    vector<string> simpul(jumlahSimpul);
    cout << "Silakan masukkan nama simpul" << endl;
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> simpul[i];
    }

    vector<vector<int>> busur(jumlahSimpul, vector<int>(jumlahSimpul, 0));
    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < jumlahSimpul; ++i) {
        for (int j = 0; j < jumlahSimpul; ++j) {
            cout << simpul[i] << "--> " << simpul[j] << " = ";
            cin >> busur[i][j];
        }
    }

    cout << "\n";
    cout << setw(10) << " ";
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << setw(10) << simpul[i];
    }
    cout << endl;
    for (int i = 0; i < jumlahSimpul; ++i) {
        cout << setw(10) << simpul[i];
        for (int j = 0; j < jumlahSimpul; ++j) {
            cout << setw(10) << busur[i][j];
        }
        cout << endl;
    }

    return 0;
}