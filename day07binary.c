#include <stdlib.h>
#include <stdio.h>
int fuelcost(int a, int *b, int length_b)
{
    int fuelcost1 = 0;
    for (int i = 0; i < length_b; ++i)
    {
        fuelcost1 = fuelcost1 + abs(a - b[i]);
    }
    return fuelcost1;
}
int max_value(int *a, int length_a)
{
    int value = a[0];
    for (int i = 0; i < length_a; ++i)
    {
        if (a[i] > value)
        {
            value = a[i];
        }
    }
    return value;
}

int binary_search(int* a, int min, int max, int bestposition)
{
    int mid = (min + max) / 2;
    if(a[mid] == bestposition){
        return mid;
    }
    return 0;
}
int main(int argc, char **argv)
{
    int input[] = {16, 1, 2, 0, 4, 2, 7, 1, 2, 14};
    int length_input = sizeof(input) / sizeof(*input);
    int *temporary_array = malloc(length_input * sizeof(int));
    for (int i = 0; i < length_input; ++i)
    {
        temporary_array[i] = input[i];
        printf("%i ", temporary_array[i]);
    }
    int best_position = 0;
    int max_value1 = max_value(temporary_array, length_input);
    int middle_value = 0;
    
    
    int output_fuelcost = fuelcost(best_position, temporary_array, length_input);
    printf("%i", output_fuelcost);
    return 0;
}