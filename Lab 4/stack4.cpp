#include<bits/stdc++.h>
using namespace std;
struct node
{
    char data;
    int pr;
    struct node * next;
};
struct node *push(struct node *top,char a,int x)
{
    struct node *ptr=new node;
    ptr->data=a;
    if(top==NULL)
    {
        ptr->next=NULL;
        ptr->pr=x;
        return ptr;
    }
    else if(x<top->pr)
    {
        ptr->next=top;
        ptr->pr=x;
        return ptr;
    }
    struct node *p1=new node;
    struct node *p2=new node;
    p1=top;
    p2=top->next;
    while(p2!=NULL && x>=p2->pr)
    {
        p1=p1->next;
        p2=p2->next;
    }
    ptr->pr=x;
    ptr->next=p1->next;
    p1->next=ptr;
    return top;
}

void traverse(struct node *top)
{
    while(top!=NULL)
    {
        cout<<top->data<<" ";
        struct node* temp=(struct node*)malloc(sizeof(struct node));
        top=top->next;
    }
    cout<<endl;
}
int main()
{
    struct node *top=(struct node*)malloc(sizeof(struct node));
    top=NULL;
    int n; cin>>n;
    for(int i=0;i<n;i++)
    {
        int p; cin>>p;
        char a; cin>>a;
        top=push(top,a,p);
    }

    traverse(top);
}