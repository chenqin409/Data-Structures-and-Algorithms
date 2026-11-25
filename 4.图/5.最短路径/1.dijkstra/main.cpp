#include <iostream>
using namespace std;

#define MAXVEX 100 //最大顶点数
#define MAX 1e+8


struct GraphMatrix{
    int n;  //顶点个数
    char vexs[MAXVEX]; //顶点信息
    int arcs[MAXVEX][MAXVEX]; //邻接矩阵信息（其中，对角线当做visit数组来使用）
};

struct Path{
    char vex;  //顶点
    int length;  //长度
    int prevex;  //前驱顶点
};

Path dist[MAXVEX];  //distance,记录单源最短路径

//初始化
void Init(GraphMatrix& gm,Path dist[])
{
    dist[0].length=0;  //对起始点初始化
    dist[0].prevex = 0;
    dist[0].vex = gm.vexs[0];
    gm.arcs[0][0] = 1; //标记已访问

    for(int i=1;i<gm.n;i++)
    {
        dist[i].length = gm.arcs[0][i];
        dist[i].vex = gm.vexs[i];
        if(dist[i].length==MAX)  //判断前驱结点的记录
        {
            dist[i].prevex = -1;
        }
        else
        {
            dist[i].prevex = 0;
        }
    }

}

void dijkstra(GraphMatrix gm,Path dist[])
{
    int min_vex,min_path;
    Init(gm,dist);
    //找到最小路径
    for(int i=1;i<gm.n;i++)  //第i条路径
    {
        min_vex = 0; min_path = MAX;
        for(int j=1;j<gm.n;j++)  //第j个顶点
        {
            if(gm.arcs[j][j]==0 && dist[j].length<min_path)
            {
                min_path = dist[j].length;
                min_vex = j;
            }
        }
        if(min_vex==0) break;

        gm.arcs[min_vex][min_vex] = 1;    //标记改次找到的最短路径节点

        //更新下一轮数据
        for(int j=1;j<gm.n;j++)
        {
            if(gm.arcs[j][j]==0 && dist[j].length>min_path+gm.arcs[min_vex][j])
            {
                dist[j].length=min_path+gm.arcs[min_vex][j];
                dist[j].prevex = min_vex;
            }
        }

    }
}

void CreatGraph(GraphMatrix& gm,int n)
{
    gm.n = n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>gm.arcs[i][j];
            if(i!=j && gm.arcs[i][j]==0)  gm.arcs[i][j] = MAX;
        }
    }
}

int main()
{
    GraphMatrix gm;
    int n;
    cin>>n;
    CreatGraph(gm,n);
    dijkstra(gm,dist);

    for(int i=0;i<gm.n;i++)
    {
        cout<<dist[i].length<<"————"<<dist[i].prevex<<endl;
    }
    return 0;
}
