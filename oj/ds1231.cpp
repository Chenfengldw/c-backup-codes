#include<iostream>
using namespace std;

struct Node
{
    int id;
    Node *parent;
    Node(Node *p=NULL): parent(p){}

};

int main()
{
    int N,X,Y;
    cin>>N>>X>>Y;
    if(X==Y)cout<<X;
    if(X==1)cout<<1;
    if(Y==1)cout<<1;
    Node *arr;
    arr=new Node[N+1];
    for(int i=1;i<=N;++i) arr[i].id=i;
    for(int i=1;i<=N;++i)
    {
        int lson,rson;
        cin>>lson>>rson;

        if(lson!=0) arr[lson].parent=&arr[i];
        if(rson!=0)arr[rson].parent=&arr[i];
    }

    int *ancestorX, *ancestorY;
    Node *currentAncestor;
    ancestorX=new int[N];
    ancestorY=new int[N];
    for(int i=0;i<N;++i)
    {
        ancestorX[i]=-1;
        ancestorY[i]=-1;
    }


    int j=0;
    currentAncestor=arr[X].parent;
    while(currentAncestor!=NULL)
    {
        ancestorX[j]=currentAncestor->id;
        currentAncestor=currentAncestor->parent;
        j++;
    }

    j=0;
    currentAncestor=arr[Y].parent;
    while(currentAncestor!=NULL)
    {
        ancestorY[j]=currentAncestor->id;
        currentAncestor=currentAncestor->parent;
        j++;
    }

    for(int i=0;i<N;++i)//一定不能只用一个循环，再犯这么2B的错误就去死好了==#
    {
        for(int k=0;k<N;++k)
        {
            if(ancestorX[i]==ancestorY[k])
            {
            cout<<ancestorX[i];
            return 0;
            }
        }
    }

}
