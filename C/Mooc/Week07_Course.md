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
  // 数组作为函数的参数是，不能在`[]`给出数组的大小
  // 同时，也不能再利用`sizeof`来计算数组大小
  /* use for testing
  {
    int i;
    for ( i=0; i<13; i++ )// 常见错误：循环条件<=数组长度
    {
      printf("%d\t",a[i]);
    }
    printf("\n");
  }
  int b[]=a; ->❌
  若想复制到另一个数组中，只能使用遍历
  */
  int x;
  int loc;
  printf("请输入一个数字：");
  scanf("%d",&x);
  loc=search(x,a,sizeof(a)/sizeof(a[0]));// `sizeof`永远是正确的
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
### 1.2 数组例子
#### 1.2.1 判断素数
```C

```
#### 1.2.2 判断是否能被已知的且<x的素数整除
```C
#include<stdio.h>
int main(void)
{
  const int number = 100;
  int prime[number] = [2];
  int count = 1;
  int i = 3;
  while( count < number )
  {
    if ( isPrime(i, prime, count))
    {
      prime[count++] = i; // 先赋值再将count变量+1
    }
    i++;
  }
  for( i=0; i<number; i++ )
  {
    printf("%d",prime[i]);
    if( (i+5)%5 )
    {
      printf("\t");
    }
    else
    {
      printf("\n");
    }
  }
  return 0;
}

int isPrime(int x, int knownPrimes[], int numberOfKnownPrimes)
{
  int ret = 1;
  int i;
  for( i=0; i<numberOfKnownPrimes; i++ )
  {
    if（ x % knownPrimes[i] == 0）
    {
      ret =0;
      break;
    }
  }
  return ret;
}
```
#### 1.2.3 构造素数表
欲构造n以内的素数表
1. 令x为2；
2. 将2x、3x、4x直至ax<n的数标记为非素数
3. 令x为
