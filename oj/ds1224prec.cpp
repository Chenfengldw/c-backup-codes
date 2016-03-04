#include<iostream>
#define INF 20000000
using namespace std;

class hashList
{
public:
    struct hashNode
    {
        int data;
        int state;

        hashNode()
        {
            state=0;
            data=INF;
        }
    };

    hashNode *arr;

    hashList()
    {
        arr=new hashNode[500009];
    }

    void Insert(int x)
    {
        int index=(x+1000000)%500009;
        int i;
        for(i=index;arr[(i+1000000)%500009].state!=0&&arr[(i+1000000)%500009].data!=x;++i){}
        if(arr[(i+1000000)%500009].state==0){arr[(i+1000000)%500009].state++;arr[(i+1000000)%500009].data=x;}
        else arr[(i+1000000)%500009].state++;
    }

    int Find(int x)
    {
        int index=(x+1000000)%500009;
        for(int i=index;arr[(i+1000000)%500009].state!=0;++i)
        {
            if(arr[(i+1000000)%500009].data==x)return arr[(i+1000000)%500009].state;
        }
        return 0;

    }


};


int main()
{
    int n;
    cin>>n;
    hashList hl;
    int A[500],B[500],C[500],D[500];
    for(int i=0;i<n;++i)
    {
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j) hl.Insert(-A[i]-B[j]);
    }

    int counter=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            counter+=hl.Find(C[i]+D[j]);
        }
    }

    cout<<counter;

    return 0;


}
