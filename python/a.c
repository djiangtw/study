#include <stdlib.h>
#include <stdio.h>

void print_master() {
    printf("this is a master.\n");
}

void print_test() {
    printf("this is a test!");
}

int main(int argc, char** argv)
{
    print_master();
    print_test();
    printf("hello world!\n");
    return 0;
}
