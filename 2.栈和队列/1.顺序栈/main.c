#include <stdio.h>
#include <stdlib.h>

//定义数据 
#define MaxSize 255
typedef int MyType;
//栈的结构体
typedef struct{
	MyType stack[MaxSize];
	int Top;
}Stack;

//初始化栈（指针传入，栈顶下标值赋值为0）
void Initialize(Stack *s)
{
	s->Top=0;
}

//判断栈是否为空 
int IsEmpty(Stack s)
{
	if(s.Top<=0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//进栈
void push(Stack *s,MyType value)
{
	if(s->Top>=MaxSize)
	{
		printf("Error!\n");
	}
	else
	{
		s->stack[s->Top++] = value;
	}
}

//出栈
void pop(Stack *s)
{
	if(IsEmpty(*s))
	{
		printf("Error!\n");
	}
	else
	{
		s->Top--;
	}
}

//取栈顶元素（把值赋给指针）
void top(Stack s,MyType * value)
{
	if(IsEmpty(s))
	{
		printf("Error!\n");
	}
	else
	{
		*value = s.stack[--s.Top];
	}
}
 
int main(int argc, char *argv[]) {
	Stack s;
	Initialize(&s);
	for(int i=0;i<10;i++)
	{
		push(&s,i*21-12);
	}
	int value;
	for(int i = 0;i<12;i++)
	{
		top(s,&value);
		printf("%d\n",value);
		pop(&s);
	}

	return 0;
}
