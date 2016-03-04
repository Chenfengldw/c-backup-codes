#include<iostream>//本题最大坑点！！！最开始就可以有很！多！个！根！！！！而非像书上那样只有一个！！！！！！！！

using namespace std;

int term=0;

struct Node
{
    int data;
    Node *next;

    Node():next(NULL){}
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



class graph
{
private:
    struct edgeNode
    {
        int endNode;
        int weight;
        edgeNode *next;

        edgeNode(int e,int w=1,edgeNode *n=NULL):endNode(e),weight(w),next(n){}
    };
    struct verNode
    {
        int id;
        edgeNode *head;

        verNode(edgeNode *h=NULL):head(h){}
    };

    verNode *verList;
    int graphSize;


public:
    graph(int s)
    {
        graphSize=s;
        verList=new verNode[graphSize+1];
        for(int i=1;i<=graphSize;i++) verList[i].id=i;
    }
    //~graph(){delete [] verList;}
    void insertEdge(int u,int v,int w)
    {
        edgeNode *tmp1,*tmp2;
        tmp1=new edgeNode(v,w);
        tmp2=verList[u].head;
        verList[u].head=tmp1;
        tmp1->next=tmp2;

    }

    void topSort();
};

void graph::topSort()
{
    //Queue q;
    int *learned;
    learned=new int[graphSize+1];
    for(int i=1;i<=graphSize;++i)learned[i]=0;
    int *inDegree;
    inDegree=new int[graphSize+1];
    for(int i=1;i<=graphSize;++i)inDegree[i]=0;
    for(int i=1;i<=graphSize;++i)
    {
        for(edgeNode *p=verList[i].head;p!=NULL;p=p->next)
        {
            inDegree[p->endNode]++;
        }
    }



    bool learnAll=true;
    for(int i=1;i<=graphSize;++i){if(learned[i]==0)learnAll=false;}

    while(!learnAll)
    {

        bool flag=false;
        //int current=q.deQueue();
        //learned[current]=true;
        //cout<<current<<' ';
        for(int i=1;i<=graphSize;++i)
        {
            if(inDegree[i]==0&&learned[i]==0)
            {
                flag=true;
                learned[i]=term+1;
            }
        }
        if(flag)term++;
        flag=false;

        for(int i=1;i<=graphSize;++i)
        {
            if(learned[i]==term)
            {
                //cout<<i;
                for(edgeNode *p=verList[i].head;p!=NULL;p=p->next)inDegree[p->endNode]--;
            }
        }

        learnAll=true;
        for(int i=1;i<=graphSize;++i){if(learned[i]==0)learnAll=false;}
    }
}





int main()
{
    int n,m;
    cin>>n>>m;
    graph test(n);
    for(int i=0;i<m;++i)
    {
        int a,b;
        cin>>a>>b;
        test.insertEdge(b,a,1);
    }

    test.topSort();
    cout<<term;
}



