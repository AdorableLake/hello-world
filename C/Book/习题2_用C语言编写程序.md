## 习题2 用C语言编写程序

1. 求整数均值：输入4个整数，计算并输出这些证书的和与平均值，其中平均值精确到小数点后1位。

答：
```C
#include<stdio.h>
int main()
{
  int a,b,c,d;
  int num;
  float aver;
  scanf("%d %d %d %d",&a,&b,&c,&d);
  num=a+b+c+d;
  aver=(a+b+c+d)/4.0;
  printf("这些整数的和为%d,平均值精确到一位小数为%.1lf\n",num,aver);
  return 0;
}
```

2. 阶梯电价：为了提倡居民节约用电，某省电力公司执行“阶梯电价”，安装一户一表的居民用户电价氛围两个“阶梯”：月用电量50kW·h(含50kW·h)以内的，电价为0.53元/kW.h；超过50kW·h的，超出部分的用电量电价每千瓦时上调0.05元。输入用户的月用电量（千瓦时），计算并输出该用户应支付的电费（元），若用电量小雨0，则输出“Invalid Value！”

答：
```C
#include<stdio.h>
int main()
{
  double cost,fee;
  printf("请输入用户的用电量：\n");
  scanf("%lf",&cost);
  /*当使用量小于等于50千瓦时时*/
  if(cost<=50)
  {
    fee=0.53*cost;
    printf("用户应支付电费：%lf\n",fee);
  }
  /*当使用量大于50千瓦时时*/
  else if(cost>50)
  {
    fee=0.53*50+0.58*(fee-50);
    printf("用户应支付电费：%lf\n",fee);
  }
  /*输入量小于0时*/
  else if(cost<0)
  {
    printf("Invalid Value!");
  }
  return 0;
}
```

3. 序列求和：输入两个正整数m和n（0<m<=n），求（i^2+1/i）从i=m到i=n的和，结果保留6位小数。

答：
```C
#include<stdio.h>
int main()
{
  int m,n,i;
  double sum=0.000000;
  printf("Enter lower:\n");
  scanf("%d",&m);
  printf("Enter upper:\n");
  scanf("%d",&n);
  if(m>n){
    printf("Invalid Value!\n");
  }
  for(i=m;i<=n;i++){
    sum=sum+i*i+1/i;
  }
  printf("Sum of the numbers from %d to %d is %.6lf\n",m,n,sum);
  return 0;
}
```

4. 求交错序列前n项和：输入一个正整数n，计算交错序列1-2/3+3/5-4/7+5/9-6/11+···的前n项之和。

答：
```C
#include<stdio.h>
#include<math.h>
int main()
{
  int n,i;
  double sum;
  printf("Enter the number:\n"); /*提示：输入一个正整数n*/
  scanf("%d",&n); /*输入一个正整数，关联到n*/
  for(i=1;i<=n;i++)
    {
      sum=sum+(i/(2*i-1))*pow(-1,i);
    }
  printf("Sum of the numbers is %lf\n");
  return 0;
}
```

5. 平方根求和：输入一个正整数n，计算1+根号2+根号n的值（保留两位小数）。

答:
```C
#include<stdio.h>
#include<math.h>
int main()
{
  int n,i;
  double sum;
  printf("Enter the number:\n"); /*提示：输入一个正整数n*/
  scanf("%d",&n); /*输入一个正整数，关联到n*/
  for(i=1;i<=n;i++)
    {
      sum=sum+sqrt(i);
    }
  printf("Sum of the numbers is %.2lf\n");
  return 0;
}
```

6. 求给定序列前n项和（1！+2！+...）:输入一个正整数n，求e=1！+2！+3！+···+n！的值。要求定义和调用函数fact(n)计算n！，函数类型是double。

答：
```C
#include<stdio.h>
int main()
{
  double fact(int n);
  int n,i,sum;
  printf("Enter the number:\n");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
    sum=sum+fact(i);
  printf("Sum of the numbers is %d\n",sum);
  return 0;
}

double fact(int n)
{
  int i;
  double production=1;
  for(i=1;i<=n;i++)
    production=production*i;
  return production;  
}
```
