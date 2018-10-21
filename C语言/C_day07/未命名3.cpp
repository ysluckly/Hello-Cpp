#include<stdio.h>
 
int is_prime_year(int year)
	{
		return(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));

	}
int main()
{
	 
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (is_prime_year(year))
		{
			printf("%5d", year);
		}
	}
	return 0;
 
}
