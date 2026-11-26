#include <iostream>
#include<stack>
using namespace std;
#define MAX 100

struct GraphMatrix{
    int n;
    int arcs[MAX][MAX];
};


//统计入度，通过遍历每一列来记录
void FindInDegree(GraphMatrix& gm,int InDegree[])
{
    for(int i=0;i<gm.n;i++)
    {
        InDegree[i]=0;
        for(int j=0;j<gm.n;j++)
        {
            if(gm.arcs[j][i]!=0) InDegree[i]++;
        }
    }
}

//每次删除一个顶点后，做出一个新的图
void MakeNewAoV(GraphMatrix& gm,int line,int InDegree[],stack<int>&topo)
{
    for(int i=0;i<gm.n;i++) //统计第line个节点
    {
        if(gm.arcs[line][i]!=0)
        {
            InDegree[i]--; //如果该节点到第i个节点有路径，则第i个节点入度减1

            if(InDegree[i]==0) //只有刚刚变成0的节点才需要入栈，防止重复入栈
            {
                topo.push(i);
            }
        }

    }
}

bool TopoSort(GraphMatrix&gm,int result[])
{
    int InDegree[MAX];
    FindInDegree(gm,InDegree);
    stack<int>topo;   //stack类似深度遍历，改为queue则类似广度遍历
    for(int i=0;i<gm.n;i++)
    {
        if(InDegree[i]== 0) topo.push(i); //找到初始入度为0的节点
    }

    int count=0;
    while(!topo.empty())
    {
        int node = topo.top();
        topo.pop();
        result[count++] = node;
        MakeNewAoV(gm,node,InDegree,topo);
    }
    if(count!=gm.n) return false;
    else return true;
}


void CreatGroup(int n,GraphMatrix& gm)
{
    gm.n = n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>gm.arcs[i][j];
        }
    }
}

int main()
{
    int n;
    cin>>n;
    GraphMatrix gm;
    CreatGroup(n,gm);
    int result[MAX];
    if(TopoSort(gm,result))
    {
        for(int i=0;i<n;i++) cout<<result[i]<<" ";
    }
    else
    {
        cout<<"该图有闭合环";
    }

    return 0;
}
