#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("%zu\n", sizeof(char));
    printf("%zu\n", sizeof(int));
    printf("%zu\n", sizeof(float));
    printf("%zu\n", sizeof(double));
    printf("%zu\n", sizeof(void)); // This is not right!
    printf("%zu\n", sizeof(void *)); 

    int a_chiquita = 10;
    int * p_a_chiquita = &a_chiquita;
    int calificaciones[30];
    printf("%zu\n", sizeof(calificaciones)); 

    //printf("%d\n", a_chiquita);
    //printf("%p\n", &a_chiquita);

    return 0;
}