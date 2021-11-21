//
// Created by Jan Kaczmarczyk on 24.11.2020.
//

#include <iostream>
#include <string>
#include "ObslugaMagazynu.h"


//funkcja czytająca string z konsoli
string czytaj_string() {
    string linijka;
    getline(cin, linijka);
    cout << "Wczytalem z pliku: " << linijka << endl;
    return linijka;
}

//funkcja czytająca int
int czytaj_int() {
    string linijka;
    getline(cin, linijka);
    //dla łatwiejszego sprawdzania wypisuje co wczytał getline
    cout << "Wczytalem z pliku: " << linijka << endl;

    char* koniec;
    return strtol(linijka.c_str(), &koniec,10);
}

//funkcja czytająca double
double czytaj_double() {
    string linijka;
    getline(cin, linijka);
    cout << "Wczytalem z pliku: " << linijka << endl;

    char* koniec;
    return strtod(linijka.c_str(), &koniec);
}

//funkcja dodająca towar do magazynu
void dodanieTowaru(Magazyn& m) {

    cout << "Podaj nazwe towaru:" << endl;
    string nazwa=czytaj_string();

    //wybór typu towaru
    cout << "Wybierz rodzaj towaru" << endl;
    cout << "1. Zwykly towar (szt)" << endl;
    cout << "2. Towar Sypki (kg)" << endl;
    cout << "3. Towar Ciekly (l)" << endl;

    int wybor=czytaj_int();

    Produkt* p = nullptr;

    //switch służy do przypisania odpowiedniego typu towaru do wskaźnika p
    switch (wybor) {
        case 1: {
            p = new Towar(nazwa);
            break;
        }
        case 2: {
            p = new Towar_Sypki(nazwa);
            break;
        }
        case 3: {
            p = new Towar_Ciekly(nazwa);
            break;
        }
        default:
            cout << "Podana akcja nie istnieje!!!" << endl;
            return;
    }
    
    //uruchomienie metody dodania towaru oraz wypisanie stanu magazynu
    m.dodajTowar(p);
    m.wypiszMagazyn();
}

void przyjecieTowaru(Magazyn& m) {
    //wypisuje stan magazynu przed operacją przyjęcia towaru
    m.wypiszMagazyn();

    //wczytywanie indeksu oraz kontrola
    cout << "Podaj miejsce towaru do przyjecia: " << endl;
    int index = czytaj_int();

    //kontrola w przypadku podania złego indeksu
    while(index>=m.zwrocWielkosc() || index<0) {
        cout << "Podane miejsce towaru nie istnieje!" << endl;
        cout << "Podaj poprawne miejsce towaru do przyjecia lub anuluj (wpisz -1): " << endl;
        index = czytaj_int();

        if(index==-1) {
            return;
        }
    }

    //wczytanie ilości towaru
    cout << "Podaj ilosc towaru do przyjecia: " << endl;
    double ilosc = czytaj_double();

    //uruchomienie metody przyjęcia towaru oraz wypisanie stanu magazynu po operacji
    m.przyjmijTowar(index, ilosc);
    m.wypiszMagazyn();
}

void odbiorTowaru(Magazyn& m) {
    //wypisuje stan magazynu przed operacją przyjęcia towaru
    m.wypiszMagazyn();

    //wczytywanie indeksu oraz kontrola
    cout << "Podaj miejsce towaru do zabrania: " << endl;
    int index = czytaj_int();

    //kontrola w przypadku podania złego indeksu
    while(index>=m.zwrocWielkosc() || index<0) {
        cout << "Podane miejsce towaru nie istnieje!" << endl;
        cout << "Podaj poprawne miejsce towaru do zabrania lub anuluj (wpisz -1): " << endl;
        index = czytaj_int();

        //na wypadek gdyby użytkownik chciał anulować operację
        if(index==-1) {
            return;
        }
    }

    //wczytywanie ilości oraz kontrola
    cout << "Podaj ilosc towaru do zabrania: " << endl;
    double ilosc = czytaj_double();

    //kontrola w przypadku podania zbyt dużej ilości towaru
    while(ilosc>m.zwrocIlosc(index)) {
        cout << "Nie ma tyle towaru w magazynie" << endl;
        cout << "Podaj mniejsza ilosc towaru do zabrania lub anuluj (wpisz -1): " << endl;
        ilosc = czytaj_double();

        //na wypadek gdyby użytkownik chciał anulować operację
        if(ilosc==-1) {
            return;
        }
    }

    //uruchomienie metody odbioru towaru oraz wypisanie stanu magazynu po operacji
    m.zabierzTowar(index, ilosc);
    m.wypiszMagazyn();
}

void pokazMagazyny(Kontener<Magazyn>& m) {
    for(int i=0; i<m.zwrocRozmiar(); i++) {
        cout << i << ". Magazyn: ";
        for(int j=0; j<m[i].zwrocWielkosc(); j++) {
            cout << "# ";
        }
        cout << endl;
    }
}

void doPaleciaka(Paleciak& p, Magazyn& m) {
    m.wypiszMagazyn();

    //wczytywanie indeksu oraz kontrola
    cout << "Podaj miejsce towaru do zabrania z magazynu: " << endl;
    int index = czytaj_int();

    //kontrola w przypadku podania złego indeksu
    while(index>=m.zwrocWielkosc() || index<0) {
        cout << "Podane miejsce towaru nie istnieje!" << endl;
        cout << "Podaj poprawne miejsce towaru do zabrania lub anuluj (wpisz -1): " << endl;
        index = czytaj_int();

        //na wypadek gdyby użytkownik chciał anulować operację
        if(index==-1) {
            return;
        }
    }

    //wczytywanie ilości oraz kontrola
    cout << "Podaj ilosc towaru do zabrania: " << endl;
    double ilosc = czytaj_double();

    //kontrola w przypadku podania zbyt dużej ilości towaru
    while(ilosc>m.zwrocIlosc(index)) {
        cout << "Nie ma tyle towaru w magazynie" << endl;
        cout << "Podaj mniejsza ilosc towaru do zabrania lub anuluj (wpisz -1): " << endl;
        ilosc = czytaj_double();

        //na wypadek gdyby użytkownik chciał anulować operację
        if(ilosc==-1) {
            return;
        }
    }

    //kontrola udzwigu paleciaka
    //jeśli podana waga produktu z magazynu + aktualne obciążenie paleciaka są większe od udźwigu
    // to dodanie towaru jest anulowane
    if(m.zwrocWageProduktu(index,ilosc)+p.zwrocObciazenie()>p.zwrocUdzwig()) {
        cout << "Nie mozna dodac towaru! Paleciak jest przeciazony!" << endl;
        return;
    }

    //uruchomienie metody dzielącej wybrany towar oraz umieszczajacej go w paleciaku
    m.wydajPaleciak(p, index, ilosc);

    //wypisanie magazynu oraz paleciaka
    m.wypiszMagazyn();
    //dla lepszej widoczności
    cout << endl;
    p.wypiszPaleciak();
}

void zPaleciaka(Paleciak& p, Magazyn& m) {
    //wypisanie zawartości paleciaka
    p.wypiszPaleciak();

    //wczytywanie indeksu oraz kontrola
    cout << "Podaj miejsce towaru do zabrania z paleciaka: " << endl;
    int indexP = czytaj_int();

    //kontrola w przypadku podania złego indeksu
    while(indexP >= p.zwrocWielkosc() || indexP < 0) {
        cout << "Podane miejsce towaru nie istnieje!" << endl;
        cout << "Podaj poprawne miejsce towaru do zabrania lub anuluj (wpisz -1): " << endl;
        indexP = czytaj_int();

        //na wypadek gdyby użytkownik chciał anulować operację
        if(indexP == -1) {
            return;
        }
    }
    //wypisanie zawartości magazynu
    m.wypiszMagazyn();

    //wczytywanie indeksu oraz kontrola
    cout << "Podaj miejsce towaru do dodania w magazynie: " << endl;
    int indexM = czytaj_int();

    //kontrola w przypadku podania złego indeksu
    while(indexM >= m.zwrocWielkosc() || indexM < 0) {
        cout << "Podane miejsce towaru nie istnieje!" << endl;
        cout << "Podaj poprawne miejsce towaru do zabrania lub anuluj (wpisz -1): " << endl;
        indexM = czytaj_int();

        //na wypadek gdyby użytkownik chciał anulować operację
        if(indexM == -1) {
            return;
        }
    }

    //ostateczna kontrola, jeśli nazwy produktów nie są takie same wtedy nie można scalić produktów
    if(p.zwrocNazweProduktu(indexP)!=m.zwrocNazweProduktu(indexM)) {
        cout << "Produkty o podanych miejscach nie są takie same!" << endl;
        cout << "Nie mozna mieszac produktow!" << endl;
        cout << "Wybierz produkty o tych samych nazwach!" << endl;
        return;
    }

    //metoda dodaje produkt o podanym indeksie paleciaka do produktu o podanym indeksie w magazynie,
    //następnie usuwa produkt z paleciaka
    m.przyjmijPaleciak(p, indexM, indexP);

    //wypisanie magazynu oraz paleciaka
    m.wypiszMagazyn();
    //dla lepszej widoczności
    cout << endl;
    p.wypiszPaleciak();
}