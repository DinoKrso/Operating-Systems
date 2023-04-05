
/* Next, create a little program that uses a certain amount of memory,
called memory-user.c. This program should take one commandline argument: 
the number of megabytes of memory it will use.
When run, it should allocate an array, and constantly stream through
the array, touching each entry. The program should do this indefinitely, 
or, perhaps, for a certain amount of time also specified at the
command line. */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MB (1024 * 1024)

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <memory in MB>\n", argv[0]);
        return 1;
    }

    int mem_size = atoi(argv[1]);
    int array_size = mem_size * MB / sizeof(int);

    printf("Allocating %d MB of memory...\n", mem_size);
    int* array = malloc(array_size * sizeof(int));
    if (array == NULL) {
        printf("Error: Unable to allocate memory.\n");
        return 1;
    }

    printf("Touching each entry of the array...\n");
    int index = 0;
    while (1) {
        array[index] = index;
        index = (index + 1) % array_size;
	free(array[index]) ;
}
}
