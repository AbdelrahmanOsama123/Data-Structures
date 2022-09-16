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
void printInorder(node*curr)
{
    if(curr==NULL)
        return ;
    printInorder(curr->left);
    cout<<curr->data<<" ";
    printInorder(curr->right);
}
node*constructBSTUtill(int *pre,int *preIndex,int Start,int End,int Size)
{
    if(Start>End || *preIndex >= Size)
        return NULL;
    node*Root = createNode(pre[*preIndex]);
    *preIndex = *preIndex + 1;
    if(Start==End)
        return Root;
    int i;
    for(i=Start;i<=End;++i)
    {
        if(pre[i]>Root->data)
            break;
    }
    Root->left = constructBSTUtill (pre,preIndex,*preIndex,i-1,Size);
    Root->right = constructBSTUtill(pre,preIndex,i,End,Size);
    return Root;
}
node * constructBST(int pre[],int n)
{
    int preIndex = 0;
    return constructBSTUtill(pre,&preIndex,0,n-1,n);
}
int main()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int n = sizeof(pre)/sizeof(pre[0]);
    node *root = constructBST(pre, n );

    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);
    return 0;
}
