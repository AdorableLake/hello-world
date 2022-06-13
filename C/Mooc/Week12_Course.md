# Week 12 链表
## 12.1 可变数组
### 1. 可变数组/Resizeable Array
1. 可增长性/Growable；
2. 可知性/Get the current size；
3. 可访问性/Access to the elements；
```C
//<array.h>
#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef struct {
    int *array;
    int size;
} Array;

Array a;

Array array_create(int init_size);              //创建/初始化
void array_free(Array *a);                      //释放
int array_size(const Array *a);                 //知道现有多少单元
int* array_at(Array *a, int index);             //访问
void array_inflate(Array *a, int more_size);    //让数组增长

#endif

//<array.c>
#include "array.h"
#include<stdio.h>
#include<stdlib.h>

const BLOCK_SIZE = 20;

typedef struct {
    int *array;
    int size;
} Arrary;

Array array_create(int init_size)              //创建/初始化
{
    Array.a;
    a.size = init_size;
    a.array = (int*)malloc(sizeof(int)*a.size);
    return a;
}

void array_free(Array *a)                      //释放
{
    free(a->array);
    a->array = NULL;
    a->size = 0;
}

int array_size(const Array *a)                 //知道现有多少单元
{
    return a->size;
}

int* array_at(Array *a, int index)             //访问并增长
{
    if(index >= a->size) 
    {
        array_inflate(a, (index/BLOCK_SIZE+1)*BLOCK_SIZE - a->size);
        //位于BLOCK区域 * BLOCK的大小 - a指向的size
    }
    return &(a->array[index]);
}

int array_get(const Array *a, int index)
{
    return a->array[index];
}

void array_set(Array *a, int index, int value)
{
    a->array[index] = value;    
}

void array_inflate(Array *a, int more_size)    //让数组增长
{
    int *p = (int*)malloc(sizeof(int)(a->size + more_size));
    int i;
    for(i=0;i<a->size;i++)
    {
        p[i] = a->array[i];
    }
    free(a->array);
    a->array = p;
    a->size += more_size;
}

int main()
{
    Arrary a arrary_create(100);
    printf("%d\n",array_size(&a));
    *array_at(&a,0) = 10;
    printf("%d\n", *array_at(&,0));
    int number;
    int cnt = 0;
    while(1){
        scanf("%d",&number);
        if(number != -1)
        {
            *array_at(&a,cnt++);
        }
        //scanf("%d",array_at(&a,cnt++));
    }
    array_free(&a);
    
    return 0;
}
```
### 2. 可变数组的缺陷
1. 需要时间去拷贝；
2. 以及可能被内存进程拒绝；

[返回标题行](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week12_Course.md#week-12-链表)

## 12.2 链表
### 1. 链表
```C
//<LNode.h>

#ifndef _NODE_H_
#define _NODE_H_

typedef struct LNode 
{
    int value;
    struct LNode *next;
} LNode;

#endif

//<LNode.c>
#include "LNode.h"
#include<stdio.h>
#include<stdlib.h>

typedef struct LNode 
{
    int value;
    struct LNode *next;
} LNode;

int main(int argc, const char *argv[])
{
    LNode * head = NULL;
    int number;
    do {
        scanf("%d", &number);
        if(number != -1) {
            // add to linkedlist
            LNode *p = (int *)malloc(sizeof(LNode));
            p->value = number;
            p->next = NULL;
            
            // find the last
            LNode *last = head;
            if(last) {
                while(last->next) {
                    last = last->next;
                }
                // attach
                last->next = p;
            } else {
                head = p;
            }
        }   
    } while(number != -1)
    
    return 0;
}
```

[返回标题行](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week12_Course.md#week-12-链表)

### 12.2.2 链表的函数
```C
#include "LNode.h"
#include<stdio.h>
#include<stdlib.h>
/*
typedef struct LNode {
    int value;
    struct LNode *next;
} LNode;
*/

typedef struct List {
    LNode* head;
    //LNode* tail;
} List;

void add(List * pList, int number)
{
    // add to linkedlist
    LNode *p = (int *)malloc(sizeof(LNode));
    p->value = number;
    p->next = NULL;
            
    // find the last
    LNode *last = head;
    if(last) {
        while(last->next) {
            last = last->next;
        }
        // attach
        last->next = p;
    } else {
        pList->head = p;
    }
}

int main(int argc, const char *argv[])
{
    List L;
    int number;
    L.head = NULL;
    do {
        scanf("%d", &number);
        if(number != -1) {
            head = add(&L, number);
        }
    } while(number != -1);
    
    return 0;   
}
```

[返回标题行](https://github.com/AdorableLake/hello-world/blob/master/C/Mooc/Week12_Course.md#week-12-链表)
