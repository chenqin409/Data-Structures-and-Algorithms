#include <iostream>
#include<string>
using namespace std;

class node{
public:
	node(char data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
	char data;
	node* left;
	node* right;
};

node* BuildTree(string mid,int m_left,int m_right,  string post,int p_left,int p_right)
{
	if(m_left>=m_right) return NULL;
	node* Node = new node(post[p_right-1]);
	int position =m_left;
	while(mid[position]!= post[p_right-1]) position++;
	int left_length = position - m_left;
	Node->left = BuildTree(mid,m_left,m_left+left_length,post,p_left,p_left+left_length);
	Node->right = BuildTree(mid,m_left+left_length+1,m_right,  post,p_left+left_length,p_right-1);
	return Node;
}

void Print_pro(node *Node)
{
	if(Node == NULL) return;
	cout<<Node->data;
	Print_pro(Node->left);
	Print_pro(Node->right);
}
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string mid,post;
		cin>>mid;
		cin>>post;
		node* Node = BuildTree(mid,0,mid.size(),post,0,post.size());
		Print_pro(Node);
		cout<<endl;
	}
	return 0;
}
