#include<iostream>
#include<iomanip>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(){next=NULL;}
};

class Queue
{
public:
    Node *head;
    Node *rear;

    Queue()
    {
        head=new Node;
        rear=head;

    }

    void enQueue(int x)
    {
        Node *tmp;
        tmp=new Node;
        tmp->data=x;
        rear->next=tmp;
        rear=tmp;
    }
    int deQueue()
    {
        if(isEmpty())return -1;
        Node *tmp;
        int toBeReturned;
        tmp=head->next;
        toBeReturned=tmp->data;
        if(head->next==rear)rear=head;
        head->next=tmp->next;

        delete tmp;
        return toBeReturned;
    }
    bool isEmpty()
    {
        return head==rear;
    }
};


int main()
{
    Queue bus,van;

    int N,busNum=0,vanNum=0;
    cin>>N;
    int *cars;
    cars=new int[2*N];
    for(int i=0;i<2*N;++i) cin>>cars[i];
    for(int i=0;i<2*N;i+=2)
    {

        if (cars[i]==0) {bus.enQueue(cars[i+1]);busNum++;}
        else {van.enQueue(cars[i+1]);vanNum++;}

    }

    int totalTime,timer;
    totalTime=max(((cars[2*N-1]+10)/10)*10,(N-1/10+1)*10);
    int busWaitTime=0,vanWaitTime=0;
    int onboard=0;

    for(timer=0;timer<=totalTime;timer+=10)
    {
        for(onboard=0;onboard<8&&!bus.isEmpty()&&bus.head->next->data<=timer;)
        {
            onboard++;
            busWaitTime+=timer-bus.deQueue();
        }
        for(;onboard<10&&!van.isEmpty()&&van.head->next->data<=timer;)
        {
            onboard++;
            vanWaitTime+=timer-van.deQueue();
        }
        for(;onboard<10&&!bus.isEmpty()&&bus.head->next->data<=timer;)
        {
            onboard++;
            busWaitTime+=timer-bus.deQueue();
        }
        onboard=0;
    }
    double out1,out2;
    out1=(double(busWaitTime)/busNum);
    out2=(double(vanWaitTime)/vanNum);
    cout<<setiosflags(ios::fixed)<<setprecision(3)<<out1<<' '<<setprecision(3)<<out2;


}
