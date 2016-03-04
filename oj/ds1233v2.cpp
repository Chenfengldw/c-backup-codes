#include<iostream>
using namespace std;


int n,m,initStart,M,counter=0;


class graph
{
private:
    struct edgeNode
    {
        int endNode;
        edgeNode *next;
        int weight;

        edgeNode(int e,edgeNode *n=NULL):endNode(e),next(n){weight=1;}
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
    graph(int tmpsize)
    {
        graphSize=tmpsize;
        verList=new verNode[tmpsize];
        for(int i=0;i<graphSize;i++) verList[i].id=i+1;
    }
    void insertEdge(int u,int v)
    {
        edgeNode *tmp;
        tmp=new edgeNode(v);
        if(verList[u-1].head==NULL)
        {
            verList[u-1].head=tmp;
        }
        else
        {
            edgeNode *tmp2;
            bool exist=false;
            for(tmp2=verList[u-1].head;tmp2!=NULL;tmp2=tmp2->next)
            {
                if (tmp2->endNode==v){tmp2->weight++;exist=true;break;}
            }
            if(!exist)
            {
                edgeNode *last=verList[u-1].head;
                while(last->next!=NULL)last=last->next;
                last->next=tmp;
            }
        }
    }

    void Find(int start,int m);
    void Find(int start,int m,int &top,bool *visited,int *route);



};


void graph::Find(int start,int m)
{
    bool *visited=new bool[graphSize];
    int *route=new int[m+1],top=0;

    for(int i=0;i<graphSize;++i)visited[i]=false;

    Find(start,m,top,visited,route);
}

void graph::Find(int start,int m,int &top,bool *visited,int *route)
{
    edgeNode *p=verList[start-1].head;
    visited[start-1]=true;
    route[top]=start;
    top++;

    if(top==m+1)
       {
            counter++;
            visited[start-1]=false;
            top--;
            return;
       }

    while(p!=NULL)
    {
        if(!visited[p->endNode])Find(p->endNode,m,top,visited,route);
        p=p->next;
    }
    visited[start-1]=false;
    --top;
}





int main()
{

    cin>>n>>m>>initStart>>M;
    graph test(n);

    for(int i=0;i<m;++i)
    {
        int a,b;
        cin>>a>>b;
        test.insertEdge(a,b);
    }

    test.Find(initStart,M);
    cout<<counter;

}


