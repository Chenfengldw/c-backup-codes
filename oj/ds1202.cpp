#include<iostream>
#include<cstring>
using namespace std;
class Node
{
public:

    Node *next;
    Node *prev;
    int data;
    Node();
};

Node::Node()
{
    next=NULL;
    prev=NULL;
    data=0;
}

class Int
{
    friend ostream & operator<<(ostream &os,Int &a);
    friend istream & operator>>(istream &is,Int &a);
  public:
    Node *head;
    Node *tail;
    Int();
    Int operator+(Int &a);
    Int & operator=(Int a);


};


Int::Int()
{
    head=new Node;
    Node *tmp;
    Node *last;
    for(long int i=0;i<1000001;++i){
        tmp=new Node;
        if (i==0) {head->next=tmp;tmp->prev=head;last=tmp;}
        else {last->next=tmp;tmp->prev=last;last=tmp;}
    }
    head->prev=NULL;
    tail=new Node;
    tail->prev=last;
    tail->next=NULL;
    last->next=tail;
}

Int & Int::operator=(Int a)
{
    Node *tmp,*tmpa;
    tmp=head->next;
    tmpa=a.head->next;
    for(int i=0;i<1000001;++i){
        tmp->data=tmpa->data;
        tmp=tmp->next;
        tmpa=tmpa->next;
    }
    return *this;

}
Int Int::operator+(Int &a)
{
    Int tmpint;
    Node *tmp,*tmp1,*tmp2;
    int up=0;
    tmp2=tmpint.tail->prev;
    for(tmp=tail->prev,tmp1=a.tail->prev;tmp->prev!=NULL;tmp=tmp->prev,tmp1=tmp1->prev)
    {
        tmp2->data=(tmp1->data+tmp->data+up)%10;
        up=(tmp1->data+tmp->data+up)/10;
        tmp2=tmp2->prev;
    }
    return tmpint;


}

istream & operator>>(istream &is,Int &a)
{
    char *in;
    in=new char[1000001];
    is>>in;
    long int len=strlen(in);
    Node *tmp;
    tmp=a.tail->prev;
    for(long int i=len-1;i>=0;--i) {tmp->data=int(in[i])-int('0');tmp=tmp->prev;}
    return is;
}

ostream & operator<<(ostream &os,Int &a)
{

    Node *tmp;
    tmp=a.head->next;
    while(tmp->data==0){tmp=tmp->next;}
    while(tmp->next!=NULL) {os<<tmp->data;tmp=tmp->next;}
    return os;
}


int main()
{

    Int a,b,c;
    cin>>a;
    cin>>b;
    c=a+b;
    cout<<c;
    return 0;
}
