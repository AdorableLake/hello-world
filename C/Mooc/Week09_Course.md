# Week09: 指针与字符串
## 9.1 指针的使用
### 9.1.1
#### 1. 指针应用场景一
交换两个变量的值
```C
#include<stdio.h>

void swap(int *pa, int *pb);

int main(void)
{
    int a=5,b=6;
    swap(&a,&b);
    printf("a=%d,b=%d\n",a,b);
    
    return 0;
}

void swap(int *pa, int *pb)
{
    int t= *pa;
    *pa=*pb;
    *pb=t;
}
```
#### 2. 指针应用场景二
A.
1. 函数返回多个值，某些值就只能通过指针返回；
2. 传入的参数实际上是需要保存带回的结果的变量；
```C
#include<stdio.h>

void minmax(int a[], int len, int *max, int *min);

int main(void)
{
    int a[]={1,2,3,4,5,6,7,8,9,12,13,14,16,17,21,23,55,};
    int min,max;
    minmax(a,sizeof(a)/sizeof(a[0]),&max,&min);
    printf("min=%d,max=%d\n",min,max);
    
    return 0;
}

void minmax(int a[], int len, int *max, int *min)
{
    *min = *max = a[0];
    for(int i=1; i<len;i++)
    {
        if(a[i] < *min)
        {
            *min = a[i];
        }
        if(a[i] > *max)
        {
            *max = a[i];
        }
    }
}
```
B.
1. 函数返回运算的状态，结果通过指针返回
2. 常用套路是让函数返回特殊的，不属于有效范围内的值来表示出错；
3. 但是当任何数值都是有效的可能结果时，就得分开返回；

```C
#include<stdio.h>
/*
return: 除法成功返回1；否则返回0
*/
int divide(int a, int b, int *result)
{
    int res = 1;
    if(b==0) res =0;
    else *result = a/b;
    return res;
}

int main(void)
{
    int a = 5;
    int b = 2;
    int c;
    if (divide(a,b,&c) ) printf("%d/%d=%d\n",a,b,c);
    return 0;
}
```
#### 3. 常见错误
1. 定义了指针变量，但没有指向任何变量，就开始使用指针；
e.g(错误例子)
```C
#include<stdio.h>

void f(int *p)
{
    printf("p=%p\n",p);
    printf("*p=%d\n",*p);
    *p = 26;
}

void g(int k)
{
    printf("k=%d\n",k);
}

int main(void)
{
    int i = 6;
    int *p=0;
    int k;
    k = 12;
    *p = 12;
    printf("&i=%p\n",&i);
    f(&i);
    g(i);
    
    return 0;
}
```

[返回标题行](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week09_Course.md#week09-指针与字符串)

### 9.1.2 指针与数组
#### 1. 传入函数的数组
```C
int isPrime(int x, int knowPrimes[], int NumberOfKnownPrimes)
{
    int ret = 1;
    int i;
    for(int i=0;i<NumberOfKnownPrimes;i++)
    {
        if(x%knownPrimes[i]==0)
        {
            ret=0;
            break;
        }
    }
    return ret;
}
```

e.g
```C
#include<stdio.h>

void minmax(int a[], int len, int *max, int *min);

int main(void)
{
    int a[]={1,2,3,4,5,6,7,8,9,12,13,14,16,17,21,23,55,};
    int min,max;
    printf("main sizeof(a)=%lu\n",sizeof(a));
    minmax(a,sizeof(a)/sizeof(a[0]),&max,&min);
    printf("min=%d,max=%d\n",min,max);
    
    return 0;
}

void minmax(int a[], int len, int *max, int *min)
{
    printf("minmax sizeof(a)=%lu\n",sizeof(a));
    *min = *max = a[0];
    for(int i=1; i<len;i++)
    {
        if(a[i] < *min)
            *min = a[i];
        }
        if(a[i] > *max)
        {
            *max = a[i];
        }
    }
}
```
### 2. 数组变量是特殊的指针
注：这一部分和入门的第八周视频一致 👉[_Week08 Note_](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week08_Course.md#135-数组变量是特殊的指针)

1. 数组变量本身表达地址，所以：
```
1. int a[10]; int *p=a;`// 无须使用`&` 取地址；
2. 但是数组的单元表达的是变量，需要用`&`取地址；
3. a == &a[0]
```
2. `[]`运算符可以对数组做，也可以对指针做：
```
p[0] <==> a[0]//指针变量
```
3. `*`运算符既可以对指针做，也可以对数组做；
```
例如`*a=25`；
```
4. 数组变量其实是const(常量)的指针，因此不能被赋值；
```
int a[] <==> int * const a=`
```
例子
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
  printf("*a=%d\n",*a);
  int b[] --> int * const b;
  int *q = a;
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

[返回标题行](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week09_Course.md#week09-指针与字符串)

### 9.1.3 指针与const（仅适用于C99标准）
#### 1. 指针是const（常量）
1. 表示一旦得到了某个变量的地址，不能再指向其他变量
```
int * const q = &i; // q 是const
*q = 26;    //OK
q++;        //ERROR
```
#### 2. 所指是const
1. 表示不能通过这个指针去修改那个变量
```
const int *p = &i;
*p = 26;            //ERROR: (*p)->const
i=26;               //OK
p=&j;               //OK
```

#### 3. 啥意思？
```
int i;
const int *p1 = &i; 
int const* p2 = &i;
int *const p3 = &i;
```
通过const在`*`的位置来判断到底哪个是常量

#### 4. 转换
1. 总是可以吧一个非const的值转换成const的值
```C
void f(const int * x);
int a = 15;
f(&a);      //OK
const int b = a;

f(&b);      //OK
b = a+1;    //ERROR!
```
2. 当要传递的参数的类型比地址大的时候，常用手段如下：

既能用比较少的字节数传递值给参数，又能避免函数对外面的变量的修改；

#### 5. const数组
1. `const int a[]={1,2,3,4,5,6,};`
```
意思是数组a[]内部的元素也是常量值，无法再次被改变;
因此必须通过初始化进行赋值；
```
#### 6. 保护数组值
1. 因为把数组传入函数是传递的是地址，所以在那个函数内部可以修改数组的值；
2。为了保护数组不被函数破环，可以设置参数为const
```
int sum(const int a[],int length);
```

[返回标题行](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week09_Course.md#week09-指针与字符串)

## 9.2 指针运算
### 9.2.1 
#### 1. 
```C
#include<stdio.h>

int main(void)
{
    char ac[] = {0,1,2,3,4,5,6,7,8,9,};
    char *p = ac;                   //<==> *p = &ac[n]; <==> *p = ac[n];
    printf("p = %p\n",p);
    printf("p+1 = %p\n",p+1);       //+1*sizeof(char)
    
    int ai[] = {0,1,2,3,4,5,6,7,8,9,};
    int *q = ai;
    printf("q = %p\n",q);
    printf("q+1 = %p\n",q+1);       //+1*sizeof(int)
    
    double ad[] = {0,1,2,3,4,5,6,7,8,9,}; 
    double *o = ad;
    printf("o = %p\n",o);
    printf("o+1 = %p\n",o+1);       //+1*sizeof(double)
    
    float af[] = {0,1,2,3,4,5,6,7,8,9,}; 
    float *r = af;
    printf("r = %p\n",r);
    printf("r+1 = %p\n",r+1);       //+1*sizeof(float)
    
    return 0;
}
```
输出结果
```
p = 0x7fff3ec24b56
p+1 = 0x7fff3ec24b57
p+1-p=1;->sizeof(char)=1;

q = 0x7fff3ec24b20
q+1 = 0x7fff3ec24b24
q+1-q=4;->sizeof(int)=4;

o = 0x7fff3ec24ad0
o+1 = 0x7fff3ec24ad8
o+1-o=8;->sizeof(double)=8;

r = 0x7fff3ec24aa0
r+1 = 0x7fff3ec24aa4
r+1-r=4;->sizeof(float)=4;
```

#### 2. 指针可以进行的运算
算术运算
```
给指针加减一个整数 -> +/+=/-/-=
递增递减 -> ++/--
```
#### 3. `*p++`
1. 取出p所指的那个数据，结束后再把p移动到下一个位置去；
2. `++` 的优先级 > `*`的优先级；
3. 常用于数组类的连续空间操作；
4. 在某些CPU上，可直接被翻译为汇编指令；

```C
#include<stdio.h>

int main(void)
{
    char ac[] = {0,1,2,3,4,5,6,7,8,9,};
    char *p = ac;                   //<==> *p = &ac[n]; <==> *p = ac[n];
    int i;
    
    for(i=0;i<sizeof(ac)/sizeof(ac[0]);i++)
    {
        printf("%d\n",ac[i]);
    }
    
    while(*p != -1)
    {
        printf("%d\n",*p++);
    }
    return 0;
}
```
详细解释在 [Week10](url) 中字符串部分详解

#### 4. 指针比较
1. `</<=/==/>/>=/!=`都可以用于指针运算中；
2. 用于比较指针在内存中的地址大小；
3. 数组单元的地址一定是线性递增的；

#### 5. 0地址
1. 内存中含有0地址，但0地址不要随便触碰；
2. 编写的程序中的指针不应该具有0值； 
3. 0地址的用处：
```
返回的指针是无效的；
指针没有被真正初始化（先初始化为0）；
```
4. `NULL` 是一个预定定义的符号，表示0地址；（有的编译器不愿意用0表示0地址）

#### 6. 指针的类型
1. 无论指向什么类型，所有的指针的大小都是一样的，因为都是地址；
2. 但是指向不同类型的指针的是不能直接互相赋值的；
```
为了避免用错指针
```

#### 7. 指针的类型转换
1. void* 表示不知道指向何物的指针
```
计算时与 char* 相同但不相通
```
2. 指针也可以转换类型
```
int *p = &i;
void *q = (void*)p;
//这并没有改变p所指的变量的类型，而是让程序员不再当p是int型，而是void型
```

#### 8. 用指针来做什么
1. 需要传入较大的数据使用参数；
2. 传入数组后对数组做操作；
3. 函数返回不止一个结果；
4. 需要用函数来修改不止一个变量；
5. 动态申请内存；

[返回标题行](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week09_Course.md#week09-指针与字符串)

### 9.2.2 动态内存分配
#### 1. 输入数据
```
int *a = (int*)malloc(n*sizeof(int));
```
动态内存分配
```C
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int number;
    int* a;
    int i;
    printf("Enter the number:\n");
    scanf("%d",&number);
    //int a[number];                //C99之后的做法
    a=(int*)malloc(number*sizeof(int));
    
    for(i=0; i<number; i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(i=number-1;i>=0;i--)
    {
        printf("%d ",a[i]);
    }
    free(a);
    return 0;
}
```

#### 2. malloc
```
#include<stdlib.h>
void*malloc(size_t size);
```
1. 向malloc申请的空间的大小是以字节为单位的；
2. 返回的结果是 `void*` ，需要转换为自己需要的类型；
```
(int*)malloc(n*sizeof(int))
```

#### 3. 没空间了？
```C
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    void *p;
    int cnt = 0;
    while( (p=malloc(100*1024*1024)) )           //每次申请100M的空间
    {
        cnt++;
    }
    printf("Allocate the memory space: %d00MB\n",cnt);
    
    return 0;
}
```

#### 4. free()
1. 申请来的空间还给系统

```C
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i;
    void *p = 0;
    int cnt = 0;
    //p=malloc(100*1024*1024);
    //p++;
    free(p);
    
    return 0;
}
```

#### 5. 常见问题
1. 申请了忘记free -> 长时间运行内存逐渐下降；
2. free过了再次free -> 崩溃
3. 地址变过了，free了原地址

[返回标题行](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week09_Course.md#week09-指针与字符串)

## 9.3 字符串操作
### 9.3.1 单字符输入输出
1. putchar
```
int putchar(int c);
向标准输出写一个字符；
返回写了几个字符，EOF(-1)表示写失败；
```
2. getchar
```
int getchar(void);
从标准输入读入一个字符；
返回类型是int，是为了返回EOF(-1);
windows: control z;
unix: control d
```
```C
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int ch;
    
    while( (ch = getchar())!=EOF )
    {
        putchar(ch);
    }
    
    printf("EOF\n");
    
    return 0;
}
```

### 9.3.2 字符串数组
#### 1. 字符串数组
```
char **a; // a 是一个指针，指向另一个指针，另一个指针指向一个字符串

char a[][];
```
#### 2. 程序参数
```
int main() <==> int main(int argc, char const *argv[])
argv[0]是命令本身，当使用Unix的符号链接时，反映符号链接的名字；
```

```C
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int i;
    for(i=0;i<argc;i++)
    {
        printf("%d: %s\n",i,argv[i]);
    }
    return 0;
}
```

## 9.4 字符串函数的实现
### 9.4.1 strlen
1. `strlen: size_t strlen(const char *s); `//const 保证 strlen 不会修改字符串
```C
#include<stdio.h>
#include<string.h>

size_t mylen(const char *s)
{
    int idx=0;
    while(s[idx] != '0')
    {
        idx++;
    }
    return cnt;
}
```
### 9.4.2 strcmp
1. `strcmp: int strcmp(const char *s1,const char *s2);`
```C
#include<stdio.h>
#include<string.h>

int mycmp(const char* s1, const char *s2)
{
    while(*s1 == *s2 && *s1 != '\0')
    {
        s1++;
        s2++;
    }
    return *s1-*s2;
}

int main(int argc, char const *argv[])
{
    char s1[] = "abc";
    char s2[] = "abc";
    printf("%d\n",strcmp(s1,s2));
  
    return 0;
}

/*
    int idx=0;
    while(s1[idx] == s2[idx] && s1[idx] != '\0')
    {
        /*
        if(s1[idx] != s2[idx])
        {
            break;
        }
        else if(s1[idx] == '\0')
        {
            break;
        }
        */
        idx++;
    }
*/    
```

### 9.4.3 strcpy

`
strcpy: char *strcpy(char *restrict dst, const char *restrict src); 
把src的字符串拷贝到dst，并返回dst；
stc是原，dst是目的；
char *dst = (char*)malloc(strlen(src)+1); -> +1 不要忘记
strcpy(dst, scr);
`
```C
#include<stdio.h>
#include<string.h>

char* mycpy(char* dst, const char* src)
{
    /*数组版本
    int idx = 0;
    while(src[idx])
    {
        dst[idx] = src[idx];
        idx++;
    }
    dst[idx]='\0';
    return dst;
    */
    
    char* ret=dst;
    while(*dst++ = *src++);
    *dst='\0';
    return ret;
    
}

int main(int argc, char const *argv[])
{
    char s1[] = "abc";
    char s2[] = "abc";
    strcpy(s1,s2);
  
    return 0;
}
```
### 9.4.4 字符串中找字符
```
char *strchr(const char *s, int c) -> 从左到右查找c在字符串中第一次出现的位置，返回的是指针；
char *strrchr(const char *s, int c)->从右到左查找c在字符串中第一次出现的位置，返回的是指针；
返回NUll表示没有找到；
```
如何寻找第二个？
```C
#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char s[] = "hello";
    
    char *p=strchr(s,'l');
    p=strchr(p+1,'l')
    
    printf("%s\n",p);
  
    return 0;
}
```
将第一个字符串复制到另一个字符串
```C
#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char s[] = "hello";
    
    char *p=strchr(s,'l');
    char *q=(char*)malloc(strlen(p)+1);
    strcpy(q,p);

    printf("%s\n",q);
    free(q);
  
    return 0;
}
```
找l前面的字符串
```C
#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char s[] = "hello";
    
    char *p = strchr(s,'l');
    char c = *p;
    *p = '\0';
    char *q = (char*)malloc(strlen(s)+1);
    strcpy(q,s);

    printf("%s\n",q);
    free(q);
  
    return 0;
}
```
字符串中找字符串
```
char * strstr(const char *s1, const char *s2);
char * strcasestr(const char *s1, const char *s2); -> 忽略大小写寻找
```

补充：strcat
```C
#include<stdio.h>
#include<string.h>

char * mystrcat(char* s1,char* s2)
{
    char * str = s1 + strlen(s1);
    strcpy(str,s2);
    return s1;
}

int main(int argc, char const *argv[])
{
    char s1[] = "abc";
    char s2[] = "abc";
    printf("%d\n",strcat(s1,s2));
  
    return 0;
}
```
