#include<iostream>
using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;

    int *all_bisquare,*whether_a_bisquare;
    whether_a_bisquare=new int[M*M*2+1];
    all_bisquare=new int[M*M*2+1];
    for(int i=0;i<M*M*2+1;++i) whether_a_bisquare[i]=0;


    for(int i=0;i<=M;++i)
    {
        for(int j=0;j<=M;++j)
        {
            whether_a_bisquare[i*i+j*j]=1;
        }
    }

    int bisquareCounter=0;
    for(int i=0;i<M*M*2+1;++i)
    {
        if(whether_a_bisquare[i]==1)
        {
            all_bisquare[bisquareCounter]=i;
            bisquareCounter++;
        }

    }

    bool haveFound=false;

    int start=all_bisquare[0];
    for(int step=1;step*(N-1)+start<=M*M*2;++step)
    {
        for(int i=0;i<bisquareCounter&&step*(N-1)+all_bisquare[i]<=M*M*2;i++)
          {
            start=all_bisquare[i];
            bool flag=true;
            for(int j=1;j<N;j++)
            {
                if(whether_a_bisquare[j*step+start]==0){flag=false;break;}
            }
            if(flag)
            {cout<<start<<' '<<step<<endl;haveFound=true;}
         }
         start=all_bisquare[0];
    }
    if(!haveFound) cout<<"NONE"<<endl;





}
