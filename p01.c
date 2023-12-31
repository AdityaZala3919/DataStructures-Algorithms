//implement arrays as an abstract data type
#include<stdio.h>
#include<stdlib.h>

struct arr
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct arr *a, int tSize, int uSize)
{
    a->total_size = tSize;
    a->used_size = uSize;
    a->ptr = (int *)malloc(tSize * sizeof(int));
}

void show(struct arr *a)
{
    int i;
    for(i=0;i<a->used_size;i++)
    {
        printf("\n%d",(a->ptr)[i]);
    }
}

void setValue(struct arr *a)
{
    int i,n;
    for(i=0;i<a->used_size;i++)
    {
        printf("\nEnter arr[%d] => ",i);
        scanf("%d",&n);
        (a->ptr)[i] = n;
    }
}

int main()
{
    struct arr array;
    createArray(&array, 10, 2);
    printf("\nSet Value Is RUnning...!!!");
    setValue(&array);

    printf("\nArray...!!!");
    show(&array);

    return 0;
}
