#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct node
{
    int data ;
    node*left;
    node*right;
};
node*root;
node* createNode(int data)
{
    node*newnode = new node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
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
void print_paths_recursion(node*curr,vector<int>path,int &path_count)
{
    if(curr==NULL)
        return ;
    path.push_back(curr->data);
    path_count++;

    if(curr->left == NULL && curr->right == NULL)
    {
        for(int i = 0;i<path_count;++i)
            cout<<path[i]<< " ";
        cout<<endl;
    }
    else
    {
        print_paths_recursion(curr->left,path,path_count);
        print_paths_recursion(curr->right,path,path_count);
    }
}
void print_paths()
{
    vector<int>path;
    int pathcount = 0;
    print_paths_recursion(root,path,pathcount);
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
    cout<<"Binary tree before printing each path in separate line "<<endl;
    Print_In_Order(root);
    cout<<endl<<"--------------------------------------------------------------"<<endl;
    cout<<"Binary tree after printing each path in separate line :"<<endl;
    print_paths();
    return 0;
}
