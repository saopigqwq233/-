//分治求数组和
#include <stdio.h>
#include "stdlib.h"
#include "time.h"
#define ADD(X,Y) (X+Y)
#define NUM 100
typedef int ElementType;
int main()
{
    ElementType sum_arr(ElementType [],int left,int right);//分治函数
    ElementType add_arr(ElementType []);
    ElementType arr[NUM];
    srand((unsigned ) time(NULL));
    for (int i = 0; i < NUM; ++i)
    {
        arr[i]=rand()%100;
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("%d", sum_arr(arr,0,NUM-1));
    printf("\n%d", add_arr(arr));
    return 0;
}
ElementType sum_arr(ElementType arry[NUM],int left,int right)
{
    if(left==right)
        return arry[left];
    else if(left>right)
        return 0;
    else
        return ADD(sum_arr(arry,left,(left+right)/2),
                   sum_arr(arry,(left+right)/2+1,right));
}
ElementType add_arr(ElementType arr[NUM])
{
    int res=0;
    for (int i = 0; i < NUM; ++i)
    {
        res+=arr[i];
    }
    return res;
}