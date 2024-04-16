#include <iostream>
#include <vector>
#include <future>
#include <thread>

//Zadanie 4
//Napisz funkcje która zwraca sume dwóch liczb. Użyj vector<packaged_task> oraz vector<future> aby uzyskać 5 wyników dodawania różnych liczb.

int dodawanie(int a, int b)
{
    return a + b;
}

void przypisz(std::vector<std::packaged_task<int(int, int)>>& zadania, std::vector<std::future<int>>& wyniki)
{
    for (int i = 0; i < zadania.size(); ++i)
    {
        zadania[i] = std::packaged_task<int(int, int)>(dodawanie);
        while (!zadania[i].valid()) {}
        wyniki[i] = zadania[i].get_future();
    }
}

void skladniki(std::vector<std::packaged_task<int(int, int)>>& zadania, std::vector<std::future<int>>& wyniki)
{
    for (int i = 0; i < zadania.size(); ++i) 
        zadania[i](i + 1, i + 2);
}

int main() 
{
    std::vector<std::packaged_task<int(int, int)>> zadania(5);
    std::vector<std::future<int>> wyniki(5);
    std::vector<std::thread> watki;

    std::thread t1(przypisz, std::ref(zadania), std::ref(wyniki));
    std::thread t2(skladniki, std::ref(zadania), std::ref(wyniki));

    t1.join();
    t2.join();

    for (int i = 0; i < wyniki.size(); ++i)
        std::cout << "Wynik " << i + 1 << ": " << wyniki[i].get() << std::endl;
}