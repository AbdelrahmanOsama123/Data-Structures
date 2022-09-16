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

void Print_In_Order(node*curr)
{
    if(curr==NULL)
        return ;
    Print_In_Order(curr->left);
    cout<<curr->data<<" ";
    Print_In_Order(curr->right);
}
bool has_path_sum(node*curr,int sum)
{
    if(curr==NULL)
        return sum==0;
    bool path_sum_left = has_path_sum(curr->left,sum-curr->data);
    bool path_sum_right = has_path_sum(curr->right,sum-curr->data);
    return path_sum_left||path_sum_right;
}
int main()
{
    root = createNode(1);
    root -> left = createNode(2);
    root ->left->left= createNode(5);
    root ->left->right= createNode(9);
    root ->right = createNode(7);
    root->right->left = createNode(10);
    root->right->right= createNode(8);

    int sum = 12;
    if(has_path_sum(root,sum))
        cout<<"Binary tree has path sum equal the sum "<<endl;
    else
        cout<<"Binary tree hasn't path sum equal the sum "<<endl;
    return 0;
}
