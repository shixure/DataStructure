#include <stdio.h>

#define MAX 100
typedef int DataType;
typedef struct
{
    DataType stack[MAX];
    int top;
} seqstack;

void StackInitiate(seqstack *S) /*��ʼ��˳���ջS*/
{
    S->top = 0; /*�����ʼջ���±�ֵ*/
}
int StackNotEmpty(seqstack S)

/*��˳���ջS�ǿշ񣬷ǿ��򷵻�1�����򷵻�0*/
{

    if (S.top <= 0)
        return 0;
    else
        return 1;
}
int StackPush(seqstack *S, DataType x)

/*������Ԫ��ֵxѹ��˳���ջS����ջ�ɹ��򷵻�1�����򷵻�0 */

{
    if (S->top >= MAX)
    {
        printf("��ջ�����޷�����! \n");
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

/*����˳���ջS��ջ������Ԫ��ֵ������d ����ջ�ɹ��򷵻�1�����򷵻�0*/
{
    if (S->top <= 0)
    {
        printf("��ջ�ѿ�������Ԫ�س�ջ! \n");
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

/*ȡ˳���ջS�ĵ�ǰջ������Ԫ��ֵ������d ���ɹ��򷵻�1�����򷵻�0*/
{
    if (S.top <= 0)
    {
        printf("��ջ�ѿ�! \n");
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

    while (StackNotEmpty(S)) //���
    {
        StackPop(&S, &x);
        printf("%d", x);
    }
}
int main()
{
    conversion(8);//����
    getchar();
}