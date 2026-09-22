#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef int ElemType; //重定义 

typedef struct{
	ElemType list[MaxSize];
	int size;
}SequenceList;

//初始化
void ListInitialize(SequenceList *L) 
{
	L->size=0;
}

//返回长度
int ListLength(SequenceList L)
{
	return L.size;
} 

//插入操作
int ListInsert(SequenceList *L,int i,ElemType x) //插入的位置及插入的数据
{
	if(L->size>=MaxSize)
	{
		printf("顺序表已满，无法插入！\n");
		return 0;
	}
	else if(i<0 || i>L->size)
	{
		printf("参数i不合法！\n");
		return 0;
	}
	else
	{
		for(int j=L->size;j>i;j--)
		{
			L->list[j] = L->list[j-1];
		}
		L->list[i] = x;
		L->size++;
		return 1;
	}
} 

//删除操作
int ListDelete(SequenceList *L,int i,ElemType *x) //删除元素的序号，以及保存删除元素的参数
{
	if(L->size<=0)
	{
		printf("顺序表以空，无数据可删！\n");
	}	
	else if(i<0 ||i>L->size-1)
	{
		printf("参数i不合法！\n");
	}
	else
	{
		*x = L->list[i];
		for(int j = i+1;j<=L->size-1;j++)
		{
			L->list[j-1] = L->list[j];
		}
		L->size--;
		return 1;
	}
} 

//取元素
int ListGet(SequenceList L,int i,ElemType *x)
{
	if(i<0 || i>=L.size)
	{
		printf("参数i不合法！\n");
		return 0;
	}
	else
	{
		*x = L.list[i];
		return 1;
	}
} 

int main(int argc, char *argv[]) {
	SequenceList sq;
	ListInitialize(&sq);

	return 0;
}
