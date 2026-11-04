#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

class Student{
public:
	string m_Name;
	vector<int>Score;
	int avarage_Score; 
};

bool com(Student s1,Student s2)
{
	return s1.avarage_Score>s2.avarage_Score;
}
int main()
{
	int k,temp;
	cin>>k;
	vector<int>credit;
	for(int i=0;i<k;i++)
	{
		cin>>temp;
		credit.push_back(temp);
	}
	int N;
	cin>>N;
	string name;
	vector<Student>v(N);
	
	for(int i=0;i<N;i++)
	{
		cin>>name;
		v[i].m_Name = name;
		for(int j=0;j<k;j++)
		{
			cin>>temp;
			v[i].Score.push_back(temp);
		}
		temp=0;
		for(int j=0;j<k;j++)
		{
			temp+= v[i].Score[j]*credit[j];
		}
		v[i].avarage_Score = temp;
	}
	sort(v.begin(),v.end(),com);
	int num = (N+10 -1)/10;
	for(int i=0;i<num;i++)
	{
		cout<<v[i].m_Name<<endl;
	}
	return 0;
}
