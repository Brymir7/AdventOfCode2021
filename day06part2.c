#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main(int argc, char **argv)
{   struct timespec begin, end;
    clock_gettime(CLOCK_MONOTONIC_RAW, &begin);

    long input[] = {4, 3, 4, 5, 2, 1, 1, 5, 5, 3, 3, 1, 5, 1, 4, 2, 2, 3, 1, 5, 1, 4, 1, 2, 3, 4, 1, 4, 1, 5, 2, 1, 1, 3, 3, 5, 1, 1, 1, 1, 4, 5, 1, 2, 1, 2, 1, 1, 1, 5, 3, 3, 1, 1, 1, 1, 2, 4, 2, 1, 2, 3, 2, 5, 3, 5, 3, 1, 5, 4, 5, 4, 4, 4, 1, 1, 2, 1, 3, 1, 1, 4, 2, 1, 2, 1, 2, 5, 4, 2, 4, 2, 2, 4, 2, 2, 5, 1, 2, 1, 2, 1, 4, 4, 4, 3, 2, 1, 2, 4, 3, 5, 1, 1, 3, 4, 2, 3, 3, 5, 3, 1, 4, 1, 1, 1, 1, 2, 3, 2, 1, 1, 5, 5, 1, 5, 2, 1, 4, 4, 4, 3, 2, 2, 1, 2, 1, 5, 1, 4, 4, 1, 1, 4, 1, 4, 2, 4, 3, 1, 4, 1, 4, 2, 1, 5, 1, 1, 1, 3, 2, 4, 1, 1, 4, 1, 4, 3, 1, 5, 3, 3, 3, 4, 1, 1, 3, 1, 3, 4, 1, 4, 5, 1, 4, 1, 2, 2, 1, 3, 3, 5, 3, 2, 5, 1, 1, 5, 1, 5, 1, 4, 4, 3, 1, 5, 5, 2, 2, 4, 1, 1, 2, 1, 2, 1, 4, 3, 5, 5, 2, 3, 4, 1, 4, 2, 4, 4, 1, 4, 1, 1, 4, 2, 4, 1, 2, 1, 1, 1, 1, 1, 1, 3, 1, 3, 3, 1, 1, 1, 1, 3, 2, 3, 5, 4, 2, 4, 3, 1, 5, 3, 1, 1, 1, 2, 1, 4, 4, 5, 1, 5, 1, 1, 1, 2, 2, 4, 1, 4, 5, 2, 4, 5, 2, 2, 2, 5, 4, 4};
    long length_input = sizeof(input) / sizeof(*input);
    long fish[9] = {0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < length_input; ++i)
    {
        long value = input[i];
        fish[value] += 1;
    }

    for (int i = 0; i <= 8; ++i)
    {
        printf("Amount of age %i fish: %i \n", i, fish[i]);
    }
    long temp1 = 0;
    for (int j = 0; j < 256; ++j)
    {
        for (int i = 0; i <= 8; ++i)
        {
            fish[i - 1] = fish[i];
            if (i == 8)
            {
                fish[8] = 0;
            }
        }
        fish[6] += temp1;
        fish[8] += temp1;
        temp1 = fish[0];
        printf("Day: %i \n", j + 1);
        for (int i = 0; i <= 8; ++i)
        {
            printf("Amount of age %li fish: %li \n", i, fish[i]);
        }
    }
    long output = 0;
    for (int i = 0; i < 9; ++i)
    {
        output += fish[i];
    }
    printf("output: %li \n", output);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    printf("Total time = %f seconds\n",(end.tv_nsec - begin.tv_nsec) / 1000000000.0 +
            (end.tv_sec  - begin.tv_sec));
    return 0;
}