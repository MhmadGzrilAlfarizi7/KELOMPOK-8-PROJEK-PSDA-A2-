#include "queue.h"
#include <limits>

void tampilkanMenu() {
    cout << "\n--- SISTEM MANAJEMEN ANTRIAN BANK ---";
    cout << "\n1. Tambah Nasabah Baru";
    cout << "\n2. Panggil Nasabah (Dequeue)";
    cout << "\n3. Lihat Antrian Aktif";
    cout << "\n4. Lihat Riwayat (History)";
    cout << "\n5. simulasi (5 Orang)";
    cout << "\n0. Keluar";
    cout << "\nPilih menu: ";
}

int main() {
    BankQueue csBank(20);
    int pilihan;
    string nama;
    int tipe;

    do {
        tampilkanMenu();
        cin >> pilihan;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (pilihan) {
            case 1:
                cout << "Tipe (1: VIP, 0: Reguler): ";
                cin >> tipe;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Nama Nasabah: ";
                getline(cin, nama);
                csBank.tambahNasabah(nama, tipe);
                break;
            case 2:
                csBank.panggilNasabah();
                break;
            case 3:
                csBank.cekStatus();
                break;
            case 4:
                csBank.lihatHistory();
                break;
            case 5:
                csBank.isiDataDemo();
                break;
        }
    } while (pilihan != 0);

    return 0;
}