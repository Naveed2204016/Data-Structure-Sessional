#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
bool ok=true;
void preorder(struct node *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
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
            return save;
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
struct node* search(struct node *root,int item)
{
    struct node *p=new node;
    p=root;
    while(p!=NULL)
    {
        if(p->data==item)
        {
            return p;
        }
        else if(item>p->data)
        p=p->right;
        else
        p=p->left;
    }
    return NULL;
}
struct node *del1(struct node *root,struct node *loc)
{
    struct node* par=find(root,loc->data);
    if(par==NULL)
    {
        if(loc->left==NULL && loc->right==NULL)
        return NULL;
        else if(loc->left!=NULL)
        {
        return loc->left;
        }
        else
        {
        return loc->right;
        }
    }
    else
    {
        if(loc->left==NULL && loc->right==NULL)
        {
            if(par->left==loc)
            {
                par->left=NULL;
                delete(loc);
                return root;
            }
            else
            {
                par->right=NULL;
                delete(loc);
                return root;
            }
        }
        else if(loc->left!=NULL)
        {
            if(par->left==loc)
            {
                par->left=loc->left;
                delete(loc);
                return root;
            }
            else
            {
                par->right=loc->left;
                delete(loc);
                return root;
            }
        }
        else
        {
            if(par->left==loc)
            {
                par->left=loc->right;
                delete(loc);
                return root;
            }
            else
            {
                par->right=loc->right;
                delete(loc);
                return root;
            }
        }
    }
}
struct node *del2(struct node *root,struct node *loc)
{
    struct node* par=find(root,loc->data);
    struct node *suc=loc->right;
    struct node *parsuc=loc;
    while(suc->left!=NULL)
    {
        parsuc=suc;
        suc=suc->left;
    }
    int t=suc->data;
    root=del1(root,suc);
    if(par==NULL)
    {
        node *temp=new node;
        temp->left=loc->left;
        temp->right=loc->right;
        temp->data=t;
        delete(loc);
        return temp;
    }
    else
    {
        if(par->left==loc)
        {
            node *temp=new node;
            temp->data=t;
            par->left=temp;
            temp->left=loc->left;
            temp->right=loc->right;
            delete(loc);
            return root;
        }
        else
        {
            node *temp=new node;
            temp->data=t;
            par->right=temp;
            temp->left=loc->left;
            temp->right=loc->right;
            delete(loc);
            return root; 
        }
    }

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
    int d;
    cin>>d;
    struct node *loc=search(p,d);
    if(loc==NULL)
    {
        cout<<"item not in tree"<<endl;
    }
    else if(loc->left!=NULL && loc->right!=NULL)
    {
        p=del2(p,loc);
    }
    else
    {
        p=del1(p,loc);
    }
    preorder(p);
}