#include <stdlib.h>
#include <stdio.h>

int main() {
    int* data = (int*) malloc(100 * sizeof(int));
    free(data);

    printf("data[0]: %d\n", data[0]);

    return 0;
}

