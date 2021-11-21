//
// Created by Jan Kaczmarczyk on 16.11.2020.
//
#include <iostream>
#include "Produkt.h"
using namespace std;

//konstruktor
Produkt::Produkt(string& nazwa, double ilosc) : _nazwa(nazwa), _ilosc(ilosc), _id(zwrocId()) {}

//Metody wypisywania poszczególnych towarów

void Towar::wypiszTowar() const {
    cout << _id << "\t\t" << _nazwa << "\t\t" << _ilosc << " szt" << endl;
}

void Towar_Sypki::wypiszTowar() const {
    cout << _id << "\t\t" << _nazwa << "\t\t" << _ilosc << " kg" << endl;
}

void Towar_Ciekly::wypiszTowar() const {
    cout << _id << "\t\t" << _nazwa << "\t\t" << _ilosc << " l" << endl;
}

//Metody odpowiadające za podzielenie lub scalenie dla poszczególnych klas

Produkt* Towar::podziel (double ilosc) {

    if(ilosc<0) {
        throw wyjatekPodziel("Blad: Nie mozna podac wartosci ujemnej!");
    }

    //odejmuje z wybranego towaru ilosc podaną przez użytkownika
    _ilosc=_ilosc-ilosc;

    //zwracam nowo zaalokowany towar
    return new Towar(this->_nazwa, ilosc);
}
void Towar::scal(Produkt* t) {
    //dodaje ilość towaru do aktualnego produktu z produktu wskazywanego przez t
    _ilosc=_ilosc+t->zwrocIlosc();

    //zwalnianie pamięci
    delete t;
}

Produkt* Towar_Sypki::podziel (double ilosc) {

    if(ilosc<0) {
        throw wyjatekPodziel("Blad: Nie mozna podac wartosci ujemnej!");
    }

    _ilosc=_ilosc-ilosc;

    //zwracam nowo zaalokowany towar
    return new Towar_Sypki(this->_nazwa, ilosc);
}
void Towar_Sypki::scal(Produkt* t) {
    _ilosc=_ilosc+t->zwrocIlosc();

    delete t;
}

Produkt* Towar_Ciekly::podziel (double ilosc) {

    if(ilosc<0) {
        throw wyjatekPodziel("Blad: Nie mozna podac wartosci ujemnej!");
    }

    _ilosc=_ilosc-ilosc;

    //zwracam nowo zaalokowany towar
    return new Towar_Ciekly(this->_nazwa, ilosc);
}
void Towar_Ciekly::scal(Produkt* t) {
    _ilosc=_ilosc+t->zwrocIlosc();

    delete t;
}