/*依次输入数据元素1,2,3,4,5,然后判断栈是否为空,显示栈顶元素,出栈并在屏幕上显示出栈的数据元素*/
#include <malloc.h>
#include <stdio.h> /*该文件包含pringtf()等函数*/
#include <stdlib.h>
#define MaxStackSize 100 /*定义MaxSize为100*/
typedef int DataType;	/*定义DataType为int*/
typedef struct
{
	DataType stack[MaxStackSize];
	int top;
} SeqStack;

void StackInitiate(SeqStack *S) /*初始化顺序堆栈S*/
{
	S->top = -1; /*定义初始栈顶下标值*/
}

int StackNotEmpty(SeqStack S)
/*判顺序堆栈S非空否，非空则返回1，否则返回0*/
{
	if (S.top != -1)
		return 1;
	else
		return 0;
}

int StackPush(SeqStack *S, DataType x)

/*把数据元素值x压入顺序堆栈S，入栈成功则返回1，否则返回0 */
{
	if (S->top == MaxStackSize - 1)
	{
		printf("堆栈已满无法插入! \n");
		return 0;
	}
	else
	{
		S->top++;
		S->stack[S->top] = x;

		return 1;
	}
}

int StackPop(SeqStack *S, DataType *d)

/*弹出顺序堆栈S的栈顶数据元素值到参数d ，出栈成功则返回1，否则返回0*/
{
	if (S->top == -1)
	{
		printf("堆栈已空无数据元素出栈! \n");
		return 0;
	}
	else
	{
		*d = S->stack[S->top];
		S->top--;

		return 1;
	}
}

int StackTop(SeqStack S, DataType *d)
/*取顺序堆栈S的当前栈顶数据元素值到参数d ，成功则返回1，否则返回0*/
{
	if (S.top == -1)
	{
		printf("堆栈已空! \n");
		return 0;
	}
	else
	{
		*d = S.stack[S.top];
		return 1;
	}
}

int main()
{
	SeqStack S;
	StackInitiate(&S);
	int x, i, n, d;
	int a;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &x);
		StackPush(&S, x);
	}
	n = StackNotEmpty(S);
	if (n = 1)
	{
		printf("栈非空\n");
		StackTop(S, &d);
		printf("栈顶元素：%d\n", d);
	}
	else
		printf("栈为空\n");
	printf("出栈：");
	for (i = 0; i < 5; i++)
	{
		StackPop(&S, &d);
		printf("%d ", d);
	}
}
