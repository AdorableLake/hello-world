# 第8周 指针与字符串
## 1. 指针
### 1.1 取地址运算

#### 运算符`sizeof`
是一个运算符，能够给出某个类型或变量在内存中所占据的字节数
1. `sizeof(int)`
2. `sizeof(i)`

🌰
  
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
🌰

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

🌰
  
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

[返回页首](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week08_Course.md#第8周-指针与字符串)

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

🌰

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

🌰
  
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

[返回页首](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week08_Course.md#第8周-指针与字符串)

### 1.3 指针与数组
#### 1.3.1 传入函数的数组成了什么？
```C
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
#### 1.3.2 Explore

🌰
  
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

[返回页首](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week08_Course.md#第8周-指针与字符串)

🌰

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

[返回页首](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week08_Course.md#第8周-指针与字符串)

🌰
  
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

[返回页首](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week08_Course.md#第8周-指针与字符串)

#### 1.3.3 小结
1. 因此函数参数表中的数组其实是指针；
                                   
2. `sizeof(a) == sizeof(int*)`；

3. 尽管如此，可以用数组的运算符`[]`进行运算；

#### 1.3.4 数组参数
下列四种函数原型是等价的
  1. `int sum(int *ar, int n);`
  2. `int sum(int *, int);`
  3. `int sum(int ar[], int n);`
  4. `int sum(int [], int);`
  
#### 1.3.5 数组变量是特殊的指针，
  1. 数组变量本身表达地址，所以：
  
    1.1 `int a[10]; int *p=a;` // 无须使用`&` 取地址；
  
    1.2 但是数组的单元表达的是变量，需要用`&`取地址；
  
    1.3 `a == &a[0]`
  
  2. `[]`运算符可以对数组做，也可以对指针做：
  
    2.1 `p[0] <==> a[0]`
  
  3. `*`运算符既可以对指针做，也可以对数组做；
  
    3.1 例如`*a=25`；
  
  4. 数组变量其实是`const`(常量)的指针，因此不能被赋值；
  
    4.1 `int a[] <==> int * const a=`
  
🌰
  
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

[返回页首](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week08_Course.md#第8周-指针与字符串)
  
## 2. 字符类型
  ### 2.1 字符类型
  char是一种整数，也是一种特殊的类型：字符。
  1. 用单引号表示的字符字面量：'a','1';
  2. ''也是一个字符；
  3. `Printf`和`Scanf`里用`%c`来输入输出字符

🌰
  
  ```C
  #include<stdio.h>
  int main()
  {
    char c;
    char d;
    c = 1;
    d = '1';
    if( c == d )
    {
      printf("相等\n");
    }
    else
    {
      printf("不相等\n");
    }
    printf("c=%d\n",c);
    printf("d=%d\n",d);
  
    return 0;
  }
  ```
  
  
### 2.2 字符的输入输出
如何输入‘1’这个字符给`char c`?
1. `scnaf("%c",&c);`->1
2. `scanf("%d",&i);c=i`->49

🌰
  
```C
#include<stdio.h>
int main()
{
  char c;
  scnaf("%c",&c);
  printf("c=%d\n",c);
  printf("c='%c'\n",c);
    
  return 0;
}
```

[返回页首](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week08_Course.md#第8周-指针与字符串)
  
### 2.3 混合输入
#### 2.3.1 有何区别？
```
  scanf("%d %c",&i,&c);
  scanf("%d%c",&i,&c);
```
  
🌰
  
```C
#include<stdio.h>
int main()
{
  int i;
  char c;
  scnaf("%d %c",&i,&c);
  printf("i=%d,c=%d,c=`%c`\n"i,c,c);

  return 0;
}
```
  
[返回页首](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week08_Course.md#第8周-指针与字符串)  
  
#### 2.3.2 字符计算
```
  char c = 'A';
  c++;
  printf("%c\n",c);
```
  
🌰
  
```C
#include<stdio.h>
int main()
{
  char c = 'A';
  c++;
  printf("%c\n",c);

  return 0;
}
``` 

```
  int i = 'Z' - 'A'
  printf("%d\n",i);
```
  
### 2.4 逃逸字符
#### 2.4.1 逃逸字符
用来表达无法打印出来的控制字符或特殊字符，由一个反斜杠`\`开头，后面跟上另一个字符，两个字符和起来，组成了一个字符
```
  printf("请分别输入身高的英尺和英寸"
  "如输入\"5 7\"表示5英尺7英寸：");
```

[返回页首](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week08_Course.md#第8周-指针与字符串)

## 3. 字符串
### 3.1 定义
1. 以整数0结尾的一串字符  ->  0 <==> '\0', 0!='0';
2. 0标志字符串的结束，但它不是字符串的一部分  ->  计算字符串长度的时候不包含这个 0；
3. 字符串以数组的形式存在，以数组或指针的形式访问  ->  更多地是以指针的形式；
4. <string.h>里有很多处理字符串的函数；

### 3.2 字符串变量
1. 
```C
char *str = "Hello";
```
2. 
```C
char word[] = "Hello";
```
3. 
```C
char line[10] = "Hello";
```

### 3.3 字符串常量 
```
char *s = "Hello World";
```
<img width="1312" alt="截屏2022-06-08 18 55 33" src="https://user-images.githubusercontent.com/50417000/172599685-fc2b801c-c428-4570-a0b9-2b12a3c3d1e8.png">

#### 3.3.1

<img width="1312" alt="截屏2022-06-08 18 57 31" src="https://user-images.githubusercontent.com/50417000/172600025-d8e000e1-ebfa-4ab3-b01e-715462c838b4.png">

## 4. 字符串计算
<img width="1312" alt="截屏2022-06-08 19 03 01" src="https://user-images.githubusercontent.com/50417000/172601042-63337185-1b56-4302-9874-96c1af2a6010.png">

### 4.1 常见错误
<img width="1312" alt="截屏2022-06-08 19 07 17" src="https://user-images.githubusercontent.com/50417000/172601835-fb957d0d-f27a-42b0-aae9-501684644f7e.png">

### 4.2 空字符串
<img width="1312" alt="截屏2022-06-08 19 09 54" src="https://user-images.githubusercontent.com/50417000/172602300-3ad41c4f-0ff1-4ef8-a0ab-c98a3a3d3a08.png">

### 4.3 string.h
1. strlen: `size_t strlen(const char *s); //const 保证 strlen 不会修改字符串`
```C
#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char line[] = "Hello";
    printf("strlen=%lu\n",strlen(line));
    printf("sizeof=%lu\n",sizeof(line));
  
    return 0;
}
```
2. strcmp: `int strcmp(const char *s1,const char *s2);`

```C
#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char s1[] = "abc";
    char s2[] = "abc";
    printf("%d\n",strcmp(s1,s2));
  
    return 0;
}
```
3. strcpy: `char *strcpy(char *restrict dst, const char *restrict src);`
把src的字符串拷贝到dst，并返回dst

4. strcat: `char *strcat(char *restrict s1, const char *restrict s2);`
把s2拷贝到s1的后面，接成一个长的字符串，再返回s1，其中s1必须具有足够的空间

⚠️上述代码不够安全！(容易越界)

安全版本👇
```
char * strncpy(char *restrict dst, const char *restrict src,size_t n);
char * strncat(char *restrict s1, const char *restrict s2,size_t n);
int strncmp(const char *s1, const char *s2,size_t n);
```

5. 
`char *strchr(const char *s, int c)`->从左到右查找c在字符串中第一次出现的位置，返回的是指针；

`char *strrchr(const char *s, int c)`->从右到左查找c在字符串中第一次出现的位置，返回的是指针；

返回`NUll`表示没有找到；
