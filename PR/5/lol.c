// C program to create loading bar
#include <stdio.h>
#include <windows.h>

// Function to creating loading bar
void loadingBar()
{
    char a = 177, b = 219;
    printf("\t\t\t\t\t");
    for (int i = 0; i < 26; i++)
        printf("%c", a);
    printf("\r");
    printf("\t\t\t\t\t");
    printf("%c", b);
}

// Driver Code
int main()
{
    // Function Call
    loadingBar();
    return 0;
}