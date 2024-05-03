# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Olivia Intan Puspita</p>

## Dasar Teori
Stack digunakan secara sangat luas dalam computing. Interupsi program dan sifat multi-tasking komputer modern bergantung salah satunya pada konsep stack ini. Konsep stack sangat umum dalam literatur ilmu komputer dan banyak digunakan di berbagai penyelesaian masalah. Stack juga ditemui dalam kehidupan sehari-hari [1]. Perhatikan gambar abstrak stack di bawah ini.

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/a5f2ca1b-8c56-4183-9ce2-b69140b35f02)

Stack, diterjemahkan menjadi tumpukan, digunakan untuk menyimpan data sedemikian hingga item terakhir yang disisipkan adalah item pertama. Stack adalah sebuah struktur data linear di mana item baru ditambahkan dan diambil dari ujung yang sama, yakni puncak tumpukan (top of stack). Di bagian paling bawah adalah base atau dasarnya [1].

Stack merupakan struktur data yang bertumpuk dengan  konsep urutan yang disebut dengan LIFO (Last In First Out). Konsep LIFO tersebut memiliki beberapa proses. Pertama, proses push yang diibaratkan jika kita menyimpan buku di atas tumpukan buku. Kedua yaitu proses pop yang diibaratkan dengan pengambilan tumpukan buku pada tumpukan yang paling atas atau yang dapat disebut dengan top of the stack [2]. 

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/c2141659-35a7-4008-8892-0ee8fdafaf1f)

Gambar di atas menggambarkan bagaimana stack bekerja [2].

Tumpukan adalah sekumpulan elemen-elemen data yang disimpan dalam satu laju linier. Kumpulan elemen-elemen data hanya boleh diakses pada satu lokasi saja yaitu pada posisi Atas (TOP) tumpukan. Tumpukan disebut juga Push Down Stack yaitu penambahan elemen bary (PUSH) dan penghapusan elemen dari tumpukan (POP). Sistem pengaksesan pada tumpukan menggunakan sistem elemen yang terakhir masuk itu akan pertama dikeluarkan dari tumpukan [3].

Berikut adalah beberapa perintah yang ada di class stack:
1. Stack(): membuat stack baru yang kosong.
2. isEmpty: mengembalikan nilai boolean yang menunjukkan apakah stack itu kosong.
3. length(): mengembalikan banyaknya item di dalam stack.
4. pop(): mengembalikan nilai dari item yang paling atas dan menghapusnya, jika stack nya tidak kosong.
5. peek(): mengembalikan nilai dario item yang paling atas, tanpa menghapusnya.
6. push(item): menambah item ke puncak stack [1].

## Guided 

### 1. Guided 1

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";

    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    cetakArrayBuku();

    return 0;
}
```
Program di atas merupakan program yang mengimplementasikan struktur data stack menggunakan array. Untuk yang pertama program tersebut mendeklarasikan array dan variabel. 'arrayBuku[5]' digunakan untuk menyimpan data dengan ukuran 5. Selanjutnya 'maksimal' yang merupakan variabel yang menunjukkan kapasitas maksimum stack. Lalu 'top' yang menunjukkan posisi puncak dari stack. Selanjutnya terdapat beberapa fungsi yang digunakan pada program di atas. Fungsi isFull() adalah fungsi untuk mengecek apakah stack sudah penuh atau tidak. Fungsi ini mengembalikan true/1 jika stack sudah penuh dan false/0 jika tidak. Kemudian fungsi isEmpty() yang berfungsi untuk mengecek apakah stack kosong atau tidak. Sama dengan fungsi isFull(), fungsi ini juga akan mengembalikan true/1 jika stack kosong dan false/0 jika tidak. Selanjutnya fungsi pushArrayBuku(string data) yang digunakan untuk menambahkan data baru ke dalam stack (arrayBuku). Apabila stack penuh, maka akan mencetak pesan "Data telah penuh". Lalu fungsi popArrayBuku(). Fungsi ini menghapus elemen teratas dari tumpukan, jika tumpukan tidak kosong elemen di indeks 'top-1' dihapus. Jika stack kosong, maka akan mencetak pesan "Tidak ada data yang dihapus". Selanjutnya fungsi peekArrayBuku(int posisi) untuk melihat data di posisi tertentu dalam stack. Apabila stack kosong, maka akan mencetak pesan "Tidak ada data yang bisa dilihat". Kemudian fungsi countStack() yang akan mengembalikan jumlah elemen dalam stack. Lalu fungsi changeArrayBuku(int posisi, string data) yang berfungsi untuk mengubah data pada posisi tertentu dengan data baru yang diinginkan. Apabila posisi melebihi jumlah elemen dalam stack, maka akan mencetak pesan "Posisi melebihi data yang ada". Selanjutnya fungsi destroyArraybuku() yang berfungsi untuk menghapus semua data dalam stack. Terakhir fungsi cetakArrayBuku(), sesuai namanya fungsi ini digunakan untuk mencetak seluruh data dalam stack, dimulai dari puncak (top) hingga dasar stack. Apabila stack kosong, maka akan mencetak pesan "Tidak ada data yang dicetak". Selanjutnya, program menjalankan program utama atau main(). Pada main(), dilakukan pengujian terhadap fungsi-fungsi sesuai dengan permintaan yang telah didefinisikan. Setiap langkah dilakukan dengan memanggil fungsi-fungsi yang sesuai dan mencetak hasilnya.

#### Output:

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/6a229b03-b052-497b-9185-9b849574425a)

Dari output tersebut dapat kita ketahui bahwa, yang pertama kita menambahkan elemen ke dalam tumpukan sebanyak 4, yaitu "Kalkulus", "Struktur Data", "Matematika Diskrit", "Dasar Multimedia", dan "Inggris". Setelah itu buku di cetak. Kemudian kita melakukan pengecekan apakah tumpukan sudah penuh, lalu program mengembalikan 1 yang berarti tumpukan sudah penuh. Lanjut kita mengecek apakah tumpukan kosong atau tidak, kemudian program mengembalikan 0 yang berarti tumpukan tidak kosong. Setelah itu kita melihat elemen pada posisi ke-2, dan didapatkan hasil yaitu "Matematika Diskrit". Lalu kita menghapus satu elemen. Selanjutnya jumlah elemen dalam tumpukan dihitung, didapatkan hasilnya adalah 4. Kemudian kita mengubah elemen pada posisi ke-2 menjadi "Bahasa Jerman". Setelah itu kita mencetak elemen-elemen dari tumpukan. Kemudian semua elemen dari tumpukan dihapus. Dan yang terakhir tidak ada elemen yang dicetak karena tumpukan kosong.

#### Full code Screenshot:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/c07f0514-6972-4144-8936-f10833423554)

## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
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
```
Program di atas merupakan program untuk menentukan apakah kalimat yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom sendiri adalah sebutan untuk kalimat yang apabila dibaca dari depan maupun belakang akan sama. Cara kerja program untuk yang pertama dimulai dari fungsi 'preprocessString'. Fungsi ini digunakan untuk membersihkan string dari karakter non-huruf dan mengubah semua huruf menjadi huruf kecil. Dalam fungsi tersebut terdapat parameter 's' yang merupakan string input yang akan diproses. Iterasi pada program ini dilakukan pada setiap karakter dari string input 's'. Apabila karakter tersebut adalah huruf yang disebut isalpha(c), maka karakter tersebut akan ditambahkan ke string result setelah diubah menjadi huruf kecil yang disebut tolower(c). Setelah proses iterasi selesai, string result yang telah diproses akan dikembalikan sebagai output. Kemudian dilanjut dengan fungsi kedua yaitu isPalindrome(const string &s). Fungsi ini berfungsi untuk memeriksa apakah sebuah kalimat merupakan palindrom atau tidak. Fungsi ini menggunakan sebuah stack (stack<char> charStack) untuk membantu dalam memeriksa palindrom. String input s akan diproses terlebih dahulu menggunakan fungsi preprocessString untuk membersihkan dan merubah huruf menjadi huruf kecil. Jadi, setengah karakter pertama dari kalimat yang telah diproses akan dimasukkan ke dalam stack. Setelah itu karakter-karakter setengah kedua dari kalimat akan dibandingkan dengan karakter-karakter yang diambil dari stack. Apabila semua karakter cocok, maka string tersebut dianggap sebagai palindrom. Namun, apabila ada perbedaan antara karakter-karakter tersebut, maka fungsi akan mengembalikan nilai false yang menunjukkan bahwa kalimat tersebut bukan palindrom. Selanjutnya yaitu main(). Di dalam main(), pengguna diminta untuk memasukkan sebuah kalimat menggunakan getline(cin, input). Kalimat yang dimasukkan kemudian akan diproses menggunakan fungsi isPalindrome untuk memeriksa apakah kalimat tersebut adalah palindrom atau tidak. Hasil dari pengecekan akan ditampilkan melalui cout sesuai dengan pesan yang sudah dibuat.

#### Output:
- Kalimat Polindrom

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/181e1b70-4a7b-4ae3-bc95-7213f1a3849f)

Dari output tersebut dapat kita ketahui bahwa, saya memasukkan kalimat 'Level' untuk mengecek apakah kalimat tersebut palindrom atau bukan. Setelah diinputkan dan program dijalankan, ternyata hasilnya kalimat 'Level' termasuk palindrom. Jika kita analisa manual, hal ini memang benar karena apabila kalimat tersebut dibalik, maka bacanya akan tetap 'Level'.

- Kalimat bukan Polindrom

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/e65bbc4f-c7b0-4310-985c-3709259b0d89)

Dari output tersebut dapat kita ketahui bahwa, saya memasukkan kalimat 'Tingkat' untuk mengecek apakah kalimat tersebut palindrom atau bukan. Setelah diinputkan dan program dijalankan, ternyata hasilnya kalimat 'Tingkat' bukan termasuk palindrom. Jika kita analisa manual, hal ini memang benar karena apabila kelimat tersebut dibalik, maka bacanya menjadi "takgniT", yang berarti ini tidak sama.

#### Full code Screenshot:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/6245a5a2-fbb8-4fe4-974a-18aa361bb1c7)

### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat? 

```C++
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
```
Program di atas adalah sebuah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata, yang dimana kalimat diinputkan menggunakan input user. Untuk yang pertama, program meminta kita untuk memasukkan sebuah kalimat melalui fungsi getline(cin, sentence). Dimana kalimat yang kita masukkan disimpan dalam variabel sentence. Selanjutnya fungsi reverseWord() yang digunakan untuk membalikkan sebuah kata. Fungsi ini mengambil kata dan mengembalikan kata tersebut dalam kebalikan urutannya. Fungsi reverseSentence() digunakan untuk membalikkan urutan kata-kata dalam kalimat menggunakan stack. Kalimat dimasukkan ke dalam stack dengan memisahkan kata-kata menggunakan spasi. Setiap kata dikeluarkan dari stack dan dibalik urutannya, kemudian digabungkan kembali untuk membentuk kalimat terbalik. Tetapi sebelum membalikkan kalimat, program akan memastikan terlebih dahulu bahwa kalimat memiliki minimal 3 kata. Hal ini dilakukan dengan menghitung jumlah spasi dalam kalimat. Jika jumlah spasi kurang dari 2 (artinya hanya terdapat maksimal 2 kata), maka program akan mencetak pesan "Kalimat harus memiliki minimal 3 kata." dan keluar dengan menggunakan return 1;. Namun, jika kalimat memenuhi syarat yaitu minimal 3 kata, maka program akan membalikkan urutan kata-kata dalam kalimat menggunakan fungsi reverseSentence(). Hasil dari pembalikan kata-kata tersebut kemudian dicetak sebagai "Kalimat terbalik".

#### Output:
- Jumlah kata kurang dari 3

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/3d53c314-fa4d-44ff-b679-afd23d37f688)

Dari output tersebut dapat kita ketahui bahwa, kalimat yang dimasukkan adalah 'Sains Data' yang dimana kalimat tersebut berjumlah 2 kata. Ini artinya kalimat tersebut tidak memenuhi syarat, sehingga program tidak dapat membalikkan kalimat dan mencetak pesan yang ada pada gambar tersebut.

- Jumlah kata 3 atau lebih dari 3

![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/548701aa-a0cc-466a-b0e7-39605e50bb4e)

Dari output tersebut dapat kita ketahui bahwa, kalimat yang dimasukkan adalah 'Program Studi Sains Data' yang dimana kalimat tersebut berjumlah 4 kata. Ini artinya kalimat tersebut telah memenuhi syarat, sehingga program membalikkan kalimat serta urutan kata-katanya. 

#### Full code Screenshot:
![image](https://github.com/OliviaIntan/Praktikum-Struktur-Data-Assignment/assets/162260430/628b6a9e-24ff-401d-8ac7-4dff7766f192)

## Kesimpulan
Ringkasan dan interpretasi pandangan saya dari hasil praktikum dan pembelajaran yang didapat yaitu:
- Hasil Praktikum

Hasil dari praktikum ketujuh ini, saya menjadi paham mengenai konsep stack pada struktur data dan algoritma. Selain itu, saya juga dapat mengimplementasikan operasi-operasi pada stack ke dalam program C++ serta dapat memecahkan permasalahan dengan solusi stack. 

- Pembelajaran yang didapat

Pada praktikum ketujuh ini, saya mendapat pembelajaran yang banyak dan berarti. Saya banyak belajar mengenai karakteristik stack serta implementasinya pada program C++. Kemudian tidak bisa dilupakan juga mengenai adanya laporan praktikum di setiap minggunya. Tentu rasa bosan dan malas ada, namun ini adalah sebuah tantangan kepada diri saya sendiri untuk dapat bangun belajar dan mengerjakan laporan sehingga tidak ada waktu yang terbuang sia-sia. Saya juga tetap mengevaluasi laporan mulai dari kode program, interpretasi, hingga pencarian sumber, dengan harapan agar terus lebih baik di setiap minggunya.

## Referensi
[1] F. Suryawan, dkk. Modul Praktikum Algoritma & Struktur Data Versi 4.3. Jawa Tengah: Muhammadiyah University Press, 2020.

[2] G. M. Putri, K. A. D. Pradja, M. B. Azizi, P. Nurwahid, A. S. Perdana, and M. ., “Implementasi Stack dan Array pada Pengurutan Lagu dengan Metode Selection Sort”, JTEKSIS, vol. 6, no. 2, pp. 286-296, Apr. 2024.

[3] J. Nasir, S.Kom., M.Kom., dkk. Algoritma dan Struktur Data dengan Pemograman Pascal dan Phyton. Padang: CV. Gita Lentera , 2024.