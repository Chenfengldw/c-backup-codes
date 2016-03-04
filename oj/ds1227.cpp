#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(){next=NULL;data=-1;}
} ;

class linkList
{
public:
    Node *head,*rear;
    linkList(){head=rear=new Node;}
    void add(int x)
    {
        Node *tmp;
        tmp=new Node;
        tmp->data=x;
        rear->next=tmp;
        rear=rear->next;
    }
    void moveHead(){head=head->next;}
};



int main()
{
    int n;
    cin>>n;
    linkList test;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        test.add(x);
    }
    Node *first=test.head;
    Node *last=test.rear;
    while(test.head!=test.rear)
    {
        for(Node *p=test.head->next;p!=NULL;p=p->next)
        {
        if(p->data<test.head->next->data)
        {
            int tmp;
            tmp=test.head->next->data;
            test.head->next->data=p->data;
            p->data=tmp;
        }
        }
        test.moveHead();
    }
    for(Node *i=first->next;i!=NULL;i=i->next)cout<<i->data<<' ';
}
