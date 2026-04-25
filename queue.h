#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;


struct Nasabah {
    string nama;
    int priority; 
};

class BankQueue {
private:
    Nasabah* antrian;
    int kapasitas, jumlah;
    
   
    Nasabah history[100]; 
    int jumlahHistory;

public:
    BankQueue(int size);
    ~BankQueue();
    bool isFull();
    bool isEmpty();
    void tambahNasabah(string nama, int tipe);
    void panggilNasabah();
    void cekStatus();
    void lihatHistory();
    void isiDataDemo(); 
};

#endif