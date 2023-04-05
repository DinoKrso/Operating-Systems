#include <stdlib.h>

int main() {
    int *ptr = malloc(sizeof(int));
    return 0;
}


*When this program runs, it will allocate memory using malloc() to store 
an integer. However, since the program does not call free() to release the 
memory before exiting, the memory remains allocated even after the program 
finishes. This can lead to memory leaks, where the memory is not available 
for other programs to use.*/
