#define _CRT_SECURE_NO_WARNINGS 1  
#include<stdio.h>  
#define MAX(a,b) a>b?a:b  
  
int main()  
{  
    int x = 0;  
    int y = 0;  
    printf("请输入两个数值\n");  
    scanf("%d %d", &x, &y);  
    printf("两个数字中较大的是%d", MAX(x, y));  
    getchar();  
}  

