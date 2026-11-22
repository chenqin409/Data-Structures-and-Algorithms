#include<bits/stdc++.h>
using namespace std;

class index{
public:
    int position;
    int type;
};

int compute(string s)
{
    vector<index>ind(2);
    int j=0;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+')
        {
            ind[j].position = i;
            ind[j].type=1;
            j++;
        }
        if(s[i]=='-')
        {
            ind[j].position = i;
            ind[j].type=2;
            j++;
        }
        if(s[i]=='*')
        {
            ind[j].position = i;
            ind[j].type=3;
            j++;
        }
    }

    int result=0;
    for(int i=0;i<2;i++)
    {
        if(ind[i].type==3)
        {
            if(i==1)
            {
                int num1 = stoi(s.substr(ind[0].position+1,ind[1].position-ind[0].position-1));
                int num2 = stoi(s.substr(ind[1].position+1,s.size()-ind[1].position-1));
                result =num1*num2;

                int num3 = stoi(s.substr(0,ind[0].position));
                if(ind[0].type==1)
                {
                    result+=num3;
                }
                else if(ind[0].type==2)
                {
                    result=num3-result;
                }
                else
                {
                    result*=num3;
                }
                return result;
            }

        }
    }
    for(int i=0;i<2;i++)
    {
        int num0 = stoi(s.substr(0,ind[0].position));
        int num1 = stoi(s.substr(ind[0].position+1,ind[1].position-ind[0].position-1));
        int num2 = stoi(s.substr(ind[1].position+1,s.size()-ind[1].position-1));

        if(i==0)
        {
            if(ind[0].type==1)
            {
                result=num1+num0;
            }
            else if(ind[0].type==2)
            {
                result=num0-num1;
            }
            else
            {
                result=num0*num1;
            }
        }
        if(i==1)
        {

            if(ind[1].type==1)
            {
                result+=num2;
            }
            else if(ind[1].type==2)
            {
                result-=num2;
            }
            else
            {
                result*=num2;
            }

        }

    }
    return result;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        int result;
        result =compute(s);
        cout<<result<<endl;
    }
    return 0;
}
