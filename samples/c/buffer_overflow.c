#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv) {
    char buf1 [16];
    char buf2 [32];
    printf ("stack\n");
    memset (buf1, '1', 16);
    memset (buf2, '2', 32+atoi(argv[1]));
    printf ("buf1 = %s\n", buf1);
    printf ("buf2 = %s\n", buf2);
    getch();
    return 0;
}
