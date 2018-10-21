#include <stdio.h>  
#include <string.h>  
#include <assert.h>  
  
int rotate(char *p, char *q)  
{  
    assert(p != NULL && q != NULL);  
    strncat(p,p,strlen(p));  
    if (strstr(p, q) == NULL)  
    {  
        return 0;  
    }  
    else  
    {  
        return 1;  
    }  
}  
  
int main()  
{  
    char p[20] = "AABCD";  
    char *q = "BCDAA";  
    char r[20] = "abcd";  
    char *s = "ACBD";  
    printf("%d\n", rotate(p, q));  
    printf("%d\n", rotate(r, s));  
    return 0;  
}  
  
  
