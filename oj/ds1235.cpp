#include<iostream>
#define INF 100000000
using namespace std;

int path[100000];
int pathLength=0;
int totalWeight;


struct queueNode
{
    int dist;
    int nodeID;
    bool operator<(queueNode &qN){return dist<qN.dist;}
    bool operator<=(queueNode &qN){return dist<qN.dist;}
    bool operator>(queueNode &qN){return dist<qN.dist;}
    bool operator>=(queueNode &qN){return dist<qN.dist;}
};

class graph
{
private:
    struct edgeNode
    {
        int endNode;
        edgeNode *next;
        int weight;

        edgeNode(int e,edgeNode *n=NULL,int w=1):endNode(e),next(n),weight(w){}
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
        verList=new verNode[tmpsize+1];
        for(int i=1;i<=graphSize;i++) verList[i].id=i;
    }
    void insertEdge(int u,int v,int w);
    void dijkstra(int start,int destination);
    void printPath(int start,int stop,int *prev);

};


void graph::insertEdge(int u,int v,int w)
{
        edgeNode *tmp,*tmp2;
        tmp=new edgeNode(v,NULL,w);
        tmp2=verList[u].head;
        verList[u].head=tmp;
        tmp->next=tmp2;
}





template<class T>
class priorityQueue
{
private:
    int currentSize;
    int maxSize;
    T *array;

    void doubleSpace();
    void percolateDown(int hole);

public:
    priorityQueue(int capacity=100)
    {
        array=new T[capacity];
        maxSize=capacity;
        currentSize=0;
    }
    //~priorityQueue(){delete [] array;}

    bool isEmpty() {return currentSize==0;}
    void enQueue(T x);
    void buildHeap();
    T deQueue();

};

template<class T>
void priorityQueue<T>::doubleSpace()
{
    T *tmp;
    tmp=new T[2*maxSize];
    maxSize*=2;
    for(int i=1;i<=currentSize;++i) tmp[i]=array[i];
    delete [] array;
    array=tmp;

}

template<class T>
void priorityQueue<T>::percolateDown(int hole)
{
    int child;
    T tmp=array[hole];
    for(;hole*2<=currentSize;hole=child)
    {
       child=hole*2;
       if(child+1<=currentSize)
       {
           if(array[child]>=array[child+1])
           {
               child++;
           }
       }
       if(array[child]<tmp)array[hole]=array[child];
       else break;

    }
     array[hole]=tmp;
}





template<class T>
void priorityQueue<T>::enQueue(T x)
{
    if (currentSize==maxSize-1) doubleSpace();

    int hole=++currentSize;
    for(;hole>1&&x<array[hole/2];hole/=2)
    {
        array[hole]=array[hole/2];
    }
    array[hole]=x;
}

template<class T>
T priorityQueue<T>::deQueue()
{
    T minData=array[1];
    array[1]=array[currentSize];
    currentSize--;
    percolateDown(1);
    return minData;
}


template<class T>
void priorityQueue<T>::buildHeap()
{
    for(int i=currentSize/2;i>0;--i)percolateDown(i);
}



void graph::printPath(int start,int stop,int *prev)
{

    if(start==stop)
    {
        path[pathLength++]=start;
        return;
    }
    printPath(start,prev[stop],prev);
    path[pathLength++]=stop;
}


void graph::dijkstra(int start,int destination)
{
    int *distance=new int[graphSize+1];
    int *prev=new int[graphSize+1];
    bool *known=new bool[graphSize+1];
    queueNode minNode,renewedNode;
    priorityQueue <queueNode>q;

    for(int i=1;i<=graphSize;++i)
    {
        known[i]=false;
        distance[i]=INF;

    }

    distance[start]=0;
    prev[start]=start;
    minNode.nodeID=start;
    minNode.dist=0;
    q.enQueue(minNode);

    while(!q.isEmpty())
    {8
        minNode=q.deQueue();
        if(known[minNode.nodeID])continue;
        known[minNode.nodeID]=true;
        for(edgeNode *p=verList[minNode.nodeID].head;p!=NULL;p=p->next)
        {
         if(!known[p->endNode]&&distance[p->endNode]>minNode.dist+p->weight)
         {
             renewedNode.dist=distance[p->endNode]=minNode.dist+p->weight;
             prev[p->endNode]=minNode.nodeID;
             renewedNode.nodeID=p->endNode;
             q.enQueue(renewedNode);
         }
        }
    }
    totalWeight=distance[destination];
    printPath(start,destination,prev);


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

  test.dijkstra(start,end);
  cout<<totalWeight<<endl;
  for(int i=0;i<pathLength;++i) cout<<path[i]<<' ';

}
