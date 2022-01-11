#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{

    int input[] = {3, 4, 3, 1, 2};
    int *simulation = malloc(sizeof(input) / sizeof(*input) * sizeof(int));

    for (int i = 0; i < sizeof(input) / sizeof(*input); ++i)
    {
        simulation[i] = input[i];
        printf("%i", simulation[i]);
    }
    printf("\n");
    int eggcounter = 0;
    int position_egg = 0;
    for (int j = 0; j < 5; ++j)
    {
        for (int i = 0; i < 5+j; ++i)
        {
            simulation[i] -= 1;
            printf("%i", simulation[i]);
            if(simulation[i] == 0) {
                eggcounter += 1;
                position_egg = simulation[i];
            }
            
            
        }
        printf("\n");
        simulation[position_egg] = 6;        
    }
    printf("%i", eggcounter);

    return 0;
}