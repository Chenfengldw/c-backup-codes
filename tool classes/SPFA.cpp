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

class  Queue
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
        Node *tmp=new Node;
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
        if(head->next==rear)rear=head;
        head->next=tmp->next;
        delete tmp;
        return x;
    }

    bool isEmpty()
    {
        return rear==head;
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

        edgeNode(int v,int w)
        {
            next=NULL;
            endNode=v;
            weight=w;
        }
    };

    struct verNode
    {
        int id;
        edgeNode *head;

        verNode()
        {
            head=NULL;
        }

    };

    int graphSize;
    verNode *verList;

    graph(int s)
    {
        graphSize=s;
        verList=new verNode[s+1];

    }

    void insertEdge(int u,int v,int w)
    {
        edgeNode *tmp=new edgeNode(v,w);
        edgeNode *tmp1=verList[u].head;

        verList[u].head=tmp;
        tmp->next=tmp1;


    }

    void SPFA(int start,int stop);
    void printPath(int start,int stop,int *prev)
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
    for(int i=1;i<graphSize+1;++i)distance[i]=INF;
    distance[start]=0;
    prev[start]=start;

    Queue q;
    q.enQueue(start);

    int cnt;
    while(!q.isEmpty())
    {
        cnt=q.deQueue();
        edgeNode *p;

        for(p=verList[cnt].head;p!=NULL;p=p->next)
        {
            if(distance[p->endNode]>distance[cnt]+p->weight)
            {
                distance[p->endNode]=distance[cnt]+p->weight;
                prev[p->endNode]=cnt;
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
        int a,b,p;
        cin>>a>>b>>p;

        test.insertEdge(a,b,p);
    }

    test.SPFA(start,end);

    return 0;
}






