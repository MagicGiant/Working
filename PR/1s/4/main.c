#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "notation.h"

FILE* fin;
int ID3_size;

int scan_size(int number)
{
    char *bits=(char*)malloc(number*7+1);
    bits[number*7]=0;
    for (int i=0; i<number; i++)
    {
        int data=0;
        fread(&data, 1, 1, fin);
        bits=get_10_2(data, 7, i, bits);
    }
    int data=get_2_10(bits);
    free(bits);
    return data;
}

void frame()
{
    int it=0;
    while (it<ID3_size)
    {
        char frame[5];
        int frame_size=0;
        fread (frame, 4, 1, fin);
        frame_size = scan_size(4);
        fseek(fin, 2, SEEK_CUR);
        for (int i=0; i< frame_size; i++)
        {
            char data=0;
            fread(&data, 1, 1, fin);
            printf("%c", data);
        }
        it+=4+4+frame_size;
        printf("\n");
    }
}
void read_file()
{
    //узнаём длину
    fseek(fin, 6, SEEK_SET);
    ID3_size=scan_size(4);
    //читаем фреймы
    fseek(fin, 10, SEEK_SET);
    frame();
}
int main(int argc, char *argv[])
{
    fin = fopen ("2.mp3", "rb");
    read_file();
    return 0;
}