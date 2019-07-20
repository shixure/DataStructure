/*
任意给出一组关键字（关键字的个数和值在运行时由键盘输入），
构造对应的二叉排序树（每次先找到当前关键字的插入位置，然后将其插入），
并对其进行中序遍历，输出得到的序列。
*/

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;

typedef struct
{
    KeyType key;
} DataType;

typedef struct BinSTreeNode
{
    DataType elem; //elem含有关键字域
    struct BinSTreeNode *lchild;
    struct BinSTreeNode *rchild;
} BinSTreeNode, *BinSTree;

void BSTreeInsert(BinSTree *t, KeyType k)
//在二叉排序树中插入值为elem的元素，*t指向二叉排序树根结点
{
    BinSTree r;
    if (*t == NULL)
    {
        r = (BinSTree)malloc(sizeof(struct BinSTreeNode));
        r->elem.key = k;
        r->lchild = r->rchild = NULL;
        *t = r;
        return;
    }
    else if (k < (*t)->elem.key)
    {
        BSTreeInsert(&((*t)->lchild), k);
    }
    else
    {
        BSTreeInsert(&((*t)->rchild), k);
    }
}

void InOrder(BinSTree t)
{
    if (t)
    {
        InOrder((t)->lchild); /* 遍历左子树 */
        printf("%4d", (t)->elem.key);
        InOrder((t)->rchild); /* 遍历左子树 */
    }
}

BinSTree BSTreeSearch(BinSTree t, KeyType k)
{
    if (t == NULL)
        return NULL;
    if (t->elem.key == k)
        return (t);
    if (t->elem.key > k)
        return (BSTreeSearch(t->lchild, k));
    else
        return (BSTreeSearch(t->rchild, k));
}

int BSTreeDelete(BinSTree *bt, KeyType k)
// 在二叉排序树中删除关键字为k的结点，*bt指向二叉排序树的根结点。删除成功返回1，不成功返回0
{
    BinSTree f, p, q, s;
    p = *bt;
    f = NULL;
    while (p && p->elem.key != k) /* 查找关键字为key的结点 */
    {
        f = p; /* f为指向结点*p的双亲结点的指针 */
        if (p->elem.key > k)
            p = p->lchild; /* 搜索左子树 */
        else
            p = p->rchild; /* 搜索右子树 */
    }
    if (p == NULL)
        return (0);        /* 找不到待删的结点时返回 */
    if (p->lchild == NULL) /* 待删结点的左子树为空 */
    {
        if (f == NULL) /* 待删结点为根结点 */
            *bt = p->rchild;
        else if (f->lchild == p) /* 待删结点是其双亲结点的左结点 */
            f->lchild = p->rchild;
        else
            f->rchild = p->rchild; /* 待删结点是其双亲结点的右结点 */
        free(p);
    }
    else
    {
        q = p;
        s = p->lchild;
        while (s->rchild) /* 在待删结点的左子树中查找最右下结点 */
        {
            q = s;
            s = s->rchild;
        }
        if (q == p) /* 将最右下结点的左子树链到待删结点上 */
            q->lchild = s->lchild;
        else
            q->rchild = s->lchild;
        p->elem.key = s->elem.key;
        free(s);
    }
    return (1);
}

main()
{
    BinSTree t = NULL, p;
    //KeyType  k;
    int n, i, c = 1, op;
    int flag;
    KeyType a[20], k;
    while (c)
    {
        printf("\n\n\n\n");
        printf("\t\t\t---二叉排序树---\n");
        printf("\n\t\t\t*******************************************");
        printf("\n\t\t\t*          1---创建二叉排序树             *");
        printf("\n\t\t\t*          2---中序遍历二叉排序树         *");
        printf("\n\t\t\t*          3---查找给定关键字             *");
        printf("\n\t\t\t*          4---删除给定关键字             *");
        printf("\n\t\t\t*          0---退     出                  *");
        printf("\n\t\t\t*******************************************");
        printf("\t\t\t请选择菜单号(0--4):");
        scanf("%d", &op);
        getchar();
        switch (op)
        {
        case 1:
            printf("创建二叉排序树\n");
            printf("请输入待构造二叉排序数的结点总数：");
            scanf("%d", &n);
            printf("请输入%d个结点的值：", n);
            for (i = 0; i < n; i++)
            {
                scanf("%d", &a[i]);
            }
            for (i = 0; i < n; i++)
                BSTreeInsert(&t, a[i]);
            break;
        case 2:
            printf("中序遍历二叉排序树\n");
            InOrder(t);
            break;
        case 3:
            printf("查找给定关键字\n");
            printf("请输入待查找关键字:");
            scanf("%d", &k);
            p = BSTreeSearch(t, k);
            if (p == NULL)
                printf("查找失败\n");
            else
                printf("%#x,%d", p, (p->elem).key);
            break;
        case 4:
            printf("删除给定关键字\n");
            printf("请输入待删除关键字:");
            scanf("%d", &k);
            flag = BSTreeDelete(&t, k);
            if (flag == 0)
                printf("删除失败，表中不存在待删除关键字\n");
            else
                printf("删除的关键字为：%d", k);
            break;
        case 0:
            c = 0;
            printf("\n\t\t\t程序结束!\n");
            break;
        default:
            printf("\n\t\t\t\t输入错误!请重新输入!\n");
            break;
        }
    }
}
