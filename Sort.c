/*
�������һ��ؼ��֣��ؼ��ֵĸ�����ֵ������ʱ�ɼ������룩��
�ֱ����ֱ�Ӳ�������ϣ������ð�����򣬿�������ѡ����������������
�����ÿ�������㷨�õ������С�
*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 //�ٶ�˳������󳤶�Ϊ100

typedef int KeyType; //�ٶ��ؼ�������Ϊ��������
typedef struct
{
	KeyType key; //�ؼ�����
} DataType;		 //����Ԫ������
typedef struct
{
	DataType r[MAXSIZE + 1]; //r[0]���û�䵱�ڱ�
	int length;				 //˳�����
} SqList;

void Creat_SqList(SqList *S)
{
	int i;
	printf("������˳���ĳ��ȣ�");
	scanf("%d", &(S->length));
	printf("������%d���ؼ��֣�", S->length);
	for (i = 1; i <= S->length; i++)
		scanf("%d", &(S->r[i].key));
}

void StraightInsertSort(SqList *S) //ֱ�Ӳ�������//��˳���s��s->r[1..length]��ֱ�Ӳ�������
{
}

void ShellInsert(SqList *s, int gap) //����Ϊgap�Ĳ�������
{
	int i, j;
	for (i = gap + 1; i <= s->length; i++)
		if (s->r[i].key < s->r[i - gap].key) //С��ʱ���轫r[i]���������
		{
			s->r[0] = s->r[i]; //Ϊͳһ�㷨���ü�����
			for (j = i - gap; j > 0 && s->r[0].key < s->r[j].key; j = j - gap)
				s->r[j + gap] = s->r[j]; //��¼����
			s->r[j + gap] = s->r[0];	 //���뵽��ȷλ��
		}
}

void ShellSort(SqList *S, int gaps[], int t)
{ //����������gaps[0��1����t-1]��˳���S��ϣ������
	int k;
	for (k = 0; k < t; k++)
		ShellInsert(S, gaps[k]);
}

void BubbleSort(SqList *S)
//��˳���S��ð������
{
	int i,j,mid;
	for (i = 0; i < S->length-1;i++)
	{
		for (j = 0; j < S->length-1-i;j++)
		{
			if(S->r[j].key>S->r[j+1].key)			{
				mid = S->r[j].key;
				S->r[j].key = S->r[j+1].key;
				S->r[j + 1].key = mid;
			}
		}
	}
}
int QuickSort1(SqList *S, int low, int high)
{
	KeyType pivotkey;
	S->r[0] = S->r[low];	  //���ӱ�ĵ�һ����¼��Ϊ��ֵ��¼
	pivotkey = S->r[low].key; //ȡ��ֵ��¼�ؼ���
	while (low < high)		  //�ӱ�����˽�������м�ɨ��
	{
		while (low < high && S->r[high].key >= pivotkey)
			high--;
		if (low < high)
			S->r[low++] = S->r[high]; //������ֵ��¼С�Ľ������Ͷ�
		while (low < high && S->r[low].key <= pivotkey)
			low++;
		if (low < high)
			S->r[high--] = S->r[low];
	}
	S->r[low] = S->r[0]; //��ֵ��֧�㣩��¼��λ
	return low;			 //������ֵ��֧�㣩��¼����λ��
}

void QuickSort(SqList *S, int low, int high)
{ //��˳���S�е�������r[low��high]����������
	int pivotloc;
	if (low < high)
	{
		pivotloc = QuickSort1(S, low, high);
		//��С����ֵ����ʵ�ֵݹ�����
		QuickSort(S, low, pivotloc - 1);
		//�Դ�����ֵ����ʵ�ֵݹ�����
		QuickSort(S, pivotloc + 1, high);
	}
}
void SelectSort(SqList *S)
{
	int i, j, t;
	for (i = 1; i < S->length; i++) /* ��S->length-1��ѡȡ */
	{
		for (j = i + 1, t = i; j <= S->length; j++)
		{
			if (S->r[t].key > S->r[j].key)
				t = j; /* t�д�Źؼ�����С�ļ�¼�±� */
		}
		if (t != i)
		{
			S->r[0] = S->r[t];
			S->r[t] = S->r[i];
			S->r[i] = S->r[0];
		}
	}
}
void Out_SqList(SqList *S)
{
	int i;
	for (i = 1; i <= S->length; i++)
	{
		printf("%4d", S->r[i].key);
	}
}
int main()
{
	int c = 1, op, i;
	SqList S;
	int gaps[10];
	int t;
	while (c)
	{
		printf("\n\n\n\n");
		printf("\t\t\t---����---\n");
		printf("\n\t\t\t*******************************************");
		printf("\n\t\t\t*          1---��������������             *");
		printf("\n\t\t\t*          2---ֱ�Ӳ�������               *");
		printf("\n\t\t\t*          3---ϣ������                   *");
		printf("\n\t\t\t*          4---ð������                   *");
		printf("\n\t\t\t*          5---��������                   *");
		printf("\n\t\t\t*          6---��ѡ������               *");
		printf("\n\t\t\t*          7---������������             *");
		printf("\n\t\t\t*          0---��     ��                  *");
		printf("\n\t\t\t*******************************************");
		printf("\t\t\t��ѡ��˵���(0--7):");
		scanf("%d", &op);
		getchar();
		switch (op)
		{
		case 1:
			Creat_SqList(&S);
			break;
		case 2:
			StraightInsertSort(&S);
			break;
		case 3:
			printf("�������������еĸ�����");
			scanf("%d", &t);
			printf("������%d������ֵ��\n", t);
			for (i = 0; i < t; i++)
				scanf("%d", &gaps[i]);
			ShellSort(&S, gaps, t);
			break;
		case 4:
			BubbleSort(&S);
			break;
		case 5:
			QuickSort(&S, 1, S.length);
			break;
		case 6:
			SelectSort(&S);
			break;
		case 7:
			Out_SqList(&S);
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
