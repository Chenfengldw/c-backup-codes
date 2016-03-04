#include <iostream>
#include <iomanip>
using namespace std;
void draw(int n,int start,int **p);
int main()
{
    int **p,i,j,n;
    cin>>n;
    p=new int *[n];
    for (i=0;i<n;++i) p[i]=new int [n];
    draw(n,1,p);
    for (i=0;i<n;++i){
        for (j=0;j<n;++j){
            cout<<setw(4)<<p[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}

void draw(int n,int start,int **p){
    int i,j,k;

    for (k=0;k<(n+1)/2;++k){
    for (j=k;j<n-k;++j) p[k][j]=4*n*k-4*k*k+1+j-k;
    //cout<<"1111111111";
    for (i=k+1;i<n-k;++i) p[i][n-k-1]=4*n*k-4*k*k+n-3*k+i;
    //cout<<"1111111111";
    for (j=n-2-k;j>=k;--j) p[n-k-1][j]=4*n*k-4*k*k+3*n-5*k-2-j;
    //cout<<"22221111";
    for (i=n-2-k;i>=k+1;--i) p[i][k]=4*n*k-4*k*k+4*n-7*k-3-i;
    }
}

