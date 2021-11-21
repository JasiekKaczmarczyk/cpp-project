//
// Created by Jan Kaczmarczyk on 17.12.2020.
//
#include "Paleciak.h"

void Paleciak::wypiszPaleciak() const {
    cout << "====Paleciak==== UDZWIG: " << zwrocObciazenie() << "/" << zwrocUdzwig() << endl;

    cout <<"Miejsce\t\t" << "Id\t\t" << "Nazwa Towaru\t" << "Ilosc" << endl;
    for (int i = 0; i < produkty.size(); i++) {
        //wypisuje nr miejsca
        cout << i << "\t\t";
        produkty[i]->wypiszTowar();
    }
    cout << endl;
}

//funkcja oblicza aktualne obciążenie paleciaka
double Paleciak::zwrocObciazenie() const {
    double obciazenie=0;
    for (int i=0; i<produkty.size(); i++) {
        //obciążenie to aktualne obciążenie + masa 1 jednostki wybranego towaru*ilość tego towaru
        obciazenie = obciazenie + produkty[i]->zwrocWage()*produkty[i]->zwrocIlosc();
    }
    return obciazenie;
}

Paleciak::~Paleciak() {
    produkty.clear();
    produkty.shrink_to_fit();
}