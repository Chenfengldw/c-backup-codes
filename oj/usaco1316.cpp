#include<iostream>
using namespace std;

class farmer
{
    public:
    int start;
    int end;
    farmer *next;
    farmer(){next=NULL;}
    farmer(int a,int b) {start=a;end=b;next=NULL;}
    ~farmer(){}
};


int main()
{
    int N;
    cin>>N;
    farmer *farmers;
    farmers=new farmer[N];
    for(int i=0;i<N;++i)
    {
        cin>>farmers[i].start;
        cin>>farmers[i].end;
    }
    for(int i=0;i<N-1;++i)
    {
        if (farmers[i].end>=farmers[i+1].start) farmers[i].next=&farmers[i+1];
    }
    int maxContinue=0,maxBreak=0;
    for(int i=0;i<N-1;i++)
    {
        int tmp1,tmp2,first=i;
        while (farmers[i].next!=NULL) i++;
        tmp1=farmers[i].end-farmers[first].start;
        if (i<N-1) tmp2=farmers[i+1].start-farmers[i].end;
        else tmp2=0;
        if(maxContinue<tmp1) maxContinue=tmp1;
        if(maxBreak<tmp2) maxBreak=tmp2;
    }
    cout<<maxContinue<<' '<<maxBreak;
}

