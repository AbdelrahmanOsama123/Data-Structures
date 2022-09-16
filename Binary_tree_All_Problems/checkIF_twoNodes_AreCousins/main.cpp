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
bool isSiblings(node*curr,node*Node1,node*Node2)
{
    if(curr==NULL || (curr->left ==NULL && curr->right ==NULL))
        return false;

    return(curr->left == Node1 && curr->right == Node2 )
        ||(curr->left == Node2 && curr->right == Node1 )
        || isSiblings(curr->left,Node1,Node2)
        || isSiblings(curr->right,Node1,Node2);
}
int Level(node*curr,node*Node,int level)
{
    if(curr==NULL)
        return 0;
    if(curr==Node)
        return level;

    int left = Level(curr->left, Node, level+1);
    if(left!=0)
        return left;

    int right = Level(curr->right,Node, level+1);
    if(right!=0)
        return right;
}
bool isCousins(node*curr,node*Node1,node*Node2)
{
    if(Level(curr,Node1,1)==Level(curr,Node2,1) && isSiblings(curr,Node1,Node2))
        return true;
    else
        return false;
}
int main()
{
    node *root = CreateNode(12);
    root->left = CreateNode(5);
    root->left->left = CreateNode(3);
    root->left->right = CreateNode(9);
    root->right = CreateNode(10);
    root->right->left = CreateNode(11);
    root->right->right = CreateNode(12);
    root->left->left->left = CreateNode(7);
    root->left->left->right = CreateNode(8);
    node*Node1 = root->left->left;
    node*Node2 = root->left->left->left;

    cout<<Level(root,Node1,1)<<endl;
    if(isCousins(root,Node1,Node2))
        cout<<"Node1 && Node2 are Cousins \n"<<endl;
    else
        cout<<"Node1 && Node2 are not Cousins \n"<<endl;

        ///Node1 && Node2 are not cousins in this case
    return 0;
}
