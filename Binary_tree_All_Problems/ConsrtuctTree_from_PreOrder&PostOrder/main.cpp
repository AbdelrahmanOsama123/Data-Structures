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
node*constructTreeUtill(int *pre,int *post,int &preIndex,int Start,int End,int Size)
{
    if(Start>End || preIndex >= Size)
        return NULL;
    node*Root = createNode(pre[preIndex]);
    preIndex++;
    if(Start==End)
        return Root;
    int i;
    for(i=Start;i<=End;++i)
    {
        if(pre[preIndex]==post[i])
            break;
    }
    if(i <= End)
    {
        Root->left = constructTreeUtill(pre,post,preIndex,Start,i,Size);
        Root->right = constructTreeUtill(pre,post,preIndex,i,End-1,Size);
    }
    return Root;
}
node *constructTree(int pre[],int post[],int Size)
{
    int preIndex = 0;
    return constructTreeUtill(pre,post,preIndex,0,Size-1,Size);
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
    int pre[] = { 1, 2, 4, 8, 9, 5, 3, 6, 7 };
    int post[] = { 8, 9, 4, 5, 2, 6, 7, 3, 1 };
    int Size = sizeof(pre) / sizeof(pre[0]);

    node* Root = constructTree(pre, post, Size);

    cout << "Inorder traversal of the constructed tree: \n";
    Print_In_Order(Root);
    return 0;
}
