#include <stdio.h>  
#include <stdlib.h>  
void sort(int *a,int sz)  
{  
    int i = 0;  
    int j = sz-1;  
    for(i=0; i!=j; i++)  
    {   
        if(a[i]%2!=0)  
            continue;  
        else  
        {  
            int t = a[i];  
            a[i] = a[j];  
            a[j] = t;  
            if(a[j]%2==0)  
                j--;  
            i--;  
        }  
  
    }  
}  
  
int main()  
{  
    int a[] = {1,9,5,6,4,3,1};  
    int sz = sizeof(a)/sizeof(a[0]);  
    int i ;  
    sort(a,sz);  
    for(i=0; i<sz ;i++)  
    {  
        printf("%d ",a[i]);  
    }  
    return 0;  
}  
