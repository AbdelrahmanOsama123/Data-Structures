#include <iostream>
#include <queue>
using namespace std;
struct node
{
    string data;
    node*left;
    node*right;
};
node*root ;
node* createNode(string data)
{
    node*newnode = new node();
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
node* insert_node(node*root ,string value)
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
void print_level_order()
{
    if(root==NULL)
    {
        return ;
    }
    queue<node*>q;
    q.push(root);

    while(!q.empty())
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
    }
}
void print_pre_order(node*curr)
{
    if(curr==NULL)
        return ;
    cout<<curr->data<<" ";
    print_pre_order(curr->left);
    print_pre_order(curr->right);

}
void print_post_order(node*curr)
{
    if(curr==NULL)
    {
       return ;
    }
    print_post_order(curr->left);
    print_post_order(curr->right);
    cout<<curr->data<<" ";
}
void print_paths_recursion(node*root)
{
    if(root==NULL)
        return ;
    cout<<root->data<<" ";
    if(root->left!=NULL)
    {
        print_paths_recursion(root->left);
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
bool Search(node*curr,string data)
{
    if(curr==NULL)
        return false;
    if(curr->data==data)
        return true;
    bool currLeft  = Search(curr->left,data);
    bool currRight = Search(curr->right,data);
    return currLeft || currRight ;
}
void delete_all_node(node*curr)
{
    if(curr==NULL)
        return ;
    delete_all_node(curr->left);
    delete_all_node(curr->right);
    delete (curr);
}
int convertToInt(string data)
{
    int num = 0;
    for(int i=0;i<data.size();++i)
    {
        num = num*10 + int(data[i]-'0');
    }
    return num;
}
int Evaluation(node*curr)
{
    if(curr==NULL)
        return 0;
    if(curr->left==NULL && curr->right ==NULL)
        return convertToInt(curr->data);
    if(curr->data =="*")
    {
        return Evaluation(curr->left) * Evaluation(curr->right);
    }
    if(curr->data =="/")
    {
        return Evaluation(curr->left) / Evaluation(curr->right);
    }
    if(curr->data =="-")
    {
        return Evaluation(curr->left) - Evaluation(curr->right);
    }
    if(curr->data =="+")
    {
        return Evaluation(curr->left) + Evaluation(curr->right);
    }
    return -1;
}
int main()
{
    root = createNode("+");
    root -> left = createNode("*");
    root ->left->left= createNode("5");
    root ->left->right= createNode("4");
    root ->right = createNode("-");
    root->right->left = createNode("100");
    root->right->right= createNode("/");
    root->right->right->left= createNode("20");
    root->right->right->right= createNode("2");
    cout<<"In_Order Traverse  "<<endl;
    Print_In_Order(root);
    cout<<'\n';
    cout<<"-------------------------"<<endl;
    cout<<"Pre_Order Traverse  "<<endl;
    print_pre_order(root);
    cout<<'\n';
    cout<<"-------------------------"<<endl;
    cout<<"Post_Order Traverse  "<<endl;
    print_post_order(root);
    cout<<'\n';
    cout<<"-------------------------"<<endl;
    cout<<"Level_Order Traverse  "<<endl;
    print_level_order();
    cout<<'\n';
    cout<<"-------------------------"<<endl;
  /*  if(Search(root,12))
        cout<<"12 is found"<<endl;
    else
        cout<<"12 is not found "<<endl;
    int sum = 8;
    */
    cout<<endl<<Evaluation(root)<<endl;
    delete_all_node(root);
    cout<<"-------------------------"<<endl;
    cout<<"Binary search now is empty ";
    return 0;
}
