#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node *lChild;
    Node *rChild;
};
class Tree{
    private:
    Node *root;
    public:
    Tree(){
        root=NULL;
    }
    void createTree();
    void preorder(Node *p);
    void preorder(){
        preorder(root);
    }
    void inorder(Node *p);
    void inorder(){
        inorder(root);
    }
};
void Tree::createTree(){
    Node *p,*t;
    int x;
    queue<Node*>q;
    cout<<"Enter Root Value "<<endl;
    cin>>x;
    root=new Node;
    root->data=x;
    root->lChild=root->rChild=NULL;
    q.push(root);
    while(!q.empty()){
        p=q.front();
        q.pop();
        cout<<"Enter Left Child "<<endl;
        cin>>x;
        if(x!=-1){
        t=new Node;
        t->data=x;
        t->lChild=t->rChild=NULL;
        p->lChild=t;
        q.push(t);
        }
        cout<<"Enter Right Child "<<endl;
        cin>>x;
        if(x!=-1)
        {
        t=new Node;
        t->data=x;
        t->lChild=t->rChild=NULL;
        p->rChild=t;
        q.push(t);
        }
    }
}
void Tree::preorder(Node *p){
    if(p){
        cout<<p->data<<" ";
        preorder(p->lChild);
        preorder(p->rChild);
    }
}
void Tree::inorder(Node *p){
    if(p){
        inorder(p->lChild);
        cout<<p->data<<" ";
        inorder(p->rChild);
    }
}
int main(){
    Tree t;
    t.createTree();
    cout<<"Preorder "<<endl;
    t.preorder();
    cout<<"\nInorder "<<endl;
    t.inorder();

 return 0;   
}