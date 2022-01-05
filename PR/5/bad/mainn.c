#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
FILE * fin;
FILE * fout;

int beas;
int x = 0;
int y = 0;
int image_path = 0;

const char life = '1';
const char death = '0';

char *arr;

void copy ()
{
    fseek(fin, 0, SEEK_SET);
    int i;
    while (fread(&i, 1, 1, fin))
        fwrite(i, 1, 1, fout);
}
int get_10_in_2 (int arr_10)
{
    int i=0;
    int j=1;
    while (arr_10/2!=0)
    {
        i=i+(arr_10%2)*j;
        arr_10/=2;
        j*=10;
    }
    i+=arr_10*j;
    return i;
}
int get_O(int X, int Y)
{
    return (X-1)+(Y-1)*x;
}
void print() 
{
    int i=x;
    int j=y;
    while (j>0)
    {
        if (i>0)
        {
            printf("%c", arr[get_O(i,j)]);
            i--;
        }
        else
        {
            printf("\n");
            i=x;
            j--;
        }
    }
}
void scan_file()
{
    arr = malloc(x*y);
    int i=1;
    int j=1;
    int ch=0;
    fseek(fin, image_path, SEEK_SET);
    while (j<=y)
    {
        int arr_10=0;
        fread(&arr_10, 1, 4, fin);
        int arr_2=get_10_in_2(arr_10);
        while (i<=x)
        {
            ch=arr_2%10;
            arr_2/=10;
            if (ch==1)
                arr[get_O(i,y-j+1)]=life;
            else
                arr[get_O(i,y-j+1)]=death;
            i++;
        }
        j++;
        i=1;
    }
}
void scan(int X, int Y, char data)
{
    arr[get_O(X,Y)]=data;
}
bool check (int X, int Y)
{
    short lifes=0;
    if (X>1 && Y>1 && arr[get_O(X-1,Y-1)]==life)
            lifes++;
    if(Y>1 && arr[get_O(X,Y-1)]==life)
            lifes++;
    if (X<x && Y>1 && arr[get_O(X+1,Y-1)]==life)
        lifes++;
    if(X<x && arr[get_O(X+1,Y)]==life)
        lifes++;
    if (X<x && Y<y && arr[get_O(X+1,Y+1)]==life)
            lifes++;
    if(Y<y && arr[get_O(X,Y+1)]==life)
        lifes++;
    if (X>1 && Y<y && arr[get_O(X-1,Y+1)]==life)
        lifes++;
    if(X>1 && arr[get_O(X-1,Y)]==life)
        lifes++;
    if (lifes==3 || (lifes==2 && arr[get_O(X,Y)]==life) )
        return 1;
    else
        return 0;
}
void start(int n)
{
    char *arr_clone = malloc(x*y);
    for (int j=0; j<n; j++)
    {
        for (int Y=1; Y<=y; Y++)
        {
            for (int X=1; X<=x; X++)
            {
                if (check(X,Y))
                    arr_clone[get_O(X,Y)]=life;
                else
                    arr_clone[get_O(X,Y)]=death;
            }
        }
        for (int i=0; i<x*y; i++)
        {
            arr[i]=arr_clone[i];
        }
    }
}
void inf()
{   
    //Узнаём длину
    fseek(fin, 18, SEEK_SET);
    fread(&x, 1, 2, fin);
    //Узнаём побитовый сдвиг
    if (x<=8)
        beas=8-x;
    else if (x<=16)
        beas=16-x;
    else if (x<=24)
        beas=24-x;
    else if (x<=32)
        beas=32-x;
    //увеличиваем до предела
    x+=beas;
    //Узнаём высоту
    fseek(fin, 22, SEEK_SET);
    fread (&y, 1, 2, fin);
    //Узнаём место начала изображения
    fseek(fin, 10, SEEK_SET);
    fread (&image_path, 1, 1, fin);
    //Сканируем изображение
    scan_file();

    // printf("%i %i %i",x,y,image_path);
}
int main()
{
    fin = fopen("my.bmp","rb");
    fout = fopen("your.bmp","wb");

    inf();
    start(4);
    print();
    copy();
    return 0;
}