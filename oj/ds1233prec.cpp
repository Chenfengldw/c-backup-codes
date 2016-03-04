#include<iostream>
using namespace std;

int pathNum=0,n,m,Start,M;

class graph
{
public:


    struct edgeNode
    {
        int endNode;
        edgeNode* next;
        int weight;

        edgeNode()
        {
            next=NULL;
            weight=1;
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

    void insertEdge(int u,int v)
    {
        for(edgeNode *p=verList[u].head;p!=NULL;p=p->next)
        {
            if(p->endNode==v)
            {
                p->weight++;
                return;
            }
        }
        edgeNode *tmp1,*tmp2;
        tmp1=verList[u].head;
        tmp2=new edgeNode;
        tmp2->endNode=v;
        verList[u].head=tmp2;
        tmp2->next=tmp1;

    }

    void DFS(int start)
    {
        bool *visited;
        visited=new bool[graphSize+1];
        for(int i=1;i<=graphSize;++i)visited[i]=false;

        int length=0;
        visited[start]=true;

        int multiply=1;
        DFS(start,visited,length,multiply);



    }

    void DFS(int start,bool *visited,int length,int multiply)
    {
        if(length==M)
        {
            pathNum+=multiply;
            return;
        }

        edgeNode *p;
        for(p=verList[start].head;p!=NULL;p=p->next)
        {
            if(visited[p->endNode])continue;
            visited[p->endNode]=true;

            length++;//cout<<p->endNode<<' '<<length;
            multiply*=p->weight;
            DFS(p->endNode,visited,length,multiply);
            length--;
            multiply/=p->weight;
            visited[p->endNode]=false;
        }
    }

};



int main()
{
    cin>>n>>m>>Start>>M;

    graph test(n);
    for(int i=0;i<m;++i)
    {
        int a,b;
        cin>>a>>b;
        test.insertEdge(a,b);
    }

    test.DFS(Start);
    cout<<pathNum;
    return 0;
}
