#include <stdio.h>
int f()
{
    static int a=0;
    a++;
    return a;
}
int main(int argc, char *argv[])
{
    for (int i=0; i<10; i++)
        f();
    printf("%i", f());
    return 0;
}