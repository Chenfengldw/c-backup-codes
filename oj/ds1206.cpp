#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

class Node
{
public:

    int data;
    Node *next;
    Node();
};

Node::Node()
{
    int data;
    next=NULL;

}



class Stack
{
public:

    Node *top;
    Stack();
    void push(int x);
    void pop();
};

Stack::Stack()
{
    top=NULL;

}

void Stack::push(int x)
{
    Node *tmp;
    tmp=new Node;
    tmp->data=x;
    tmp->next=top;
    top=tmp;

}

void Stack::pop()
{
    Node *tmp;
    tmp=top;
    top=top->next;
    delete tmp;
}

int main()
{
    Stack st;
    bool flag=true;
    char code[4000];
    for(int i=0;i<4000;++i) code[i]='0';
    cin.getline(code,4000,EOF);
    for(int i=0;i<3998;++i)
    {
        if(code[i]=='b'&&code[i+1]=='e'&&code[i+2]=='g'&&code[i+3]=='i'&&code[i+4]=='n')
        {
            st.push(1);

        }
        if((i==0||code[i-1]==' ')&&code[i]=='i'&&code[i+1]=='f'&&code[i+2]==' ')
        {
            if(st.top==NULL||st.top->data!=2){st.push(2);}
            else {cout<<"Error!";return 0;}
        }
         if(code[i]=='t'&&code[i+1]=='h'&&code[i+2]=='e'&&code[i+3]=='n')
        {
            if(st.top->data==2){st.push(3);}
            else {cout<<"Error!";return 0;}
        }
         if(code[i]=='e'&&code[i+1]=='l'&&code[i+2]=='s'&&code[i+3]=='e')
        {
            if(st.top==NULL){cout<<"Error!";return 0;}
            if(st.top==NULL||st.top->data==3) {st.pop();st.pop();}
            else {cout<<"Error!";return 0;}
        }
        if(code[i]=='e'&&code[i+1]=='n'&&code[i+2]=='d')
        {

            if(st.top==NULL){cout<<"Error!";return 0;}
            while (st.top->data==2||st.top->data==3)
            {
                st.pop();
            }
            if(st.top->data==1) {flag=false;st.pop();}
            else {cout<<"Error!";return 0;}
        }
    }
    if (st.top==NULL&&flag==false)cout<<"Match!";
    else cout<<"Error!";

}






