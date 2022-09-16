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
int Min_Path_Sum(node*curr)
{
    if(curr==NULL)
        return 0 ;
    int Sum_Left_Path  =  Min_Path_Sum(curr->left);
    int Sum_Right_Path  = Min_Path_Sum(curr->right);
    return curr->data + min(Sum_Left_Path,Sum_Right_Path) ;
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

    cout<<"Min Path Summation ==> "<<Min_Path_Sum(root);
    return 0;
}
