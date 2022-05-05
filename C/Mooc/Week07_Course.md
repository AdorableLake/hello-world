# 第7周 数组运算

## 1. 数组运算
### 1.1 在一组给定的数据中，如何找出某个数据是否存在？
```C
#include<stdio.h>
/*
找出Key在数组a中的位置
@param key 要寻找的数字
@param a 要寻找的数组
@param length 数组a的长度
@return 如果找到，返回其在a中的位置；找不到则返回-1
*/
int search(int key, int a[], int length);

int main(void)
{
  int a[] = {2,4,6,7,1,3,5,9,11,23,14,32}; // 数组的集成初始化
  /* use for testing
  {
    int i;
    for ( i=0; i<13; i++ )
    {
      printf("%d\t",a[i]);
    }
    printf("\n");
  }
  */
  int x;
  int loc;
  printf("请输入一个数字：");
  scanf("%d",&x);
  loc=search(x,a,sizeof(a)/sizeof(a[0]));// `sizeof`永远是真正确的
  if( loc != -1)
  {
    printf("%d在第%d个位置上\n",x,loc);
  }
  else
  {
    printf("%d不存在\n",x);
  }
  
  return 0;
}

int search(int key, int a[], int length)
{
  int ret = -1;
  int i;
  for( i=0; i<length; i++ )
  {
    if( a[i] == key )
    {
      ret = i;
      break;
    }
  }
  return ret;
}
```
### 1.2 数组的大小
