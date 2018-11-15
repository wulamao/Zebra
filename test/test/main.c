#include <stdio.h>
#include <stdlib.h>


#include "../../lib/pt-1.4/pt.h"

struct pt pt1;

int main()
{
    em_thread(&pt1);
    printf("Hello world!\n");
    return 0;
}
