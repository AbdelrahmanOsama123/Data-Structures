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

bool checkUtill(node*curr,int level,int &leaflevel)
{
    if(curr==NULL)
        return true;
    if(curr->left == NULL && curr->right ==NULL)
    {
        if(leaflevel == 0)
        {
            leaflevel = level;
            return true;
        }
        return level==leaflevel;
    }
    return checkUtill(curr->left,level+1,leaflevel) && checkUtill(curr->right,level+1,leaflevel);
}
bool check(node*curr)
{
    int level = 0 , leafLevel = 0;
    return checkUtill(curr,level,leafLevel);
}
int main()
{
    // Let us create tree shown in third example
    node *root = CreateNode(12);
    root->left = CreateNode(5);
    root->left->left = CreateNode(3);
    root->left->right = CreateNode(9);
    root->right = CreateNode(10);
    root->right->left = CreateNode(11);
    root->right->right = CreateNode(12);

    if (check(root))
        cout << "Leaves are at same level\n";
    else
        cout << "Leaves are not at same level\n";
    return 0;
}
