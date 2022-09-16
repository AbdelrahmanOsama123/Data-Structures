#include <iostream>

using namespace std;
struct node
{
    char data;
    node*left;
    node*right;
};
node*root;
node*CreateNode(char data)
{
    node*newnode = new node();
    newnode->data = data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
node*buildTreeUtill(char*in,char*pre,int&preIndex,int Start,int End,int Size)
{
    if(Start>End || preIndex>=Size)
        return NULL;
    node*Root = CreateNode(pre[preIndex]);
    preIndex ++;
    if(Start==End)
        return Root;
    int i;
    for(i = Start;i<=End;++i)
        if(in[i]==Root->data)
            break;
    Root->left = buildTreeUtill(in,pre,preIndex,Start,i-1,Size);
    Root->right = buildTreeUtill(in,pre,preIndex,i+1,End,Size);
    return Root;
}
node*buildTree(char *in,char *pre,int Start,int End,int Size)
{
    int preIndex = 0;
    return buildTreeUtill(in,pre,preIndex,Start,End,Size);
}
void printInorder(node*curr)
{
    if(curr==NULL)
        return ;
    printInorder(curr->left);
    cout<<curr->data<<" ";
    printInorder(curr->right);
}
int main()
{
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);
    node* Root = buildTree(in, pre, 0, len - 1,len);

    /* Let us test the built tree by
    printing Inorder traversal */
    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(Root);
    return 0;
}
