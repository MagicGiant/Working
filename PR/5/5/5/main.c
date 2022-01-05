#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

FILE* fout;
FILE* fin;

char code[10]={1,35,20,5,6,7,12,2,56,10};
int size;

struct arhivator
{
    int memory[4];
    char name[10];
    char* data;
};

bool new_check()
{
    char ch[10];
    fseek(fout, 0, SEEK_SET);
    fread(ch, 1, 10, fout);
    for (int i = 0; i < 10; i++)
        if (code[i] != ch[i])
            return true;
        else
            return false;
}
 
int main(int argc, char *argv[])
{
    char  command[4][9] = { "--file", "--create", "--extract", "--list" };

    if (strcmp(argv[1], &command[0]) != 0)
    {
        printf("Error!");
        return 1;
    }
    
    fout = fopen(argv[2], "rb");
    fread(&size, 1, 4, fout);
    struct arhivator arh;
    if (strcmp(argv[3], &command[2]) != 0)
    {
        
    }
  
    return 0;
}