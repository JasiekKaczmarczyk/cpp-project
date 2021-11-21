#include <iostream>
#include <thread>
#include <fstream>
#include "ObslugaMagazynu.h"
using namespace std;

int main(int argc, char* argv[]) {

    fstream plik;

    if(argc==2) {
        plik.open(argv[1], ios::in);
        cin.rdbuf(plik.rdbuf());
    }

    //tworzenie wzkaźników na obiekty typu magazyn
    //Magazyn* m;
    //tworzenie paleciaka z domyślnym udźwigiem (100kg)
    Paleciak p;


    cout << "Podaj ilosc magazynow" << endl;
    int nMagazynow=czytaj_int();

    while(nMagazynow<=0) {
        cout << "Nie mozna podac liczby ujemnej ani zera!" << endl;
        cout << "Podaj ilosc magazynow" << endl;
        nMagazynow=czytaj_int();
    }
    //alokacja pamięci
    //m=new Magazyn[nMagazynow];
    //tworzenie kontenera na obiekty typu magazyn
    Kontener<Magazyn> m(nMagazynow);

    //zmienne na wybor magazynu oraz akcji w wybranym magazynie
    int wyborMagazynu;
    int wyborAkcji;


    do {
        try {

            cout << "====== MENU ======" << endl;
            cout << "Wybierz Magazyn (Podaj Nr Magazynu) lub wpisz liczbe ujemna by zakonczyc program" << endl;

            pokazMagazyny(m);

            //wczytywanie wyboru z klawiatury
            wyborMagazynu = czytaj_int();

            //ten if powoduje przerwanie pętli i wyjście z programu
            if (wyborMagazynu < 0) {
                break;
            }

            if (m[wyborMagazynu].zwrocWielkosc() == 0) {
                //dodanie pierwszego towaru
                cout << "Magazyn jest pusty. Dodaj towar!" << endl;
                dodanieTowaru(m[wyborMagazynu]);
            }

            do {
                cout << "====== MENU MAGAZYNU NR " << wyborMagazynu << " ======" << endl;
                cout << "1: Dodanie towaru" << endl;
                cout << "2: Przyjecie towaru" << endl;
                cout << "3: Odbior towaru" << endl;
                cout << "4: Przenies towar do paleciaka" << endl;
                cout << "5: Przenies towar z paleciaka" << endl;
                cout << "0: Wyjscie z magazynu" << endl;

                cout << "Wybierz akcje: " << endl;

                //wczytywanie wyboru z klawiatury
                wyborAkcji = czytaj_int();

                switch (wyborAkcji) {
                    case 0:
                        break;
                    case 1:
                        dodanieTowaru(m[wyborMagazynu]);
                        break;
                    case 2:
                        przyjecieTowaru(m[wyborMagazynu]);
                        break;
                    case 3:
                        odbiorTowaru(m[wyborMagazynu]);
                        break;
                    case 4:
                        doPaleciaka(p, m[wyborMagazynu]);
                        break;
                    case 5:
                        zPaleciaka(p, m[wyborMagazynu]);
                        break;
                    default:
                        cout << "Podana akcja nie istnieje!!!" << endl;
                }

            } while (wyborAkcji != 0);
        }
        catch (wyjatekKontener& wyj) {
            cout << wyj.wiadomosc << endl;
        }

    } while (1);


    //zwolnienie pamięci dla wskaźników m
    //delete [] m;

    plik.close();

    return 0;
}