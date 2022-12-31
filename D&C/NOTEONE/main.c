//分治寻找数组最小值
#include <stdio.h>
#include "stdlib.h"
#include "time.h"
#define MIN(X,Y) X<Y?X:Y
#define NUM 50
typedef int ElementType;
int main()
{
    int min_arr(int *,int ,int );
    ElementType a[NUM];
    srand((unsigned )time(NULL));
    for (int i = 0; i < NUM; ++i)
    {
        a[i]=rand()%1000;
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("%d", min_arr(a,0,NUM-1));
    return 0;
}
int min_arr(int a[NUM],int left,int right)
{
    if(left==(right-1)||left==right)
        return MIN(a[left],a[right]);
    else
        return MIN(min_arr(a,left,(left+right)/2), min_arr(a,(left+right)/2+1,right));
}
