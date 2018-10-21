#include <stdio.h>

int main (void)

{int i, j, r;

for(i = 1 ; i <= 1000 ; i++)

{

r = 0;

for(j = 1 ; j < i ; j++)

{

if(i % j == 0)             //这一句是关键;

r = r + j;

}

if(r == i)

printf("perfect number is %d\n", r);

}

return 0;

}
