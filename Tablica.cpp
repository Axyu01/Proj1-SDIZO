#include "Tablica.h"
    Tablica::Tablica()
    {
        rozmiarTablicy = 0;
        poczatekTablicy = new int[0];
    }
    void Tablica::wstawElement(int element, unsigned int index)
    {
        int* staraTablica = poczatekTablicy;
        poczatekTablicy = new int[rozmiarTablicy + 1];
        if (index >= rozmiarTablicy)
        {
            index = rozmiarTablicy;
        }
        for (unsigned int i = 0; i < index; i++)
        {
            poczatekTablicy[i] = staraTablica[i];
        }
        poczatekTablicy[index] = element;
        for (unsigned int i = index; i < rozmiarTablicy; i++)
        {
            poczatekTablicy[i + 1] = staraTablica[i];
        }
        rozmiarTablicy++;
        delete[] staraTablica;
    }//Przenosi element tablicy zawarty w indexie jak i wszystkie elementy "po prawo" do nastepnych komorek.Dodaje element na miejsce pod danym indexem.
    bool Tablica::usunElement(unsigned int index)
    {
        if (index >= rozmiarTablicy || rozmiarTablicy == 0)
        {
            return false;
        }
        else//if (rozmiarTablicy > 0)
        {
            int* staraTablica = poczatekTablicy;
            poczatekTablicy = new int[rozmiarTablicy - 1];
            for (unsigned int i = 0; i < index; i++)
            {
                poczatekTablicy[i] = staraTablica[i];
            }
            for (unsigned int i = index + 1; i < rozmiarTablicy; i++)
            {
                poczatekTablicy[i - 1] = staraTablica[i];
            }
            rozmiarTablicy--;
            delete[] staraTablica;
            return true;
        }
    }
    bool Tablica::znajdzElement(int element)
    {
        for (unsigned int i = 0; i < rozmiarTablicy; i++)
        {
            if (poczatekTablicy[i] == element)
            {
                //std::cout << "Znaleziono element '"<<element<<"' !" << std::endl;
                return true;
            }
        }
        //std::cout << "Nie znaleziono elementu '" << element << "' :(" << std::endl;
        return false;
    }
    void Tablica::dodajNaPoczatku(int element)
    {
        int* staraTablica = poczatekTablicy;
        poczatekTablicy = new int[rozmiarTablicy + 1];
        poczatekTablicy[0] = element;
        for (unsigned int i = 0; i < rozmiarTablicy; i++)
        {
            poczatekTablicy[i + 1] = staraTablica[i];
        }
        rozmiarTablicy++;
        delete[] staraTablica;
    }
    void Tablica::dodajNaKoncu(int element)
    {
        int* staraTablica = poczatekTablicy;
        poczatekTablicy = new int[rozmiarTablicy + 1];
        for (unsigned int i = 0; i < rozmiarTablicy; i++)
        {
            poczatekTablicy[i] = staraTablica[i];
        }
        poczatekTablicy[rozmiarTablicy] = element;
        rozmiarTablicy++;
        delete[] staraTablica;
    }
    bool Tablica::usunNaPoczatku()
    {
        if (rozmiarTablicy == 0)
        {
            return false;
        }
        else//if (rozmiarTablicy > 0)
        {
            int* staraTablica = poczatekTablicy;
            poczatekTablicy = new int[rozmiarTablicy - 1];
            for (unsigned int i = 1; i < rozmiarTablicy; i++)
            {
                poczatekTablicy[i - 1] = staraTablica[i];
            }
            rozmiarTablicy--;
            delete[] staraTablica;
            return true;
        }
    }
    bool Tablica::usunNaKoncu()
    {
        if (rozmiarTablicy == 0)
        {
            return false;
        }
        else//if (rozmiarTablicy > 0)
        {
            int* staraTablica = poczatekTablicy;
            poczatekTablicy = new int[rozmiarTablicy - 1];
            for (unsigned int i = 0; i < rozmiarTablicy - 1; i++)
            {
                poczatekTablicy[i] = staraTablica[i];
            }
            rozmiarTablicy--;
            delete[] staraTablica;
            return true;
        }
    }
    bool Tablica::usun(int element)
    {
        for (unsigned int i = 0; i < rozmiarTablicy; i++)
        {
            if (poczatekTablicy[i] == element)
            {
                return usunElement(i);
            }
            return false;
        }
    }
    void Tablica::wyswietlTablice()
    {
        std::cout << std::endl;
        for (unsigned int i = 0; i < rozmiarTablicy; i++)
        {
            std::cout << " |[" << i << "]>" << poczatekTablicy[i] << "| ";
            if (i % 10 == 9)
            {
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    ///-----------------------------------
    int Tablica::getElement(unsigned int index)
    {
        if (index < rozmiarTablicy)
        {
            return poczatekTablicy[index];
        }
        return poczatekTablicy[rozmiarTablicy - 1];
    }
    bool Tablica::changeElement(unsigned int index, int element)
    {
        if (index < rozmiarTablicy)
        {
            poczatekTablicy[index] = element;
            return true;
        }
        else
        {
            return false;
        }
    }
    unsigned int Tablica::rozmiar()
    {
        return rozmiarTablicy;
    }
    Tablica::Tablica(const std::string& fileName)
    {
        Tablica();
        std::ifstream plik;
        plik.open(fileName);
        if (plik.good())
        {
            int rozmiar;
            plik >> rozmiar;

            int element;
            for (int i = 0; i < rozmiar; i++)
            {
                plik >> element;
                dodajNaKoncu(element);
            }
        }
    }

    //destruktor
    Tablica::~Tablica()
    {
        delete[] poczatekTablicy;
    }
