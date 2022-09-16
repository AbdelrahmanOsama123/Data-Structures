#include <iostream>
#include <queue>
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
node* insert_node(node*root ,int value)
{
    if(root==NULL)
    {
        root=createNode(value);
        return root;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node*curr = q.front();
        q.pop();
        if(curr->left==NULL)
        {
            curr->left = createNode(value);
            return curr->left;
        }
        else if(curr->right==NULL)
        {
            curr->right =createNode(value);
            return curr->right;
        }
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->left!=NULL)
            q.push(curr->right);
    }
}
void Print_In_Order(node*curr)
{
    if(curr==NULL)
    {
        return ;
    }
    Print_In_Order(curr->left);
    cout<<curr->data<<" ";
    Print_In_Order(curr->right);
}
void print_level_order_Line_BY_Line()
{
    if(root==NULL)
    {
        return ;
    }
    queue<node*>q;
    q.push(root);
    int Count = q.size();
    while(Count>0)
    {
        while(Count>0)
        {
            node*temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
            Count--;
        }
        cout<<endl;
        Count=q.size();
    }
}
int main()
{
    root = createNode(3);
    root -> left = createNode(1);
    root ->left->left= createNode(5);
    root ->left->right= createNode(12);
    root ->right = createNode(10);
    root->right->left = createNode(15);
    root->right->right= createNode(8);
    cout<<"Binary tree values "<<endl;
    Print_In_Order(root);
    cout<<endl<<"--------------------------------------------------------------"<<endl;
    cout<<"Binary tree values after print level order line by line :"<<endl;
    cout<<"-------------------------------------"<<endl;
    print_level_order_Line_BY_Line();
    return 0;
}
