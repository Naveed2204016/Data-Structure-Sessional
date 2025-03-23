#include<bits/stdc++.h>
using namespace std;
struct node
{
    char data;
    struct node * next;
};
struct node *push(struct node *top,char a)
{
    struct node *ptr=new node;
    ptr->data=a;
    if(top==NULL)
    {
        ptr->next=NULL;
        return ptr;
    }
    struct node *p=new node;
    p=top;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    ptr->next=p->next;
    p->next=ptr;
    return top;
}

void traverse(struct node *top)
{
    while(top!=NULL)
    {
        cout<<top->data<<" ";
        struct node *temp=new node;
        top=top->next;
        delete(temp);
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
        char a; cin>>a;
        top=push(top,a);
    }

    traverse(top);
}