// Zadanie1StrukturyDanych.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>//do wypisywania ladnego kopca
#include <chrono>
#include "Tablica.h"
#include "Lista.h"
#include "KopiecBinarny.h"
#include "RedBlackTree.h"
//#include <vector>

namespace Utils
{
    class Timer
    {
    public:
        void Start() noexcept;
        void Stop() noexcept;

        [[nodiscard]] int64_t GetTimeInNanos() const;
        [[nodiscard]] int64_t GetTimeInMicros() const;
        [[nodiscard]] int64_t GetTimeInMillis() const;
        [[nodiscard]] int64_t GetTimeInSeconds() const;

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> start;
        std::chrono::time_point<std::chrono::high_resolution_clock> stop;
    };
}
namespace Utils
{
    void Timer::Start() noexcept
    {
        start = std::chrono::high_resolution_clock::now();
        //std::cout<<"start" << std::endl;
    }

    void Timer::Stop() noexcept
    {
        stop = std::chrono::high_resolution_clock::now();
        //std::cout << "stop" << std::endl;
    }

    int64_t Timer::GetTimeInNanos() const
    {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count();
    }

    int64_t Timer::GetTimeInMicros() const
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
    }

    int64_t Timer::GetTimeInMillis() const
    {
        return std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    }

    int64_t Timer::GetTimeInSeconds() const
    {
        return std::chrono::duration_cast<std::chrono::seconds>(stop - start).count();
    }
}

void stworzProbke(unsigned int ilosc)
{
    std::ofstream plik("probka.txt"); //jesli nie istnieje, zostanie utworzony
    //srand(time(NULL));
    plik << ilosc<<std::endl;
    for(unsigned int i=0;i<ilosc;i++)
    plik << rand()%200 -99<<std::endl;
}
void stworzProbke(unsigned int ilosc, int min, int max)
{
    //int variable = 1;
    //if (max - min != 0)
        //variable = ilosc / (max - min);//standardowo operacja wykonuje podloge z dzielenia
    //{//ten fragment kodu powoduje sufit z dzielenia
        //float variable2 = 1;
       // if ((min - max) != 0)
       // {
         //   variable2 = (float)ilosc / (float)(max - min);
         //   if (variable2 - (float)(ilosc / (max - min)) > 0)
         //   {
         //       variable2++;
        //    }
       // }
//}
    std::ofstream plik("probka.txt");
    plik << ilosc << std::endl;
    /*for (int i = 0; i < ilosc; i++)
    {
        plik << i << std::endl;
    }
    return;*/
    //srand(time(NULL));
    plik << ilosc << std::endl;
    for (unsigned int i = 0; i < ilosc; i++)
    {
        if ((max - min) == 0)
        {
            plik <<min << std::endl;
        }
        else
        {
            int liczba = i;//rand() % (max - min) + min;

            if (true)
            {
                plik << liczba << std::endl;
                //std::cout << liczba << std::endl;
            }
            else
            {
                i--;
            }
        }
    }
}
void stworz13579()
{
    std::ofstream plik("13579.txt"); //jesli nie istnieje, zostanie utworzony
    //srand(time(NULL));
    plik << 5 << std::endl;
    plik << 1 << std::endl;
    plik << 3 << std::endl;
    plik << 5 << std::endl;
    plik << 7 << std::endl;
    plik << 9 << std::endl;
}
namespace WszystkieCLI
{
    void tablicaMenu()
    {
        
        Tablica* tablica;
        {
            std::cout << "Wczytac tablice z pliku? 1.TAK ELSE.NIE\n";
            std::string choice;
            std::cin >> choice;
            if (choice == "1")
            {
                std::cout << "Podaj sciezke pliku:";
                std::cin >> choice;
                tablica = new Tablica(choice);
            }
            else
            {
                tablica = new Tablica();
            }
        }
        
        {
            int choice = 0;
            while (choice >= 0)
            {
                std::cout << "--------------MENU--------------" << std::endl;
                std::cout << " 1.Wstaw element(element,index) " << std::endl;
                std::cout << "     2.Usun element(index)      " << std::endl;
                std::cout << "                                " << std::endl;
                std::cout << "    3.Znajdz element(element)   " << std::endl;
                std::cout << "                                " << std::endl;
                std::cout << "  4.Dodaj na poczatku(element)  " << std::endl;
                std::cout << "    5.Dodaj na koncu(element)   " << std::endl;
                std::cout << "     6.Dodaj losowo(element)    " << std::endl;
                std::cout << "                                " << std::endl;
                std::cout << "       7.Usun na poczatku       " << std::endl;
                std::cout << "         8.Usun na koncu        " << std::endl;
                std::cout << "          9.Usun losowo         " << std::endl;
                std::cout << "                                " << std::endl;
                std::cout << "      10.Wyswietl Tablice       " << std::endl;
                std::cout << "--------------------------------" << std::endl;
                std::cout << "           Else.Wyjdz           " << std::endl;

                std::cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    int element;
                    unsigned int index;
                    std::cin >> element;
                    std::cin >> index;
                    Utils::Timer timer;
                    timer.Start();
                    tablica->wstawElement(element, index);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 2:
                {
                    unsigned int index;
                    std::cin >> index;
                    Utils::Timer timer;
                    timer.Start();
                    bool isDeleted=tablica->usunElement(index);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                    if (isDeleted)
                    {
                        std::cout << "Usunieto!" << std::endl;
                    }
                    else
                    {
                        std::cout << "Nie usunieto!" << std::endl;
                    }
                }
                break;
                case 3:
                {
                    unsigned int index;
                    std::cin >> index;
                    Utils::Timer timer;
                    timer.Start();
                    bool isFound = tablica->znajdzElement(index);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                    if (isFound)
                    {
                        std::cout << "Znaleziono element!\n";
                    }
                    else
                    {
                        std::cout << "Nie znaleziono elementu!\n";
                    }
                }
                break;
                case 4:
                {
                    int element;
                    std::cin >> element;
                    Utils::Timer timer;
                    timer.Start();
                    tablica->dodajNaPoczatku(element);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 5:
                {
                    int element;
                    std::cin >> element;
                    Utils::Timer timer;
                    timer.Start();
                    tablica->dodajNaKoncu(element);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 6:
                {
                    //Dodawanie losowe
                    int element;
                    //srand(time(NULL));
                    unsigned int index=rand()%(tablica->rozmiar()+1);
                    std::cin >> element;
                    Utils::Timer timer;
                    timer.Start();
                    tablica->wstawElement(element, index);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 7:
                {
                    Utils::Timer timer;
                    timer.Start();
                    bool isDeleted = tablica->usunNaPoczatku();
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                    if (isDeleted)
                    {
                        std::cout << "Usunieto!" << std::endl;
                    }
                    else
                    {
                        std::cout << "Nie usunieto!" << std::endl;
                    }
                }
                break;
                case 8:
                {
                    //Usuniecie losowe
                    Utils::Timer timer;
                    timer.Start();
                    bool isDeleted = tablica->usunNaKoncu();
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                    if (isDeleted)
                    {
                        std::cout << "Usunieto!" << std::endl;
                    }
                    else
                    {
                        std::cout << "Nie usunieto!" << std::endl;
                    }
                }
                break;
                case 9:
                {
                    //Usuniecie losowe
                    //srand(time(NULL));
                    unsigned int index = rand() % (tablica->rozmiar());
                    Utils::Timer timer;
                    timer.Start();
                    bool isDeleted = tablica->usunElement(index);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                    if (isDeleted)
                    {
                        std::cout << "Usunieto!" << std::endl;
                    }
                    else
                    {
                        std::cout << "Nie usunieto!" << std::endl;
                    }
                }
                break;
                case 10:
                    tablica->wyswietlTablice();
                    break;
                default:
                    choice = -1;
                    break;
                }
            }
        }
    }
    void listaMenu()
    {
        Utils::Timer timer;
        Lista* lista;
        {
            std::cout << "Wczytac liste z pliku? 1.TAK ELSE.NIE\n";
            std::string choice;
            std::cin >> choice;
            if (choice == "1")
            {
                std::cout << "Podaj sciezke pliku:";
                std::cin >> choice;
                lista = new Lista(choice);
            }
            else
            {
                lista = new Lista();
            }
        }
        {
            int choice = 0;
            while (choice >= 0)
            {
                std::cout << "---------------MENU---------------" << std::endl;
                std::cout << "   1.Dodaj na poczatku(element)   " << std::endl;
                std::cout << "    2.dodaj Na koncu(element)     " << std::endl;
                std::cout << "    3.dodaj losowo(element)       " << std::endl;
                std::cout << "    4.dodaj po(element,index)     (dodatkowa funkcja)" << std::endl;
                std::cout << "   5.dodaj przed(element,index)   (dodatkowa funkcja)" << std::endl;
                std::cout << " 6.dodaj (elementOdnosnik,element)" << std::endl;
                std::cout << "     7.dodaj (element,index)      " << std::endl;
                std::cout << "                                  " << std::endl;
                std::cout << "        8.Usun na poczatku        " << std::endl;
                std::cout << "         9.Usun na koncu          " << std::endl;
                std::cout << "          10.usun losowo          " << std::endl;
                std::cout << "         11.usun(element)         " << std::endl;
                std::cout << "                                  " << std::endl;
                std::cout << "      12.zwroc element(index)     (dodatkowa funkcja)" << std::endl;
                std::cout << "      13.usun element(index)      (dodatkowa funkcja)" << std::endl;
                std::cout << "                                  " << std::endl;
                std::cout << "14.znajdz element od glowy(element)" << std::endl;
                std::cout << "15.znadz element od ogonu(element)" << std::endl;
                std::cout << "    16.Wyswietl Liste + rozmiar   " << std::endl;
                std::cout << "----------------------------------" << std::endl;
                std::cout << "            Else.Wyjdz            " << std::endl;

                std::cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    int element;
                    std::cin >> element;
                    timer.Start();
                    lista->dodajNaPoczatku(element);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 2:
                {
                    int element;
                    std::cin >> element;
                    timer.Start();
                    lista->dodajNaKoncu(element);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 3:
                {
                    //srand(time(NULL));
                    unsigned int index = rand() % (lista->zwrocRozmiarListy()+1);
                    int element = rand();
                    if (index < lista->zwrocRozmiarListy())
                    {
                        timer.Start();
                        lista->dodajPrzed(element,index);
                        timer.Stop();
                    }
                    else
                    {
                        timer.Start();
                        lista->dodajNaKoncu(element);
                        timer.Stop();
                    }
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 4:
                {
                    int element;
                    int index;
                    std::cin >> element;
                    std::cin >> index;
                    timer.Start();
                    lista->dodajPo(element, index);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 5:
                {
                    int element;
                    int index;
                    std::cin >> element;
                    std::cin >> index;
                    timer.Start();
                    lista->dodajPrzed(element, index);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 6:
                {
                    int element;
                    int elementOdnosnik;
                    std::cin >> elementOdnosnik;
                    std::cin >> element;
                    timer.Start();
                    lista->dodaj(elementOdnosnik, element);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 7:
                {
                    int element;
                    unsigned int index;
                    std::cin >> element;
                    std::cin >> index;
                    if (index < lista->zwrocRozmiarListy())
                    {
                        timer.Start();
                        lista->dodajPrzed(element, index);
                        timer.Stop();
                    }
                    else
                    {
                        timer.Start();
                        lista->dodajNaKoncu(element);
                        timer.Stop();
                    }
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 8:
                {
                    bool isDeleted;
                    timer.Start();
                    isDeleted = lista->usunNaPoczatku();
                    timer.Stop();
                    if (isDeleted)
                        std::cout << "Usunieto!" << std::endl;
                    else
                        std::cout << "Nie usunieto!" << std::endl;

                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 9:
                {
                    bool isDeleted;
                    timer.Start();
                    isDeleted = lista->usunNaKoncu();
                    timer.Stop();
                    if (isDeleted)
                        std::cout << "Usunieto!" << std::endl;
                    else
                        std::cout << "Nie usunieto!" << std::endl;

                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 10:
                {
                    bool isDeleted;
                    //srand(time(NULL));
                    unsigned int index = rand() % lista->zwrocRozmiarListy();

                    timer.Start();
                    isDeleted = lista->usunElement(index);
                    timer.Stop();

                    if (isDeleted)
                        std::cout << "Usunieto!" << std::endl;
                    else
                        std::cout << "Nie usunieto!" << std::endl;

                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 11:
                {
                    int element;
                    std::cin >> element;
                    bool isDeleted;
                    timer.Start();
                    isDeleted = lista->usun(element);
                    timer.Stop();
                    if (isDeleted)
                        std::cout << "Usunieto!" << std::endl;
                    else
                        std::cout << "Nie usunieto!" << std::endl;

                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 12:
                {
                    int index;
                    std::cin >> index;
                    std::cout << "Element pod indeksem [" << index << "] :";
                    int element;
                    timer.Start();
                    element = lista->zwrocElement(index);
                    timer.Stop();
                    std::cout << element << std::endl;
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 13:
                {
                    int index;
                    std::cin >> index;
                    timer.Start();
                    bool isDeleted = lista->usunElement(index);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                    if (isDeleted)
                        std::cout << "Usunieto element pod indeksem [" << index << "] :" << std::endl;
                    else
                        std::cout << "Nie usunieto!" << std::endl;
                }
                break;
                case 14:
                {
                    int element;
                    std::cin >> element;
                    bool isFound;
                    timer.Start();
                    isFound = lista->znajdzElementOdGlowy(element);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                    if (isFound)
                        std::cout << "Znaleziono element " << element << "!" << std::endl;
                    else
                        std::cout << "Nie znaleziono elementu " << element << "!" << std::endl;
                }
                break;
                case 15:
                {
                    int element;
                    std::cin >> element;
                    bool isFound;
                    timer.Start();
                    isFound = lista->znajdzElementOdOgonu(element);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                    if (isFound)
                        std::cout << "Znaleziono element " << element << "!" << std::endl;
                    else
                        std::cout << "Nie znaleziono elementu " << element << "!" << std::endl;
                }
                break;
                case 16:
                {
                    std::cout << "Rozmiar Listy:" << lista->zwrocRozmiarListy() << std::endl;
                    timer.Start();
                    lista->wyswietlListe();
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                    break;
                }
                default:
                    choice = -1;
                    break;
                }
            }
        }
    }
    void kopiecMenu()
    {
        Utils::Timer timer;
        KopiecBinarny* kopiecBinarny;
        {
            std::cout << "Wczytac kopiec z pliku? 1.TAK ELSE.NIE\n";
            std::string choice;
            std::cin >> choice;
            if (choice == "1")
            {
                std::cout << "Podaj sciezke pliku:";
                std::cin >> choice;
                kopiecBinarny = new KopiecBinarny(choice);
            }
            else
            {
                kopiecBinarny = new KopiecBinarny();
            }
        }
        {
            int choice = 0;
            while (choice >= 0)
            {
                std::cout << "---------------MENU---------------" << std::endl;
                std::cout << "      1.Dodaj element(element)    " << std::endl;
                std::cout << "       2.usun element(index)      (dodatkowe)" << std::endl;
                std::cout << "       3.usun element(element)    " << std::endl;
                std::cout << "     4.znajdz element(element)    " << std::endl;
                std::cout << "  5.Wyswietl Kopiec z indeksami   " << std::endl;
                std::cout << "  6.Wyswietl Kopiec bez indeksow  " << std::endl;
                std::cout << "  7.Wyswietl Kopiec jako tablice  " << std::endl;
                std::cout << "----------------------------------" << std::endl;
                std::cout << "            Else.Wyjdz            " << std::endl;

                std::cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    int element;
                    std::cin >> element;

                    timer.Start();
                    kopiecBinarny->dodajElement(element);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 2:
                {
                    unsigned int index;
                    std::cin >> index;
                    timer.Start();
                    kopiecBinarny->usunElement(index);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                        std::cout << "Usunieto element pod indeksem [" << index << "] :" << std::endl;
                }
                break;
                case 3:
                {
                    int element;
                    std::cin >> element;
                    timer.Start();
                    bool isDeleted = kopiecBinarny->usun(element);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                    if (isDeleted)
                        std::cout << "Usunieto '" << element << "'!" << std::endl;
                    else
                        std::cout << "Nie usunieto '" << element << "'!" << std::endl;
                }
                break;
                case 4:
                {
                    int element;
                    std::cin >> element;
                    timer.Start();
                    bool isFound = kopiecBinarny->znajdzElement(element);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                    if (isFound)
                        std::cout << "Znaleziono element " << element << "!" << std::endl;
                    else
                        std::cout << "Nie znaleziono elementu " << element << "!" << std::endl;
                }
                break;
                case 5:
                    std::cout << "Rozmiar Kopca:" << kopiecBinarny->tablica->rozmiar() << std::endl;
                    kopiecBinarny->wyswietlKopiec();
                    break;
                case 6:
                    std::cout << "Rozmiar Kopca:" << kopiecBinarny->tablica->rozmiar() << std::endl;
                    kopiecBinarny->wyswietlKopiecBezIndeksow();
                    break;
                case 7:
                    std::cout << "Rozmiar Kopca:" << kopiecBinarny->tablica->rozmiar() << std::endl;
                    kopiecBinarny->tablica->wyswietlTablice();
                    break;
                default:
                    choice = -1;
                    break;
                }
            }
        }
    }
    void rbMenu()
    {
        Utils::Timer timer;
        RedBlackTree* rbTree;
        {
            std::cout << "Wczytac drzewo z pliku? 1.TAK ELSE.NIE\n";
            std::string choice;
            std::cin >> choice;
            if (choice == "1")
            {
                std::cout << "Podaj sciezke pliku:";
                std::cin >> choice;
                rbTree = new RedBlackTree(choice);
            }
            else
            {
                rbTree = new RedBlackTree();
            }
        }
        {
            int choice = 0;
            while (choice >= 0)
            {
                std::cout << "---------------MENU---------------" << std::endl;
                std::cout << "      1.dodaj element(element)    " << std::endl;
                std::cout << "       2.usun element(element)    " << std::endl;
                std::cout << "     3.znajdz element(element)    " << std::endl;
                std::cout << "4.wyswietl drzewo czerwono-czarne " << std::endl;
                std::cout << "----------------------------------" << std::endl;
                std::cout << "            Else.Wyjdz            " << std::endl;

                std::cin >> choice;
                switch (choice)
                {
                case 1:
                {
                    int element;
                    std::cin >> element;

                    timer.Start();
                    rbTree->insert(element);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 2:
                {
                    unsigned int index;
                    std::cin >> index;
                    timer.Start();
                    rbTree->remove(index);
                    timer.Stop();
                    std::cout << "Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                }
                break;
                case 3:
                {
                    int element;
                    std::cin >> element;
                    timer.Start();
                    bool isFound = rbTree->find(element)!=nullptr;
                    timer.Stop();
                    std::cout<<"Proces trwal " << timer.GetTimeInNanos() << " nanosekund\n";
                    if (isFound)
                        std::cout << "Znaleziono '" << element << "'!" << std::endl;
                    else
                        std::cout << "Nie znaleziono '" << element << "'!" << std::endl;
                }
                break;
                case 4:
                {
                    rbTree->print();
                }
                break;
                default:
                    choice = -1;
                    break;
                }
            }
        }
    }
};
namespace Eksperymenty {
    void dodajNaPoczatkuTab(unsigned int rozmiar)
    {
        Tablica* tablica;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        tablica = new Tablica("probka.txt");
        for (unsigned int i = 0; i < 100; i++)
        {
            t.Start();
            tablica->dodajNaPoczatku(1);
            t.Stop();
            tablica->usunNaPoczatku();
            allTime += t.GetTimeInNanos();
        }
        std::cout << "TDP|rozmiar:" << rozmiar << "|nanosekund:" << ((unsigned int)allTime / 100) << std::endl;
        delete tablica;
    }
    void dodajNaKoncuTab(unsigned int rozmiar)
    {
        Tablica* tablica;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        tablica = new Tablica("probka.txt");
        for (unsigned int i = 0; i < 100; i++)
        {
            t.Start();
            tablica->dodajNaKoncu(1);
            t.Stop();
            tablica->usunNaPoczatku();
            allTime += t.GetTimeInNanos();
        }
        std::cout << "TDK|rozmiar:" << rozmiar << "|nanosekund:" << ((unsigned int)allTime / 100) << std::endl;
        delete tablica;
    }
    void dodajLosowoTab(unsigned int rozmiar)
    {
        Tablica* tablica;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        tablica = new Tablica("probka.txt");

        for (unsigned int i = 0; i < 100; i++)
        {
            //srand(time(NULL));
            unsigned int index = rand() % (tablica->rozmiar() + 1);
            t.Start();
            tablica->wstawElement(1, index);
            t.Stop();
            tablica->usunNaPoczatku();
            allTime += t.GetTimeInNanos();
        }
        std::cout << "TDL|rozmiar:" << rozmiar << "|nanosekund:" << ((unsigned int)allTime / 100) << std::endl;
        delete tablica;
    }
    void DodawanieTablicy()
    {
        dodajNaPoczatkuTab(100);
        dodajNaPoczatkuTab(500);
        dodajNaPoczatkuTab(1000);
        dodajNaPoczatkuTab(5000);
        dodajNaPoczatkuTab(10000);
        dodajNaPoczatkuTab(50000);
        dodajNaPoczatkuTab(100000);
        dodajNaKoncuTab(100);
        dodajNaKoncuTab(500);
        dodajNaKoncuTab(1000);
        dodajNaKoncuTab(5000);
        dodajNaKoncuTab(10000);
        dodajNaKoncuTab(50000);
        dodajNaKoncuTab(100000);
        dodajLosowoTab(100);
        dodajLosowoTab(500);
        dodajLosowoTab(1000);
        dodajLosowoTab(5000);
        dodajLosowoTab(10000);
        dodajLosowoTab(50000);
        dodajLosowoTab(100000);
    }
    void usunNaPoczatkuTab(unsigned int rozmiar)
    {
        Tablica* tablica;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        tablica = new Tablica("probka.txt");
        for (unsigned int i = 0; i < 100; i++)
        {
            t.Start();
            tablica->usunNaPoczatku();
            t.Stop();
            allTime += t.GetTimeInNanos();
            tablica->dodajNaPoczatku(1);
        }
        std::cout << "TUP|rozmiar:" << rozmiar << "|nanosekund:" << ((unsigned int)allTime / 100) << std::endl;
        delete tablica;
    }
    void usunNaKoncuTab(unsigned int rozmiar)
    {
        Tablica* tablica;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        tablica = new Tablica("probka.txt");
        for (unsigned int i = 0; i < 100; i++)
        {
            t.Start();
            tablica->usunNaKoncu();
            t.Stop();
            tablica->dodajNaPoczatku(1);
            allTime += t.GetTimeInNanos();
        }
        std::cout << "TUK|rozmiar:" << rozmiar << "|nanosekund:" << ((unsigned int)allTime / 100) << std::endl;
        delete tablica;
    }
    void usunLosowoTab(unsigned int rozmiar)
    {
        Tablica* tablica;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        tablica = new Tablica("probka.txt");

        for (unsigned int i = 0; i < 100; i++)
        {
            //srand(time(NULL));
            unsigned int index = rand() % (tablica->rozmiar() + 1);
            t.Start();
            tablica->usunElement(index);
            t.Stop();
            tablica->dodajNaPoczatku(1);
            allTime += t.GetTimeInNanos();
        }
        std::cout << "TUL|rozmiar:" << rozmiar << "|nanosekund:" << ((unsigned int)allTime / 100) << std::endl;
        delete tablica;
    }
    void UsuwanieTablicy()
    {
        usunNaPoczatkuTab(100);
        usunNaPoczatkuTab(500);
        usunNaPoczatkuTab(1000);
        usunNaPoczatkuTab(5000);
        usunNaPoczatkuTab(10000);
        usunNaPoczatkuTab(50000);
        usunNaPoczatkuTab(100000);
        usunNaKoncuTab(100);
        usunNaKoncuTab(500);
        usunNaKoncuTab(1000);
        usunNaKoncuTab(5000);
        usunNaKoncuTab(10000);
        usunNaKoncuTab(50000);
        usunNaKoncuTab(100000);
        usunLosowoTab(100);
        usunLosowoTab(500);
        usunLosowoTab(1000);
        usunLosowoTab(5000);
        usunLosowoTab(10000);
        usunLosowoTab(50000);
        usunLosowoTab(100000);
    }
    void znajdzElementTab(unsigned int rozmiar)
    {
        Tablica* tablica;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar,0,rozmiar);
        tablica = new Tablica("probka.txt");
        //tablica->wyswietlTablice();
        //srand(time(NULL));
        bool xd;
        for (unsigned int i = 0; i < 100; i++)
        {
            int element = rand() % (2 * rozmiar);
            t.Start();
            xd=tablica->znajdzElement(element);
            t.Stop();
            std::cout << xd;//<< element;
            //std::cout << t.GetTimeInNanos() << std::endl;
            allTime += t.GetTimeInNanos();
        }
        //std::cout << rozmiar;
        std::cout << "TZ |rozmiar:" << rozmiar << "|nanosekund:" << (allTime / (int64_t)100) << std::endl;
        delete tablica;
    }
    void ZnalezienieTablicy()
    {
        znajdzElementTab(100);
        znajdzElementTab(500);
        znajdzElementTab(1000);
        znajdzElementTab(5000);
        znajdzElementTab(10000);
        znajdzElementTab(50000);
        znajdzElementTab(100000);
    }
    //Lista
    void dodajNaPoczatkuLista(unsigned int rozmiar)
    {
        Lista* lista;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        lista = new Lista("probka.txt");
        for (unsigned int i = 0; i < 100; i++)
        {
            t.Start();
            lista->dodajNaPoczatku(1);
            t.Stop();
            lista->usunNaPoczatku();
            allTime += t.GetTimeInNanos();
        }
        std::cout << "LDP|rozmiar:" << rozmiar << "|nanosekund:" << ((unsigned int)allTime / 100) << std::endl;
        delete lista;
    }
    void dodajNaKoncuLista(unsigned int rozmiar)
    {
        Lista* lista;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        lista = new Lista("probka.txt");
        for (unsigned int i = 0; i < 100; i++)
        {
            t.Start();
            lista->dodajNaKoncu(1);
            t.Stop();
            lista->usunNaPoczatku();
            allTime += t.GetTimeInNanos();
        }
        std::cout << "LDK|rozmiar:" << rozmiar << "|nanosekund:" << ((unsigned int)allTime / 100) << std::endl;
        delete lista;
    }
    void dodajLosowoLista(unsigned int rozmiar)
    {
        Lista* lista;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        lista = new Lista("probka.txt");

        for (unsigned int i = 0; i < 100; i++)
        {
            //srand(time(NULL));
            unsigned int index = rand() % (lista->zwrocRozmiarListy());
            t.Start();
            lista->dodajPo(1, index);
            t.Stop();
            lista->usunNaPoczatku();
            allTime += t.GetTimeInNanos();
        }
        std::cout << "LDL|rozmiar:" << rozmiar << "|nanosekund:" << ((unsigned int)allTime / 100) << std::endl;
        delete lista;
    }
    void DodawanieListy()
    {
        dodajNaPoczatkuLista(100);
        dodajNaPoczatkuLista(500);
        dodajNaPoczatkuLista(1000);
        dodajNaPoczatkuLista(5000);
        dodajNaPoczatkuLista(10000);
        dodajNaPoczatkuLista(50000);
        dodajNaPoczatkuLista(100000);
        dodajNaKoncuLista(100);
        dodajNaKoncuLista(500);
        dodajNaKoncuLista(1000);
        dodajNaKoncuLista(5000);
        dodajNaKoncuLista(10000);
        dodajNaKoncuLista(50000);
        dodajNaKoncuLista(100000);
        dodajLosowoLista(100);
        dodajLosowoLista(500);
        dodajLosowoLista(1000);
        dodajLosowoLista(5000);
        dodajLosowoLista(10000);
        dodajLosowoLista(50000);
        dodajLosowoLista(100000);
    }
    void usunNaPoczatkuLista(unsigned int rozmiar)
    {
        Lista* lista;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        lista = new Lista("probka.txt");
        for (unsigned int i = 0; i < 100; i++)
        {
            t.Start();
            lista->usunNaPoczatku();
            t.Stop();
            lista->dodajNaKoncu(1);
            allTime += t.GetTimeInNanos();
        }
        std::cout << "LUP|rozmiar:" << rozmiar << "|nanosekund:" << ((unsigned int)allTime / 100) << std::endl;
        delete lista;
    }
    void usunNaKoncuLista(unsigned int rozmiar)
    {
        Lista* lista;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        lista = new Lista("probka.txt");
        for (unsigned int i = 0; i < 100; i++)
        {
            t.Start();
            lista->usunNaKoncu();
            t.Stop();
            lista->dodajNaPoczatku(1);
            allTime += t.GetTimeInNanos();
        }
        std::cout << "LUK|rozmiar:" << rozmiar << "|nanosekund:" << ((unsigned int)allTime / 100) << std::endl;
        delete lista;
    }
    void usunLosowoLista(unsigned int rozmiar)
    {
        Lista* lista;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        lista = new Lista("probka.txt");

        for (unsigned int i = 0; i < 100; i++)
        {
            //srand(time(NULL));
            unsigned int index = rand() % lista->zwrocRozmiarListy();
            t.Start();
            lista->usunElement(index);
            t.Stop();
            lista->dodajNaPoczatku(1);
            allTime += t.GetTimeInNanos();
        }
        std::cout << "TUL|rozmiar:" << rozmiar << "|nanosekund:" << ((unsigned int)allTime / 100) << std::endl;
        delete lista;
    }
    void UsuwanieListy()
    {
        usunNaPoczatkuLista(100);
        usunNaPoczatkuLista(500);
        usunNaPoczatkuLista(1000);
        usunNaPoczatkuLista(5000);
        usunNaPoczatkuLista(10000);
        usunNaPoczatkuLista(50000);
        usunNaPoczatkuLista(100000);
        usunNaKoncuLista(100);
        usunNaKoncuLista(500);
        usunNaKoncuLista(1000);
        usunNaKoncuLista(5000);
        usunNaKoncuLista(10000);
        usunNaKoncuLista(50000);
        usunNaKoncuLista(100000);
        usunLosowoLista(100);
        usunLosowoLista(500);
        usunLosowoLista(1000);
        usunLosowoLista(5000);
        usunLosowoLista(10000);
        usunLosowoLista(50000);
        usunLosowoLista(100000);
    }
    void znajdzElementListy(int rozmiar)
    {
        Lista* lista;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        lista = new Lista("probka.txt");
        //tablica->wyswietlTablice();
        //srand(time(NULL));
        bool xd;
        for (unsigned int i = 0; i < 100; i++)
        {
            int element = rand() % (2 * rozmiar);
            t.Start();
            xd = lista->znajdzElementOdGlowy(element);
            t.Stop();
            std::cout <<element<<" " << (xd==true ? "\033[1;32mtrue" : "\033[1;31mfalse") << "\033[0m\n";//<< element;
            //std::cout << t.GetTimeInNanos() << std::endl;
            allTime += t.GetTimeInNanos();
        }
        //std::cout << rozmiar;
        std::cout << "LZ |rozmiar:" << rozmiar << "|nanosekund:" << (allTime / (int64_t)100) << std::endl;
        delete lista;
    }
    void ZnalezienieListy()
    {
        znajdzElementListy(100);
        znajdzElementListy(500);
        znajdzElementListy(1000);
        znajdzElementListy(5000);
        znajdzElementListy(10000);
        znajdzElementListy(50000);
        znajdzElementListy(100000);
    }
    //Kopiec
    void dodajKopiec(unsigned int rozmiar)
    {
        KopiecBinarny* kopiec;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        kopiec = new KopiecBinarny("probka.txt");
        for (unsigned int i = 0; i < 100; i++)
        {

            int element = rand() % rozmiar;
            kopiec->tablica->dodajNaKoncu(element);
            t.Start();
            kopiec->dodajElementKontynuacja();
            t.Stop();
            kopiec->usun(element);
            allTime += t.GetTimeInNanos();
        }
        std::cout << "KD |rozmiar:" << rozmiar << "|nanosekund:" << ((unsigned int)allTime / 100) << std::endl;
        delete kopiec;
    }
    void usunKopiec(unsigned int rozmiar)
    {
        KopiecBinarny* kopiec;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        kopiec = new KopiecBinarny("probka.txt");
        for (unsigned int i = 0; i < 100; i++)
        {
            int element = rand() % rozmiar;
            kopiec->dodajElement(element);
            t.Start();
            int index = kopiec->znajdzIndexElementu(element);
            t.Stop();
            allTime += t.GetTimeInNanos();
            kopiec->tablica->changeElement(index, kopiec->tablica->getElement(kopiec->tablica->rozmiar() - 1));
            kopiec->tablica->usunNaKoncu();
            t.Start();
            kopiec->usunElementKontynuacja(index);
            t.Stop();
            allTime += t.GetTimeInNanos();
        }
        std::cout << "KU |rozmiar:" << rozmiar << "|nanosekund:" << ((unsigned int)allTime / 100) << std::endl;
        delete kopiec;
    }
    void znajdzKopiec(unsigned int rozmiar)
    {
        KopiecBinarny* kopiec;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        kopiec = new KopiecBinarny("probka.txt");
        //tablica->wyswietlTablice();
        //srand(time(NULL));
        bool xd;
        for (unsigned int i = 0; i < 100; i++)
        {
            int element = rand() % (2 * rozmiar);
            t.Start();
            xd = kopiec->znajdzElement(element);
            t.Stop();
            std::cout << xd;//<< element;
            //std::cout << t.GetTimeInNanos() << std::endl;
            allTime += t.GetTimeInNanos();
        }
        //std::cout << rozmiar;
        std::cout << "KZ |rozmiar:" << rozmiar << "|nanosekund:" << (allTime / (int64_t)100) << std::endl;
        delete kopiec;
    }
    void TestKopca()
    {
        dodajKopiec(100);
        dodajKopiec(500);
        dodajKopiec(1000);
        dodajKopiec(5000);
        dodajKopiec(10000);
        dodajKopiec(50000);
        dodajKopiec(100000);
        usunKopiec(100);
        usunKopiec(500);
        usunKopiec(1000);
        usunKopiec(5000);
        usunKopiec(10000);
        usunKopiec(50000);
        usunKopiec(100000);
        znajdzKopiec(100);
        znajdzKopiec(500);
        znajdzKopiec(1000);
        znajdzKopiec(5000);
        znajdzKopiec(10000);
        znajdzKopiec(50000);
        znajdzKopiec(100000);
    }
    //RedBlackTree
    void insertRedBlackTree(unsigned int rozmiar)
    {
        RedBlackTree* rbTree;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        rbTree = new RedBlackTree("probka.txt");
        for (unsigned int i = 0; i < 100; i++)
        {

            int element = rand() % rozmiar;
            t.Start();
            rbTree->insert(element);
            t.Stop();
            std::cout << "element: " << element<< std::endl;
            rbTree->print();
            rbTree->remove(element);
            allTime += t.GetTimeInNanos();
        }
        std::cout << "RBTD |rozmiar:" << rozmiar << "|nanosekund:" << ((unsigned int)allTime / 100) << std::endl;
        delete rbTree;
    }
    void removeRedBlackTree(unsigned int rozmiar)
    {
        RedBlackTree* rbTree;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        rbTree = new RedBlackTree("probka.txt");
        for (unsigned int i = 0; i < 100; i++)
        {
            int element = rand() % rozmiar;
            rbTree->insert(element);
            t.Start();
            rbTree->remove(element);
            t.Stop();
            allTime += t.GetTimeInNanos();
        }
        std::cout << "RBTU |rozmiar:" << rozmiar << "|nanosekund:" << ((unsigned int)allTime / 100) << std::endl;
        delete rbTree;
    }
    void findRedBlackTree(unsigned int rozmiar)
    {
        RedBlackTree* rbTree;
        Utils::Timer t;
        int64_t allTime = 0;
        stworzProbke(rozmiar, 0, rozmiar);
        rbTree = new RedBlackTree("probka.txt");
        bool xd;
        for (unsigned int i = 0; i < 100; i++)
        {
            int element = rand() % (2 * rozmiar);
            t.Start();
            xd = (rbTree->find(element)!=nullptr);
            t.Stop();
            std::cout << xd;
            allTime += t.GetTimeInNanos();
        }
        std::cout << "RBTZ |rozmiar:" << rozmiar << "|nanosekund:" << (allTime / (int64_t)100) << std::endl;
        delete rbTree;
    }
    void TestRBTree()
    {
        insertRedBlackTree(100);
        insertRedBlackTree(500);
        insertRedBlackTree(1000);
        insertRedBlackTree(5000);
        insertRedBlackTree(10000);
        insertRedBlackTree(50000);
        removeRedBlackTree(100);
        removeRedBlackTree(500);
        removeRedBlackTree(1000);
        removeRedBlackTree(5000);
        removeRedBlackTree(10000);
        removeRedBlackTree(50000);
        findRedBlackTree(100);
        findRedBlackTree(500);
        findRedBlackTree(1000);
        findRedBlackTree(5000);
        findRedBlackTree(10000);
        findRedBlackTree(50000);
    }
}
int main()
{
    srand(time(NULL));
    int x= 0;
    while (false)
    {
        int y = rand();
        if (y > x)
        {
            std::cout << "BEST " << y << "!\n";
            x = y;
        }
    }
    /*Eksperymenty::DodawanieTablicy();
    Eksperymenty::UsuwanieTablicy();
    Eksperymenty::ZnalezienieTablicy();//*/
    //Eksperymenty::DodawanieListy();
    //Eksperymenty::UsuwanieListy();
    //Eksperymenty::ZnalezienieListy();
    //Eksperymenty::TestKopca();
    //Eksperymenty::DodawanieListy();
   // Eksperymenty::TestRBTree();
    /*RedBlackTree tree;
    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);
    tree.insert(2);
    tree.insert(6);
    tree.insert(13);
    tree.remove(18);
    tree.print();*/
    unsigned int wielkoscProbki=31;
    std::cout << "Podaj wielkosc probki\n";
    std::cin >> wielkoscProbki;
    stworzProbke(wielkoscProbki);//tworzy plik probka.txt z liczbami od -99 do 100 (podawana ilosc elementow)
    stworz13579();//tworzy plik 13579.txt z liczbami 1,3,5,7,9

    int choice = 0;
    while (choice >= 0)
    {
        std::cout << "---------WYBIERZ STRUKTURE--------" << std::endl;
        std::cout << "            1.Tablica             " << std::endl;
        std::cout << "             2.Lista              " << std::endl;
        std::cout << "            3.Kopiec              " << std::endl;
        std::cout << "     4.Drzewo Czerwono-Czarne     " << std::endl;
        std::cout << "----------------------------------" << std::endl;
        std::cout << "            Else.Wyjdz            " << std::endl;

        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            WszystkieCLI::tablicaMenu();
        }
        break;
        case 2:
        {
            WszystkieCLI::listaMenu();
        }
        break;
        case 3:
        {
            WszystkieCLI::kopiecMenu();
        }
        break;
        case 4:
        {
            WszystkieCLI::rbMenu();
        }
        break;
        default:
            choice = -1;
            break;
        }
    }
    return 0;
}
