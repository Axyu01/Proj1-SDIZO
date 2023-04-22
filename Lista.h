#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>//do wypisywania ladnego kopca
#include <chrono>
class Lista
{
    struct ElementListy
    {
        ElementListy* poprzedni;
        ElementListy* nastepny;
        int element;
    };
private:
    ElementListy* glowa;
    ElementListy* ogon;
    unsigned int rozmiarListy;

    //ElementListy* obecny;//? czy jest to potrzebne?
    ElementListy* wstawPo(ElementListy* odnosnik, int element);// E1<=>odnosnik<=>E2 --> E1<>odnosnik<=>element<=>E2
    ElementListy* wstawPrzed(ElementListy* odnosnik, int element);// E1<=>odnosnik<=>E2 --> E1<=>element<=>odnosnik<=>E2
    ElementListy* znajdzElement(unsigned int index);
    bool usunElement(ElementListy* elementListy);
public:
    Lista();
    void dodajNaPoczatku(int element);
    void dodajNaKoncu(int element);
    bool usunNaPoczatku();
    bool usunNaKoncu();
    void dodajPo(int element, unsigned int index);
    void dodajPrzed(int element, unsigned int index);
    unsigned int zwrocRozmiarListy();
    int zwrocElement(unsigned int index);
    bool usunElement(unsigned int index);
    bool usun(const int element);
    bool dodaj(int odnosnikElement, int wstawianyElement);
    bool znajdzElementOdGlowy(const int element);
    bool znajdzElementOdOgonu(const int element);
    void wyswietlListe();
    Lista(std::string fileName);
    ~Lista();
};
