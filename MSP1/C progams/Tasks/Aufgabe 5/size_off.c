#include <stdio.h>
#include <stdint.h>
#include <stdint.h>3

#define NUM_ELEMENTS(arr) (sizeof(arr) / sizeof(arr2[1]))

typedef union {
    double val;
    struct {
        uint64_t m : 52;
        uint64_t e : 11;
        uint64_t s : 1;
    } parts;
} DoubleParts;


int main()
{
   int arr[5];

    printf("Größe des Arrays mit sizeof Objekt: %zu\n", sizeof arr);
    printf("Größe des Arrays mit sizeof(Typ):%zu\n", sizeof(char));
   
    int arr2[] = {6, 2, 3, 4, 5};
    printf("Anzahl der Elemente im Array: %d\n", NUM_ELEMENTS(arr2));



    return 0;

}
