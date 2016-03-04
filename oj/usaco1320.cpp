#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int **p,**q;//q[i][j] represents the largest sum to location (i,j);p[i][j] represents the number at location(i,j)
    for(int i=0;i<n;++i){p=new int*[n];q=new int*[n];}
    for(int i=0;i<n;++i){p[i]=new int[n];q[i]=new int[n];}
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(j<=i) cin>>p[i][j];
            else p[i][j]=-1;
            q[i][j]=p[i][j];
        }
    }


    for(int i=1;i<n;++i)
    {
        for(int j=0;j<=i;++j)
        {
            if(q[i-1][j]+p[i][j]>q[i][j])q[i][j]=q[i-1][j]+p[i][j];
            if(j-1>=0&&(q[i-1][j-1]+p[i][j]>q[i][j]))q[i][j]=q[i-1][j-1]+p[i][j];
        }
    }
    int maximum=0;
    for(int j=0;j<n;++j)
    {
        if(q[n-1][j]>maximum)maximum=q[n-1][j];
    }
    cout<<maximum;
}
