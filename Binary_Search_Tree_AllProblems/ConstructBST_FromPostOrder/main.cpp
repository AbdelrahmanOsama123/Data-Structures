#include <iostream>

using namespace std;
struct node
{
    int data;
    node*left;
    node*right;
};
node*createNode(int data)
{
    node*newnode = new node();
    newnode->data = data;
    newnode->left=newnode->right=NULL;
    return newnode;
}
void printInorder(node*curr)
{
    if(curr==NULL)
        return ;
    printInorder(curr->left);
    cout<<curr->data<<" ";
    printInorder(curr->right);
}
node*constructBstUtill(int *post,int *postIndex,int key,int Min,int Max,int Size)///O(n)
{
    if(*postIndex<0)
        return NULL;
    node*Root = NULL;
    if(key>Min && key< Max)
    {
        Root= createNode(key);
        *postIndex = *postIndex - 1;
        if(*postIndex>=0)
        {
            Root->right = constructBstUtill(post,postIndex,post[*postIndex],key,Max,Size);
            Root->left  = constructBstUtill(post,postIndex,post[*postIndex],Min,key,Size);
        }
    }
    return Root;
}
node*constructBst(int *post,int Size)
{
    int postIndex = Size-1;
    return constructBstUtill
            (post,&postIndex,post[postIndex],INT_MIN,INT_MAX,Size);
}
int main()
{
    struct node* root = NULL;
    queue<int> q1;

    int k = 80;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "Before Reverse :" << endl;
    inorder(root);
    cout << "\n";
    reversePath(&root, k, q1);
    cout << "After Reverse :" << endl;
    inorder(root);
    return 0;
}
