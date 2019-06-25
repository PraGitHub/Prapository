#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int n)
{
        int i = 0;
        while(i<n)
        {
                printf("%d\n",arr[i++]);
        }
        printf("\n");
}

int* getIntArr(char* pcstrIn, int* count)
{
    if(pcstrIn == 0)
    {
        *count = 0;
        return 0;
    }
    
    int* digits = (int*) malloc(sizeof(int));
    int* dollarPos = (int*) malloc(sizeof(int));
    int digitCount = 0;
    int dollarCount = 0;
    char c = pcstrIn[digitCount + dollarCount]; // (digitCount + dollarCount) acts as iterator
    while(c != 0)
    {
        if(c == '$')
        {
            dollarPos[dollarCount] = dollarCount + digitCount; 
            dollarCount++;
            dollarPos = (int*) realloc(dollarPos, (dollarCount+1)*sizeof(int));
        }
        else // it will be a digit
        {
            digits[digitCount] = c - '0';
            digitCount++;
            digits = (int*) realloc(digits, (digitCount+1)*sizeof(int));
        }
        c = pcstrIn[digitCount + dollarCount];
    }
    // by now we will have all digits in 'digits' and all positions of '$'s in 'dollarPos'
    printArray(digits, digitCount);
}

int main()
{
    int size;
    printf("Enter the length of string : ");
    scanf("%d", &size);
    
    char* pcstrInput = (char*) malloc((size+1)*sizeof(char));
    printf("Enter the string : ");
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
