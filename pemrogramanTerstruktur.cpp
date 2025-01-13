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

//void tambahDataBarang()
void tambahDataBarang() {
    Barang baru;
    cout << "Masukkan Kode Barang: ";
    cin >> baru.kode;
    cout << "Masukkan Nama Barang: ";
    cin >> baru.nama;
    cout << "Masukkan Satuan Barang: ";
    cin >> baru.satuan;
    cout << "Masukkan Harga Barang: ";
    while (!(cin >> baru.harga)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input harus berupa angka. Masukkan Harga Barang: ";
    }
    barang.push_back(baru);
    cout << "Barang berhasil ditambahkan!" << endl;
}
//void tambahDataBarang() - Selesai

//void updateDataBarang()
void updateDataBarang() {
    string kode;
    cout << "Masukkan Kode Barang yang akan diupdate: ";
    cin >> kode;
    for (auto &b : barang) {
        if (b.kode == kode) {
            cout << "Masukkan Nama Barang baru: ";
            cin >> b.nama;
            cout << "Masukkan Satuan Barang baru: ";
            cin >> b.satuan;
            cout << "Masukkan Harga Barang baru: ";
            while (!(cin >> b.harga)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input harus berupa angka. Masukkan Harga Barang baru: ";
            }
            cout << "Barang berhasil diperbarui!" << endl;
            return;
        }
    }
    cout << "Barang tidak ditemukan!" << endl;
}
//void updateDataBarang () - Selesai

//void hapusDataBarang()
void hapusDataBarang() {
    string kode;
    cout << "Masukkan Kode Barang yang akan dihapus: ";
    cin >> kode;
    for (size_t i = 0; i < barang.size(); ++i) {
        if (barang[i].kode == kode) {
            barang.erase(barang.begin() + i);
            cout << "Barang berhasil dihapus!" << endl;
            return;
        }
    }
    cout << "Barang tidak ditemukan!" << endl;
}
//void hapusDataBarang() - Selesai