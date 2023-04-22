#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>//do wypisywania ladnego kopca
#include <chrono>
class Tablica
{
    // friend KopiecBinarny;
private:
    int* poczatekTablicy;
    unsigned int rozmiarTablicy;
public:
    Tablica();
    void wstawElement(int element, unsigned int index);
    bool usunElement(unsigned int index);
    bool znajdzElement(int element);
    void dodajNaPoczatku(int element);
    void dodajNaKoncu(int element);
    bool usunNaPoczatku();
    bool usunNaKoncu();
    bool usun(int element);
    void wyswietlTablice();
    ///-----------------------------------
    int getElement(unsigned int index);
    bool changeElement(unsigned int index, int element);
    unsigned int rozmiar();
    Tablica(const std::string& fileName);

    //destruktor
    ~Tablica();
};
