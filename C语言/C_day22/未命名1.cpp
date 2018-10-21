

char *my_strncpy(char *dest, const char *str, int len)
{
	char *tmp = dest;
	assert(dest&&str);
	while(len--)
	{
		*tmp++ = *str++;
	}
	if((*tmp) != '\0')
	{
		*tmp = '\0';
	}
	return dest;
 } 
 
char *my_strncat(char *dest, const char *str, int len)
{
	char *tmp = dest;
	assert(dest&&str);
	while(*tmp)
	{
		tmp++;
	}
	while(len--)
	{
		*tmp++ = *str++;
	}
	if((*tmp) != '\0')
	{
		*tmp = '\0';
	}
	return dest;
}

int my_strncmp(const char *str1, const char *str2, int len)
{
	assert(str1&&str2);
	while(len--)
	{
		if(*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else if((*str1)-(*str2) < 0)
		{
			return -1;
		}
		else return 1;
	 
	}
	return 0;	
}


 
