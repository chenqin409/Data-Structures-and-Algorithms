#include <stdio.h>
#include <stdlib.h>

//定义数据
typedef int MyType;
//定义结构体（包含数据和指向下一节点的指针）
typedef struct temp{
	MyType data;
	struct temp *next;
}node;

//初始化带头节点的链式栈（二级指针传入，先给二级指针分配内存，再通过一级指针把下一节点置空） 
void Initialize(node* *head)
{
	if((*head=(node*)malloc(sizeof(node)))==NULL)
	{
		exit(1);
	}
	(*head)->next = NULL;
}

//判断是否为空
int IsEmpty(node* head)
{
	if(head->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//入栈（新建一个指针型节点，在进行赋值）
void push(node* head,MyType value)
{
	node* p;
	if((p=(node*)malloc(sizeof(node)))==NULL)
	{
		printf("Error!");
		return;
	}
	p->data = value;
	p->next = head->next;
	head->next = p;
	
}
//出栈（先取栈顶节点，改变头指针，再删除）
void pop(node* head)
{
	if(IsEmpty(head))
	{
		printf("Error!\n");
	}
	else
	{
		node* p=head->next;
		head->next = p->next;  //把第三个点给第一个点，第二个点（第一个值）丢弃 
		free(p);
	}
}
//取栈顶元素
void top(node* head,MyType* value)
{
	if(IsEmpty(head))
	{
		printf("Error!\n");
		return;
	}
	*value = head->next->data;
}
//撤销动态空间申请（使用两个指针，一个不断自增，另一个用来释放空间） 
void Destroy(node* *head)
{
	node *p,*q;
	p = *head;  //二级指针head取星号变一级指针传给p 
	while(p!=NULL)
	{
		q = p;
		p=p->next;
		free(q);
	}	
	*head = NULL;
}

int main(int argc, char *argv[]) {
	node *head;
	Initialize(&head);
	for(int i =1;i<10;i++)
	{
		push(head,i);
	}
	for(int i = 1;i<11;i++)
	{
		int value=0;
		top(head,&value);
		printf("%d\t",value);
		pop(head);
	}
	
	return 0;
}
