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
node* Find_LCA(node*curr,node*node1,node*node2)
{
    if(curr==NULL)
        return NULL;
    if(curr->data < node1->data && curr->data < node2->data)
        return Find_LCA(curr->right,node1,node2);
    if(curr->data > node1->data && curr->data > node2->data)
        return Find_LCA(curr->left,node1,node2);
    return curr;
}

int main()
{
    root = insert_node(root,3);
    root = insert_node(root,5);
    root = insert_node(root,1);
    root = insert_node(root,6);
    root = insert_node(root,2);
    root = insert_node(root,0);
    root = insert_node(root,8);
    root = insert_node(root,7);
    root = insert_node(root,4);

    node*node1 = CreateNode(6);
    node*node2 = CreateNode(8);

    cout<<"BST LCA ==> " <<Find_LCA(root,node1,node2)->data;
    return 0;
}
