#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * gcd - calculates the greatest common divisor of two numbers.
 * @a: the first number
 * @b: the second number
 * Return: the greatest common divisor of a and b
 */
unsigned long long gcd(unsigned long long a, unsigned long long b)
{
unsigned long long temp;
while (b != 0)
{
temp = b;
b = a % b;
a = temp;
}
return (a);
}

/**
 * is_prime - checks if a number is prime.
 * @number: the number to check
 * Return: true if the number is prime, false otherwise
 */
bool is_prime(unsigned long long number)
{
if (number <= 1)
return (false);

unsigned long long i;
for (i = 2; i * i <= number; i++)
{
if (number % i == 0)
return (false);
}

return (true);
}

/**
 * pollard_rho - performs Pollard's rho algorithm for prime factorization.
 * @n: the number to factorize
 * Return: the prime factor of n
 */

unsigned long long pollard_rho(unsigned long long n)
{
unsigned long long x = 2, y = 2, d = 1;

while (d == 1)
{
x = (x *x + 1) % n;
y = (y *y + 1) % n;
y = (y *y + 1) % n;
d = gcd(abs(x - y), n);
}

if (d == n)
return (0);

return (d);
}

/**
 * factorize - factors the RSA number n into its prime factors.
 * @n: the RSA number to factorize
 */
void factorize(unsigned long long n)
{
if (is_prime(n))
{
printf("%llu=%llu*1\n", n, n);
return;
}

unsigned long long factor = pollard_rho(n);
if (factor == 0)
{
printf("Failed to factorize the number.\n");
return;
}

printf("%llu=%llu*%llu\n", n, factor, n / factor);
}

/**
 * main - entry point of the program.
 * @argc: the number of arguments
 * @argv: an array of argument strings
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
if (argc != 2)
{
printf("Usage: rsa <file>\n");
return (1);
}

FILE *file = fopen(argv[1], "r");
if (!file)
{
printf("Failed to open the file.\n");
return (1);
}

unsigned long long number;
if (fscanf(file, "%llu", &number) != 1)
{
printf("Invalid input.\n");
fclose(file);
return (1);
}

factorize(number);

fclose(file);
return (0);
}
