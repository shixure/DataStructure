/*
���ڸ�����һ�鰴�մ�С���������������ͨ����ͨ���ҷ����Ͷ��ֲ��ҵķ����ж�һ�����Ƿ�����������С�
*/

#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100
typedef int KeyType; //����
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
    L->size = 0; /*�����ʼ����Ԫ�ظ���*/
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
//�ڱ�s��˳����ҹؼ���k�������ҳɹ����򷵻ظ�Ԫ���ڱ��е�λ�ã�������ʧ�ܣ�����-1
{
    for (int i = 0; i < s->size; i++)
    {
        if (s->list[i].key == k)
            return i;
    }
    return -1;
}

int BinSearch(SeqList *s, KeyType k)
//�ڱ�s�����۰���ҷ�Binary_Search���ҹؼ���k�������ҳɹ�������ֵΪ��Ԫ���ڱ��е�λ�ã�������ʧ�ܣ�����-1��
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
    printf("���������ĳ��ȣ�");
    scanf("%d", &n);
    creat(&a, n);
    a.size = n;
    printf("������Ҫ���ҵ�����");
    scanf("%d", &x);
    printf("˳����ҽ����%d\n", SeqSearch(&a, x));
    printf("�۰���ҽ����%d", BinSearch(&a, x));
}

