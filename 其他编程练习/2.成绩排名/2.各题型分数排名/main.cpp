#include<bits/stdc++.h>
using namespace std;

class Student{
public:
    string id;
    void compute()
    {
        sum = grade_1+grade_2+grade_3;
    }
    int grade_1;
    int grade_2;
    int grade_3;
    int sum;
};

bool compare(Student s1,Student s2)
{
    if(s1.sum==s2.sum)
    {
        if(s1.grade_3==s2.grade_3)
        {
            if(s1.grade_2==s2.grade_2)
            {
                if(s1.grade_1==s2.grade_1)
                {
                    return s1.id<s2.id;
                }
                return s1.grade_1>s2.grade_1;
            }
            return s1.grade_2>s2.grade_2;
        }
        return s1.grade_3>s2.grade_3;
    }
    return s1.sum>s2.sum;
}

int main()
{
    int n;
    cin>>n;
    vector<Student>st(n);
    for(int i=0;i<n;i++)
    {
        cin>>st[i].id;
        cin>>st[i].grade_1>>st[i].grade_2>>st[i].grade_3;
        st[i].compute();
    }
    sort(st.begin(),st.end(),compare);
    int index =0;
    for(int i=0;i<n;i++)
    {
        if(st[i].grade_1>=80&&st[i].grade_2>=80&&st[i].grade_3>=80)
        {
            cout<<st[i].id<<" "<<st[i].sum<<endl;
            index =1;
        }
    }
    if(index ==0)
    {
        cout<<"NULL";
    }
    return 0;
}
