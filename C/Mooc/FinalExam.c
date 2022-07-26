/*
# 1. 最小包围矩形
## 题目内容：

给定一组二维坐标，表示直角坐标系内的一个多边形的连续的顶点的坐标序列。计算能包围这个多边形的平行于坐标轴的最小矩形，输出它的左下角和右上角的坐标。

## 输入格式:

第一行是一个正整数n表示顶点的数量，第二行是n组整数，依次表示每个顶点坐标的x和y值。

## 输出格式：

四个整数，依次表示所计算的矩形的左下角的坐标的x、y值和右上角坐标的x、y值。输出最后带有回车换行。

## 输入样例：
```
5

1 1 1 4 3 7 4 4 4 1
```

## 输出样例：
```
1 1 4 7
```
## 解答：

```C
*/

#include<stdio.h>

typedef struct Window {
    int x;
    int y;
} Win;

int main()
{
    int n, max_x, max_y, min_x, min_y;
    scanf("%d\n",&n);
    Win *w;
    w=(Win*)malloc(n*sizeof(Win));
 
    for(int i=0; i<n; i++) {
        scanf("%d %d", &w[i].x, &w[i].y);
    }
    min_x = max_x = w[0].x;
    min_y = max_y = w[0].y;

    for(int j=1; j<n; j++) {
        if(min_x>w[j].x) min_x=w[j].x;
        if(max_x<w[j].x) max_x=w[j].x;
        if(min_y>w[j].y) min_y=w[j].y;
        if(max_y<w[j].y) max_y=w[j].y;
    }
  
    printf("%d %d %d %d\n", min_x, min_y, max_x, max_y);
    free(w);
    return 0;
}
// ```
/*
# 2. 分数比较 
## 题目内容：

本题要求编写程序，比较两个分数的大小。

## 输入格式:

输入在一行中按照“a1/b1 a2/b2”的格式给出两个分数形式的有理数，其中分子和分母全是int类型范围内的正整数。

## 输出格式：

在一行中按照“a1/b1 关系符 a2/b2”的格式输出两个有理数的关系。其中“>”表示“大于”，“<”表示“小于”，“=”表示“等于”。

*注意在关系符前后各有一个空格。

## 输入样例：
```
1/2 3/4
```
## 输出样例：
```
1/2 < 3/4
```
## 解答
```C
*/
#include<stdio.h>
int main()
{
    int a1, b1, a2, b2;
    scanf("%d/%d %d/%d\n", &a1, &b1, &a2, &b2);
    if( b1 == 0 || b2 == 0 ) printf("Error!\n");
    else if( a1*b2 - b1*a2 > 0 ) printf("%d/%d > %d/%d\n", a1, b1, a2, b2);
    else if( a1*b2 - b1*a2 == 0 ) printf("%d/%d = %d/%d\n", a1, b1, a2, b2);
    else if( a1*b2 - b1*a2 < 0 ) printf("%d/%d < %d/%d\n", a1, b1, a2, b2);
    return 0;
}
// ```
