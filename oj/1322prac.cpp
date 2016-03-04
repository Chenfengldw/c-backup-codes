#include<iostream>
using namespace std;

bool state[21][21];
int A,B,C;


void pour(int &x,int &y,int X,int Y)//x pour to y
{
    if(Y-y>=x)
    {
        y+=x;
        x=0;
    }
    else
    {
        x-=(Y-y);
        y=Y;
    }
}


void findAnswer(int a,int b,int c)
{
    if(state[a][b])return;
    int a0=a,b0=b,c0=c;
    state[a][b]=true;

    pour(a,b,A,B);
    findAnswer(a,b,c);
    a=a0;b=b0;c=c0;

    pour(a,c,A,C);
    findAnswer(a,b,c);
    a=a0;b=b0;c=c0;

    pour(b,a,B,A);
    findAnswer(a,b,c);
    a=a0;b=b0;c=c0;

    pour(b,c,B,C);
    findAnswer(a,b,c);
    a=a0;b=b0;c=c0;

    pour(c,b,C,B);
    findAnswer(a,b,c);
    a=a0;b=b0;c=c0;

    pour(c,a,C,A);
    findAnswer(a,b,c);
    a=a0;b=b0;c=c0;
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

    findAnswer(0,0,C);

    for(int j=20;j>=0;--j)
    {
        if(state[0][j]==true)cout<<C-j<<' ';
    }

   return 0;

}




