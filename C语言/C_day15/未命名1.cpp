可变参数最大值
#include <stdio.h>    
#include <stdarg.h>    
#include <windows.h>    
int Max(int n, ...)    
{    
    int i = 0;    
    int max = 0;    
    va_list arg;    
    va_start(arg, n);    
    max = va_arg(arg,int);//获取参数列表第一个可比较值  
    for (i = 1; i < n; i++)    
    {    
        int val = va_arg(arg, int);    
        if (val > max)    
        {    
            max = val;    
        }    
    }    
    va_end(arg);    
    return max;    
}    
int main()    
{    
    int ret = Max(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);    
    printf("%d\n", ret);    
    system("pause");    
    return 0;    
}     
/*模拟实现printf函数，可完成下面的功能 
能完成下面函数的调用。 
print(“s ccc d.\n”,”hello”,’b’,’i’,’t’，100); 
函数原型： 
print(char *format, …)*/ 
#include<stdio.h>  
#include<assert.h>  
#include<stdarg.h>  
void print(char *fomt, ...)  
{  
    char *ch;  
    assert(*fomt);//断言  
    va_list arg;//定义arg  
    va_start(arg, fomt);初始化arg 即把可变参数列表中首个变量地址给arg  
    while (*fomt)  
    {  
        switch(*fomt)  
        {  
        case 'c':  
            putchar(va_arg(arg,char));//va_arg 获取参数列表中下一个未知参数，可以通过前面获取的字符判断下一个参数类型  
            break;  
        case 's':  
            /*puts(va_arg(arg, char*));*/   //字符串可以直接用puts()函数输出  
            ch = va_arg(arg, char*);//还可以定义一个指针变量接收获取的字符，从而用putchar（）一个一个输出  
            while (*ch)  
            {  
                putchar(*ch);  
                ch++;  
            }  
                  
                break;  
        default :  
            putchar(*fomt);  
  
        }  
        fomt++;  
      
    }  
    va_end(arg);//最后释放arg  
}  
int main()  
{  
    print("val:s ccccc\n","hello", 'w', 'o', 'r', 'l', 'd');  
    system("pause");  
    return 0;  
}  


平均值
#include<stdio.h>      
#include<stdlib.h>      
#include <stdarg.h>       
int average(int num, ...)//第一个参数传的是参数的个数，后面三个点代表可变参数列表      
{    
    int sum = 0;    
    va_list arg;  //定义一个va_list类型的变量      
    va_start(arg, num); //宏 va_start      
    for (int i = 0; i < num; i++)    
    {    
        sum += va_arg(arg, int);  //宏 va_arg      
    }    
    va_end(arg); //宏 va_end      
    return sum / num;    
}    
    
int main()    
{    
    int aver = 0;    
    aver = average(5,2,4,6,8,10); //第一参数为个数,之后的数为被平均的数      
    printf("%d\n", aver);    
    system("pause");    
    return 0;    
}     
