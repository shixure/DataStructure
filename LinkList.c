/*建立10个数据元素的线性表L={1，2，3…10}指定在第2位置插入元素25，然后删除第4个位置上的元素，
分别显示各步骤结果，线性表链表表示及实现*/
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct Nodes
{
   ElemType data;
   struct Node *next;
} LNode, *LinkList;

void inilialist(LNode **L)
{
   if ((*L = (LNode *)malloc(sizeof(LNode))) == NULL)
      exit(1);
   (*L)->next = NULL;
}

void insert(LNode *L, int i, ElemType x)
{
   LNode *s, *p = L;
   int j = 0;
   while (j != (i - 1) && p != NULL)
   {
      p = p->next;
      j++;
   }
   if (p == NULL)
   {
      printf("序号出错！");
   }
   else
   {
      if ((s = (LNode *)malloc(sizeof(LNode))) == NULL)
         exit(1);
      s->data = x;
      s->next = p->next;
      p->next = s;
   }
}

void Delete(LNode *L, int i) //删除值为x的结点
{
   LNode *p;
   LNode *u;
   int j = 0;
   p = L;
   while (j != i - 1 && p != NULL)
   {
      p = p->next;
      j++;
   }
   if (p == NULL || p->next == NULL)
   {
      printf("删除序号出错！");
   }
   else
   {
      u = p->next;
      p->next = u->next;
      free(u);
   }
}
int main()
{
   LNode *L;
   inilialist(&L);
   int i, x;
   LNode *head = L;
   for (i = 1; i < 11; i++)
   {
      scanf("%d", &x);
      insert(L, i, x);
   }
   printf("初始表：");
   L = head->next;
   while (L)
   {
      printf("%d ", L->data);
      L = L->next;
   }
   printf("\n");
   L = head;
   insert(L, 2, 25);
   printf("插入后：");
   L = head->next;
   while (L)
   {
      printf("%d ", L->data);
      L = L->next;
   }
   printf("\n");
   L = head;
   Delete(L, 4);
   printf("删除后：");
   L = head->next;
   while (L)
   {
      printf("%d ", L->data);
      L = L->next;
   }
}
