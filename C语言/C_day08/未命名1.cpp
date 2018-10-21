#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a = 1;
    for (a = 1; a <= 5; a++)
    {   int b = 1;
        for (b = 1; b <= 5; b++)
        { 
            if (b != a)//剔除并列情况，a和b名次不能相同
            {   int c = 1;
                for (c = 1; c <= 5; c++)
                {
                    if ((c != a) && (c != b))//同上
                    {   int d = 1;
                        for (d = 1; d <= 5; d++)
                        {
                            if ((d != a) && (d != b) && (d != c))//同上
                            {   int e = 1;
                                for (e = 1; e <= 5; e++)
                                {
                                    if ((e != a) && (e != b) && (e != c) && (e != d))//同上
                                    {
                                        if ((1 == (2 == b) + (3 == a)) &&
                                            (1 == (2 == b) + (4 == e)) &&
                                            (1 == (1 == c) + (2 == d)) &&
                                            (1 == (5 == c) + (3 == d)) &&
                                            (1 == (4 == e) + (1 == a)))
                                        {
                                            printf("A—>%d B—>%d C—>%d D—>%d E—>%d ", a, b, c, d, e);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }   
        }
    }
    system("pause");
    return 0;
}
