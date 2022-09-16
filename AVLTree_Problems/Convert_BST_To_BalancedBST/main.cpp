#include <iostream>
#include <cmath>
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

}
void storeBST_ToVector(node*curr,vector<node*>&nodes)
{
    if(curr==NULL)
        return ;
    storeBST_ToVector(curr->left,nodes);
    nodes.push_back(curr);
    storeBST_ToVector(curr->right,nodes);
}
node* BuildBalancedTree(vector<node*>&nodes,int Start,int End)
{
    if(Start>End)
        return NULL;
    int mid = (Start+End)/2;
    node*Root = nodes[mid];
    Root->left = BuildBalancedTree(nodes,Start,mid-1);
    Root->right = BuildBalancedTree(nodes,mid+1,End);
    return Root;
}
node* convertToBalancedBST(node*curr)
{
    vector<node*>nodes;
    storeBST_ToVector(curr,nodes);
    return BuildBalancedTree(nodes,0,nodes.size()-1);
}
void print_inOrder(node*curr)
{
    if(curr==NULL)
        return ;
    print_inOrder(curr->left);
    cout<<curr->data<<" ";
    print_inOrder(curr->right);
}
int main()
{
    root = insert_node(root,10);
    root = insert_node(root,9);
    root = insert_node(root,8);
    root = insert_node(root,4);
    root = insert_node(root,11);

    node*Root = convertToBalancedBST(root);
    print_inOrder(Root);
    return 0;
}
