#include <iostream>

using namespace std;
struct node
{
    int data;
    node*left;
    node*right;
};
node*root ;
node* createNode(int data)
{
    node*newnode = new node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
int Min_Depth_value(node*curr)
{
    if(curr==NULL)
        return 0;
    return 1+min(Min_Depth_value(curr->left),Min_Depth_value(curr->right));
}

void Find_Full_Nodes(node*curr)
{
    if(curr==NULL)
        return ;
    if(curr->left!=NULL && curr->right!=NULL)
        cout<<curr->data<<" ";
    Find_Full_Nodes(curr->left);
    Find_Full_Nodes(curr->right);
}
int main()
{
    root = createNode(3);
    root -> left = createNode(1);
    root ->left->left= createNode(5);
    root->left->left->left = createNode(11);
    root ->left->right= createNode(12);
    root->right = createNode(10);
    root->right->left= createNode(15);

    cout<<"The full nodes are : "<<endl;
    Find_Full_Nodes(root);

    return 0;
}
