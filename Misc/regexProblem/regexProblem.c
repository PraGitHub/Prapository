/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int* getIntArr(char* pcstrIn, int* count)
{
    
}

int main()
{
    int size;
    printf("Enter the length of string : ");
    scanf("%d", &size);
    
    char* pcstrInput = malloc((size+1)*sizeof(char));
    printf("Enter the string : ")
    scanf("%s", pcstrInput);
    int count = 0;
    int* arr = getIntArr(pcstrInput,&count);
    if(arr != 0)
    {
        int i;
        for(i = 0; i < count; i++)
        {
            printf("%d\n", arr[i]);
        }
    }
    return 0;
}
