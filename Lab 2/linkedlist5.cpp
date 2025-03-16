#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

struct node * insertlast(struct node *head,int item)
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=item;
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

struct node * insertpos(struct node *head,int item,int pos)
{
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p=head;
    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=item;
    ptr->next=p->next;
    p->next=ptr;
    return head;
}

void traverse(struct node *head)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

struct node * insertbeg(struct node *head,int item)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=item;
    ptr->next=head;
    return ptr;
}
int main()
{
    int n;
    cin>>n;
    struct node *head=(struct node*)malloc(sizeof(struct node));
    if(n>0)
    {
    int d; cin>>d;
    head->data=d;
    head->next=NULL;
    }
    else
    head=NULL;
    for(int i=0;i<n-1;i++)
    {
        int d;
        cin>>d;
        head=insertlast(head,d);
    }
    cout<<"Linked list before insertion"<<endl;
    traverse(head);
    cout<<"Give the item you want to insert and the position after you want to insert"<<endl;
    int x,pos; cin>>x>>pos;
    if(pos==0)
    head=insertbeg(head,x);
    else
    {
    head=insertpos(head,x,pos);
    }
    cout<<"Linked list after insertion"<<endl;
    traverse(head);
}

