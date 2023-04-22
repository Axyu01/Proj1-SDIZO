#include "Lista.h"
Lista::ElementListy* Lista::wstawPo(ElementListy* odnosnik, int element)// E1<=>odnosnik<=>E2 --> E1<>odnosnik<=>element<=>E2
    {
    Lista::ElementListy* elementListy = new Lista::ElementListy;

        if (rozmiarListy == 0)
        {
            elementListy->element = element;
            elementListy->nastepny = elementListy;
            elementListy->poprzedni = elementListy;
            glowa = elementListy;
            ogon = elementListy;
        }
        else
        {
            elementListy->element = element;
            elementListy->poprzedni = odnosnik;
            elementListy->nastepny = odnosnik->nastepny;
            (odnosnik->nastepny)->poprzedni = elementListy;
            odnosnik->nastepny = elementListy;

            if (odnosnik == ogon)
            {
                ogon = elementListy;
            }
        }

        rozmiarListy++;

        return elementListy;
    }
Lista::ElementListy* Lista::wstawPrzed(ElementListy* odnosnik, int element)// E1<=>odnosnik<=>E2 --> E1<=>element<=>odnosnik<=>E2
    {
        ElementListy* elementListy = new ElementListy;

        if (rozmiarListy == 0)
        {
            elementListy->element = element;
            elementListy->nastepny = elementListy;
            elementListy->poprzedni = elementListy;
            glowa = elementListy;
            ogon = elementListy;
        }
        else
        {
            elementListy->element = element;
            elementListy->nastepny = odnosnik;
            elementListy->poprzedni = odnosnik->poprzedni;
            (odnosnik->poprzedni)->nastepny = elementListy;
            odnosnik->poprzedni = elementListy;
            if (odnosnik == glowa)
            {
                glowa = elementListy;
            }
        }

        rozmiarListy++;

        return elementListy;
    }
Lista::ElementListy* Lista::znajdzElement(unsigned int index)
    {
        if (rozmiarListy == 0)
        {
            return NULL;
        }
        index = index % rozmiarListy;
        ElementListy* elementListy;
        if (index == 0)
        {
            return glowa;
        }
        else if (rozmiarListy / index >= 2)
        {
            elementListy = glowa;
            for (int i = 0; i != index; i++)
            {
                elementListy = elementListy->nastepny;
            }
        }
        else
        {
            elementListy = ogon;
            for (int i = rozmiarListy - 1; i != index; i--)
            {
                elementListy = elementListy->poprzedni;
            }
        }
        return elementListy;
    }
    bool Lista::usunElement(ElementListy* elementListy)
    {
        if (elementListy == NULL)
        {
            return false;
        }
        //mozna usunac jedna linie chyba
        if (elementListy == glowa)
        {
            glowa = elementListy->nastepny;
        }
        if (elementListy == ogon)
        {
            ogon = elementListy->poprzedni;
        }
        ElementListy* nastepny = elementListy->nastepny;
        ElementListy* poprzedni = elementListy->poprzedni;
        (elementListy->poprzedni)->nastepny = nastepny;
        (elementListy->nastepny)->poprzedni = poprzedni;

        delete elementListy;
        rozmiarListy--;
        return true;
    }
    Lista::Lista()
    {
        glowa = nullptr;
        ogon = nullptr;
        rozmiarListy = 0;
    }
    void Lista::dodajNaPoczatku(int element)
    {
        glowa = wstawPrzed(glowa, element);
    }
    void Lista::dodajNaKoncu(int element)
    {
        wstawPo(ogon, element);
    }
    bool Lista::usunNaPoczatku()
    {
        if (rozmiarListy > 0)
        {
            return usunElement(glowa);
        }
        return false;
    }
    bool Lista::usunNaKoncu()
    {
        if (rozmiarListy > 0)
        {
            return usunElement(ogon);
        }
        return false;
    }
    void Lista::dodajPo(int element, unsigned int index)
    {
        wstawPo(znajdzElement(index), element);
    }
    void Lista::dodajPrzed(int element, unsigned int index)
    {
        wstawPrzed(znajdzElement(index), element);
    }
    unsigned int Lista::zwrocRozmiarListy()
    {
        return rozmiarListy;
    }
    int Lista::zwrocElement(unsigned int index)
    {
        if (rozmiarListy == 0)
        {
            return 0;
        }
        ElementListy* elementListy = znajdzElement(index);

        return elementListy->element;
    }
    bool Lista::usunElement(unsigned int index)
    {
        return usunElement(znajdzElement(index));
    }
    bool Lista::usun(const int element)
    {
        if (rozmiarListy == 0)
            return false;
        ElementListy* elementListy = glowa;
        if (glowa->element == element)
        {
            usunElement(glowa);
            return true;
        }
        else
        {
            for (ElementListy* elementListy = glowa->nastepny; elementListy != ogon; elementListy = elementListy->nastepny)
            {
                if (elementListy->element == element)
                {
                    usunElement(elementListy);
                    return true;
                }
            }
            if (ogon->element == element)
            {
                usunElement(ogon);
                return true;
            }
            return false;
        }

    }
    bool Lista::dodaj(int odnosnikElement, int wstawianyElement)//1 zamieniono,0 niezamieniono,-1 dodano na poczatek
    {
        if (rozmiarListy == 0)
            return false;
        if (glowa->element == odnosnikElement)
        {
            wstawPo(glowa, wstawianyElement);
            return true;
        }
        else
        {
            for (ElementListy* elementListy = glowa->nastepny; elementListy != glowa; elementListy = elementListy->nastepny)
            {
                if (elementListy->element == odnosnikElement)
                {
                    wstawPo(elementListy, wstawianyElement);
                    return true;
                }
            }
            dodajNaPoczatku(wstawianyElement);
            return true;
        }
    }

    bool Lista::znajdzElementOdGlowy(const int element)
    {
        for (ElementListy* obecnyElement = glowa; obecnyElement != ogon; obecnyElement = obecnyElement->nastepny)
        {
            if (obecnyElement->element == element)
            {
                //std::cout << "Znaleziono element '" << element << "' !" << std::endl;
                return true;
            }
        }
        if (ogon->element == element)
        {
            //std::cout << "Znaleziono element '" << element << "' !" << std::endl;
            return true;
        }
        //std::cout << "Nie znaleziono elementu '" << element << "' :(" << std::endl;
        return false;
    }
    bool Lista::znajdzElementOdOgonu(const int element)
    {
        for (ElementListy* obecnyElement = ogon; obecnyElement != glowa; obecnyElement = obecnyElement->poprzedni)
        {
            if (obecnyElement->element == element)
            {
                //std::cout << "Znaleziono element '" << element << "' !" << std::endl;
                return true;
            }
        }
        if (glowa->element == element)
        {
            //std::cout << "Znaleziono element '" << element << "' !" << std::endl;
            return true;
        }
        //std::cout << "Nie znaleziono elementu '" << element << "' :(" << std::endl;
        return false;
    }
    void Lista::wyswietlListe()
    {
        if (rozmiarListy == 0)
            return;
        if (rozmiarListy > 1)
            std::cout << std::endl << "<(glowa)" << glowa->element << ">";
        else if (rozmiarListy == 1)
            std::cout << std::endl << "<(glowa/ogon)" << glowa->element << ">";
        ElementListy* elementListy = glowa->nastepny;
        for (unsigned int i = 1; elementListy != ogon; elementListy = elementListy->nastepny)
        {
            std::cout << "<" << elementListy->element << ">";
            if (i % 10 == 9)
            {
                std::cout << std::endl;
            }
            i++;
        }
        if (rozmiarListy > 1)
            std::cout << std::endl << "<(ogon)" << ogon->element << ">";
        std::cout << std::endl;
    }
    Lista::Lista(std::string fileName)
    {
        Lista();
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
    Lista::~Lista()
    {
        while (rozmiarListy > 0)
        {
            usunElement((unsigned int)0);
        }
    }
