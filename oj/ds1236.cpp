#include<iostream>
#define INF 20000000
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node()
    {
        next=NULL;
    }
};


class Queue
{
public:
    Node *head,*rear;

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
        tmp=head->next;
        int x;
        x=tmp->data;
        if(head->next==rear) rear=head;
        head->next=tmp->next;

        delete tmp;
        return x;
    }

    bool isEmpty()
    {
        return head==rear;
    }

};

class graph
{
public:
    struct edgeNode
    {
        int endNode;
        edgeNode *next;
        int weight;

        edgeNode(int e,int w)
        {
            weight=w;
            endNode=e;
            next=NULL;
        }
    };
    struct verNode
    {
        int id;
        edgeNode *head;

        verNode(edgeNode *h=NULL)
        {
            head=h;
        }
    };

    int graphSize;
    verNode *verList;

    graph(int s)
    {
        graphSize=s;
        verList=new verNode[s+1];
        for(int i=1;i<=s;++i)verList[i].id=i;
    }

    void insertEdge(int a,int b,int w)
    {
        edgeNode *tmp1,*tmp2;
        tmp1=new edgeNode(b,w);
        tmp2=verList[a].head;
        verList[a].head=tmp1;
        tmp1->next=tmp2;
    }

    void SPFA(int start,int stop);
    void printPath(int start,int stop,int prev[])
    {
        if(start==stop){cout<<start<<' ';return;}
        printPath(start,prev[stop],prev);
        cout<<stop<<' ';
    }

};



void graph::SPFA(int start,int stop)
{
    int *distance=new int[graphSize+1];
    int *prev=new int[graphSize+1];

    edgeNode *p;
    Queue q;

    for(int i=1;i<=graphSize;++i)distance[i]=INF;
    distance[start]=0;
    prev[start]=start;
    q.enQueue(start);


    while(!q.isEmpty())
    {
        int u=q.deQueue();
        for(p=verList[u].head;p!=NULL;p=p->next)
        {
            if(distance[p->endNode]>distance[u]+p->weight)
            {
                distance[p->endNode]=distance[u]+p->weight;
                prev[p->endNode]=u;
                q.enQueue(p->endNode);
            }
        }
    }

    cout<<distance[stop]<<endl;
    printPath(start,stop,prev);


}

int main()
{
    int n,m,start,end;
    cin>>n>>m>>start>>end;
    graph test(n);

    for(int i=0;i<m;++i)
    {
        int a,b,w;
        cin>>a>>b>>w;
        test.insertEdge(a,b,w);

    }
    test.SPFA(start,end);
}
