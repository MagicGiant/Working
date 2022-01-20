#include <stdio.h>
#include "notation.h"
FILE *file;
void print_size(int data)
{
    char *bits=(char*)malloc(33);
    bits[32]=0;
    bits = get_10_2(data, 32, 0, bits);
    char new_bits[33];
    new_bits[32]=0;
    int j=3;
    for (int i=28; i>=0; i--)
    {
        if((i+3)%8==0)
        {
            new_bits[i+j]='0';
            j--;
        }
        new_bits[i+j]=bits[i+3];
    }
    free(bits);
    for (int i=0; i<4; i++)
    {
        char arr[9];
        arr[8]=0;
        for (int k=i*8; k<(i+1)*8; k++)
            arr[k-i*8]=new_bits[k];
        printf("%i\n", get_2_10(arr));
    }
}
int main()
{
    print_size(1356543);
    return 0;
}