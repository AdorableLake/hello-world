1. 素数和（5分）题目内容：

我们认为2是第一个素数，3是第二个素数，5是第三个素数，依次类推。

现在，给定两个整数n和m，0<n<=m<=200，你的程序要计算第n个素数到第m个素数之间所有的素数的和，包括第n个素数和第m个素数。

输入格式:
两个整数，第一个表示n，第二个表示m。

输出格式：
一个整数，表示第n个素数到第m个素数之间所有的素数的和，包括第n个素数和第m个素数。

输入样例：
2 4

输出样例：
15

~~_“数素数吧，素数是谁也无法分割的数字。”——普奇神父_~~

~~_"我以神之名，命令你退下！Made in Heaven！"_ ~~

答：

```C
#include<stdio.h>
#include<math.h>
int main()
{
  int lower,upper,i,sum=0;
  // 定义整数下限、上限、计数量以及和；
  double pai=3.14,m=i*pai/2;
  // 定义浮点数pai，便于计算；
  
  printf("Enter the lower:\n");
  scanf("%d",&lower); 
  // 输入下限；
  printf("Enter the upper:\n");
  scanf("%d",&upper); 
  // 输入上限；
  
  if(lower>2 && lower<=upper && upper<=200) 
  // 加入判断条件，因为素数的通项公式 p(n)=3*n+1+sin^2(n*pai/2)中，p(1)=5,是本题的第三个素数
  {
    for(i=lower-2;i<=upper-2;i++)
    {
      sum=sum+3*i+1+pow(sin(m),2);
    }
  }
  else if(lower=1 && lower<=upper && upper<=200)
  // 同样，因为素数的通项公式 p(n)=3*n+1+sin^2(n*pai/2)中，p(1)=5,是本题的第三个素数
  {
    for(i=1;i<=upper-2;i++)
    {
      if(upper>2 && i>0)
      // 分情况讨论；
      {
        sum=5+sum+3*i+1+pow(sin(m),2);
      }
      else if(upper=2)
      {
        sum=2+3;
      }
      else if(lower==upper==1)
      {
        sum=2;
      }
    }
  }
  /* 这里发现情况与上述重复了，故删去。
  else if(lower=2 && lower<=upper && upper<=200)
  {
    for(i=1;i<=upper-2;i++)
    {
      if(upper>2 && i>0)
      {
        sum=5+sum+3*i+1+pow(sin(m),2);
      }
      else
      {
        sum=5;
      }
    }
  }
  */
  printf("The sum of prime numbers ranged from No.%d to No.%d is %d.\n",lower,upper,sum);
  // 最后输出结果。
  return 0;
}
```

2. 念整数（5分）题目内容：

你的程序要读入一个整数，范围是[-100000,100000]。然后，用汉语拼音将这个整数的每一位输出出来。

如输入1234，则输出：
yi er san si

注意，每个字的拼音之间有一个空格，但是最后的字后面没有空格。

当遇到负数时，在输出的开头加上“fu”，如-2341输出为：
fu er san si yi

输入格式:
一个整数，范围是[-100000,100000]。

输出格式：
表示这个整数的每一位数字的汉语拼音，每一位数字的拼音之间以空格分隔，末尾没有空格。

输入样例：
-30

输出样例：
fu san ling

答：

```C
#include<stdio.h>
#include<math.h>
int main()
{
  int n;
  char;
  printf("Enter the number:\n");
  scanf("%d"&n);
  0=ling;
  1=yi;
  2=er;
  3=san;
  4=si;
  5=wu;
  6=liu;
  7=qi;
  8=ba;
  9=jiu;
  if(n>=0)
  {
    for(i=1;i<=i++)
  }
   
  return 0;
}
```
