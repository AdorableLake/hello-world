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
