#include<iostream>
#include<queue>
using namespace std;
#define N 20

class Group{
public:
    char data[N];
    int arc[N][N];
    int nodesize;
};

void CreatGroup(Group& g)
{
    cout<<"请输入图节点个数（<=20）：";
    int n;
    cin>>n;
    if(n>N||n<0)
    {
        cout<<"error！"<<endl;
        return;
    }
    g.nodesize = n;
    for(int i=0;i<g.nodesize;i++)
    {
        g.data[i] = 'A'+i;
    }
    for(int i =0;i<g.nodesize;i++)
    {
        for(int j = 0;j<g.nodesize;j++)
        {
            if(i==j) g.arc[i][j]=0;
            else if(i<j)
            {
                int value = (rand()%100<40)?1:0;
                g.arc[i][j] = g.arc[j][i]= value;
            }
        }
    }
}

int visit[N];
void bfs_v(Group &g,int v)
{
    queue<int>q;
    cout<<g.data[v]<<" ";
    visit[v]=1;
    q.push(v);
    while(!q.empty())
    {
        int temp =q.front();
        q.pop();
        for(int i=0;i<g.nodesize;i++)
        {
            if(g.arc[temp][i]==1&&visit[i]!=1)
            {
                cout<<g.data[i]<<" ";
                visit[i]=1;
                q.push(i);
            }
        }
    }
}
//排查漏遍历的节点
void bfs(Group& g)
{
    for(int i=0;i<g.nodesize;i++)
    {
        if(visit[i]==0) bfs_v(g,i);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    Group g;
    CreatGroup(g);
    bfs(g);
    return 0;
}
