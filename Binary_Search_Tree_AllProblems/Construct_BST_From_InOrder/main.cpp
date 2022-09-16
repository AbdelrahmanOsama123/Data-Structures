#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int data;
    node*left;
    node*right;
};
node*root;
node*CreateNode(int data)
{
    node*newnode = new node();
    newnode->data = data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
node* insert_node(node*curr,int value)
{
    if(curr==NULL)
    {
        return CreateNode(value);
    }
    if(value<curr->data)
    {
        curr->left = insert_node(curr->left,value);
    }
    if(value>curr->data)
    {
        curr->right=insert_node(curr->right,value);
    }
    return curr;
}

void Print_In_Order(node*curr)
{
    if(curr==NULL)
    {
        return ;
    }
    Print_In_Order(curr->left);
    cout<<curr->data<<" ";
    Print_In_Order(curr->right);
}
int indexOfMax(int *InOrder,int Start,int End)
{
    int MaxNum = InOrder[Start];
    int MaxIndex = Start ;
    for(int i=Start+1;i<=End;++i)
    {
        if(InOrder[i]>MaxNum)
        {
            MaxNum=InOrder[i];
            MaxIndex = i;
        }
    }
    return MaxIndex ;
}
node* constructBST_InOrder(int *InOrder,int Start,int End)
{
    if(Start>End)
        return NULL;
    int MaxIndex = indexOfMax(InOrder,Start,End);
    node*Root = CreateNode(InOrder[MaxIndex]);
    if(Start==End)
        return Root;
    Root->left =  constructBST_InOrder(InOrder,Start,MaxIndex-1);
    Root->right = constructBST_InOrder(InOrder,MaxIndex+1,End);
    return Root;
}
int main()
{
    int inOrder[] = {5, 10, 40, 30, 28};
    int n = sizeof(inOrder)/sizeof(int);
    node*Root = constructBST_InOrder(inOrder,0,n-1);
    cout<<"Constructed BST values By InOrder Traverse :"<<endl;
    Print_In_Order(Root);
    return 0;
}
