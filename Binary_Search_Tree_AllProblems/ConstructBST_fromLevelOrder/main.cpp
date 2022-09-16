#include <iostream>

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
node*insert_node(node*curr,int data)
{
    if(curr==NULL)
        return createNode(data);
    if(data<curr->data)
        curr->left = insert_node(curr->left,data);
    if(data>curr->data)
        curr->right = insert_node(curr->right,data);
    return curr;
}
void inorderTraversal(node*curr)
{
    if(curr==NULL)
        return ;
    inorderTraversal(curr->left);
    cout<<curr->data<<" ";
    inorderTraversal(curr->right);
}
node*constructBst(int arr[],int n)
{   if(n==0)
        return NULL;
    node*Root = NULL ;
    for(int i=0;i<n;++i)
    {
        Root = insert_node(Root,arr[i]);
    }
    return Root;
}
int main()
{
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    node *root = constructBst(arr, n);

    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    return 0;
}
