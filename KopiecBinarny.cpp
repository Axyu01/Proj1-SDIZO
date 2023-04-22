#include "KopiecBinarny.h"
KopiecBinarny::KopiecBinarny()
    {
        tablica = new Tablica();
    }
KopiecBinarny::KopiecBinarny(std::string fileName)
    {
        tablica = new Tablica(fileName);
        przywrocWlasnoscKopca();
    }
    //rodzic+1 = podloga(dziecko+1/2)
    //rodzic= podloga(dziecko+1/2) -1
    // 
    //dzieckoLewe+1=(rodzic+1)*2
    //dzieckoPrawe+1=(rodzic+1)*2+1
    bool KopiecBinarny::przywrocWlasnoscWezla(const unsigned int index)
    {
        if (index >= tablica->rozmiar())
        {
            return false;
        }

        unsigned int najwiekszyIndex = index;
        int najwiekszy = tablica->getElement(index);

        const unsigned int synLewyIndex = (index + 1) * 2 - 1;
        if (tablica->rozmiar() > synLewyIndex)
        {
            const int synLewy = tablica->getElement(synLewyIndex);
            if (synLewy > najwiekszy)
            {
                najwiekszyIndex = synLewyIndex;
                najwiekszy = synLewy;
            }
        }

        const unsigned int synPrawyIndex = (index + 1) * 2;
        if (tablica->rozmiar() > synPrawyIndex)
        {
            const int synPrawy = tablica->getElement(synPrawyIndex);
            if (synPrawy > najwiekszy)
            {
                najwiekszyIndex = synPrawyIndex;
                najwiekszy = synPrawy;
            }
        }
        if (najwiekszyIndex != index)
        {
            tablica->changeElement(najwiekszyIndex, tablica->getElement(index));
            tablica->changeElement(index, najwiekszy);
            this->przywrocWlasnoscWezla(najwiekszyIndex);
        }
        return true;
    }
    void KopiecBinarny::przywrocWlasnoscKopca()
    {
        for (unsigned int i = tablica->rozmiar(); i >= 1; i--)
        {
            this->przywrocWlasnoscWezla(i - 1);
        }
    }
    void KopiecBinarny::dodajElement(int element)
    {
        tablica->dodajNaKoncu(element);
        dodajElementKontynuacja();
    }
    void KopiecBinarny::dodajElementKontynuacja()//rozdzielane na potrzeby eksperymentu
    {
        unsigned int index = (tablica->rozmiar() - 1);
        unsigned int parentIndex;
        while (true)
        {
            if (index != 0)
            {
                unsigned int parentIndex = (index + 1) / 2 - 1;
                if (tablica->getElement(index) > tablica->getElement(parentIndex))
                {
                    int temp = tablica->getElement(index);
                    tablica->changeElement(index, tablica->getElement(parentIndex));
                    tablica->changeElement(parentIndex, temp);
                    index = parentIndex;
                }
                else
                {
                    return;
                }
            }
            else
            {
                return;
            }
        }
    }
    void KopiecBinarny::usunElement(unsigned int index)
    {
        tablica->changeElement(index, tablica->getElement(tablica->rozmiar() - 1));
        tablica->usunNaKoncu();
        usunElementKontynuacja(index);
    }
    void KopiecBinarny::usunElementKontynuacja(unsigned int index)//rozdzielane na potrzeby eksperymentu
    {
        if (index < tablica->rozmiar())
        {
            przywrocWlasnoscWezla(index);
        }
    }
    int KopiecBinarny::znajdzIndexElementu(int element)
    {
        if (tablica->rozmiar() == 0)
            return -1;
        if (element > tablica->getElement(0))
            return -1;
        if (element == tablica->getElement(0))
        {
            return tablica->getElement(0);
        }
        return znajdzIndexElementu(element, 0);
    }
    int KopiecBinarny::znajdzIndexElementu(int element, int index)
    {
        const unsigned int synLewyIndex = (index + 1) * 2 - 1;
        if (tablica->rozmiar() > synLewyIndex)
        {
            const int synLewy = tablica->getElement(synLewyIndex);
            if (synLewy == element)
            {
                return (int)synLewyIndex;
            }
            else if (synLewy > element)
            {
                return znajdzIndexElementu(element, (int)synLewyIndex);
            }
        }

        const unsigned int synPrawyIndex = (index + 1) * 2;

        if (tablica->rozmiar() > synPrawyIndex)
        {
            const int synPrawy = tablica->getElement(synPrawyIndex);
            if (synPrawy == element)
            {
                return (int)synPrawyIndex;
            }
            else if (synPrawy > element)
            {
                return znajdzIndexElementu(element, (int)synPrawyIndex);
            }
        }
        return -1;
    }
    bool KopiecBinarny::usun(int element)//taka sam kod jak przy znajdywaniu indexu
    {
        if (tablica->rozmiar() == 0)
            return false;
        if (element > tablica->getElement(0))
            return false;
        if (element == tablica->getElement(0))
        {
            bool ret = tablica->usunNaPoczatku();
            przywrocWlasnoscKopca();
            return ret;
        }
        return usun(element, 0);
    }
    bool KopiecBinarny::usun(int element, unsigned int index)
    {
        const unsigned int synLewyIndex = (index + 1) * 2 - 1;
        if (tablica->rozmiar() > synLewyIndex)
        {
            const int synLewy = tablica->getElement(synLewyIndex);
            if (synLewy == element)
            {
                bool ret = tablica->usunElement(synLewyIndex);
                przywrocWlasnoscKopca();
                return ret;
            }
            else if (synLewy > element)
            {
                if (usun(element, synLewyIndex))
                    return true;
            }
        }

        const unsigned int synPrawyIndex = (index + 1) * 2;

        if (tablica->rozmiar() > synPrawyIndex)
        {
            const int synPrawy = tablica->getElement(synPrawyIndex);
            if (synPrawy == element)
            {
                bool ret = tablica->usunElement(synPrawyIndex);
                przywrocWlasnoscKopca();
                return ret;
            }
            else if (synPrawy > element)
            {
                if (usun(element, synPrawyIndex))
                    return true;
            }
        }
        return false;
    }
    bool KopiecBinarny::znajdzElement(int element)
    {
        if (tablica->rozmiar() == 0)
            return false;
        if (tablica->getElement(0) == element)
            return true;
        else
            return znajdzElement(element, 0);
    }
    bool KopiecBinarny::znajdzElement(int element, unsigned int index)
    {
        const unsigned int synLewyIndex = (index + 1) * 2 - 1;
        if (tablica->rozmiar() > synLewyIndex)
        {
            const int synLewy = tablica->getElement(synLewyIndex);
            if (synLewy == element)
            {
                return true;
            }
            else if (synLewy > element)
            {
                if (znajdzElement(element, synLewyIndex))
                    return true;
            }

        }

        const unsigned int synPrawyIndex = (index + 1) * 2;

        if (tablica->rozmiar() > synPrawyIndex)
        {
            const int synPrawy = tablica->getElement(synPrawyIndex);
            if (synPrawy == element)
            {
                return true;
            }
            else if (synPrawy > element)
            {
                if (znajdzElement(element, synPrawyIndex))
                    return true;
            }
        }
        return false;
    }
    void KopiecBinarny::wyswietlKopiec()
    {
        std::cout << std::endl;
        unsigned int rozmiarKopca = tablica->rozmiar();
        if (rozmiarKopca == 0)
        {
            std::cout << "Brak elementow do wyswietlania!" << std::endl;
            return;
        }
        int x = 2;
        while (rozmiarKopca + 1 > x)
        {
            x *= 2;
        }
        //x = x / 2;
        unsigned int wielkoscWarstwy = 1;
        unsigned int ktory = 1;
        for (unsigned int i = 0; i < tablica->rozmiar(); i++)
        {
            if (ktory == 1)
            {
                for (int j = 0; j < x / 4 - 1; j++)
                {
                    std::cout << std::setw(10) << " ";
                }
            }
            std::cout << "[" << std::setw(3) << i << "|" << std::setw(4) << tablica->getElement(i) << "]";
            if (ktory != wielkoscWarstwy)
            {
                for (int j = 0; j < x / 2 - 1; j++)
                {
                    std::cout << std::setw(10) << " ";
                }
            }
            if (ktory == wielkoscWarstwy)
            {
                ktory = 1;
                wielkoscWarstwy *= 2;
                x = x / 2;

                std::cout << std::endl;
            }
            else
            {
                ktory++;
            }
        }
        std::cout << std::endl;
    }
    void KopiecBinarny::wyswietlKopiecBezIndeksow()
    {
        std::cout << std::endl;
        unsigned int rozmiarKopca = tablica->rozmiar();
        if (rozmiarKopca == 0)
        {
            std::cout << "Brak elementow do wyswietlania!" << std::endl;
            return;
        }
        int x = 2;
        while (rozmiarKopca + 1 > x)
        {
            x *= 2;
        }
        //x = x / 2;
        unsigned int wielkoscWarstwy = 1;
        unsigned int ktory = 1;
        for (unsigned int i = 0; i < tablica->rozmiar(); i++)
        {
            if (ktory == 1)
            {
                for (int j = 0; j < x / 4 - 1; j++)
                {
                    std::cout << std::setw(5) << " ";
                }
            }
            std::cout << "[" << std::setw(3) << tablica->getElement(i) << "]";
            if (ktory != wielkoscWarstwy)
            {
                for (int j = 0; j < x / 2 - 1; j++)
                {
                    std::cout << std::setw(5) << " ";
                }
            }
            if (ktory == wielkoscWarstwy)
            {
                ktory = 1;
                wielkoscWarstwy *= 2;
                x = x / 2;

                std::cout << std::endl;
            }
            else
            {
                ktory++;
            }
        }
        std::cout << std::endl;
    }
