#include <iostream>
using namespace std;

#define N 20
#define max 99999
struct Group{
    char data[N];
    int arc[N][N];
    int nodesize;
};

struct Edge{
    int start;
    int stop;
    int weight;
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
                int value = (rand()%100<40)?1:max;
                g.arc[i][j] = g.arc[j][i]= value;
            }
        }
    }
}

void Prim(Group& g,Edge mst[])  //传入图和权值表
{
    //初始化权值表
    for(int i=0;i<g.nodesize-1;i++)
    {
        mst[i].start =0; //第i条边的起点
        mst[i].stop = i+1; //第i条边的终点
        mst[i].weight = g.arc[0][i+1]; //第i条边的权重
    }
    //每一轮循环找出最小权值的边

    for(int i=0;i<g.nodesize-1;i++)  //当前候选边为从第i条边到第g.nodesize-2条边
    {
        int j;
        int min_weight = max;
        int min_edge = i;
        for(j=i;j<g.nodesize-1;j++)
        {
            if(mst[j].weight<min_weight)
            {
                min_weight = mst[j].weight;
                min_edge = j;
            }
        }

        if(min_edge!=i)  //判断是否需要交换顺序，把最小边排序到前面
        {
            Edge temp = mst[i];
            mst[i] = mst[min_edge];
            mst[min_edge] = temp;
        }
        int x = mst[i].stop;
        //通过找到最小边更新权值，为下一次循环做准备
        for(j=i+1;j<g.nodesize-1;j++)
        {
            int stop = mst[j].stop;
            int new_weight = g.arc[x][stop];
            if(new_weight<mst[j].weight)
            {
                mst[j].start = x;
                mst[j].weight = new_weight;
            }
        }
    }
}

void Output(Edge mst[],Group& g)
{
    for(int i=0;i<g.nodesize-1;i++)
    {
        cout<<mst[i].start<<"——"<<mst[i].stop<<"\tweight："<<mst[i].weight<<endl;
    }

}
int main()
{
    Group g;
    CreatGroup(g);
    Edge mst[N];
    Prim(g,mst);
    Output(mst,g);
    return 0;
}
