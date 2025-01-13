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

//void menuKasir()
void menuAdmin(); // Deklarasi awal

void menuKasir() {
    int pilihan;
    vector<pair<Barang, int>> keranjang;

    do {
        cout << "|===============================|" << endl;
        cout << "|         -MENU KASIR-          |" << endl;
        cout << "|===============================|" << endl;
        cout << "| 1. Lihat Barang               |" << endl;
        cout << "| 2. Tambah ke Keranjang        |" << endl;
        cout << "| 3. Checkout                   |" << endl;
        cout << "| 4. Kembali ke Menu Utama      |" << endl;
        cout << "|===============================|" << endl;
        cout << "| Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tampilDataBarang();
            break;
        case 2: {
            string kode;
            int jumlah;
            cout << "Masukkan Kode Barang: ";
            cin >> kode;
            cout << "Masukkan Jumlah: ";
            while (!(cin >> jumlah)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input harus berupa angka. Masukkan Jumlah: ";
            }

            bool ditemukan = false;
            for (const auto &b : barang) {
                if (b.kode == kode) {
                    keranjang.push_back({b, jumlah});
                    cout << "Barang berhasil ditambahkan ke keranjang!" << endl;
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan) {
                cout << "Barang tidak ditemukan!" << endl;
            }
            break;
        }
        case 3: {
            int total = 0;
            cout << "\n|===========================================|" << endl;
            cout << "| Nama Barang   | Jumlah | Harga  | Subtotal  |" << endl;
            cout << "|=============================================|" << endl;
            for (const auto &item : keranjang) {
                int subtotal = item.first.harga * item.second;
                total += subtotal;
                cout << " | " << setw(12) << item.first.nama
                     << " | " << setw(6) << item.second
                     << " | " << setw(6) << item.first.harga
                     << " | " << setw(8) << subtotal << " |" << endl;
            }
            cout << "|===========================================|" << endl;
            cout << "Total: " << total << endl;

            int bayar;
            cout << "Masukkan jumlah bayar: ";
            while (!(cin >> bayar) || bayar < total) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Jumlah bayar tidak mencukupi. Masukkan lagi: ";
            }

            cout << "Kembalian: " << bayar - total << endl;
            keranjang.clear();
            break;
        }
        case 4:
            cout << "Kembali ke menu utama..." << endl;
            return;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 4);
}
//void menuKasir() - Selesai

//void menuAdmin()
void menuAdmin() {
    int pilihan;
    do {
        cout << "|===============================|" << endl;
        cout << "|            -MENU-             |" << endl;
        cout << "|===============================|" << endl;
        cout << "| 1. Lihat Barang               |" << endl;
        cout << "| 2. Tambah Barang              |" << endl;
        cout << "| 3. Edit Barang                |" << endl;
        cout << "| 4. Hapus Barang               |" << endl;
        cout << "| 5. Menu Kasir                 |" << endl;
        cout << "| 6. Logout                     |" << endl;
        cout << "|===============================|" << endl;
        cout << "| Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tampilDataBarang();
            break;
        case 2:
            tambahDataBarang();
            break;
        case 3:
            updateDataBarang();
            break;
        case 4:
            hapusDataBarang();
            break;
        case 5:
            menuKasir();
            break;
        case 6:
            cout << "Logout berhasil!" << endl;
            return;
        default:
            cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 6);
}
//void menuAdmin() - Selesai

//void login()
void login() {
    string username, password;
    // system("cls"); // membersihkan layar ketika output berjalan.
    cout << "|===============================|" << endl;
    cout << "|             -LOGIN-           |" << endl;
    cout << "|           -Interface-         |" << endl;
    cout << "|                               |" << endl;
    cout << "|      TOKO KELONTONG CANGGIH   |" << endl;
    cout << "|           KELOMPOK 3          |" << endl;
    cout << "|                               |" << endl;
    cout << "|           KELOMPOK 3 :        |" << endl;
    cout << "|         Amrullah Azzaky       |" << endl;
    cout << "|           Zulfa Riana         |" << endl;
    cout << "|        Defina Rahmayanti      |" << endl;
    cout << "|      Farida Agil Rahmadani    |" << endl;
    cout << "|      Mohamad Farrel Pratama   |" << endl;
    cout << "|===============================|" << endl;
    cout << "| Username : ";
    cin >> username;
    cout << "| Password : ";
    cin >> password;
    if (username == "adminkelompok3" && password == "admin0000") {
        menuAdmin();
    } else {
        cout << "Username atau Password salah!" << endl;
        login();
    }
}
//void login() - Selesai

// int main berisikan void menu login
int main() {
    login();
    return 0;
}
// int main berisikan void menu login - selesai

