//
// Created by Jan Kaczmarczyk on 17.12.2020.
//

#ifndef KACZMARCZYKJAN_ETAP2_MAGAZYN_H
#define KACZMARCZYKJAN_ETAP2_MAGAZYN_H

#include "Produkt.h"
#include "Paleciak.h"
//nie trzeba includować vector tu bo jest już w paleciaku zaincludowany
//#include <vector>

/*=================MAGAZYN==========================*/
class Magazyn {
private:
    vector <Produkt*> towary;
public:
    //destruktor klasy magazyn, czyści wektor towary
    ~Magazyn();

    //wypisuje magazyn
    void wypiszMagazyn() const;
    //dodanie towaru
    void dodajTowar(Produkt* t);
    //przyjęcie towaru
    void przyjmijTowar(int index, double ilosc);
    //odbiór towaru
    void zabierzTowar(int index, double ilosc);

    //oblicza i zwraca wagę wybranego towaru (ilosc jest podana przez użytkownika)
    //metoda wykorzystywana przy kontroli obciążenia paleciaka
    double zwrocWageProduktu(int index, int ilosc) const {
        return towary[index]->zwrocWage()*ilosc;
    }

    //metody interakcji z paleciakiem
    void wydajPaleciak(Paleciak& p, int index, double ilosc);

    //dodaje ilość wybranego towaru z paleciaka do towaru z magazynu o podanym indeksie
    void przyjmijPaleciak(Paleciak& p, int indexM, int indexP);

    //zwraca wielkość wektora
    int zwrocWielkosc() const{
        return towary.size();
    }
    //zwraca ilosc danego towaru, wykorzystywana do sprawdzenia czy jest wystarczająca ilość towaru do zabrania
    double zwrocIlosc(int index) const {
        return towary[index]->_ilosc;
    }

    //zwraca nazwę produktu o podanym indeksie z magazynu
    string zwrocNazweProduktu(int index) const {
        return towary[index]->wezNazwe();
    }
};

#endif //KACZMARCZYKJAN_ETAP2_MAGAZYN_H
