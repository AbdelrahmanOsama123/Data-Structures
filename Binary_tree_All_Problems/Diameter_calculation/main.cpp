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
int Min_Depth_value(node*curr)
{
    if(curr==NULL)
        return 0;
    return 1+min(Min_Depth_value(curr->left),Min_Depth_value(curr->right));
}
int Height(node*curr)
{
    if(curr==NULL)
        return 0;
    return 1 +max(Height(curr->left),Height(curr->right));
}
int Diameter(node*curr)
{
    if(curr==NULL)
        return 0;
    int left_diameter = Diameter(curr->left);
    int right_diameter = Diameter(curr->right);
    return max(Height(curr->left)+Height(curr->right)+1,max(left_diameter,right_diameter));
}
int main()
{
    root = createNode(3);
    root -> left = createNode(1);
    root ->left->left= createNode(5);
    root->left->left->left = createNode(11);
    root ->left->right= createNode(12);
    root ->right = createNode(10);
    root->right->left = createNode(15);
    root ->right->left->left = createNode(13);
    cout<<"Diameter ==> "<<Diameter(root);

    return 0;
}

