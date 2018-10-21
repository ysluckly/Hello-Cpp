#include <stdio.h> 

char* fun()
{
 char a[] = "hello world";
 return a + 6;
}
int main()
{
 printf("%s", fun());
}
