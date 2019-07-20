#include <stdio.h>
#include <string.h>
#define MAXLEN 100
#define MaxStackSize 100
typedef char elementType; //定义具体应用的数据类型elementType

typedef struct
{
    elementType data[MAXLEN];
    int rear;  /*队尾指针*/
    int front; /*队头指针*/
} SeqQueue;

typedef struct
{
    elementType stack[MaxStackSize];
    int top;
} SeqStack;

void dataInitiate(SeqQueue *Q) /*初始化顺序循环队列Q*/
{
    Q->rear = 0;  /*定义初始队尾指针下标值*/
    Q->front = 0; /*定义初始队头指针下标值*/
}

int queueNotEmpty(SeqQueue Q)
/*判顺序循环队列Q非空否，非空则返回1，否则返回0*/
{
    if (Q.front == Q.rear)
        return 0;
    else
        return 1;
}

int enQueue(SeqQueue *Q, elementType x)
/*把数据元素值x插入顺序循环队列Q的队尾，成功返回1，失败返回0 */
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
/*删除顺序循环队列Q的队头元素并赋给d ，成功返回1，失败返回0*/
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
void StackInitiate(SeqStack *S) /*初始化顺序堆栈S*/
{
    S->top = 0; /*定义初始栈顶下标值*/
}

int StackNotEmpty(SeqStack S)

/*判顺序堆栈S非空否，非空则返回1，否则返回0*/
{
    if (S.top <= 0)
        return 0;
    else
        return 1;
}

int StackPush(SeqStack *S, elementType x)

/*把数据元素值x压入顺序堆栈S，入栈成功则返回1，否则返回0 */
{
    if (S->top >= MaxStackSize)
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

int StackPop(SeqStack *S, elementType *d)

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

int StackTop(SeqStack S, elementType *d)

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

int main()
{
    SeqQueue mydata;

    SeqStack myStack;

    char x, y;

    int i, length;
    char str[20];
    dataInitiate(&mydata);

    StackInitiate(&myStack);

    printf("输入一个字符串：");
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
            printf("%s不是回文!\n", str);
            break;
        }
    }
    if (queueNotEmpty(mydata) == 0 || StackNotEmpty(myStack) == 0)
    {
        printf("%s是回文!\n", str);
        printf("%d\n", queueNotEmpty(mydata));
        printf("%d\n", StackNotEmpty(myStack));
    }
    getchar();getchar();
}
