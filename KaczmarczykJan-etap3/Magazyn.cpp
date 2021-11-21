//
// Created by Jan Kaczmarczyk on 16.11.2020.
//
#include <iostream>
#include "Magazyn.h"

using namespace std;

//metoda wypisuje aktualną zawartość magazynu w postaci tabelki
void Magazyn::wypiszMagazyn() const {
    cout << "====MAGAZYN====" << endl;

    cout <<"Miejsce\t\t" << "Id\t\t" << "Nazwa Towaru\t" << "Ilosc" << endl;
    for (int i = 0; i < towary.size(); i++) {
        //wypisuje nr miejsca
        cout << i << "\t\t";
        towary[i]->wypiszTowar();
    }
    cout << endl;
}

void Magazyn::dodajTowar(Produkt* t) {
    cout << "Dodaje towar: " << t->wezNazwe() << " do magazynu"<<endl;
    towary.push_back(t);
}

void Magazyn::przyjmijTowar(int index, double ilosc) {
    cout << "Przyjmuje " << ilosc << " towaru o indeksie: " << index << endl;

    //usunięcie określonej ilości towaru
    towary[index]->_ilosc =  towary[index]->_ilosc + ilosc;
}

void Magazyn::zabierzTowar(int index, double ilosc) {

    cout << "Zabieram " << ilosc << " towaru o indeksie: " << index << endl;

    //usunięcie określonej ilości towaru
    towary[index]->_ilosc =  towary[index]->_ilosc - ilosc;
}

//funkcje interakcji magazynu z paleciakiem
void Magazyn::wydajPaleciak(Paleciak& p, int index, double ilosc) {

    Produkt* prod= nullptr;
    try {
        //wywołanie funkcji dzielącej dany towar z magazynu, zwraca ona wskaźnik na produkt
        prod = towary[index]->podziel(ilosc);
    }
    catch (wyjatekPodziel& wyj) {
        cout << wyj.wiadomosc << endl;
        return;
    }

    //umieszczenie produktu w paleciaku
    p.produkty.push_back(prod);
}

void Magazyn::przyjmijPaleciak(Paleciak& p, int indexM, int indexP) {

    //wybieram index towaru w magazynie a następnie wywołuje na nim metodę scal
    // gdzie podaję index produktu z paleciaka
    towary[indexM]->scal(p.produkty[indexP]);

    //usuwanie produktu z paleciaka
    p.produkty.erase(p.produkty.begin()+indexP);
}

//Destruktor, czyści wektor towary
Magazyn::~Magazyn() {
    towary.clear();
    towary.shrink_to_fit();
}