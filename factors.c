#include <stdio.h>
#include <stdlib.h>

/*
 * factorize - takes an integer 'number' as input
 * and factors it into two smaller numbers.
 * It iterates from 2 up to the square root of the input number.
 * For each iteration, it checks if the current number divides evenly into the input number.
 * If it does, it calculates the factors 'p' and 'q' by dividing the input number by the current iteration.
 * It then prints the factorization in the format "number = p * q".
 * The function continues this process until the input number is fully factorized.
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

/*
 * main - entry point of the program.
 * It takes command-line arguments 'argc' and 'argv',
 * which represent the number of arguments and an array of argument strings, respectively.
 * The function first checks if the number of arguments is not equal to 2.
 * If this condition is true, it prints a usage message and returns from the program.
 * Otherwise, it attempts to open the file specified in the second argument (argv[1]).
 * If the file fails to open, it prints an error message and returns from the program.
 * Inside the main loop, the function reads each line from the file,
 * converts it to an integer, and calls the 'factorize' function to factorize the number.
 * After processing all the numbers in the file, the function closes the file and returns 0.
 */

int main(int argc, char* argv[])
{
if (argc != 2)
{
printf("Usage: factors <file>\n");
return (1);
}

FILE* file = fopen(argv[1], "r");
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
