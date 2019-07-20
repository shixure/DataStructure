/*
对于给定的一组按照从小到大排序的整数，通过普通查找方法和二分查找的方法判断一个数是否在这个数组中。
*/

#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef int KeyType; //整型
typedef struct
{
    KeyType key;
} DataType;
typedef struct
{
    DataType list[MaxSize];
    int size;
} SeqList;

void ListInitiate(SeqList *L)
{
    L->size = 0; /*定义初始数据元素个数*/
}

int creat(SeqList *L, int n)
{
    int i;
    printf("input the datas:");
    for (i = 0; i < n; i++)
        scanf("%d", &L->list[i]);
    return 1;
}

int ListLength(SeqList *L)

{
    return L->size;
}

int SeqSearch(SeqList *s, KeyType k)
//在表s中顺序查找关键字k，若查找成功，则返回该元素在表中的位置，若查找失败，返回-1
{
    for (int i = 0; i < s->size; i++)
    {
        if (s->list[i].key == k)
            return i;
    }
    return -1;
}

int BinSearch(SeqList *s, KeyType k)
//在表s中用折半查找法Binary_Search查找关键字k，若查找成功，则函数值为该元素在表中的位置，若查找失败，返回-1。
{
    int low = 0;
    int high = s->size - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (s->list[mid].key == k)
            return mid;
        else if (s->list[mid].key > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    SeqList a;
    int n,x;
    ListInitiate(&a);
    printf("请输入数的长度：");
    scanf("%d", &n);
    creat(&a, n);
    a.size = n;
    printf("请输入要查找的数：");
    scanf("%d", &x);
    printf("顺序查找结果：%d\n", SeqSearch(&a, x));
    printf("折半查找结果：%d", BinSearch(&a, x));
}

