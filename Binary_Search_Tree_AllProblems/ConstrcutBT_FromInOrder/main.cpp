#include <iostream>

using namespace std;
struct node
{
    int data;
    node*left;
    node*right;
};
node*createNode(int data)
{
    node*newnode = new node();
    newnode->data = data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void printInorder (node*curr)
{
    if(curr==NULL)
        return ;
    printInorder(curr->left);
    cout<<curr->data<<" ";
    printInorder(curr->right);
}
int maximumIndex(int arr[],int Start,int End)
{
    int Max= arr[Start] , MaxIndex = Start ;
    for(int i=Start+1;i<=End;++i)
    {
        if(arr[i]>Max)
            MaxIndex=i;
    }
    return MaxIndex;
}
node*constructBST(int *inOrder,int Start,int End)
{
    if(Start>End)
        return NULL;
    int MaxIndex = maximumIndex(inOrder,Start,End);
    node*Root = createNode(inOrder[MaxIndex]);
    if(Start==End)
        return Root;

    Root->left = constructBST (inOrder,Start,MaxIndex-1);
    Root->right = constructBST (inOrder,MaxIndex+1,End);
    return Root;
}
int main()
{
    int inorder[] = {1, 5, 10, 40, 30, 15, 28, 20};
    int n = sizeof(inorder)/sizeof(inorder[0]);
    node *Root = constructBST(inorder, 0 , n-1 );

    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(Root);
    return 0;
}
