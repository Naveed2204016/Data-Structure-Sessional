#include<bits/stdc++.h>
using namespace std;
struct node
{
    int count;
    int data;
    struct node* next;
    struct node* prev;

};

struct node *insert(struct node *head,int item)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->data=item;
    if(head->prev==head)
    {
    head->prev=p;
    p->prev=head;
    p->next=head;
    head->next=p;
    }
    else
    {
    ptr=head->prev;
    while(ptr->next!=head)
    {
        ptr=ptr->next;
    }
    p->next=ptr->next;
    ptr->next=p;
    p->prev=head->next;
    head->next=p;
    }
    head->count+=1;
    return head;
}

void traverse(struct node *head)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head->prev;
    while(ptr!=head)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}

struct node *del(struct node *head,int item)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head->prev;
    if(ptr->data==item)
    {
        head->prev=ptr->next;
        ptr->prev=head;
        head->count-=1;
        return head;
    }
    while(ptr!=head)
    {
        if(ptr->data==item)
        {
            (ptr->prev)->next=ptr->next;
            if(ptr->next==head)
            {
            (ptr->next)->next=ptr->prev;
            (ptr->prev)->next=head;
            }
            else
            (ptr->next)->prev=ptr->prev;
            head->count-=1;
            return head;
        }
        else
        ptr=ptr->next;
    }
    return head;
}

void backtraverse(struct node* head)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr=head->next;
    while(ptr!=head)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->prev;
    }
    cout<<endl;
}
int main()
{
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head->count=0;
    head->next=head;
    head->prev=head;
    int x;
    cin>>x;
    for(int i=0;i<x;i++)
    {
        int d; cin>>d;
        head=insert(head,d);
    }
    cout<<"Traversing forward.."<<endl;
    traverse(head);
    cout<<"Traversing backward.."<<endl;
    backtraverse(head);
    cout<<"Give the item you want to input"<<endl;
    int k; cin>>k;
    head=insert(head,k);
    traverse(head);
    cout<<"Give the item you wanna delete"<<endl;
    int item; cin>>item;
    head=del(head,item);
    traverse(head);
}