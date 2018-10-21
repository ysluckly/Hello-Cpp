#include <stdio.h>
#define n 10 //控制行数
int main()
{
    int arr[n][n] = {0};
    int i = 0;
    int j = 0;
    for(i=0; i<n; i++)
    {
       for(j=1; j<n-i; j++)//控制空格
       {
            printf("  ");//打印空格
       }
        for(j=0; j<=i; j++)
        {
           if(j==0 || i==j)//第一列和i=j列赋成1
           {
                arr[i][j] = 1;
           }
           else
           {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
           }
           printf("%4d",arr[i][j]);//对齐，打印数组
        }
           printf("\n");
    }
    
    return 0;
}
