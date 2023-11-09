//depth first search in graphs
#include<stdio.h>
#include<stdlib.h>

int visited[7]={0,0,0,0,0,0,0};
int A[7][7] = {
//   0 1 2 3 4 5 6
    {0,1,1,1,0,0,0},// 0
    {1,0,1,0,0,0,0},// 1
    {1,1,0,1,1,0,0},// 2
    {1,0,1,0,1,0,0},// 3
    {0,0,1,1,0,1,1},// 4
    {0,0,0,0,1,0,0},// 5
    {0,0,0,0,1,0,0} // 6
};

void depthFirstSearch(int i)
{
    int j;
    printf("%d ", i);
    visited[i] = 1;
    for(j=0;j<7;j++)
    {
        if(A[i][j] == 1 && !visited[j])
        {
            depthFirstSearch(j);
        }
    }
}

int main()
{
    //DFS implementation
    depthFirstSearch(0);
    return 0;
}