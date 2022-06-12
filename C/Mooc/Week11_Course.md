# Week 11 结构类型

## 11.1 枚举
### 1. 常量符号化

用符号而不是具体的数字来表示程序中的数字

### 2. 枚举
1. 例子
```C
#include<stdio.h>
enum COLOR {RED, YELLOW, GREEN};

int main(int argc, char const *argv[])
{
    int color = -1;
    char *colorname = NULL;
    
    printf("Input your favorite color:\n");
    scanf("%d", &color);
    switch(color)
    {
        case RED: colorname = "red"; break;
        case YELLOW: colorname = "yelow"; break;
        case GREEN: colorname = "green"; break;
        default: colorname = "unknown"; break;
    }
    printf("Your favorite color is %s.\n",colorname);
    
    return 0;
}
```
用枚举而不是定义独立的 const int 变量；

2. 定义

2.1 枚举是一种用户定义的数据类型，用关键字 enum 用以下语法来声明
```
enum name{name0,name1,...,namen};
```
2.2 枚举类型名字通常不真的使用，通常使用大括号内的名字，因为他们就是 int 类型的常量符号，值依次从0到n
```
enum colols{red yello,green};
```
2.3 定义枚举的意义就是给力这些常量值的名字

```C
#include<stdio.h>

enum COLOR {RED, YELLOW, GREEN};    

void f(enum color c)            //C语言使用枚举需要带上关键字enum
{
    printf("%d\n",c);           //尽管使用的是enum类型，内部进行运算是使用int
}

int main(void)
{
    enum color t = RED;         
    scanf("%d", &t);            //外部输出也采用int
    return 0;
}
```
### 3. 套路：自动计数的枚举
```C
#include<stdio.h>
enum COLOR {RED, YELLOW, GREEN, NumCOLORS};

int main(int argc, char const *argv[])
{
    int color = -1;
    char *ColorNames[NumCOLORS] = {"red","yellow","green",}; 
    //需要遍历所有的枚举量或者需要建立一个用枚举量做下标的数组就会方便很多
    char *colorname = NULL;
    
    printf("Input your favorite color:\n");
    scanf("%d", &color);
    if(color >= 0 && color < NumCOLORS)
    {
        colorname = ColorNames[color];
    }
    else
    {
        colorname = "unknown";
    }
  
    printf("Your favorite color is %s.\n",colorname);
    
    return 0;
}
```
### 4.枚举量
声明枚举量可以指定值；

枚举只是int，不会出现warning/error；

[返回标题行](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week11_Course.md#week-11-结构类型)

## 11.2 结构
### 11.2.1 
#### 1. 声明结构类型
```C
#include<stdio.h>
struct date
{
    int month;
    int day;
    int year;
};                  //;不能漏掉

int main(int argc, char const *argv[])
{

    
    struct date today;
    
    today.month = 06;
    today.day = 12;
    today.year = 2022;
    
    printf("Today's date is %i-%i-%i.\n",today.year,today.month,today.day);
    return 0;
}
```
