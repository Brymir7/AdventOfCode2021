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
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void print_integer_array(int *a, int length)
{
    for (int i = 0; i < length; ++i)
    {
        printf("%i ", a[i]);
    }
    printf("\n");
}
void bubblesort(int *a, int length)
{

    for (int i = 0; i < length; ++i)
    {
        for (int j = 0; j < length - i; ++j)
        {
            if (a[j] > a[j + 1])
            {
                swap(a + j, a + j + 1);  // Swap addresses not actual values
            }
        }
    }
}
int binary_search(int min, int max, int *a, int length_a)
{
    int middle = (min + max) / 2;
    int fuelcost1 = fuelcost(middle - 1, a, length_a);
    int fuelcost2 = fuelcost(middle, a, length_a);
    if ((max - min) == 1)
    {
        return 1;
    }
    if (fuelcost1 < fuelcost2)
    {
        return binary_search(0, middle - 1, a, length_a);
    }
    else if (fuelcost2 < fuelcost1)
    {
        return binary_search(middle, max, a, length_a);
    }
    return -1;
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
    printf("\n");
    bubblesort(temporary_array, length_input);
    print_integer_array(temporary_array, length_input);
    int max_value1 = max_value(temporary_array, length_input);
    int best_position = binary_search(0, max_value1, temporary_array, length_input);
    printf("%i \n", best_position);
    int output_fuelcost = fuelcost(best_position, temporary_array, length_input);
    printf("%i", output_fuelcost);
    return 0;
}