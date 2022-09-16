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
void preOrder(node*curr)
{
    if(curr==NULL)
        return ;
    cout<<curr->data<<" ";
    preOrder(curr->left);
    preOrder(curr->right);
}
node*buildTreeUtill(int*in , int*post,int Start,int End,int &PostIndex)
{
    if(Start>End || PostIndex < 0 )
        return NULL;
    node*Root = createNode(post[PostIndex]);
    PostIndex--;
    if(Start==End)
        return Root;
    int i;
    for(i=Start;i<=End;++i)
        if(in[i]==Root->data)
            break;
    Root->right = buildTreeUtill(in , post,i+1,End,PostIndex);
    Root->left = buildTreeUtill(in , post,Start,i-1,PostIndex);
    return Root;
}
node* buildTree(int *in, int*post, int n)
{
    int postIndex = n - 1;
    return buildTreeUtill(in,post,0,n-1,postIndex);
}
int main()
{
    int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 };
    int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 };
    int n = sizeof(in) / sizeof(in[0]);

    node* Root = buildTree(in, post, n);

    cout << "Preorder of the constructed tree : \n";
    preOrder(Root);

    return 0;
}
