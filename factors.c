#include <stdio.h>
#include <stdlib.h>

/**
 * factorize - takes an integer 'number' as input
 * and factors it into two smaller numbers.
 * If it does, it calculates the factors 'p' and 'q' by
 * @number: the input number by the current iteration.
 * It then prints the factorization in the format "number = p * q".
 * The function continues this process until
 * the input number is fully factorized.
 */
void factorize(int number)
{
int i, p, q;

for (i = 2; i * i <= number; i++)
{
while (number % i == 0)
{
p = i;
q = number / i;
printf("%d = %d * %d\n", number, p, q);
number = q;
}
}

if (number > 1)
{
p = number;
q = 1;
printf("%d = %d * %d\n", number, p, q);
}
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
printf("Usage: factors <file>\n");
return (1);
}

FILE *file = fopen(argv[1], "r");
if (!file)
{
printf("Failed to open the file.\n");
return (1);
}

int number;
while (fscanf(file, "%d", &number) != EOF)
{
factorize(number);
}

fclose(file);
return (0);
}
