#include <stdio.h>
#include <stdlib.h>


#include "../../lib/pt-1.4/pt.h"

struct pt pt1;



typedef void (func *)(void);

func func1;

int fun1(int a)
{
    return printf("xxx %d\n",a);
}

int main()
{
    em_thread(&pt1);
    printf("Hello world!\n");

    func1 = fun1;
    fun1(1);

    return 0;
}
