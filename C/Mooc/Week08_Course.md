# 第8周 指针与字符串
## 1. 指针
### 1.1 取地址运算
#### 运算符`sizeof`
是一个运算符，能够给出某个类型或变量在内存中所占据的字节数
1. `sizeof(int)`
2. `sizeof(i)`

```C
#include<stdio.h>
int main()
{
  int a;
  a = 6;
  printf("sizeof(int)=%d\n",sizeof(int));
  printf("sizeof(a)=%d\n",sizeof(a));
  return 0;
}
```
#### 运算符`&`
`scanf("%d",&i);`里的`&`
1. 用来获得变量的地址，操作数必须是变量

```
int i; printf("%x", &i);
```
2. 地址的大小是否与`int`相同，取决于编译器架构（32-bit or 64-bit）

```
int i; printf("%p",&i);
```
例子🌰
```C
#include<stdio.h>
int main(void)
{
  int i = 0;
  int p;
  p = (int)&i; // 强制整型
  printf("0x%x\n", p); 
  printf("%p\n", &i); // 取地址
  printf("%lu\n",sizeof(int));
  printf("%lu\n",sizeof(&i));
  
  return 0;
}
// 32-bit & 64-bit 会有区别
```
3. `&`不能取的地址
`&`不能对没有地址的东西取地址

`&(a+b)`->?

`&(a++)`->?

`&(++a)`->?

```C
#include<stdio.h>

int main(void)
{
  int a[10];
 
  printf("%p\n", &a); 
  printf("%p\n", a);
  printf("%p\n",&a[0]); //取a[0]的地址
  printf("%p\n",&a[1]); //取a[1]的地址
  
  return 0;
}
```
### 1.2 指针
#### 指针
```
int i;
int* p = &i;
int* p,q;
int *p,q;✅->`*p`为指针
```
#### 指针变量
1. 变量的值是内存的地址；
2. 普通变量的值是实际的值；
3. 指针变量的值是具有实际值的变量的地址；


#### 作为参数的指针
1. `void f(int*p)`;
2. 在被调用的时候得到了某个变量的地址：`int i=0; f(&i)`，在函数里可以通过该指针访问外面的`i`;

例子🌰
```C
#include<stdio.h>

void f(int *p);

int main(void)
{
  int i =6;
  printf("&i=%p\n",&i);
  f(&i);
  
  return 0;
}

void f(int *p)
{
  printf(" p=%p\n",p);
}
```
#### 访问那个地址上的变量
`*`是一个单目运算符，用来访问指针的值所表示的低智商的变量

既可以表示左值也可以表示右值
```
int k = *p;->
*p = k+1;-> 
```
例子🌰
```C
#include<stdio.h>

void f(int *p);
void g(int k);

int main(void)
{
  int i =6;
  printf("&i=%p\n",&i);//指的是i代表的地址
  f(&i);
  g(i);
  
  return 0;
}

void f(int *p)
{
  printf(" p=%p\n",p);
  printf("*p=%d\n",*p);
  *p = 26;//函数代表的是值的传递
}

void g(int k)
{
  printf("k=%d\n",k);
}
```
### 1.3 指针与数组
#### 1.3.1 传入函数的数组成了什么？
```
int isPrime(int x, int knownPrimes[], int numberOfKnownPrimes)
{
  int ret = 1;
  int i;
  for( i=0; i<numberOfKnownPrimes; i++ )
  {
    if( x % knownPrimes[i] == 0 )
    {
      ret = 0;
      break;
    }
  }
  return ret;
}
```
#### Explore
<details>
<summary>点击这里打开/关闭隐藏内容😯</summary>
<p>
  
```C
#include<stdio.h>

void minmax(int a[], int len, int *max, int *min);

int main(void)
{
  int a[] = {1,2,3,4,5,6,7,8,9,12,13,14,16,17,21,23,55,};
  int min,max;
  printf("main sizeof(a)=%lu\n",sizeof(a));
  minmax(a, sizeof(a)/sizeof(a[0]),&min,&max);
  printf("min=%d,max=%d\n",min, max);
  
  return 0;
}

void minmax(int a[], int len, int *max, int *min)
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

```C
#include<stdio.h>

void minmax(int a[], int len, int *max, int *min);

int main(void)
{
  int a[] = {1,2,3,4,5,6,7,8,9,12,13,14,16,17,21,23,55,};
  int min,max;
  printf("main sizeof(a)=%lu\n",sizeof(a));//
  
  printf("main a=%p\n",a); // 查看a的地址
  
  minmax(a, sizeof(a)/sizeof(a[0]),&min,&max);
  printf("min=%d,max=%d\n",min, max);
  
  return 0;
}

void minmax(int a[], int len, int *max, int *min)
// int a[]即为指针
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
</details>
  
```
int isPrime(int x, int knownPrimes[], int numberOfKnownPrimes)
{
  int ret = 1;
  int i;
  for( i=0; i<numberOfKnownPrimes; i++ )
  {
    if( x % knownPrimes[i] == 0 )
    {
      ret = 0;
      break;
    }
  }
  return ret;
}
```
1. 因此函数参数表中的数组其实是指针
                                   
2. `sizeof(a) == sizeof(int*)`

3. 尽管如此，可以用数组的运算符`[]`进行运算                     
