#include <bits/stdc++.h>
using namespace std;
#define N 100

struct Graph{
    int nodesize;
    int arcs[N][N];
};

int topo[N];
int v_early[N],v_late[N];  //事件的最早发生时间和最晚发生时间

void CreatGraph(Graph& g)
{
    int n;
    cin>>n;
    g.nodesize = n;
    for(int i=0;i<n;i++)
    {
        for(int j = 0 ;j<n;j++)
        {
            cin>>g.arcs[i][j];
        }
    }
}

void GetInDegree(Graph& g,int InDegree[])
{
    for(int i=0;i<g.nodesize;i++)
    {
        InDegree[i]=0;
        for(int j=0;j<g.nodesize;j++)
        {
            if(g.arcs[j][i]!=0) InDegree[i]++;  //注意是[j][i],按列求
        }
    }
}

bool TopoSort(Graph& g) //判断是否满足拓扑排序
{
    int InDegree[N];
    GetInDegree(g,InDegree);
    stack<int>st;
    for(int i=0;i<g.nodesize;i++)  //初始化，找到度为0的节点
    {
        if(InDegree[i]==0) st.push(i);
    }
    int count =0;
    while(!st.empty())
    {
        int i = st.top();
        st.pop();
        topo[count++] = i;
        for(int j=0;j<g.nodesize;j++)
        {
            if(g.arcs[i][j]!=0)
            {
                InDegree[j]--;
                if(InDegree[j]==0)
                {
                    st.push(j);
                }
            }

        }
    }
    return g.nodesize==count;
}

bool CriticalPath(Graph &g)
{
    if(!TopoSort(g))
    {
        cout<<"该图有环，无法求关键路径！";
        return false;
    }

    cout<<"拓扑排序为：";
    for(int i=0;i<g.nodesize;i++)  cout<<topo[i]<<" ";
    cout<<endl;

    //求各节点的最早发生时间
    for(int i=0;i<g.nodesize;i++)
    {
        int k = topo[i];  //拓扑排序里第i个值
        for(int j=0;j<g.nodesize;j++)  //第j个节点
        {
            if(g.arcs[k][j])  //k到j有边
            {
                v_early[j] = max(v_early[j],v_early[k]+g.arcs[k][j]);
            }
        }
    }
    int total_time = v_early[g.nodesize-1];

    //求各节点最晚发生时间
    for(int j=0;j<g.nodesize;j++) v_late[j]=total_time; //初始化为最大值
    for(int i=g.nodesize-1;i>=0;i--)
    {
        int k = topo[i];
        for(int j=0;j<g.nodesize;j++)
        {
            if(g.arcs[j][k])  //往回溯，所以是j->k
            {
                v_late[j] = min(v_late[j],v_late[k]-g.arcs[j][k]);
            }
        }
    }

    cout<<"关键顶点：";
    for(int i=0;i<g.nodesize;i++)
    {
        if(v_early[i]==v_late[i]) cout<<i<<" ";
    }
    cout<<endl;

    cout<<"关键活动：";
    for(int i=0;i<g.nodesize;i++)
    {
        for(int j=0;j<g.nodesize;j++)
        {
            if(g.arcs[i][j]&&v_late[j]==v_early[i]+g.arcs[i][j])
            {
                cout<<i<<"->"<<j<<" ";
            }
        }
    }
    cout<<endl;
    return true;
}

int main()
{
    Graph g;
    CreatGraph(g);
    CriticalPath(g);
    return 0;
}
