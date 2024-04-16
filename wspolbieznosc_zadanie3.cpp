#include <iostream>
#include <thread>
#include <future>

//Zadanie 3
//Oblicz napięcie prądu. W funkcji void natężenie oblicz wartość I=Q/t,
//w funkcji void rezystancja oblicz rezystancje zastępczą dla rezystorów połączonych równolegle R = R1 * R2 / (R1 + R2),
//a w funkcji main oblicz napięcie U = I * R. Wykorzystaj std::future, std::promise oraz std::thread.

void natezenie(std::promise<float>& promise, float Q, float t)
{
    float I = Q / t;
    promise.set_value(I);
    std::cout << "Natezenie pradu jest rowne: " << I <<std::endl;
}

void rezystancja(std::promise<float>& promise, float R1, float R2 )
{
    float R = R1 * R2 / (R1 + R2);
    promise.set_value(R);
    std::cout << "Rezystancja zastepcza jest rowna: " << R << std::endl;
}

int main() 
{
    std::promise<float> promise_natezenie;
    std::promise<float> promise_rezystancja;

    std::future<float> future_natezenie = promise_natezenie.get_future();
    std::future<float> future_rezystancja = promise_rezystancja.get_future();

    std::thread t1(natezenie, std::ref(promise_natezenie), 6.f, 2.f);
    t1.join();

    std::thread t2(rezystancja, std::ref(promise_rezystancja), 2.F, 3.F);

    float U = future_natezenie.get() * future_rezystancja.get();

    t2.join();

    std::cout  << "Napiecie jest rowne: " << U <<std::endl;

}
