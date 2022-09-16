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

void Find_nth_node_PreOrder(node*curr,int nth)
{
    static int Count = 0;
    if(curr==NULL)
        return ;
    if(Count<=nth)
    {
        Count++;
        if(Count==nth)
            cout <<curr->data<<" ";
        Find_nth_node_PreOrder(curr->left,nth);
        Find_nth_node_PreOrder(curr->right,nth);
    }
}
int main()
{
    root = createNode(5);
    root -> left = createNode(1);
    root ->left->left = createNode(3);
    root ->left->right = createNode(4);
    root ->right = createNode(10);
    root->right->left = createNode(9);
    root->right->right = createNode(11);

    int n = 5;
    cout << "The nth node ==> " ;
    Find_nth_node_PreOrder(root,n);
    return 0;
}
