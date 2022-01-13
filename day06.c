#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{

    int input[] = {3, 4, 3, 1, 2};
    int *simulation = calloc(sizeof(input) / sizeof(*input), sizeof(int));

    for (int i = 0; i < sizeof(input) / sizeof(*input); ++i)
    {
        simulation[i] = input[i];
        printf("%i", simulation[i]);
    }
    printf("\n");
    int eggcounter = 0;
    int *position_egg = 0;
    int length_simulation = sizeof(simulation) / sizeof(*simulation);
    
    for (int j = 0; j < 5; ++j)
    {
        printf("After %i days: ", j);

        for (int i = 0; i < 6; ++i)
        {
            simulation[i] -= 1;
            printf("%i", simulation[i]);

            if (simulation[i] == 0)
            {
                eggcounter += 1;
                position_egg = simulation + i;
            }
        }
        printf("\n");
        printf("%i", eggcounter);
        
        for(int x = 0; x<eggcounter; ++x){
            simulation[length_simulation+x] = 8;
        }
        
        position_egg[0] = 7;
        eggcounter = 0;
        
    }

    return 0;
}