#include "CommentConvert.h"

static enum STATUS status = NUL_STATUS;

void CommentConvert(FILE *pfIn, FILE *pfOut)
{
	while (status != END_STATUS)
	{
		switch (status)
		{
		case NUL_STATUS:
			DoNulStatus(pfIn, pfOut);
			break;
		case C_STATUS:
			DoCStatus(pfIn, pfOut);
			break;
		case CPP_STATUS:
			DoCppStatus(pfIn, pfOut);
			break;
		case STR_STATUS:
			DoStrStatus(pfIn, pfOut);
			break;
		case END_STATUS:
			break;
		default:
			break;
		}
	}
}

void DoNulStatus(FILE *pfIn, FILE *pfOut)
{
	int first = 0;
	int second = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case '/':
		second = fgetc(pfIn);
		if (second == '/')
		{
			fputc('/', pfOut);
			fputc('/', pfOut);
			status = CPP_STATUS;   //在无状态下遇到//直接将//写进去，并进入cpp状态  
		}
		else if (second == '*')
		{
			fputc(first, pfOut);
			fputc('/', pfOut);
			status = C_STATUS;//在无状态下遇到/*要将/*变成//写进去，并进入c状态  
		}
		else
		{
			fputc(first, pfOut);
			fputc(second, pfOut);//如果遇到其他字符，直接写进去，状态不改变。  
		}
		break;
	case EOF:
		status = END_STATUS;//如果遇到EOF，进入结束状态  
		break;
	case '"':
		fputc(first, pfOut);
		status = STR_STATUS;//如果遇到"，进入字符串状态  
		break;
	default:
		fputc(first, pfOut);//其他情况的字符，直接写进去就行  
		break;
	}
}

void DoStrStatus(FILE *pfIn, FILE *pfOut)
{
	int first = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case '"':
		fputc(first, pfOut);
		status = NUL_STATUS;//在字符串状态如果遇到后引号，将后引号写入，并进入无状态  
		break;
	default:
		fputc(first, pfOut);//其他情况的字符，直接写进去就行  
		break;
	}
}

void DoCStatus(FILE *pfIn, FILE *pfOut)
{
	int first = 0;
	int second = 0;
	int third = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case '*':
		second = fgetc(pfIn);
		if (second == '/')  // 遇到*/ 说明c的注释结束，切换到无状态  
		{
			status = NUL_STATUS;
			third = fgetc(pfIn);
			if (third != '\n')
			{
				fputc('\n', pfOut);    //如果/后边的字符不是回车，需要写进去回车，然后再把独到的字符放回  
				ungetc(third, pfIn);
			}
			else
			{
				ungetc(third, pfIn);//如果是回车，把回车放回  
			}
		}
		else
		{
			fputc(first, pfOut);
			//如果遇到*，但是后边不是/，把*放进去，*后边的字符放回，比如，/***/,进入c状态以后，  
			//遇到*，后边的字符也是*，如果把两个*都写进去，后边就只剩下/，就不能找到c状态结束的标志，  
			//所以，需要把第二个字符原样写回  
			/*fputc(second, pfOut);*/
			ungetc(second, pfIn);    //放回  
		}
		break;
	case '\n':
		fputc(first, pfOut);//如果需要回车，吧回车写入，在写入//，状态不变。  
		fputc('/', pfOut);
		fputc('/', pfOut);
		break;
	default:
		fputc(first, pfOut);
		break;
	}
}

void DoCppStatus(FILE *pfIn, FILE *pfOut)
{
	int first = 0;
	int second = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case '\n':
		fputc(first, pfOut);//cpp状态，如果遇到回车，cpp状态结束，进入无状态  
		status = NUL_STATUS;
		break;
	default:
		if (first == EOF)
		{
			status = END_STATUS;
		}
		else
		{
			fputc(first, pfOut);
		}
		break;
	}
}