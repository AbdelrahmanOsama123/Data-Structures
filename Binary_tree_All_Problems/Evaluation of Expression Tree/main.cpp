#include <iostream>

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

void Print_In_Order(node*curr)
{
    if(curr==NULL)
        return ;
    Print_In_Order(curr->left);
    cout<<curr->data<<" ";
    Print_In_Order(curr->right);
}
int convert_to_Int(string s)
{
    int num = 0;
    for(int i=0;i<s.size();++i)
    {
        num = num*10 + int(s[i]-'0');
    }
    return num;
}
int Evaluation_Expression(node*curr)
{
    if(curr==NULL)
        return 0;
    if(curr->left==NULL && curr->right==NULL)
        return convert_to_Int(curr->data);
    int left = Evaluation_Expression(curr->left);
    int right = Evaluation_Expression(curr->right);
    if(curr->data=="*")
        return left*right;
    if(curr->data=="/")
        return left/right;
    if(curr->data=="+")
        return left+right;
    if(curr->data=="-")
        return left-right;

}
int main()
{
    root = createNode("+");
    root -> left = createNode("*");
    root ->left->left = createNode("5");
    root ->left->right = createNode("4");
    root ->right = createNode("-");
    root->right->left = createNode("100");
    root->right->right = createNode("/");
    root->right->right->right = createNode("2");
    root->right->right->left = createNode("20");

    cout << "The evaluation Expression ==> "<<Evaluation_Expression(root);
    return 0;
}
