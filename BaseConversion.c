#include <stdio.h>

#define MAX 100
typedef int DataType;
typedef struct
{
    DataType stack[MAX];
    int top;
} seqstack;

void StackInitiate(seqstack *S) /*初始化顺序堆栈S*/
{
    S->top = 0; /*定义初始栈顶下标值*/
}
int StackNotEmpty(seqstack S)

/*判顺序堆栈S非空否，非空则返回1，否则返回0*/
{

    if (S.top <= 0)
        return 0;
    else
        return 1;
}
int StackPush(seqstack *S, DataType x)

/*把数据元素值x压入顺序堆栈S，入栈成功则返回1，否则返回0 */

{
    if (S->top >= MAX)
    {
        printf("堆栈已满无法插入! \n");
        return 0;
    }
    else
    {
        S->stack[S->top] = x;
        S->top++;
        return 1;
    }
}
int StackPop(seqstack *S, DataType *d)

/*弹出顺序堆栈S的栈顶数据元素值到参数d ，出栈成功则返回1，否则返回0*/
{
    if (S->top <= 0)
    {
        printf("堆栈已空无数据元素出栈! \n");
        return 0;
    }
    else
    {
        S->top--;
        *d = S->stack[S->top];
        return 1;
    }
}
int StackTop(seqstack S, DataType *d)

/*取顺序堆栈S的当前栈顶数据元素值到参数d ，成功则返回1，否则返回0*/
{
    if (S.top <= 0)
    {
        printf("堆栈已空! \n");
        return 0;
    }
    else
    {
        *d = S.stack[S.top - 1];
        return 1;
    }
}

void conversion(int i)
{
    seqstack S;
    int x = 0;
    StackInitiate(&S);

    while (i > 0)
    {
        x = i % 8;
        StackPush(&S, x);
        i /= 8;
    }

    while (StackNotEmpty(S)) //输出
    {
        StackPop(&S, &x);
        printf("%d", x);
    }
}
int main()
{
    conversion(8);//测试
    getchar();
}