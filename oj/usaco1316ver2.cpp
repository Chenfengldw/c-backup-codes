#include<iostream>
using namespace std;

class farmer
{
    public:
    int start;
    int end;

    farmer(){}
    ~farmer(){}
};


int main()
{
    bool *p;
    int N;
    cin>>N;

    farmer *farmers;
    farmers=new farmer[N];
    for(int i=0;i<N;++i)
    {
        cin>>farmers[i].start;
        cin>>farmers[i].end;
    }
    int when_begin=1000000,when_stop=0;
    for(int i=0;i<N;++i)
    {
        if(farmers[i].start<when_begin) when_begin=farmers[i].start;
        if(farmers[i].end>when_stop) when_stop=farmers[i].end;
    }
    p=new bool[1000000];
    for(int i=0;i<1000000;++i)p[i]=false;
    for(int i=0;i<N;++i)
    {
        for(int j=farmers[i].start-1;j<=farmers[i].end-2;++j) p[j]=true;
    }
    int maxContinue=0,maxBreak=0,i=0;
    for(i=when_begin-1;i<when_stop;)
    {

        int tmp1,tmp2,first=i,stop;
        while (p[i]==true) i++;
        tmp1=i-first;

        if(maxContinue<tmp1) maxContinue=tmp1;
        if (i!=when_stop-1)
        {
        stop=i;
        while (p[i]==false) i++;
        tmp2=i-stop;
        if(maxBreak<tmp2) maxBreak=tmp2;
        }
        else i++;
    }

    cout<<maxContinue<<' '<<maxBreak;

}
