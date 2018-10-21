#include<stdio.h>  
#include<string.h>
#include<assert.h>  

void reverse(char *left,char*right)//逆序  
{  
    assert(left&&right);
    while (left < right)  
    {  
        char tmp;  
        tmp = *left;  
        *left = *right;  
        *right = tmp;  
        left++, 
		right--;  
    }  
}  
void reverse_left(char *str,int k)  
{  
    int len = 0; 
	assert(str);
    len = strlen(str);  
    k=k%len;
    reverse(str, (str + k-1));//要旋转的k个字符逆序  
    reverse((str + k ), (str + len-1));//之后的字符逆序  
    reverse(str, (str + len-1));//所有的字符逆序  
}  
int main()  
{  
    int k = 0;  
    char str[] = "abcdefgh"; 
	scanf("%d",&k); 
    reverse_left(str, k);  
    printf("%s", str);  
    return 0;  
}  

