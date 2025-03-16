#include<bits/stdc++.h>
using namespace std;
struct node
{
    int count;
    int data;
    struct node *next;
};


struct node* insert(struct node *head,int item)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=item;
    struct node *p=(struct node*)malloc(sizeof(struct node));
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    ptr->next=p->next;
    p->next=ptr;
    head->count+=1;
    return head;
} 

void traverse(struct node *head)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head->next;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

struct node* search(struct node *head,int item)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head->next;
    while(ptr!=NULL)
    {
        if(ptr->data==item)
        return ptr;
        ptr=ptr->next;
    }
    return NULL;
}

struct node *del(struct node *head,int item)
{
    struct node *p1=(struct node*)malloc(sizeof(struct node));
    struct node *p2=(struct node*)malloc(sizeof(struct node));
    p1=head,p2=head->next;
    while(p2!=NULL)
    {
        if(p2->data==item)
        {
            p1->next=p2->next;
            head->count-=1;
            return head;
        }
        else
        {
            p2=p2->next;
            p1=p1->next; 
        }
    }
    return head;
}
int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->count=0;
    head->next=NULL;
    int x; cin>>x;
    for(int i=0;i<x;i++)
    {
        int d; cin>>d;
        head=insert(head,d);
    }
    
    cout<<head->count<<endl;
    traverse(head);
    int item;
    cin>>item;
    struct node *loc=(struct node*)malloc(sizeof(struct node));
    loc=search(head,item);
    if(loc==NULL) cout<<"Item not found"<<endl;
    else cout<<"Item found"<<endl;
    cout<<"Give the item you want to input"<<endl;
    int k; cin>>k;
    head=insert(head,k);
    traverse(head);
    cout<<"Give the item you want to delete"<<endl;
    int delitem; cin>>delitem;
    head=del(head,delitem);
    traverse(head);
    cout<<head->count<<endl;
}