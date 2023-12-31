//insertion in an array
#include<stdio.h>

void printArray(int arr[], int size);
int insertInArray(int arr[], int size, int element, int index);

capacity = 100;

int main()
{
    int sizeOfArray=10,i,array[capacity] = {2,3,5,7,11,13,17,19,23,29};

    for(i=0;i<10;i++)
    {
        printf("\na[%d] => ",i);
        scanf("%d",&array[i]);
    }

    printArray(array, 10);
    insertInArray(array, 10, 4, 3);
    sizeOfArray+=1;
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

int insertInArray(int arr[], int size, int element, int index)
{
    int i;
    if(size>=capacity)
    {
        return -1;
    }
    for(i=size-1;i>=index;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
}
