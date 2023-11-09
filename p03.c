//deletion in an array
#include<stdio.h>

void printArray(int arr[], int size);
void indDeletion(int arr[], int size, int index);

int main()
{
    int sizeOfArray=10,i,array[100] = {1,2,3,4,12,6,7,8,9,10};

    for(i=0;i<10;i++)
    {
        scanf("%d",&array[i]);
    }
    printArray(array, sizeOfArray);
    indDeletion(array, sizeOfArray, 4);
    sizeOfArray-=1;
    printArray(array, sizeOfArray);

    return 0;
}

void printArray(int arr[], int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void indDeletion(int arr[], int size, int index)
{
    for (int i = index; i < size-1; i++)
    {
        arr[i] = arr[i + 1];
    }  
}
#   D a t a S t r u c t u r e s - A l g o r i t h m s  
 