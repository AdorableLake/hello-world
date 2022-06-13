# Week 13 程序结构
## 13.1 全局变量
### 1. 全局变量
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

### 2. 全局变量的初始化
1. 没有做初始化的全局变量会得到 `0` 值，而指针全局变量会得到 `NULL`；
2. 只能用编译时刻已知的值来初始化全局变量；
3. 他们的初始化发生在 `main` 函数之前；


[返回标题行](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week13_Course.md#week-13-程序结构)

### 3. 静态本地变量
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

### 4. 静态本地变量、全局变量、本地变量
1 静态本地变量实际上是特殊的全局变量；
2
