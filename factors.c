#include <stdio.h>
#include <stdlib.h>

void factorize(int number)
{
int i, p, q;
for (i = 2; i * i <= number; i++)
{
while (number % i == 0)
{
p = i;
q = number / i;
printf("%d=%d*%d\n", number, p, q);
number = q;
}
}
if (number > 1)
{
p = number;
q = 1;
printf("%d=%d*%d\n", number, p, q);
}
}

int main(int argc, char* argv[])
{
if (argc != 2) {
printf("Usage: factors <file>\n");
return (0);
}

FILE* file = fopen(argv[1], "r");
if (!file)
{
printf("Failed to open the file.\n");
return (0);
}

int number;
while (fscanf(file, "%d", &number) != EOF) {
factorize(number);
}

fclose(file);
return (0);
}
