#include <iostream>
#include <cmath>

std::string binary(int decimal) {
    if (decimal < 2) {
        return std::to_string(decimal);
    }
    return binary(decimal / 2) + std::to_string(decimal % 2);
}

std::string binary(double decimal) {
    if (decimal == 0) {
        return "0";
    }
    decimal *= 2;
    if (decimal >= 1) {
        return "1" + binary(decimal - 1.0);
    }
    else {
        return "0" + binary(decimal);
    }
}

std::string toBinary(double decimal) {
    return binary((int)floor(decimal)) + "." + binary(decimal - floor(decimal));
}

int main() {
    double decimal;
    std::cin >> decimal;
    std::cout << toBinary(decimal) << '\n';
}
