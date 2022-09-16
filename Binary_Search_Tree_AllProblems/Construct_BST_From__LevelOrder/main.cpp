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
node* LevelOrder(node*curr,int data)
{
    if(curr==NULL)
    {
        curr = CreateNode(data);
        return curr;
    }
    if(data<=curr->data)
    {
        curr->left = LevelOrder(curr->left,data);
    }
    else if(data>curr->data)
    {
        curr->right = LevelOrder(curr->right,data);
    }
    return curr;
}
node*construct_Bst_LevelOrder(int*levelOrder,int Size)
{
    if(Size==0)
        return NULL;
    node*Root;
    for(int i=0;i<Size;++i)
        Root=LevelOrder(Root,levelOrder[i]);
    return Root;
}
int main()
{
     int LevelOrder[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
     int n = sizeof(LevelOrder) / sizeof(LevelOrder[0]);
     root = construct_Bst_LevelOrder(LevelOrder, n);
    cout << "Constructed BST values By InOrder Traverse "<<endl;
    Print_In_Order(root);
    return 0;
}
