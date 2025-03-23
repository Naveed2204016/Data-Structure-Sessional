#include<bits/stdc++.h>
using namespace std;
struct node
{
    char data;
    struct node * next;
};
struct node *push(struct node *top,char a)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=a;
    ptr->next=top;
    return ptr;
}

void traverse(struct node *top)
{
    while(top!=NULL)
    {
        cout<<top->data<<" ";
        struct node *temp=(struct node*)malloc(sizeof(struct node));
        temp=top;
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