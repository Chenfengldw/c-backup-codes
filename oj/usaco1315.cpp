#include<iostream>
using namespace std;

void simplify(int m,int n)
{
    int tmp=1;
    for(int i=1;i<=m&&i<=n;++i)
    {
        if (m%i==0&&n%i==0&&i>tmp) {tmp=i;}
    }

    cout<<m/tmp<<'/'<<n/tmp<<endl;
}

int main()
{
    int n;
    cin>>n;
    int *denominator,*numerator;
    denominator=new int[n];
    numerator=new int[n];
    for(int i=0;i<n;++i)
    {
        denominator[i]=i+1;
        numerator[i]=i+1;
    }
    double **result;
    result=new double *[n];
    for(int i=0;i<n;++i) result[i]=new double[n];

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=i;++j)
        {
            result[i][j]=100;
        }
    }

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=i;++j)
        {
            result[i][j]=double(numerator[j])/denominator[i];
        }
    }

    double tmp=100,min=0;
    int x=1,y=1;
    cout<<0<<'/'<<1<<endl;
    while(min<1)
    {
            for(int i=0;i<n;++i)
        {
            for(int j=0;j<=i;++j)
            {
                if (result[i][j]<tmp) {tmp=result[i][j];y=i;x=j;}
            }
        }

        min=tmp;
        simplify(x+1,y+1);

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<=i;++j)
            {
                if (result[i][j]==tmp) {result[i][j]=100;}
            }
        }
        tmp=100;
    }




}
