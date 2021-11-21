//
// Created by Jan Kaczmarczyk on 24.11.2020.
//moduł zawiera funkcje obsługi magazynu oraz funkcje czytające string i int (inspirowane funkcjami z laboratorium)
//
#include "Magazyn.h"
#include "Kontener.h"

#ifndef PROJEKTMAGAZYN_OBSLUGAMAGAZYNU_H
#define PROJEKTMAGAZYN_OBSLUGAMAGAZYNU_H

//funkcje czytające int oraz string z klawiatury
int czytaj_int();
string czytaj_string();
double czytaj_double();


//funkcje obsługujące magazyn
void dodanieTowaru(Magazyn& m);
void przyjecieTowaru(Magazyn& m);
void odbiorTowaru(Magazyn& m);

//funkcja wypisująca informacje ile produktow jest w poszczególnych magazynach
void pokazMagazyny(Kontener<Magazyn>& m);

//funkcje interakcji między magazynem a paleciakiem
void doPaleciaka(Paleciak& p, Magazyn& m);
void zPaleciaka(Paleciak& p, Magazyn& m);

#endif //PROJEKTMAGAZYN_OBSLUGAMAGAZYNU_H
