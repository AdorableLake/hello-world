# Week 13 程序结构
## 13.1 全局变量
### 13.1.1 全局变量
#### 1. 全局变量
1. 定义在函数外面的变量；
2. 具有全局的生存期和作用域；
```C
#include<stdio.h>

int f(void);

int gAll = 12;

int main(int argc, const char * argv[])
{
  printf("in %s gAll = %d\n", __func__, gAll);      //__func__->当前的函数
  f();
  printf("agn in %s gAll = %d\n", __func__, gAll);
  return 0;
}

int f(void)
{
  printf("in %s gAll = %d\n", __func__, gAll);
  gAll += 2;
  printf("agn in %s gAll = %d\n", __func__, gAll);
  return gAll;
}
```

#### 2. 全局变量的初始化
1. 没有做初始化的全局变量会得到 `0` 值，而指针全局变量会得到 `NULL`；
2. 只能用编译时刻已知的值来初始化全局变量；
3. 他们的初始化发生在 `main` 函数之前；

[返回标题行](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week13_Course.md#week-13-程序结构)

### 13.1.2 静态本地变量
#### 1. 静态本地变量
1. 在本地变量定义时加入上 `static` 修饰符就会成为静态本地变量；
2. 当函数离开的时候，静态本地变量会继续存在并保持其值；
3. 静态本地变量的初始化只会在第一次进入这个函数时做，以后进入函数时会保持上次离开时的值；

```C
#include<stdio.h>

int f(void);

int gAll = 12;

int main(int argc, const char * argv[])
{
  f();
  f();
  f();
  return 0;
}

int f(void)
{
  static int all = 1;
  printf("in %s all = %d\n", __func__, all);
  all += 2;
  printf("agn in %s all = %d\n", __func__, all);
  return all;
}
```

#### 2. 静态本地变量、全局变量、本地变量
1. 静态本地变量实际上是特殊的全局变量，它们位于相同的内存区域；
2. 静态本地变量具有全局的生存期，函数内的局部作用域，`static` 在这里的意思其实是局部作用域（本地可访问）；

[返回标题行](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week13_Course.md#week-13-程序结构)

### 13.1.3 全局变量贴士
#### 1. 返回指针的函数
1. 返回本地变量的地址是危险的；
2. 返回全局变量/静态本地变量的地址是安全的；
3. 返回在函数内 `malloc` 的内存是安全的，但容易造成问题；
4. 最好的做法是返回传入的指针；

```C
// 返回本地变量的地址是危险的
#include<stdio.h>

int* f(void);
void g(void);

int main(int argc, const char * argv[])
{
  int *p = f();
  printf("*p = %d\n",*p);
  g();
  printf("8p = %d\n",*p);
  
  return 0;
}

int* f(void)
{
  int i = 12;
  return &i;
}

void g(void)
{
  int k = 24;
  printf("k = %d\n",k);
}
```

#### 2. 提示
1. 不要使用全局变量来在函数间传递参数和结果；
2. 尽量避免使用全局变量：[丰田汽车2013年事故](https://www.sohu.com/a/133455549_464086)
3. 使用全局变量和静态本地变量的函数的线程不安全；

[返回标题行](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week13_Course.md#week-13-程序结构)

## 13.2 编译预处理
### 13.2.1 宏定义
#### 1. 编译预处理指令：#define/#include
1. `#` 开头的是编译预处理指令；
2. 不是C语言的成分，但C语言离不开；
3. `#define` 用来定义一个宏。

#### 2. #define

#### 3. 没有值的宏

#### 4. 与定义的宏
```
__LINE__
__FILE__
__DATE__
__TIME__
__STDC__
```
### 13.2.2 预定义的宏
#### 1. 像函数的宏
1. 
```
#define cube(x)((x)*(x)*(x))
```
2. 宏可以带参数；

#### 2. 错误定义的宏
```
#define RADTODEG1(x)(x*57.29578)
#define RADTODEG2(x)(x)*57.29578
```
正确定义👇
```
#define RADTODEG(x)((x)*57.29578)
```
#### 3. 带参数的宏
1. 一切都要有括号：整个值和参数出现的地方；
2. 有 `#` 和 `##` 两种形式；
3. 部分可用 `inline` 语句替代;

[返回标题行](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week13_Course.md#week-13-程序结构)

## 13.3 大程序结构
### 1. 多个.c文件
### 2. 头文件
1. 函数源代码存放位置，以.h结尾；
2. 需要时在.c文件中使用 `#include` 来调用；
3. `" "` 与 `< >`：前者更灵活，后者只会在制定目录库中寻找；
### 3. 外部声明
```C
int i;        ->  定义变量 
extern int i; ->  声明变量
```
1. 声明与定义：

定义会产生代码；
声明不产生代码；

2. 声明：

3. 标准头文件格式
```C
#ifndef __LIST_HEAD_
#define __LIST_HEAD_

#include "node.h"

typedef struct _list {
  Node* head;
  Node* tail;
} List;

#endif
```
