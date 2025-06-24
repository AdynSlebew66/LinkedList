#include <iostream>
#include <vector>
using namespace std;

vector<string> daftarBuah;

void showMenu() {
    cout << "===== MENU DASAR =====" << endl;
    cout << "1. Tambah Buah" << endl;
    cout << "2. Hapus Buah" << endl;
    cout << "3. Tampilkan Buah" << endl;
    cout << "4. Cari Buah" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih menu: ";
}

// Fungsi untuk menambah buah ke daftar
void tambahBuah() {
    string buah;
    cout << "Masukkan nama buah: ";
    cin.ignore(); // Menghindari masalah input newline
    getline(cin, buah);
    daftarBuah.push_back(buah);
    cout << "Buah \"" << buah << "\" berhasil ditambahkan." << endl;
}

int main() {
    int pilihan;
    do {
        showMenu();
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                tambahBuah();
                break;
            case 2:
                cout << "Hapus Buah." << endl;
                break;
            case 3:
                cout << "Tampilkan Buah" << endl;
                break;
            case 4:
                cout << "Cari Buah" << endl;
                break;
            case 5:
                cout << "Keluar " << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        cout << endl;
    } while (pilihan != 5);

    return 0;
}