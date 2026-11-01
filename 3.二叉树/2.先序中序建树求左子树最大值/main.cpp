#include<bits/stdc++.h>
#include<vector>
using namespace std;
class Node{
public:
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
	int data;
	Node* left;
	Node* right;
};

//建树，区间是左闭右开 
Node* CreatTree(const vector<int>&pre,int pre_left,int pre_right,const vector<int>&ino,int ino_left,int ino_right)
{
	if(pre_left>=pre_right) return NULL;    
	int root_value=pre[pre_left]; 
	Node* node = new Node(root_value);
	int pos=ino_left;
	while(ino[pos]!= root_value) pos++;
	int left_size = pos-ino_left;
	node->left = CreatTree(pre, pre_left+1, pre_left+1+left_size,   ino, ino_left, ino_left+left_size);
	node->right = CreatTree(pre, pre_left+1+left_size, pre_right,   ino, ino_left+left_size+1, ino_right);
	return node;
}

Node* find(Node* node,int value)
{
	if(node==NULL) return NULL;
	if(node->data == value) return node;
	Node* left_node = find(node->left,value); 
	if(left_node!=NULL) return left_node;   //下一步的left_node通过return node找到了值，返回回去 
	return find(node->right,value);      //先找左边，找不到再来右边找 
}

int return_max(Node* node)
{
	if(node==NULL) return -1;
	int result = node->data;
	result=max(result,return_max(node->left));
	result=max(result,return_max(node->right));
	return result;
}

int main() {
	int n,temp,value;
	cin>>n;
	vector<int>pre;
	vector<int>ino;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		pre.push_back(temp);
	}
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		ino.push_back(temp);
	}
	cin>>value;
	Node* node = CreatTree(pre,0,n,ino,0,n);
	
	node = find(node,value);
	int target =-1;
	if(node==NULL) {
	}
	else if(node->left == NULL){
	}
	else
	{
		target = return_max(node->left);
	}
	cout<<target;
	return 0;
}
