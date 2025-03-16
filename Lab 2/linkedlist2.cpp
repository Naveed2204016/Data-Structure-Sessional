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

bool isexist(struct node *head,int item,node **loc)
{
    if(head==NULL)
    {
        return false;
    }
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr=head;
    while(ptr->data!=item && ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    if(ptr->data==item)
    {
    *loc=ptr;
    return true;
    }
    else
    return false;
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
    cout<<"Insert the item you want to search"<<endl;
    int x; cin>>x;
    struct node *loc=(struct node*)malloc(sizeof(struct node));
    if(isexist(head,x,&loc))
    
    {
        cout<<"The item exists at location: "<<loc<<endl;
    }
    else cout<<"The item doesn't exist"<<endl;
}

