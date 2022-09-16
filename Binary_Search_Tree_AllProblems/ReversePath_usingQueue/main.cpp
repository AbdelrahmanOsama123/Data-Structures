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
void inorder(node*curr)
{
    if(curr==NULL)
        return ;
    inorder(curr->left);
    cout<<curr->data<<" ";
    inorder(curr->right);
}

void reversePath(node*curr,int k,queue<int>&q)
{

}
int main()
{
    queue<int> q1;
    int k = 80;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);

    cout << "Before Reverse :" << endl;
    inorder(root);
    cout << "\n";
    reversePath(root, k, q1);
    cout << "After Reverse :" << endl;
    inorder(root);
    return 0;
}
