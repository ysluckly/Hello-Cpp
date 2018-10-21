 #include<stdio.h>
void chengfa(int line)
{
	int i = 0;
	for(i = 1; i<=line;i++)
	{
		int j = 0;
		for(j = 1; j<=i;j++)
		{
			printf("%d*%d=%2d  ",i,j,i*j);
		}
		printf("\n");
	}
}
 int main()
 {
 	int line  = 0;
 	scanf("%d",&line);
 	chengfa(line);
 	return 0;
 }
