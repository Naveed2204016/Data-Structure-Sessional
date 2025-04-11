#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
void preorder(struct node *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    struct node *p1=(struct node*)malloc(sizeof(struct node));
    struct node *p2=(struct node*)malloc(sizeof(struct node));
    struct node *p3=(struct node*)malloc(sizeof(struct node));
    struct node *p4=(struct node*)malloc(sizeof(struct node));
    struct node *p5=(struct node*)malloc(sizeof(struct node));
    p1->data=5;
    p2->data=10;
    p3->data=11;
    p4->data=3;
    p5->data=15;
    p1->left=p2;
    p1->right=p3;
    p2->left=p4;
    p2->right=p5;
    p3->left=NULL;
    p3->right=NULL;
    p4->left=NULL,p4->right=NULL;
    p5->left=NULL,p5->right=NULL;
    preorder(p1);
}