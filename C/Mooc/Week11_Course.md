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
#### 2. 声明结构的形式
```C
//标准形式
struct point
{
    int x;
    int y;
};
struct point p1,p2;

//无名结构
struct
{
    int x;
    int y;
}p1,p2;

//名为p1、p2的 point 结构体
struct point
{
    int x;
    int y;
}p1,p2;
```

#### 3. 结构的初始化
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

    
    struct date today = {06,12,2022};
    struct date thismonth = {.month=6,.year=2022};
    
    today.month = 06;
    today.day = 12;
    today.year = 2022;
    
    printf("Today's date is %i-%i-%i.\n",today.year,today.month,today.day);
    printf("This month is %i-%i.\n",thismonth.year,thismonth.month);
    return 0;
}
```
#### 4. 结构成员
结构和数组类似：数组用 `[]` 运算符和下标访问其成员；结构用 `.` 运算符和名字访问其成员；
```C
a[0]=10;

today.day;
student.firstName;
p1.x;
p2.y;
```
#### 5. 结构运算
1. 要访问整个结构，直接用结构变量的名字；
2. 对于整个结构，可以做赋值、取地址，也可以传递给函数参数；
```
p1=(struct point){5,10}; <==> p1.x=5;p1.y=10;
p1=p2; <==> p1.x=p2.x;p1.y=p2.y;

//⚠️注意：数组无法执行以上两种运算！
```

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
    
    today = (struct date){06,12,2022};
    
    struct date day;
    
    day = today;
    
    printf("Today's date is %i-%i-%i.\n",today.year,today.month,today.day);
    printf("The day's date is %i-%i-%i.\n",day.year,day.month,day.day);
    return 0;
}
```

#### 6. 结构指针
和数组不同，结构变量的名字并不是结构变量的地址，必须使用 `&` 运算符
```
struct date *pDate = &today;
```

[返回标题行](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week11_Course.md#week-11-结构类型)

### 11.2.2 结构与函数
#### 1. 结构作为函数参数
```C
int NumberOfDays(struct date d)
```
1. 整个结构可以作为参数的值传入函数；
2. 此时在函数内新建一个结构变量，并复制调用者的结构的值；
3. 也可以返回一个结构；
4. 与数组完全不同；
```C
#include<stdio.h>
#include<stdbool.h>

struct date
{
    int month;
    int day;
    int year;
};                  

bool isLeap(struct date d)          //判断是否为闰年
{
    bool leap = false;
    if( (d.year %4 == 0 && d.year %100 != 0 || d.year %400 ==0) )
        leap = true;
    return leap;
}

int NumberOfDays(struct date d)     //判断月份
{
    int days;
    const int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(d.month == 2 && isLeap(d))
        days = 29;
    else
        days = daysPerMonth[d.month-1];
        
    return days;            //Single-output
}

int main(int argc, char const *argv[])
{
    struct date today,tomorrow;
    
    printf("Enter today's date(mm dd yyyy):\n");
    scanf("%i %i %i",&today.month,&today.day,&today.year);
    
    if(today.day != NumberOfDays(today))    //非该月最后天
    {
        tomorrow.day = today.day+1;         //天数加一
        tomorrow.month = today.month;       //月不变
        tomorrow.year = today.year;         //年不变
    }
    else if(today.month == 12)              //12月最后一天
    {
        tomorrow.day = 1;
        tomorrow.month = 1;
        tomorrow.year = today.year+1;
    }
    else
    {
        tomorrow.day = 1;
        tomorrow.month = today.month+1;
        tomorrow.year = today.year;
    }
    
    printf("Tomorrow's date is %i-%i-%i.\n",
        tomorrow.year,tomorrow.month,tomorrow.day);
    
    return 0;
}
```
#### 2. 输入结构
1. 没有直接的方式可以一次scanf一个结构;
2. 如果我们打算写一个函数来读入结构；
```C
#include<stdio.h>

struct point
{
    int x;
    int y;
};

void getStruct(struct point p)
{
    scanf("%d",&p.x);
    scanf("%d",&p.y);
    printf("%d, %d",p.x,p.y);
}

void output(struct point p)
{
    printf("%d, %d",p.x,p.y);
}

int main()
{
    struct point y = {0,0};
    getStruct(y);
    output(y);
    
    return 0;
}
```
修正后：
```C
#include<stdio.h>

struct point
{
    int x;
    int y;
};

struct point getStruct(void)
{
    struct point p;
    scanf("%d",&p.x);
    scanf("%d",&p.y);
    printf("%d, %d",p.x,p.y);
    return p;
}

void output(struct point p)
{
    printf("%d, %d",p.x,p.y);
}

int main()
{
    struct point y = {0,0};
    y= getStruct();
    output(y);
    
    return 0;
}
```
#### 3. 结构指针作为参数

#### 4. 指向结构的指针
```C
struct date
{
    int month;
    int day;
    int year;
}myday;

struct date *p = &myday;

(*p).month = 12;    // <==> p->month = 12;
```
用 `->` 运算符表示指针所指的结构变量的成员
```C
#include<stdio.h>

struct point
{
    int x;
    int y;
};

struct point* getStruct(struct point* p)
{
    scanf("%d",&p->x);
    scanf("%d",&p->y);
    printf("%d, %d",p->x,p->y);
    return p;
}

void output(struct point p)     //结构本身
{
    printf("%d, %d",p.x,p.y);
}

void print(const struct point* p)   
{
    printf("%d, %d",p->x,p->y);
}

int main(int argc, char const *argv[])
{
    struct point y = {0,0};
    getStruct(&y);
    output(y);
    output(*getStruct(&y));
    print(getStruct(&y));
    
    getStruct(&y)->x = 0;
    *getStruct(&y) = (struct point){1,2};
    
    return 0;
}
```

[返回标题行](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week11_Course.md#week-11-结构类型)

### 11.2.3 结构中的结构
#### 1. 结构数组
```
struct date dates[100];
struct date dates[] = {{4,5,2005},{2,4,2005}};
```

```C
#include<stdio.h>

struct time
{
    int hour;
    int minute;
    int second;
};

struct time timeUpdate(struct time now)
{
    ++now.second;
    if(now.second == 60)
    {
        now.second = 0;
        ++now.minutes;
        
        if(now.minute == 60)
        {
            now.minute = 0;
            ++now.hour;
            
            if(now.hour == 24)
            {
                now.hour = 0;
            }
        }
    }
}
```
#### 2. 嵌套的结构
```
struct point
{
    int x;
    int y;
};

struct rectangle
{
    struct point pt1;
    struct point pt2;
};

/*
若有变量 

struct rectangle r;

就可以有

r.pt1.x,r.pt1.y;
r.pt2.x,r.pt2.y;

若有变量定义

struct rectangle r,*rp;
rp=&r;

下面四种形式是等价的

r.pt1.x;
rp->pt1.x;
(r.pt1).x;
(rp->pt1).x;

但是不存在 rp->pt1->x，因为 pt1 不是指针
*/
```

#### 3. 结构中的结构的数组
```C
#include<stdio.h>

struct point
{
    int x;
    int y;
};

struct rectangle
{
    struct point p1;
    struct point p2;
};

void printRect(struct rectangle r)
{
    printf("<%d,%d> to <%d,%d>\n", r.p1.x, r.p1.y, r.p2.x, r.p2.y);
}

int main(int argc, const char *argv[])
{
    int i;
    struct rectangle rects[] = 
    {
        {{1,2},{3,4}},
        {{5,6},{7,8}}
    };                  //2 rectangles
    
    for(i=0;i<2;i++)
    {
        printRect(rects[i]);
    }
    
    return 0;
}
```

[返回标题行](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week11_Course.md#week-11-结构类型)

### 11.2.3 联合
