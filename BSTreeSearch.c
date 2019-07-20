/*
�������һ��ؼ��֣��ؼ��ֵĸ�����ֵ������ʱ�ɼ������룩��
�����Ӧ�Ķ�����������ÿ�����ҵ���ǰ�ؼ��ֵĲ���λ�ã�Ȼ������룩��
����������������������õ������С�
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
    DataType elem; //elem���йؼ�����
    struct BinSTreeNode *lchild;
    struct BinSTreeNode *rchild;
} BinSTreeNode, *BinSTree;

void BSTreeInsert(BinSTree *t, KeyType k)
//�ڶ����������в���ֵΪelem��Ԫ�أ�*tָ����������������
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
        InOrder((t)->lchild); /* ���������� */
        printf("%4d", (t)->elem.key);
        InOrder((t)->rchild); /* ���������� */
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
// �ڶ�����������ɾ���ؼ���Ϊk�Ľ�㣬*btָ������������ĸ���㡣ɾ���ɹ�����1�����ɹ�����0
{
    BinSTree f, p, q, s;
    p = *bt;
    f = NULL;
    while (p && p->elem.key != k) /* ���ҹؼ���Ϊkey�Ľ�� */
    {
        f = p; /* fΪָ����*p��˫�׽���ָ�� */
        if (p->elem.key > k)
            p = p->lchild; /* ���������� */
        else
            p = p->rchild; /* ���������� */
    }
    if (p == NULL)
        return (0);        /* �Ҳ�����ɾ�Ľ��ʱ���� */
    if (p->lchild == NULL) /* ��ɾ����������Ϊ�� */
    {
        if (f == NULL) /* ��ɾ���Ϊ����� */
            *bt = p->rchild;
        else if (f->lchild == p) /* ��ɾ�������˫�׽������� */
            f->lchild = p->rchild;
        else
            f->rchild = p->rchild; /* ��ɾ�������˫�׽����ҽ�� */
        free(p);
    }
    else
    {
        q = p;
        s = p->lchild;
        while (s->rchild) /* �ڴ�ɾ�����������в��������½�� */
        {
            q = s;
            s = s->rchild;
        }
        if (q == p) /* �������½���������������ɾ����� */
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
        printf("\t\t\t---����������---\n");
        printf("\n\t\t\t*******************************************");
        printf("\n\t\t\t*          1---��������������             *");
        printf("\n\t\t\t*          2---�����������������         *");
        printf("\n\t\t\t*          3---���Ҹ����ؼ���             *");
        printf("\n\t\t\t*          4---ɾ�������ؼ���             *");
        printf("\n\t\t\t*          0---��     ��                  *");
        printf("\n\t\t\t*******************************************");
        printf("\t\t\t��ѡ��˵���(0--4):");
        scanf("%d", &op);
        getchar();
        switch (op)
        {
        case 1:
            printf("��������������\n");
            printf("���������������������Ľ��������");
            scanf("%d", &n);
            printf("������%d������ֵ��", n);
            for (i = 0; i < n; i++)
            {
                scanf("%d", &a[i]);
            }
            for (i = 0; i < n; i++)
                BSTreeInsert(&t, a[i]);
            break;
        case 2:
            printf("�����������������\n");
            InOrder(t);
            break;
        case 3:
            printf("���Ҹ����ؼ���\n");
            printf("����������ҹؼ���:");
            scanf("%d", &k);
            p = BSTreeSearch(t, k);
            if (p == NULL)
                printf("����ʧ��\n");
            else
                printf("%#x,%d", p, (p->elem).key);
            break;
        case 4:
            printf("ɾ�������ؼ���\n");
            printf("�������ɾ���ؼ���:");
            scanf("%d", &k);
            flag = BSTreeDelete(&t, k);
            if (flag == 0)
                printf("ɾ��ʧ�ܣ����в����ڴ�ɾ���ؼ���\n");
            else
                printf("ɾ���Ĺؼ���Ϊ��%d", k);
            break;
        case 0:
            c = 0;
            printf("\n\t\t\t�������!\n");
            break;
        default:
            printf("\n\t\t\t\t�������!����������!\n");
            break;
        }
    }
}
