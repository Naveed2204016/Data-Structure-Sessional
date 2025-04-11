#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
bool ok=true;
struct node* find(struct node *root,int item)
{
    ok=true;
    if(root==NULL)
    {
        return NULL;
    }

    struct node *save=new node;
    struct node *p=new node;
    save=NULL;
    p=root;
    while(p!=NULL)
    {
        if(p->data==item)
        {
            ok=false;
            return NULL;
        }
        else if(item>p->data)
        {
            save=p;
            p=p->right;
        }
        else
        {
            save=p;
            p=p->left;
        }
    }
    return save;
}

struct node *insert(struct node* root,int item)
{
    struct node *par=find(root,item);
    if(par==NULL && ok)
    {
        struct node *p=new node;
        p->data=item;
        p->left=NULL;
        p->right=NULL;
        return p;
    }
    else
    {
        if(item>par->data)
        {
        struct node *p=new node;
        p->data=item;
        p->left=NULL;
        p->right=NULL;
        par->right=p;
        return root;
        }
        else
        {
            struct node *p=new node;
            p->data=item;
            p->left=NULL;
            p->right=NULL;
            par->left=p;
            return root;
        }
    }
}

void search(struct node *root,int item)
{
    struct node *p=new node;
    p=root;
    while(p!=NULL)
    {
        if(p->data==item)
        {
            cout<<"Item found"<<endl;
            return;
        }
        else if(item>p->data)
        p=p->right;
        else
        p=p->left;
    }
    cout<<"Item not found"<<endl;
    return;
}
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
    int n;
    cin>>n;
    node *p=new node;
    p=NULL;
    for(int i=0;i<n;i++)
    {
        int d;
        cin>>d;
        p=insert(p,d);
    }
    preorder(p);
    cout<<endl;
    int d;
    cin>>d;
    search(p,d);
}