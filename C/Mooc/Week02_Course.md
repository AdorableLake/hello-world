## 第二周 计算
### 1. 变量
`int`整型变量
```C
#include <stdio.h>

int main()
{
	int a;
	int b;

	printf("请输入两个整数：");
	scanf("%d %d", &a, &b);
	printf("%d + %d = %d\n", a, b, a + b);

	return 0;
}
```

```C
#include <stdio.h>

int main()
{
	const int AMOUNT = 100;
	int price = 0;

	printf("请输入金额（元）：");
	scanf("%d", &price);

	int change = AMOUNT - price;

	printf("找您%d元。\n", change);

	return 0;
}
```
`double`双精度浮点数
```C
#include <stdio.h>

int main()
{
	printf("请分别输入身高的英尺和英寸，"
		"如输入\"5 7\"表示5英尺7英寸：");

	double foot;
	double inch;

	scanf("%lf %lf", &foot, &inch);

	printf("身高是%f米。\n", 
		((foot + inch / 12) * 0.3048));

	return 0;
}
```
### 2. 数据类型
```C
#include <stdio.h>

int main()
{
	int a,b;

	scanf("%d %d", &a, &b);

	double c = (a+b)/2.0;
	
	printf("%d和%d的平均值=%f\n", a, b, c);

	return 0;
}
```
### 3. 表达式
计算时间差

```C

```
