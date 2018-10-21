#include <stdio.h>  
#define ROW 4  
#define COL 4  
int Yang(int arr[ROW][COL],int val)  
{  
    int i = 0;  
    int j = COL - 1;  
    int tmp = arr[i][j];  
    while(1)  
    {  
        if(tmp == val)  
        {  
            return 1;  
        }  
        else if(tmp < val && j >= 0)  
        {  
            tmp = arr[++i][j];  
        }  
        else if(tmp > val &&j >= 0)  
        {  
            tmp = arr[i][--j];  
        }  
        else  
        {  
            return 0;  
        }  
    }  
      
}  
int main()  
{  
    int a[ROW][COL] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};  
    int i = 0;  
    int j = 0;  
    int num;  
    printf("数组为:\n");  
    for(i = 0; i<ROW; i++)  
    {  
        for(j = 0; j < COL; j++)  
        {  
            printf("%5d",a[i][j]);  
        }  
        printf("\n");  
    }  
    printf("Please Enter:");  
    scanf("%d",&num);  
    if(Yang(a,num))  
    {  
        printf("%d在该数组中\n",num);  
    }  
    else  
    {  
        printf("%d不在该数组中\n",num);  
    }  
      
    return 0;  
}  

