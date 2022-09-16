#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int data;
    node*left;
    node*right;
    int height;
};
node*root;
node*newNode(int value)
{
    node*newnode = new node();
    newnode->data= value;
    return newnode;
}
void print_inOrder(node*curr)
{
    if(curr==NULL)
        return ;
    print_inOrder(curr->left);
    cout<<curr->data<<" ";
    print_inOrder(curr->right);
}
void StoreAVLTree_ToVector(node*curr,vector<int>&vec)
{
    if(curr==NULL)
        return ;
    StoreAVLTree_ToVector(curr->left,vec);
    vec.push_back(curr->data);
    StoreAVLTree_ToVector(curr->right,vec);
}
bool isPairPresent(node*curr,int targetSum)
{
    vector<int>vec;
    StoreAVLTree_ToVector(curr,vec);
    int start = 0;
    int End = vec.size()-1;
    while(start<End)
    {
        if(vec[start] + vec[End] == targetSum)
        {
            cout<<"Part found: " <<vec[start]<<" + "<<vec[End] << " = "<<targetSum;
            return true;
        }
        if(vec[start] + vec[End] > targetSum)
        {
            End--;
        }
        if(vec[start] + vec[End] < targetSum)
        {
            start++;
        }
    }
    cout<<"pair is not found "<<endl;
    return false;
}
int main()
{
    node *root = newNode(15);
    root->left  = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(8);
    root->left->right = newNode(12);
    root->right->left = newNode(16);
    root->right->right = newNode(25);

    isPairPresent(root,30);
    return 0;
}
