#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MaxSize 255

typedef struct{
	char ch[MaxSize];
	int len;
}String; 


void get_next(String T,int next[])
{
	int i = 1; //主指针
	int j = 0; //匹配指针
	next[1] = 0 ; //规定
	while(i<T.len)
	{
		if(j==0||T.ch[i]==T.ch[j]) //正在判断第i+1个位置的情况 
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j]; //匹配指针回退 
		}
	}
}

int Index_KMP(String S,String T,int pos)
{
	int i = pos;//主串的下标
	int j = 1; //字串的下标
	int next[MaxSize];
	get_next(T,next);
	while(i<=S.len && j<=T.len)
	{
		if(j==0 || S.ch[i]==T.ch[j])
		{
			i++;
			j++;
		}	
		else
		{
			j=next[j];
		}
	} 
	if(j>T.len)
	{
		return i-T.len;
	}
	else
	{
		return 0;
	}
}




int main(int argc, char *argv[]) {
	for(int i=0;i<3;i++)
	{
		String a,b;
		char temp_a[MaxSize],temp_b[MaxSize];
		scanf("%s",temp_a);
		scanf("%s",temp_b);
		a.len=strlen(temp_a);
		b.len=strlen(temp_b);
		for(int i=0;i<a.len;i++)
		{
			a.ch[i+1]=temp_a[i];
		}
		a.ch[a.len+1]='\0';
		
		for(int i=0;i<b.len;i++)
		{
			b.ch[i+1]=temp_b[i];
		}
		b.ch[b.len+1]='\0';
		
		printf("%d\n",Index_KMP(a,b,1));
	}
	return 0;
}
