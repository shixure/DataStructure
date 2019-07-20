/*建立10个数据元素的线性表L={1，2，3…10}指定在第2位置插入元素25，然后删除第4个位置上的元素，
分别显示各步骤结果，线性表顺序表示及实现*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef int DataType;

typedef struct
{
	DataType list[MaxSize];
	int size;
} SeqList;

void ListInitiate(SeqList *L)
{
	L->size = 0; /*定义初始数据元素个数*/
}

int creat(SeqList *L)
{
	int i;
	printf("input the datas:");
	for (i = 0; i < 10; i++)
		scanf("%d", &L->list[i]);
	return 1;
}

int ListLength(SeqList L)

{
	return L.size;
}
int ListInsert(SeqList *L, int i, DataType x)
{
	int j;
	if (i < 0 || i > L->size)
	{
		printf("i is error");
		return 0;
	}
	for (j = L->size; j > i - 1; j--)
		L->list[j] = L->list[j - 1]; /*依次后移*/
	L->list[i] = x;					 /*插入x*/
	L->size++;						 /*元素个数加1*/
	return 1;
}

int ListDelete(SeqList *L, int i, DataType *x)
{
	int j;

	if (L->size <= 0)
	{
		printf("顺序表已空，无法删除");
		return 0;
	}
	else
		*x = L->list[i]; /*保存删除的元素到x中*/
	for (j = i + 1; j <= L->size - 1; j++)
		L->list[j - 1] = L->list[j]; /*依次前移*/
	L->size--;						 /*数据元素个数减1*/
	return 1;
}

int ListGet(SeqList L, int i, DataType *x)
{
	if (i < 0 || i > 10)
	{
		printf("参数i不合法! \n");
		return 0;
	}
	else
	{
		*x = L.list[i];
		return 1;
	}
}
int main()
{
	SeqList L;
	ListInitiate(&L);
	DataType a, b;
	creat(&L);
	L.size = 10;
	printf("初始表：");
	for (int i = 0; i < 10; i++)
	{
		ListGet(L, i, &a);
		printf("%d ", a);
	}
	printf("\n");
	ListInsert(&L, 2, 25);
	printf("插入后：");
	for (int i = 0; i < 11; i++)
	{
		ListGet(L, i, &a);
		printf("%d ", a);
	}
	printf("\n");
	ListDelete(&L, 4, &b);
	printf("删除后：");
	for (int i = 0; i < 10; i++)
	{
		ListGet(L, i, &a);
		printf("%d ", a);
	}
}
