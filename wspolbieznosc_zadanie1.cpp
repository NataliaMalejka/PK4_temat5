#include <iostream>
#include <thread>

//zadanie 1
//Napisz program który tworzy dwa wątki. 
//Każdy z wątków ma wyświetlić inny komunikat na standardowym wyjściu,
//a następnie za pomocą petli obliczyć i wyświetlić 5 kolejnych potęgę liczby całkowitej. 
//Jeden wątek nie może przerwać drugiemu.


void wypisz(const std::string& wiadomosc, const int& a)
{
    std::cout << wiadomosc << std::endl;
    int wynik = a;

    for (int i = 1; i < 5; i++)
    {
        //std::cout << a << "^" << i << "=" << wynik << std::endl;
        printf("%.0i^%0i = %.0i \n", a, i, wynik);
        wynik *= a;
    }
    printf("wynik: %.0i^5 = %.0i \n", a, wynik);
}

int main()
{
    std::thread thread1(wypisz, "Obliczenia ktore wykonal watek 1: ", 7);
    thread1.join();

    std::thread thread2(wypisz, "Obliczenia ktore wykonal l watek 2: ", 5);
    thread2.join();
}

