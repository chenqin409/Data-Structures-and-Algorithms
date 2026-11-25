#include<bits/stdc++.h>
using namespace std;

class Septinary{
public:
    Septinary(string num)
    {
        data= new char[100];
        CreatSeptinary(num);
    }

    void CreatSeptinary(string num)
    {
        int temp1,i=0;
        stack<int>st;
        while(1)
        {
            temp1 = mod(num);
            st.push(temp1);
            num=divide(num);
            if(num=="0") break;
        }
        while(!st.empty())
        {
            data[i++]=(char)numberToChar(st.top());
            st.pop();
        }
        data[i]='\0';

    }

    int mod(string num)
    {
        int temp1=0;
        for(int i=0;i<num.size();i++)
        {
            temp1+= num[i]-'0';
            temp1=(temp1%8)*10;
        }
        return temp1/10;
    }

    string divide(string num)
    {
        int a=0,temp;
        string s;
        for(int i=0;i<num.size();i++)
        {
            a=a*10+num[i]-'0';
            if(a<8 && s.empty()) continue;  //只跳过开头，中间计算时有0需要保留
            temp=a/8;
            s.push_back(temp+'0');
            a%=8;
        }
        if(s.empty()) s="0";
        return s;
    }

    int numberToChar(int num)
    {
        char c=num+'0';
        return (int)c;
    }

    ~Septinary()
    {
        delete[] data;
    }

    char *data;
};


int main()
{
    string num;
    cin>>num;
    Septinary s(num);
    cout<<s.data;

    return 0;
}
