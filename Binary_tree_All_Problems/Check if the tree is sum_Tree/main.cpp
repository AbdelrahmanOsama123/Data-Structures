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
int Nodes_Sum(node*curr)
{
    if(curr==NULL)
        return 0;

    return curr->data + Nodes_Sum(curr->left) + Nodes_Sum(curr->right);
}
bool Is_Sum_Tree(node*curr)
{
    if(curr==NULL)
        return true;
    if(curr->left ==NULL && curr->right==NULL)
        return true;
    int Left_Sum = Nodes_Sum(curr->left);
    int Right_Sum = Nodes_Sum(curr->right);
    return (curr->data == Left_Sum + Right_Sum) && Is_Sum_Tree(curr->left) && Is_Sum_Tree(curr->right);
}
int main()
{
    root = createNode(204);
    root -> left = createNode(29);
    root ->left->left= createNode(10);
    root ->left->right= createNode(19);
    root ->right = createNode(73);
    root->right->left = createNode(31);
    root->right->right= createNode(42);

    if(Is_Sum_Tree(root))
        cout<<"Binary tree is Sum Tree "<<endl;
    else
        cout<<"Binary tree isn't Sum Tree "<<endl;
    return 0;
}
