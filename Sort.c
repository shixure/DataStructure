/*
任意给出一组关键字（关键字的个数和值在运行时由键盘输入），
分别采用直接插入排序，希尔排序，冒泡排序，快速排序，选择排序对其进行排序，
并输出每个排序算法得到的序列。
*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 //假定顺序表的最大长度为100

typedef int KeyType; //假定关键字类型为整数类型
typedef struct
{
	KeyType key; //关键字项
} DataType;		 //数据元素类型
typedef struct
{
	DataType r[MAXSIZE + 1]; //r[0]闲置或充当哨兵
	int length;				 //顺序表长度
} SqList;

void Creat_SqList(SqList *S)
{
	int i;
	printf("请输入顺序表的长度：");
	scanf("%d", &(S->length));
	printf("请输入%d个关键字：", S->length);
	for (i = 1; i <= S->length; i++)
		scanf("%d", &(S->r[i].key));
}

void StraightInsertSort(SqList *S) //直接插入排序//对顺序表s中s->r[1..length]作直接插入排序
{
}

void ShellInsert(SqList *s, int gap) //步长为gap的插入排序
{
	int i, j;
	for (i = gap + 1; i <= s->length; i++)
		if (s->r[i].key < s->r[i - gap].key) //小于时，需将r[i]插入有序表
		{
			s->r[0] = s->r[i]; //为统一算法设置监视哨
			for (j = i - gap; j > 0 && s->r[0].key < s->r[j].key; j = j - gap)
				s->r[j + gap] = s->r[j]; //记录后移
			s->r[j + gap] = s->r[0];	 //插入到正确位置
		}
}

void ShellSort(SqList *S, int gaps[], int t)
{ //按增量序列gaps[0，1…，t-1]对顺序表S作希尔排序
	int k;
	for (k = 0; k < t; k++)
		ShellInsert(S, gaps[k]);
}

void BubbleSort(SqList *S)
//对顺序表S作冒泡排序
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
	S->r[0] = S->r[low];	  //以子表的第一个记录作为轴值记录
	pivotkey = S->r[low].key; //取轴值记录关键字
	while (low < high)		  //从表的两端交替地向中间扫描
	{
		while (low < high && S->r[high].key >= pivotkey)
			high--;
		if (low < high)
			S->r[low++] = S->r[high]; //将比轴值记录小的交换到低端
		while (low < high && S->r[low].key <= pivotkey)
			low++;
		if (low < high)
			S->r[high--] = S->r[low];
	}
	S->r[low] = S->r[0]; //轴值（支点）记录到位
	return low;			 //返回轴值（支点）记录所在位置
}

void QuickSort(SqList *S, int low, int high)
{ //对顺序表S中的子序列r[low…high]作快速排序
	int pivotloc;
	if (low < high)
	{
		pivotloc = QuickSort1(S, low, high);
		//对小于轴值序列实现递归排序
		QuickSort(S, low, pivotloc - 1);
		//对大于轴值序列实现递归排序
		QuickSort(S, pivotloc + 1, high);
	}
}
void SelectSort(SqList *S)
{
	int i, j, t;
	for (i = 1; i < S->length; i++) /* 作S->length-1趟选取 */
	{
		for (j = i + 1, t = i; j <= S->length; j++)
		{
			if (S->r[t].key > S->r[j].key)
				t = j; /* t中存放关键字最小的记录下标 */
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
		printf("\t\t\t---排序---\n");
		printf("\n\t\t\t*******************************************");
		printf("\n\t\t\t*          1---创建待排序序列             *");
		printf("\n\t\t\t*          2---直接插入排序               *");
		printf("\n\t\t\t*          3---希尔排序                   *");
		printf("\n\t\t\t*          4---冒泡排序                   *");
		printf("\n\t\t\t*          5---快速排序                   *");
		printf("\n\t\t\t*          6---简单选择排序               *");
		printf("\n\t\t\t*          7---输出排序后序列             *");
		printf("\n\t\t\t*          0---退     出                  *");
		printf("\n\t\t\t*******************************************");
		printf("\t\t\t请选择菜单号(0--7):");
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
			printf("请输入增量序列的个数：");
			scanf("%d", &t);
			printf("请输入%d增量的值：\n", t);
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
			printf("\n\t\t\t程序结束!\n");
			break;
		default:
			printf("\n\t\t\t\t输入错误!请重新输入!\n");
			break;
		}
	}
}
