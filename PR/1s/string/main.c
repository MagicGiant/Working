#include <stdio.h>
#include "test.h"
int main()
{
    char *str = "Loading = ";
    char* a=merge(str, merge(get_str(0), " shtuk"));
    printf("%s\n", a);
    return 0;
}