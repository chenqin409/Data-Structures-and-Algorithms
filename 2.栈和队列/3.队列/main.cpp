#include<iostream>
#include<string>
#include<queue>
using namespace std;

//状态用4位二进制表示，分别是农夫，狼，羊，菜
//1表示在南岸，0表示在北岸，目标是从1到0

//安全判断函数（先分别记录4个位置，再进行判断）
bool safe(int s)
{
	int farmer = (s>>3)&1;
	int wolf = (s>>2)&1;
	int goat = (s>>1)&1;
	int cabbage = s&1;
	
	if(farmer==0&&wolf+goat==2) return false;
	if(farmer==0&&goat+cabbage==2) return false;
	
	if(farmer==1&&wolf+goat==0) return false;
	if(farmer==1&&goat+cabbage==0) return false;
	
	return true;
}


int main() {
	//定义队列，前驱状态（初始化为-1），当前操作，访问状态（初始化为0） 
	queue<int>Q;
	int pre[16];
	int act[16];
	int vis[16]={0};
	for(int i=0;i<16;i++) pre[i]=-1;
	
	// 把都在南岸的初始状态记录
	Q.push(15);
	vis[15] = 1;
	
	//while搜索（退出条件，农夫带的物品，判断安全后记录） 
	while(!Q.empty())
	{
		int location = Q.front();
		Q.pop();
		
		if(location == 0) break;
		int farmer = (location>>3)&1;
		
		for(int item = 0;item<4;item++) //农夫带的东西（0：狼，1:羊，2：菜，3：空手） 
		{
			//跳过农夫不是空手的条件下，带的东西和农夫不在同一岸的情况 
			if(item!=3&&(location>>(2-item)&1)!=farmer) continue; 
			
			int next = location^(1<<3); //翻转农夫的位置 
			if(item!=3) next = next^(1<<(2-item)); //翻转物品的位置 
			
			//判断是否能写进记录
			if(safe(next)&&vis[next]==0)
			{
				Q.push(next);
				vis[next]=1;
				pre[next] = location;
				act[next] = item;
			} 
		} 
	}
	
	//找回最佳路径
	int path[16],i=0;
	for(int place = 0;place!=-1;place = pre[place])
	{
		path[i++] = place;
	}
	
	//通过逆序遍历找到正向结果 
	string name[4]={"狼","羊","菜","空手"};
	for(int j=i-1;j>=0;j--)
	{
		if(j<i-1) //排除未赋值的act[15] 
		{
			cout<<"第"<<i-j-1<<"步：";
			if(act[path[j]]==3) cout<<"农夫"<<name[act[path[j]]]<<"过河"<<endl; 
			else           cout<<"农夫带"<<name[act[path[j]]]<<"过河"<<endl; 
			
		}
	}
	return 0;
}
