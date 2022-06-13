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
