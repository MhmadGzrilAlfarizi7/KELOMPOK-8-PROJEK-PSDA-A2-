#include "queue.h"

BankQueue::BankQueue(int size) {
    kapasitas = size;
    antrian = new Nasabah[kapasitas];
    jumlah = 0;
    jumlahHistory = 0;
}

BankQueue::~BankQueue() {
    delete[] antrian;
}

bool BankQueue::isFull() { return jumlah == kapasitas; }
bool BankQueue::isEmpty() { return jumlah == 0; }

void BankQueue::tambahNasabah(string nama, int tipe) {
    if (isFull()) {
        cout << "\n[!] Antrian Penuh! Nasabah " << nama << " tidak bisa masuk.\n";
        return;
    }

    Nasabah baru = {nama, tipe};
    
    
    int i = jumlah - 1;
    while (i >= 0 && antrian[i].priority < baru.priority) {
        antrian[i + 1] = antrian[i];
        i--;
    }
    
    antrian[i + 1] = baru;
    jumlah++;
    
    string label = (tipe == 1) ? "VIP" : "Reguler";
    cout << "[OK] " << nama << " (" << label << ") berhasil masuk antrian.\n";
}

void BankQueue::panggilNasabah() {
    if (isEmpty()) {
        cout << "\n[!] Antrian Kosong! Tidak ada yang bisa dipanggil.\n";
        return;
    }

    Nasabah dipanggil = antrian[0];
    cout << "\n>>> LOKET: Memanggil " << (dipanggil.priority == 1 ? "[VIP] " : "") << dipanggil.nama << "!";

   
    if (jumlahHistory < 100) {
        history[jumlahHistory++] = dipanggil;
    }

   
    for (int i = 0; i < jumlah - 1; i++) {
        antrian[i] = antrian[i + 1];
    }
    jumlah--;
}

void BankQueue::cekStatus() {
    if (isEmpty()) {
        cout << "\nStatus: Antrian sedang kosong.\n";
        return;
    }

    cout << "\n" << setfill('=') << setw(45) << "=" << endl;
    cout << setfill(' ') << " No | " << left << setw(20) << "Nama Nasabah" << " | Status" << endl;
    cout << setfill('-') << setw(45) << "-" << endl;
    
    for (int i = 0; i < jumlah; i++) {
        string t = (antrian[i].priority == 1) ? "PRIORITAS (VIP)" : "REGULER";
        cout << setfill(' ') << " " << i + 1 << "  | " << left << setw(20) << antrian[i].nama << " | " << t << endl;
    }
    cout << setfill('=') << setw(45) << "=" << endl;
}

void BankQueue::lihatHistory() {
    cout << "\n========== RIWAYAT PELAYANAN HARI INI ==========\n";
    if (jumlahHistory == 0) {
        cout << "Belum ada nasabah yang dilayani.\n";
    } else {
        for (int i = 0; i < jumlahHistory; i++) {
            cout << "[" << i + 1 << "] " << left << setw(20) << history[i].nama 
                 << (history[i].priority == 1 ? " (VIP)" : " (REGULER)") << endl;
        }
        cout << "\nTotal Sukses Melayani: " << jumlahHistory << " Nasabah.";
    }
    cout << "\n================================================\n";
}

void BankQueue::isiDataDemo() {
    tambahNasabah("Aldi Muklis", 0);
    tambahNasabah("Ridho Alnoq", 0);
    tambahNasabah("CEO NGAWI PANTAI SELATAN", 1); 
    tambahNasabah("Ghina salwa", 1);  
    tambahNasabah("pak budi", 0);
    cout << "\n[INFO] 5 Data Demo berhasil dimasukkan.\n";
}