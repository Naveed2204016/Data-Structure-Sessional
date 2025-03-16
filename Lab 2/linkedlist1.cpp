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

void traverse(struct node *head)
{
    if(head==NULL)
    {
        cout<<"Empty"<<endl;
        return;
    }
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head;
    cout<<"The elements of the linked list are:"<<endl;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
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
    traverse(head);
}

