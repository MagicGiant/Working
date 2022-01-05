#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
FILE * fin;
FILE *fout;

int beas;
int x = 0;
int y = 0;
int image_path = 0;

const char life = '1';
const char death = '0';

char *arr;

int get_10_in_2 (int arr_10)
{
    int i=0;
    int j=1;
    for (int j = 0; arr_10 > 0; j++)
    {
        i += (arr_10 % 2) * pow(10.0, j);
        arr_10 /= 2;
    }
    return i;
}

int get_2_in_10 (int arr_2)
{
    int i=1;
    int data=0;
    while (arr_2 != 0)
    {
        if (arr_2%10==1)
            data+=i;
        i*=2;
        arr_2/=10;
    }
    return data;
}

int get_O(int X, int Y)
{
    return (X-1)+(Y-1)*x;
}
void print() 
{
    int i=x;
    int j=y;
    char ch;
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
    int ch;
    fseek(fin, image_path, SEEK_SET);
    while (j<=y)
    {
        int arr_10=0;
        fread(&arr_10, 1, x/8, fin);
        fseek(fin, 3, SEEK_CUR);
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
    if (X<x-beas+1 && Y>1 && arr[get_O(X+1,Y-1)]==life)
        lifes++;
    if(X<x-beas+1 && arr[get_O(X+1,Y)]==life)
        lifes++;
    if (X<x-beas+1 && Y<y && arr[get_O(X+1,Y+1)]==life)
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
    char* arr_clone = malloc (x*y);

    if (n==-1)
        n=999999;

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

        bool flag=false;
        for (int i=0; i<x*y; i++)
            if(arr[i]!=arr_clone[i])
            {
                flag=true;
                break;
            }
        if(flag==false)
            break;
        
        int q1=x, q2=y;
        for (int i=0; i<x*y; i++)
        {
            arr[i]=arr_clone[i];
        }
    }
}
void end()
{
    // printf("\n__________________\n");
    char *arr_end=malloc(y);
    for (int j=y; j>=1; j--)
    {
        int data_2=0;
        for (int i=x; i>=1; i--)
        {
            data_2=data_2*10+arr[get_O(i,j)]-'0';
        }
        // printf("%d\n", data_2);
        arr_end[y-j]=get_2_in_10(data_2);
    }
    // printf("\n__________________\n");
    // for (int i=0; i<y; i++)
        // printf("%d\n", arr_end[i]);
    // printf("\n__________________\n");

    char ch;
    fseek(fin, 0, SEEK_SET);
    fseek(fout, 0, SEEK_SET);
    while(!feof(fin))
    {
        ch=getc(fin);
        putc(ch, fout);
    }

    fseek(fout, image_path, SEEK_SET);
    for (int i=0; i<y; i++)
    {
        putc(arr_end[i], fout);
        fseek(fout, 3, SEEK_CUR);
    }
}
void go_life()
{   
    //Узнаём длину
    fseek(fin, 18, SEEK_SET);
    fread(&x, 1, 2, fin);
    //Узнаём побитовый сдвиг
    beas %= 8;
    x+=beas;
    // printf("%i\n", x);
    //Узнаём высоту
    fseek(fin, 22, SEEK_SET);
    fread (&y, 1, 2, fin);

    //Узнаём место начала изображения
    fseek(fin, 10, SEEK_SET);
    fread (&image_path, 1, 1, fin);

    //Сканируем изображение
    scan_file();

    //Реализация игры в жизнь
    // start(21);
    print();

    //Запись в БМП
    // end ();
}

int main(int argc, char *argv)
{
    fin = fopen("9.bmp","rb");
    fout = fopen("out.bmp", "wb");
    go_life();
    return 0;
}