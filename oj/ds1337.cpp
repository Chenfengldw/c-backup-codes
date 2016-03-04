#include<iostream>
using namespace std;

int totalWeight=0,totalNum=0;


class disjointSet
{
public:
    int Size;
    int *parent;

    disjointSet(int s)
    {
        Size=s;
        parent=new int[s];

        for(int i=0;i<s;++i)parent[i]=-1;
    }

    int Find(int x)
    {
        if(parent[x]<0)return x;
        return parent[x]=Find(parent[x]);
    }

    void Union(int a,int b);

};

void disjointSet::Union(int a,int b)
{
    if(a==b)return;
    if(parent[a]<parent[b])
    {
        parent[a]+=parent[b];
        parent[b]=a;
    }
    else
    {
        parent[b]+=parent[a];
        parent[a]=b;
    }

}


void quicksort(int *index1,int *index2,int *arr,int left,int right)
{
    int l=left,r=right;
    int base=arr[(l+r)/2];
    while(l<r)
    {
        while(arr[l]<base)l++;
        while(arr[r]>base)r--;
        if(l<=r)
        {
            int tmp,tmp1,tmp2;
            tmp=arr[l];tmp1=index1[l];tmp2=index2[l];
            arr[l]=arr[r]; index1[l]=index1[r];index2[l]=index2[r];
            arr[r]=tmp;index1[r]=tmp1;index2[r]=tmp2;
            l++;
            r--;
        }

    }
    if(l<right)quicksort(index1,index2,arr,l,right);
    if(r>left)quicksort(index1,index2,arr,left,r);
}

int main()
{
   // ifstream in("file1.in");
   // ofstream out("file2.out");

    int N,M;
    cin>>N>>M;
    int *weight;
    int *start;
    int *endNode;
    int *root;
    disjointSet djs(N+1);
   // djs=new int[N+1];
    //for(int i=0;i<=N;++i)djs[i]=i;
    root=new int[N+1];
    weight=new int[M+N];
    start=new int[M+N];
    endNode=new int[M+N];
    for(int i=1;i<=N;++i)
    {
        cin>>root[i];
    }
    for(int i=0;i<M;++i)
    {
        cin>>start[i]>>endNode[i]>>weight[i];
    }
    for(int i=M;i<M+N;++i)
    {
        start[i]=0;
        endNode[i]=i-M+1;
        weight[i]=root[i-M+1];
    }


    quicksort(start,endNode,weight,0,M+N-1);


    for(int i=0;i<M+N;++i)
    {
        int p1=djs.Find(start[i]),p2=djs.Find(endNode[i]);
        if(p1!=p2)
        {
            //cout<<start[i]<<' '<<endNode[i]<<' '<<weight[i]<<endl;
            //int small=(djs[start[i]]<djs[endNode[i]])?djs[start[i]]:djs[endNode[i]];
            //djs[start[i]]=small;
            //djs[endNode[i]]=small;
            totalWeight+=weight[i];
            totalNum++;
            djs.Union(p1,p2);
        }
        if(totalNum==N)break;
    }



    cout<<totalWeight;

    return 0;

}

