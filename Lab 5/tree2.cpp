#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void preorder(struct node *root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


void postorder(struct node *root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void preorderSTACK(struct node * root)
{
    if(root==NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    stack<node*> s;
    s.push(root);
    while(!s.empty())
    {
        node* p=s.top();
        cout<<p->data<<" ";
        s.pop();
        if(p->right!=NULL) s.push(p->right);
        if(p->left!=NULL)  s.push(p->left);
    }
    cout<<endl;
}


void inorderSTACK(struct node* root) {
    if (root == NULL) return;

    stack<node*> s;
    struct node* current = root;

    while (current != NULL || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        cout << current->data << " ";

        current = current->right;
    }
    cout << endl;
}

void postorderSTACK(node* root) {
    if (root == NULL) return;

    stack<node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        node* node= s1.top();
        s1.pop();
        s2.push(node);

        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << endl;
}
int main()
{
    struct node *p1=(struct node*)malloc(sizeof(struct node));
    struct node *p2=(struct node*)malloc(sizeof(struct node));
    struct node *p3=(struct node*)malloc(sizeof(struct node));
    struct node *p4=(struct node*)malloc(sizeof(struct node));
    struct node *p5=(struct node*)malloc(sizeof(struct node));
    p1->data=5;
    p2->data=10;
    p3->data=11;
    p4->data=3;
    p5->data=15;
    p1->left=p2;
    p1->right=p3;
    p2->left=p4;
    p2->right=p5;
    p3->left=NULL;
    p3->right=NULL;
    p4->left=NULL,p4->right=NULL;
    p5->left=NULL,p5->right=NULL;
    cout<<"Preorder traversal using recursion"<<endl;
    preorder(p1);
    cout<<endl;
    cout<<"Inorder traversal using recursion"<<endl;
    inorder(p1);
    cout<<endl;
    cout<<"Postorder traversal using recursion"<<endl;
    postorder(p1);
    cout<<endl;
    cout<<"Postorder traversal using stack"<<endl;
    preorderSTACK(p1);
    cout<<"Inorder traversal using stack"<<endl;
    inorderSTACK(p1);
    cout<<"Postorder traversal using stack"<<endl;
    postorderSTACK(p1);

}