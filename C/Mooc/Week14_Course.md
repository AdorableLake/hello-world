# Week14 交互图形设计
## 14.2 函数指针
### 1. 函数指针
```C
#include<stdio.h>

void f(void)
{
    printf("in f()\n");
}

int main(void)
{
    int i = 0;
    int *p = &i;
    * p = 20;
    int a[] = {1,2};
    
    void (*pf)(void) = f;       //指向函数的指针(参数表为void，函数类型也是void)
    
    f(); //-> f函数本身
    (*pf)();//-> f函数的指针(*pf)
    
    printf("%p\n", main);
    printf("%p\n", pf);
    printf("%p\n", a);
  
    return 0;
}
```
### 2. 函数指针的运用
```C
#include<stdio.h>

void f(int i)
{
    printf("in f(), %d\n", i);
}

int main(void)
{
    int i = 0;
    int *p = &i;
    * p = 20;
    int a[] = {1,2};
    
    void (*pf)(int) = f;       //指向函数的指针(参数表为void，函数类型也是void)
    
    f(20); //-> f函数本身
    (*pf)(10);//-> f函数的指针(*pf)
    
    printf("%p\n", main);
    printf("%p\n", pf);
    printf("%p\n", a);
  
    return 0;
}
```
不使用函数指针的情况：
```C
#include<stdio.h>

void f(int i);
void g(int i);
void h(int i);

int main(void)
{
    int i;
    scnaf("%d", &i);
    switch(i) {
        case 0: f(0); break;
        case 1: g(0); break;
        case 2: h(0); break;
    }
    return 0;
}

void f(int i)
{
    printf("in f(), %d\n", i);
}

void g(int i)
{
    printf("in g(), %d\n", i);
}

void h(int i)
{
    printf("in h(), %d\n", i);
}
```

使用函数指针的情况：
```C
#include<stdio.h>

void f(int i);
void g(int i);
void h(int i);

int main(void)
{
    int i;
    scnaf("%d", &i);
    (void)(*fa)(int) = {f,g,h};
    if( i>= 0 && i<sizeof(fa)/sizeof(fa[0]) ) {
        (*fa[i])(0);
    }
    return 0;
}

void f(int i)
{
    printf("in f(), %d\n", i);
}

void g(int i)
{
    printf("in g(), %d\n", i);
}

void h(int i)
{
    printf("in h(), %d\n", i);
}
```

```C
#include<stdio.h>

int plus(int a, int b);
int minus(int a, int b);
void cal(int (*f)(int, int));

int main(void)
{
    cal(plus);
    cal(minus);
    
    return 0;
}

int plus(int a, int b)
{
    return a+b;
}

int minus(int a, int b)
{
    return a-b;
}

void cal(int (*f)(int, int))
{
    printf("%d", (*f)(2,3));
}
```
