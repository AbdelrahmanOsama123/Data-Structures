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
bool Is_Sum_Property(node*curr)
{
    if(curr==NULL)
        return true;
    if(curr->left ==NULL && curr->right == NULL )
        return true;
    int left_data = curr->left->data;
    int right_data = curr->right->data;
    return (curr->data == left_data+right_data) && Is_Sum_Property(curr->left) && Is_Sum_Property(curr->right);
}
int main()
{
    root = createNode(102);
    root -> left = createNode(29);
    root ->left->left= createNode(10);
    root ->left->right= createNode(19);
    root ->right = createNode(73);
    root->right->left = createNode(31);
    root->right->right= createNode(42);

    if(Is_Sum_Property(root))
        cout<<"Binary tree has sum property "<<endl;
    else
        cout<<"Binary tree hasn't sum property "<<endl;
    return 0;
}
