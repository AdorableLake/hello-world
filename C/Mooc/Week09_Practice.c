/*
字符串比对（10分）
题目内容：
题目说起来很简单，你会读到两个字符串，每个字符串占据一行，每个字符串的长度均小于10000字符，而且第一个字符串的长度小于第二个字符串的。你的程序要找出第一个字符串在第二个字符串中出现的位置，输出这些位置，如果找不到，则输出-1。

注意，第一个字符的位置是0。

注意，第一个字符串在第二个字符串中的位置可能不止一处。

注意，字符串中可能含有空格。

注意，两个字符串的长度一定大于0。

输入格式:
两个字符串，一行一个。

输出格式：
第一个字符串在第二个字符串中出现的位置，按照从小到到的顺序排列，每个数字后面有一个空格。如果在第二个字符串中找不到第一个字符串，则输出-1。

输入样例：
abba
ababbba abbabbabbabbaacc

输出样例：
8 11 14 17
*/

/*
第一种思路：
1. 定义源码、目标；
2. 利用for循环来写入字节串，但是会缺斤少两；
3. 
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 10000

int main(void)
{
    char src[N]={'\0'};             
    char dst[N]={'\0'};             
    char c;                         
    
    for(int i = 0; getchar() != '\n'; i++) {
        c=getchar();
        src[i]=c;
    }

    for(int j = 0; getchar() != '\n'; j++) {    //用for循环语句更好，但仍然解决不了问题
        c=getchar();
        dst[j]=c;
    }
    printf("%s\n",src);
    printf("%s\n",dst);

    char *p=src, *q=dst;                        //定义指针数组用来
    
    if( !strstr(q, p) ) {
        printf("%d",-1);
    } else {
        while( strstr(q, p) ) {
            q = strstr(q, p);
            printf("%ld ", q-dst);
            q++;
        }
    }
    return 0;
}

/*
解法2:
1. 使用gets()从键盘获取字符串；
2. 但是采用getchar()就会出现缺斤少两的错误；
3. 很迷惑；
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10000

int main()
{
    char src[N]={'\0'}, dst[N]={'\0'};
    
    gets(src);
    gets(dst);
    
    char *p=strstr(dst,src);
    if(p==NULL) {
        printf("-1");
    } else {
        while(p!=NULL) {
            printf("%ld",p-dst);
            if(p-dst!=0) {
                printf(" ");
            }
            p=strstr(++p,src);
        }
    }
    return 0;
}
