#include <stdio.h>
#include <conio.h>
#include <string.h>
#define ID3_MAX_SIZE 128
 
typedef struct IDv3Tag
{
    char signature[3];
    char name[30];
    char artist[30];
    char album[30];
    char year[4];
    char description[30];
    unsigned short ganre;
} ID3TAG;
 
long idv3_file_offset(FILE* fp)
{
    fseek(fp, 0L, SEEK_END); 
    return ftell(fp) - ID3_MAX_SIZE;
}

int main()
{
    FILE* fp = NULL; 
    const char* filename = "test.mp3";
    if ((fp = fopen(filename,"r")) == NULL)
        printf("Unable to open file %s for reading\n", filename);
 
    struct IDv3Tag buf;
    memset(&buf, 0x00, ID3_MAX_SIZE);
 
    fseek(fp, idv3_file_offset(fp), SEEK_SET);
    fread(&buf, 1, ID3_MAX_SIZE, fp);
    
    printf("%s", buf.album);
    return 0;
}