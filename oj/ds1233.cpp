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
    void dfs(int start)const;
    void dfs(int start,bool *visited,int length,int mutiply)const;


};






void graph::dfs(int start)const
{
        int length=0;
        bool *visited;
        visited=new bool[graphSize];
        for(int i=0;i<graphSize;i++) visited[i]=false;
        int initMultiply=1;
        dfs(start,visited,length,initMultiply);



}

void graph::dfs(int start,bool *visited,int length,int mutiply)const
{

    edgeNode *p=verList[start-1].head;
    visited[start-1]=true;//critical error if this was forgotten!!!!!
    int mulThisLevel=mutiply;
    while(p!=NULL)
    {
        if(!visited[p->endNode-1])
        {
            visited[p->endNode-1]=true;
            length++;
            //cout<<p->endNode<<' '<<length<<'*'<<' ';
            mutiply*=p->weight;
            dfs(p->endNode,visited,length,mutiply);

            if(length==M&&p->endNode!=initStart)counter+=mulThisLevel;
            visited[p->endNode-1]=false;
            length--;
        }
        p=p->next;
    }


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

    test.dfs(initStart);
    cout<<counter;


}
