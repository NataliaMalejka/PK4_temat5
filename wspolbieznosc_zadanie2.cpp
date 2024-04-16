#include <iostream>
#include <future>

//Stwórz dwie funkcje przeciążone.Niech pierwsza zwraca sumę dwóch liczb typu int, a druga typu double.
//Wykorzystaj std::future, std::async oraz wyrażenie lambda.


int suma(int a, int b)
{
    return a + b;
}

double suma(double a, double b)
{
    return a + b;
}

int main()
{
    std::future<int> future_int = std::async(std::launch::async, [](int a, int b) {return suma(a, b);}, 12, 11);
    std::future<double> future_double = std::async(std::launch::async, [](double a, double b) {return suma(a, b);}, 1.2, 1.1);

    std::cout << "wynik dodawania (int): " << future_int.get() << std::endl;
    std::cout << "wynik dodawania (double): " << future_double.get() << std::endl;
}

