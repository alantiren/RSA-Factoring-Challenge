#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

// Function to calculate the greatest common divisor
uint64_t gcd(uint64_t a, uint64_t b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Pollard's rho algorithm for factorization
uint64_t pollard_rho(uint64_t n) {
    uint64_t x = rand() % n;
    uint64_t y = x;
    uint64_t c = rand() % (n - 1) + 1;
    uint64_t d = 1;

    while (d == 1) {
        x = (x * x + c) % n;
        y = (y * y + c) % n;
        y = (y * y + c) % n;
        d = gcd(abs(x - y), n);
    }

    return d;
}

// Function to check if a number is prime
bool is_prime(uint64_t number) {
    if (number <= 1) {
        return false;
    }
    if (number <= 3) {
        return true;
    }
    if (number % 2 == 0 || number % 3 == 0) {
        return false;
    }

    for (uint64_t i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

// Function to factorize the given number into prime factors
void factorize(uint64_t number) {
    if (is_prime(number)) {
        printf("%lu=%lu*%lu\n", number, number, 1);
        return;
    }

    uint64_t factor = pollard_rho(number);
    while (!is_prime(factor)) {
        factor = pollard_rho(factor);
    }

    uint64_t p = factor;
    uint64_t q = number / factor;
    printf("%lu=%lu*%lu\n", number, p, q);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./rsa <file>\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    srand(time(NULL));

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        uint64_t number = strtoull(line, NULL, 10);
        factorize(number);
    }

    fclose(file);
    return 0;
}
