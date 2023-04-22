#pragma once
#include "KopiecBinarny.h"
#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>//do wypisywania ladnego kopca
#include <chrono>
#include "Tablica.h"
class KopiecBinarny
{
    //Kopiec typu max
public:
    Tablica* tablica;
    KopiecBinarny();
    KopiecBinarny(std::string fileName);
    //rodzic+1 = podloga(dziecko+1/2)
    //rodzic= podloga(dziecko+1/2) -1
    // 
    //dzieckoLewe+1=(rodzic+1)*2
    //dzieckoPrawe+1=(rodzic+1)*2+1
    bool przywrocWlasnoscWezla(const unsigned int index);
    void przywrocWlasnoscKopca();
    void dodajElement(int element);
    void dodajElementKontynuacja();//rozdzielane na potrzeby eksperymentu

    void usunElement(unsigned int index);
    void usunElementKontynuacja(unsigned int index);//rozdzielane na potrzeby eksperymentu
    int znajdzIndexElementu(int element);
    int znajdzIndexElementu(int element, int index);
    bool usun(int element);//taka sam kod jak przy znajdywaniu indexu
    bool usun(int element, unsigned int index);

    bool znajdzElement(int element);
    bool znajdzElement(int element, unsigned int index);
    void wyswietlKopiec();
    void wyswietlKopiecBezIndeksow();
};
