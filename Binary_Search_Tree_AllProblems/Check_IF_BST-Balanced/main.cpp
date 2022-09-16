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
int Height_Calculation(node*curr)
{
    if(curr==NULL)
        return 0;
    return 1 +max(Height_Calculation(curr->left),Height_Calculation(curr->right));
}
bool Is_Balanced(node*curr)
{
    if(curr==NULL)
        return true;
    int left_height = Height_Calculation(curr->left);
    int right_height = Height_Calculation(curr->right);
    return abs(left_height-right_height)<=1
       &&Is_Balanced(curr->left)
       &&Is_Balanced(curr->right);
}
int main()
{
    root = insert_node(root,11);
    root = insert_node(root,9);
    root = insert_node(root,8);
    root = insert_node(root,5);
    root = insert_node(root,12);
    root = insert_node(root,13);
    root = insert_node(root,14);
    root = insert_node(root,10);

    if(Is_Balanced(root))
        cout<<"BST is Balanced"<<endl;
    else
        cout<<"BST isn't Balanced"<<endl;
    return 0;
}
