#include<iostream>
using namespace std;
class Node
{
    private:
    public:
    int data;
    Node *next;
};
class LinkedList{
private:
int i,n,x;
Node *h=NULL;
Node *q=NULL;
Node *p=NULL;
public:
void create(){
 cout<<"How many numbers : "<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        p=new Node();
        cout<<"Enter New adress "<<p<<endl;
        cout<<"Enter Data: "<<i+1<<endl;
        cin>>x;
        p->data=x;
        if(h==NULL)
            h=p;        
        else
            if(q!=NULL)
            q->next=p;
        q=p;
            cout<<"i= "<<i<<" "<<"h= "<<h<<" "<<"q= "<<q<<" "<<"p= "<<p<<"p->data= "<<p->data<<" "<<"q->data= "<<q->data<<endl;
        }
    q->next=NULL;
}
void display(){
 p=h;
    while(p!=NULL){
        cout<<p->data<<endl;
        p=p->next;
    }
}
};
int main()
{    
    LinkedList l;
    int opt;
    for(;;){
        cout<<"******MENU*******"<<endl;
        cout<<"1.create"<<endl;
        cout<<"2.Insert"<<endl;
        cout<<"3.delete"<<endl;
        cout<<"4.update"<<endl;
        cout<<"5.Update"<<endl;
        cout<<"6.Display"<<endl;
        cout<<"7.exit"<<endl;
        cin>>opt;
        if(opt==7)
        switch(opt){
   
    case 1: l.create();
    case 2: l.display();
        }
    }
    return 0;
}