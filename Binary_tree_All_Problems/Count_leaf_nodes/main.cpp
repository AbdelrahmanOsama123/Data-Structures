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
int leafNodes_count(node*curr)
{
    if(curr==NULL)
        return 0 ;
    if(curr->left==NULL && curr->right == NULL)
        return 1 ;
    return leafNodes_count(curr->left)+leafNodes_count(curr->right);
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

    cout<<"leaf Nodes count ==> "<<leafNodes_count(root);
    return 0;
}
