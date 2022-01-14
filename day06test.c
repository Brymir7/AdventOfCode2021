#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{

    int input[] = {3, 4, 3, 1, 2};
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
    for (int days = 0; days < 5; ++days)
    {

        for (int i = 0; i < length_simulation; ++i)
        {
            if (simulation[i] == 0)
            {   int* temp = simulation;
                simulation = simulation + i;
                simulation[0] = 7;
                eggcounter += 1; 
                simulation = temp;            
            }
            
        }

        for (int x = 0; x < eggcounter; --eggcounter)
        {   int* temp = simulation;
            simulation = simulation + length_simulation;
            simulation[0] = 9;
            length_simulation += 1;
            simulation = temp;
        }
        // size_t new_size_simulation = length_simulation * sizeof(int);
        // simulation = realloc(simulation, new_size_simulation);
        
        
        printf("Day %i: ", days);
        for (int i = 0; i < length_simulation; ++i)
        {
            simulation[i] -= 1;
            printf("%i", simulation[i]);
        }
        
        printf("\n");
    }

    return 0;
}