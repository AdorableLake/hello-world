/*
逆序输出（10分）
题目内容：
你的程序会读入一系列的正整数，预先不知道正整数的数量，一旦读到-1，就表示输入结束。然后，按照和输入相反的顺序输出所读到的数字，不包括最后标识结束的-1。

输入格式:
一系列正整数，输入-1表示结束，-1不是输入的数据的一部分。

输出格式：
按照与输入相反的顺序输出所有的整数，每个整数后面跟一个空格以与后面的整数区分，最后的整数后面也有空格。

输入样例：
1 2 3 4 -1

输出样例：
4 3 2 1 
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXN 10000

int main()
{
    int n;
    int i=0;
    int src[]={0,};
    
    while( n != -1 ) {
        scanf("%d ",&n);
        src[i]=n;
        i++;
    }
    
    for(int j=i-1; j>=0; j--) {
        printf("%d ",src[j]);
    }
   
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LNode {
    int data;
    struct LNode *next;    
} LNode, *linklist;

void tailInsert(LNode);
void reverse(LNode L);
void Print(LNode L);

int main()
{
    LNode L,P;
    tailInsert(L);
    P=reverse(L);   
    Print(P);

    return 0;
}

void tailInsert(LNode &L)            //尾插法建立单链表
{
    int x;
    L=(int*)malloc(sizeof(LNode));
    LNode *s, *r=L;
    scanf("%d",&x);
    while(x!=-1) {                      //当输入为-1时，停止输入
        s=(LNode*)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        scanf("%d",&x);
    }
    r->next=NULL;
    return L;
}

void reverse(LNode L)
{
    LNode P = L->next, P0 = L, P1 = P->next;
    LNode Ph = L;
    Ph->next = NULL;
    while( P1 != NULL ) {
        P->next = P0;
        P0 = P;
        P = P1;
        P1 = P->next;
    }
    L = P0;
    free(P);
    return L;
}

void Print(LNode L)
{
    LNode P;
    for( P = L; P != NULL; P = P->next) {
        printf("%d ", P->data);
    }
}

#include <stdio.h>
#include <stdlib.h>
 

typedef struct LNode {
	int data;
	struct LNode *next;
} LNode, *List;
 
List ReadInput();       /* 输入 */ 
List Sort(List L);      /* 逆序 */ 
void Print(List L);     /* 输出 */ 
 
int main()
{
	List L,P;
	L = ReadInput();
	P = Sort(L);
	Print(P);
	return 0;		
}
 
List ReadInput()
{
	List P,Q,t;
	P = (List)malloc(sizeof(LNode));
	Q = P;
	for(;;) {
		scanf("%d", &Q->data);
		t = Q;
		Q = (List)malloc(sizeof(LNode));
		t->next = Q;
		if(t->data == -1)
		{
			t->next = NULL; 
			free(Q);
			break;
		}
	}
	return P;
 } 
 
List Sort(List L)
{
	List P=L->next,P0=L,P1=P->next,t;  /* P0当前处理的上一个结点，P1当前处理的下一个结点 */ 
	List Pt = L;
	Pt->next = NULL;                    /* 头结点指向空 */ 
	for(; P1!=NULL; )
	{
		P->next = P0;                   /* 指向前驱 */     
		P0 = P;                         /* 将当前结点赋给上一个结点 */
		P = P1;                         /* 将下一个结点赋给当前结点 */
		P1 = P->next;                   /* P重新指向下一个结点P */ 
	}
	L = P0;   
	free(P);
	return L;
}
 
void Print(List L)
{
	List P;
	for(P=L;P!=NULL;P=P->next)
		printf("%d ",P->data);
}
