#include <stdlib.h>
#include <stdio.h>

int main() {
    int* data = (int*) malloc(100 * sizeof(int));
    int* ptr = &data[50];

    free(ptr); // trying to free a pointer in the middle of the array

    free(data); // freeing the entire array correctly

    return 0;
}

