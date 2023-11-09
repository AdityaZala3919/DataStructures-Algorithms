//linear search
#include<stdio.h>
#include<time.h>

int linearSearch(int arr[], int size, int element);

int main()
{ 
    int array[100] = {2,4,6,8,10,12,14,16,18,20},size=10, result;

    for(int i=0;i<size;i++)
    {
        printf("\na[%d] => ",i);
        scanf("%d",&array[i]);
    }
    result=binarySearch(array, size, 12);
    if (result != -1) {
        printf("\nNumber Is At Index %d...!!!", result);
    }
    else {
        printf("\nNumber Not Found in the Array...!!!");
    }
    return 0;
}

int linearSearch(int arr[], int size, int element)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(arr[i]==element)
        {
            return i;
        }
    }
    return -1;
}
