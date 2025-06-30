#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Definisi struct Buah tanpa ID
struct Buah {
    string nama;
    int stok;
};

// Fungsi untuk mencari buah berdasarkan nama
void cariBuah(const vector<Buah> &daftarBuah) {
    if (daftarBuah.empty()) {
        cout << "Belum ada data buah." << endl;
        cout << endl << "Tekan Enter untuk kembali ke menu utama...";
        cin.ignore();
        cin.get();
        return;
    }
    string namaCari;
    cout << "Masukkan nama buah yang dicari: ";
    getline(cin, namaCari);

    bool ditemukan = false;
    for (size_t i = 0; i < daftarBuah.size(); ++i) {
        if (daftarBuah[i].nama == namaCari) {
            cout << "Buah ditemukan!" << endl;
            cout << "Nama Buah: " << daftarBuah[i].nama << endl;
            cout << "Jumlah Buah: " << daftarBuah[i].stok << endl;
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) {
        cout << "Buah dengan nama '" << namaCari << "' tidak ditemukan." << endl;
    }
    cout << endl << "Tekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}

// Fungsi untuk menambah buah hanya dengan nama dan jumlah
void tambahBuahNamaJumlah(vector<Buah> &daftarBuah) {
    Buah buah;
    cout << "Masukkan Nama Buah: ";
    getline(cin, buah.nama);

    // Validasi nama tidak boleh kosong
    if (buah.nama.empty()) {
        cout << "Nama buah tidak boleh kosong!" << endl;
        return;
    }

    cout << "Masukkan Jumlah Buah: ";
    while (!(cin >> buah.stok)) {
        cout << "Input tidak valid. Masukkan angka untuk Jumlah Buah: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    cin.ignore(1000, '\n');

    // Validasi jumlah buah harus lebih dari 0
    if (buah.stok <= 0) {
        cout << "Jumlah buah harus lebih dari 0!" << endl;
        return;
    }

    daftarBuah.push_back(buah);
    cout << "Data buah berhasil disimpan!" << endl;
}

// Fungsi untuk menampilkan daftar buah dalam bentuk tabel
void tampilkanDaftarBuah(const vector<Buah> &daftarBuah) {
    if (daftarBuah.empty()) {
        cout << "Belum ada data buah." << endl;
    } else {
        cout << "===== DAFTAR BUAH =====" << endl;
        cout << left << setw(5) << "No" 
             << setw(20) << "Nama Buah" 
             << setw(15) << "Jumlah Buah" << endl;
        cout << string(40, '-') << endl;
        for (size_t i = 0; i < daftarBuah.size(); ++i) {
            cout << left << setw(5) << (i+1)
                 << setw(20) << daftarBuah[i].nama
                 << setw(15) << daftarBuah[i].stok << endl;
        }
    }
    // Validasi input agar tetap di menu Daftar Buah
    cout << endl << "Tekan Enter untuk kembali ke menu utama...";
    cin.ignore();
    cin.get();
}

int main() {
    int pilihan;
    vector<Buah> daftarBuah;

    do {
        cout << "===== MENU UTAMA =====" << endl;
        cout << "1. Tambah Buah (Nama & Jumlah)" << endl;
        cout << "2. Tampilkan Data Buah Terakhir" << endl;
        cout << "3. Daftar Buah" << endl;
        cout << "3. Cari Buah" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        while (!(cin >> pilihan)) {
            cout << "Input tidak valid. Pilih menu: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        cin.ignore(1000, '\n'); // Bersihkan buffer sebelum switch

        switch (pilihan) {
            case 1:
                tambahBuahNamaJumlah(daftarBuah);
                break;
            case 2:
                if (!daftarBuah.empty()) {
                    const Buah &buah = daftarBuah.back();
                    cout << "Nama Buah: " << buah.nama << endl;
                    cout << "Jumlah Buah: " << buah.stok << endl;
                } else {
                    cout << "Belum ada data buah." << endl;
                }
                break;
            case 3:
                tampilkanDaftarBuah(daftarBuah);
                break;
            case 4:
                CariBuah(daftarBuah);
            case 0:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
        cout << endl;
    } while (pilihan != 0);

    return 0;
}
