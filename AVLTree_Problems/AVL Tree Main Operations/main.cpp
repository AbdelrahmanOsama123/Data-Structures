#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int data;
    node*left;
    node*right;
    int height;
};
node*root;
int height(node*curr)
{
    if(curr==NULL)
        return 0;
    return curr->height;
}
int getBalance(node*curr)
{
    if(curr==NULL)
        return 0;
    return height(curr->left) - height(curr->right);
}
node *leftRotate(node *x) { // O(1)

    if (x == NULL || x->right == NULL)
        return NULL;

    node *y = x->right;
    node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}
node* rightRotate(node *y) {

    if (y == NULL || y->left == NULL)
        return NULL;

    node *x = y->left;
    node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}
node* insert_node (node* curr, int new_data) {

    if (curr == NULL) {
        node* new_node = new node();
        new_node->data = new_data;
        new_node->height = 1;
        return new_node;
    }

    if (new_data < curr->data)
        curr->left  = insert_node(curr->left, new_data);
    else if (new_data > curr->data)
        curr->right = insert_node(curr->right, new_data);

    else
        return curr;

    curr->height = 1 + max(height(curr->left), height(curr->right));
    int balance = getBalance(curr);

    if (balance > 1 && new_data < curr->left->data)
        return rightRotate(curr);

    if (balance < -1 && new_data > curr->right->data)
        return leftRotate(curr);

    if (balance > 1 && new_data > curr->left->data) {
        curr->left =  leftRotate(curr->left);
        return rightRotate(curr);
    }
    if (balance < -1 && new_data < curr->right->data) {
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }

    return curr;
}
node* max_node_value(node*curr)
{
    node*result = curr;
    while(curr->right!=NULL)
    {
        result= result->right;
    }
    return result;
}
node*deleteNode(node*curr , int data)
{
    if(curr==NULL)
        return curr;
    if(data < curr->data)
        curr->left = deleteNode(curr->left,data);
    else if(data > curr->data)
        curr->right = deleteNode(curr->right,data);
    else
    {
        if(curr->left ==NULL && curr->right==NULL)
        {
            node*temp = curr;
            curr=NULL;
            delete(temp);
        }
        else if(curr->left ==NULL)
        {
            node*temp = curr->right;
            curr=temp;
            delete(temp);
        }
        else if(curr->right ==NULL)
        {
            node*temp = curr->left;
            curr=temp;
            delete(temp);
        }
        else
        {
            node*temp = max_node_value(curr->left);
            curr->data = temp->data;
            curr->left = deleteNode(curr->left,temp->data);
        }
    }
    if(curr==NULL)
        return curr;

    curr->height = max(height(curr->left),height(curr->right))+1;
    int balance = getBalance(curr);

    if(balance < -1 && getBalance(curr->right)<=0)
    {
        return leftRotate(curr);
    }
    else if(balance > 1 && getBalance(curr->left) >=0)
    {
        return rightRotate(curr);
    }
    else if(balance > 1 && getBalance(curr->left)<0)
    {
        curr->left = leftRotate(curr->left);
        return rightRotate(curr);
    }
    else if(balance < -1 && getBalance(curr->right)>0)
    {
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }
    return curr;
}
void print_preOrder(node*curr)
{
    if(curr==NULL)
        return ;
    cout<<curr->data<<" ";
    print_preOrder(curr->left);
    print_preOrder(curr->right);
}
int main()
{
    root = insert_node(root,10);
    root = insert_node(root,7);
    root = insert_node(root,4);
    root = insert_node(root,8);
    root = insert_node(root,11);

    print_preOrder(root);
    return 0;
}
