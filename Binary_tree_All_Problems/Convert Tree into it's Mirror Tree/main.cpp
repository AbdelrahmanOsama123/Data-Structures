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
int Max_Path_Sum(node*curr)
{
    if(curr==NULL)
        return 0 ;
    int Sum_Left_Path  =  Max_Path_Sum(curr->left);
    int Sum_Right_Path  = Max_Path_Sum(curr->right);
    return curr->data + max(Sum_Left_Path,Sum_Right_Path) ;
}

void Print_In_Order(node*curr)
{
    if(curr==NULL)
        return ;
    Print_In_Order(curr->left);
    cout<<curr->data<<" ";
    Print_In_Order(curr->right);
}
void Mirror(node*curr)
{
    if(curr==NULL)
        return ;
    node*temp =curr->left;
    curr->left= curr->right;
    curr->right = temp;
    Mirror(curr->left);
    Mirror(curr->right);
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

    cout<<"Binary Tree Values Before Converting : "<<endl;
    Print_In_Order(root);
    cout<<endl<<"-------------------------------"<<endl;
    cout<<"Binary Tree Values after Converting to it's Mirror tree : "<<endl;
    Mirror(root);
    Print_In_Order(root);
    return 0;
}
