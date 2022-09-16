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
int Max_node_value(node*curr)
{
    if(curr->left==NULL && curr->right==NULL)
    {
        return curr->data ;
    }
    return max(curr->data,max(Max_node_value(curr->left),Max_node_value(curr->right)));
}
int main()
{
    root = createNode(3);
    root -> left = createNode(1);
    root ->left->left= createNode(5);
    root ->left->right= createNode(12);
    root ->right = createNode(10);
    root->right->left = createNode(15);
    root->right->right= createNode(8);

    cout<<"Max Node Value ==> "<<Max_node_value(root);
    return 0;
}
