//binary search
#include<stdio.h>
#include<time.h>

int binarySearch(int arr[], int size, int element);

int main()
{ 
    int array[100] = {2,4,6,8,10,12,14,16,18,20},size=10,result;

    for(int i=0;i<size;i++)
    {
        printf("\na[%d] => ",i);
        scanf("%d",&array[i]);
    }
    result = linearSearch(array, size, 12);
    if (result != -1) {
        printf("\nNumber Is At Index %d...!!!", result);
    }
    else {
        printf("\nNumber Not Found in the Array...!!!");
    }
    return 0;
}

int binarySearch(int arr[], int size, int element)
{
    int mid;
    int low=0;
    int high=size-1;

    while(low<=high)
    {
        mid = (low+high)/2;
        if(arr[mid]==element)
        {
            return mid;
        }
        if(arr[mid]<element)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}
