//分治实现快速排序
#include <stdio.h>
#include "stdlib.h"
#include "time.h"
#define NUM 10
int main()
{
    void q_sort(int *,int left,int right);
    int arry[NUM];
    srand((unsigned ) time(NULL));
    for (int i = 0; i < NUM; ++i)
    {
        arry[i]=rand()%100;
        printf("%d ",arry[i]);
    }
    printf("\n");
    q_sort(arry,0,NUM-1);
    for (int i = 0; i < NUM; ++i)
    {
        printf("%d ",arry[i]);
    }
    return 0;
}
void q_sort(int arr[NUM],int left,int right)
{
    if(left==right)
        return;
    
}
