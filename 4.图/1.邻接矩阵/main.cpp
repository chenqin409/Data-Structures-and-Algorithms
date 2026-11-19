#include<bits/stdc++.h>
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

void Output(Group& g)
{
    cout<<"\t";
    for(int i =0;i<g.nodesize;i++)
    {
        cout<<g.data[i]<<"\t";
    }
    cout<<endl<<endl;
    for(int i=0;i<g.nodesize;i++)
    {
        cout<<g.data[i]<<"\t";
        for(int j=0;j<g.nodesize;j++)
        {
            cout<<g.arc[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }

}
int main()
{
    Group g;
    CreatGroup(g);
    Output(g);
    return 0;
}
