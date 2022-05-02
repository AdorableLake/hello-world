# 第六周 数组与函数
## 1. 数组
### 如何写一个程序计算用户输入的数字的平均数？
```C
// 之前的写法
#include<stdio.h>
int main()
{
	int x;
	double sum=0;
	int cnt=0;
	scanf("%d",&x);
	while(x!=-1)
	{
		sum=sum+x;
		cnt++;
		scanf("%d",&x);
	}
	if(cnt>0)
	{
		printf("%f\n",sum/cnt);
	}
	return 0;
}
```
### 如何写一个程序计算用户输入的数字的平均数，并输出所有大于平均数的数？
```C
// 利用数组`int number[i]`
#include<stdio.h>
int main()
{
	int x;
	double sum=0;
	int cnt=0;
	int number[100];
	scanf("%d",&x);
	while(x!=-1)
	{
		number[cnt]=x;
		/*
		{
			int i;
			printf("%d\t",cnt);
			for(i=0;i<=cnt;i++)
			{
				printf("%d\t",number[i]);
			}
			printf("\n");
		}
		*/
		sum=sum+x;
		cnt++;
		scanf("%d",&x);
	}
	if(cnt>0)
	{
		printf("%f\n",sum/cnt);
		int i;
		for(i=0;i<cnt;i++)
		{
			if(number[i]>sum/cnt)
			{
				printf("%d\n",number[i]);
			}
		}
	}
	return 0;
}
```
#### 整理后
```C
#include<stdio.h>
int main()
{
	int x;
	int cnt=0;
	int number[100]; // 定义数组
	double sum=0;
	scanf("%d",&x);
	while(x!=-1)
	{
		number[cnt]=x; // 对数组中元素赋值
		sum+=x;
		cnt++;
		scanf("%d",&x);
	}
	if(cnt>0)
	{
		int i;
		double average=sum/cnt;
		for(i=0;i<=cnt;i++) // 遍历数组
		{
			if(number[i]>average)
			{
				printf("%d ",number[i]); // 使用数组中的元素
			}
		}
	}
	return 0;
}
// 存在`cnt>number[100]`的安全隐患
```
### 定义数组
数组：
1. 其中所有的元素具有相同的数据类型；
2. 一旦创建不能改变大小；
3. 数组中的元素在内存中是连续一次排列的

#### 提前输入数字数量
```C
#include<stdio.h>
int main()
{
	int x;
	int cnt;
  printf("Enter the number of the list:\n");
	scanf("%d",&cnt);
	double sum=0;
  if(cnt>0)
  {
    int number[cnt];
    scanf("%d",&x);
    while(x!=-1)
	  {
		  number[cnt]=x; // 对数组中元素赋值
		  sum+=x;
		  cnt++;
		  scanf("%d",&x);
	  }
  }
	
	if(cnt>0)
	{
		int i;
		double average=sum/cnt;
		for(i=0;i<=cnt;i++) // 遍历数组
		{
			if(number[i]>average)
			{
				printf("%d ",number[i]); // 使用数组中的元素
			}
		}
	}
	return 0;
}

```
### 写一个程序，输入数量不确定的[0,9]范围内的整数，统计每一种数字出现的次数，输入-1表示结束。
```C
#include<stdio.h>
int main(void)
{
  const int number=10; // C99 数组的大小
  int x;
  int count[number]; //  定义数组
  int i;
  
  for(i=0;i<number;i++) // 初始化数组
  {
    count[i]=0;
  }
  scanf("%d",&x);
  while(x!=-1)
  {
    if(x>=0 && x<=9)
    {
      count[x]++; // 数组参与运算
    }
    scanf("%d",&x);
  }
  for(i=0;i<number;i++) // 遍历数组输出
  {
    printf("%d:%d\n",i,count[i]);
  }
  
  return 0;
}
```
## 函数的定义与使用
