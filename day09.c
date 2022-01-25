#include <stdio.h>
#include <stdlib.h>
int length_line(int* a){
    int counter = 0;
    for(int i = 0; a[i] != -1; ++i){
        counter +=1;
    }
    return counter;
}
int main (int argc,  char** argv){
int input[] = {
2,1,9,9,9,4,3,2,1,0, -1,
3,9,8,7,8,9,4,9,2,1, -1,
9,8,5,6,7,8,9,8,9,2, -1,
8,7,6,7,8,9,6,7,8,9, -1,
9,8,9,9,9,6,5,6,7,8, -1
};

int length_line1 = length_line(input);
int length_input = sizeof(input) / sizeof(*input);
printf("%i \n", length_line1 );
printf("%i \n", length_input);
for(int i = 0; i<length_input; ++i){
    if(input[i] != -1){
        i
}

    return 0;   
}