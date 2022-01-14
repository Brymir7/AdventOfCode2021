#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{

    int input[] = {4, 3, 4, 5, 2, 1, 1, 5, 5, 3, 3, 1, 5, 1, 4, 2, 2, 3, 1, 5, 1, 4, 1, 2, 3, 4, 1, 4, 1, 5, 2, 1, 1, 3, 3, 5, 1, 1, 1, 1, 4, 5, 1, 2, 1, 2, 1, 1, 1, 5, 3, 3, 1, 1, 1, 1, 2, 4, 2, 1, 2, 3, 2, 5, 3, 5, 3, 1, 5, 4, 5, 4, 4, 4, 1, 1, 2, 1, 3, 1, 1, 4, 2, 1, 2, 1, 2, 5, 4, 2, 4, 2, 2, 4, 2, 2, 5, 1, 2, 1, 2, 1, 4, 4, 4, 3, 2, 1, 2, 4, 3, 5, 1, 1, 3, 4, 2, 3, 3, 5, 3, 1, 4, 1, 1, 1, 1, 2, 3, 2, 1, 1, 5, 5, 1, 5, 2, 1, 4, 4, 4, 3, 2, 2, 1, 2, 1, 5, 1, 4, 4, 1, 1, 4, 1, 4, 2, 4, 3, 1, 4, 1, 4, 2, 1, 5, 1, 1, 1, 3, 2, 4, 1, 1, 4, 1, 4, 3, 1, 5, 3, 3, 3, 4, 1, 1, 3, 1, 3, 4, 1, 4, 5, 1, 4, 1, 2, 2, 1, 3, 3, 5, 3, 2, 5, 1, 1, 5, 1, 5, 1, 4, 4, 3, 1, 5, 5, 2, 2, 4, 1, 1, 2, 1, 2, 1, 4, 3, 5, 5, 2, 3, 4, 1, 4, 2, 4, 4, 1, 4, 1, 1, 4, 2, 4, 1, 2, 1, 1, 1, 1, 1, 1, 3, 1, 3, 3, 1, 1, 1, 1, 3, 2, 3, 5, 4, 2, 4, 3, 1, 5, 3, 1, 1, 1, 2, 1, 4, 4, 5, 1, 5, 1, 1, 1, 2, 2, 4, 1, 4, 5, 2, 4, 5, 2, 2, 2, 5, 4, 4};
    int length_input = sizeof(input) / sizeof(*input);
    int *simulation = malloc(length_input * sizeof(int));
    printf("Starting value: ");
    for (int i = 0; i < length_input; ++i)
    {
        simulation[i] = input[i];
        printf("%i", simulation[i]);
    }
    printf("\n");
    int length_simulation = length_input;
    int eggcounter = 0;
    for (int days = 0; days < 256; ++days)
    {

        for (int i = 0; i < length_simulation; ++i)
        {
            if (simulation[i] == 0)
            {
                simulation[i] = 7;
                eggcounter += 1;
            }
        }
        length_simulation += eggcounter;
        simulation = realloc(simulation, (length_simulation + 1) * sizeof(int));

        for (int x = 0; x < eggcounter; --eggcounter)
        {

            simulation[length_simulation - eggcounter] = 9;
        }
        printf("Day %i: ", days);
        for (int i = 0; i < length_simulation; ++i)
        {
            simulation[i] -= 1;
            printf("%i", simulation[i]);
        }
        printf("\n");
    }
    printf("%i \n", length_simulation);
    free(simulation);
    return 0;
}