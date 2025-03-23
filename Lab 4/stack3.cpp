#include<bits/stdc++.h>
using namespace std;
struct node
{
    char data;
    struct node *next;
};
struct node *pushfront(struct node *first,char a)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=a;
    ptr->next=first;
    return ptr;
}

struct node *pushback(struct node *last,char a)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=a;
    last->next=ptr;
    ptr->next=NULL;
    return ptr;
}

void traverse(struct node *first)
{
    while(first!=NULL)
    {
        cout<<first->data<<" ";
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp=first;
        first=first->next;
        delete(temp);
    }
    cout<<endl;
}
int main()
{
    struct node *first=(struct node*)malloc(sizeof(struct node));
    struct node *last=(struct node*)malloc(sizeof(struct node));
    int n; cin>>n;
    char a; cin>>a;
    char b; cin>>b;
    first->data=a;
    last->data=b;
    first->next=last;
    last->next=NULL;
    for(int i=2;i<n;i++)
    {
        char a; cin>>a;
        cout<<"pushfront :1 & pushback :2"<<endl;
        int d; cin>>d;
        if(d==1)
        {
            first=pushfront(first,a);
        }
        else
        {
            last=pushback(last,a);
        }
    }

    traverse(first);
}