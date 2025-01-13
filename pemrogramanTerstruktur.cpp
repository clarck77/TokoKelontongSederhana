#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip> 

using namespace std;

// deklarasi struct barang
struct Barang {
    string kode;
    string nama;
    string satuan;
    int harga;
};
// deklarasi struct barang - selesai

// string barang pertama kali yang akan muncul
vector<Barang> barang = {
    {"22001", "Beras_Bulog", "KG", 25000},
    {"22002", "Gula_Pasir", "KG", 5000},
    {"22003", "Minyak", "Liter", 15000},
    {"22004", "Susu_Dancow", "Gram", 20000},
    {"22005", "Telur_Ayam", "KG", 20000}
};
// string barang pertama kali yang akan muncul - selesai

//void hanyaTampilkanData()
void tampilDataBarang() {
    cout << "|=============================================|" << endl;
    cout << "| No | Kode  | Nama Barang   | Satuan | Harga |" << endl;
    cout << "|=============================================|" << endl;
    for (size_t i = 0; i < barang.size(); ++i) {
        cout << "|" << setw(2) << i + 1 << " | " << setw(6) << barang[i].kode
             << "|" << setw(12) << barang[i].nama
             << "|" << setw(6) << barang[i].satuan
             << "|" << setw(6) << barang[i].harga << "|" << endl;
    }
    cout << "|===========================================|" << endl;
}
//void hanyaTampilkanData() - Selesai
