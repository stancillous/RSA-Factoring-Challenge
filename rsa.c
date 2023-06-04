#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(unsigned long long int num) {
    if (num <= 1)
        return false;
    
    if (num == 2 || num == 3)
        return true;

    if (num % 2 == 0 || num % 3 == 0)
        return false;

    unsigned long long int divisor = 6;
    while (divisor - 1 <= sqrt(num)) {
        if (num % (divisor - 1) == 0)
            return false;

        if (num % (divisor + 1) == 0)
            return false;

        divisor += 6;
    }

    return true;
}

int main(int argc, char *argv[]) {
    FILE *file;
    size_t count;
    ssize_t line;
    char *buffer = NULL;

    if (argc != 2) {
        fprintf(stderr, "Usage Error\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: can't open file %s\n", argv[1]);
        return 1;
    }

    while ((line = getline(&buffer, &count, file)) != -1) {
        unsigned long long int num, i;

        num = strtoull(buffer, NULL, 10);

        for (i = 2; i < num; i++) {
            if (num % i == 0 && isPrime(i) && isPrime(num / i)) {
                printf("%llu = %llu * %llu\n", num, num / i, i);
                break;
            }
        }
    }

    free(buffer);
    fclose(file);

    return 0;
}

