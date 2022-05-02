# 第五周 循环控制
## 1. 循环控制
### 如何写一个程序判断读入的数是否是素数？
```C
#include<stdio.h>
int main()
{
  int x;
  scanf("%d",&x);
  for(x=2;x<=100;x++)
  {
    int i;
    int isPrime=1;
    for(i=2;i<x;i++)
    {
      if(x%i==0)
      {
        isPrime==0;
        break;
      }
    }
    if(isPrime==1)
    {
      printf("是素数\n");
    }
    else
    {
      printf("不是素数\n");
    }
  }
  return 0;
}
```
### 如何输出100以内的素数？
```C
#include<stdio.h>
int main()
{
  int x;
  scanf("%d",&x);
  for(x=2;x<=100;x++)
  {
    int i;
    int isPrime=1;
    for(i=2;i<x;i++)
    {
      if(x%i==0)
      {
        isPrime==0;
        break;
      }
    }
    if(isPrime==1)
    {
      printf("是素数\n");
    }
    else
    {
      printf("不是素数\n");
    }
  }
  return 0;
}
```
## 2. 多重循环
### 如何写一个程序输出100以内的素数？
```C
#include<stdio.h>
int main()
{
  int x;
  scanf("%d",&x);
  for(x=2;x<100;x++)
  {
    int i;
    int isPrime=1; // x是素数
    for(i=2;i<x;i++)
    {
      if(x%1==0)
      {
        isPrime==0;
        break;
      }
    }
    if(isPrime==1)
    {
      printf("%d ",x);
    }
  }
  printf("\n");
  return 0;
}
```
### 输出前五十个素数的程序
```C
#include<stdio.h>
int main()
{
  int x;
  scanf("%d",&x);
  // for(x=2;x<100;x++)
  // while(cnt<50)
  for(x=2;cnt<50;x++)
  {
    int i;
    int isPrime=1; // x是素数
    for(i=2;i<x;i++)
    {
      if(x%1==0)
      {
        isPrime==0;
        break;
      }
    }
    if(isPrime==1)
    {
      printf("%d ",x);
      cnt++;
    }
    // x++;
  }
  printf("\n");
  return 0;
}
```
### 如何用1角、2角、5角的硬币凑出10元以下的金额？
```C
#include<stdio.h>
int main()
{
  int x;
  int one,two,five;
  scanf("%d",&x);
  for(one=1;one<x*10;one++)
  {
    for(two=1;two<x*10/2;two++)
    {
      for(five=1;five<x*10/5;five++)
      {
        if(one+two*2+five*5==x*10)
        {
          printf("可以用%d个1角加%d个2角加%d个5角得到%d元\n",one,two five,x);
        }
      }
    }
  }
  return 0;
}
```
### 如何在以上程序基础上找出一种即可？
```C
#include<stdio.h>
int main()
{
  int x;
  int one,two,five;
  scanf("%d",&x);
  int exit=1; // 利用新定义一个变量;
  for(one=1;one<x*10;one++)
  {
    for(two=1;two<x*10/2;two++)
    {
      for(five=1;five<x*10/5;five++)
      {
        if(one+two*2+five*5==x*10)
        {
          printf("可以用%d个1角加%d个2角加%d个5角得到%d元\n",one,two five,x);
          exit=1;
          break;
        }
      }
      if(exit) // if()语句后面默认变量为`1`;
        break;
    }
    if(exit)
      break;
  }
  return 0;
}
```
```C
#include<stdio.h>
int main()
{
  int x;
  int one,two,five;
  scanf("%d",&x);
  for(one=1;one<x*10;one++)
  {
    for(two=1;two<x*10/2;two++)
    {
      for(five=1;five<x*10/5;five++)
      {
        if(one+two*2+five*5==x*10)
        {
          printf("可以用%d个1角加%d个2角加%d个5角得到%d元\n",one,two five,x);
          goto out; // 不推荐使用`goto`语句，因为有很多原因：D
        }
      }
    }
  }
out:  
  return 0;
}
```

## 3. 循环应用
### 求和
```
f(n)=1+1/2+1/3+···+1/n
```
```C
#include<stdio.h>
int main()
{
  int n;
  int i;
  double sum=0.0;
  
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    sum=sum+1.0/i;
  }
  printf("f(%d)=%f\n",n,sum);
  return0;
}
```
```
f(n)=1-1/2+1/3-1/4+...+1/n
```
```C
#include<stdio.h>
int main()
{
  int n;
  int i;
  double sum=0.0;
  // int sign=1;
  double sign=1.0;
  
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    sum=sum+sign/i;
    sign=-sign;
  }
  printf("f(%d)=%f\n",n,sum);
  return0;
}
```
### 求最大公约数
利用辗转相除法以及利用枚举法
```C
// 枚举法思路
// 1. 设t为2；
// 2. 如果u和v都能被t整除，则记下这个t；
// 3. t+1后重复2，直到 t==u || t==v;
// 4. 曾经记下的最大的可以同时整除u和v的t就是gcd(Short from GreatCommonDivisor).
#include<stdio.h>
int main()
{
  int a,b;
  int min;
  
  scanf("%d %d",&a,&b);
  if(a<b)
  {
    min=a;
  }
  else
  {
    min=b;
  }
  int ret=0;
  int i;
  for(i=1;i<min;i++)
  {
    if(a%i==0)
    {
      if(b%i==0)
      {
        ret=i;
      }
    }
  }
  printf("%d和%d的最大公约数是%d。\n",a,b,ret);
  return 0;
}
```
```C
//  辗转相除法思路
// 1. 如果b=0，计算结束，a就是最大公约数；
// 2. 否则，计算a%b，a=b，b=a%b；
// 3.回到第一步。
#include<stdio.h>
int main()
{
  int a,b;
  int t;
  scanf("%d %d",&a,&b);
  while(b!=0)
  {
    t=a%b;
    a=b;
    b=t;
    printf("a=%d,b=%d,t=%d\n",a,b,t);
  }
  printf("gcd=%d\n",a);
  return 0;
}
```
### 正序分解整数
```C
#include<stdio.h>
int main()
{
  int x;
  scanf("%d",&x);
   
  /*
  x=12345;
  int cnt=0;
  for(x>0;x=x/10;cnt++)
  do{
     x=x/10;
     mask=mask*10;
  }while(x>9);
  */
   
  int mask=1;
  int t=x;
  while(t>9)
  {
    t=t/10;
    mask=mask*10;
  }
  printf("x=%d, mask=%d\n",x,mask);
   
  /*
  int t=0;
  do{
     int d=x%10;
     t=t*10+d;
     x=x/10;
  }while(x>0);
  printf("x=%d,t=%d\n",x,t);
  */
   
  do{
     int d=x%10;
     printf("%d",d);
     if(x>9) // 输出最后一位时去掉空格的判断语句
     {
       printf(" ");
     }
     x=x/10;
  }while(x>0);
  printf("\n");
   
  return 0;
}
```
```C
#include<stdio.h>
int main()
{
  int x;
  scanf("%d",&x);
	
  int mask=1;
  int t=x;
  while(t>9)
  {
    t=t/10;
    mask=mask*10;
  }
  printf("x=%d, mask=%d\n",x,mask);
   
  do{
     int d=x%10;
     printf("%d",d);
     if(x>9) // 输出最后一位时去掉空格的判断语句
     {
       printf(" ");
     }
     x=x/10;
  }while(x>0);
  printf("\n");
   
  return 0;
}
```
