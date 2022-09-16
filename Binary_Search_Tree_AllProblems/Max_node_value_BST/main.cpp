#include <iostream>
#include <queue>
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
int Max_node_value1(node*curr) //Recursion
{
    if(curr->right==NULL)
        return curr->data;
    if(curr->right!=NULL)
    {
        Max_node_value1(curr->right);
    }
}
int Max_node_value2(node*curr) // Iterative
{
    while(curr->right!=NULL)
        curr=curr->right;
    return curr->data;
}
int main()
{
    root = insert_node(root,10);
    root = insert_node(root,5);
    root = insert_node(root,35);
    root = insert_node(root,6);
    root = insert_node(root,30);
    root = insert_node(root,40);
    root = insert_node(root,8);

    cout<<"Max node value in BST ==> "<<Max_node_value1(root);
    return 0;
}
