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
