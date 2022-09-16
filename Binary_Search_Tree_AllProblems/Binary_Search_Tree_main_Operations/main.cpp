#include <iostream>
#include <queue>
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
node* insert_node(node*curr,int value)
{
    if(curr==NULL)
    {
        return CreateNode(value);
    }
    if(value<curr->data)
    {
        curr->left = insert_node(curr->left,value);
    }
    if(value>curr->data)
    {
        curr->right=insert_node(curr->right,value);
    }
    return curr;
}
node* minValueNode(node* curr)
{
    node* current = curr;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}
node*delete_node(node*curr,int data)
{
    if(curr==NULL)
        return curr;
    if(data<curr->data)
        curr->left=delete_node(curr->left,data);
    else if(data>curr->data)
        curr->right=delete_node(curr->right,data);
    else
    {
        if(curr->left == NULL && curr->right==NULL)
        {
            delete(curr);
            return NULL;
        }
        if(curr->left==NULL)
        {
            node*temp = curr->right;
            delete(curr);
            return temp;
        }
        if(curr->right==NULL)
        {
            node*temp=curr->left;
            delete(curr);
            return temp;
        }
        node*temp ;
        temp = minValueNode(curr->right);
        curr->data = temp->data;
        curr->right = delete_node(curr->right,temp->data);
    }
    return curr;
}
node*search_node(node*curr,int data)
{
    if(curr==NULL || curr->data==data )
    {
        return curr;
    }
    if(data<curr->data)
    {
        return search_node(curr->left,data);
    }
    else if(data>curr->data)
    {
        return search_node(curr->right,data);
    }
}
void print_level_order_LineBYLine(node*curr)
{
    if(curr==NULL)
        return ;
    queue<node*> q;
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
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
            Count--;
        }
        cout<<endl;
        Count=q.size();
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
void print_paths(node*curr,int *path,int pathnum)
{
    if(curr==NULL)
        return ;
    path[pathnum]=curr->data;
    pathnum++;
    if(curr->left==NULL && curr->right==NULL)
    {
        for(int i=0;i<pathnum;++i)
            cout<<path[i]<<" ";
        cout<<'\n';
    }
    else
    {
        print_paths(curr->left,path,pathnum);
        print_paths(curr->right,path,pathnum);
    }
}
void print_paths_recursion(node*curr)
{
    int Size=1e5;
    int path[Size];
    print_paths(curr,path,0);
}

int main()
{
    root = insert_node(root,10);
    root = insert_node(root,5);
    root = insert_node(root,1);
    root = insert_node(root,6);
    root = insert_node(root,19);
    root = insert_node(root,17);
    root = insert_node(root,8);

    delete_node(root,10);
    cout<<"Binary Search Values InOrder"<<endl;
    Print_In_Order(root);
    if(search_node(root,20)==NULL)
        cout<<"\n-------------------\nthe node is not found "<<endl;
    else
        cout<<"\n-------------------\nthe node is found "<<endl;
    print_level_order_LineBYLine(root);
    cout<<endl;
    print_paths_recursion(root);
    return 0;
}
