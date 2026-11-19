#include <iostream>
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
void dfs_v(Group& g,int v)
{
    cout<<g.data[v]<<" ";
    visit[v] = 1;
    for(int i =0;i<g.nodesize;i++)
    {
        if(g.arc[v][i]!=0&&visit[i]!=1)
        {
            dfs_v(g,i);
        }
    }
}

void dfs(Group &g)
{
    for(int i=0;i<g.nodesize;i++)
    {
        if(visit[i]!=1) dfs_v(g,i);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    Group g;
    CreatGroup(g);
    dfs(g);
    return 0;
}
