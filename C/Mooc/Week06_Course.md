# 第六周 数组与函数

## 目录/Catalog
## [1. 数组](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week06_Course.md#1-数组-1)
### 1.1 如何写一个程序计算用户输入的数字的平均数？
### 1.2 如何写一个程序计算用户输入的数字的平均数，并输出所有大于平均数的数？
### 1.3 定义数组
### 1.4 写一个程序，输入数量不确定的[0,9]范围内的整数，统计每一种数字出现的次数，输入-1表示结束。
## [2. 函数的定义与使用](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week06_Course.md#2-函数的定义与使用)
### 2.1 求素数和
### 2.2 求和：求出1～10、20～30、35～45的三个和
### 2.3 函数定义
### 2.4 从函数中返回值
### 2.5 没有返回值的函数
## [3. 函数的参数和变量](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week06_Course.md#3-函数的参数和变量-1)
### 3.1
### 3.2
### 3.3
### 3.4
## [4. 二维数组](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week06_Course.md#4-二维数组-1)
### 4.1 二维数组
### 4.2 

## 1. 数组
### 1.1 如何写一个程序计算用户输入的数字的平均数？
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
### 1.2 如何写一个程序计算用户输入的数字的平均数，并输出所有大于平均数的数？
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
// 利用数组`int number[i]`
#include<stdio.h>
int main()
{
  int x;
  double sum=0;
  int cnt=0;
  int number[100]; // 定义数组
  scanf("%d",&x);
  while(x!=-1)
  {
    number[cnt]=x; // 对数组元素赋值
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
      if(number[i]>sum/cnt)
      {
        printf("%d\n",number[i]); // 使用数组的元素
      }
    }
  }
  return 0;
}
// 存在超过数组范围的风险`cnt>number[100]`
```
### 1.3 定义数组
#### 数组：
1. 其中所有的元素具有相同的数据类型；
2. 一旦创建不能改变大小；
3. 数组中的元素在内存中是连续一次排列的

#### 提前输入数字数量
```C
// 利用数组`int number[i]`
#include<stdio.h>
int main()
{
  int x;
  int cnt;
  printf("Enter the number of the list:\n");
  scanf("%d\n".&cnt);
  double sum=0.0;
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
      if(number[i]>sum/cnt)
      {
        printf("%d\n",number[i]); // 使用数组的元素
      }
    }
  }
  return 0;
}
// 存在超过数组范围的风险`cnt>number[100]`
```

### 1.4 写一个程序，输入数量不确定的[0,9]范围内的整数，统计每一种数字出现的次数，输入-1表示结束。
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
## 2. 函数的定义与使用
### 2.1 求素数和
```C
#include<stdio.h>
int main()
{
  int m,n;
  int sum=0;
  int cnt=0;
  int i;
  
  scanf("%d %d",&m,&n);
  // m=10,n=31;
  if(m==1)
  {
    m=2;
  }
  for(i=m;i<=n;i++) // 判断`i`是否是素数
  {
    int isPrime=1;
    int k;
    for(k=2;k<i-1;k++)
    {
      if(i%k==0)
      {
        isPrime=0;
        break;
      }
    }
    if(isPrime) // 代表`isPrime==1`
    {
      sum+=i;
      cnt++;
    }
  }
  printf("%d %d\n",cnt,sum);
  
  return 0;
}
```
可以变成下面这样👇
```C
#include<stdio.h>

int isPrime(int n) // 定义了一个自定函数
{
  int res=1;
  int k;
  for(k=2;k<i-1;k++)
  {
    if(i%k==0)
    {
      isPrime=0;
      break;
    }
  }
  return res;
}

int main()
{
  int m,n;
  int sum=0;
  int cnt=0;
  int i;
  
  scanf("%d %d",&m,&n);
  // m=10,n=31;
  if(m==1)
  {
    m=2;
  }
  for(i=m;i<=n;i++) // 判断`i`是否是素数
  {
    if(isPrime(i)) 
    {
      sum+=i;
      cnt++;
    }
  }
  printf("%d %d\n",cnt,sum);
  
  return 0;
}
```
### 2.2 求和：求出1～10、20～30、35～45的三个和
```C
// `Command+C` `Command+V`->代码复制->不良代码
// 所以我们写自己的函数
#include<stdio.h>

void sum(int begin, int end)
{
  int i;
  int sum=0;
  for(i=begin;i<=end;i++)
  {
    sum+=i;
  }
  printf("%d到%d的和是%d\n",begin,end,sum);
}

int main()
{
  sum(1,10);
  sum(20;30);
  sum(35,45);
  return 0;
}
```
### 2.3 函数定义
以下面的代码为例
```C
void sum(int begin, int end)
// 第一行为函数头，`void`为返回类型，`sum`为函数名，`int begin, int end`为参数表
{
  int i;
  int sum=0;
  for(i=begin;i<=end;i++)
  {
    sum+=i;
  }
  printf("%d到%d的和是%d\n",begin,end,sum);
}
// `{}`内部为函数体
```
### 2.4 从函数中返回值
```C
int max(int a, int b)
{
  int ret;
  if(a>b)
  {
    ret=a;
  }
  else
  {
    ret=b;
  }
  return ret;
}
// “单一出口理念”
```

```C
int max(int a, int b)
{
  if(a>b)
  {
    return a;
  }
  else
  {
    return b;
  }
}
// 不符合“单一出口”理念
```
### 2.5 没有返回值的函数
```
viod 函数名（参数表）
```
## 3. 函数的参数和变量
### 3.1 函数先后关系
```C
#include<stdio.h>
void sum(int begin, int end);
// 函数原型
int main()
{
  sum(1,10);
  sum(20;30);
  sum(35,45);
  return 0;
}

void sum(int begin, int end)
// 真正的函数头
{
  int i;
  int sum=0;
  for(i=begin;i<=end;i++)
  {
    sum+=i;
  }
  printf("%d到%d的和是%d\n",begin,end,sum);
}
```
```C
#include<stdio.h>
int main()
{
  void sum(int begin, int end);
  // 旧版本的函数原型，现阶段不使用
  sum(1,10);
  sum(20;30);
  sum(35,45);
  return 0;
}

void sum(int begin, int end)
// 真正的函数头
{
  int i;
  int sum=0;
  for(i=begin;i<=end;i++)
  {
    sum+=i;
  }
  printf("%d到%d的和是%d\n",begin,end,sum);
}
```
### 3.2 参数传递
调用函数给的值与参数的类型不匹配是C语言的传统上最大的漏洞，因此需要自己对于编程上的参数进行匹配。
#### 3.2.1 传值
1. 每个函数有自己的变量空间，参数也位于着独立的空间中，和其他函数没有关系；
2. 过去，对于函数参数表中的参数，叫做“形式参数”，调用函数时给的值叫做“实际参数“；
```C
#include<stdio.h>
void swap(int a, int b); // 形参（Formal Actor）->参数

int main()
{
  int a=5;
  int b=6;
  
  swap(a,b); // 实参（Real Actor）->值
  
  return 0;
}

void swap(int a, int b) // 形参（Formal Actor）->参数
// 真正的函数头
{
  int t=a;
  a=b;
  b=t;
}
// 不建议使用这种“古老的语言去形容这些变量”
// 我们认为是“参数”和“值”
```
### 3.3 本地变量（Local Variables）
#### 3.3.1 定义
1. 函数的每次运行，就产生了一个独立的变量空间，在这个空间中的变量，是函数的这次运行所独有的，乘坐本地变量；
2. 定义在函数内部的变量就是本地变量；
3. 参数也是本地变量。
#### 3.3.2 变量的生存期和作用域
1. 生存期：什么时候这个变量开始出现了，到什么时候消亡了；
2. 作用域：在代码的什么范围内可以访问这个变量（即该变量可以起作用）；
3. 对于本地变量来说，上述两个概念是一样的，即`{}`内部的“块”。

以`swap`语句为例👇
```C
#include<stdio.h>
void swap(int a, int b); 

int main(void)
{
  int a=5;
  int b=6;
  
  swap(a,b); // 这时`C`离开了`main`的变量空间，去到了下方`void`语句的变量空间
  
  return 0;
}

void swap(int a, int b) 
{
  int t=a;
  a=b;
  b=t;
}
```
#### 3.3.3 本地变量的规则
1. 本地变量是定义在块内的；
  1.1. 可以定义在函数的块内；
  1.2. 也可以定义在语句的块内；
  1.3. 甚至可以随机放在一组`{}`内；
2. 程序运行进入这块之前，其中的变量不存在，离开这个块，其中的变量就消失了；
3. 块外面定义的变量在块内仍然有效；
4. 块内部定义的和外部同名的变量则视内部变量有效；
5. 不能在一个块内定义同名变量；
6. 本地变量不会被默认初始化；
7. 参数在进入函数的时候被初始化。

### 3.4 其他细节
#### 3.4.1 没有参数
```
void f(void) 与 void f()的区别
```

不要写下面的原型
```
void swap();❌
```

#### 3.4.2 逗号运算符
```
f(a,b)

f((a,b))
```
#### 3.4.3 函数里的函数？
C语言不允许函数嵌套定义

#### 3.4.4 一些定义（不建议）
```
int i,j,sum(int a, int b);

return (i);
```
不建议🙅

#### 3.4.5 关于`main`
1. `int main()`也是一个函数；
2. `int main(void)`与`int main()`: `void`表示“不输出”；
3. `return 0;`是有意义的

## 4. 二维数组
### 4.1 二维数组
#### 4.1.1 定义
#### 4.1.2 二维数组的遍历
