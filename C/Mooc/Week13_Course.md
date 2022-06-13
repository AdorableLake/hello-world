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

[返回标题行](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week13_Course.md#week-13-程序结构)

### 2. 全局变量的初始化
1. 没有做初始化的全局变量会得到 `0` 值，而指针全局变量会得到 `NULL`；
2. 只能用编译时刻已知的值来初始化全局变量；
3. 他们的初始化发生在 `main` 函数之前；
