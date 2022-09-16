#include <iostream>

using namespace std;
struct node
{
    int data;
    node*left;
    node*right;
    int height;
    node()
    {
        data = 0 ;
        left = right = NULL;
    }
    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
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
void storeBST_ToArray(node*curr,int *nodes,int *index)
{
    if(curr==NULL)
        return ;
    storeBST_ToArray(curr->left,nodes,index);
    nodes[*index] = curr->data;
    (*index)++;
    storeBST_ToArray(curr->right,nodes,index);
}
int* mergeTwoArrays(int*arr1,int Size1,int *arr2,int Size2)
{
    int k = 0, i = 0 , j = 0;
    int *MergedArr = new int [Size1 + Size2];
    while(i < Size1 && j < Size2)
    {
        if(arr1[i]<arr2[j])
        {
            MergedArr[k] = arr1[i];
            i++;
        }
        else
        {
            MergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while(i < Size1)
    {
        MergedArr[k] = arr1[i];
        i++;
        k++;
    }
     while(j < Size2)
    {
        MergedArr[k] = arr2[j];
        j++;
        k++;
    }
    return MergedArr;
}
void printMergedArr(int *MergedArr, int Size)
{
    for(int i=0;i<Size;++i)
        cout<<MergedArr[i]<< " ";
}
node*storeMergedArr_ToBST(int *MergedArr,int start,int End)
{
    if(start>End)
        return NULL;
    int mid = (start + End)/2;
    node*MergedTree = newNode(MergedArr[mid]);
    MergedTree->left  =  storeMergedArr_ToBST(MergedArr,start,mid-1);
    MergedTree->right = storeMergedArr_ToBST(MergedArr,mid+1,End);
    return MergedTree;
}
node* MergedArraysT0_BST(node*curr1,node*curr2,int Size1,int Size2)
{
    int *arr1 = new int [Size1];
    int i=0;
    storeBST_ToArray(curr1,arr1,&i);

    int *arr2 = new int [Size2];
    int j=0;

    storeBST_ToArray(curr2,arr2,&j);

    int*MergedArr = mergeTwoArrays(arr1,Size1,arr2,Size2);
    int MergedArrSize = Size1+Size2;
    return storeMergedArr_ToBST(MergedArr,0,MergedArrSize-1);
}

int main()
{
    node *root1 = newNode(100);
    root1->left     = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);

    node *root2 = newNode(80);
    root2->left     = newNode(40);
    root2->right = newNode(120);

    node*MergedTree = MergedArraysT0_BST(root1,root2,5,3);
    print_inOrder(MergedTree);
    return 0;
}
