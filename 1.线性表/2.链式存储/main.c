#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef int ElemType;

typedef struct SingleNode{
	ElemType data;
	struct SingleNode *next;
}SingleLinkedList, *LinkList;

//初始化
void ListInitialize(SingleLinkedList* *head)
{
	if((*head = (SingleLinkedList*) malloc(sizeof(SingleLinkedList)))==NULL)
	{
		exit(1);
	}
	(*head)->next = NULL;
} 

//求长度
int ListLength(SingleLinkedList* head)
{
	SingleLinkedList* p = head;
	int size = 0;
	while(p->next!= NULL)
	{
		p = p->next;
		size++;
	}
	return size;	
} 

//取数据元素
int ListGet(SingleLinkedList* head,int i,ElemType* x)
{
	SingleLinkedList* p=head;
	int j=-1;
	while(p->next!=NULL&& j<i)
	{
		p=p->next;
		j++;
	}
	if (j!=i)
	{
		//printf("取元素位置参数出错！\n");
		return 0; //不进行后面赋值操作 
	}
	*x = p->data;
	return 1;	 
} 

//插入元素
int ListInsert(SingleLinkedList* head ,int i,ElemType x)
{
	SingleLinkedList *p=head,*q;
	int j=-1;
	while(p->next!=NULL && j<i-1)
	{
		p=p->next;
		j++;
	}
	if(j!= i-1)
	{
		//printf("插入位置参数错！\n");
		return 0;
	}
	if((q=(SingleLinkedList*)malloc(sizeof(SingleLinkedList)))==NULL)
	{
		exit(1);
	}
	q->data = x;
	q->next = p->next;
	p->next = q;
	return 1;
}

//删除元素
int ListDelete(SingleLinkedList* head,int i,ElemType *x)
{
	SingleLinkedList *p=head,*s;
	int j=-1;
	while(p->next!=	NULL && p->next->next!= NULL &&j<i-1)
	{
		p = p->next;
		j++;
	}
	if(j!=i-1)
	{
		//printf("删除位置参数错！\n");
		return 0;
	}
	s = p->next;
	*x = s->data;
	p->next = s->next;
	free(s);
	return 1;
} 

//释放操作
void ListDestroy(SingleLinkedList* *head)
{
	SingleLinkedList *p,*p1;
	p = *head;
	while(p!= NULL)
	{
		p1 = p;
		p= p->next;
		free(p1);
	}	
	*head = NULL;
} 

//打印
void PrintList(SingleLinkedList* head)
{
	SingleLinkedList *p=head->next;
	if(p==NULL)
	{
		return;
	}
	printf("%d",p->data);
	p=p->next;
	while(p!=NULL)
	{
		printf(" %d",p->data);
		p=p->next;
	}

} 
 
int main(int argc, char *argv[]) {
	
	SingleLinkedList* sl;
	ListInitialize(&sl);
	int num;
	int temp;
	int value;
	scanf("%d",&num);
	int a[num];
	for(int i=0;i<num;i++)
	{
		scanf("%d",&temp);
		a[i]=temp;
	}
	for(int i=0;i<num;i++)
	{
		temp=ListInsert(sl,i,a[num-i-1]);
	}
	int times;
	scanf("%d",&times);
	while(times>0)
	{
		char str[20];
		scanf("%s",&str);
		if(strcmp(str,"show")==0)
		{
			if(sl->next==NULL)
			{
				printf("Link list is empty\n");
			}
			else
			{
				PrintList(sl);
				printf("\n");
			}
			
		}
		
		if(strcmp(str,"get")==0)
		{
			scanf("%d",&temp);
			temp = ListGet(sl,temp-1,&value);
			if(temp ==0)
			{
				printf("get fail\n");
			}
			else
			{
				printf("%d\n",value);
			}
		}
		
		if(strcmp(str,"delete")==0)
		{
			scanf("%d",&temp);
			temp = ListDelete(sl,temp-1,&value);
			if(temp==0)
			{
				printf("delete fail\n");
			}
			else
			{
				printf("delete OK\n");
			}
		}
		
		if(strcmp(str,"insert")==0)
		{
			scanf("%d",&temp);
			scanf("%d",&value);
			temp = ListInsert(sl,temp-1,value);
			if(temp == 0)
			{
				printf("insert fail\n");
			}
			else
			{
				printf("insert OK\n");
			}
		}
		times--;
	}
	return 0;
}
