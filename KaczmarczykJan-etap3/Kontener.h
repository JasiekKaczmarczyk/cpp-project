//
// Created by Jan Kaczmarczyk on 09.01.2021.
//
//Kontener służy do przechowywania wybranego rodzaju danych

#ifndef KACZMARCZYKJAN_ETAP3_KONTENER_H
#define KACZMARCZYKJAN_ETAP3_KONTENER_H

#include <iostream>
using namespace std;

struct wyjatekKontener : exception {
    string wiadomosc;

    explicit wyjatekKontener(string msg) : wiadomosc(move(msg)) {}
};

template<typename T>
class Kontener {

    T* tab;
    int rozmiar;
public:

    explicit Kontener(int x=10) : rozmiar(x) {
        tab=new T[rozmiar];
    }
    ~Kontener() {
        delete [] tab;
    }

    int zwrocRozmiar() const {
        return rozmiar;
    }

    T& operator[](int i) {
        if(i<rozmiar && rozmiar>=0) {
            return tab[i];
        }
        else {
            throw wyjatekKontener("Indeks poza granica tablicy!");
        }
    }
};

#endif //KACZMARCZYKJAN_ETAP3_KONTENER_H
