
#include <stdio.h>
#include <stdlib.h>

void close_files(void) ;
void cleanup_resources(void);

int main(void) {
    atexit(cleanup_resources);
    atexit(close_files);

    printf("Main function is executing.\n");
    printf("Exiting main function now...\n");

    return 0;
}
void cleanup_resources(void) {
    printf("Cleaning up resources...\n");
}

void close_files(void) {
    printf("Closing all open files...\n");
}

