 
//A说：不是我。 
//B说：是C。 
////C说：是D。 
//D说：C在胡说 
//已知3个人说了真话，1个人说的是假话。 
//现在请根据这些信息，写一个程序来确定到底谁是凶手。 
#include <stdio.h>
int main()
{
	int killer = 0;
	for(killer = 65; killer<68;killer++)
	{
    	if(3 == ((killer != 65)+(killer == 67)+(killer == 68)+(killer != 68)))
    	{
		    printf("%C",killer);
    	}
	}

	return 0;
}
