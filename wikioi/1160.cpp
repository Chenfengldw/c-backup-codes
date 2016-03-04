#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int **p;
    p=new int*[n];
    for(int i=0;i<n;++i) p[i]=new int[n];
    p[n/2][n/2]=1;
    int number=2;
    for(int j=1;j<=(n-1)/2;++j){
        for(int t=0;t<2*j;++t){
            p[n/2+j][n/2-j+1+t]=number;
            ++number;
        }
        for(int t=0;t<2*j;++t){
            p[n/2+j-t-1][n/2+j]=number;
            ++number;
        }
        for(int t=0;t<2*j;++t){
            p[n/2-j][n/2+j-1-t]=number;
            ++number;
        }
        for(int t=0;t<2*j;++t){
            p[n/2-j+t+1][n/2-j]=number;
            ++number;
        }
    }
        for(int i=0;i<n;++i){
             for(int j=0;j<n;++j){
                    cout<<p[j][n-1-i]<<' ';

        }
        cout<<endl;
        }
        int sum=0;
        for(int j=0;j<n;++j) sum+=p[j][j];
        for(int j=0;j<n;++j) sum+=p[j][n-1-j];
        cout<<sum-1;
        return 0;


    }

