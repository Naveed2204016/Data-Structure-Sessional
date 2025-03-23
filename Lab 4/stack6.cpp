#include<bits/stdc++.h>
using namespace std;
double op(double a,double b,char d)
{
    if(d=='+')
    return a+b;
    else if(d=='*')
    return a*b;
    else if(d=='/')
    return a/b;
    else if(d=='-')
    return a-b;
    else
    return pow(a,b);
}
struct node
{
    double item;
    char data;
    struct node *next;
};

int precedence(char a)
{
    if(a=='^') return 3;
    else if(a=='*' || a=='/') return 2;
    else if(a=='+' || a=='-') return 1;
    else return 0;
}
struct node *push(struct node *top,char a)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=a;
    ptr->next=top;
    return ptr;
}

struct node *push(struct node *top,double a)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->item=a;
    ptr->next=top;
    return ptr;
}



struct node *pop(struct node *top)
{
    struct node *temp=new node;
    temp=top->next;
    free(top);
    return temp;
}

int main()
{
    struct node *top=(struct node*)malloc(sizeof(struct node));
    top=NULL;
    string infix; cin>>infix;
    string postfix;
    infix+=')';
    top=push(top,'(');
    for(int i=0;i<infix.size();i++)
    {
        if(infix[i]=='(') top=push(top,infix[i]);
        else if(isdigit(infix[i]))
        {
            while(isdigit(infix[i]) || infix[i]=='.')
            {
                postfix+=infix[i];
                i++;
            }
            i--;
            postfix+=' ';
        }
        else if(infix[i]==')')
        {
            while(top->data!='(')
            {
                postfix+=top->data;
                top=pop(top);
            }
            top=pop(top);
        }
        else
        {
            while(precedence(top->data)>=precedence(infix[i]))
            {
                postfix+=top->data;
                top=pop(top);
            }
            top=push(top,infix[i]);
        }
    }
    
    struct node* top1=new node;
    top1=NULL;
    for(int i=0;i<postfix.size();i++)
    {
        if(isdigit(postfix[i]))
        {
            double ans=0;
            double frac=0;
            bool ok=false;
            double tx=10;
            while(postfix[i]!=' ')
            {
                if(postfix[i]=='.')
                {
                    ok=true;
                    i++;
                    continue;
                }
                if(!ok)
                ans=ans*10+(postfix[i]-'0');
                else
                {
                    frac=frac+(postfix[i]-'0')/tx;
                    tx*=10;
                }
                i++;
            }
            top1=push(top1,ans+frac);
        }
        else
        {
        double b=top1->item;
        top1=pop(top1);
        double a=top1->item;
        top1=pop(top1);
        top1=push(top1,op(a,b,postfix[i]));
        }
    }
    cout<<top1->item<<endl;
}