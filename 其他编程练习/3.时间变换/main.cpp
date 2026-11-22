#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    int a1,b1,c1;
    scanf("%d:%d:%d",&a,&b,&c);
    scanf("%d:%d:%d",&a1,&b1,&c1);
    int sum=0;
    //法2，直接把两个时间转换成秒做差
    if(c1-c>=0)
    {
        sum+=c1-c;
    }
    else
    {
        sum+=c1+60-c;
        b1--;
    }

    if(b1-b>=0)
    {
        sum+=60*(b1-b);
    }
    else
    {
        sum+=(b1+60-b)*60;
        a1--;
    }
    if(a1-a>=0)
    {
        sum+=(a1-a)*3600;
    }
    else
    {
        a1+=24;
        sum+=(a1-a)*3600;
    }
    cout<<sum;
    return 0;
}
