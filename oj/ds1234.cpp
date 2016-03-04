#include<iostream>
using namespace std;
int n,m;

void quicksort(int *index1,int *index2,int *arr,int left,int right)
{
    int l=left,r=right,mid=(l+r)/2;
    int base=arr[mid];
    while(l<r)
    {
        while(arr[l]<base)l++;
        while(arr[r]>base)r--;
        if(l<=r)
        {
            int tmp=arr[l],tmp1=index1[l],tmp2=index2[l];
            arr[l]=arr[r];index1[l]=index1[r];index2[l]=index2[r];
            arr[r]=tmp;index1[r]=tmp1;index2[r]=tmp2;
            r--;
            l++;
        }
        //cout<<'k';
    }

    if(l<right)quicksort(index1,index2,arr,l,right);
    if(r>left)quicksort(index1,index2,arr,left,r);


}



class disjointSet
{
private:
    int size;
    int *parent;

public:
    disjointSet(int n)
    {
        size=n;
        parent=new int[n+1];
        for(int i=1;i<=size;++i)parent[i]=-1;
    }
    ~disjointSet(){delete [] parent;}

    void Union(int root1,int root2);
    int Find(int x);

};

int disjointSet::Find(int x)
{
    int tmp,start=x;
    while(parent[x]>=0)x=parent[x];
    while(start!=x)
    {
        tmp=parent[start];
        parent[start]=x;
        start=tmp;
    }
    return x;
}


void disjointSet::Union(int root1,int root2)
{

     if(root1==root2) return;
     if(Find(root1)>Find(root2))
     {
         parent[root2]+=parent[root1];
         parent[root1]=root2;
     }

     else
     {

        parent[root1]+=parent[root2];
        parent[root2]=root1;
     }

}



class graph
{
private:
    struct edgeNode
    {
        int endNode;
        edgeNode *next;
        int weight;

        edgeNode(int e,int w):endNode(e),next(NULL){weight=w;}
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
    void insertEdge(int u,int v,int w)
    {
        edgeNode *tmp1,*tmp2;
        tmp1=new edgeNode(v,w);
        tmp2=verList[u].head;
        verList[u].head=tmp1;
        tmp1->next=tmp2;
    }
    int kruskal();


};



int graph::kruskal()
{
    int edgeIn=0,totalWeight=0,u,v;
    edgeNode *p;
    disjointSet djs(graphSize);
    int *weightArray,*startArray,*endArray;
    weightArray=new int[m];
    startArray=new int[m];
    endArray=new int[m];
   // cout<<'!';
    int counter=0;
    for(int i=1;i<=graphSize;++i)
    {
        for(edgeNode *tmp=verList[i].head;tmp!=NULL;tmp=tmp->next)
        {
            if(tmp->endNode>i)
            {
                weightArray[counter]=tmp->weight;
                startArray[counter]=i;
                endArray[counter]=tmp->endNode;
                counter++;
            }
        }
    }
    //cout<<'!';
    quicksort(startArray,endArray,weightArray,0,m-1);
   // cout<<'!';
   counter=0;
    while(edgeIn<graphSize-1)
    {

        u=djs.Find(startArray[counter]);
        v=djs.Find(endArray[counter]);

        if(u!=v)
        {

            djs.Union(u,v);
            //cout<<endl<<u<<' '<<v<<weightArray[counter]<<endl;
            totalWeight+=weightArray[counter];
            edgeIn++;
        }
        counter++;
    }

    return totalWeight;





}



int main()
{

    cin>>n>>m;
    graph test(n);
    for(int i=0;i<m;++i)
    {
        int a,b,p;
        cin>>a>>b>>p;
        test.insertEdge(a,b,p);
        //cout<<1;
        test.insertEdge(b,a,p);
       // cout<<1;6 10

    }

   cout<<test.kruskal();
}





