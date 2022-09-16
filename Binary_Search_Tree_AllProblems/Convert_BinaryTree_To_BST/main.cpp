#include <iostream>
#include <algorithm>
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
void Print_In_Order(node*curr)
{
    if(curr==NULL)
    {
        return ;
    }
    Print_In_Order(curr->left);
    cout<<curr->data<<" ";
    Print_In_Order(curr->right);
}
int nodes_count(node*curr)
{
    if(curr==NULL)
        return 0 ;
    return 1+ nodes_count(curr->left)+nodes_count(curr->right);
}
void Store_inArray_PreOrder(node*curr,int*BS_Arr)
{
    static int Count = 0;
    if(curr==NULL)
        return ;
    BS_Arr[Count] = curr->data;
    Count++;
    Store_inArray_PreOrder(curr->left,BS_Arr);
    Store_inArray_PreOrder(curr->right,BS_Arr);
}
void Store_Array_InOrder_inBST(node*curr,int *BS_Arr)
{
    static int Count = 0;
    if(curr==NULL)
        return ;
    Store_Array_InOrder_inBST(curr->left,BS_Arr);
    curr->data = BS_Arr[Count];
    Count++;
    Store_Array_InOrder_inBST(curr->right,BS_Arr);
}
void Convert_BinaryTree_To_BST(node*curr)
{
    int Size = nodes_count(root);
    int *BS_Arr = new int [Size];
    Store_inArray_PreOrder(curr,BS_Arr);
    sort(BS_Arr,BS_Arr+Size);
    Store_Array_InOrder_inBST(curr,BS_Arr);
}
int main()
{
    root = createNode(10);
    root->left = createNode(30);
    root->right = createNode(15);
    root->left->left = createNode(20);
    root->right->right = createNode(5);

    cout<<"Binary Tree Values Before Converting to BST :"<<endl;
    Print_In_Order(root);
    cout<<"---------------------------------------------"<<endl;
     Convert_BinaryTree_To_BST(root);
    cout<<"\nBinary Tree Values Before Converting to BST :"<<endl;
    Print_In_Order(root);
    return 0;
}
