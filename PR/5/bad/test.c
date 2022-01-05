#include <stdio.h>

int main()
{
   
    FILE *fin = fopen("small_3.bmp", "rb");
    FILE *fout = fopen("out.bmp", "wb");
    char ch;
    while(!feof(fin))
    {
        ch=getc(fin);
        putc(ch, fout);
    }
    return 0;
}