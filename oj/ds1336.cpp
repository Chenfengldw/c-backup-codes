#include<iostream>
using namespace std;
int N;

struct Node
{
    int data;
    Node *next;
    Node *before;

    Node(){next=NULL;before=NULL;}

};


bool adjacent(Node *p1,Node *p2)
{
    if(p1->before->before==p2)return true;
    if(p1->before==p2)return true;
    if(p1==p2)return true;
    if(p2->before->before==p1)return true;
    if(p2->before==p1)return true;
    return false;
}

int main()
{

    cin>>N;
    int farmer[3];
    int master[3];
    for(int i=0;i<3;i++)
    {
        cin>>farmer[i];
    }
    for(int i=0;i<3;i++)
    {
        cin>>master[i];
    }
    Node *head=new Node;
    Node *rear;
    rear=head;
    head->data=1;

    for(int i=2;i<=N;++i)
    {
        Node * tmp=new Node;
        tmp->data=i;
        tmp->before=rear;
        rear->next=tmp;
        rear=rear->next;
    }
    rear->next=head;
    head->before=rear;

    Node *farmer1,*farmer2,*farmer3,*master1,*master2,*master3;


    for(farmer1=head;farmer1->data!=farmer[0];farmer1=farmer1->next){}
    for(farmer2=head;farmer2->data!=farmer[0];farmer2=farmer2->next){}
    for(farmer3=head;farmer3->data!=farmer[0];farmer3=farmer3->next){}
    for(master1=head;master1->data!=master[0];master1=master1->next){}
    for(master2=head;master2->data!=master[0];master2=master2->next){}
    for(master3=head;master3->data!=master[0];master3=master3->next){}

        int a=0;
        int counter1=0,counter2=0,counter3=0;
        for(Node *tmp=head;a<N;tmp=tmp->next)
        {
            a++;
            if(adjacent(tmp,farmer1)&&adjacent(tmp,master1))counter1++;

        }
        a=0;
        for(Node *tmp=head;a<N;tmp=tmp->next)
        {
            a++;
            if(adjacent(tmp,farmer2)&&adjacent(tmp,master2))counter2++;
        }
        a=0;
        for(Node *tmp=head;a<N;tmp=tmp->next)
        {
            a++;
            if(adjacent(tmp,farmer3)&&adjacent(tmp,master3))counter3++;
        }

        cout<<250-counter1*counter2*counter3;






}







