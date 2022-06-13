# Week 12 链表
## 12.1 可变数组
### 12.1.1 
#### 1. 可变数组/Resizeable Array
1. 可增长性/Growable；
2. 可知性/Get the current size；
3. 可访问性/Access to the elements；
```
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

Arrary array_crete(int init_size)
{
    Array.a;
    a.size = init_size;
    a.array = (int*)malloc(sizeof(int)*a.size);
}

Array array_create(int init_size);              //创建/初始化
void array_free(Array *a);                      //释放
int array_size(const Array *a);                 //知道现有多少单元
int* array_at(Array *a, int index);             //访问
void array_inflate(Array *a, int more_size);    //让数组增长

```
