# Week15 File/文件
## 15.1 文件
### 15.1.1 格式化输入输出
```C
printf("%[flags][width][.prec][hlL]type");

scanf("%[flag]type");
```
printf:

| Flag  | Meaning | width/.prec | Meaning | hlL/类型修饰 | Meaning | hlL/类型修饰 | Meaning |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| - | 左对齐 | number | 最小字符数 | hh | 单个字节 | h | short |
| + | 在前面放+或- | * | 下一个参数是字符数 | l | long |
| (space) | 正数留空 | .number | 小数点后的位数 | ll | long long |
| 0 | 0填充 | .* | 下一个参数是小数点后的位数 | L | long double |

scanf:

| flag | Meaning | type | How | type | How |
| :---: | :---: | :---: | :---: | :---: | :---: |
| * | 跳过 | d | int | s | string |
| (number) | 最大字符数 | i | 整数，十六进制/八进制 | `[...]` | 所允许的字符 |
| hh | char | u | unsigned int | p | 指针 |
| h | short | o | 八进制 |
| l | long, double | x | 十六进制 |
| ll | long long | a,e,f,g | float | 
| L | long double | c | char |

`[^.]`

### 15.1.2 文件输入输出
1. 打开文件的标准方式
```
//FILE
FILE* fopen(const char * restrict path, const char * restrict mode);
int fclose(FILE *stream);
fscanf(FILE*,...);
fprintf(FILE*,...);
```
