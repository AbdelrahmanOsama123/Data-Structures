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
node*createNode(int data)
{
    node*newnode = new node();
    newnode->data = data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

bool Is_BST(node*curr)
{
    if(curr==NULL)
        return true;
    if(curr->left==NULL && curr->right==NULL)
        return true;
    int left_data,right_data;
    if(curr->left!=NULL)
         left_data = curr->left->data;
    if(curr->right!=NULL)
         right_data = curr->right->data;
    return (curr->data > left_data && curr->data < right_data && Is_BST(curr->left) && Is_BST(curr->right));

}
int main()
{
    root = createNode(10);
    root -> left = createNode(7);
    root ->left->left= createNode(6);
    root ->left->right= createNode(9);
    root ->right = createNode(13);
    root->right->left = createNode(11);
    root->right->right= createNode(14);

    if(Is_BST(root))
        cout<<"Binary Tree is BST"<<endl;
    else
        cout<<"Binary Tree isn't BST"<<endl;
    return 0;
}
