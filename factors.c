#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> factorize(int number) {
    std::vector<int> factors;
    for (int i = 2; i * i <= number; i++) {
        while (number % i == 0) {
            factors.push_back(i);
            number /= i;
        }
    }
    if (number > 1) {
        factors.push_back(number);
    }
    return factors;
}

void printFactorization(int number, int p, int q) {
    std::cout << number << "=" << p << "*" << q << "\n";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: factors <file>\n";
        return 0;
    }

    std::ifstream file(argv[1]);
    if (!file.is_open()) {
        std::cout << "Failed to open the file.\n";
        return 0;
    }

    int number;
    while (file >> number) {
        std::vector<int> factors = factorize(number);
        int size = factors.size();
        for (int i = 0; i < size / 2; i++) {
            int p = factors[i];
            int q = factors[size - i - 1];
            printFactorization(number, p, q);
        }
    }

    file.close();
    return 0;
}
