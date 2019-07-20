/*
二叉树采用二叉链表作存储结构，试编程实现二叉树的如下基本操作：
1. 按先序序列构造一棵二叉链表表示的二叉树T；
2. 对这棵二叉树进行遍历：先序、中序、后序以及层次遍历序列，分别输出结点的遍历序列；
3. 求二叉树的深度/结点数目/叶结点数目；
*/
#include <malloc.h>
#include <stdio.h>
#define Null 0
typedef char ElemType;
typedef struct node
{
    ElemType data;
    struct node *lchild;
    struct node *rchild;
} BTree, *pBTree;

//先序创建树
void CreateBTree(BTree **T)
//此处参数应该用指针的指针，应给它要改变指向二叉树根的那个指针
{
    char ch;
    printf("请输入先序二叉树\n");
    ch = getchar();
    getchar();     //得到回车按那个字符
    if (ch == '/') //输入空字符时要打空格
    {
        (*T) = NULL;
        return;
    }
    else
    {
        if (!((*T) = (BTree *)malloc(sizeof(BTree))))
            return;
        (*T)->data = ch;

        CreateBTree(&(*T)->lchild);
        CreateBTree(&(*T)->rchild);
    }
}

void BTreePrint(BTree *Tr, int n)
//逆时针旋转90°打印二叉树，n为缩进层数，初始值为0
{
    int i;
    if (Tr == NULL)
        return;

    BTreePrint(Tr->rchild, n + 1);
    for (i = 0; i < n; i++)
        printf("  ");
    if (n >= 0)
    {
        printf("--");
        printf("%c\n", Tr->data);
    }
    BTreePrint(Tr->lchild, n + 1);
}

void pre(BTree *T)
{
    if(T)
    {
        printf("%c", T->data);
        pre(T->lchild);
        pre(T->rchild);
    }
}

void in(BTree *T)
{
    if (T)
    {
        in(T->lchild);
        printf("%c", T->data);
        in(T->rchild);
    }
}

void post(BTree *T)
{
    if (T)
    {
        post(T->lchild);
        post(T->rchild);
        printf("%c", T->data);
    }
}

int getnodes(BTree *T)
{
    int n1 = 0, n2 = 0;
    if (T == Null)
        return 0;
    else if (T->lchild == Null && T->rchild == Null)
        return 1;
    else
    {
        n1 = getnodes(T->lchild);
        n2 = getnodes(T->rchild);
        return (n1 + n2 + 1);
    }
}

int getlefs2(BTree *T)
{
    static int n = 0;
    if (T)
    {
        getlefs2(T->lchild);

        getlefs2(T->rchild);
        if (T->lchild == Null && T->rchild == Null)
        {
            n++;
        }
    }
    return n;
}

int getlefes(BTree *T)
{
    int n1 = 0, n2 = 0;
    if (T == Null)
        return 0;
    else if (T->lchild == Null && T->rchild == Null)
        return 1;
    else
    {
        n1 = getlefes(T->lchild);
        n2 = getlefes(T->rchild);
        return (n1 + n2);
    }
}

int depth(BTree *T)
{
    int h1=0, h2=0;
    if (T != Null)
    {
        h1 = depth(T->lchild);
        h2 = depth(T->rchild);
        if(h1>h2)
            return h1 + 1;
        else
            return h2 + 1;
    }
    return 0;
}

int count(BTree *t)
{
    static int c = 0;
    if (t != Null)
    {
        count(t->lchild);
        c++;
        count(t->rchild);
    }
    return c;
}

int main()
{
    int a, b;
    BTree *bTree;
    CreateBTree(&bTree);
    BTreePrint(bTree, 0);
    printf("先序遍历序列");
    pre(bTree);
    printf("中序遍历序列");
    in(bTree);
    printf("后序遍历序列");
    printf("\n");
    post(bTree);
    printf("结点总数是%d\n", getnodes(bTree));
    printf("叶子总数是%d\n", getlefes(bTree));
    a = count(bTree);
    printf("树上结点数是%d\n", a);
    b = getlefs2(bTree);
    printf("树上叶子%d\n", b);
    printf("树的高度是%d\n", depth(bTree));
    getchar();getchar();
}
