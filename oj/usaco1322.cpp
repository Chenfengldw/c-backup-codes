#include<iostream>
using namespace std;

int A,B,C;
bool state[21][21];//It is the key of this problem!!!!!!state[i][j] indicates the a=i,b=j situation is available or not.
void pour(int &x,int &y,int X,int Y)
{
    if(Y-y>=x)
    {
        y+=x;
        x=0;

    }
    else{
        x-=(Y-y);
        y=Y;

    }
}


void findAnswer(int &a,int &b,int &c,int &i)
{
        int a0=a,b0=b,c0=c;
        if(state[a][b])return;
        state[a][b]=true;
       // cout<<a<<' '<<b<<' '<<c<<' ';
        pour(a,b,A,B);
       //cout<<a<<' '<<b<<' '<<c<<' ';
        findAnswer(a,b,c,i);
       // cout<<a<<' '<<b<<' '<<c<<' ';
        a=a0;b=b0;c=c0;
        pour(a,c,A,C);
     //  cout<<a<<' '<<b<<' '<<c<<' ';
        findAnswer(a,b,c,i);
      //  cout<<a<<' '<<b<<' '<<c<<' ';
      a=a0;b=b0;c=c0;
        pour(b,c,B,C);
       // cout<<a<<' '<<b<<' '<<c<<' ';
        findAnswer(a,b,c,i);
       // cout<<'&'<<a<<' '<<b<<' '<<c<<' '<<A<<B;
       a=a0;b=b0;c=c0;
        pour(b,a,B,A);
       // cout<<a<<' '<<b<<' '<<c<<' ';
        findAnswer(a,b,c,i);
       // cout<<a<<' '<<b<<' '<<c<<' ';
        //cout<<a<<' '<<b<<' '<<c<<' ';
        a=a0;b=b0;c=c0;
        pour(c,b,C,B);
        //cout<<a<<' '<<b<<' '<<c<<' ';
        //cout<<a<<' '<<b<<' '<<c<<' ';
        findAnswer(a,b,c,i);
        a=a0;b=b0;c=c0;
        pour(c,a,C,A);
       // cout<<a<<' '<<b<<' '<<c<<' ';
        findAnswer(a,b,c,i);


}

int main()
{
    cin>>A>>B>>C;

    for(int i=0;i<=20;++i)
    {
        for(int j=0;j<=20;++j)
        {
            state[i][j]=false;
        }
    }
    int i=0,a=0,b=0,c=C;
    findAnswer(a,b,c,i);
    bool *result;
    result=new bool[C+1];
    for(int i=0;i<C+1;++i)result[i]=false;
    for(int i=0;i<=20;++i)
    {
        for(int j=0;j<=20;++j)
        {
            if(state[i][j])result[C-j]=true;
        }
    }
    for(int i=0;i<C+1;++i)
    {
        if(result[i]) cout<<i<<' ';
    }

}
