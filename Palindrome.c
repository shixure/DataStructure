#include <stdio.h>
#include <string.h>
#define MAXLEN 100
#define MaxStackSize 100
typedef char elementType; //�������Ӧ�õ���������elementType

typedef struct
{
    elementType data[MAXLEN];
    int rear;  /*��βָ��*/
    int front; /*��ͷָ��*/
} SeqQueue;

typedef struct
{
    elementType stack[MaxStackSize];
    int top;
} SeqStack;

void dataInitiate(SeqQueue *Q) /*��ʼ��˳��ѭ������Q*/
{
    Q->rear = 0;  /*�����ʼ��βָ���±�ֵ*/
    Q->front = 0; /*�����ʼ��ͷָ���±�ֵ*/
}

int queueNotEmpty(SeqQueue Q)
/*��˳��ѭ������Q�ǿշ񣬷ǿ��򷵻�1�����򷵻�0*/
{
    if (Q.front == Q.rear)
        return 0;
    else
        return 1;
}

int enQueue(SeqQueue *Q, elementType x)
/*������Ԫ��ֵx����˳��ѭ������Q�Ķ�β���ɹ�����1��ʧ�ܷ���0 */
{
    if ((Q->rear+1)%MAXLEN == Q->front)
    {
        return 0;
    }
    else
    {
        Q->data[Q->rear] = x;
        Q->rear = (Q->rear + 1) % MAXLEN;
        return 1;
    }
}
int outQueue(SeqQueue *Q, elementType *d)
/*ɾ��˳��ѭ������Q�Ķ�ͷԪ�ز�����d ���ɹ�����1��ʧ�ܷ���0*/
{
    if (Q->front==Q->rear)
    {
        return 0;
    }
    else
    {
        *d = Q->data[Q->front];
        Q->front = (Q->front + 1) % MAXLEN;
        return 1;
    }    
}
void StackInitiate(SeqStack *S) /*��ʼ��˳���ջS*/
{
    S->top = 0; /*�����ʼջ���±�ֵ*/
}

int StackNotEmpty(SeqStack S)

/*��˳���ջS�ǿշ񣬷ǿ��򷵻�1�����򷵻�0*/
{
    if (S.top <= 0)
        return 0;
    else
        return 1;
}

int StackPush(SeqStack *S, elementType x)

/*������Ԫ��ֵxѹ��˳���ջS����ջ�ɹ��򷵻�1�����򷵻�0 */
{
    if (S->top >= MaxStackSize)
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

int StackPop(SeqStack *S, elementType *d)

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

int StackTop(SeqStack S, elementType *d)

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

int main()
{
    SeqQueue mydata;

    SeqStack myStack;

    char x, y;

    int i, length;
    char str[20];
    dataInitiate(&mydata);

    StackInitiate(&myStack);

    printf("����һ���ַ�����");
    scanf("%s", str);
    length = strlen(str);
    for (i = 0; i < length; i++)
    {
        enQueue(&mydata, str[i]);
        StackPush(&myStack, str[i]);
    }
    while (queueNotEmpty(mydata) == 1 && StackNotEmpty(myStack) == 1)
    {
        if (outQueue(&mydata, &x) == 1 && StackPop(&myStack, &y) == 1 && x != y)
        {
            printf("%s���ǻ���!\n", str);
            break;
        }
    }
    if (queueNotEmpty(mydata) == 0 || StackNotEmpty(myStack) == 0)
    {
        printf("%s�ǻ���!\n", str);
        printf("%d\n", queueNotEmpty(mydata));
        printf("%d\n", StackNotEmpty(myStack));
    }
    getchar();getchar();
}
