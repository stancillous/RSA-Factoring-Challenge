#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("usage error\n");
    return (1);
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL)
  {
    printf("failed to open file");
    return (1);
  }
  char line[98];
  while (fgets(line, sizeof(line), file) != NULL)
    {
      unsigned long long int num = atoi(line), counter = 2, fact1, fact2;

      while (counter <= num)
        {
          if (num % counter == 0)
          {
            fact1 = counter;
            fact2 = num / counter;
            break;
          }
            counter++;
        }

      printf("%llu = %llu * %llu\n", num, fact2, fact1);

      
    }

  return (0);

}
