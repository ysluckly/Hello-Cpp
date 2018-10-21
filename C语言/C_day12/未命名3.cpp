#include <stdio.h>

int main()

{
	int a= 19;
	int b= 33;
	printf("%d %d %d",a+((b-a)>>1),(a+b)/2,(a&b)+((a^b)>>1)); 
	return 0;
 } 
