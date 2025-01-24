#include "duration.h"
#include <iostream>
#include <cassert>
#include <string>

void test_add() {
    Duration dur1(10, "min"), dur2(20, "min");
    Duration sum = dur1.add(dur2);
    assert(sum.get_value() == 30);
}

void test_subtract(){
    Duration dur1(7, "hours"), dur2(5, "hours");
    Duration dif = dur1.subtract(dur2);
    assert(dif.get_value() == 2);
}

void test_multiply(){
    Duration dur1(15, "min");
    Duration mul = dur1.multiply(2);
    assert(mul.get_value() == 30);
}

void test_divide(){
    Duration dur1(10, "hours");
    Duration div = dur1.divide(5);
    assert(div.get_value() == 2);
}

int main() {
    double value1, value2, value3, value4;
    double multiplier, divisor;
    std::string unit1, unit2, unit3, unit4;

    // Citește intervalelor de timp
    std::cout << "Introduceti primul interval de timp:";
    std::cin >> value1 >> unit1;

    std::cout << "Introduceti al doilea interval de timp:";
    std::cin >> value2 >> unit2;

    // Crează obiectele Duration 1 și 2, 3 și 4 sunt mai jos
    Duration dur1(value1, unit1);
    Duration dur2(value2, unit2);

    std::cout << "dur1: " << dur1.to_string() << std::endl;
    std::cout << "dur2: " << dur2.to_string() << std::endl;

    // Apelează metodele de operare
    Duration sum = dur1.add(dur2);
    std::cout << "Suma: " << sum.to_string() << std::endl;

    Duration difference = dur1.subtract(dur2);
    std::cout << "Diferenta: " << difference.to_string() << std::endl;

    std::cout << "Introduceti o durata si un numar pentru inmultire:";
    std::cin >> value3 >> unit3;
    Duration dur3(value3, unit3);
    std::cin >> multiplier;
    Duration multiplied = dur3.multiply(multiplier);
    std::cout << "Inmultirea: " << multiplied.to_string() << std::endl;

    std::cout << "Introduceti o durata si un numar pentru impartire:";
    std::cin >> value4 >> unit4;
    Duration dur4(value4, unit4);
    std::cin >> divisor;
    Duration divided = dur4.divide(divisor);
    std::cout << "Impartirea: " << divided.to_string() << std::endl;

    // Apelează comparația
    int comparison = dur1.compare(dur2);
    std::cout << "Comparatia: " << comparison << std::endl;


    return 0;
}
