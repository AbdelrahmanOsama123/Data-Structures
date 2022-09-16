#include <iostream>

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

node*buildTree(int*in,int*pre,int Start,int End)
{
    static int preIndex = 0;
    if(Start>End )
        return NULL;
    node*Root =CreateNode(pre[preIndex]);
    preIndex++;
    if(Start==End)
        return Root;
    int i;
    for(i=Start;i<=End;++i)
        if(in[i]==Root->data)
            break;
    Root->left  = buildTree(in,pre,Start,i-1);
    Root->right = buildTree(in,pre,i+1,End);
    return Root;
}

int checkPostOrder(node*curr,int*postOrder,int postIndex)
{
    if(curr==NULL)
        return postIndex;
    postIndex = checkPostOrder(curr->left,postOrder,postIndex);
    postIndex = checkPostOrder(curr->right,postOrder,postIndex);
    if(curr->data == postOrder[postIndex])
    {
        postIndex++;
    }
    else
        return -1;
    return postIndex;
}
void printpostOrder(node*curr)
{
    if(curr==NULL)
        return ;
    printpostOrder(curr->left);
    printpostOrder(curr->right);
    cout<<curr->data<<" ";
}
int main()
{
    int inOrder[] = {4, 2, 5, 1, 3};
    int preOrder[] = {1, 2, 4, 5, 3};
    int postOrder[] = {4, 5, 2,3,5};

    int len = sizeof(inOrder)/sizeof(inOrder[0]);

    node *Root = buildTree(inOrder, preOrder, 0, len - 1);

    int index = checkPostOrder(Root,postOrder,0);
    if(index == len)
        cout<<"yes"<<endl;
    else
        cout<<"No "<<endl;

    printpostOrder(Root);
 //   int index = checkPostorder(root,postOrder,0);

    // If both postorder traversals are same
  /*  if (index == len)
        cout << "Yes";
    else
        cout << "No";*/
    return 0;
}
