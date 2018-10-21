#include<stdio.h>
#include<string.h> //memset函数
#include<math.h> //sqrt()求平方根
#define N 10001 //假定N最大值为10000
int a[N];
int main() {
 int n;
 scanf("%d", &n);
  
 memset(a, 0, sizeof(a)); //①初始默认都为素数置为0，不是素数标记1，下面再筛去。
 int i = 1;
 a[1] = 1; //1不是素数、将其置1
  
 for (i = 2; i < sqrt(n); i++) //i为素数因子，②当i等于根号n时，可筛去所有的非素数。
 {
  if (a[i] == 0) {//i未标记，则i是素数.
   int j;
   for (j = 2; j * i <= n; j++) {//将i的倍数标记
    a[j*i] = 1;
   }
  }
 }//已将a[1]-a[n]标记完成。
  
  
 for (i = 1; i <= n; i++) { //输出
  if (!a[i]) printf("%d\n", i);
 }
 return 0;
}
