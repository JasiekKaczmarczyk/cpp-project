//
// Created by Jan Kaczmarczyk on 17.12.2020.
//

#ifndef KACZMARCZYKJAN_ETAP2_PALECIAK_H
#define KACZMARCZYKJAN_ETAP2_PALECIAK_H

#include <vector>
#include "Produkt.h"

class Paleciak {
private:
    vector <Produkt*> produkty;
    double _udzwig;

public:
    //konstruktor paleciaka, domyślnie udźwig jest równy 100 kg
    explicit Paleciak(double udzwig=100) : _udzwig(udzwig) {};
    ~Paleciak();

    //wypisuje paleciak
    void wypiszPaleciak() const;

    //zwraca maksymalny udźwig paleciaka
    double zwrocUdzwig() const {
        return _udzwig;
    }
    //zwraca aktualne obiążenie paleciaka
    double zwrocObciazenie() const;

    //zwraca wielkość paleciaka
    int zwrocWielkosc() const{
        return produkty.size();
    }

    //zwraca nazwę produktu o podanym indeksie z paleciaka
    string zwrocNazweProduktu(int index) const {
        return produkty[index]->wezNazwe();
    }

    friend class Magazyn;
};

#endif //KACZMARCZYKJAN_ETAP2_PALECIAK_H
