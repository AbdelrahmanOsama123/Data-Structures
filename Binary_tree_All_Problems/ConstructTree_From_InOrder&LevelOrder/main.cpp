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
int Search(int *inOrder,int Start,int End,int value)
{
    for(int i=Start;i<=End;++i)
    {
        if(inOrder[i]==value)
            return i;
    }
    return -1;
}
int *extractValues(int inOrder[],int level[],int Index,int n)
{
    int * newLevel = new int [Index];
    int j=0;
    for(int i=0;i<n;++i)
    {
        if(Search(inOrder,0,Index-1,level[i])!=-1)
        {
            newLevel[j] = level[i] ,
            j++;
        }
    }
    return newLevel;
}
node*buildTree(int inOrder[],int LevelOrder[],int Start,int End,int n)
{
    if(Start>End)
        return NULL;
    node*Root = createNode(LevelOrder[0]);
    if(Start==End)
        return Root;
    int currNodeIndex = Search(inOrder,Start,End,Root->data);
    int *LeftSubtree = extractValues(inOrder,LevelOrder,currNodeIndex,n);
    int *RightSubtree = extractValues(inOrder+currNodeIndex+1,LevelOrder,n-1,n);

    Root->left = buildTree(inOrder , LeftSubtree , Start,currNodeIndex-1,currNodeIndex-Start);
    Root->right = buildTree(inOrder ,RightSubtree ,currNodeIndex+1,End,End-currNodeIndex);

    return Root;
}
void Print_In_Order(node*curr)
{
    if(curr==NULL)
        return ;
    Print_In_Order(curr->left);
    cout<<curr->data<<" ";
    Print_In_Order(curr->right);
}
int main()
{
    int in[] = { 4, 8, 10, 12, 14, 20, 22 };
    int level[] = { 20, 8, 22, 4, 12, 10, 14 };
    int n = sizeof(in) / sizeof(in[0]);
    node* root = buildTree(in, level,0, n - 1, n);

    cout << "Inorder traversal of the constructed tree is "
            "\n";
    Print_In_Order(root);

    return 0;
}
