#include <stdio.h>
#include <stdlib.h>
int length_line(int *a)
{
    int counter = 0;
    for (int i = 0; a[i] != -1; ++i)
    {
        counter += 1;
    }
    return counter;
}
int is_minimum_at_location(int *a, int index, int length_line, int size)
{
    if (a[index] < a[index - length_line])
    {
        if (a[index] < a[index - 1])
        {
            if (a[index] < a[index + 1])
            {
                if (a[index] < a[index + length_line])
                {
                    return 1;
                }
            }
        }
    }
    else
    {
        return -1;
    }
}
int main(int argc, char **argv)
{
    int input[] = {
        2, 1, 9, 9, 9, 4, 3, 2, 1, 0,
        3, 9, 8, 7, 8, 9, 4, 9, 2, 1,
        9, 8, 5, 6, 7, 8, 9, 8, 9, 2,
        8, 7, 6, 7, 8, 9, 6, 7, 8, 9,
        9, 8, 9, 9, 9, 6, 5, 6, 7, 8};

    int length_line1 = 10;
    int length_input = sizeof(input) / sizeof(*input);
    printf("%i \n", length_line1);
    printf("%i \n", length_input);
    for (int i = 0; i < length_input; ++i)
    {
        if(is_minimum_at_location(input, i, length_line1, length_input) == 1){
            printf("Index at which minimum : %i\n", i);
            printf("Value at Index: %i\n", input[i]);
        }
    }

    return 0;
}