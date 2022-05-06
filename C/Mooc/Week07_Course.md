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
欲构造n以内的素数表（算法）
1. 令x为2；
2. 将2x、3x、4x直至ax<n的数标记为非素数；
3. 令x为下一个没有被标记为非素数的数，重复2；
4. 直到所有的数都已经尝试完毕；


构造n以内的素数表（伪代码）
1. 开辟`prime[n]`，初始化其所有的元素为1，`prime[x]`为1表示x是素数；
2. 令x=2；
3. 如果x是素数，则对于`(i=2;x*i<n;i++)`令`prime[i*x]=0`；
4. 令`x++`，如果`x<n`重复3，否则结束；


构造n以内的素数表（代码）
```C
#include<stdio.h>
int main()
{
  const int maxNumber = 25;
  int isPrime[maxNumber];
  int i;
  int x;
  for( i=0; i<maxnumber; i++ )
  {
    isPrime[i] = 1;
  }
  for( x=2; x<maxNumber; x++ )
  {
    if( isPrime[x] )
    {
      for( i=2; i*x<maxNumber; i++ )
      {
        isPrime[i*x] = 0;
      }
    }
  }
  for( i=2; i<maxNumber; i++ )
  {
    if( isPrime[i])
    {
      printf("%d\t",i);
    }
  }
  printf("\n");
  
  return 0;
}
// 算法不一定和人的思考方式相同
```
## 2. 搜索
### 2.1 线性搜索
最简单的方式：遍历
```C
#include<stdio.h>

int search(int key, int a[], int len)
{
  int ret = -1;
  for( int i=0; i<len; i++ )
  {
    if( key == a[i])
    {
      ret = i; // "single output"
      break;
    }
  }
  return ret;
}

int main()
{
  int a[] = {1,3,2,5,12,14,23,6,9,45};
  int r = search(12, a, sizeof(a)/sizeof(a[0]));
  printf("%d\n",r);
  
  return 0;
}
```
### 2.2 搜索的例子
```C
#include<stdio.h>

int amount[] = {1,5,10,25,50};
char *name[] = {"penny","nickel","dime","quarter","half-dollar"};

int search(int key, int a[], int len)
{
  int ret = -1;
  for( int i=0; i<len; i++ )
  {
    if( key == a[i])
    {
      ret = i; // "single output"
      break;
    }
  }
  return ret;
}

int main()
{
  int k = 10;
  int r = search(k, amount, sizeof(amount)/sizeof(amount[0]));
  if( r > -1 )
  {
    printf("%s\n",name[r]);
  }
  
  return 0;
}
// 以上做法对`cache`不友好
```
浅改一下👇
```C
#include<stdio.h>

int amount[] = {1,5,10,25,50};
char *name[] = {"penny","nickel","dime","quarter","half-dollar"};

struct{
  int aount;
  char *name;
} coins[] = {
  {1,"penny"},
  {5,"nickel",
  {10,"dime"}},
  {25,"quarter"},
  {50,"half-dollar"}
};
// 利用`struct`语句构建搜索，对`cache`更友好

int search(int key, int a[], int len)
{
  int ret = -1;
  for( int i=0; i<len; i++ )
  {
    if( key == a[i])
    {
      ret = i; // "single output"
      break;
    }
  }
  return ret;
}

int main()
{
  int k = 10;
  for( int i=0; i<sizeof(coins)/sizeof(coins[0]); i++ )
  {
    if( k == coins[i].amount)
    {
      printf("%s\n",coins[i].name);
      break;
    }
  }

  return 0;
}
```
### 2.3 二分搜索
```C
#include<stdio.h>

int search(int key, int a[], int len)
{
  int ret = -1;
  int left = 0;
  int right = len-1;
  while(right>left)
  {
    int mid = (left+right)/2;
    if( a[mid] == k )
    {
      ret =mid;
      break;
    }
    else if( a[mid]>k )
    {
      right = mid-1;
    }
    else
    {
      left = mid+1;
    }
  }
  return ret;
}

int main()
{
  int a[] = {1,3,2,5,12,14,23,6,9,45};
  int r = search(12, a, sizeof(a)/sizeof(a[0]));
  printf("%d\n",r);
  
  return 0;
}
```
## 3. 排序初步
```C
#include<stdio.h>

int max(int a[], int len)
{
  int maxid = 0;
  for( int i=1; i<len; i++ )
  {
    if( a[i] > a[maxid])
    {
      maxid = i;
    }
  }
  return maxid;
}

int main()
{
  int a[] = {2,45,6,12,87,34,90,24,23,11,65};
  int len = sizeof(a)/sizeof(a[0]);
  
  // 选择排序法
  for( int i=len-1; i>0; i-- )
  {
    int maxid = max(a, i+1);
    //swap a[maxid], a[len-1]
    int t = a[maxid];
    a[maxid] = a[i];
    a[i] = t;
  }
  
  for( int i=0; i<len; i++ )
  {
    printf("%d ",a[i]);
  }
  
  return 0;
}
```
