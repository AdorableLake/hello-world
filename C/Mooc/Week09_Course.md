# Week09: 指针与字符串
## 9.1 指针的使用
### 9.1.1
#### 1. 指针应用场景一
交换两个变量的值
```C
#include<stdio.h>

void swap(int *pa, int *pb);

int main(void)
{
    int a=5,b=6;
    swap(&a,&b);
    printf("a=%d,b=%d\n",a,b);
    
    return 0;
}

void swap(int *pa, int *pb)
{
    int t= *pa;
    *pa=*pb;
    *pb=t;
}
```
#### 2. 指针应用场景二
A.
1. 函数返回多个值，某些值就只能通过指针返回；
2. 传入的参数实际上是需要保存带回的结果的变量；
```C
#include<stdio.h>

void minmax(int a[], int len, int *max, int *min);

int main(void)
{
    int a[]={1,2,3,4,5,6,7,8,9,12,13,14,16,17,21,23,55,};
    int min,max;
    minmax(a,sizeof(a)/sizeof(a[0]),&max,&min);
    printf("min=%d,max=%d\n",min,max);
    
    return 0;
}

void minmax(int a[], int len, int *max, int *min)
{
    *min = *max = a[0];
    for(int i=1; i<len;i++)
    {
        if(a[i] < *min)
        {
            *min = a[i];
        }
        if(a[i] > *max)
        {
            *max = a[i];
        }
    }
}
```
B.
1. 函数返回运算的状态，结果通过指针返回
2. 常用套路是让函数返回特殊的，不属于有效范围内的值来表示出错；
3. 但是当任何数值都是有效的可能结果时，就得分开返回；

```C
#include<stdio.h>
/*
return: 除法成功返回1；否则返回0
*/
int divide(int a, int b, int *result)
{
    int res = 1;
    if(b==0) res =0;
    else *result = a/b;
    return res;
}

int main(void)
{
    int a = 5;
    int b = 2;
    int c;
    if (divide(a,b,&c) ) printf("%d/%d=%d\n",a,b,c);
    return 0;
}
```
#### 3. 常见错误
1. 定义了指针变量，但没有指向任何变量，就开始使用指针；
e.g(错误例子)
```C
#include<stdio.h>

void f(int *p)
{
    printf("p=%p\n",p);
    printf("*p=%d\n",*p);
    *p = 26;
}

void g(int k)
{
    printf("k=%d\n",k);
}

int main(void)
{
    int i = 6;
    int *p=0;
    int k;
    k = 12;
    *p = 12;
    printf("&i=%p\n",&i);
    f(&i);
    g(i);
    
    return 0;
}
```
### 9.1.2 指针与数组
#### 1. 传入函数的数组
```C
int isPrime(int x, int knowPrimes[], int NumberOfKnownPrimes)
{
    int ret = 1;
    int i;
    for(int i=0;i<NumberOfKnownPrimes;i++)
    {
        if(x%knownPrimes[i]==0)
        {
            ret=0;
            break;
        }
    }
    return ret;
}
```

e.g
```C
#include<stdio.h>

void minmax(int a[], int len, int *max, int *min);

int main(void)
{
    int a[]={1,2,3,4,5,6,7,8,9,12,13,14,16,17,21,23,55,};
    int min,max;
    printf("main sizeof(a)=%lu\n",sizeof(a));
    minmax(a,sizeof(a)/sizeof(a[0]),&max,&min);
    printf("min=%d,max=%d\n",min,max);
    
    return 0;
}

void minmax(int a[], int len, int *max, int *min)
{
    printf("minmax sizeof(a)=%lu\n",sizeof(a));
    *min = *max = a[0];
    for(int i=1; i<len;i++)
    {
        if(a[i] < *min)
            *min = a[i];
        }
        if(a[i] > *max)
        {
            *max = a[i];
        }
    }
}
```
### 2. 数组变量是特殊的指针
注：这一部分和入门的第八周视频一致[Week08 Note](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week08_Course.md#135-数组变量是特殊的指针)

1. 数组变量本身表达地址，所以：
```
1. int a[10]; int *p=a;`// 无须使用`&` 取地址；
2. 但是数组的单元表达的是变量，需要用`&`取地址；
3. a == &a[0]
```
2. `[]`运算符可以对数组做，也可以对指针做：
```
p[0] <==> a[0]//指针变量
```
3. `*`运算符既可以对指针做，也可以对数组做；
```
例如`*a=25`；
```
4. 数组变量其实是const(常量)的指针，因此不能被赋值；
```
int a[] <==> int * const a=`
```
例子
```C
#include<stdio.h>

void minmax(int *a, int len, int *max, int *min);

int main(void)
{
  int a[] = {1,2,3,4,5,6,7,8,9,12,13,14,16,17,21,23,55,};
  int min,max;
  printf("main sizeof(a)=%lu\n",sizeof(a));//
  
  printf("main a=%p\n",a); // 查看a的地址
  
  minmax(a, sizeof(a)/sizeof(a[0]),&min,&max);
  printf("min=%d,max=%d\n",min, max);
  
  int *p = &min;
  printf("*p=%d\n",*p);
  printf("p[0]=%d\n",p[0]); 
  printf("*a=%d\n",*a);
  int b[] --> int * const b;
  int *q = a;
  // p[0] 指 p 这个数组的第一个单元，这是一个指针变量，因此可如此书写
  
  return 0;
}

void minmax(int *a, int len, int *max, int *min)
{
  int i;
  printf("minmax sizeof(a)=%lu\n",sizeof(a));
  *min = *max = a[0];
  for( i=1; i<len; i++ )
  {
    if( a[i] < *min )
    {
      *min = a[i];
    }
    else if( a[i] > *max )
    {
      *max = a[i];
    }
  }
}
```
### 9.1.3 指针与const
