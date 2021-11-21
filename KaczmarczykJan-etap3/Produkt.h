//
// Created by Jan Kaczmarczyk on 16.11.2020.
// Plik przechowuje deklaracje klasy Produkt oraz jej klas pochodnych
//
#include <iostream>
using namespace std;

#ifndef PROJEKTMAGAZYN_TOWAR_H
#define PROJEKTMAGAZYN_TOWAR_H

//wyjątek dla metody podziel, w przypadku podania ujemnej wartości
struct wyjatekPodziel : exception {
    string wiadomosc;

    explicit wyjatekPodziel(string wiad) : wiadomosc(move(wiad)) {}
};

/*=================Produkt==========================*/
class Produkt {

protected:
    int _id;
    string _nazwa;
    double _ilosc;

public:
    //konstruktor
    Produkt(string& nazwa, double ilosc=0);

    //funkcja wypisująca pojedynczy towar
    virtual void wypiszTowar() const=0;

    //metoda zwraca nazwę towaru
    virtual string wezNazwe() const=0;

    //metoda zwraca masę 1 jednostki towaru
    virtual double zwrocWage() const=0;

    //metoda zwraca ilość towaru
    virtual double zwrocIlosc() const=0;

    //metoda jest wykorzystywana do obliczenia id produktu
    static int zwrocId() {
        static int _countId=0;
        return ++_countId-1;
    }

    //metody dzielące lub scalajace produkt
    virtual Produkt* podziel (double ilosc)=0;
    virtual void scal(Produkt* t)=0;

    //zaprzyjaźnienie klasy Towar z Magazynem by Magazyn mógł modyfikować ilości towaru przy wywołaniu metod pryjęcia i odbioru
    friend class Magazyn;

};

class Towar : public Produkt {

private:
    //int _id;
    //string _nazwa;
    //int _ilosc;

public:
    //konstruktor
    Towar(string& nazwa, double ilosc=0): Produkt(nazwa,ilosc) {}

    //funkcja wypisująca pojedynczy towar
    void wypiszTowar() const;

    //metoda zwraca nazwę towaru
    string wezNazwe() const {
        return _nazwa;
    }

    //metoda zwraca wagę towaru, przyjąłem że masa 1 szt to 0.01 kg
    double zwrocWage() const {
        //zwraca masę 1 szt
        return 0.01;
    }

    double zwrocIlosc() const {
        return _ilosc;
    }

    Produkt* podziel (double ilosc);
    void scal(Produkt* t);

    //zaprzyjaźnienie klasy Towar z Magazynem by Magazyn mógł modyfikować ilości towaru przy wywołaniu metod pryjęcia i odbioru
    friend class Magazyn;

};

class Towar_Sypki : public Produkt {

private:
    //int _id;
    //string _nazwa;
    //double _ilosc;

public:
    //konstruktor
    Towar_Sypki(string& nazwa, double ilosc=0): Produkt(nazwa,ilosc) {}

    //funkcja wypisująca pojedynczy towar
    void wypiszTowar() const;

    //metoda zwraca nazwę towaru
    string wezNazwe() const {
        return _nazwa;
    }

    //metoda zwraca wagę towaru, ponieważ ilość towaru sypkiego wyrażana jest w kg to metoda zwraca po prostu ilosc
    double zwrocWage() const {
        //zwraca masę 1 kg
        return 1;
    }

    double zwrocIlosc() const {
        return _ilosc;
    }

    Produkt* podziel (double ilosc);
    void scal(Produkt* t);

    //zaprzyjaźnienie klasy Towar z Magazynem by Magazyn mógł modyfikować ilości towaru przy wywołaniu metod pryjęcia i odbioru
    friend class Magazyn;

};

class Towar_Ciekly : public Produkt {

private:
    //int _id;
    //string _nazwa;
    //double _ilosc;

public:
    //konstruktor
    Towar_Ciekly(string& nazwa, double ilosc=0): Produkt(nazwa,ilosc) {}

    //funkcja wypisująca pojedynczy towar
    void wypiszTowar() const;

    //metoda zwraca nazwę towaru
    string wezNazwe() const {
        return _nazwa;
    }

    //metoda zwraca wagę towaru, przyjąłem że masa 1 l to 0.998 kg czyli masa litra wody
    double zwrocWage() const {
        //zwraca masę litra wody
        return 0.998;
    }

    double zwrocIlosc() const {
        return _ilosc;
    }

    Produkt* podziel (double ilosc);
    void scal(Produkt* t);

    //zaprzyjaźnienie klasy Towar z Magazynem by Magazyn mógł modyfikować ilości towaru przy wywołaniu metod pryjęcia i odbioru
    friend class Magazyn;

};

#endif //PROJEKTMAGAZYN_TOWAR_H
